public class Rectangle
{
	public static void main(String[] args)
	{
		int length,width;
		length=20;										//Input Length
		width=20;										//Input Width
		for(int length_counter=0; length_counter < length; length_counter++)
		{
			System.out.print(" \t \t \t \t \t ");
			for(int width_counter=0; width_counter < width; width_counter++)
			{
				if(length_counter == 0 || length_counter == length-1)
				{
					System.out.print("* ");
				}
				else
				{
				if(width_counter == 0 || width_counter == width-1)
					{
						System.out.print("* ");
					}
					else
					{
						System.out.print("  ");
					}
				}
			}
			System.out.println();
		}
	}
}