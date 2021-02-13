public class DecimalToBinary
{
	public static void main(String[] args)
	{
		int counter=0,counter1,div_store,decimal_number,decimal,result_binary=0,binary_store[];
		binary_store=new int[10];
		decimal_number=201;
		decimal=decimal_number;
		while(decimal_number!=0)
		{
			div_store=decimal_number/2;
			binary_store[counter]=decimal_number%2;
			decimal_number=div_store;
			counter++;
		}
		while(counter!=0)
		{
			counter1=counter;
			while(counter1!=1)
			{
				binary_store[counter-1]*=10;
				counter1--;
			}
			result_binary+=binary_store[counter-1];
			counter--;
		}
		System.out.println("Binary Conversion of "+decimal+" is "+result_binary);
	}
}