#include "accessibility.h"
#include "soh/Enhancements/game-interactor/GameInteractor.h"
#include "soh/OTRGlobals.h"


extern "C" {
#include <z64.h>
#include "macros.h"
#include "functions.h"
#include "variables.h"
extern SaveContext gSaveContext;
extern PlayState* gPlayState;
}

void Accessibility_LightSensitivity(GIVanillaBehavior _, bool* should, va_list originalArgs) {
	static uint32_t shouldHookId1 = 0;
	GameInteractor::Instance->UnregisterGameHookForID<GameInteractor::OnVanillaBehavior>(shouldHookId1);
    shouldHookId1 = 0;
	
	if (!gPlayState) {
		return;
	}

	if (CVarGetInteger(CVAR_SETTING("Lightsensitivity"), 0)) {
		return;
	}

	shouldHookId1 = REGISTER_VB_SHOULD(VB_DISABLE_LIGHT_SENSITIVITY, {
		*should = true;
		return;
	});

	*should = false;
	return;
}

void RegisterLightSensitivityBehavior() {
	GameInteractor::Instance->RegisterGameHookForID<GameInteractor::OnVanillaBehavior>(VB_DISABLE_LIGHT_SENSITIVITY, Accessibility_LightSensitivity);
}
