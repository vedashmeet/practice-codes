public class SameNumbersPyramid
{
	public static void main(String[] args)
	{
		int counter_row,counter_coloumn,counter_space,no_of_lines;
		no_of_lines=20;
		for(counter_row=0; counter_row < no_of_lines; counter_row++)
		{
			for(counter_space=0; counter_space < no_of_lines-counter_row; counter_space++)
			{
				for(int temp=0;temp<4;temp++)
					System.out.print(" ");
			}
			for(counter_coloumn=0; counter_coloumn < (2*counter_row)+1; counter_coloumn++)
			{
				System.out.printf("%4d",counter_row+1);
			}
			System.out.println();
		}
	} 
}