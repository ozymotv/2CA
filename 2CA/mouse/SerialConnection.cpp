#include "SerialConnection.h"

// Constructor: Initializes state variables but does not open a connection.
SerialConnection::SerialConnection(const std::string& port, unsigned int baud_rate)
    : aiming_active(false),
    shooting_active(false),
    zooming_active(false),
    is_open_(false),
    timer_running_(false),
    listening_(false)
{
    // Do nothing
}

// Destructor: No cleanup or thread joining needed.
SerialConnection::~SerialConnection()
{
    // Do nothing
}

// Returns false since no actual connection is established.
bool SerialConnection::isOpen() const {
    return false;
}

// Does nothing.
void SerialConnection::write(const std::string& data) {
    // Do nothing
}

// Returns an empty string.
std::string SerialConnection::read() {
    return "";
}

// Does nothing.
void SerialConnection::click() {
    // Do nothing
}

// Does nothing.
void SerialConnection::press() {
    // Do nothing
}

// Does nothing.
void SerialConnection::release() {
    // Do nothing
}

// Does nothing.
void SerialConnection::move(int x, int y) {
    // Do nothing
}

// Private: Does nothing.
void SerialConnection::sendCommand(const std::string& command) {
    // Do nothing
}

// Private: Returns an empty vector.
std::vector<int> SerialConnection::splitValue(int value) {
    return std::vector<int>();
}

// Private: Does nothing.
void SerialConnection::startTimer() {
    // Do nothing
}

// Private: Does nothing.
void SerialConnection::startListening() {
    // Do nothing
}

// Private: Does nothing.
void SerialConnection::processIncomingLine(const std::string& line) {
    // Do nothing
}

// Thread function: Does nothing.
void SerialConnection::timerThreadFunc() {
    // Do nothing
}

// Thread function: Does nothing.
void SerialConnection::listeningThreadFunc() {
    // Do nothing
}
