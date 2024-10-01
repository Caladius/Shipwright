#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include "GuiWindow.h"


class PluginManager : public Ship::GuiWindow {
  public:
    using GuiWindow::GuiWindow;

    void InitElement();
    void DrawElement();
    void UpdateElement() override{};
};

#endif // PLUGINMANAGER_H