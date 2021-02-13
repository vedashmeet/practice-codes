public class PronicNum
{
	public static void main(String[] args)
	{
		double root,D;
		double c=Double.parseDouble(args[0]);
		D=1-(4*(-c));
		root=(-1+(Math.sqrt(D)))/2;
		if((root*(root+1))==c)
		{
			System.out.println(c+" is a Pronic Number");
		}
		else
		{
			System.out.println(c+" is not a Pronic Number");
		}
	}
}