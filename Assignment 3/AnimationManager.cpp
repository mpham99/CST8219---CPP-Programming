/**********************************************************************
Filename: AnimationManager.cpp
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
#include <vector> 
#include <iostream>
#include <string>
#include <forward_list>
using namespace std;
#include "Frame.h"
#include "AudioFrame.h"
#include "VideoFrame.h"
#include "Animation.h"
#include "AnimationManager.h"

/********************************************************************
Function name: EditAnimation
Purpose: Edit a selected Animation by inserting, deleting or editing a frame
In parameters: none
Out parameters: none
Version: 1.0
Author: Minh Duc Pham
**********************************************************************/
void AnimationManager::EditAnimation() {
	vector<Animation>::iterator i;
	int count = 0;
	int position;

	/*If the linked list is empty*/
	/*If the linked list is empty*/
	if (animations.empty()) {
		cout << "There is no Animation. Please add an Animation first!\n";
		return;
	}

	/*Count the number of nodes inside the vectors*/
	for (i = animations.begin(); i != animations.end(); i++) {
		count++;
	}

	cout << "Which Animation do you wish to edit? Please give the the index (from 0 to " << count - 1 << "): ";
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
		cout << "The index is not available in the vector!\n";
		return;
	}

	count = 0;
	for (i = animations.begin(); i != animations.end(); i++) {
		if (count == position) {
			char response;
			bool RUNNING = true;
			cout << "Editing Animation #" << count << endl;
			while (RUNNING)
			{
				cout << "MENU\n 1. Insert a Frame at Front\n 2. Delete first Frame\n 3. Edit a Frame\n 4. Quit" << endl;
				cin >> response;
				switch (response)
				{
				case '1':cin >> *i; break;
				case '2':(*i).DeleteFrame(); break;
				case '3':(*i).EditFrame(); break;
				case '4':cout << "Animation #" << count << " edit complete" << endl; RUNNING = false; break;
				default:
					cout << "Please enter a valid option" << endl;
					cin.clear();
					cin.ignore(500, '\n');
					break;					
				}
			}
			return;
		}
		count++;
	}
}

/********************************************************************
Function name: DeleteAnimation
Purpose: Delete an Animation
In parameters: none
Out parameters: none
Version: 1.0
Author: Minh Duc Pham
**********************************************************************/
void AnimationManager::DeleteAnimation() {
	cout << "Delete an Animation from the Animation Manager" << endl;
	vector<Animation>::iterator i;
	int count = 0;
	int position;

	/*If the linked list is empty*/
	if (animations.empty()) {
		cout << "There is no Animation. Please add an Animation first!\n";
		return;
	}

	/*Count the number of nodes inside the vectors*/
	for (i = animations.begin(); i != animations.end(); i++) {
		count++;
	}

	cout << "Which Animation do you wish to delete? Please give the the index in the range 0 to " << count - 1 << "): ";
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
		cout << "The index is not available in the vector!\n";
		return;
	}

	//Delete the Animation inside the vector
	animations.erase(animations.begin() + ((long long)position));
	cout << "Animation #" << position << " Deleted" << endl;
}

/********************************************************************
Function name: operator>>
Purpose: Add an Animation
In parameters: istream& input, AnimationManager& M
Out parameters: istream& input
Version: 1.0
Author: Minh Duc Pham
**********************************************************************/
istream& operator>> (istream& input, AnimationManager& M) {
	string name;

	//Ask for the Animation Name
	cout << "Add an Animation to the Animation Manager " << endl;
	cout << "Please enter the Animation Name: ";
	input >> name;

	//Add the Animation at the end of the animations vector
	//Animation* tempAnimation = new Animation(name);
	//M.animations.push_back(*tempAnimation);
	Animation tempAnimation(name);
	M.animations.push_back(tempAnimation);
	cout << "Animation " << name << " is added at the back of the animations" << endl;

	return input;
}

/********************************************************************
Function name: operator<<
Purpose: Output the Animations
In parameters: ostream& output, AnimationManager& M
Out parameters: ostream& output
Version: 1.0
Author: Minh Duc Pham
**********************************************************************/
ostream& operator<<(ostream& output, AnimationManager& M) {
	output << "AnimationManager: " << M.managerName << endl;
	int count = 0;
	vector<Animation>::iterator i;

	//No animation inside the list
	if (M.animations.empty()) {
		output << "There is no animation inside the list\n";
		return output;
	}

	for (i = M.animations.begin(); i != M.animations.end(); i++) {
		output << "Animation: " << count << endl;
		output << "\t" << *i;
		count++;
	}

	return output;
}
