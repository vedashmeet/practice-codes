public class StarPatternUsingTwoDimensionArray
{
	public static void main(String[] args)
	{
		int m=5;
		char a[][]=new char [5][m];
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<i;j++)
			{
				a[i][j]='*';
			}
		}
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<m;j++)
			{
				System.out.print(a[i][j]);
			}
			System.out.println();
		}
	}
}