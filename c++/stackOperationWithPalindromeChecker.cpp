//*Program to check the entered string is Palindrome or not with help of Stack using C++

#include<iostream>
#include<string.h>

using namespace std;

class Stacks {
	private	: int stackMaxLength;
	          char *stack;
		  int topOfStack;
		  string str;
	
		  bool checkOverflow();
		  bool checkUnderflow();
		  void printStack();
		  void pushElement(char);
		  char popElement();
		  bool isEven(int);
		  bool isPalindrome(string);

	public	: Stacks();
		  void optionMenu();
};


/*Algorithm for 'Stacks()':-
 * 1> Start.
 * 2> Read maximum_length_of_stack.
 * 3> Set top_of_stack = 0.
 * 4> End.
 * */

inline Stacks :: Stacks() {
	cout << "Enter the size of stack: ";
	cin >> stackMaxLength;

	stack = new char[stackMaxLength];
	topOfStack = 0;
}


/*Algorithm for function 'checkOverflow()':-
 * 1> Start.
 * 2> If top_of_stack = maximum_length_of_stack, then Stack Overflow. Otherwise not.
 * 3> End.
 * */

inline bool Stacks :: checkOverflow() {

	return (topOfStack == stackMaxLength) ? true : false;
}


/*Algorithm for function 'checkUnderflow()':-
 * 1> Start. 
 * 2> If top_of_stack = 0, then Stack Underflow. Otherwise not.
 * 3> End.
 * */

inline bool Stacks :: checkUnderflow() {
	
	return (topOfStack == 0) ? true : false;
}


/*Algorithm for function 'printStack()':-
 * 1> Start.
 * 2> If stack not underflow, then apply steps 3 to 6. Otherwise print Stack is empty.
 * 3> Set iteration = topOfStack - 1.
 * 4> Repeat steps 5 and 6 for iteration >= lower_bound.
 * 5> Print stack[iteration].
 * 6> Decrement iteration by 1.
 * 7> End.
 * */

inline void Stacks :: printStack() {
	
	if(!checkUnderflow()) {
		cout << "\n\n\nResultant Stack is:" << endl;
	
		for(int iteration = topOfStack - 1; iteration >= 0; iteration--) {
			cout << stack[iteration] << endl;			
		}

	} else {
		cout << "\n*****Null Stack*****" << endl;
	}

}


/*Algorithm for function 'pushElement(char Element)':-
 * 1> Start.
 * 2> If stack not overflow, then apply steps 3 and 4. Otherwise print Stack is full.
 * 3> Set stack[top_of_stack] = new_element.
 * 4> Increment top_of_stack by 1.
 * 5> End.
 * */

inline void Stacks :: pushElement(char element) {
	
	if(!checkOverflow()) {
		stack[topOfStack] = element;
		topOfStack ++;
	} else {
		cout << "\n*****Stack is full*****" <<endl;
	}

}


/*Algorithm for function 'popElement()':-
 * 1> Start.
 * 2> If stack not underflow, then apply step 3. Otherwise print Stack is empty and return nothing.
 * 3> Decrement top_of_stack by 1 and return top_element_in_stack.
 * 4> End.
 * */

inline char Stacks :: popElement() {
	
	if(!checkUnderflow()) {
		topOfStack --;
		return stack[topOfStack];
	} else {
		cout << "\n*****Stack is empty*****" << endl;
		return '\0';
	}

}

/*Algorithm for 'isEven(int length)':-
 * 1> Start.
 * 2> If length % 2 gives 0 then number is even. Otherwise odd.
 * 3> End.
 * */

inline bool Stacks :: isEven(int length) {
	
	return (length % 2 == 0) ? true : false;
}

/*Algorithm for 'isPalindrome(string str)':-
 * 1> Start.
 * 2> Set top_of_stack = 0.
 * 3> If length_of_str is even then set half_of_str = length_of_str / 2. Otherwise half_of_str = (length_of_str - 1) / 2.
 * 4> Set iteration = 0.
 * 5> Repeat steps 6 and 7 for iteration < first_half_of_str.
 * 6> Push str[iteration] into stack.
 * 7> Increment iteration by 1.
 * 9> If length_of_str is odd then half_of_str is incrementd by 1.
 * 10> Set iteration = half_of_str.
 * 11> Repeat steps 12 and 13 for iteration < length_of_str.
 * 12> If str[iteration] not = popped_element_from_stack, print str is not palindrome.
 * 13> Increment iteration by 1.
 * 14> Print str is palindrome.
 * 15> End.*/

inline bool Stacks :: isPalindrome(string str) {
	topOfStack = 0;
	int halfOfString;
	
	halfOfString = (isEven(str.length())) ? str.length() / 2 : (str.length() - 1) / 2;

	for(int iteration = 0; iteration <  halfOfString; iteration++) {
		pushElement((char)str[iteration]);	
	}
	
	if(!isEven(str.length())) {
		halfOfString ++;
	}
	
	for(int iteration = halfOfString; iteration < str.length(); iteration++) {
		
		if((char)str[iteration] != popElement()) {
			return false;
		}
		
	}
	
	return true;
}


/*Algorithm for 'optionMenu()':-
 * 1> Start.
 * 2> If user want to push element into stack, then read element and it to pushElement() and then recall optionMenu().
 * 3> If user want to pop element from stack, then call popElement() and recall optionMenu().
 * 4> If user want to display stack, then call printStack() and recall optionMenu().
 * 5> If user want to check input string is palindrome or not, then apply steps 6 to 8.
 * 6> Read string.
 * 7> If string is palindrome, then print Palindrome. Otherwise not.
 * 8> Recall optionMenu().
 * 9> If user choose 0, then it will be quit from program.
 * 10> If use choose undefined choice, then print Invalid choice and recall optionMenu().
 * 11> End.*/

inline void Stacks :: optionMenu() {
	int choice;

	cout << "\nPress 1 to push element into stack";
	cout << "\nPress 2 to pop element from stack";
	cout << "\nPress 3 to display stack";
	cout << "\nPress 4 to check string is palindrome or not (For this operation stack will be auto-empty)";
	cout << "\nPress 0 to Quit";

	cout << "\n\nEnter your choice: ";
	cin >> choice;

	switch(choice) {
		case 1:
			char element;

			cout << "\nEnter the element that you want to push into stack: ";
			cin >> element;
			
			pushElement(element);
			optionMenu();
			break;
		case 2:
			popElement();
			optionMenu();
			break;
		case 3:
			printStack();
			optionMenu();
			break;
		case 4:			
			cout << "Enter the string of which you want to check palindrome: ";
			cin >> str;
	
			if(isPalindrome(str)) {
				cout << str << " is Palindrome" << endl;
			} else {
				cout << str << " is not Pailndrome" << endl;
			}

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
	Stacks stk;
	
	stk.optionMenu();	
	return 0;
}
