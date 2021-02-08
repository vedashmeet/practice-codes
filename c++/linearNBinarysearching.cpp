#include<iostream>

using namespace std;

class Searching {
	private	: int arraySize;
		  void optionMenu(int*, int*);
		  void linearSearch(int*, int*);
		  void readArray(int*, int*);
		  void binarySearch(int*, int*);
	public	: Searching();
};

inline Searching :: Searching() {
	cout << "Enter the size of array: ";
	cin >> arraySize;

	int array[arraySize];
	optionMenu(array, &arraySize);
}

inline void Searching :: readArray(int *array, int *arraySize) {
	cout << "Enter the list of array (in non-repeated-sorted form for binary searching):" << endl;
	

        for(int iteration = 0; iteration < *arraySize; iteration++) {
                cin >> array[iteration];
        }
}

inline void Searching :: binarySearch(int *array, int *arraySize) {
	readArray(array, arraySize);

	int low = 0;
	int high = (int)*arraySize - 1;

	int element, notMatchedElement = 0, matchedElementLength = -1, matchedElements[(int)*arraySize];
        cout << "Enter the element you want to search: ";
        cin >> element;

	while(low <= high) {
		int mid = low + (high - low) / 2;
		
		if (array[mid] == element) {
			matchedElementLength++;
                        matchedElements[matchedElementLength] = mid;
		} else {
			notMatchedElement++;
		}
		
		if (array[mid] < element) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}

	if(notMatchedElement == (int)*arraySize) {
                cout << "No element matched in the list with your specified element" << endl;
        } else {
                cout << "\nElements matched in the list with your specified element at followig position:\n";

                for(int iteration = 0; iteration <= matchedElementLength; iteration++) {
                        cout << matchedElements[iteration] + 1 <<endl;
                }
	}
}

inline void Searching :: linearSearch(int *array, int *arraySize) {
	
	readArray(array, arraySize);
		
	int element, notMatchedElement = 0, matchedElementLength = -1, matchedElements[(int)*arraySize];
	cout << "Enter the element you want to search: ";
	cin >> element;

	for(int iteration = 0; iteration < *arraySize; iteration++) {
	
		if(array[iteration] == element) {
			matchedElementLength++;
			matchedElements[matchedElementLength] = iteration;
		} else {
			notMatchedElement++;
		}

	}

	if(notMatchedElement == (int)*arraySize) {
		cout << "No element matched in the list with your specified element" << endl;
	} else {
		cout << "\nElements matched in the list with your specified element at followig position:\n";
	
		for(int iteration = 0; iteration <= matchedElementLength; iteration++) {
			cout << matchedElements[iteration] + 1 <<endl;
		}

	}
}

inline void Searching :: optionMenu(int *array, int *arraySize) {
	int choice;

	cout << "\nPress 1 to Linear Search the position of the elements from the list";
	cout << "\nPress 2 to Binary Search the position of the elements from the list";
	cout << "\nPress 0 to Quit";

	cout << "\nEnter your choice: ";
	cin >> choice;
	
	switch(choice) {
		case 1:
			linearSearch(array, arraySize);
			optionMenu(array, arraySize);
			break;
		case 2:
			binarySearch(array, arraySize);
			optionMenu(array, arraySize);
			break;
		case 0:
			break;
		default:
			cout << "Invalid choice" << endl;
			optionMenu(array, arraySize);
	}

}
int main() {
	Searching srg;
	return 0;
}
