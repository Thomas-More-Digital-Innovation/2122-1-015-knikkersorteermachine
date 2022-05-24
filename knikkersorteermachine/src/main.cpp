/**
 * @file main.cpp
 * @author Jonas Claes (jonas@jonasclaes.be)
 * @brief Main application entry point.
 * @version 0.1
 * @date May 24, 2022
 * @copyright Copyright 2022
 */

#include "App.h"

// Fancy C hack to let the processor force-reset.
// This is done using a null-pointer, yay!
void (* reset) (void) = 0;

KnikkerSorteerMachine::App app;

void setup() {
  if (!app.setup()) reset();
}

void loop() {
  app.loop();
}
