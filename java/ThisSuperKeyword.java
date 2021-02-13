class Profile {
	private String name;
	private int age;

	Profile(String name, int age) {
		this.name = name;
		this.age = age;
	}

	void display() {
		System.out.println("Name: " + this.name);
		System.out.println("Age: " + this.age + "yrs");
	}
}

class Person extends Profile {
	private float salary;

	Person(String name, int age, float salary) {
		// super keyword used to call constructor of base class
		super(name, age);
		this.salary = salary;
	}

	void display() {
		// super keyword used to call method of base class.
		super.display();
		System.out.println("Salary: " + this.salary);
	}
}

class ThisSuperKeyword {
	public static void main(String[] args) {
		Person person = new Person("Amay", 24, 1200f);
		person.display();
	}
}
