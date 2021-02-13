public class ASCIIvalueOfChar
{
	public static void main(String[] args)
	{
		int ASCII_code;
		char input_char;
		input_char='/';								//Input
		for(char counter_ASCII=0;counter_ASCII<=127;counter_ASCII++)
		{
			if(input_char==counter_ASCII)
			{
				ASCII_code=counter_ASCII;
				System.out.println("ASCII code of '"+input_char+"' character is "+ASCII_code);
				break;
			}
		}
	}
}