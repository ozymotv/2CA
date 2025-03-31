#ifndef SERIALCONNECTION_H
#define SERIALCONNECTION_H

#include <string>

class SerialConnection
{
public:
    SerialConnection(const std::string& port, unsigned int baud_rate) {}
    ~SerialConnection() {}

    bool isOpen() const { return false; }

    void write(const std::string& data) {}
    std::string read() { return ""; }

    // Dummy flags, always false
    bool aiming_active = false;
    bool shooting_active = false;
    bool zooming_active = false;
};

#endif // SERIALCONNECTION_H
