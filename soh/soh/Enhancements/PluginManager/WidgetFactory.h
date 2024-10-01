#pragma once
#include "soh/OTRGlobals.h"
#include <unordered_map>
#include <functional>
#include <string>
#include <vector>
#include <memory>
#include "Widget.h"
#include "soh/Enhancements/game-interactor/GameInteractor.h"
#include "soh/UIWidgets.hpp"


// WidgetFactory responsible for creating widgets and storing registrations
class WidgetFactory {
public:
    // A map that stores creation functions by widget name
    using CreateWidgetFunc = std::function<std::unique_ptr<Widget>()>;

    static WidgetFactory& GetInstance() {
        static WidgetFactory instance;
        return instance;
    }

    // Registers a widget creation function with the given name
    void RegisterWidget(const std::string& name, CreateWidgetFunc func) {
        widgetCreators[name] = func;
    }

    // Creates a widget by name
    std::unique_ptr<Widget> CreateWidget(const std::string& name) const {
        auto it = widgetCreators.find(name);
        if (it != widgetCreators.end()) {
            return it->second();
        }
        return nullptr;
    }

    // Returns a list of registered widget names
    std::vector<std::string> GetRegisteredWidgetNames() const {
        std::vector<std::string> names;
        for (const auto& pair : widgetCreators) {
            names.push_back(pair.first);
        }
        return names;
    }

private:
    std::unordered_map<std::string, CreateWidgetFunc> widgetCreators;
};

// Helper class for static registration of widgets
class WidgetRegistrar {
public:
    WidgetRegistrar(const std::string& name, WidgetFactory::CreateWidgetFunc func) {
        WidgetFactory::GetInstance().RegisterWidget(name, func);
    }
};