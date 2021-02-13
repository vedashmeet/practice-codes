import java.util.Scanner;
public class SortingOfNumbers
{
	public static void main(String[] args)
	{
		int temp;
		int a[]=new int[4];
		String order;
		Scanner sc =new Scanner(System.in);
		for(int i=0;i<a.length;i++)
		{
			a[i]=sc.nextInt();
		}
		System.out.println("Enter 'a' for ascending order or 'd' for descending order,");
		order=sc.next();
		for(int i=0;i<a.length;i++)
		{
			for(int j=0;j<a.length-1;j++)
			{
				if(order=="a"||order=="A")
				{
					if(a[j]>a[j+1])
					{
						temp=a[j+1];
						a[j+1]=a[j];
						a[j]=temp;
					}
				}
				if(order=="d"||order=="D")
				{
					if(a[i]>a[j])
					{
						temp=a[j];
						a[j]=a[i];
						a[i]=temp;
					}
				}
			}
		}
		System.out.println("Sorting of number,");
		for(int i=0;i<a.length;i++)
		{
			System.out.println(a[i]);
		}
	}
}