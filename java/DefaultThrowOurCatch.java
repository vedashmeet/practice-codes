public class DefaultThrowOurCatch
{
	public static void main(String[] args)
	{
		try
		{
			System.out.println("Arithmetic Exception"+4/0);
		}
		catch(ArithmeticException e)
		{
			System.out.println("Exception: "+e.getMessage());
		}
		finally
		{
			System.out.println("DefaultThrowOurCatch");
		}
	}
}