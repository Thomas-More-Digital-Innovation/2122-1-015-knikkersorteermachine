/**
 * @file App.cpp
 * @author Jonas Claes (jonas@jonasclaes.be)
 * @brief Main application implementation.
 * @version 0.1
 * @date May 24, 2022
 * @copyright Copyright 2022
 */

#include "App.h"

using namespace KnikkerSorteerMachine;

App::App() = default;

App::~App() = default;

bool App::setup()
{
    // Setup the Chute module on pin 11.
    if (!chute.setup(11)) return false;

    // Setup the Feeder module on pin 9 and 10.
    if (!feeder.setup(9, 10)) return false;

    // Setup the MessageParser module.
    if (!messageParser.setup()) return false;

    return true;
}

void App::loop()
{
    messageParser.loop();

    if (messageParser.isMessageAvailable())
    {
        Message message = messageParser.getMessage();
        Serial.print(message.command, message.value);

        if (message.command == MessageCommand::CHUTE)
        {
            chute.moveTo(message.value);
        }

        if (message.command == MessageCommand::FEEDER)
        {
            if (message.value == 0)
            {
                feeder.feed();
            } else {
                feeder.feed(message.value);
            }
        }
    }
}