/**********************************************************************
Filename: VideoFrame.cpp
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
Purpose: Initialize variables and define the functions related to VideoFrame object
*********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
using namespace std;
#include "Frame.h"
#include "VideoFrame.h"


/********************************************************************
Function name: calculateFrameResource
Purpose: Overrided function to calculate the memory for each object
In parameters: none
Out parameters: none
Version: 1.0
Author: Minh Duc Pham
**********************************************************************/
void VideoFrame::CalculateFrameResource() {
	double calcSize = 0.0;
	cout << "Video Frame: " << *(Frame*) this;
	cout << *this;
	for (int i = 0; i < BITS; i++) {
		calcSize = size / (COMPRESSION_RATIO*BITDEPTH_FACTOR[i]);
		cout << "| " << setprecision(4) << calcSize << setw(4);
	}
	cout << "\n--------------------------------------------------------------------------------------------" << endl;
}

/**********************************************************************
Function name: operator<<
Purpose: Overloaded operator << to print out a AudioFrame members
In parameters: ostream& output, VideoFrame& RV
Out parameters: ostream& output
Version: 1.0
Author: Minh Duc Pham
**********************************************************************/
ostream& operator<< (ostream& output, VideoFrame& RV) {
	int num = 2;

	output << "Lempel-Ziv-Welch Lossless Compression " << endl;
	output << "--------------------------------------------------------------------------------------------" << endl;
	output << "colours:        ";
	for (int i = 0; i < 8; i++) {
		output << "| " << num;
		if (num < 10)
			output << setw(8);
		else if (num < 100)
			output << setw(7);
		else
			output << setw(6);
		num*=2;
	}
	output << "\n--------------------------------------------------------------------------------------------" << endl;
	output << "file size (MB): ";
	
	return output;
}

