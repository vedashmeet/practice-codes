import java.io.*;
public class FileBufferedW
{
	public static void main(String[] args)throws IOException
	{
		BufferedWriter bf=new BufferedWriter(new FileWriter("./FileBufW.txt",true));
		bf.write("Computer");
		bf.close();
	}
}