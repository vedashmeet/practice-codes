public class StringClass
{
	public static void main(String[] args)
	{
		String s1="hello ";
		String s2=new String("Hello");
		String s3=s1.toUpperCase();
		String s4=s3.toLowerCase();
		int com=s2.compareTo(s1);
		String s5=s1.concat(s2);
		//String s6=s1.toIgnoreCase(s2);//error
		int in=s1.indexOf('e');
		//int in=s1.indexOf('e',2);
		//int in=s1.indexOf("ll");
		//int in=s1.indexOf("ll",4);
		//int in=s1.lastIndexOf('e');
		//int in=s1.lastIndexOf('e',4);
		System.out.println(s1);
		System.out.println(s2);
		System.out.println(s3);
		System.out.println(s4);
		System.out.println(com);
		System.out.println(s5);
		System.out.println(s1.endsWith(" "));
		System.out.println(in);
		//System.out.println(s6);//error
		for(int i=0;i<s2.length();i++)
		{
			char c=s2.charAt(i);
			System.out.println(c);
		}
	}
}