public class ChristmasTree
{
	public static void main(String[] args)
	{
		int temp,counter_box,counter_row,counter_space,counter_star,no_of_lines_of_star,space,space_temp,star_add,stem,base;
		space=53;							//Input Space
		no_of_lines_of_star=5;				//Input Number of lines of star which is equals to number of block of lines of stars
		star_add=1;
		space_temp=space+3;
		temp=space_temp;
		for(counter_box=0; counter_box < no_of_lines_of_star; counter_box++)
		{
			for(counter_row=0; counter_row < no_of_lines_of_star; counter_row++)
			{
				for(counter_space=0; counter_space < space_temp-counter_row; counter_space++)
				{
					System.out.print(" ");
				}
				for(counter_star=0; counter_star < (counter_row*2)+star_add; counter_star++)
				{
					System.out.print("*");
				}
				System.out.println();
			}
			space_temp=space+2;
			space--;
			star_add+=2;
		}				
		//Stem and Base
		stem=temp;
		base=(no_of_lines_of_star*no_of_lines_of_star/3)+1;
		for(int counter_stem_temp=0; counter_stem_temp < 2; counter_stem_temp++)
		{
			for(int counter_stem=0; counter_stem < stem; counter_stem++)
			{
				System.out.print(" ");
			}
			System.out.println("*");
		}
		for(int counter_base_temp=0; counter_base_temp < stem-(base/2); counter_base_temp++)
		{
			System.out.print(" ");
		}
		for(int counter_base=0; counter_base < base; counter_base++)
		{
			System.out.print("*");
		}
	}
}