/**
 * @file Feeder.cpp
 * @author Jonas Claes (jonas@jonasclaes.be)
 * @brief Feeder implementation.
 * @version 0.1
 * @date May 24, 2022
 * @copyright Copyright 2022
 */

#include "Feeder.h"

using namespace KnikkerSorteerMachine;

Feeder::Feeder() = default;

Feeder::~Feeder() = default;

bool Feeder::setup(uint8_t directionPin, uint8_t stepPin)
{
    this->directionPin = directionPin;
    this->stepPin = stepPin;

    pinMode(this->directionPin, OUTPUT);
    pinMode(this->stepPin, OUTPUT);

    return true;
}

void Feeder::feed()
{
    digitalWrite(this->directionPin, LOW);

    for (int i = 0; i < 27; i++)
    {
        digitalWrite(this->stepPin, HIGH);
        delayMicroseconds(3000);

        digitalWrite(this->stepPin, LOW);
        delayMicroseconds(3000);
    }
    
}

void Feeder::feed(int positions)
{
    for (int i = 0; i < positions; i++)
    {
        this->feed();
    }
}