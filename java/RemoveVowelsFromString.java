public class RemoveVowelsFromString
{
	public static void main(String[] word)
	{
		int counter,counter1,counter2,size_temp,counter3,size_temp_extra;
		System.out.println("String after removing vowels is: \n");
		for(counter=0;counter<word.length;counter++)
	    {
		   String temp1=String.valueOf(word[counter]);
		   char temp[]=temp1.toCharArray();
		   size_temp=temp.length;
		   size_temp_extra=temp.length;
		   counter1=0;
		   while(counter1<size_temp)
		   {
				if(temp[counter1]=='a'||temp[counter1]=='e'||temp[counter1]=='i'||temp[counter1]=='o'||temp[counter1]=='u'||temp[counter1]=='A'||temp[counter1]=='E'||temp[counter1]=='I'||temp[counter1]=='O'||temp[counter1]=='U')
				{
					for(counter2=counter1+1;counter2<size_temp;counter2++)
					{
					temp[counter2-1]=temp[counter2];
					}
					size_temp_extra--;
					counter1--;
				}
				counter1++;
			}
				for(counter3=0;counter3<size_temp_extra;counter3++)
			{
				System.out.print(temp[counter3]);
			}
			System.out.print(" ");
	    }
		System.out.println();	  
	}
}