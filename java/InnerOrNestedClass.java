class Outer
{
	//int x=10;
	static int x=10;
	static class Inner
	//class Inner
	{
		void fn()
		{
			System.out.println("Hello");
			System.out.println(x);
		}
	}
}
public class InnerOrNestedClass
{
	public static void main(String[] args)
	{
		//Outer out=new Outer();
		//Outer.Inner in=out.new Inner();
		Outer.Inner in=new Outer.Inner();
		in.fn();
	}	
}