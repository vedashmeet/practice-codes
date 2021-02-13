class StaticVariableMethod {
	private static int count;
	
	private static void incrementCount() {
		count++;
	}

	private void displayCount() {
		System.out.println("value of count is " + count);
	}

	public static void main(String[] args) {
		// static variable can be initialised and accessed by the name of class
		StaticVariableMethod.count = 1;
		
		StaticVariableMethod static1 = new StaticVariableMethod();
		StaticVariableMethod static2 = new StaticVariableMethod();

		System.out.println("Before Increment in static method, ");
		System.out.print("For first instance, ");
		static1.displayCount();
		System.out.print("For second instance, ");
		static2.displayCount();

		// value of static variable is same for every instance of same class 
		StaticVariableMethod.incrementCount();

		System.out.println("After Increment in static method, ");
		System.out.print("For first instance, ");
		static1.displayCount();
		System.out.print("For second instance, ");
		static2.displayCount();
	}
}