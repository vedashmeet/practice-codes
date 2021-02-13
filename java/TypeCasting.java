class TypeCasting {
	private int num1 = 10;
	private float num2 = 11.56f;

	private int explicitTypeCasting(float num) {
		return (int)num;
	}

	private float implicitTypeCasting(int num) {
		return num;
	}

	private void sumOfFloats() {
		//Implicit type casting apply on int converted into float
		System.out.println("(Implicit Type Casting) Sum of " + num1 + "(int) and " + num2 + "(float) is " + (implicitTypeCasting(num1) + num2));
	}

	private void sumOfInts() {
		//Explicit type casting apply on float converted into int
		System.out.println("(Explicit Type Casting) Sum of " + num1 + "(int) and " + num2 + "(float) is " + (num1 + explicitTypeCasting(num2)));
	}

	public static void main(String[] args) {
		TypeCasting typeCast = new TypeCasting();
		typeCast.sumOfFloats();
		typeCast.sumOfInts();
	}
}