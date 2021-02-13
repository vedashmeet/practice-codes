public class Factorial
{
	public static void main(String[] args)
	{
		int input_number;
		long result=1L;	
		input_number=0;												//Input
		if(input_number!=0)
		{
			for(int counter=1;counter<=input_number;counter++)
			{
				result*=counter;
			}
		}
		System.out.println("Factorial of "+input_number+" is "+result);
	}
}