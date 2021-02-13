import java.util.Scanner;
public class SwappingOfTwoDimensionArray
{
	public static void main(String[] args)
	{
		Scanner sc=new Scanner(System.in);
		int m=3;
		int a[][]=new int [3][m];
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<m;j++)
			{
				a[i][j]=sc.nextInt();
			}
		}
		for(int i=m-1;i>=0;i--)
		{
			for(int j=0;j<m;j++)
			{
				if(i!=0)
					a[i][j]=a[i-1][j];
				if(i==0)
					a[i][j]=a[m-1][j];
			}
		}
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<m;j++)
			{
				System.out.println(a[i][j]);
			}
		}
	}
}