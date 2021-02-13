import java.io.*;
public class FileOP
{
	public static void main(String[] args)throws IOException
	{
		int i;
		FileOutputStream fout=new FileOutputStream("./Fileop.txt",true);
		String s="asdfg";
		char ch[]=s.toCharArray();
		for(i=0;i<s.length();i++)
			fout.write(ch[i]);
		//fout.close();
	}
}