public class HarshadNum
{
	public static void main(String[] args)
	{
		int temp,div_store=-1,result=0;
		int input_num=Integer.parseInt(args[0]);
		temp=input_num;
		while(div_store!=0)
		{
			result+=temp%10;
			div_store=temp/10;
			temp=div_store;
		}
		if(input_num%result==0)
		{
			System.out.println(input_num+" is a Harshad Number");
		}
		else
		{
			System.out.println(input_num+" is not a Harshad Number");
		}
	}
}