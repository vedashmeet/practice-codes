public class InitialisationBlock
{
	//Instance Initialisation block
	private int x;
	{
		System.out.println("Initialisation of x = "+x);
		x=5;
	}
	public InitialisationBlock()
	{
		System.out.println("Constructor of x = "+x);
		System.out.println("Constructor of y = "+y);
	}
	//Static Initialisation Block
	private static int y;
	static
	{
		System.out.println("Initialisation of y = "+y);
		y=5;
	}
	public static void staticInitialisation()
	{
		System.out.println("Static Initialisation of y = "+y);
	}
	public static void main(String[] args)
	{
		InitialisationBlock IB=new InitialisationBlock();		//for constructor
		InitialisationBlock.staticInitialisation();				//for static methods
	}
}