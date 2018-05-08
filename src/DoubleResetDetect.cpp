/* DoubleResetDetect.cpp
 *
 * Copyright (C) 2018 Jens-Christian Skibakk
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include <DoubleResetDetect.h>

DoubleResetDetect::DoubleResetDetect(float timeout, uint32_t address)
  : _timeout(timeout)
  , _address(address)
  , _status(-1)
{
}

bool DoubleResetDetect::detect()
{
  if (_status < 0)
  {
    uint32_t data;
    ESP.rtcUserMemoryRead(_address, &data, sizeof(data));
    _status = data == 0xAAAAAAAA ? 1 : 0;

    if (_status == 1)
    {
      clearFlag(_address);
    }
    else
    {
      data = 0xAAAAAAAA;
      ESP.rtcUserMemoryWrite(_address, &data, sizeof(data));

      _ticker.once(_timeout, clearFlag, _address);
    }
  }

  return _status == 1;
}

void DoubleResetDetect::clearFlag(const uint32_t address)
{
  uint32_t data = 0x5555555;
  ESP.rtcUserMemoryWrite(address, &data, sizeof(data));
}
