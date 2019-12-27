/**********************************************************************
Filename: Frame.cpp
Version: 1.0
Author:	Minh Duc Pham
Student No: 040905103
Course Name/Number:	C++ Programming CST8219
Lab Section: 313
Assignment #: 3
Assignment name: Animation Project in C++
Due Date: November 30th 2019
Submission Date: November 27th 2019 
Professor:	Mohammed Abouseif
Purpose: Initialize variables and define the functions related to Frame object
*********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "Frame.h"

/********************************************************************
Function name: operator<<
Purpose: Overloaded operator << to print out a Frame members
In parameters: ostream& output, Frame& frame
Out parameters: ostream& output
Version: 1.0
Author: Minh Duc Pham
**********************************************************************/
ostream& operator<< (ostream& output, Frame& frame) {
	output << "frameName = " << frame.frameName << endl;
	return output; 
}