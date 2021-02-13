class A extends Thread
{
	public void run()
	{
		for(int i=1;i<=10;i++)
		{
			System.out.println("Thread A"+i);
		}
	}
}
class B extends Thread
{
	public void run()
	{
		for(int i=1;i<=10;i++)
		{
			System.out.println("Thread B"+i);
		}
	}
}
public class SleepMethod
{
	public static void main(String[] args)
	{
		A t1=new A();
		B t2=new B();
		t1.start();
		try
		{
			Thread.sleep(3000);
		}
		catch(InterruptedException e)
		{}
		t2.start();
	}
}