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

#include "Arduino.h"
#include "ButterworthFilter.h"

// Constructor /////////////////////////////////////////////////////////////////
// Function that handles the creation and setup of instances

ButterworthFilter::ButterworthFilter(uint8_t _gain)
{
	// initialize this instance's variables
	error = 1;
	if (_gain<=0) error =-1;			// incorrect Gain variable
	if (_gain>10) error =-2;			// incorrect Gain variable

	//Set initial values	
	gain			= _gain;		//
	x			= 0;			// 
	y			= 0;			//

}


// Public Methods //////////////////////////////////////////////////////////////
// Update the Status of this Filter with the Last available Read and 

uint16_t ButterworthFilter::UpdateFilter(uint16_t x0)
{
uint16_t x1,y1,y0,ay1;
uint16_t temp0,temp1;

	if (error < 0) return error;            // bad constructor variables

	x1 = x;
	y1 = y;

	temp0 = y1>>2;
	temp1 = y1>>4;
	ay1   = y1 - temp0 + temp1;

	//1st order filter equation
	// y[0] = x[0] + x[1] + a.y[1]
	y0 = x0 + x1 + ay1;
	
	//Store current values
	//y = y0;		// 
	y = y0>>gain;
	x = x0;

	//return y0>>gain;
	return y;	
}



// Private Methods /////////////////////////////////////////////////////////////
// Functions only available to other functions in this library


// /////////////////////////////////////////////////////////////////////////////

