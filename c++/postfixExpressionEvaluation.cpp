//*Program to convert infix expression to postfix expression and evaluate postfix expression using Stack using C++

#include<iostream>
#include<cstring>
#include<string.h>

using namespace std;

class Stacks {
	private	: int stackMaxLength;
	          string *stack;
		  int topOfStack;
	
		  bool checkOverflow();
		  bool checkUnderflow();
		  void printStack();
		  void pushElement(string);
		  string popElement();
		  void parenthesisChecker();
		  bool checkParenthesis(string);
		  void infixToPostfixConversion();
		  string infixToPostfix(string);
		  bool checkPrecedence(char, string);
		  int postfixEvaluation(string);
		  int evaluateOperations(char, int, int);
		  int power(int, int); 

	public	: Stacks();
		  void postfixExpression();
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

	stack = new string[stackMaxLength];
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


/*Algorithm for function 'pushElement(string Element)':-
 * 1> Start.
 * 2> If stack not overflow, then apply steps 3 and 4. Otherwise print Stack is full.
 * 3> Set stack[top_of_stack] = new_element.
 * 4> Increment top_of_stack by 1.
 * 5> End.
 * */

inline void Stacks :: pushElement(string element) {
	
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

inline string Stacks :: popElement() {
	
	if(!checkUnderflow()) {
		topOfStack --;
		return stack[topOfStack];
	} else {
		cout << "\n*****Stack is empty*****" << endl;
		return "";
	}

}


/*Algorithm for 'checkParanthesis(string expression)':-
 * 1> Start.
 * 2> Set iteration = 0.
 * 3> Repeat steps 4 to 9 for iteration < length_of_expression.
 * 4> If iterated_expression = (, { or [, then push it to stack.
 * 5> If iterated_expression = ), } or ], then apply steps 6 to 9.
 * 6> Set asciiCode = ASCII_Code for iterated_expression.
 * 7> Set poppedElement = element_to_be_popped_from_stack.
 * 8> Push the same element into stack.
 * 9> If closing paranthesis comes in expression will not matched to opening paranthesis popped out from stack, then print Paranthesis not matched. Otherwise popped out element from stack.
 * 10> If stack underflow then print Paranthesis Matched. Otherwise not.
 * 11> End.
 * */

inline bool Stacks :: checkParenthesis(string expression) {
	topOfStack = 0;

	for(int iteration = 0; iteration < expression.length(); iteration++) {
		
		if(expression[iteration] == '(' ||
		   expression[iteration] == '{' ||
		   expression[iteration] == '['
		) {
			string expressionIteration = "";
			expressionIteration += expression[iteration];

			pushElement(expressionIteration);
		} else if(expression[iteration] == ')' ||
			  expression[iteration] == '}' ||
			  expression[iteration] == ']'
		) {
			int asciiCode = (int)expression[iteration];
			string poppedElement = popElement();

			pushElement(poppedElement);

			char checkWithPopped[poppedElement.length() + 1];
			strcpy(checkWithPopped, poppedElement.c_str());
			
			if((asciiCode == 41 && checkWithPopped[0] != 40) ||
			   (asciiCode == 93 && checkWithPopped[0] != 91) ||
			   (asciiCode == 125 && checkWithPopped[0] != 123)
			) {
				return false;
			} else {
				popElement();
			}

		}

	}

	return (checkUnderflow()) ? true : false;
}


/*Algorithm for 'paranthesisChecker()':-
 * 1> Start.
 * 2> Read expression.
 * 3> If Paranthesis is better placed, then print Expression is well. Otherwise Expression Error!.
 * 4> End.
 * */

inline void Stacks :: parenthesisChecker() {
	string expression;

	cout << "Enter the expression: ";
	cin >> expression;

	if (checkParenthesis(expression)) {
		cout << "Expression is well..." << endl;
	} else {
		cout << "Expression Error!" << endl;
	}	
}


/*Algorithm for 'checkPrecedence(char ecpressionOperator, string poppedOperator)':-
 * 1> Start.
 * 2> If expressionOperator has precedence same as or smaller than poppedOperator, then return true. Otherwise false.
 * 3> End.
 * */

inline bool Stacks :: checkPrecedence(char expressionOperator, string poppedOperator) {
	
	if(((expressionOperator == '-') &&
	    (poppedOperator == "-" || poppedOperator == "+" || poppedOperator == "*" || poppedOperator == "/" || poppedOperator == "%" || poppedOperator == "^")) ||
	    ((expressionOperator == '+') &&
	    (poppedOperator == "+" || poppedOperator == "*" || poppedOperator == "/" || poppedOperator == "%" || poppedOperator == "^")) ||
	   ((expressionOperator == '*') &&
	    (poppedOperator == "*" || poppedOperator == "/" || poppedOperator == "%" || poppedOperator == "^")) ||
	   ((expressionOperator == '/') &&
	    (poppedOperator == "/" || poppedOperator == "%" || poppedOperator == "^")) ||
	   ((expressionOperator == '%') &&
	    (poppedOperator == "%" || poppedOperator == "^")) ||
  	   ((expressionOperator == '^') &&
	    (poppedOperator == "^"))
	) {
		return true;
	}

	return false;
}


/*Algorithm for 'infixToPostfix(string infixExpression)':-
 * 1> Start.
 * 2> If paranthesis is fine, then apply steps 3 to 23. Otherwise return null.
 * 3> Set topOfStack = 0.
 * 4> Set postfixExpression = null.
 * 5> Push ( onto stack.
 * 6> Add ) at end of the infixExpression.
 * 7> Set iteration = 0.
 * 8> Repeat steps 9 to 23 while iteration < length_of_infixExpression.
 * 9> If infixExpression[iteration] contains any operands, then add it to postfixExpression.
 * 10> If infixExpression[iteration] contains (, { or [, then push it into stack.
 * 11> If infixExpression[iteration] contains +, -, *, /, % or ^, then apply steps 12 to 17.
 * 12> Set poppedElement = popped elemenet from stack.
 * 13> Repeat steps 14 and 15 checkPrecedence(infixExpression[iteration], poppedElemenet) returns true.
 * 14> Add poppedElement to postfiExpression.
 * 15> Set poppedElement = popped element from stack.
 * 16> Push poppedElement into stack.
 * 17> Push infixExpression[iteration] into stack.
 * 18> If infixExpression[iteration] contains ), } or ], then apply steps 19 to 23.
 * 19> Set asciiCode = ascii code of infixExpression[iteration].
 * 20> Set poppedElement = popped element from stack.
 * 21> Repeat steps 22 and 23 while poppedElement not-equals to (, { or [.
 * 22> Add poppedElement at end of the the postfix expression.
 * 23> Set poppedElement = popped element from stack.
 * 24> Return postfix expression.
 * 25> End.*/

inline string Stacks :: infixToPostfix(string infixExpression) {
	
	if(checkParenthesis(infixExpression)) {
		topOfStack = 0;
		string postfixExpression = "";

		pushElement("(");
		infixExpression += ")";

		for(int iteration = 0; iteration < infixExpression.length(); iteration++) {
		
			if(((infixExpression[iteration] > 64) && (infixExpression[iteration] < 91)) ||
		   	   ((infixExpression[iteration] > 96) && (infixExpression[iteration] < 123)) ||
			   ((infixExpression[iteration] > 47) && (infixExpression[iteration] < 58))
			) {
				postfixExpression += infixExpression[iteration];
			} else if((infixExpression[iteration] == 40) ||
			  	  (infixExpression[iteration] == 91) ||
			  	  (infixExpression[iteration] == 123)
		  	) {
				string expressionIteration = "";
                        	expressionIteration += infixExpression[iteration];

				pushElement(expressionIteration);
			} else if((infixExpression[iteration] == 37) ||
			  	  (infixExpression[iteration] == 42) ||
			  	  (infixExpression[iteration] == 43) ||
			  	  (infixExpression[iteration] == 45) ||
			  	  (infixExpression[iteration] == 47) ||
				  (infixExpression[iteration] == 94)
		  	) {			
				string poppedElement = popElement();
			
				while(checkPrecedence(infixExpression[iteration], poppedElement)) {
					postfixExpression += poppedElement;
					poppedElement = popElement();
				}
				
				pushElement(poppedElement);
				
				string expressionIteration = "";
                                expressionIteration += infixExpression[iteration];

				pushElement(expressionIteration);
			} else if((infixExpression[iteration] == 41) ||
			  	  (infixExpression[iteration] == 93) ||
			  	  (infixExpression[iteration] == 125)
			) {
				int asciiCode = (int)infixExpression[iteration];
				string poppedElement = popElement();

				char checkWithPopped[poppedElement.length() + 1];
                        	strcpy(checkWithPopped, poppedElement.c_str());
				
				while((asciiCode == 41 && checkWithPopped[0] != 40) ||
			   	      (asciiCode == 93 && checkWithPopped[0] != 91) ||
			   	      (asciiCode == 125 && checkWithPopped[0] != 123)
				) {
					postfixExpression += poppedElement;
					poppedElement = popElement();
					
                                	strcpy(checkWithPopped, poppedElement.c_str());		
				}

			}

		}

		return postfixExpression;
	} else {
		return "";
	}
}


/*Algorithm for 'infixToPostfixConversion()':-
 * 1> Start.
 * 2> Read infix expression.
 * 3> Set postfix expression = result of infixToPostfix(infixExpression).
 * 4> Print postfix expression.
 * 5> End.
 * */

inline void Stacks :: infixToPostfixConversion() {
	string infixExpression;

	cout << "Enter the Infix Expression: ";
	cin >> infixExpression;

	string postfixExpression = infixToPostfix(infixExpression);

	if(postfixExpression != "") {
		cout << infixExpression << "  =>  " << postfixExpression << endl;
	} else {
		cout << "Expression's Brackets Error!" << endl;
	}

}


/*Algorithm for 'power(int base, int exponent)':-
 * 1> Start.
 * 2> Set power = 1.
 * 3> If exponent = 0, then return 1.
 * 4> Repeat steps 5 and 6 while exponent < 0.
 * 5> Set power = power * base.
 * 6> Decrement base by 1.
 * 7> End.
 * */

inline int Stacks :: power(int base, int exponent) {
	
	int power = 1;
	if(exponent == 0) {
		return 1;
	}
	
	while(exponent > 0) {
		power *= base;
		exponent--;
	}

	return power;
}


/*Algorithm for 'evaluateOperations(char operators, int operand1, int operand2)':-
 * 1> Start.
 * 2> If operators = +, then return sum of two operands.
 * 3> If operators = -, then return difference of second operand from first one.
 * 4> If operators = *, then return product of two operands.
 * 5> If operators = /, then return division of first operand by second one.
 * 6> If operators = %, then return remainder get from division of first operand by second one.
 * 7> If operators = ^, then return power of first operand to the second one.
 * 8> If operators is not equals to +, -, *, /, % or ^, then return 0.
 * 9> End.
 * */

inline int Stacks :: evaluateOperations(char operators, int operand1, int operand2) {
	
	switch(operators) {
		case '+':
			return operand1 + operand2;
		case '-':
			return operand1 - operand2;
		case '*':
			return operand1 * operand2;
		case '/':
			return operand1 / operand2;
		case '%':
			return operand1 % operand2;
		case '^':
			return power(operand1, operand2);
		default:
			return 0;
	}
}


/*Algorithm for 'postfixEvaluation(string postfixExpression)':-
 * 1> Start.
 * 2> Set topOfStack = 0.
 * 3> Set iteration = 0.
 * 4> Repeat steps 5 to 10 for iteration < length_of_postfix_expression.
 * 5> If postfixExpression[iteration] contains any operand, then push it into stack.
 * 6> If postfixExpression[iteration] contains any operand, then apply steps 7 to 10.
 * 7> Set operand2 = popped operand from stack.
 * 8> Set operand1 = popped operand from stack.
 * 9> Set result = returned value of evaluateOperations(postfixExpression[iteration], operand1, operand2).
 * 10> Push result into stack.
 * 11> Retunr result.
 * 12> End.
 * */

inline int Stacks :: postfixEvaluation(string postfixExpression) {
	topOfStack = 0;
	int result;
	
	for(int iteration = 0; iteration < postfixExpression.length(); iteration++) {
		
		if((postfixExpression[iteration] > 47) && (postfixExpression[iteration] < 58)) {
			
			string expressionIteration = "";
                        expressionIteration += postfixExpression[iteration];

			pushElement(expressionIteration);
		} else if((postfixExpression[iteration] == 37) ||
			  (postfixExpression[iteration] == 42) ||
			  (postfixExpression[iteration] == 43) ||
			  (postfixExpression[iteration] == 45) ||
			  (postfixExpression[iteration] == 47) ||
			  (postfixExpression[iteration] == 94)
		) {
			int operand2 = stoi(popElement());
			int operand1 = stoi(popElement());

			result = evaluateOperations(postfixExpression[iteration], operand1, operand2);	

			pushElement(to_string(result));
		}

	}

	return result;
}


/*Algorithm for 'postfixExpression()':-
 * 1> Start.
 * 2> Read infix expression.
 * 3> Set postfix expression = returned string of infixToPostfix(infixExpression).
 * 4> If postfix expression is not equal to null, then print evaluation result. Otherwise, print Expression's Bracket Error.
 * 5> End.
 * */

inline void Stacks :: postfixExpression() {
	string infixExpression;
	
	cout << "Enter the Infix Expression:";
	cin >> infixExpression;
	
	string postfixExpression = infixToPostfix(infixExpression);
	
	if(postfixExpression != "") {
		int result = postfixEvaluation(postfixExpression);

		cout << infixExpression << "  =>  " << postfixExpression << "  =>  " << result << endl;
	} else {
		cout << "Expression's Brackets Error!" << endl;
	}
}


/*Algorithm for function 'main()':-
 * 1> Start.
 * 2> Call function options_for_menus.
 * 5> End.
 * */

int main() {	
	Stacks stk;
	
	stk.postfixExpression();	
	return 0;
}
