/* Minimal.ino
 *
 * Copyright (C) 2018 Jens-Christian Skibakk
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include <DoubleResetDetect.h>

// maximum number of seconds between resets that
// counts as a double reset 
#define DRD_TIMEOUT 2.0

// address to the block in the RTC user memory
// change it if it collides with another usage 
// of the address block
#define DRD_ADDRESS 0x00

DoubleResetDetect drd(DRD_TIMEOUT, DRD_ADDRESS);

void setup()
{
    Serial.begin(74880);

    Serial.println();
    Serial.println("***************************************");
    Serial.println("* Minimal double reset detect example *");
    Serial.println("***************************************");
    Serial.println();

    if (drd.detect())
    {
        Serial.println("** Double reset boot **");
    }
    else
    {
        Serial.println("** Normal boot **");
    }
}

void loop()
{
    // do stuff here
}