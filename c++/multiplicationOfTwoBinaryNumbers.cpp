#include<iostream>

using namespace std;

class BinaryMultiplication {
	public	: int binaryProduct(int, int);
		  void multiplicationOfBinary();
};

inline int BinaryMultiplication :: binaryProduct(int binaryNumber1, int binaryNumber2) {
	int iteration = 0, remainder = 0, sum[20];
    	int binaryProd = 0;
 
    	while (binaryNumber1 != 0 || binaryNumber2 != 0) {
        	sum[iteration++] = (binaryNumber1 % 10 + binaryNumber2 % 10 + remainder) % 2;
        	remainder = (binaryNumber1 % 10 + binaryNumber2 % 10 + remainder) / 2;
        	binaryNumber1 /= 10;
        	binaryNumber2 /= 10;
	}
	
	if (remainder != 0) {
		sum[iteration++] = remainder;	
	}

    	iteration--;
    	
	while (iteration >= 0) {
        	binaryProd = binaryProd * 10 + sum[iteration--];	
	}

    	return binaryProd;
}

inline void BinaryMultiplication :: multiplicationOfBinary() {
	long int binaryNumber1, binaryNumber2, multiply = 0;
    	int digit, factor = 1;
	
	cout << "Enter the first binary number: ";
	cin >> binaryNumber1;
	cout << "Enter the second binary number: ";
	cin >> binaryNumber2;
	
	while (binaryNumber2 != 0) {
        	digit =  binaryNumber2 % 10;
        	
		if (digit == 1) {	
            		binaryNumber1 *= factor;
            		multiply = binaryProduct(binaryNumber1, multiply);
        	} else {
			binaryNumber1 *= factor;		
		}

        	binaryNumber2 /= 10;
        	factor = 10;
	}
	
	cout << "Product of two binary number is " << multiply << endl;
}

int main() {
	BinaryMultiplication bm;
	
	bm.multiplicationOfBinary();
	return 0;
}
