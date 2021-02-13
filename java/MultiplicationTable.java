public class MultiplicationTable
{
	public static void main(String[] args)
	{
		int table;										//Store Multiplication Result
		for(int multiplicant_counter=1;multiplicant_counter<=10;multiplicant_counter++)
		{
			System.out.println();
			System.out.println("Multiplication Table of "+multiplicant_counter+" is,");
			for(int multiplier_counter=1;multiplier_counter<=10;multiplier_counter++)
			{
				table=multiplicant_counter*multiplier_counter;
				System.out.format("%5d     +  %5d     =  %5d\n",multiplicant_counter,multiplier_counter,table);
			}
			System.out.println();
		}
	}
}