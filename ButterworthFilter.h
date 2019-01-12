/*
  ButterworthFilter.h v.01 - Library for 'duino
  https://github.com/newEndeavour/ButterworthFilter

  Implementation of a Butterworth Low Pass Filter with alpha = 0.8125, and Gain = 3
  see: http://ww1.microchip.com/downloads/en/appnotes/00001334b.pdf, p22/23.

  Copyright (c) 2019 Jerome Drouin  All rights reserved.

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
 
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
 
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/


// ensure this library description is only included once
#ifndef ButterworthFilter_h
#define ButterworthFilter_h

#include "Arduino.h"


// library interface description
class ButterworthFilter
{
  // user-accessible "public" interface
  public:
  // methods
	ButterworthFilter(uint8_t _gain);
	uint16_t UpdateFilter(uint16_t lastRead);

  // library-accessible "private" interface
  private:
  // variables
	int 		error;
	uint8_t		gain;
	uint16_t	y;		// 
	uint16_t	x;		// 

	
  // methods
};

#endif
