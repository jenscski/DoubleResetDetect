/* DoubleResetDetect.cpp
 *
 * Copyright (C) 2018 Jens-Christian Skibakk
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include <Arduino.h>
#include <Ticker.h>

class DoubleResetDetect
{
  public:
    // Constructor
    DoubleResetDetect(float, uint32_t);

    // Functions
    bool detect(void);

  private:
    // Variables
    float _timeout;
    uint32_t _address;
    int8_t _status;
    Ticker _ticker;

    // Functions
    static void clearFlag(uint32_t address);
};
