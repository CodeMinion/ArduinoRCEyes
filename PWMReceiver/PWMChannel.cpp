#include "Arduino.h"
#include "PWMChannel.h"

PWMChannel::PWMChannel(int channelPin, int threshold)
{
	_channelPin = channelPin;
	pinMode(_channelPin, INPUT);
	_threshold = threshold;
	_prevRead = -1;
	_centerRead = 0;
}

int PWMChannel::readPulse()
{
	// Read a pulse
	_currRead = pulseIn(_channelPin, HIGH, 25000);
	
	// Check if the current reading surpasses the last
	// by the threshold or more.
	if(abs(_prevRead - _currRead)>_threshold)
	{
		// Find out the duration when the stick is
		// centered.
		if(_centerRead ==0 || _currRead == 0)
		{
			_centerRead =_currRead;
		}
		
		
		if(abs(_currRead - _centerRead)<_threshold)
		{
			_currRead = _centerRead;
		}
		_prevRead = _currRead;
	}
	
	return _prevRead;
	
}

int PWMChannel::getPulseDifference()
{
	return _prevRead - _centerRead;
}

void PWMChannel::setThreshold(int threshold)
{
	_threshold = threshold;
}