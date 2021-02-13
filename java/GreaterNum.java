public class GreaterNum
{
	public static void main(String[] args)
	{
		int a=Integer.parseInt(args[0]);
		int b=Integer.parseInt(args[1]);
		int c=Integer.parseInt(args[2]);
		if(a<b)
		{
			if(c<b)
			{
				System.out.println(b+" is greater");
            }
            else
            {
            	System.out.println(c+" is greater");
            }
        }
        else
        {
        	System.out.println(a+" is greater");
        }
	}
}