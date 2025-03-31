#ifndef MOUSE_H
#define MOUSE_H

#include <mutex>
#include <atomic>
#include <chrono>
#include <vector>
#include <utility>

#include "AimbotTarget.h"
//#include "SerialConnection.h"
//#include "KmboxConnection.h"
#include "ghub.h"

class MouseThread
{
private:
    double screen_width;
    double screen_height;
    double dpi;
    double prediction_interval;
    double mouse_sensitivity;
    double fov_x;
    double fov_y;
    double max_distance;
    double min_speed_multiplier;
    double max_speed_multiplier;
    double center_x;
    double center_y;
    bool   auto_shoot;
    float  bScope_multiplier;

    double prev_x, prev_y;
    double prev_velocity_x, prev_velocity_y;
    std::chrono::time_point<std::chrono::steady_clock> prev_time;
    std::chrono::steady_clock::time_point last_target_time;
    std::atomic<bool> target_detected{ false };
    std::atomic<bool> mouse_pressed{ false };

    //SerialConnection* serial;
    //KmboxConnection* kmbox;
    GhubMouse* gHub;

    std::vector<std::pair<double, double>> futurePositions;
    std::mutex futurePositionsMutex;

    std::pair<double, double> calc_movement(double target_x, double target_y);
    double calculate_speed_multiplier(double distance);
    void sendMovementToDriver(int move_x, int move_y);

public:
    std::mutex input_method_mutex;

    MouseThread(
        int resolution,
        int dpi,
        double sensitivity,
        int fovX,
        int fovY,
        double minSpeedMultiplier,
        double maxSpeedMultiplier,
        double predictionInterval,
        bool auto_shoot,
        float bScope_multiplier,
        //SerialConnection* serialConnection = nullptr,
        GhubMouse* gHub = nullptr
        //KmboxConnection* kmboxConnection = nullptr
    );

    void updateConfig(int resolution, double dpi, double sensitivity, int fovX, int fovY,
        double minSpeedMultiplier, double maxSpeedMultiplier,
        double predictionInterval, bool auto_shoot, float bScope_multiplier);

    void moveMousePivot(double pivotX, double pivotY);
    std::pair<double, double> predict_target_position(double target_x, double target_y);
    void moveMouse(const AimbotTarget& target);
    void pressMouse(const AimbotTarget& target);
    void releaseMouse();
    void resetPrediction();
    void checkAndResetPredictions();
    bool check_target_in_scope(double target_x, double target_y, double target_w, double target_h, double reduction_factor);

    std::vector<std::pair<double, double>> predictFuturePositions(double pivotX, double pivotY, int frames);
    void storeFuturePositions(const std::vector<std::pair<double, double>>& positions);
    void clearFuturePositions();
    std::vector<std::pair<double, double>> getFuturePositions();

    //void setSerialConnection(SerialConnection* newSerial);
   // void setKmboxConnection(KmboxConnection* newKmbox);
    void setGHubMouse(GhubMouse* newGHub);

    void setTargetDetected(bool detected)
    {
        target_detected.store(detected);
    }

    void setLastTargetTime(const std::chrono::steady_clock::time_point& time)
    {
        last_target_time = time;
    }
};

#endif // MOUSE_H
