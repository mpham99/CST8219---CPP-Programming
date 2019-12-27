/**********************************************************************
Filename: AudioFrame.cpp
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
Purpose: Initialize variables and define the functions related to AudioFrame object
*********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
using namespace std;
#include "Frame.h"
#include "AudioFrame.h"

/********************************************************************
Function name: calculateFrameResource
Purpose: Overrided function to calculate the memory for each object
In parameters: none
Out parameters: none
Version: 1.0
Author: Minh Duc Pham
**********************************************************************/
void AudioFrame::CalculateFrameResource() {
	double calcSize = 0.0;
	cout << "Audio Frame: " << *(Frame*) this;
	cout << *this;
	for (int i = 0; i < 3; i++) {
		calcSize = size / COMPRESSION_RATIO[i];
		cout << "| " << setprecision(3) << calcSize << setw(3);
	}
	cout << "\n----------------------------------------------" << endl;
}

/************************************************1sn********************
Function name: operator<<
Purpose: Overloaded operator << to print out a AudioFrame members
In parameters: ostream& output, Frame& frame
Out parameters: ostream& output
Version: 1.0
Author: Minh Duc Pham
**********************************************************************/
ostream& operator<< (ostream& output, AudioFrame& RA) {
	int num = 128;

	output << "MP3 Lossy Compression " << endl;
	output << "----------------------------------------------" << endl;
	output << "bitrate (kbits/s):      ";
	for (int i = 0; i < 3; i++) {
		output << "| " << num << setw(4);
		num += 32;
	}
	output << "\n----------------------------------------------" << endl;
	output << "file size (MB):         ";
	
	return output;
}