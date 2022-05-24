/**
 * @file MessageParser.cpp
 * @author Jonas Claes (jonas@jonasclaes.be)
 * @brief Message parser implementation.
 * @version 0.1
 * @date May 24, 2022
 * @copyright Copyright 2022
 */

#include "MessageParser.h"

using namespace KnikkerSorteerMachine;

MessageParser::MessageParser() = default;

MessageParser::~MessageParser() = default;

bool MessageParser::setup()
{
    int retries{0};

    // Open the serial port at baud 115200.
    Serial.begin(115200);
    while (!Serial) {
        if (retries > 10) return false;

        retries += 1;
        delay(500);
    }

    Serial.println("READY");

    return true;
}

void MessageParser::loop()
{
    if (Serial.available() == 2) {
        byte data[2];
        Serial.readBytes(data, 2);
        this->message.command = data[0];
        this->message.value = data[1];
        this->messageAvailable = true;
    }
}

bool MessageParser::isMessageAvailable()
{
    return this->messageAvailable;
}

Message MessageParser::getMessage()
{
    this->messageAvailable = false;
    return this->message;
}