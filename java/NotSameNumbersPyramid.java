public class NotSameNumbersPyramid
{
	public static void main(String[] args)
	{
		int counter_row,counter_star,counter_space,no_of_lines,vari=1;
		no_of_lines=15;							//Input
		for(counter_row=0; counter_row < no_of_lines; counter_row++)
		{
			for(counter_space=0; counter_space < no_of_lines-counter_row; counter_space++)
			{
				for(int temp=0;temp<4;temp++)
					System.out.print(" ");
			}
			for(counter_star=0; counter_star < (2*counter_row)+1; counter_star++)
			{
				System.out.printf("%4d",vari);
				vari++;
			}
			System.out.println();
		}
	} 
}