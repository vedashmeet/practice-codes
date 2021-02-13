import java.util.Scanner;
public class OneDimensionArray
{
	public static void main(String[] args)
	{
		int result=0;
		int arr[]=new int[5];
		Scanner sc=new Scanner(System.in);
		for(int i=0;i<arr.length;i++)
		{
			arr[i]=sc.nextInt();
			result+=arr[i];
		}
		for(int i=0;i<arr.length;i++)
			System.out.print(arr[i]+"    ");
		System.out.println(result);
	}
}