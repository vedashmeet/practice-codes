public class ElectricityCharges
{
	public static void main(String[] args)
	{
		String name=args[0];
		int quantity=Integer.parseInt(args[1]);
		float rupee,charges=0f;
		if(quantity<=84)
		{
			System.out.println("Entered number of units is below the range");
		}
		else
		{
			if(quantity<=100)
			{
				rupee=quantity*0.6f;
			}
			else if(quantity<=200)
			{
				rupee=quantity*0.8f;
			}
			else
			{
				rupee=quantity*0.9f;
			}
			if(rupee<=300)
			{
				charges=rupee;
			}
			else
			{
				charges=((15*rupee)/100)+rupee;
			}
			System.out.println("The electricity bill charges of "+name+" is Rs. "+charges);
		}
	}
}