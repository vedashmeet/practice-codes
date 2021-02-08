//*Program to insert, delete and display list of employee's data using Doubly Linked List Data Structure in C++
#include<iostream>

using namespace std;

class DoublyLinkedList {
	private	: struct node {
		  	int employeeId;
			string name;
			string department;
			string designation;
			int salary;
			long int phoneNo;
			struct node *linkToPreviousNode;
			struct node *linkToNextNode;
		  };

		  void optionMenu(struct node *, struct node *);
		  void insertAtFront(struct node **, struct node **);
		  void insertAtEnd(struct node **, struct node **);
		  void deleteFromFront(struct node **, struct node **);
		  void deleteFromEnd(struct node **, struct node **);
		  void displayListInFCDF(struct node *);
		  void displayListInLCDF(struct node *);
		  void countNodes(struct node *);
	public	: void initialiseList();
};


/*Algorithm for 'initialiseList()':-
 * 1> Start.
 * 2> Set Start = NULL and end = NULL.
 * 3> Call optionMenu().
 * 4> End.
 * */

inline void DoublyLinkedList :: initialiseList() {
	struct node *start;
	struct node *end;
	
	start = NULL;
	end = NULL;

	optionMenu(start, end);
}


/*Algorithm for 'optionMenu(struct node *start, struct node *end)':-
 * 1> Start.
 * 2> Press 1 to insert details at front and call optionMenu().
 * 3> Press 2 to insert details at end and call optionMenu().
 * 4> Press 3 to delete details from front and call optionMenu().
 * 5> Press 4 to delete details from end and call optionMenu().
 * 6> Press 5 to display list of employee's details in FIRST COME DISPLAY FIRST ORDER and call optionMenu().
 * 7> Press 6 to display list of employee's details in LAST COME DISPLAY FIRST ORDER and call optionMenu().
 * 8> Press 7 to count number of nodes and call optionMenu().
 * 9> Press 0 to quit.
 * 10> End.
 * */

inline void DoublyLinkedList :: optionMenu(struct node *start, struct node *end) {
	int choice;

	cout << "\n\nPress 1 to insert employee data at beginning" << endl;
	cout << "Press 2 to insert employee data at end" << endl;
	cout << "Press 3 to delete employee data from beginning" << endl;
	cout << "Press 4 to delete employee data from end" << endl;
	cout << "Press 5 to display list of employee data (in FIRST COME DISPLAY FIRST order)" << endl;
	cout << "Press 6 to display list of employee data (in LAST COME DISPLAY FIRST order)" << endl;
	cout << "Press 7 to display the count of nodes" << endl;
	cout << "Press 0 to Quit" << endl;

	cout << "Enter your choice: ";
	cin >> choice;

	switch(choice) {
		case 1:
			insertAtFront(&start, &end);
			optionMenu(start, end);
			break;
		case 2:
			insertAtEnd(&start, &end);
			optionMenu(start, end);
			break;
		case 3:
			deleteFromFront(&start, &end);
			optionMenu(start, end);
			break;
		case 4:
			deleteFromEnd(&start, &end);
			optionMenu(start, end);
			break;
		case 5:
			displayListInFCDF(start);
			optionMenu(start, end);
			break;
		case 6:
			displayListInLCDF(end);
			optionMenu(start, end);
			break;
		case 7:
			countNodes(start);
			optionMenu(start, end);
			break;
		case 0:
			break;
		default:
			cout << "Invalid choice!" << endl << endl;
			optionMenu(start, end);
	}

}


/*Algorithm for 'insertAtFront(struct node **start, struct node **end)':-
 * 1> Start.
 * 2> Create newList and read its data such as employee_ID, name, department, designation, salary, phone no.
 * 3> Set Forward-Link of newList node = *pointer.
 * 4> If *start not = to NULL, then set Backward-Link of Forward-Link of newList node = newList. Otherwise set *end = newList.
 * 5> Set *start = newList.
 * 6> Set Backward-Link of newList = NULL.
 * 7> End.
 * */

inline void DoublyLinkedList :: insertAtFront(struct node **start, struct node **end) {
	struct node *newList;
	newList = new node();

	cout << "Enter employee ID: ";
	cin>> newList->employeeId;
	cout << "Enter name: ";
	cin >> newList->name;
	cout << "Enter department: ";
	cin >> newList->department;
	cout << "Enter designation: ";
	cin >> newList->designation;
	cout << "Enter salary: ";
	cin >> newList->salary;
	cout << "Enter phone number: ";
	cin >> newList->phoneNo;

	newList->linkToNextNode = *start;

	if(*start != NULL) {
		newList->linkToNextNode->linkToPreviousNode = newList;
	} else {
		*end = newList;
	}

	*start = newList;
	newList->linkToPreviousNode = NULL;	
}


/*Algorithm for 'insertAtEnd(struct node **start, struct node **end)':-
 * 1> Start.
 * 2> Create newList and read its data such as employee_ID, name, department, designation, salary, phoneNo.
 * 3> Create pointer and set it equals to *start.
 * 4> If pointer not = to NULL, then apply steps 5 to 7.
 * 5> Repeat step 6 while Forward-Link of pointer not = to NULL.
 * 6> Set pointer = Forward-Link of pointer.
 * 7> Set Forward-Link of pointer = newList.
 * 8> Set Backward-Link of newList = pointer.
 * 9> Set Forward-Link of newList = NULL.
 * 10> If *end = NULL, then set *start = newList.
 * 11> Set *end = newList.
 * 12> End.
 * */

inline void DoublyLinkedList :: insertAtEnd(struct node **start, struct node **end) {
        struct node *newList;
        newList = new node();

        cout << "Enter employee ID: ";
        cin>> newList->employeeId;
        cout << "Enter name: ";
        cin >> newList->name;
        cout << "Enter department: ";
        cin >> newList->department;
        cout << "Enter designation: ";
        cin >> newList->designation;
        cout << "Enter salary: ";
        cin >> newList->salary;
        cout << "Enter phone number: ";
        cin >> newList->phoneNo;

	struct node *pointer;
	pointer = *start;

	if(pointer != NULL) {
	
		while(pointer->linkToNextNode != NULL) {
			pointer = pointer->linkToNextNode;
		}

        	pointer->linkToNextNode = newList;
	}

	newList->linkToPreviousNode = pointer;
	newList->linkToNextNode = NULL;
	
	if(*end == NULL) {
		*start = newList;
	}
	
	*end = newList;
}


/*Algorithm for 'deleteFromFront(struct node **start, struct node **end)':-
 * 1> Start.
 * 2> If *start not = to NULL and *end not = to NULL, then apply steps 3 and 4.
 * 3> Create pointer and set it equals to *start.
 * 4> If Backward-Link of pointer = NULL and Forward-Link of pointer = NULL, then delete pointer and set *start = *end = NULL. Otherwise set *start = Forward-Link of pointer, delete Backward-Link of pointer, set pointer = *start and set Backward-Link of pointer = NULL.
 * 5> End.
 * */

inline void DoublyLinkedList :: deleteFromFront(struct node **start, struct node **end) {
	
	if(*start != NULL && *end != NULL) {
		struct node *pointer;
        	pointer = *start;

		if(pointer->linkToPreviousNode == NULL && pointer->linkToNextNode == NULL) {
			delete pointer;
			*start = NULL;
			*end = NULL;
		} else {
			*start = pointer->linkToNextNode;
			delete pointer->linkToPreviousNode;
			pointer = *start;
			pointer->linkToPreviousNode = NULL;
		}
	}
}


/*Algorithm for 'deleteFromEnd(struct node **start, struct node **end)':-
 * 1> Start.
 * 2> If *start not = to NULL and *end not = to NULL, then apply steps 3 and 4.
 * 3> Create pointer and set it equals to *end.
 * 4> If Backward-Link of pointer = NULL and Forward-Link of pointer = NULL, then delete pointer and set *start = *end = NULL. Otherwise set *end = Backward-Link of pointer, delete Forward-Link of pointer, set pointer = *end and set Forward-Link of pointer = NULL.
 * 5> End.
 * */

inline void DoublyLinkedList :: deleteFromEnd(struct node **start, struct node **end) {
	
	if(*start != NULL && *end != NULL) {
		struct node *pointer;
        	pointer = *end;

        	if(pointer->linkToPreviousNode == NULL && pointer->linkToNextNode == NULL) {
                	delete pointer;
			*start = NULL;
                	*end = NULL;
        	} else {
                	*end = pointer->linkToPreviousNode;
			delete pointer->linkToNextNode;
			pointer = *end;
                	pointer->linkToNextNode = NULL;
        	}
	}
}


/*Algorithm for 'displayListInFCDF(struct node *pointer)':-
 * 1> Start.
 * 2> Repeat steps 3 and 4 while pointer not = to NULL.
 * 3> Print data of pointer such as employee_ID, name, department, designation, salary, phoneNo.
 * 4> Set pointer = Forward-Link of pointer.
 * 5> End.
 * */

inline void DoublyLinkedList :: displayListInFCDF(struct node *pointer) {
	cout << "Employee ID \t Employee's Name \t Department \t Designation \t Salary \t Phone Number" << endl;
	
	while(pointer != NULL) {
		cout << pointer->employeeId << "\t" << pointer->name << "\t" << pointer->department << "\t" << pointer->designation << "\t" << pointer->salary << "\t" << pointer->phoneNo <<endl;
		pointer = pointer->linkToNextNode;
	}

}

/*Algorithm for 'displayListInLCDF(struct node *pointer)':-
 * 1> Start.
 * 2> Repeat steps 3 and 4 while pointer not = to NULL.
 * 3> Print data of pointer such as employee_ID, name, department, designation, salary, phoneNo.
 * 4> Set pointer = Backward-Link of pointer.
 * 5> End.
 * */

inline void DoublyLinkedList :: displayListInLCDF(struct node *pointer) {
        cout << "Employee ID \t Employee's Name \t Department \t Designation \t Salary \t Phone Number" << endl;

        while(pointer != NULL) {
                cout << pointer->employeeId << "\t" << pointer->name << "\t" << pointer->department << "\t" << pointer->designation << "\t" << pointer->salary << "\t" << pointer->phoneNo <<endl;
                pointer = pointer->linkToPreviousNode;

        }

}


/*Algorithm for 'countNodes(struct node *pointer)':-
 * 1> Start.
 * 2> Set count = 0, 
 * 3> Repeat steps 4 and 5 while pointer not = to NULL.
 * 4> Set pointer = Forward-Link of pointer.
 * 5> Increment count by 1.
 * 6> End.
 * */

inline void DoublyLinkedList :: countNodes(struct node *pointer) {
	int count = 0;
	
	while(pointer != NULL) {
		pointer = pointer->linkToNextNode;
		count++;
	}

	cout << "Count of Nodes are " << count << endl;
}


/*Algorithm for 'main()':-
 * 1> Start.
 * 2> Call initialiseList().
 * 3> End.
 * */

int main() {
	DoublyLinkedList dll;
	dll.initialiseList();
	return 0;
}
