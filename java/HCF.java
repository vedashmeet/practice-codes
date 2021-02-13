public class HCF
{
	public static void main(String[] args)
	{
		int check_counter,prime,num1,num2,result=1,number1,number2;
		num1=52;num2=102;								//Input Two Numbers
		number1=num1;
		number2=num2;
		out:
		for(check_counter=2;check_counter<100;check_counter++)
		{
			if((check_counter==2||check_counter==3||check_counter==5||check_counter==7)||(check_counter%2!=0&&check_counter%3!=0&&check_counter%5!=0&&check_counter%7!=0))
			{
				prime=check_counter;
				while((num1!=1)||(num2!=1))
				{
					if(num1%prime==0&&num2%prime==0)
					{
						num1=num1/prime;
						num2=num2/prime;
						result*=prime;
					}
					else
					{
						continue out;
					}
					}
				break;
			}
		}
		System.out.println("HCF of "+number1+" and "+number2+" is "+result);
	}
}
