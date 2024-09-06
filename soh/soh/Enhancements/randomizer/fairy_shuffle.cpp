#include "soh/Enhancements/game-interactor/GameInteractor_Hooks.h"
#include "fairy_shuffle.h"
#include "randomizer_grotto.h"
#include "draw.h"
#include "src/overlays/actors/ovl_En_Elf/z_en_elf.h"
#include "src/overlays/actors/ovl_Obj_Bean/z_obj_bean.h"

#define FAIRY_FLAG_TIMED (1 << 8)

void FairyDrawRandomizedItem(EnElf* enElf, PlayState* play) {
    GetItemEntry randoGetItem = enElf->sohFairyIdentity.itemEntry;
    if (CVarGetInteger(CVAR_RANDOMIZER_ENHANCEMENT("MysteriousShuffle"), 0)) {
        randoGetItem = GET_ITEM_MYSTERY;
    }
    Matrix_Push();
    Matrix_Scale(37.5, 37.5, 37.5, MTXMODE_APPLY);
    EnItem00_CustomItemsParticles(&enElf->actor, play, randoGetItem);
    GetItemEntry_Draw(play, randoGetItem);
    Matrix_Pop();
}

bool FairyInitialise(EnElf* fairy, int32_t params) {
    Rando::Location* location = OTRGlobals::Instance->gRandomizer->GetCheckObjectFromActor(ACTOR_EN_ELF, gPlayState->sceneNum, params);
    RandomizerInf flag = static_cast<RandomizerInf>(location->GetCollectionCheck().flag);
    if (location->GetRandomizerCheck() != RC_UNKNOWN_CHECK && !Flags_GetRandomizerInf(flag)) {
        GetItemEntry item = Rando::Context::GetInstance()->GetFinalGIEntry(location->GetRandomizerCheck(), true, GI_FAIRY);
        fairy->sohFairyIdentity = { flag, item };
        fairy->actor.draw = (ActorFunc)FairyDrawRandomizedItem;
        return true;
    } else {
        return false;
    }
}

void FairyOnVanillaBehaviorHandler(GIVanillaBehavior id, bool* should, void* optionalArg) {
    if (id == VB_FAIRY_HEAL) {
        EnElf* enElf = static_cast<EnElf*>(optionalArg);
        if (enElf->sohFairyIdentity.randomizerInf != RAND_INF_MAX) {
            Flags_SetRandomizerInf(enElf->sohFairyIdentity.randomizerInf);
            *should = false;
        }
    } else if (id == VB_SPAWN_FAIRY_GROUP) {
        EnElf* enElf = static_cast<EnElf*>(optionalArg);
        s16 grottoId = (gPlayState->sceneNum == SCENE_FAIRYS_FOUNTAIN) ? Grotto_CurrentGrotto() : 0;
        for (s16 index = 0; index < 8; index++) {
            EnElf* newFairy = (EnElf*)Actor_Spawn(&gPlayState->actorCtx, gPlayState, ACTOR_EN_ELF, enElf->actor.world.pos.x,
                        enElf->actor.world.pos.y - 30.0f, enElf->actor.world.pos.z, 0, 0, 0, FAIRY_HEAL, true);

            FairyInitialise(newFairy, (grottoId << 8) | index);
        }
        *should = false;
    } else if (id == VB_BEAN_SPAWN_FAIRIES) {
        ObjBean* objBean = static_cast<ObjBean*>(optionalArg);
        for (s16 index = 0; index < 3; index++) {
            EnElf* newFairy = (EnElf*)Actor_Spawn(&gPlayState->actorCtx, gPlayState, ACTOR_EN_ELF, objBean->dyna.actor.world.pos.x,
                        objBean->dyna.actor.world.pos.y + 15.0f, objBean->dyna.actor.world.pos.z, 0, 0, 0, FAIRY_HEAL, true);

            if (!FairyInitialise(newFairy, ((objBean->dyna.actor.params & 0x3F) << 8) | index)) {
                newFairy->fairyFlags |= FAIRY_FLAG_TIMED;
            }
        }
        *should = false;
    }
}

void FairyOnActorInitHandler(void* actorRef) {
    EnElf* enElf = static_cast<EnElf*>(actorRef);
    enElf->sohFairyIdentity = { RAND_INF_MAX, GET_ITEM_NONE };
}

uint32_t onVanillaBehaviorHook = 0;
uint32_t onActorInitHook = 0;

void FairyRegisterHooks() {
    onVanillaBehaviorHook = GameInteractor::Instance->RegisterGameHook<GameInteractor::OnVanillaBehavior>(FairyOnVanillaBehaviorHandler);
    onActorInitHook = GameInteractor::Instance->RegisterGameHookForID<GameInteractor::OnActorInit>(ACTOR_EN_ELF, FairyOnActorInitHandler);
}

void FairyUnregisterHooks() {
    GameInteractor::Instance->UnregisterGameHook<GameInteractor::OnVanillaBehavior>(onVanillaBehaviorHook);
    GameInteractor::Instance->UnregisterGameHookForID<GameInteractor::OnActorInit>(onActorInitHook);

    onVanillaBehaviorHook = 0;
    onActorInitHook = 0;
}