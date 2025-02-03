import ctypes
import ctypes.wintypes as wintypes
import os
from settings import Settings
from colorbot import Colorbot
from capture import Capture

class Main:
    def __init__(self):
        # Initialize settings and capture
        self.settings = Settings()
        self.capture = Capture()  # Instantiate the singleton Capture class
        self.capture.start()  # Start the capture thread
        
        # Retrieve capture and aim settings
        self.CENTER_X, self.CENTER_Y = self.capture.screen_x_center, self.capture.screen_y_center
        self.XFOV = self.settings.get_int('AIMBOT', 'xFov')
        self.YFOV = self.settings.get_int('AIMBOT', 'yFov')
        
        # Initialize the Colorbot
        self.colorbot = Colorbot(self.CENTER_X - self.XFOV // 2, self.CENTER_Y - self.YFOV // 2, self.XFOV, self.YFOV)

    def better_cmd(self, width, height):
        hwnd = ctypes.windll.kernel32.GetConsoleWindow()
        if hwnd:
            style = ctypes.windll.user32.GetWindowLongW(hwnd, -16)
            style &= ~0x00080000  # Remove WS_MAXIMIZEBOX
            style &= ~0x00C00000  # Remove WS_SIZEBOX
            ctypes.windll.user32.SetWindowLongW(hwnd, -16, style)
        
        STD_OUTPUT_HANDLE_ID = -11
        windll = ctypes.windll.kernel32
        handle = windll.GetStdHandle(STD_OUTPUT_HANDLE_ID)

        if not handle:
            raise Exception("Failed to get standard output handle")

        # Set console buffer size
        windll.SetConsoleScreenBufferSize(handle, wintypes._COORD(width, height))

        # Set console window size
        rect = wintypes.SMALL_RECT(0, 0, width - 1, height - 1)
        windll.SetConsoleWindowInfo(handle, True, ctypes.byref(rect))

        ctypes.windll.user32.ShowWindow(hwnd, 3)
        ctypes.windll.kernel32.SetConsoleTitleW(f"Sunone Aimbot - {width}x{height}")
        os.system(f"mode con: cols={width} lines={height}")

    def info(self):
        os.system('cls')
        print('Enemy Outline Color: Purple')

    def run(self):
        self.better_cmd(120, 30)
        self.info()
        self.colorbot.listen()

if __name__ == '__main__':
    main = Main()
    main.run()
