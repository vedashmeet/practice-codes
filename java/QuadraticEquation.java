public class QuadraticEquation
{
	public static void main(String[] args)
	{
		double root,root1,root2;
		int D;
		int a=Integer.parseInt(args[0]);
		int b=Integer.parseInt(args[1]);
		int c=Integer.parseInt(args[2]);
		D=(b*b)-(4*a*c);
		if(D>0)
		{
			root1=(-b+(Math.sqrt(D)))/(2*a);
			root2=(-b-(Math.sqrt(D)))/(2*a);
			System.out.println("Two roots of "+a+"x^2+"+b+"y"+c+" are "+root1+" and "+root2);
		}
		else if(D==0)
		{
			root=-b/(2*a);
			System.out.println("The root of "+a+"x^2+"+b+"y"+c+" is "+root);
		}
		else
		{
			System.out.println("Not possible yet.");
		}
	}
}