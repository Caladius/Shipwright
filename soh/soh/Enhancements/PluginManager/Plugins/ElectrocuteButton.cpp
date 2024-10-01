#include "../WidgetFactory.h"

bool openSettings = false;

// Derived widget class for a button
class ButtonWidget : public Widget {
public:
    ButtonWidget(const std::string& tableLabel, const std::string& buttonLabel, std::function<void()> onClickAction) 
        : tableLabel(tableLabel), buttonLabel(buttonLabel), onClickAction(onClickAction) {}

    const std::string& GetLabel() const override {
        return tableLabel;
    }

    void Draw() override {
        if (ImGui::Button(buttonLabel.c_str())) {
            onClickAction();
        }
    }

    void Settings() override {
        if (openSettings) {
            ImGui::SetNextWindowSize(ImVec2(400, 400), ImGuiCond_FirstUseEver);
            ImGui::Begin("Electrocute Settings", &openSettings);

            UIWidgets::PaddedEnhancementCheckbox("Enable Button", "gEnhancements.CanShock", true, true);

            ImGui::End();
        }
    }

private:
    std::string tableLabel;  // Label for the table
    std::string buttonLabel; // Label for the button
    std::function<void()> onClickAction;
};

static WidgetRegistrar electrocuteButtonRegistrar(
    "ElectrocuteButton",
    []() -> std::unique_ptr<Widget> {
        return std::make_unique<ButtonWidget>(
            "Electrocute Player",    // Table label
            "Electrocute",           // Button label
            []() { 
                if (CVarGetInteger("gEnhancements.CanShock", 0) == 1) {
                    GameInteractor::RawAction::ElectrocutePlayer();
                }
            }
        );
    }
);

static WidgetRegistrar electrocuteSettingsButtonRegistrar(
    "ElectrocuteSettingsButton",
    []() -> std::unique_ptr<Widget> {
        return std::make_unique<ButtonWidget>(
            "Open Settings",    // Table label
            "Settings",           // Button label
            []() { openSettings = !openSettings; }
        );
    }
);