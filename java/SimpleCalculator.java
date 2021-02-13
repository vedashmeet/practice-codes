import java.util.Scanner;

class Calculation {
	private double firstNumber;
	private double secondNumber;
	private String operation;

	Calculation(double firstNumber, double secondNumber, String operation) {
		this.firstNumber = firstNumber; 
		this.secondNumber = secondNumber;
		this.operation = operation;
	}

	String calculate() {
		switch(operation) {
			case "+":
				return this.firstNumber + " + " + this.secondNumber + " = " + add();
			case "-":
				return this.firstNumber + " - " + this.secondNumber + " = " + subtract();
			case "*":
				return this.firstNumber + " * " + this.secondNumber + " = " + multiply();
			case "/":
				return this.firstNumber + " / " + this.secondNumber + " = " + division();
			case "%":
				return this.firstNumber + " % " + this.secondNumber + " = " + remainder();
			default:
				return "Invalid operation! Try again.";
		}
	}

	double add() {
		return this.firstNumber + this.secondNumber;
	}

	double subtract() {
                return this.firstNumber - this.secondNumber;
        }

	double multiply() {
                return this.firstNumber * this.secondNumber;
        }

	double division() {
                return this.firstNumber / this.secondNumber;
        }

	int remainder() {
                return (int)(this.firstNumber % this.secondNumber);
        }

}
class SimpleCalculator {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		System.out.print("Enter the first number: ");
		double firstNumber = sc.nextDouble();

		System.out.print("Enter the second number: ");
                double secondNumber = sc.nextDouble();

		System.out.println("Enter the operation you want to perform, \n\t + for addition \n\t - for subtraction \n\t * for multiplication \n\t / for division % \n\t % to find remainder of division");
		String operation = sc.next();

		Calculation clc = new Calculation(firstNumber, secondNumber, operation);
		System.out.println(clc.calculate());
	}
}
