/*
 *  Example for DS4driver
 */

#include "mraa.hpp"

#include <iostream>
#include <unistd.h>
#include "DS4driver.h"

/*
 */
using namespace std;

int main()
{
	//mraa_platform_t platform = mraa_get_platform_type();
	mraa::Gpio* d_pin = NULL;
	d_pin = new mraa::Gpio(13, true, false);

	if (d_pin == NULL) {
		std::cerr << "Can't create mraa::Gpio object, exiting" << std::endl;
		return MRAA_ERROR_UNSPECIFIED;
	}
	// set the pin as output
	if (d_pin->dir(mraa::DIR_OUT) != MRAA_SUCCESS) {
		std::cerr << "Can't set digital pin as output, exiting" << std::endl;
		return MRAA_ERROR_UNSPECIFIED;
	}

	DS4driver myDS4;

	myDS4.init("/dev/input/event2");

	cout << "DS4 Driver test program" << endl;

	// loop forever toggling the on board LED every second
	while (1) {

		if( myDS4.update() == 0){ // 0 means error
			break;
		}

		//cout << "Left is: " << myDS4.btn_dleft << endl;
		//cout << "Cross is:     " << myDS4.btn_cross << endl;

		if( myDS4.btn_square == true ){
			d_pin->write(1);
		}
		else d_pin->write(0);

		sleep(.01);
	}

}
