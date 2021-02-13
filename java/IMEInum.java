public class IMEInum
{
	public static void main(String[] args)
	{
		int counter=0,result=0;
		long temp,div_store=-1;
		long input_num=Long.parseLong(args[0]);
		temp=input_num;
		while(div_store!=0)
		{
			result+=temp%10;
			div_store=temp/10;
			temp=div_store;
			counter++;
		}
		if(counter==15)
		{
			if(result%10==0)
			{
				System.out.println(input_num+" is an IMEI Number");
			}
			else
			{
				System.out.println(input_num+" is not an IMEI Number");
			}
		}
		else
		{
			System.out.println("\nPlease enter 15 digit number without any space");
			System.out.println("Because IMEI number is 15 digit number.");
		}
	}
}