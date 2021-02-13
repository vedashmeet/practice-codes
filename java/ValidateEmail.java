import java.util.Scanner;
public class ValidateEmail
{
	public static int at,counts=0;
	public static void main(String[] args)
	{
		Scanner sc=new Scanner(System.in);
		do
		{
			System.out.println("\nPlease enter Valid Email Id\n\n");
			String email_ids=sc.nextLine();
			char email_ida[]=email_ids.toCharArray();
			int length=email_ida.length;
			int count=0;
			for(int at_counter=0;at_counter<length;at_counter++)
			{
				if(email_ida[at_counter]==32)
				{
					System.out.println("\nSpace is removed by default, so");
					for(int temp=at_counter;temp<length;temp++)
					{
						email_ida[temp-1]=email_ida[temp];
					}
					length--;
				}
				if(email_ida[at_counter]=='@')
				{
					at=at_counter;
					count++;
					break;
				}
			}
			if(count!=1)
			{
				counts++;
				System.out.println("  !  Check the invalid entering of '@'");
			}
			else 
			{
				if(at<10||at>30)
				{
					counts++;
					System.out.println("Please enter your email name between 10 to 30 characters");
				}
				else
				{
					for(int counter=0;counter<at;counter++)
					{
						if(counter==0)
						{
							if((email_ida[0]>=0)&&(email_ida[0]<97)||(email_ida[0]>=123)&&(email_ida[0]<128))
							{
								counts++;
								System.out.println("  !  First character of email id should be lowercase alphabet '"+email_ida[0]+"'");
							}
						}
						else if((email_ida[counter]>=65)&&(email_ida[counter]<91))
						{
							counts++;
							System.out.println("  !  Email Id should not have uppercase alphabets '"+email_ida[counter]+"'");
						}
						if((email_ida[counter]>=0)&&(email_ida[counter]<32)||(email_ida[counter]>=33)&&(email_ida[counter]<48)||(email_ida[counter]>=58)&&(email_ida[counter]<64)||(email_ida[counter]>=91)&&(email_ida[counter]<97)||(email_ida[counter]>=123)&&(email_ida[counter]<128))
						{
							counts++;
							System.out.println("  !  Email Id should not have special characters '"+email_ida[counter]+"'");
						}
					}
					if(email_ida[length-1]=='m')
					{
						if((email_ida[length-4]!='.')||(email_ida[length-3]!='c')||(email_ida[length-2]!='o'))
						{
							counts++;
							System.out.println("Invalid email address");
						}
					}
					if(email_ida[length-1]=='n')
					{
						if((email_ida[length-3]!='.')||(email_ida[length-2]!='i'))
						{
							counts++;
							System.out.println("Invalid email address");
						}
					}
				}
			}
			if(counts==0)
			{
				System.out.println("\nYour Email id is submitted");
			}
		}
		while(counts!=0);
	}
}