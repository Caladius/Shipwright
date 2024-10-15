#include "PluginManager.h"
#include "../../UIWidgets.hpp"
#include "../../util.h"
#include "../../OTRGlobals.h"

#include "WidgetFactory.h"

void PluginManagerDrawPlugins() {
    ImGui::Text("Plugins");

    WidgetFactory& factory = WidgetFactory::GetInstance();

    // Retrieve all registered widget names
    std::vector<std::string> widgetNames = factory.GetRegisteredWidgetNames();

    // Create a table to show the widgets
    if (ImGui::BeginTable("WidgetTable", 2, ImGuiTableFlags_Borders)) {
        ImGui::TableSetupColumn("Plugin Name");
        ImGui::TableSetupColumn("Plugin Options");
        ImGui::TableHeadersRow();

        for (const std::string& widgetName : widgetNames) {
            std::unique_ptr<Widget> widget = factory.CreateWidget(widgetName);

            if (widgetName.find("Settings") != std::string::npos) {
                ImGui::SameLine();
                widget->Draw();
                widget->Settings();
            } else {
                ImGui::TableNextRow();
                ImGui::TableSetColumnIndex(0);
                ImGui::Text("%s", widget->GetLabel().c_str());
                ImGui::TableSetColumnIndex(1);
                widget->Draw();
            }
            
        }

        ImGui::EndTable();
    }

}


void PluginManager::DrawElement() {
    ImGui::SetNextWindowSize(ImVec2(400, 400), ImGuiCond_FirstUseEver);
    PluginManagerDrawPlugins();
}

void PluginManager::InitElement() {

}