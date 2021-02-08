//*Program to perform basic data structure operations on Circular Queue using C++

#include<iostream>
using namespace std;

class CircularQueue  {
	private	: int queueMaxLength;
	          int *queue;
		  int frontOfQueue;
		  int rearOfQueue;
	
		  bool checkOverflow();
		  bool checkUnderflow();
		  void printQueue();
		  void insertElement(int);
		  int deleteElement();

	public	: CircularQueue();
		  void optionMenu();
};


/*Algorithm for 'CircularQueue()':-
 * 1> Start.
 * 2> Read maximum_length_of_queue.
 * 3> Set front and rear = 0.
 * 4> End.
 * */

inline CircularQueue :: CircularQueue() {
	cout << "Enter the size of queue: ";
	cin >> queueMaxLength;

	queue = new int[queueMaxLength];
	frontOfQueue = -1;
	rearOfQueue = -1;
}


/*Algorithm for function 'checkOverflow()':-
 * 1> Start.
 * 2> If rear = maximum_length_of_queue - 1 and fromt = 0, or rear = front - 1, then Queue Overflow. Otherwise not.
 * 3> End.
 * */

inline bool CircularQueue :: checkOverflow() {

	return ((rearOfQueue == queueMaxLength - 1 && frontOfQueue == 0)) || (rearOfQueue == frontOfQueue - 1) ? true : false;
}


/*Algorithm for function 'checkUnderflow()':-
 * 1> Start. 
 * 2> If front = -1, then Queue Underflow. Otherwise not.
 * 3> End.
 * */

inline bool CircularQueue :: checkUnderflow() {
	
	return (frontOfQueue == -1) ? true : false;
}


/*Algorithm for function 'printQueue()':-
 * 1> Start.
 * 2> If queue not underflow, then apply steps 3 to 5. Otherwise print Queue is empty.
 * 3> Set iteration = front.
 * 4> If iteration <= rear, then repeatedly print queue[iteration++] while iteration <= rear.
 * 5> If iteration > rear, then repeatedly print queue[iteration++] while iteration < maximun_length_of_queue, then set iteration = 0 and repeatedly prnt queue[iteration++] while iteration <= rear.
 * 6> End.
 * */

inline void CircularQueue :: printQueue() {
	
	if(!checkUnderflow()) {
		cout << "\n\n\nResultant Queue is:" << endl;
		int iteration = frontOfQueue;

		if(iteration <= rearOfQueue) {
			
			while(iteration <= rearOfQueue) {
				cout << queue[iteration++]  << " |";
			}

		} else {

			while(iteration < queueMaxLength) {
				cout << queue[iteration++] << " |";
			}

			iteration = 0;

			while(iteration <= rearOfQueue) {
				cout << queue[iteration++] << " |";
			}

		}

		cout << endl;

	} else {
		cout << "\n*****Empty Queue*****" << endl;
	}

}


/*Algorithm for function 'insertElement(int Element)':-
 * 1> Start.
 * 2> If queue not overflow, then apply steps 3 to 5. Otherwise print Queue is full.
 * 3> If front = -1, then set front = rear = 0
 * 4> If front not = -1, then if rear = maximum_length_of_queue - 1, then set rear = 0, otherwise rear is incremented by 1.
 * 5> Set queue[rear] = new_element.
 * 6> End.
 * */

inline void CircularQueue :: insertElement(int element) {
	
	if(!checkOverflow()) {
		
		if(frontOfQueue == -1) {
			frontOfQueue = 0;
			rearOfQueue = 0;
		} else {
			
			if(rearOfQueue == queueMaxLength - 1) {
				rearOfQueue = 0;
			} else {
				rearOfQueue++;
			}

		}
		
		queue[rearOfQueue] = element;
	} else {
		cout << "\n*****Queue is full*****" <<endl;
	}

}


/*Algorithm for function 'deelteElement()':-
 * 1> Start.
 * 2> If queue not underflow, then apply steps 3 to 6. Otherwise print Queue is empty and return nothing.
 * 3> If front = rear, then set deleteElementLoc = front and front = rear = -1.
 * 4> If front not = rear, then if front = maximum_length_of_queue - 1, then set deleteElementLoc = front and front = 0, otherwise set deleteElementLoc = front and front is incremented by 1.
 * 5> Set element = queue[deleteElementLoc].
 * 6> Set queue[deleteElementLoc] = 0 and return element.
 * 7> End.
 * */

inline int CircularQueue :: deleteElement() {
	
	if(!checkUnderflow()) {
		int deleteElementLoc;

		if(frontOfQueue == rearOfQueue) {
			deleteElementLoc = frontOfQueue;
			frontOfQueue = -1;
			rearOfQueue = -1;
		} else {

			if(frontOfQueue == queueMaxLength - 1) {
				deleteElementLoc = frontOfQueue;
				frontOfQueue = 0;
			} else {
				deleteElementLoc = frontOfQueue;
				frontOfQueue ++;
			}

		}

		int element = queue[deleteElementLoc];
		queue[deleteElementLoc] = 0;
		return element;
	} else {
		cout << "\n*****Queue is empty*****" << endl;
		return -1;
	}

}


/*Algorithm for 'optionMenu()':-
 * 1> Start.
 * 2> If user want to insert element into queue, then read element and pass it into insertElement() and then recall optionMenu().
 * 3> If user want to delete element from queue, then call deleteElement() and recall optionMenu().
 * 4> If user want to display queue, then call printQueue() and recall optionMenu().
 * 5> If user choose 0, then it will be quit from program.
 * 6> If use choose undefined choice, then print Invalid choice and recall optionMenu().
 * 7> End.*/

inline void CircularQueue :: optionMenu() {
	int choice;

	cout << "\nPress 1 to insert element into circular queue";
	cout << "\nPress 2 to delete element from circular queue";
	cout << "\nPress 3 to display circular queue";
	cout << "\nPress 0 to Quit";

	cout << "\n\nEnter your choice: ";
	cin >> choice;

	switch(choice) {
		case 1:
			int element;

			cout << "\nEnter the element that you want to insert into queue: ";
			cin >> element;
			
			insertElement(element);
			optionMenu();
			break;
		case 2:
			deleteElement();
			optionMenu();
			break;
		case 3:
			printQueue();
			optionMenu();
			break;
		case 0:
			break;
		default:
			cout << "Invalid choice" << endl;
			optionMenu();
	}
	
}


/*Algorithm for function 'main()':-
 * 1> Start.
 * 2> Call function options_for_menus.
 * 5> End.
 * */

int main() {	
	CircularQueue cq;
	
	cq.optionMenu();	
	return 0;
}
