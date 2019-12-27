/**********************************************************************
Filename: Animation.cpp
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
Purpose: Initialize variables and define the functions related to Animation object
*********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include "Frame.h"
#include "Animation.h"
#include <iostream>

using namespace std;

/********************************************************************
Function name: Animation
Purpose: Initialize values for a Frame object
In parameters: none
Out parameters: none
Version: 1.0
Author: Minh Duc Pham
**********************************************************************/
Animation::Animation() {
	char name[100];
	name[0] = '\0';

	cout << "Please enter the Animaiton name: ";
	cin >> name;

	animationName = new char[strlen(name) + 1];
	strcpy(animationName, name);

	frames = nullptr;
}

/********************************************************************
Function name: ~Animation
Purpose: Free the allocated memory for animationName and other frames
In parameters: none
Out parameters: none
Version: 1.0
Author: Minh Duc Pham
**********************************************************************/
Animation::~Animation(){
	delete [] animationName;
	Frame* current;

	while (frames != nullptr) {
		current = frames;
		frames = current->GetpNext();
		delete current;
	}

}

/********************************************************************
Function name: InsertFrame
Purpose: Insert a new Frame at the head of the Animation
In parameters: none
Out parameters: none
Version: 1.0
Author: Minh Duc Pham
**********************************************************************/
void Animation::InsertFrame() {
	char name[100];
	name[0] = '\0';
	Frame* tempFrame = new Frame;
	Frame* current;

	cout << "Insert a Frame in the Animation\n";
	cout << "Please enter the Frame frameName: ";
	cin >> name;

	tempFrame->GetFrameName() = (char*) new char[strlen(name) + 1];
	strcpy(tempFrame->GetFrameName(), name);
	
	/*If there is no node inside the linked list*/
	if (frames == nullptr) {
		tempFrame->GetpNext() = nullptr;
		frames = tempFrame;
	}
	else /*there are nodes inside the linked list*/ {

		/*Add the node to the head of the list*/
		current = frames;
		tempFrame->GetpNext() = current;
		frames = tempFrame;
	}
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
	char name[100] = "";
	Frame* current;
	int count = 0;
	int position;

	cout << "Edit a Frame in the Animation\n";
	/*If the linked list is empty*/
	if (frames == nullptr) {
		cout << "There is no frame inside the Animation. Please add a frame first!\n";
		return;
	}

	current = frames;

	/*Count the number of nodes inside the linked list*/
	while (current != nullptr) {
		count++;
		current = current->GetpNext();
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

	current = frames;
	count = 0;

	while (current != nullptr) {
		if (count == position) {
			cout << "The name of this Frame is " << current->GetFrameName() << ". What do you wish to replace it with? \n";
			cin >> name;
			
		    delete current->GetFrameName();
			current->GetFrameName() = new char[strlen(name)+1];
			strcpy(current->GetFrameName(), name);
			break;
		}
		current = current->GetpNext();
		count++;
	}
}

/********************************************************************
Function name: DeleteFrame
Purpose: Delete the last Frame node in the linked list
In parameters: none
Out parameters: none
Version: 1.0
Author: Minh Duc Pham
**********************************************************************/
void Animation::DeleteFrame() {
	Frame* current;
	Frame* previous;

	current = frames;
	previous = nullptr;

	/*There is no frame*/
	if (current == nullptr) {
		cout << "There is no frame inside the Animation to delete!\n";
		return;
	}

	/*There is only one frame*/
	if (current->GetpNext() == nullptr) {
		frames = nullptr;
		delete current;
		return;
	}

	/*There is more than one frame*/
	while (current->GetpNext() != nullptr) {
		previous = current;
		current = current->GetpNext();
	}

	/*Remove the last frame and change the previous pointer to null*/
	previous->GetpNext() = nullptr;
	delete(current);
}

/********************************************************************
Function name: ReportAnimation
Purpose: Report the Animation linked list
In parameters: none
Out parameters: none
Version: 1.0
Author: Minh Duc Pham
**********************************************************************/
void Animation::ReportAnimation() {
	Frame* current;
	int count;

	cout << "Animation name is "  << animationName << "\n";
	cout << "Report the animation\n";

	current = frames;
	count = 0;

	if (current == nullptr) {
		cout << "There is no frame inside the Animation\n";
		return;
	}

	while (current != nullptr) {
		cout << "Image #" << count << ", file name = " << current->GetFrameName() <<  "\n";
		count++;
		current = current->GetpNext();
	}
	cout << "\n";
}

