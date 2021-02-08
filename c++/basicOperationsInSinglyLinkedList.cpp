//*Program to insert, delete and display list of student's data using Singly Linked List Data Structure in C++
#include<iostream>

using namespace std;

class SinglyLinkedList {
	private	: struct node {
		  	int universityRollNo;
			string name;
			string branch;
			int semester;
			long int phoneNo;
			struct node *linkToNextNode;
		  };

		  void optionMenu(struct node *);
		  void insertAtFront(struct node **);
		  void insertAtEnd(struct node **);
		  void deleteFromFront(struct node **);
		  void deleteFromEnd(struct node **);
		  void displayLists(struct node *);
	public	: void initialiseList();
};


/*Algorithm for 'initialiseList()':-
 * 1> Start.
 * 2> Set Start = NULL.
 * 3> Call optionMenu().
 * 4> End.
 * */

inline void SinglyLinkedList :: initialiseList() {
	struct node *start;
	start = NULL;
	
	optionMenu(start);
}


/*Algorithm for 'optionMenu(struct node *start)':-
 * 1> Start.
 * 2> Press 1 to insert details at front and call optionMenu().
 * 3> Press 2 to insert details at end and call optionMenu().
 * 4> Press 3 to delete details from front and call optionMenu().
 * 5> Press 4 to delete details from end and call optionMenu().
 * 6> Press 5 to display list of student's details and call optionMenu().
 * 7> Press 0 to quit.
 * 8> End.
 * */

inline void SinglyLinkedList :: optionMenu(struct node *start) {
	int choice;

	cout << "\n\nPress 1 to insert student data at beginning" << endl;
	cout << "Press 2 to insert student data at end" << endl;
	cout << "Press 3 to delete student data from beginning" << endl;
	cout << "Press 4 to delete student data from end" << endl;
	cout << "Press 5 to display list of students data" << endl;
	cout << "Press 0 to Quit" << endl;

	cout << "Enter your choice: ";
	cin >> choice;

	switch(choice) {
		case 1:
			insertAtFront(&start);
			optionMenu(start);
			break;
		case 2:
			insertAtEnd(&start);
			optionMenu(start);
			break;
		case 3:
			deleteFromFront(&start);
			optionMenu(start);
			break;
		case 4:
			deleteFromEnd(&start);
			optionMenu(start);
			break;
		case 5:
			displayLists(start);
			optionMenu(start);
			break;
		case 0:
			break;
		default:
			cout << "Invalid choice!" << endl << endl;
			optionMenu(start);
	}

}


/*Algorithm for 'insertAtFront(struct node **pointer)':-
 * 1> Start.
 * 2> Create newList and read its data such as URN, name, branch, semester, phoneNo.
 * 3> Set Link of newList node = *pointer.
 * 4> Set *pointer = Start of newList.
 * 5> End.
 * */

inline void SinglyLinkedList :: insertAtFront(struct node **pointer) {
	struct node *newList;
	newList = new node();

	cout << "Enter university roll no: ";
	cin>> newList->universityRollNo;
	cout << "Enter name: ";
	cin >> newList->name;
	cout << "Enter branch: ";
	cin >> newList->branch;
	cout << "Enter semester: ";
	cin >> newList->semester;
	cout << "Enter phone number: ";
	cin >> newList->phoneNo;

	newList->linkToNextNode = *pointer;
	*pointer = newList;	
}


/*Algorithm for 'insertAtEnd(struct node **pointer)':-
 * 1> Start.
 * 2> Create newList and read its data such as URN, name, branch, semester, phoneNo.
 * 3> Create tempStoreForPointer and set it equals to *pointer.
 * 4> Repeat step 5 while Link of tempStoreForPointer not = NULL.
 * 5> Set tempStoreForPointer = Link of tempStoreForPointer.
 * 6> Set Link of tempStoreForPointer = Start of newList.
 * 7> Set Link of newList = NULL.
 * 8> End.
 * */

inline void SinglyLinkedList :: insertAtEnd(struct node **pointer) {
        struct node *newList;
        newList = new node();

        cout << "Enter university roll no: ";
        cin>> newList->universityRollNo;
        cout << "Enter name: ";
        cin >> newList->name;
        cout << "Enter branch: ";
        cin >> newList->branch;
        cout << "Enter semester: ";
        cin >> newList->semester;
        cout << "Enter phone number: ";
        cin >> newList->phoneNo;

	struct node *tempStoreForPointer;
	tempStoreForPointer = *pointer;

	while(tempStoreForPointer->linkToNextNode != NULL) {
		tempStoreForPointer = tempStoreForPointer->linkToNextNode;
	}

        tempStoreForPointer->linkToNextNode = newList;
	newList->linkToNextNode = NULL;
}


/*Algorithm for 'deleteFromFront(struct node **pointer)':-
 * 1> Start.
 * 2> Create tempStoreForPointer and set it equals to *pointer.
 * 3> Set *pointer = Link of tempStoreForPointer.
 * 4> End.
 * */

inline void SinglyLinkedList :: deleteFromFront(struct node **pointer) {
	struct node *tempStoreForPointer;
	tempStoreForPointer = *pointer;
	*pointer = tempStoreForPointer->linkToNextNode;
}


/*Algorithm for 'deleteFromEnd(struct node **pointer)':-
 * 1> Start.
 * 2> Create tempStoreForPointer and set it equals to *pointer.
 * 3> Repeat step 4 while Link of Link of tempStoreForPointer not = NULL.
 * 4> Set tempStoreForPointer = Link of tempStoreForPointer.
 * 5> Link of tempStoreForPointer = NULL.
 * 6> End.
 * */

inline void SinglyLinkedList :: deleteFromEnd(struct node **pointer) {
	struct node *tempStoreForPointer;
        tempStoreForPointer = *pointer;

	while(tempStoreForPointer->linkToNextNode->linkToNextNode != NULL) {
                tempStoreForPointer = tempStoreForPointer->linkToNextNode;
        }
	
	tempStoreForPointer->linkToNextNode = NULL;
}


/*Algorithm for 'displayLists(struct node *pointer)':-
 * 1> Start.
 * 2> Set count = 0.
 * 3> Repeat steps 4 to 6 while pointer not = NULL.
 * 4> Print data of pointer such as URN, name, branch, semester, phoneNo.
 * 5> Set pointer = Link of pointer.
 * 6> Increment count by 1.
 * 7> Print count.
 * 8> End.
 * */

inline void SinglyLinkedList :: displayLists(struct node *pointer) {
	int count = 0;

	cout << "University Roll No \t Student's Name \t Branch \t Semester \t Phone Number" << endl;
	
	while(pointer != NULL) {
		cout << pointer->universityRollNo << "\t" << pointer->name << "\t" << pointer->branch << "\t" << pointer->semester << "\t" << pointer->phoneNo <<endl;
		pointer = pointer->linkToNextNode;
		count++;
	}

	cout << endl << "Number of nodes are " << count << endl;			 
}


/*Algorithm for 'main()':-
 * 1> Start.
 * 2> Call initialiseList().
 * 3> End.
 * */

int main() {
	SinglyLinkedList sll;
	sll.initialiseList();
	return 0;
}
