//*Program to perform basic data structure operation on Array using C++

#include<iostream>
using namespace std;


/*Algorithm for function 'checkOverflow(int *arrayLength, int maxLength)':-
 * 1> Start.
 * 2> If number_of_elements_in_array = maximum_length_of_array, then function return true. Otherwise return false.
 * 3> End.
 * */

bool checkOverflow(int *arrayLength, int maxLength) {
	
	if(*arrayLength == maxLength) {
		return true;
	}

	return false;
}


/*Algorithm for function 'checkUnderflow(int *arrayLength)':-
 * 1> Start. 
 * 2> If number_of_elements_in_array = 0, then function return true. Otherwise false.
 * 3> End.
 * */

bool checkUnderflow(int *arrayLength) {
	
	if(*arrayLength == 0) {
		return true;
	}

	return false;
}


/*Algorithm for function 'printArray(int *array, int *arrayLength)':-
 * 1> Start.
 * 2> If array not underflow, then apply steps 3 to 6. Otherwise print Array is empty.
 * 3> Set iteration = lower_bound.
 * 4> Repeat steps 5 and 6 for iteration < number_of_elements_in_array.
 * 5> Print array[iteration].
 * 6> Increment iteration by 1.
 * 7> End.
 * */

void printArray(int *array, int *arrayLength) {
	
	if(!checkUnderflow(arrayLength)) {
		cout << "\n\n\nResultant Array is:" << endl;
		
		for(int iteration = 0; iteration < *arrayLength; iteration++) {
			cout << array[iteration] << endl;
		}

	} else {
		cout << "\n*****Null Array*****" << endl;
	}

}


/*Algorithm for function 'insertElementAtEnd(int *array, int *arrayLength, int maxLength)':-
 * 1> Start.
 * 2> If array not overflow, then apply steps 3 and 4. Otherwise print Array is full.
 * 3> Read array[location_of_last_element + 1].
 * 4> Increment number_of_elements_in_array by 1.
 * 5> End.
 * */

void insertElementAtEnd(int *array, int *arrayLength, int maxLength) {
	
	if(!checkOverflow(arrayLength, maxLength)) {
		cout << "Enter the new element: ";
		cin >> array[*arrayLength];
		*arrayLength = (int)*arrayLength + 1;
	} else {
		cout << "\n*****Array is full*****" <<endl;
	}

}


/*Algorithm for function'insertElementAtBegin(int *array, int *arrayLength, int maxLength)':-
 * 1> Start.
 * 2> If array not overflow, then apply steps 3 to 8. Otherwise print Array is full.
 * 3> Set iteration = number_of_elements_in_array - 1.
 * 4> Repeat steps 5 and 6 for iteration >= lower_bound.
 * 5> Set array[iteration + 1] = array[iteration].
 * 6> Decrement iteration by 1.
 * 7> Read array[lower_bound].
 * 8> Increment number_of_elements_in_array by 1.
 * 9> End.
 * */

void insertElementAtBegin(int *array, int *arrayLength, int maxLength) {
	
	if(!checkOverflow(arrayLength, maxLength)) {
		cout << "Enter the new element: ";
	
		for(int iteration = *arrayLength - 1; iteration >= 0; iteration--) {
			array[iteration + 1] = array[iteration];
		}

		cin >> array[0];
		*arrayLength = (int)*arrayLength + 1;
	} else {
		cout << "\n*****Array is full*****" << endl;
	}

}


/*Algorithm for function 'insertElementAtIthPoition(int *array, int *arrayLength, int maxLength)':-
 * 1> Start.
 * 2> If array not overflow, then apply steps 3 to 10. Otherwise print Array is full.
 * 3> Read location at which you want to enter new element in general way.
 * 4> Decrement location_of_new_element by 1.
 * 5> Set iteration = number_of_elements_in_array - 1.
 * 6> Repeat steps 7 and 8 for iteration >= location_of_new_element.
 * 7> Set array[iteration + 1] = array[iteration].
 * 8> Decrement iteration by 1.
 * 9> Read array[location_of_new_element].
 * 10> Increment number_of_elements_in_array by 1.
 * 11> End.
 * */

void insertElementAtIthPosition(int *array, int *arrayLength, int maxLength) {
	
	if(!checkOverflow(arrayLength, maxLength)) {
		int location;
		cout << "Enter the position where you want to enter new element: ";
		cin >> location;
		location--;
		cout << "Enter the new element: ";
	
		for(int iteration = *arrayLength - 1; iteration >= location; iteration--) {
			array[iteration + 1] = array[iteration];
		}
		cin >> array[location];
		*arrayLength = (int)*arrayLength + 1;
	} else {
		cout << "\n*****Array is full*****" << endl;
	}

}


/*Algorithm for function 'deleteElementAtEnd(int *arrayLength)':-
 * 1> Start.
 * 2> If array not underflow, then apply step 3. Otherwise print Array is empty.
 * 3> Decrement number_of_elements_in_array by 1.
 * 4> End.
 * */

void deleteElementFromEnd(int *arrayLength) {
	
	if(!checkUnderflow(arrayLength)) {
		*arrayLength = (int)*arrayLength - 1;
	} else {
		cout << "\n*****Array is empty*****" << endl;
	}

}


/*Algorithm for function'deleteElementAtBegin(int *array, int *arrayLength)':-
 * 1> Start.
 * 2> If array not underflow, then apply steps 3 to 7. Otherwise print Array is empty.
 * 3> Set iteration = lower_bound + 1.
 * 4> Repeat steps 5 and 6 for iteration <= number_of_element_in_array.
 * 5> Set array[iteration - 1] = array[iteration].
 * 6> Increment iteration by 1.
 * 7> Decrement number_of_elements_in_array by 1.
 * 8> End.
 * */

void deleteElementFromBegin(int *array, int *arrayLength) {

	if(!checkUnderflow(arrayLength)) {
		
		for(int iteration = 1; iteration <= *arrayLength; iteration++) {
			array[iteration - 1] = array[iteration];
		}
	
		*arrayLength = (int)*arrayLength - 1;
	} else {
		cout << "\n*****Array is empty*****" << endl;
	}

}


/*Algorithm for function 'deleteElementAtIthPoition(int *array, int *arrayLength)':-
 * 1> Start.
 * 2> If array not underflow, then apply steps 3 to 9. Otherwise print Array is empty.
 * 3> Read location at which you want to delete element in general way.
 * 4> Decrement location_of_element by 1.
 * 5> Set iteration = location_of_element + 1.
 * 6> Repeat steps 7 and 8 for iteration < total_number_of_element.
 * 7> Set array[iteration - 1] = array[iteration].
 * 8> Increment iteration by 1.
 * 9> Decrement number_of_elements_in_array by 1.
 * 10> End.
 * */

void deleteElementFromIthPosition(int *array, int *arrayLength) {
	
	if(!checkUnderflow(arrayLength)) {
		int location;
		cout << "Enter the position from where you want to delete the element: ";
		cin >> location;
		location--;
	
		for(int iteration = location + 1; iteration < *arrayLength; iteration++) {
			array[iteration - 1] = array[iteration];
		}

		*arrayLength = (int)*arrayLength - 1;
	} else {
		cout << "\n*****Array is empty*****" << endl;
	}

}


/*Algorithm for function 'deleteSpecificElement(int *array, int *arrayLength)':-
 * 1> Start.
 * 2> If array not underflow, then apply steps 3 to 16. Otherwise print Array is empty.
 * 3> Set flag-counter_for_non-matching_element = 0.
 * 4> Read element that you want to delete from the list.
 * 5> Set first_iteration = lower_bound.
 * 6> Repeat steps 7 to 15 for first_iteration < number_of_elements_in_array.
 * 7> If array[first_iteration] = elements_want_to_delete, then apply steps 8 to 13.
 * 8> Set second_iteration = first_iteration + 1.
 * 9> Repeat steps 10 and 11 for second_iteration < number_of_elements_in_array.
 * 10> Set array[second_iteration - 1] = array[second_iteration];
 * 11> Increment second_iteration by 1.
 * 12> Increment number_of_elements_in_array.
 * 13> Set iteration = 0.
 * 14> If array[first_iteration] is not-equals-to elements_want_to_delete, then Increment flag-counter_for_non-matching_element by 1.
 * 15> Increment first_iteration by 1.
 * 16> If flag-counter_for_non-matching_element = number_of_elements_in_array, then Print element not matched in array.
 * 17> End.
 * */

void deleteSpecificElement(int *array, int *arrayLength) {
	
	if(!checkUnderflow(arrayLength)) {
		int element, notMatchedElement = 0;
		cout << "Enter the element you want to delete from the list: ";
		cin >> element;

		for(int iteration = 0; iteration < *arrayLength; iteration++) {
		
			if(array[iteration] == element) {

				for(int iteration2 = iteration + 1; iteration2 < *arrayLength; iteration2++) {
					array[iteration2 - 1] = array[iteration2];
				}

				*arrayLength = (int)*arrayLength - 1;
				iteration = 0;
			} else {
				notMatchedElement++;
			}

		}

		if(notMatchedElement == (int)*arrayLength) {
			cout << "No element matched in the list with specified element" << endl;
		}

	} else {
		cout << "\n*****Array is empty*****" << endl;
	}

}


/*Algorithm for function 'linearSearch(int *array, int *arrayLength)':-
 * 1> Start.
 * 2> If array not underflow, then apply steps 3 to 15. Otherwise print Array is empty.
 * 3> Set flag-counter_for_non-matching_element = 0, number_of_element_in_array_of_matching_element = -1.
 * 4> Read element_you_want_to_search.
 * 5> Set iteration = lower_bound.
 * 6> Repeat steps 7 to 10 for iteration < number_of_elements_in_array.
 * 7> If array[iteration] = elements_want_to_search, then apply steps 8 and 9.
 * 8> Increment number_of_element_in_array_of_matching_element by 1.
 * 9> Set array_of_matching_element[number_of_element_in_array_of_matching_element] = iteration.
 * 10> If array[iteration] is not equals to elements_want_to_search, then Increment flag-counter_for_non-matching_element by 1.
 * 11> If flag-counter_for_non-matching_element = number_of_elements_in_array, then Print element not matched in array. Otherwise apply steps 12 to 15.
 * 12> Set iteration = 0.
 * 13> Repeat steps 14 and 15 for iteration <= number_of_element_in_array_of_matching_element.
 * 14> Print array_of_matching_element[iteration].
 * 15> Increment iteration by 1. 
 * 16> End.
 * */

void linearSearch(int *array, int *arrayLength) {
	
	if(!checkUnderflow(arrayLength)) {
		int element, notMatchedElement = 0, matchedElementLength = -1, matchedElements[10];
		cout << "Enter the element you want to search: ";
		cin >> element;

		for(int iteration = 0; iteration < *arrayLength; iteration++) {
		
			if(array[iteration] == element) {
				matchedElementLength++;
				matchedElements[matchedElementLength] = iteration;
			} else {
				notMatchedElement++;
			}

		}
	
		if(notMatchedElement == (int)*arrayLength) {
			cout << "No element matched in the list with your specified element" << endl;
		} else {
			cout << "\nElements matched in the list with your specified element at followig position:\n";
		
			for(int iteration = 0; iteration <= matchedElementLength; iteration++) {
				cout << matchedElements[iteration] + 1 <<endl;
			}

		}

	} else {
		cout << "\n*****Array is empty*****" << endl;
	}

}


/*Algorithm for function 'optionMenu(int *array, int *arrayLength, int maxLength):-
 * 1> Start.
 * 2> Print list of all 9 option.
 * 3> Read choice_of_user.
 * 4> If choice = 1, then call both two functions of insertion_of_an_element_at_end and for printing_of_array and recursion.
 * 5> If choice = 2, then call both two functions of insertion_of_an_element_at_beginning and for printing_of_array and recursion.
 * 6> If choice = 3, then call both two functions of insertion_of_an_element_at_Ith_position and for printing_of_array and recursion.
 * 7> If choice = 4, then call both two functions of deletion_of_an_element_from_end and for printing_of_array and recursion.
 * 8> If choice = 5, then call both two functions of deletion_of_an_element_from_beginning and for printing_of_array and recursion.
 * 9> If choice = 6, then call both two functions of deletion_of_an_element_from_Ith_position and for printing_of_array and recursion.
 * 10> If choice = 7, then call both two functions of deletion_of_a_specific_element and for printing_of_array and recursion.
 * 11> If choice = 8, then call function of linear_searching_of_an_element and recursion.
 * 12> If choice = 0, then program will be quit.
 * 13> If choice is not-equals-to 1, 2, 3, 4, 5, 6, 7, 8 or 0, then print Invalid Choice and recursion.
 * 14> End.
 * */

void optionMenu(int *array, int *arrayLength, int maxLength) {
	int choice;

	cout << "\nPress 1 to insert element at end of the list";
	cout << "\nPress 2 to insert element at beginning of the list";
	cout << "\nPress 3 to insert element at ith position of the list";
	cout << "\nPress 4 to delete element from end of the list";
	cout << "\nPress 5 to delete element from beginning of the list";
	cout << "\nPress 6 to delete element from ith position of the list";
	cout << "\nPress 7 to delete a specific element from the list";
	cout << "\nPress 8 to search linearly the position of the specified element in the list";
	cout << "\nPress 0 to Quit";

	cout << "\nEnter your choice: ";
	cin >> choice;
	
	switch(choice) {
		case 1:
			insertElementAtEnd(array, arrayLength, maxLength);
			printArray(array, arrayLength);
			optionMenu(array, arrayLength, maxLength);
			break;
		case 2:
			insertElementAtBegin(array, arrayLength, maxLength);
			printArray(array, arrayLength);
			optionMenu(array, arrayLength, maxLength);
			break;
		case 3:
			insertElementAtIthPosition(array, arrayLength, maxLength);
			printArray(array, arrayLength);
			optionMenu(array, arrayLength, maxLength);
			break;
		case 4:
			deleteElementFromEnd(arrayLength);
			printArray(array, arrayLength);
			optionMenu(array, arrayLength, maxLength);
			break;
		case 5: deleteElementFromBegin(array, arrayLength);
			printArray(array, arrayLength);
			optionMenu(array, arrayLength, maxLength);
			break;
		case 6: deleteElementFromIthPosition(array, arrayLength);
			printArray(array, arrayLength);
			optionMenu(array, arrayLength, maxLength);
			break;
		case 7:
			deleteSpecificElement(array, arrayLength);
			printArray(array, arrayLength);
			optionMenu(array, arrayLength, maxLength);
			break;
		case 8:
			linearSearch(array, arrayLength);
			optionMenu(array, arrayLength, maxLength);
			break;
		case 0:
			break;
		default:
			cout << "Invalid choice" << endl;
			optionMenu(array, arrayLength, maxLength);
	}

}


/*Algorithm for function 'main()':-
 * 1> Start.
 * 2> Read maximum_length_of_array.
 * 3> Set number_of_elements_in_array = 0.
 * 4> Call function printing_of_array and function options_for_menus.
 * 5> End.
 * */

int main() {
	int maxLength;
	
	cout << "Enter the size of the array: ";
	cin >> maxLength;

	int array[maxLength];
	int arrayLength = 0;

	printArray(array, &arrayLength);
	optionMenu(array, &arrayLength, maxLength);

	return 0;
}
