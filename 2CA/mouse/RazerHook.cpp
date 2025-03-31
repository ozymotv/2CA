#include "RazerHook.h"
#include <iostream>

void RazerHook::setupFunctions() {
    init = reinterpret_cast<InitFunc>(GetProcAddress(dllHandle, "init"));
    mouse_move = reinterpret_cast<MouseMoveFunc>(GetProcAddress(dllHandle, "mouse_move"));
    mouse_click = reinterpret_cast<MouseClickFunc>(GetProcAddress(dllHandle, "mouse_click"));
    keyboard_input = reinterpret_cast<KeyboardInputFunc>(GetProcAddress(dllHandle, "keyboard_input"));
    
    if (!init || !mouse_move || !mouse_click || !keyboard_input) {
        throw std::runtime_error("[Razer] Failed to get function pointers from DLL");
    }
}

RazerHook::RazerHook() {
    char buffer[MAX_PATH];
    GetModuleFileNameA(NULL, buffer, MAX_PATH);
    basedir = std::filesystem::path(buffer).parent_path();
    dlldir = basedir / "razer_hook.dll";
    
    dllHandle = LoadLibraryA(dlldir.string().c_str());
    if (!dllHandle) {
        throw std::runtime_error("[Razer] Failed to load DLL");
    }
    setupFunctions();
}

RazerHook::~RazerHook() {
    if (dllHandle) {
        FreeLibrary(dllHandle);
        dllHandle = nullptr;
    }
}

bool RazerHook::initialize() {
    BOOL result = init();
    if (!result) {
        std::cerr << "[Razer] Failed to initialize device" << std::endl;
        return false;
    }
    return true;
}

void RazerHook::moveMouse(int x, int y, bool from_start_point) {
    if (!from_start_point && (x == 0 && y == 0)) {
        return;
    }
    mouse_move(x, y, from_start_point);
}

void RazerHook::processMoveInstructions(const std::vector<std::pair<int, int>>& instructions, bool from_start_point, DWORD delay_ms) {
    for (const auto& [x, y] : instructions) {
        moveMouse(x, y, from_start_point);
        if (delay_ms > 0) {
            Sleep(delay_ms);
        }
    }
}

void RazerHook::sendKeyboardInput(short scan_code, KeyboardInputType up_down) {
    keyboard_input(scan_code, static_cast<int>(up_down));
}

void RazerHook::mouseClick(MouseClick click_type) {
    mouse_click(static_cast<int>(click_type));
}

bool RazerHook::mouse_xy(int x, int y) {
    moveMouse(x, y, false);
    return true;
}

bool RazerHook::mouse_down(int key) {
    if (key == 1) {
        mouseClick(MouseClick::LEFT_DOWN);
    } else {
        mouseClick(MouseClick::RIGHT_DOWN);
    }
    return true;
}

bool RazerHook::mouse_up(int key) {
    if (key == 1) {
        mouseClick(MouseClick::LEFT_UP);
    } else {
        mouseClick(MouseClick::RIGHT_UP);
    }
    return true;
}

bool RazerHook::mouse_close() {
    return true;
}
