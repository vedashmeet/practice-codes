class ClsAndObj
{
	private int x,y,z;
	public void input(int a,int b)
	{
		x=a;
		y=b;
	}
	public void output()
	{
		z=x+y;
		System.out.println("Addition of two numbers is "+z);
	}
}
public class ClassesAndObjects
{
	public static void main(String[] args)
	{
		ClsAndObj cao=new ClsAndObj();
		cao.input(5,8);
		cao.output();
	}
}