#ifndef PICKTHREEWINDOW_H
#define PICKTHREEWINDOW_H

#include "GuiWindow.h"
#include "z64.h"
#include <vector>

typedef struct {
    uint32_t itemID;
    const char* itemImage;
    const char* itemName;
} itemObject;

static std::vector<itemObject> itemObjectList = {
    { ITEM_STICKS_5, "ITEM_STICK", "Deku Stick x5" },
    { ITEM_NUTS_5, "ITEM_NUT", "Deku Nut x5" },
    { ITEM_BOMB, "ITEM_BOMB", "Bombs" },
    { ITEM_BOW, "ITEM_BOW", "Fairy Bow" },
    { ITEM_ARROW_FIRE, "ITEM_ARROW_FIRE", "Fire Arrow" },
    { ITEM_DINS_FIRE, "ITEM_DINS_FIRE", "Din's Fire" },
    { ITEM_SLINGSHOT, "ITEM_SLINGSHOT", "Fairy Slingshot" },
    { ITEM_OCARINA_FAIRY, "ITEM_OCARINA_FAIRY", "Fairy Ocarina" },
    { ITEM_OCARINA_TIME, "ITEM_OCARINA_TIME", "Ocarina of Time" },
    { ITEM_BOMBCHUS_20, "ITEM_BOMBCHU", "Bombchu x20" },
    { ITEM_HOOKSHOT, "ITEM_HOOKSHOT", "Hookshot" },
    { ITEM_LONGSHOT, "ITEM_LONGSHOT", "Longshot" },
    { ITEM_ARROW_ICE, "ITEM_ARROW_ICE", "Ice Arrow" },
    { ITEM_FARORES_WIND, "ITEM_FARORES_WIND", "Farore's Wind" },
    { ITEM_BOOMERANG, "ITEM_BOOMERANG", "Boomerang" },
    { ITEM_LENS, "ITEM_LENS", "Lens of Truth" },
    { ITEM_BEAN, "ITEM_BEAN", "Magic Bean" },
    { ITEM_HAMMER, "ITEM_HAMMER", "Megaton Hammer" },
    { ITEM_ARROW_LIGHT, "ITEM_ARROW_LIGHT", "Light Arrow" },
    { ITEM_NAYRUS_LOVE, "ITEM_NAYRUS_LOVE", "Nayru's Love" },
    { ITEM_BOTTLE, "ITEM_BOTTLE", "Empty Bottle" },
    { ITEM_SONG_NOCTURNE, "QUEST_SONG_NOCTURNE", "Nocturne of Shadow" },
    { ITEM_SONG_PRELUDE, "QUEST_SONG_PRELUDE", "Prelude of Light" },
    { ITEM_SONG_LULLABY, "QUEST_SONG_LULLABY", "Zelda's Lullaby" },
    { ITEM_SONG_EPONA, "QUEST_SONG_EPONA", "Epona's Song" },
    { ITEM_SONG_SARIA, "QUEST_SONG_SARIA", "Saria's Song" },
    { ITEM_SONG_SUN, "QUEST_SONG_SUN", "Sun's Song" },
    { ITEM_SONG_TIME, "QUEST_SONG_TIME", "Song of Time" },
    { ITEM_SONG_STORMS, "QUEST_SONG_STORMS", "Song of Storms" },
    { ITEM_ZORA_SAPPHIRE, "QUEST_ZORA_SAPPHIRE", "Zora's Sapphire" },
    { ITEM_GERUDO_CARD, "QUEST_GERUDO_CARD", "Gerudo Membership Card" },
    { ITEM_HEART_CONTAINER, "ITEM_HEART_CONTAINER", "Double Defense" },
    { ITEM_DOUBLE_MAGIC, "ITEM_MAGIC_LARGE", "Double Magic Meter" },
    { ITEM_RUPEE_GREEN, "ITEM_RUPEE_GREEN", "Greg" },
    { ITEM_SOLD_OUT, "ITEM_SOLD_OUT", "Nothing" },
    { ITEM_POCKET_EGG, "ITEM_POCKET_EGG", "Pocket Egg" },
    { ITEM_POCKET_CUCCO, "ITEM_POCKET_CUCCO", "Pocket Cucco" },
    { ITEM_COJIRO, "ITEM_COJIRO", "Cojiro" },
    { ITEM_ODD_MUSHROOM, "ITEM_ODD_MUSHROOM", "Odd Mushroom" },
    { ITEM_ODD_POTION, "ITEM_ODD_POTION", "Odd Potion" },
    { ITEM_SAW, "ITEM_SAW", "Poachers Saw" },
    { ITEM_SWORD_BROKEN, "ITEM_SWORD_BROKEN", "Broken Sword" },
    { ITEM_PRESCRIPTION, "ITEM_PRESCRIPTION", "Prescription" },
    { ITEM_FROG, "ITEM_FROG", "Eyeball Frog" },
    { ITEM_EYEDROPS, "ITEM_EYEDROPS", "World's Finest Eyedrops" },
    { ITEM_CLAIM_CHECK, "ITEM_CLAIM_CHECK", "Claim Check" },
    { ITEM_SWORD_KOKIRI, "ITEM_SWORD_KOKIRI", "Kokiri Sword" },
    { ITEM_SWORD_MASTER, "ITEM_SWORD_MASTER", "Master Sword" },
    { ITEM_SWORD_BGS, "ITEM_SWORD_BGS", "Biggorons Sword" },
    { ITEM_SHIELD_DEKU, "ITEM_SHIELD_DEKU", "Deku Shield" },
    { ITEM_SHIELD_HYLIAN, "ITEM_SHIELD_HYLIAN", "Hylian Shield" },
    { ITEM_SHIELD_MIRROR, "ITEM_SHIELD_MIRROR", "Mirror Shield" },
    { ITEM_TUNIC_GORON, "ITEM_TUNIC_GORON", "Goron Tunic" },
    { ITEM_TUNIC_ZORA, "ITEM_TUNIC_ZORA", "Zora Tunic" },
    { ITEM_BOOTS_IRON, "ITEM_BOOTS_IRON", "Iron Boots" },
    { ITEM_BOOTS_HOVER, "ITEM_BOOTS_HOVER", "Hover Boots" },
    { ITEM_BRACELET, "ITEM_BRACELET", "Goron's Bracelet" },
    { ITEM_GAUNTLETS_SILVER, "ITEM_GAUNTLETS_SILVER", "Silver Gauntlets" },
    { ITEM_GAUNTLETS_GOLD, "ITEM_GAUNTLETS_GOLD", "Golden Gauntlets" },
    { ITEM_SCALE_SILVER, "ITEM_SCALE_SILVER", "Silver Scale" },
    { ITEM_SCALE_GOLDEN, "ITEM_SCALE_GOLDEN", "Golden Scale" },
    { ITEM_WALLET_ADULT, "ITEM_WALLET_ADULT", "Adult Wallet" },
    { ITEM_WALLET_GIANT, "ITEM_WALLET_GIANT", "Giant Wallet" },
    { ITEM_SONG_MINUET, "QUEST_SONG_MINUET", "Minuet of Forest" },
    { ITEM_SONG_BOLERO, "QUEST_SONG_BOLERO", "Bolero of Fire" },
    { ITEM_SONG_SERENADE, "QUEST_SONG_SERENADE", "Serenade of Water" },
    { ITEM_SONG_REQUIEM, "QUEST_SONG_REQUIEM", "Requiem of Spirit" },
    { ITEM_MEDALLION_FOREST, "QUEST_MEDALLION_FOREST", "Forest Medallion" },
    { ITEM_MEDALLION_FIRE, "QUEST_MEDALLION_FIRE", "Fire Medallion" },
    { ITEM_MEDALLION_WATER, "QUEST_MEDALLION_WATER", "Water Medallion" },
    { ITEM_MEDALLION_SPIRIT, "QUEST_MEDALLION_SPIRIT", "Spirit Medallion" },
    { ITEM_MEDALLION_SHADOW, "QUEST_MEDALLION_SHADOW", "Shadow Medallion" },
    { ITEM_MEDALLION_LIGHT, "QUEST_MEDALLION_LIGHT", "Light Medallion" },
    { ITEM_KOKIRI_EMERALD, "QUEST_KOKIRI_EMERALD", "Kokiri Emerald" },
    { ITEM_GORON_RUBY, "QUEST_GORON_RUBY", "Goron Ruby" },
    { ITEM_STONE_OF_AGONY, "QUEST_STONE_OF_AGONY", "Stone of Agony" },
    { ITEM_SKULL_TOKEN, "QUEST_SKULL_TOKEN", "Gold Skulltula Token" },
    { ITEM_SINGLE_MAGIC, "ITEM_MAGIC_SMALL", "Magic Meter" },

};

class PickThreeWindow : public Ship::GuiWindow {
  public:
    using GuiWindow::GuiWindow;

    void InitElement();
    void DrawElement();
    void UpdateElement() override{};
};

#endif // PICKTHREEWINDOW_H