/**
 * @file Chute.h
 * @author Jonas Claes (jonas@jonasclaes.be)
 * @brief Chute header.
 * @version 0.1
 * @date May 24, 2022
 * @copyright Copyright 2022
 */

#ifndef KNIKKERSORTEERMACHINE_CHUTE
#define KNIKKERSORTEERMACHINE_CHUTE

#include <Servo.h>

namespace KnikkerSorteerMachine
{
    class Chute
    {
    private:
        Servo servo;
        const int positions[7]{ 160, 143, 123, 103, 82, 62, 42 };
    public:
        Chute();
        ~Chute();

        bool setup(uint8_t pin);
        void moveTo(uint8_t chute);
        uint8_t getAmountOfPositions();
    };
} // namespace KnikkerSorteerMachine

#endif
