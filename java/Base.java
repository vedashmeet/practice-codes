class Base {
	protected void profile() {
		System.out.println("Name: Dashmeet Singh");
		System.out.println("Age: 19yrs");
	}
	protected void bio() {
		System.out.println("Pursuing BTech");
	}
	public static void main(String[] args) {
		Base base = new Base();
		base.profile();
		base.bio();
	}
}
class Derived extends Base {
	private void linkedAccount() {
		System.out.println("https://github.com/vedashmeet");
	}
	public static void main(String[] args) {
		Derived derived = new Derived();
		derived.profile();
		derived.bio();
		derived.linkedAccount();	}
}
