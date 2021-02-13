public class DecimalToBinaryWithoutArray
{
	public static void main(String[] args)
	{
		int div_store=-1,decimal_number,decimal,binary,binary_store=0,product=1;
		decimal_number=29;
		decimal=decimal_number;
		while(div_store!=0)
		{
			div_store=decimal_number/2;
			binary=decimal_number%2;
			binary*=product;
			binary_store+=binary;
			decimal_number=div_store;
			product*=10;
		}
		System.out.println("Binary Conversion of "+decimal+" is "+binary_store);
	}
}