interface SimpleInterface {
	final float PI = 3.14f;
	void display(String message);
}

class Interface implements SimpleInterface {
	public void display(String message) {
		System.out.print(message);
	}
	
	public static void main(String[] args) {
		Interface interfaceExample = new Interface();
		String message = "The value of PI is ";
		interfaceExample.display(message);
		System.out.println(PI);
	}
}