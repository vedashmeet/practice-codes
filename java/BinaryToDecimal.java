public class BinaryToDecimal
{
	public static void main(String[] args)
	{
		int product=1,power=0,decimal=0;
		long temp,binary_temp,div_store=-1l;
		long binary=Long.parseLong(args[0]);
		binary_temp=binary;
		while(div_store!=0)
		{
			temp=binary_temp%10;
			div_store=binary_temp/10;
			while(power!=0)
			{
				product*=2;
				power--;
			}
			decimal+=product*temp;
			power++;
			binary_temp=div_store;
		}
		System.out.println("Decimal Conversion of "+binary+" is "+decimal);
	}
}