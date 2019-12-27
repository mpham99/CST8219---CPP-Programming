/**********************************************************************
Filename: Frame.cpp
Version: 1.0
Author:	Minh Duc Pham
Student No: 040905103
Course Name/Number:	C++ Programming CST8219
Lab Section: 313
Assignment #: 2
Assignment name: Animation Project in C++
Due Date: November 11th 2019
Submission Date: November 7th 2019 
Professor:	Mohammed Abouseif
Purpose: Initialize variables and define the functions related to Frame object
*********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Frame.h"
using namespace std;

/********************************************************************
Function name: Frame
Purpose: Initialize values for a Frame object
In parameters: char* frameName, double duration
Out parameters: none
Version: 1.0
Author: Minh Duc Pham
**********************************************************************/
Frame::Frame(char* frameName, double duration) {
	//Copy the name
	this->frameName = new char[strlen(frameName) + 1];
	strcpy(this->frameName, frameName);

	//Copy the duration
	this->duration = duration;
}

/********************************************************************
Function name: Frame
Purpose: Initialize values for a Frame object
In parameters: const Frame& frame
Out parameters: none
Version: 1.0
Author: Minh Duc Pham
**********************************************************************/
Frame::Frame(const Frame& frame) {
	this->frameName = new char[strlen(frame.frameName) + 1];
	strcpy(this->frameName, frame.frameName);

	//Copy the duration
	this->duration = frame.duration;
}

/********************************************************************
Function name: ~Frame
Purpose: Free the allocated memory for frameName
In parameters: none
Out parameters: none
Version: 1.0
Author: Minh Duc Pham
**********************************************************************/
Frame::~Frame() {
	delete[] this->frameName;
}

/********************************************************************
Function name: operator=
Purpose: Overloaded operator = to initialize a Frame
In parameters: const Frame& frame
Out parameters: Frame& newFrame
Version: 1.0
Author: Minh Duc Pham
**********************************************************************/
Frame& Frame::operator= (const Frame& frame) {
	//Copy the name
	delete [] this->frameName;
	this->frameName = new char[strlen(frame.frameName) + 1];
	strcpy(this->frameName, frame.frameName);

	//Copy the duration
	this->duration = frame.duration;

	return *this;
}

/********************************************************************
Function name: operator<<
Purpose: Overloaded operator << to print out a Frame members
In parameters: ostream& output, Frame& frame
Out parameters: ostream& output
Version: 1.0
Author: Minh Duc Pham
**********************************************************************/
ostream& operator<< (ostream& output, Frame& frame) {
	output << "frameName = " << frame.frameName << "; duration = " << frame.duration;
	return output;
}