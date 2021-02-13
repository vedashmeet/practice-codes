public class KaprekarNum
{
	public static void main(String[] args)
	{
		int vari_input_num,temp,div_store=-1,temp1,counter=0,product=1,num1,num2,result;
		int input_num=Integer.parseInt(args[0]);
		vari_input_num=input_num;
		vari_input_num*=vari_input_num;
		temp=vari_input_num;
		while(div_store!=0)
		{
			temp1=vari_input_num % 10;
			div_store=vari_input_num / 10;
			vari_input_num=div_store;
			counter++;
		}
		if(counter%2==0)
			counter=counter/2;
		else
			counter=(counter/2)+1;
		while(counter!=0)
		{
			product*=10;
			counter--;
		}
		num1=temp/product;
		num2=temp%product;
		result=num1+num2;
		if(input_num==result)
			System.out.println(input_num+" is a Kaprekar Number");
		else
			System.out.println(input_num+" is not a Kaprekar Number");
	}
}