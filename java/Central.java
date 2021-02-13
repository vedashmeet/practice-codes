import java.util.Scanner;
class Admin
{
	public static String luser[]=new String[50];
	public static String lpsw[]=new String[50];
	public static int length=Admin.luser.length;
	Scanner sc=new Scanner(System.in);
	private String am_log_in="admin";
	private String am_password="admin123";
	private static int count;
	public Admin()
	{
		count=0;
	}
	public void adminLogIn()
	{
		System.out.println("Enter the UserName:");
		String name=sc.next();
		System.out.println("Enter the Password:");
		String psw=sc.next();
		if((name.equals(am_log_in)) && (psw.equals(am_password)))
		{
			adminSwitch();
		}
		else
		{
			System.out.println("Enter valid UserName and Password");
			adminLogIn();
		}
	}
	public void adminSwitch()
	{
		Central ct=new Central();
		int x;
		System.out.println("Press 1:To add Librarian");
		System.out.println("Press 2:To view Librarian");
		System.out.println("Press 3:To delete Librarian");
		System.out.println("Press 4:To Log Out");
		x=sc.nextInt();
		switch(x)
		{
			case 1:
			addLibrarian();
			break;
			case 2:
			viewLibrarian();
			break;
			case 3:
			deleteLibrarian();
			break;
			case 4:
			ct.logOut();
			break;
			default:
			System.out.println("Enter a valid option");
		}
	}
	public void addLibrarian()
	{
		System.out.println("Enter UserName of Librarian:");
		luser[count]=sc.next();
		System.out.println("Enter Password of Librarian:");
		lpsw[count]=sc.next();
		count++;
		adminSwitch();
	}
	public void viewLibrarian()
	{
		for(int i=0;i<count;i++)
		{
			System.out.println(luser[i]+"\t"+lpsw[i]);
		}
		adminSwitch();
	}
	public void deleteLibrarian()
	{
		int k=0;
		System.out.println("Enter the UserName which you want "); 
		String uname=sc.next();
		for(int i=0;i<count;i++)
		{
			if(uname.equals(luser[i]))
			{
				for(int j=i;j<=count;j++)
				{
					luser[j]=luser[j+1];
					lpsw[j]=lpsw[j+1];
				}
				count--;
			}
			else
			{
				 k++;
			}
		}
		if(k==count)
			System.out.println("Enter valid UserName");
		adminSwitch();
	}
}
class Librarian
{
	Scanner sc=new Scanner(System.in);
	private static int count;
	private static int counter;
	private String book[][]=new String[3][50];
	private String issue[][]=new String[4][50];
	public Librarian()
	{
		counter=0;
		count=0;
	}
	public void librarianLogIn()
	{
		int k=0;
		System.out.println("Enter the UserName:");
		String name=sc.next();
		System.out.println("Enter the Password:");
		String psw=sc.next();
		for(int i=0;i<Admin.length;i++)
		{
			if((Admin.luser[i].equals(name)) && (Admin.lpsw[i].equals(psw)))
			{
				librarySwitch();
			}
			else
			{
				k++;
			}
		}
		if(k==Admin.length)
		{
			System.out.println("Enter valid UserName and Password");
			librarianLogIn();
		}
	}
	public void librarySwitch()
	{
		Central ct=new Central();
		int x;
		System.out.println("Press 1:To add new Books");
		System.out.println("Press 2:To view Books");
		System.out.println("Press 3:To issue Books");
		System.out.println("Press 4:To view issued Books");
		System.out.println("Press 5:To Log Out");
		x=sc.nextInt();
		switch(x)
		{
			case 1:
			addBooks();
			break;
			case 2:
			viewBooks();
			break;
			case 3:
			issueBooks();
			break;
			case 4:
			viewIssuedBooks();
			break;
			case 5:
			ct.logOut();
			break;
			default:
			System.out.println("Enter a valid option");
		}
	}
	public void addBooks()
	{
		int i=0;
		System.out.println("Enter Name of Book:");
		book[i][count]=sc.next();
		i++; 
		System.out.println("Enter Author of Book:");
		book[i][count]=sc.next();
		i++;
		System.out.println("Enter Code of Book:");
		book[i][count]=sc.next();
		count++;
		librarySwitch();
	}
	public void viewBooks()
	{
		for(int j=0;j<count;j++)
		{
			for(int i=0;i<3;i++)
			{
				System.out.print(book[i][j]+"\t");
			}
		}
		System.out.println();
		librarySwitch();
	}
	public void issueBooks()
	{
		int k=0;
		System.out.println("Enter the code of book which you want to issue");
		String code=sc.next();
		for(int i=0;i<count;i++)
		{
			if(code.equals(book[2][i]))
			{
				int j=0;
				System.out.println("Enter Name of Student who issue book which you entered code:");
				issue[j][counter]=sc.next();
				j++;
				System.out.println("Enter RollNo of Student:");
				issue[j][counter]=sc.next();
				j++;
				issue[j][counter]=book[0][i];
				j++;
				issue[j][counter]=book[2][i];
				counter++;
			}
			else
				k++;
		}
		if(k==count)
		{
			System.out.println("Enter valid code");
			issueBooks();
		}
		librarySwitch();
	}
	public void viewIssuedBooks()
	{
		for(int j=0;j<counter;j++)
		{
			for(int i=0;i<4;i++)
			{
				System.out.print(issue[i][j]+"\t");
			}
		}
		System.out.println();
		librarySwitch();
	}
}
public class Central
{
	Scanner sc=new Scanner(System.in);
	public void logOut()
	{
		Admin am=new Admin();
		Librarian lb=new Librarian();
		int x;
		System.out.println("Press 1: To log in as Admin");
		System.out.println("Press 2: To log in as Librarian");
		System.out.println("Press 3: To quit");
		x=sc.nextInt();
		switch(x)
		{
			case 1:
			am.adminLogIn();
			break;
			case 2:
			lb.librarianLogIn();
			break;
			case 3:
			break;
			default:
			System.out.println("Enter valid option");
		}
	}
	public static void main(String[] args)
	{
		Central ct=new Central();
		ct.logOut();
	}
}
