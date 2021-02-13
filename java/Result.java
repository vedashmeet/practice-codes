import java.util.Scanner;
class Student
{
	Scanner sc=new Scanner(System.in);
	private final int mm=360;
	private int sum;
	private float per;
	private String sd[][]=new String[10][50];
	private static int count;
	public Student()
	{
		count=0;
	}
	public void addStudent()
	{
		int j=0;
		System.out.println("Enter Name:");
		sd[j][count]=sc.next();
		j++;
		System.out.println("Enter Roll Number:");
		sd[j][count]=sc.next();
		j++;
		System.out.println("Enter Class:");
		sd[j][count]=sc.next();
		j++;
		while(j<9)
		{
			sd[j][count]="0";
			j++;
		}
		count++;
		System.out.println("\nStudent details is entered\n");
	}
	public void addMarks()
	{
		System.out.println("Enter Roll Number");
		String roll_no=sc.next();
		for(int i=0;i<50;i++)
		{
			if(roll_no.equals(sd[1][i]))
			{
				int d=3;
				System.out.println("Enter marks for C++:");
				sd[d][i]=sc.next();
				d++;
				System.out.println("Enter marks for C:");
				sd[d][i]=sc.next();
				d++;
				System.out.println("Enter marks for .net:");
				sd[d][i]=sc.next();
				d++;
				System.out.println("Enter marks for Java:");
				sd[d][i]=sc.next();
				d++;
				System.out.println("Enter marks for php:");
				sd[d][i]=sc.next();
				d++;
				System.out.println("Enter marks for JavaScript:");
				sd[d][i]=sc.next();
			}
		}
		System.out.println("\n\nStudent Marks is entered\n");
	}
	public void percentage(int j)
	{
		for( int i=3;i<9;i++)
		{
			int marks=Integer.parseInt(sd[i][j]);
			sum+=marks;
		}
		per=(sum*100)/360;
		String percent=Float.toString(per);
		sd[9][j]=percent;
	}
	public void displayStudent()
	{
		String name="Name";
		String roll_no="Roll Number";
		String cls="Branch";
		String MICpp="Marks In C++";
		String MIC="Marks In C";
		String MID="Marks In .net";
		String MIJ="Marks In Java";
		String MIP="Marks In PHP";
		String MIJS="Marks In JavaScript";
		String per="Percentage";
		System.out.println("\n\t\t\t\t\t\t\t\t\t\t\tStudent's Marks Details");
		System.out.printf("\n%21s%21s%21s%21s%21s%21s%21s%21s%21s%21s\n",name,roll_no,cls,MICpp,MIC,MID,MIJ,MIP,MIJS,per);
		for(int j=0;j<count;j++)
		{	
			percentage(j);
			for(int i=0;i<10;i++)
			{
				System.out.printf("%21s",sd[i][j]);
			}
		}
		System.out.println();
	}
}
public class Result extends Student
{
	public static void main(String[] args)
	{
		Result rs=new Result();
		Scanner sc=new Scanner(System.in);
		int x;
		do
		{
		System.out.println("\n1 :to add new student details");
		System.out.println("2 :to add student marks");
		System.out.println("3 :to display students according to grade");
		System.out.println("4 :quit");
		System.out.println("\nEnter your option:");
		x=sc.nextInt();
		switch(x)
		{
			case 1:
			rs.addStudent();
			break;
			case 2:
			rs.addMarks();
			break;
			case 3:
			rs.displayStudent();
			break;
			case 4:
			break;
			default:
			System.out.println("\nEnter a valid number");
		}
		}
		while(x!=4);
	}
}