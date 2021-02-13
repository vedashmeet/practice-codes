public class DivideByTwoAndFive
{
	public static void main(String[] args)
	{
		for(int counter=1;counter<=100;counter++)
		{
			if(counter%2==0 || counter%5==0)
			{
				System.out.println(counter);
			}
		}
	}
}