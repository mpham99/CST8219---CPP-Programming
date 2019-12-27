/**********************************************************************
Filename: Animation.cpp
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
Purpose: Initialize variables and define the functions related to Animation object
*********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <forward_list>
#include <iostream>
#include <string>
using namespace std;
#include "Frame.h"
#include "AudioFrame.h"
#include "VideoFrame.h"
#include "Animation.h"

/********************************************************************
Function name: ~Animation()
Purpose: Destructor for the Animation object
In parameters: none
Out parameters: none
Version: 1.0
Author: Minh Duc Pham
**********************************************************************/
Animation ::~Animation() {
	forward_list<Frame*>::iterator i;
	for (i = frames.begin(); i != frames.end(); i++)
		delete* i;
}

/********************************************************************
Function name: EditFrame
Purpose: Edit a selected frame inside the linked list to change the frame name
In parameters: none
Out parameters: none
Version: 1.0
Author: Minh Duc Pham
**********************************************************************/
void Animation::EditFrame() {
	string name, type;
	double size;
	forward_list<Frame*>::iterator i;
	int count = 0;
	int position;
	Frame* oldFrame;

	cout << "Edit a Frame in the Animation\n";
	/*If the linked list is empty*/
	if (frames.empty()) {
		cout << "There is no frame inside the Animation. Please add a frame first!\n";
		return;
	}

	/*Count the number of nodes inside the linked list*/
	for (i = frames.begin(); i != frames.end(); i++) {
		count++;
	}

	cout << "There are " << count << " Frame(s) in the list. Please specify the index (<= " << count - 1 << ") to edit at: ";
	cin >> position;

	if (cin.fail()) {
		cout << "Please enter a valid integer\n";
		cin.clear();
		cin.ignore(500, '\n');
		return;
	}

	if (position < 0) {
		cout << "Please enter a positive integer\n";
		return;
	}

	if (position > (count - 1)) {
		cout << "The index is not available in the linked list!\n";
		return;
	}

	count = 0;
	for (i = frames.begin(); i != frames.end(); i++) {
		if (count == position) {
			//Copy the selected frame to a dummy one to delete later
			oldFrame = *i;

			//Print the information out to the console
			cout << "The name and size of this Frame are " << *(Frame*) oldFrame << endl;

			//Enter the new Frame data
			cout << "Please enter the Frame frameName: ";
			cin >> name;

			cout << "Please enter the Frame size(MB): ";
			cin >> size;

			//Check the input the size
			if (cin.fail()) {
				cout << "Please enter a valid decimal\n";
				cin.clear();
				cin.ignore(500, '\n');
				return;
			}

			cout << "Please enter the Frame type (AudioFrame = A, VideoFrame = V): ";
			cin >> type;

			//Check the input of type
			if (type != "A" && type != "V") {
				cout << "Please enter the right type, either A or V!" << endl;
				return;
			}

			//Delete the old frame
			delete oldFrame;

			//Create a frame to add to the forward list
			if (type == "A") {
				AudioFrame* tempFrame = new AudioFrame(name, size);
				*i = tempFrame;
			}
			else {
				VideoFrame* tempFrame = new VideoFrame(name, size);
				*i = tempFrame;
			}
			
			cout << "Frame " << count << " edit completed\n";
			break;
		}
		count++;
	}

}

/********************************************************************
Function name: DeleteFrame
Purpose: Delete the first frame inside the Animation
In parameters: none
Out parameters: none
Version: 1.0
Author: Minh Duc Pham
**********************************************************************/
void Animation::DeleteFrame() {
	if (frames.empty()) {
		cout << "There is no frame to be deleted!\n";
		return;
	}

	Frame* deletedFrame = frames.front();
	frames.pop_front();
	delete[] deletedFrame;
	cout << "First Frame deleted" << endl;
}

/********************************************************************
Function name: operator>>
Purpose: Add a frame as in cin >> A
In parameters: istream& input, Animation& A
Out parameters: istream& input
Version: 1.0
Author: Minh Duc Pham
**********************************************************************/
istream& operator>>(istream& input, Animation& A) {
	string name;
	string type;
	double size;

	cout << "Insert a Frame in the Animation\n";
	cout << "Please enter the Frame frameName: ";
	input >> name;

	cout << "Please enter the Frame size(MB): ";
	input >> size;

	//Check the input of size
	if (input.fail()) {
		cout << "Please enter a valid decimal\n";
		input.clear();
		input.ignore(500, '\n');
		return input;
	}

	cout << " Please enter the Frame type (AudioFrame = A, VideoFrame = V): ";
	input >> type;

	//Check the input of type
	if (type != "A" && type != "V") {
		cout << "Please enter the right type, either A or V!" << endl;
		return input;
	}

	//Create a frame to add to the forward list
	if (type == "A") {
		AudioFrame* tempFrame = new AudioFrame(name, size);
		A.frames.push_front(tempFrame);
	}
	else {
		VideoFrame* tempFrame = new VideoFrame(name, size);
		A.frames.push_front(tempFrame);
	}

	cout << "Frame " << name << " Frame* added at the front of frames " << endl;

	return input;
}

/********************************************************************
Function name: operator<<
Purpose: Output the frame as in cout << A
In parameters: ostream& output, Animation& A
Out parameters: ostream& output
Version: 1.0
Author: Minh Duc Pham
**********************************************************************/
ostream& operator<<(ostream& output, Animation& A) {
	forward_list<Frame*>::iterator i;
	int count;
	count = 0;

	//Print the Animation name
	output << "Animation name is " << A.animationName << endl;
	output << "\tReport the Animation " << endl;

	//If the forward list is empty
	if (A.frames.empty()) {
		output << "\tNo frames in the Animation " << endl;
		return output;
	}

	//Else return all frames value
	for (i = A.frames.begin(); i != A.frames.end(); i++) {
		output << "Frame #" << count << endl;
		(*i)->CalculateFrameResource();
		count++;
	}

	//Return the output stream
	return output;
}
