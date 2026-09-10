#pragma once

namespace Holiday {

#define CVAR_PREFIX_HOLIDAY "gHolidays"
#define CVAR_HOLIDAY(var) CVAR_PREFIX_HOLIDAY "." var

#define IS_HOLIDAY CVAR_HOLIDAY("Enabled")

} // namespace Holiday