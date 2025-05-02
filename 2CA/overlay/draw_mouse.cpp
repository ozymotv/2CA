#define WIN32_LEAN_AND_MEAN
#define _WINSOCKAPI_
#include <winsock2.h>
#include <Windows.h>

#include <shellapi.h>

#include "imgui/imgui.h"
#include "2CA.h"
#include "include/other_tools.h"
#include "config.h"
//#include "mouse/kmbox/kmboxNet.h"
//#include "mouse/kmbox/kmboxNet.cpp"

std::string ghub_version = get_ghub_version();

void draw_mouse()
{
    // Existing mouse configuration UI
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

    ImGui::Separator();
}
