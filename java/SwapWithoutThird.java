public class SwapWithoutThird
{
	public static void main(String[] args)
	{
		int num1,num2,number1,number2;
		num1=56;							//Input1
		num2=67;							//Input2
		number1=num1;
		number2=num2;
		num1=num1+num2;
		num2=-num2+num1;
		num1=num1-num2;
		System.out.println(number1+", after swappingis "+num1);
		System.out.println(number2+", after swappingis "+num2);
	}
}
