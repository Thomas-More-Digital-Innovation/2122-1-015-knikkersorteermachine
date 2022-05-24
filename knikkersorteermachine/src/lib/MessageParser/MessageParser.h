/**
 * @file MessageParser.h
 * @author Jonas Claes (jonas@jonasclaes.be)
 * @brief Message parser header.
 * @version 0.1
 * @date May 24, 2022
 * @copyright Copyright 2022
 */

#ifndef KNIKKERSORTEERMACHINE_MESSAGEPARSER
#define KNIKKERSORTEERMACHINE_MESSAGEPARSER

#include <Arduino.h>

namespace KnikkerSorteerMachine
{
    enum MessageCommand
    {
        HELLO,
        CHUTE,
        FEEDER,
    };

    struct Message
    {
        uint8_t command;
        uint8_t value;
    };

    class MessageParser
    {
    private:
        bool messageAvailable{false};
        Message message{0, 0};
    public:
        MessageParser(/* args */);
        ~MessageParser();

        bool setup();
        void loop();

        bool isMessageAvailable();
        Message getMessage();
    };
} // namespace KnikkerSorteerMachine

#endif
