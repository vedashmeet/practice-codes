// When two or more constructors used in a program with different arguments is called constructor overloading
class Constructors {
	private String typeOfConstructor;
	private String parameteresOfConstructor;
	
	Constructors() {
		typeOfConstructor = "Default";
		parameteresOfConstructor = "no";
	}
	
	Constructors(String typeOfConstructor, String parameteresOfConstructor) {
		this.typeOfConstructor = typeOfConstructor;
		this.parameteresOfConstructor = parameteresOfConstructor;
	}
	
	public static void main(String[] args) {
		Constructors defaultConstructor = new Constructors();
		Constructors parameterisedConstructor = new Constructors("Parameterised", "many");
		
		System.out.println(defaultConstructor.typeOfConstructor + " constructors has " + defaultConstructor.parameteresOfConstructor + " parameters");
		System.out.println(parameterisedConstructor.typeOfConstructor + " constructors has " + parameterisedConstructor.parameteresOfConstructor + " parameters");
	}
}
