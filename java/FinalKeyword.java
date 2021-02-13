import java.util.Scanner;

class FinalKeyword {
	// value of PI cannot be change because it is final declared
	private static final float PI = 3.14f;
	private float radius;

	public static void main(String[] args) {
		FinalKeyword finalKeyword = new FinalKeyword();
		float radius = finalKeyword.radius;
		System.out.print("Enter radius of circle: ");
		radius = new Scanner(System.in).nextFloat();
		System.out.println("Area of circle of radius(" + radius + ") is: " + FinalKeyword.PI*radius*radius);
	}
}