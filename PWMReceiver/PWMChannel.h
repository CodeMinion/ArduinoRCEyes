#ifndef PWMChannel_h
#define PWMChannel_h

#include "Arduino.h"

/**
 * Simple class to handle the reading of 
 * PWM pulses in an Arduino.
 *
 * Author: Frank Hernandez
 * Date: October 2013
 *
 * Note: Make sure to place this header and 
 * the accompanying cpp files in the Libraries
 * folder of your Arduino installation.
 */
class PWMChannel
{
	public:
		PWMChannel(int channelPin, int threshold);
		/**
		 * Returns the pulse received from the 
		 * attached channel.
		 **/
		int readPulse();
		
		/**
		 * Returns the difference between the current 
		 * pulse and the last pulse received. 
		 **/
		int getPulseDifference();
		
		/**
		 * Sets the threshold to what to consider 
		 * a reading, useful to ignore noise readings.
		 */
		void setThreshold(int threshold);
		
		
	private:
		int _threshold;
		int _prevRead;
		int _channelPin;
		int _currRead;
		int _centerRead;
};

#endif