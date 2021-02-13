import java.util.Scanner;
class Items
{
	Scanner sc=new Scanner(System.in);
	private final int m=50;
	private int item_code[]=new int[m];
	private int item_price[]=new int[m];
	private static int count;
	public Items()
	{
		count=0;
	}
	public void getItems()
	{
		System.out.println("Enter Item Code:");
		item_code[count]=sc.nextInt();
		System.out.println("Enter Item Cost:");
		item_price[count]=sc.nextInt();
		count++;
	}
	public void displaySum()
	{
		float sum=0f;
		for(int i=0;i<item_price.length;i++)
		{
			sum+=item_price[i];
		}
		System.out.println("Sum of Cost of all Items is "+sum);
	}
	public void removeItem()
	{
		System.out.println("Enter the Item Code which you want to remove");
		int a=sc.nextInt();
		for(int i=0;i<item_code.length;i++)
		{
			if(item_code[i]==a)
			{
				for(int j=i;j<count;j++)
				{
					item_code[j]=item_code[j+1];
					item_price[j]=item_price[j+1];
				}
				count--;
			}
		}
	}
	public void displayItems()
	{
		System.out.println("Item Code\t\tItem Cost");
		for(int i=0;i<count;i++)
		{
			System.out.println(item_code[i]+"\t\t"+item_price[i]);
		}
	}
}
public class Shopping extends Items
{
	public static void main(String[] args)
	{
		Scanner sc=new Scanner(System.in);
		Shopping s=new Shopping();
		int x;
		do
		{
			System.out.println("You can do the following option,\n\t Enter the appropriate number,");
			System.out.println("Press 1 to add an item.");
			System.out.println("Press 2 to display total values.");
			System.out.println("Press 3 to delete an item.");
			System.out.println("Press 4 to display all items.");
			System.out.println("Press 5 to quit.");
			x=sc.nextInt();
			switch(x)
			{
				case 1:
				s.getItems();
				break;
				case 2:
				s.displaySum();
				break;
				case 3:
				s.removeItem();
				break;
				case 4:
				s.displayItems();
				break;
				case 5:
				break;
				default:
				System.out.println("Enter a valid number");
			}
		}
		while(x!=5);
	}
}