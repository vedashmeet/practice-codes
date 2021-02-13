public class OurThrowDefaultCatch
{
	public static void main(String[] args)
	{
		int balance=5000;
		int withdraw=6000;
		if(balance<withdraw)
			throw new ArithmeticException("Insufficient Balance");
	}
}