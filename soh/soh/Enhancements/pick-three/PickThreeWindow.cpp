#include "PickThreeWindow.h"
#include "../../UIWidgets.hpp"
#include "../../util.h"
#include "../../OTRGlobals.h"

#include <libultraship/bridge.h>
#include <libultraship/libultraship.h>
#include "soh_assets.h"

extern "C" {
#include "variables.h"
#include "functions.h"
#include "macros.h"
extern PlayState* gPlayState;

#include "textures/icon_item_static/icon_item_static.h"
#include "textures/icon_item_24_static/icon_item_24_static.h"
#include "textures/parameter_static/parameter_static.h"
#include <soh/Enhancements/item-tables/ItemTableManager.h>
}

uint32_t itemNumber = ITEM_STICK;
uint32_t statusTimer = 0;
const char* statusText = " ";
std::string str1;
std::string str2;
std::string str3;

void PickThreeStatus() {
    str1 = std::string(itemObjectList[itemNumber].itemName).c_str();
    str2 = " added.";
    str3 = str1 + str2;
    statusText = str3.c_str();
    Audio_PlaySoundGeneral(NA_SE_SY_METRONOME, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
}

void PickThreeAccept() {
    switch (itemObjectList[itemNumber].itemID) {
        case ITEM_BOMB:
            Item_Give(gPlayState, ITEM_BOMB_BAG_20);
            Item_Give(gPlayState, ITEM_BOMBS_20);
            break;
        case ITEM_BOW:
            Item_Give(gPlayState, ITEM_QUIVER_30);
            Item_Give(gPlayState, ITEM_BOW);
            break;
        case ITEM_SLINGSHOT:
            Item_Give(gPlayState, ITEM_BULLET_BAG_30);
            Item_Give(gPlayState, ITEM_SLINGSHOT);
            break;
        case ITEM_HEART_CONTAINER:
            gSaveContext.isDoubleDefenseAcquired = 1;
            break;
        case ITEM_SINGLE_MAGIC:
            gSaveContext.magicLevel = 1;
            gSaveContext.isMagicAcquired = true;
            gSaveContext.isDoubleMagicAcquired = false;
            gSaveContext.magicCapacity = gSaveContext.magicLevel * 0x30;
            if (gSaveContext.magic > gSaveContext.magicCapacity) {
                gSaveContext.magic = gSaveContext.magicCapacity;
            }
            break;
        case ITEM_DOUBLE_MAGIC:
            gSaveContext.magicLevel = 2;
            gSaveContext.isMagicAcquired = true;
            gSaveContext.isDoubleMagicAcquired = true;
            gSaveContext.magicCapacity = gSaveContext.magicLevel * 0x30;
            if (gSaveContext.magic > gSaveContext.magicCapacity) {
                gSaveContext.magic = gSaveContext.magicCapacity;
            }
            break;
        case ITEM_RUPEE_GREEN:
            Flags_SetRandomizerInf(RAND_INF_GREG_FOUND);
            break;
        default:
            Item_Give(gPlayState, itemObjectList[itemNumber].itemID);
            break;
    }
    PickThreeStatus();
}

void PickThreeRoll() {
    statusText = " ";
    itemNumber = rand() % itemObjectList.size() - 1;
}

void DrawPickThreeContainer() {
    ImGui::BeginTable("Pick Three Table", 2);
    ImGui::TableSetupColumn("Item Image", ImGuiTableColumnFlags_WidthFixed, 66.0f);
    ImGui::TableSetupColumn("Item Name");
    ImGui::TableNextColumn();
    UIWidgets::Spacer(0);
    ImGui::Image(Ship::Context::GetInstance()->GetWindow()->GetGui()->GetTextureByName(itemObjectList[itemNumber].itemImage),
        ImVec2(64.0f, 64.0f), ImVec2(0, 0), ImVec2(1, 1));
    ImGui::TableNextColumn();
    UIWidgets::PaddedSeparator();
    ImGui::Text(itemObjectList[itemNumber].itemName);
    if (ImGui::Button("Re-roll Item")) {
        PickThreeRoll();
    }
    ImGui::SameLine();
    if (ImGui::Button("Accept Item")) {
        PickThreeAccept();
    }
    if (ImGui::Button("- 1")) {
        if (itemNumber > 0) {
            itemNumber--;
        } else {
            itemNumber = itemObjectList.size() - 1;
        }
        statusText = " ";
    }
    ImGui::SameLine();
    if (ImGui::Button("+ 1")) {
        if (itemNumber >= itemObjectList.size() - 1) {
            itemNumber = 0;
        } else {
            itemNumber++;
        }
        statusText = " ";
    }
    UIWidgets::PaddedSeparator();
    ImGui::EndTable();
    ImGui::TextColored(ImVec4(0.0f, 0.7f, 0.0f, 1.0f), statusText);
}

void PickThreeWindow::DrawElement() {
    ImGui::SetNextWindowSize(ImVec2(340, 252), ImGuiCond_FirstUseEver);
    ImGui::Text("Randomly Select Starting Items.");
    ImGui::Text("-Step 1: Create a Randomizer Seed\nand a File Name, then Load that file.");
    ImGui::Text("-Step 2: Click the Re-roll Item\nbutton to roll for your Pick.");
    ImGui::Text("-Step 3: Assuming it aligns with your rules,\nclick Accept Item button to obtain it.");
    if (!gPlayState) {
        UIWidgets::PaddedSeparator();
        ImGui::TextColored(ImVec4(0.5f, 0.0f, 0.0f, 1.0f), "No Save File Loaded...");
        UIWidgets::PaddedSeparator();
        return;
    }
    DrawPickThreeContainer();
}

void PickThreeWindow::InitElement() {
    
}