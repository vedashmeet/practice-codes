import java.util.Scanner;
class Account
{
	private int bal;
	public Account(int bal)
	{
		this.bal=bal;
	}
	public boolean insufficientBalance(int w)
	{
		if(bal>w)
			return(true);
		else
			return(false);
	}
	public void withdrawl(int amt)
	{
		bal=bal-amt;
		System.out.println("Withdrawl Money is "+amt);
		System.out.println("Your current balance is "+bal);
	}
}
class Customer implements Runnable
{
	private String name;
	private Account account;
	public Customer(Account account,String n)
	{
		this.account=account;
		name=n;
	}
	public void run()
	{
		Scanner kb=new Scanner(System.in);
		System.out.println(name+",Enter amount to withdrawl");
		int amt=kb.nextInt();
		synchronized(account)
		{
			if(account.insufficientBalance(amt)==true)
			{
				System.out.println(name);
				account.withdrawl(amt);
			}
			else
				System.out.println("Insufficient Balance");
		}
	}
}
public class SynchronizedBlock
{
	public static void main(String[] args)
	{
		Account a1=new Account(1000);
		Customer c1=new Customer(a1,"abc ");
		Customer c2=new Customer(a1,"xyz ");
		Thread t1=new Thread(c1);
		Thread t2=new Thread(c2);
		t1.start();
		t2.start();
	}
}  