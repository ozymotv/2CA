#ifndef RAZERHOOK_H
#define RAZERHOOK_H

#include <windows.h>
#include <string>
#include <vector>
#include <utility>
#include <filesystem>
#include <stdexcept>

enum class MouseClick {
    LEFT_DOWN = 1,
    LEFT_UP = 2,
    RIGHT_DOWN = 4,
    RIGHT_UP = 8,
    SCROLL_CLICK_DOWN = 16,
    SCROLL_CLICK_UP = 32,
    BACK_DOWN = 64,
    BACK_UP = 128,
    FORWARD_DOWN = 256,
    FORWARD_UP = 512,
    SCROLL_DOWN = 4287104000,
    SCROLL_UP = 7865344
};

enum class KeyboardInputType {
    KEYBOARD_DOWN = 0,
    KEYBOARD_UP = 1
};

class RazerHook {
private:
    HINSTANCE dllHandle;
    std::filesystem::path basedir;
    std::filesystem::path dlldir;
    
    using InitFunc = BOOL (*)();
    using MouseMoveFunc = void (*)(int, int, BOOL);
    using MouseClickFunc = void (*)(int);
    using KeyboardInputFunc = void (*)(SHORT, int);
    
    InitFunc init;
    MouseMoveFunc mouse_move;
    MouseClickFunc mouse_click;
    KeyboardInputFunc keyboard_input;

    void setupFunctions();

public:
    RazerHook();
    ~RazerHook();

    RazerHook(const RazerHook&) = delete;
    RazerHook& operator=(const RazerHook&) = delete;

    bool initialize();
    void moveMouse(int x, int y, bool from_start_point = false);
    void processMoveInstructions(const std::vector<std::pair<int, int>>& instructions, bool from_start_point = false, DWORD delay_ms = 0);
    void sendKeyboardInput(short scan_code, KeyboardInputType up_down);
    void mouseClick(MouseClick click_type);
    bool mouse_xy(int x, int y);
    bool mouse_down(int key = 1);
    bool mouse_up(int key = 1);
    bool mouse_close();
};

#endif 
// kuyo was here | kuyo.lol