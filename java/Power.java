public class Power
{
	public static void main(String[] args)
	{
		int input_num,input_power,vari_input_power,result=1;
		input_num=25;									//Input Number
		input_power=3;									//Input Power
		vari_input_power=input_power;
		while(vari_input_power!=0)
		{
			result*=input_num;
			vari_input_power--;
		}
		System.out.println("Result of "+input_num+" raise to power "+input_power+" is "+result);
	}	
}