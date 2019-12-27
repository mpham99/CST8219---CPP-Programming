/**********************************************************************
Filename: Frame.cpp
Version: 1.0
Author:	Minh Duc Pham
Student No: 040905103 
Course Name/Number:	C++ Programming CST8219
Lab Section: 313
Assignment #: 1
Assignment name: Animation Project in C++
Due Date: October 12th 2019
Submission Date: October 11th 2019
Professor:	Mohammed Abouseif
Purpose: Initialize variables and define the functions related to Frame object
*********************************************************************/

#include "Frame.h"
#include "Animation.h"
using namespace std;

/********************************************************************
Function name: Frame
Purpose: Initialize values for a Frame object
In parameters: none
Out parameters: none
Version: 1.0
Author: Minh Duc Pham
**********************************************************************/
Frame::Frame() {
	frameName = nullptr;
	pNext = nullptr;
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
	delete [] frameName;
}