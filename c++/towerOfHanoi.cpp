//*Program to implement Tower Of Hanoi using stacks and recursion using C++

#include<iostream>
#include<cstring>

using namespace std;

class TowerOfHanoi {
	private	: int towerSize;
	          int *towerA;
		  int *towerB;
		  int *towerC;
		  int topOfTowerA;
		  int topOfTowerB;
		  int topOfTowerC;
	
		  void fillTowerA();
		  bool checkOverflow(int);
		  bool checkUnderflow(int);
		  void printTower();
		  void pushRing(char, int);
		  int popRing(char);
		  void towerOfHanoi(int, char, char, char); 

	public	: TowerOfHanoi();
		  void tower();
};


/*Algorithm for 'TowerOfHanoi()':-
 * 1> Start.
 * 2> Read number of rings in tower.
 * 3> Set top of each towers = 0.
 * 4> Call fillTowerA().
 * 5> End.
 * */

inline TowerOfHanoi :: TowerOfHanoi() {
	cout << "Enter the number of rings in tower: ";
	cin >> towerSize;

	towerA = new int[towerSize];
	towerB = new int[towerSize];
	towerC = new int[towerSize];
	topOfTowerA = 0;
	topOfTowerB = 0;
	topOfTowerC = 0;
	
	fillTowerA();
}


/*Algorithm for function 'fillTowerA()':-
 * 1> Start.
 * 2> Set iteration = 0.
 * 3> Repeat steps 4 to 7 while iteration < towerSize.
 * 4> towerA[iteration] = ringsCount.
 * 5> Increment iteration by 1.
 * 6> Decrement ringsCount by 1.
 * 7> Increment topOfTowerA by 1.
 * 8> End.
 * */

inline void TowerOfHanoi :: fillTowerA() {
	int ringsCount = towerSize;

	for(int iteration = 0; iteration < towerSize; iteration++, ringsCount--, topOfTowerA++) {
		towerA[iteration] = ringsCount;
	}

}


/*Algorithm for function 'checkOverflow(int topOfTower)':-
 * 1> Start.
 * 2> If top_of_tower = size_of_tower, then Stack Overflow. Otherwise not.
 * 3> End.
 * */

inline bool TowerOfHanoi :: checkOverflow(int topOfTower) {

	return (topOfTower == towerSize) ? true : false;
}


/*Algorithm for function 'checkUnderflow(int topOfTower)':-
 * 1> Start. 
 * 2> If top_of_tower = 0, then Stack Underflow. Otherwise not.
 * 3> End.
 * */

inline bool TowerOfHanoi :: checkUnderflow(int topOfTower) {
	
	return (topOfTower == 0) ? true : false;
}


/*Algorithm for function 'printTower()':-
 * 1> Start.
 * 2> Set iteration = 0.
 * 3> Repeat steps 4 and 5 for iteration < topOfTowerA.
 * 4> Print towerA[iteration].
 * 5> Increment iteration by 1.
 * 6> Set iteration = 0.
 * 7> Repeat steps 8 and 9 for iteration < topOfTowerB.
 * 8> Print towerB[iteration].
 * 9> Increment iteration by 1.
 * 10> Set iteration = 0.
 * 11> Repeat steps 12 and 13 for iteration < topOfTowerC.
 * 12> Print towerC[iteration].
 * 13> Increment iteration by 1.
 * 14> End.
 * */

inline void TowerOfHanoi :: printTower() {
	cout << "\n\n\nTower A:" << endl;
	
	for(int iteration = 0; iteration < topOfTowerA; iteration++) {
		cout << " | " << towerA[iteration];			
	}

	cout << "\nTower B:" << endl;
	
	for(int iteration = 0; iteration < topOfTowerB; iteration++) {
		cout << " | " << towerB[iteration];			
	}

	cout << "\nTower C:" << endl;
	
	for(int iteration = 0; iteration < topOfTowerC; iteration++) {
		cout << " | " << towerC[iteration];			
	}

	cout << endl;

}


/*Algorithm for function 'pushRing(char tower, int ring)':-
 * 1> Start.
 * 2> If tower = A, then apply steps 3 to 5.
 * 3> If stack not overflow, then apply steps 4 and 5. Otherwise print Stack is full.
 * 4> Set towerA[topOfTowerA] = ring.
 * 5> Increment topOfTowerA by 1.
 * 6> If tower = B, then apply steps to 7 to 9.
 * 7> If stack not overflow, then apply steps 8 and 9. Otherwise print Stack is full.
 * 8> Set towerB[topOfTowerB] = ring.
 * 9> Increment topOfTowerB by 1.
 * 10> If tower = C, then apply steps 11 to 13.
 * 11> If stack not overflow, then apply steps 12 and 13. Otherwise print Stack is full.
 * 12> Set towerC[topOfTowerC] = ring.
 * 13> Increment topOfTowerC by 1.
 * 14> End.
 * */

inline void TowerOfHanoi :: pushRing(char tower, int ring) {
	
	switch(tower) {
		case 'A':
			
			if(!checkOverflow(topOfTowerA)) {
				towerA[topOfTowerA] = ring;
				topOfTowerA ++;
			} else {
				cout << "\n*****Stack is full*****" << endl;
			}

			break;
		case 'B':
			
			if(!checkOverflow(topOfTowerB)) {
				towerB[topOfTowerB] = ring;
				topOfTowerB ++;
			} else {
				cout << "\n*****Stack is full*****" << endl;
			}

			break;
		case 'C':
			
			if(!checkOverflow(topOfTowerC)) {
				towerC[topOfTowerC] = ring;
				topOfTowerC ++;
			} else {
				cout << "\n*****Stack is full*****" << endl;
			}

			break;
		default:
			cout << "\n\nNot a Name of any Tower\n\n";
	}

}


/*Algorithm for function 'popRing(char tower)':-
 * 1> Start.
 * 2> If stack not underflow, then apply step 3. Otherwise print Stack is empty and return nothing.
 * 3> Decrement topOfTowerA by 1 and return top of tower A.
 * 4> If stack not underflow, then apply step 5. Otherwise print Stack is empty and return nothing.
 * 5> Decrement topOfTowerB by 1 and return top of tower B.
 * 6> If stack not underflow, then apply step 7. Otherwise print Stack is empty and return nothing.
 * 7> Decrement topOfTowerc by 1 and return top of tower C.
 * 8> End.
 * */

inline int TowerOfHanoi :: popRing(char tower) {
	
	switch(tower) {
		case 'A':
			
			if(!checkUnderflow(topOfTowerA)) {
				topOfTowerA --;
				return towerA[topOfTowerA];
			} else {
				cout << "\n*****Stack is empty*****" << endl;
			}

			break;
		case 'B':
			
			if(!checkUnderflow(topOfTowerB)) {
				topOfTowerB --;
				return towerB[topOfTowerB];
			} else {
				cout << "\n*****Stack is empty*****" << endl;
			}

			break;
		case 'C':
			
			if(!checkUnderflow(topOfTowerC)) {
				topOfTowerC --;
				return towerC[topOfTowerC];
			} else {
				cout << "\n*****Stack is empty*****" << endl;
			}

			break;
		default:
			cout << "\n\nNot a Name of any Tower\n\n";
	}

	return 0;
}


/*Algorithm for function 'towerOfHanoi(int numberOfRings, char towerA, char towerB, char towerC)':-
 * 1> Start.
 * 2> If numberOfRings = 1, then push top element of towerA to towerC and print all towers.
 * 3> If numberOfRings not = 1, then recall towerOfHanoi(numberOfRings - 1, towerA, towerC, towerB), push top element of towerA to towerC, print all towers and recall towerOfHanoi(numberOfRings - 1, towerB, towerA, towerC).
 * 4> End.
 * */

inline void TowerOfHanoi :: towerOfHanoi(int numberOfRings, char towerA, char towerB, char towerC) {
	
	if(numberOfRings == 1) {
		pushRing(towerC, popRing(towerA));
		printTower();
		return;
	} else {
		towerOfHanoi(numberOfRings - 1, towerA, towerC, towerB);
		pushRing(towerC, popRing(towerA));
		printTower();
		towerOfHanoi(numberOfRings - 1, towerB, towerA, towerC);
	}
	
}


/*Algorithm for function 'tower()':-
 * 1> Start.
 * 2> Set numberOfRings = towerSize.
 * 3> Call printTower() and towerOfHanoi(numberOfRings, 'A', 'B', 'C').
 * 4> End.
 * */

inline void TowerOfHanoi :: tower() {
	int numberOfRings = towerSize;
	
	printTower();
	towerOfHanoi(numberOfRings, 'A', 'B', 'C');
}


/*Algorithm for function 'main()':-
 * 1> Start.
 * 2> Call tower().
 * 5> End.
 * */

int main() {	
	TowerOfHanoi toh;
	
	toh.tower();	
	return 0;
}
