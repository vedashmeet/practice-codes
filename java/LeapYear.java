public class LeapYear
{
	public static void main(String[] args)
	{
		int input_year;
		input_year=1700;		//Input
		if(input_year%100==0)
		{
			if(input_year%400==0)
			{
				System.out.println(input_year+" is a leap year");
			}
			else
			{
				System.out.println(input_year+" is not a leap year");
			}
		}
		else if(input_year%4==0)
		{
			System.out.println(input_year+" is a leap year");
		}
		else
		{
			System.out.println(input_year+" is not a leap year");
		}
	}
}