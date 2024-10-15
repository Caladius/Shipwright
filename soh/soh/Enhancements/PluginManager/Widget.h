#pragma once
#include <string>
#include <imgui.h>

// Base class for all widgets
class Widget {
public:
    virtual ~Widget() = default;
    virtual const std::string& GetLabel() const = 0;
    virtual void Draw() = 0;
    virtual void Settings() = 0;
};