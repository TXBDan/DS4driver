/*
 * DS4driver.h
 *
 *  Created on: Mar 15, 2015
 *      Author: Dan
 */

#ifndef DS4DRIVER_SRC_DS4DRIVER_H_
#define DS4DRIVER_SRC_DS4DRIVER_H_

#include <cstdio>
#include <unistd.h>
#include <cstdlib>
#include <fcntl.h>
#include <cerrno>
#include <linux/input.h>
#include <cstring>
#include <iostream>

class DS4driver {

private:
	int fd;
	struct input_event ev;
	ssize_t n;

public:
	DS4driver();

	// analog values 0-255
	short leftV;
	short leftH;
	short rightV;
	short rightH;
	short L2analog;
	short R2analog;

	// binary
	bool btn_dleft;
	bool btn_dright;
	bool btn_dup;
	bool btn_ddown;
	bool btn_cross;
	bool btn_circle;
	bool btn_triangle;
	bool btn_square;
	bool btn_L1;
	bool btn_L2;
	bool btn_L3;
	bool btn_R1;
	bool btn_R2;
	bool btn_R3;
	bool btn_touchpad;
	bool btn_options;
	bool btn_ps;
	bool btn_share;

	void init(char const*dev);
	bool update();
	void close();

};

#endif /* DS4DRIVER_SRC_DS4DRIVER_H_ */
