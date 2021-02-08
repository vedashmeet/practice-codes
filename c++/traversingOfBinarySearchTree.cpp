//*Program to traverse Binary Search Tree in different order in C++
#include<iostream>

using namespace std;

class BinarySearchTree {
	private	: struct node {
		  	int element;
			struct node *linkToLeft;
			struct node *linkToRight;
		  };

		  void optionMenu(struct node *);
		  void insertElement(struct node **);
		  struct node* insert(struct node *, int);
		  void inOrderTraversal(struct node *);
		  void preOrderTraversal(struct node *);
		  void postOrderTraversal(struct node *);
		  bool searchElement(struct node *, int);
	public	: void initialiseList();
};


/*Algorithm for 'initialiseList()':-
 * 1> Start.
 * 2> Set root = NULL.
 * 3> Call optionMenu().
 * 4> End.
 * */

inline void BinarySearchTree :: initialiseList() {
	struct node *root;
	
	root = NULL;

	optionMenu(root);
}


/*Algorithm for 'optionMenu(struct node *root)':-
 * 1> Start.
 * 2> Press 1 to insert element into tree and call optionMenu().
 * 3> Press 2 to traverse the tree in in-order and call optionMenu().
 * 4> Press 3 to traverse the tree in pre-order and call optionMenu().
 * 5> Press 4 to traverse the tree in post-order and call optionMenu().
 * 6> Press 5 to search an element from tree and call optionMenu().
 * 7> Press 0 to quit.
 * 8> End.
 * */

inline void BinarySearchTree :: optionMenu(struct node *root) {
	int choice;
	
	cout << "\n\nPress 1 to insert element into tree" << endl;
	cout << "Press 2 to traverse the tree in In-order" << endl;
	cout << "Press 3 to traverse the tree in Pre-order" << endl;
	cout << "Press 4 to traverse the tree in Post-order" << endl;
	cout << "Press 5 to search an element from the tree" << endl;
	cout << "Press 0 to Quit" << endl;

	cout << "Enter your choice: ";
	cin >> choice;

	switch(choice) {
		case 1:
			insertElement(&root);
			optionMenu(root);
			break;
		case 2:
			inOrderTraversal(root);
			optionMenu(root);
			break;
		case 3:
                        preOrderTraversal(root);
                        optionMenu(root);
                        break;
		case 4:
                        postOrderTraversal(root);
                        optionMenu(root);
                        break;
		case 5:
			int element;

			cout << "Enter the element you want to search from tree: ";
			cin >> element;

			if(searchElement(root, element)) {
				cout << "Element exists" << endl;
			} else {
				cout << "Element doesn't exists" << endl;
			}

			optionMenu(root);
			break;
		case 0:
			break;
		default:
			cout << "Invalid choice!" << endl << endl;
			optionMenu(root);
	}

}


/*Algorithm for 'insertElement(struct node **root)':-
 * 1> Start.
 * 2> Create pointer and set it equals to root.
 * 3> Set Forward-Link of newList node = *pointer.
 * 4> If *start not = to NULL, then set Backward-Link of Forward-Link of newList node = newList. Otherwise set *end = newList.
 * 5> Set *start = newList.
 * 6> Set Backward-Link of newList = NULL.
 * 7> End.
 * */

inline void BinarySearchTree :: insertElement(struct node **root) {
	int choice;

	struct node *pointer;
	pointer = *root;

	cout << "\nPress any positive integer as element of tree" << endl;
	cout << "Press -1 to exit the insertion loop" << endl;

	cout << "Enter the data: ";
	cin >> choice;

	while(choice != -1) {
		
		if(pointer == NULL) {
			pointer = insert(pointer, choice);
		} else {
			insert(pointer, choice);
		}

		cin >> choice;

	}

	*root = pointer;
}


/**/

inline struct BinarySearchTree :: node* BinarySearchTree :: insert(struct node *pointer, int element) {
	
	if(pointer == NULL) {
		struct node *newNode;
		newNode = new node();

		newNode->element = element;
		newNode->linkToLeft = NULL;
		newNode->linkToRight = NULL;
		return newNode;
	}
	
	if(element < pointer->element) {
		pointer->linkToLeft = insert(pointer->linkToLeft, element);
	} else if(element > pointer->element) {
		pointer->linkToRight = insert(pointer->linkToRight, element);
	}

	return pointer;
}


/**/

inline void BinarySearchTree :: inOrderTraversal(struct node *root) {
	
	if(root != NULL) {
		inOrderTraversal(root->linkToLeft);
		cout << root->element << "\t";
		inOrderTraversal(root->linkToRight);	
	}
}


/**/

inline void BinarySearchTree :: preOrderTraversal(struct node *root) {
        
	if(root != NULL) {
		cout << root->element << "\t";
                preOrderTraversal(root->linkToLeft);
                preOrderTraversal(root->linkToRight);
        }
}


/**/

inline void BinarySearchTree :: postOrderTraversal(struct node *root) {
        
	if(root != NULL) {
                postOrderTraversal(root->linkToLeft);
                postOrderTraversal(root->linkToRight);
		cout << root->element << "\t";
        }
}


/**/

inline bool BinarySearchTree :: searchElement(struct node *root, int element) {
        
	if(root == NULL) {
		return false;
	}

	if(root->element == element) {
		return true;
	}

	if(searchElement(root->linkToLeft, element)) {
		return true;
	}

        return (searchElement(root->linkToRight, element));
}


/*Algorithm for 'main()':-
 * 1> Start.
 * 2> Call initialiseList().
 * 3> End.
 * */

int main() {
	BinarySearchTree bst;
	bst.initialiseList();
	return 0;
}
