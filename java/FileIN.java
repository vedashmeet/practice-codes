import java.io.*;leIN
{
public class Fi
	public static void main(String[] args)throws IOException
	{
		int i;
		FileInputStream fin=new FileInputStream("./Fileop.txt");
		do
		{
			i=fin.read();
			if(i!=-1)
				System.out.println((char)i);
		}
		while(i!=-1);
		fin.close();
	}
}