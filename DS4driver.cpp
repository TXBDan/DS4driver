/*
 * DS4driver.cpp
 *
 *  Created on: Mar 15, 2015
 *      Author: Dan
 */
#include "DS4driver.h"

using namespace std;

// constructor
DS4driver::DS4driver() {

	n = 0;
	fd = 0;

	leftV = 0;
	leftH = 0;
	rightV = 0;
	rightH = 0;
	L2analog = 0;
	R2analog = 0;

	btn_dleft = false;
	btn_dright = false;
	btn_dup = false;
	btn_ddown = false;
	btn_cross = false;
	btn_circle = false;
	btn_triangle = false;
	btn_square = false;
	btn_L1 = false;
	btn_L2 = false;
	btn_L3 = false;
	btn_R1 = false;
	btn_R2 = false;
	btn_R3 = false;
	btn_touchpad = false;
	btn_options = false;
	btn_ps = false;
	btn_share = false;
}

void DS4driver::init(char const*dev) {

	fd = open(dev, O_RDONLY);
	if (fd == -1) {
		fprintf(stderr, "Cannot open %s: %s.\n", dev, strerror(errno));
		exit(EXIT_FAILURE);
	}
}

//work in progress, no need to call
void DS4driver::close() {
	//close(fd);
}

bool DS4driver::update() {

	n = read(fd, &ev, sizeof ev);
	if (n == (ssize_t) -1 && errno != EINTR) {
		fflush(stdout);
		fprintf(stderr, "%s.\n", strerror(errno));
		return false; //break;
	} else if (n != sizeof ev) {
		errno = EIO;
		fflush(stdout);
		fprintf(stderr, "%s.\n", strerror(errno));
		return false; //break;
	}

	if (ev.type == EV_KEY) {
		if (ev.code == BTN_A) {
			btn_square = ev.value;
			//if(ev.value == 1) cout << "Square" << endl;
		}
		if (ev.code == BTN_B) {
			btn_cross = ev.value;
			//if(ev.value == 1) cout << "Cross" << endl;
		}
		if (ev.code == BTN_C) {
			btn_circle = ev.value;
			//if(ev.value == 1) cout << "Circle" << endl;
		}
		if (ev.code == BTN_X) {
			btn_triangle = ev.value;
			//if(ev.value == 1) cout << "Triangle" << endl;
		}
		if (ev.code == BTN_Y) {
			btn_L1 = ev.value;
			//if(ev.value == 1) cout << "L1" << endl;
		}
		if (ev.code == BTN_Z) {
			btn_R1 = ev.value;
			//if(ev.value == 1) cout << "R1" << endl;
		}
		if (ev.code == BTN_TL) {
			btn_L2 = ev.value;
			//if(ev.value == 1) cout << "L2" << endl;
		}
		if (ev.code == BTN_TR) {
			btn_R2 = ev.value;
			//if(ev.value == 1) cout << "R2" << endl;
		}
		if (ev.code == BTN_SELECT) {
			btn_L3 = ev.value;
			//if(ev.value == 1) cout << "L3" << endl;
		}
		if (ev.code == BTN_START) {
			btn_R3 = ev.value;
			//if(ev.value == 1) cout << "R3" << endl;
		}
		if (ev.code == BTN_THUMBL) {
			btn_touchpad = ev.value;
			//if(ev.value == 1) cout << "Touchpad" << endl;
		}
		if (ev.code == BTN_TR2) {
			btn_options = ev.value;
			//if(ev.value == 1) cout << "Options" << endl;
		}
		if (ev.code == BTN_MODE) {
			btn_ps = ev.value;
			//if(ev.value == 1) cout << "Playstation" << endl;
		}
		if (ev.code == BTN_TL2) {
			btn_share = ev.value;
			//if(ev.value == 1) cout << "Share" << endl;
		}

	} // end of EV_KEY

	if (ev.type == EV_ABS) {

		if (ev.code == ABS_HAT0X) {
			btn_dleft = btn_dright = false;
			if (ev.value == -1) {
				btn_dleft = true;
				//cout << "LEFT" << endl;
			}
			if (ev.value == 1) {
				btn_dright = true;
				//cout << "RIGHT" << endl;
			}
		}
		if (ev.code == ABS_HAT0Y) {
			btn_dup = btn_ddown = false;
			if (ev.value == -1) {
				btn_dup = true;
				//cout << "UP" << endl;
			}
			if (ev.value == 1) {
				btn_ddown = true;
				//cout << "DOWN" << endl;
			}
		}
		if (ev.code == ABS_X) {
			leftH = ev.value;	// 0 to 255, left to right
			//cout << "leftH:" << leftH << endl;
		}
		if (ev.code == ABS_Y) {
			leftV = ev.value; // 0 to 255, top to bottom
			//cout << "leftV:" << leftV << endl;
		}
		if (ev.code == ABS_Z) {
			rightH = ev.value;	// 0 to 255, left to right
			//cout << "rightH:" << rightH << endl;
		}
		if (ev.code == ABS_RZ) {
			rightV = ev.value; // 0 to 255, top to bottom
			//cout << "rightV:" << rightV << endl;
		}
		if (ev.code == ABS_RX) {
			L2analog = ev.value;	// 0 to 255, left to right
			//cout << "L2analog:" << L2analog << endl;
		}
		if (ev.code == ABS_RY) {
			R2analog = ev.value; // 0 to 255, top to bottom
			//cout << "R2analog:" << R2analog << endl;
		}

	} // end of EV_ABS

	return true;
}

