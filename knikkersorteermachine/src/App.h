/**
 * @file App.h
 * @author Jonas Claes (jonas@jonasclaes.be)
 * @brief Main application header.
 * @version 0.1
 * @date May 24, 2022
 * @copyright Copyright 2022
 */

#ifndef KNIKKERSORTEERMACHINE_APP
#define KNIKKERSORTEERMACHINE_APP

#include <Arduino.h>
#include "lib/Chute/Chute.h"
#include "lib/Feeder/Feeder.h"
#include "lib/MessageParser/MessageParser.h"

namespace KnikkerSorteerMachine
{
    class App
    {
    private:
        unsigned long timer{millis()};
        Chute chute;
        Feeder feeder;
        MessageParser messageParser;
    public:
        App(/* args */);
        ~App();

        bool setup();
        void loop();
    };
} // namespace KnikkerSorteerMachine

#endif
