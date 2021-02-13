public class TransferValueFromTypeToReference
{
	public static void main(String[] args)
	{
		Integer i1=Integer.valueOf("1223");
		int a=Integer.valueOf("1332");
		Integer i2=Integer.valueOf("14",8); 			//valueOf("Number Of which base",base)
		System.out.println(a);
		System.out.println(i1);
		System.out.println(i2);
	}
}