#include <libultraship/bridge/consolevariablebridge.h>
#include <ship/Context.h>

#include "soh/SohGui/SohMenu.h"
#include "HolidayTypes.h"

namespace SohGui {

extern std::shared_ptr<SohMenu> mSohMenu;
using namespace UIWidgets;

void SohMenu::AddMenuHoliday() {
    // Add Holiday Menu
    AddMenuEntry("Holiday", CVAR_SETTING("Menu.HolidaySidebarSection"));

    // General
    AddSidebarEntry("Holiday", "General", 2);
    WidgetPath path = { "Holiday", "General", SECTION_COLUMN_1 };
	
    AddWidget(path, "Enable Holiday Events", WIDGET_CVAR_CHECKBOX)
        .CVar(CVAR_HOLIDAY("Enabled"))
        .Options(
            CheckboxOptions()
            .Tooltip("Enables Holiday Events."));
}

} // namespace SohGui