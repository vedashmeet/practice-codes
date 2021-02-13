public class OurThrowOurCatch
{
	public static void main(String[] args)
	{
		int balance=5000;
		int withdraw=6000;
		try
		{
			if(balance<withdraw)
				throw new ArithmeticException("Insufficient Balance");
		}
		catch(ArithmeticException e)
		{
			System.out.println("Exception: "+e.getMessage());
		}
		finally
		{
			System.out.println("OurThrowOurCatch");
		}
	}
}