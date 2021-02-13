public class SumOfDigitOfNumbers
{
	public static void main(String[] args)
	{
		int temp,input_num,div_store=-1,result=0;
		input_num=1523;
		temp=input_num;
		while(div_store!=0)
		{
			result+=temp%10;
			div_store=temp/10;
			temp=div_store;
		}
		System.out.println("Sum of digits of "+input_num+" is "+result);
	}
}