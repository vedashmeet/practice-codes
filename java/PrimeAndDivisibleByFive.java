public class PrimeAndDivisibleByFive
{
	public static void main(String[] args)
	{	
		for(int input_num=1;input_num<=100;input_num++)
		{
			if((input_num==2||input_num==3||input_num==5||input_num%5==0)||(input_num!=1&&input_num%2!=0&&input_num%3!=0&&input_num%5!=0))
			{
				System.out.println(input_num);
			}
		}
	}
}	