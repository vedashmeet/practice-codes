import java.util.Scanner;
class Customer
{
	Scanner sc=new Scanner(System.in);
	private String cust[][]=new String[4][50];
	private static int count;
	private static int balance=0;
	public Customer()
	{
		count=0;
	}
	public void addCustomer()
	{
		int i=0;
		System.out.println("Enter Name:");
		cust[i][count]=sc.next();
		i++;
		System.out.println("Enter Account Number:");
		cust[i][count]=sc.next();
		i++;
		System.out.println("Enter Account Type:");
		cust[i][count]=sc.next();
		i++;
		System.out.println("Enter Balanc:");
		cust[i][count]=sc.next();
		int b=Integer.parseInt(cust[i][count]);
		balance=b;
		count++;
	}
	public void dipAmount()
	{
		System.out.println("Enter Account Number:");
		int account=sc.nextInt();
		for(int i=0;i<count;i++)
		{
			int temp1=Integer.parseInt(cust[1][i]);
			if(account==temp1)
			{
				System.out.println("Enter money to deposit:");
				int deposit=sc.nextInt();
				balance+=deposit;
				String balan=Integer.toString(balance);
				cust[3][i]=balan;
			}
		}
	}
	public void withAmount()
	{
		System.out.println("Enter Account Number:");
		int account=sc.nextInt();
		for(int i=0;i<count;i++)
		{
			int temp1=Integer.parseInt(cust[1][i]);
			if(account==temp1)
			{
				System.out.println("Enter money to withdrawl:");
				int withdrawl=sc.nextInt();
				int temp=Integer.parseInt(cust[3][i]);
				try
				{
					if(temp < withdrawl)
						throw new ArithmeticException("\n\n\t\tInsufficient Balance\n");
					else
						balance=balance-withdrawl;
				}
				catch(ArithmeticException ae)
				{
					System.out.println(ae.getMessage());
				}
				String balan=Integer.toString(balance);
				cust[3][i]=balan;
			}
		}
	}
	public void displayCustomer()
	{
		String name="Customer Name";
		String accno="Account Number";
		String acctp="Account Type";
		String bal="Balance";
		System.out.println("\n\n\t\t\t\t\tCustomer Details");
		System.out.printf("\n%20s%20s%20s%20s\n",name,accno,acctp,bal);
		for(int j=0;j<count;j++)
		{
			for(int i=0;i<4;i++)
			{
				System.out.printf("%20s",cust[i][j]);
			}
			System.out.println();
		}
		System.out.println();
	}
}
public class Bank extends Customer
{
	public static void main(String[] args)
	{
		Scanner sc=new Scanner(System.in);
		Bank bn=new Bank(); 
		int x;
		do
		{
			System.out.println("\nPress 1: To add new customer");
			System.out.println("Press 2: To deposit amount");
			System.out.println("Press 3: To withdrawl amount after checking balance");
			System.out.println("Press 4: To display customer details");
			System.out.println("Press 5: To quit");
			System.out.println("\nEnter your option:\n");
			x=sc.nextInt();
			switch(x)
			{
				case 1:
				bn.addCustomer();
				break;
				case 2:
				bn.dipAmount();
				break;
				case 3:
				bn.withAmount();
				break;
				case 4:
				bn.displayCustomer();
				break;
				case 5:
				break;
				default:
				System.out.println("\nEnter a valid number\n");
			}
		}
		while(x!=5);
	}
}