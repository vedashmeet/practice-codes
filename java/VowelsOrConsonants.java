import java.util.Scanner;
public class VowelsOrConstants {
	private String checkCharacter(char input) {
		if(((input > 64) && (input < 91)) || ((input > 96) && (input < 123))) {
			if(
			   (input == 65) || (input == 69) || (input == 73) || (input == 79) || (input == 85) ||
			   (input == 97) || (input == 101) || (input == 105) || (input == 111) || (input == 117)
			  ) {
				return input + " is vowel.";
			} else {
				return input + " is consonant.";
			}
		} else {
			return input + " is not an alphabet!";
		}
	}
	public static void main(String[] args) {
		System.out.print("Enter any alphabet to check wheter it is vowel or consonants: ");
		System.out.println(new CheckVowOrCons().checkCharacter(new Scanner(System.in).next().charAt(0)));
	}
}	
