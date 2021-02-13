import java.util.Scanner;

class ReverseInt {
	private int number;
	private void inputNumber() {
		Scanner scanner = new Scanner(System.in);

                System.out.print("Enter the number: ");
                number = scanner.nextInt();
	}

	// Methods return the reverse of number entered by the user to the displayReverse()
	private int reverse() {
		int reverse = 0;
		int number = this.number;
		while(number != 0) {
			reverse = reverse * 10 + number % 10;
			number /= 10;
		}
		return reverse;	
	}

	private void displayReverse() {
		System.out.println("Reverse of " + this.number + " is " + reverse());
	}

	public static void main(String[] args) {
		ReverseOfNumber reverse = new ReverseOfNumber();		
		reverse.inputNumber();
		reverse.displayReverse();
	}	
}
