/**********************************************************************
Filename: ass0.c
Version: 1.0
Author: Minh Duc Pham
Student No: 040905103
Course Name/Number: C++ Programming CST8219
Lab Sect: 313
Assignment #: 0
Assignment name: Animation Project in C
Due Date: September 21st, 2019
Submission Date: September 20th, 2019
Professor: Mohamed Abouseif
Purpose: Simple C language console application that holds data of an
		 animation application using a linked list in dynamic memory.
		 While running the application can add a new Frame to the start
		 of the Animation Frame list, delete the last frame in the list,
		 edit a selected Frame to change the frame name, report the
		 Anmiation to show the list of Frame details and quit the
		 Application.
*********************************************************************/
// ass0.c
#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC // need this to get the line identification
//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF); // in main, after local declarations
//NB must be in debug build
#include <crtdbg.h>
#include <stdio.h>
#include <string.h>
typedef enum { FALSE = 0, TRUE } BOOL;
struct Frame {
	char* frameName;
	struct Frame* pNext;
};
typedef struct {
	char* animationName;
	struct Frame* frames;
}Animation;
// Forward declarations
void InitAnimation(Animation*);
void InsertFrame(Animation*);
void DeleteFrame(Animation*);
void EditFrame(Animation*);
void ReportAnimation(Animation*);
void CleanUp(Animation*);
int main(void)
{
	char response;
	BOOL RUNNING = TRUE;
	Animation RG;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	InitAnimation(&RG);
	while (RUNNING)
	{
		printf("MENU\n 1. Insert a Frame at the front\n 2. Delete last Frame\n 3. Edit a Frame\n 4. Report the Animation\n 5. Quit\n");
		scanf("%c", &response);
		switch (response)
		{
		case '1':InsertFrame(&RG); break;
		case '2':DeleteFrame(&RG); break;
		case '3':EditFrame(&RG); break;
		case '4':ReportAnimation(&RG); break;
		case '5':RUNNING = FALSE; CleanUp(&RG); break;
		default:printf("Please enter a valid option\n");
		}
	}
	return 0;
}

/********************************************************************
Function name: InitAnimation
Purpose: Initialize values for an Animation struct type.
In parameters: pointer to an Animation
Out parameters: none
Version: 1.0
Author: Minh Duc Pham
**********************************************************************/
void InitAnimation(Animation* pAnimation) {
	char name[100];
	name[0] = '\0';
	
	if (pAnimation == NULL)
		return;

	printf("Please enter the Animation name: ");
	scanf("%s", name);

	pAnimation->animationName = (char*)malloc(strlen(name)+1);
	if (pAnimation->animationName == NULL) {
		printf("Failed to dynamically allocated the Animation's name\n");
		return;
	}
	strcpy(pAnimation->animationName, name);

	pAnimation->frames = NULL;
}

/********************************************************************
Function name: InsertFrame
Purpose: Insert Frame node into a Animation linked list at the front
In parameters: pointer to an Animation
Out parameters: none
Version: 1.0
Author: Minh Duc Pham
**********************************************************************/
void InsertFrame(Animation* pAnimation) {
	char name[100];
	name[0] = '\0';
	struct Frame* tempFrame;
	struct Frame* current;

	if (pAnimation == NULL)
		return;

	printf("Insert a Frame in the Animation\n");
	printf("Please enter the Frame frameName: ");
	scanf("%s", name);

	tempFrame = (struct Frame*) malloc(sizeof(struct Frame));
	if (tempFrame == NULL) {
		printf("Failed to dynamically allocated the frame\n");
		return;
	}
	tempFrame->frameName = (char*)malloc(strlen(name)+1);
	if (tempFrame->frameName == NULL) {
		printf("Failed to dynamically allocated the frame name");
		return;
	}
	strcpy(tempFrame->frameName, name);

	/*If there is no node inside the linked list*/
	if (pAnimation->frames == NULL) {
		tempFrame->pNext = NULL;
		pAnimation->frames = tempFrame;
	}
	else /*there are nodes inside the linked list*/ {

		/*Add the node to the head of the list*/
		current = pAnimation->frames;
		tempFrame->pNext = current;
		pAnimation->frames = tempFrame;
	}
}

/********************************************************************
Function name: EditFrame
Purpose: Edit a selected frame inside the linked list to change the frame name
In parameters: pointer to an Animation
Out parameters: none
Version: 1.0
Author: Minh Duc Pham
**********************************************************************/
void EditFrame(Animation* pAnimation) {
	char name[100];
	name[0] = '\0';

	struct Frame* current;
	int count;
	int position;
    count = 0;

	if (pAnimation == NULL)
		return;

	printf("Edit a Frame in the Animation\n");
	/*If the linked list is empty*/
	if (pAnimation->frames == NULL) {
		printf("There is no frame inside the Animation. Please add a frame first!\n");
		return;
	}
	
	current = pAnimation->frames;

	/*Count the number of nodes inside the linked list*/
	while (current != NULL) {
		count++;
		current = current->pNext;
	}

	printf("There are %d Frame(s) in the list. Please specify the index (<= %d) to edit at: ", count, count - 1);

	if (scanf("%d", &position) != 1) {
		printf("Please enter a valid integer\n");
		int c;
		while ((c = getchar()) != EOF && c != '\n');
		return;
	}

    if (position < 0) {
		printf("Please enter a positive integer\n");
		return;
	}
	else if (position > (count-1)) {
		printf("The index is not available in the linked list!\n");
		return;
	}

	current = pAnimation->frames;
	count = 0;

    while (current != NULL) {
		if (count == position) {
			printf("The name of this Frame is %s. What do you wish to replace it with ", current->frameName);
			scanf("%s", name);
			
			free(current->frameName);
			current->frameName = (char*)malloc(strlen(name) + 1);
			strcpy(current->frameName, name);
			break;
		}
		current = current->pNext;
		count++;
	}
}

/********************************************************************
Function name: DeleteFrame
Purpose: Delete the last Frame node in the linked list
In parameters: pointer to an Animation
Out parameters: none
Version: 1.0
Author: Minh Duc Pham
**********************************************************************/
void DeleteFrame(Animation* pAnimation) {
	struct Frame* current;
	struct Frame* previous;

	if (pAnimation == NULL)
		return;

	current = pAnimation->frames;
	previous = NULL;
	
	/*There is no frame*/
	if(current == NULL){
		printf("There is no frame inside the Animation to delete!\n");
		return;
	}

	/*There is only one frame*/
	if (current->pNext == NULL) {
		pAnimation->frames = NULL;
		free(current->frameName);
		free(current);
		return;
	}

	/*There is more than one frame*/
	while (current->pNext != NULL) {
		previous = current;
		current = current->pNext;
	}

	/*Remove the last frame and change the previous pointer to NULL*/
	previous->pNext = NULL;
	free(current->frameName);
	free(current);
}

/********************************************************************
Function name: ReportAnimation
Purpose: Report the Animation linked list
In parameters: pointer to an Animation
Out parameters: none
Version: 1.0
Author: Minh Duc Pham
**********************************************************************/
void ReportAnimation (Animation* pAnimation) {
	struct Frame* current;
	int count;

	if (pAnimation == NULL)
		return;

	printf("Animation name is %s\n", pAnimation->animationName);
	printf("Report the animation\n");

	current = pAnimation->frames;
	count = 0;
	if (current == NULL) {
		printf("There is no frame inside the Animation\n");
		return;
	}

	while (current != NULL) {
		printf("Image #%d, file name = %s\n", count, current->frameName);
		count++;
		current = current->pNext;
	}
}

/********************************************************************
Function name: CleanUp
Purpose: Release all dynamically allocated memory when the application terminated
In parameters: pointer to an Animation
Out parameters: none
Version: 1.0
Author: Minh Duc Pham
**********************************************************************/
void CleanUp(Animation* pAnimation) {
	struct Frame* current;

	if (pAnimation == NULL) {
		return;
	}

	while (pAnimation->frames != NULL) {
	   current = pAnimation->frames;
	   pAnimation->frames = current->pNext;
	   free(current->frameName);
	   free(current);
	}

	free(pAnimation->animationName);
}




