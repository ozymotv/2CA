#define WIN32_LEAN_AND_MEAN
#define _WINSOCKAPI_
#include <winsock2.h>
#include <Windows.h>

#include <shellapi.h>

#include "imgui/imgui.h"
#include "2CA.h"
#include "include/other_tools.h"

std::string ghub_version = get_ghub_version();

void draw_mouse()
{
    ImGui::SliderInt("DPI", &config.dpi, 400, 5000);
    ImGui::SliderFloat("Sensitivity", &config.sensitivity, 0.1f, 10.0f, "%.1f");
    ImGui::SliderInt("FOV X", &config.fovX, 10, 120);
    ImGui::SliderInt("FOV Y", &config.fovY, 10, 120);
    ImGui::SliderFloat("Min Speed Multiplier", &config.minSpeedMultiplier, 0.1f, 30.0f, "%.1f");
    ImGui::SliderFloat("Max Speed Multiplier", &config.maxSpeedMultiplier, 0.1f, 30.0f, "%.1f");
    ImGui::SliderFloat("Prediction Interval", &config.predictionInterval, 0.00f, 0.10f, "%.2f");
    if (config.predictionInterval == 0.00f)
    {
        ImGui::SameLine();
        ImGui::TextColored(ImVec4(255, 0, 0, 255), "-> Disabled");
    }

    ImGui::Separator();

    // No recoil settings
    ImGui::Checkbox("Easy No Recoil", &config.easynorecoil);
    if (config.easynorecoil)
    {
        ImGui::SliderFloat("No Recoil Strength", &config.easynorecoilstrength, 0.1f, 500.0f, "%.1f");
        ImGui::TextColored(ImVec4(1.0f, 1.0f, 0.0f, 1.0f), "Left/Right Arrow keys: Adjust recoil strength by 10");
        
        if (config.easynorecoilstrength >= 100.0f)
        {
            ImGui::TextColored(ImVec4(255, 255, 0, 255), "WARNING: High recoil strength may be detected.");
        }
    }

    ImGui::Separator();

    ImGui::Checkbox("Auto Shoot", &config.auto_shoot);
    if (config.auto_shoot)
    {
        ImGui::SliderFloat("bScope Multiplier", &config.bScope_multiplier, 0.5f, 2.0f, "%.1f");
    }

    // INPUT METHODS
    ImGui::Separator();
    std::vector<std::string> input_methods = { "WIN32", "GHUB", "ARDUINO", "KMBOX" };

    std::vector<const char*> method_items;
    method_items.reserve(input_methods.size());
    for (const auto& item : input_methods)
    {
        method_items.push_back(item.c_str());
    }

    std::string combo_label = "Mouse Input method";
    int input_method_index = 0;
    for (size_t i = 0; i < input_methods.size(); ++i)
    {
        if (input_methods[i] == config.input_method)
        {
            input_method_index = static_cast<int>(i);
            break;
        }
    }

    if (ImGui::Combo("Mouse Input Method", &input_method_index, method_items.data(), static_cast<int>(method_items.size())))
    {
        std::string new_input_method = input_methods[input_method_index];

        if (new_input_method != config.input_method)
        {
            config.input_method = new_input_method;
            config.saveConfig();
            input_method_changed.store(true);
        }
    }

}