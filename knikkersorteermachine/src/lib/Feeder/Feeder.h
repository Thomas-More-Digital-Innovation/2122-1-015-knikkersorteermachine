/**
 * @file Feeder.h
 * @author Jonas Claes (jonas@jonasclaes.be)
 * @brief Feeder header.
 * @version 0.1
 * @date May 24, 2022
 * @copyright Copyright 2022
 */

#ifndef KNIKKERSORTEERMACHINE_FEEDER
#define KNIKKERSORTEERMACHINE_FEEDER

#include <Arduino.h>

namespace KnikkerSorteerMachine
{
    class Feeder
    {
    private:
        uint8_t directionPin;
        uint8_t stepPin;
    public:
        Feeder(/* args */);
        ~Feeder();

        bool setup(uint8_t directionPin, uint8_t stepPin);
        void feed();
        void feed(int positions);
    };
} // namespace KnikkerSorteerMachine

#endif
