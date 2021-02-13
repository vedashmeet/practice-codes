import java.io.*;
public class FileClass
{
	public static void main(String[] args)throws IOException
	{
		File f1=new File("D:/Java Programs/Filein.txt");
		f1.createNewFile();
		System.out.println("Can file read "+f1.canWrite());
		System.out.println("Is file exists "+f1.exists());
		System.out.println("File Name "+f1.getName());
		System.out.println("Length of file "+f1.length());
	}
}