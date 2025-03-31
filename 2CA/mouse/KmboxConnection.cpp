// SerialConnection.cpp
#include "SerialConnection.h"

SerialConnection::SerialConnection(const std::string& port, unsigned int baud_rate)
{
    // Dummy constructor: do nothing
}

SerialConnection::~SerialConnection()
{
    // Dummy destructor: do nothing
}

bool SerialConnection::isOpen() const
{
    return false;  // Always return false for the dummy implementation
}

void SerialConnection::write(const std::string& data)
{
    // Do nothing
}

std::string SerialConnection::read()
{
    return "";
}
