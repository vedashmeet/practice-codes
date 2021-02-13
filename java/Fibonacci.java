public class Fibonacci
{
	public static void main(String [] args)
	{
		int counter,num1,num2,result,input_series;
		input_series=10;								//Input
		for(num1=0,num2=1,counter=0;counter<input_series;counter++)
		{
			result=num1+num2;
			System.out.println(num1+" + "+num2+" = "+result);
			num1=num2;
			num2=result;
		}
	}
}