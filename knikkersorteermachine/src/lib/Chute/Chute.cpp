/**
 * @file Chute.cpp
 * @author Jonas Claes (jonas@jonasclaes.be)
 * @brief Chute implementation.
 * @version 0.1
 * @date May 24, 2022
 * @copyright Copyright 2022
 */

#include "Chute.h"

using namespace KnikkerSorteerMachine;

Chute::Chute() = default;

Chute::~Chute() = default;

bool Chute::setup(uint8_t pin)
{
    servo.attach(pin);
    servo.write(positions[0]);
    return true;
}

void Chute::moveTo(uint8_t chute)
{
    if (chute > sizeof(this->positions)) return;
    servo.write(this->positions[chute]);
}

uint8_t Chute::getAmountOfPositions()
{
    return (sizeof(this->positions) / sizeof(*this->positions));
}