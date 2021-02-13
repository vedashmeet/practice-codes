abstract class  SuperClass
{
	protected int x,y;
	abstract void input();
}
class SubClassAdd extends SuperClass
{
	private int z;
	void input()
	{
		x=9;
		y=5;
	}
	public void add()
	{
		z=x+y;
		System.out.println("Addition of two  numbers is "+z);
	}
}
class SubClassSub extends SuperClass
{
	private int z;
	void input()
	{
		x=9;
		y=5;
	}
	public void sub()
	{
		z=x-y;
		System.out.println("Subtraction between two  numbers is "+z);
	}
}
public class AbstractMethods
{
	public static void main(String[] args)
	{
		/*SuperClass sp=new SuperClass();
		sp.input();*/
		SubClassAdd sca=new SubClassAdd();
		SubClassSub scs=new SubClassSub();
		sca.input();
		sca.add();
		scs.input();
		scs.sub();
	}
}