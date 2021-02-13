import java.util.Scanner;
class Example
{
	Scanner sc=new Scanner(System.in);
	private char num[]={'1','2','3','4','5','6','7','8','9'};
	private String play="0";
	private char place='0';
	private static int count;
	private static int counter;
	private char win;
	private static int cou;
	public Example()
	{
		cou=0;
		count=0;
		counter=1;
	}
	public void displayTicTacToe()
	{
		System.out.println(" -------------\n | "+num[6]+" | "+num[7]+" | "+num[8]+" |\n -------------\n | "+num[3]+" | "+num[4]+" | "+num[5]+" |\n -------------\n | "+num[0]+" | "+num[1]+" | "+num[2]+" |\n -------------");
		count++;
	}	
	public void inputNumber()
	{
		do
		{
		if(counter>9)
		{
			System.out.println("Match is draw");
			cou++;
			break;
		}
		if(count%2==0)
		{
			play="2nd";
			place='O';
		}
		else
		{
			play="1st";
			place='X';
		}
		System.out.println(play+" Player Enter number where you want to "+place+":");
		int in=sc.nextInt();
		if((in>0)&&(in<10))
		{
			if(((num[in-1])!='X')&&((num[in-1])!='O'))
			{
				for(int i=0;i<9;i++)
				{
					if(in-1==i)
					{
						if(play=="1st")
							num[i]='X';
						if(play=="2nd")
							num[i]='O';
						win=num[i];
						displayTicTacToe();
						counter++;
					}
				}
			}
			else
			{
				System.out.println("Already Exist\nInput again");
				inputNumber();
			}
		}
		else
		{
			System.out.println("Invalid option\nInput again");
			inputNumber();
		}
		}
		while(((num[0]!=num[1])||(num[1]!=num[2]))&&((num[3]!=num[4])||(num[4]!=num[5]))&&((num[6]!=num[7])||(num[7]!=num[8]))&&((num[0]!=num[3])||(num[3]!=num[6]))&&((num[1]!=num[4])||(num[4]!=num[7]))&&((num[2]!=num[5])||(num[5]!=num[8]))&&((num[0]!=num[4])||(num[4]!=num[8]))&&((num[2]!=num[4])||(num[4]!=num[6])));
		if(cou==0)
		{
			if(win=='X')
				System.out.println("1st player is winner");
			if(win=='O')
				System.out.println("2nd player is winner");
		}
	}
}
public class TicTacToe extends Example
{
	public static void main(String[] args)
	{
		Scanner sc=new Scanner(System.in);
		Example em=new Example();
		System.out.println("Enter the name Of first Player:");
		String player1=sc.next();
		System.out.println("Enter the name Of second Player:");
		String player2=sc.next();
		em.displayTicTacToe();
		em.inputNumber();
	}
}