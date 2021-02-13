class A implements Runnable
{
	public void run()
	{
		for(int i=1;i<=10;i++)
		{
			System.out.println("Thread A"+i);
		}
	}
}
class B implements Runnable
{
	public void run()
	{
		for(int i=1;i<=10;i++)
		{
			System.out.println("Thread B"+i);
		}
	}
}
public class RunnableInterface
{
	public static void main(String[] args)
	{
		Thread t1=new Thread(new A());
		Thread t2=new Thread(new B());
		t1.start();
		t2.start();
	}
}