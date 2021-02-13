public class Prime
{
	public static void main(String[] args)
	{
		int input_num;			
		input_num=7;								//Input
		if((input_num==2||input_num==3||input_num==5)||(input_num!=1&&input_num%2!=0&&input_num%3!=0&&input_num%5!=0))
		{
			System.out.println(input_num+" is a prime number");
		}
		else
		{
			System.out.println(input_num+" is not a prime number");
		}
	}
}	