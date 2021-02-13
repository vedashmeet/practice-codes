class SuperClass
{
	protected int x;
	protected int y;
	public void get(int a)					//Not Work
	{
		x=a;
		System.out.println(x);
	}
	public void get(int a,int b)
	{
		y=b;
		System.out.println(y);
	}
}
class SubClass extends SuperClass
{
	private int x,z;
	public void get(int a)        //Work
	{
		x=a;
		System.out.println(x);
	}
	public void put()
	{
		z=x+y;;
		System.out.println(z);
	}
	
}
public class OverloadingAndOveriding
{
	public static void main(String[] args)
	{
		SubClass sb=new SubClass();
		sb.get(5);
		sb.get(7,8);
		sb.put();
	}
}