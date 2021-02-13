public class EmripNum
{
	public static void main(String[] args)
	{
		int input_num=Integer.parseInt(args[0]);
		if((input_num==2||input_num==3||input_num==5||input_num==7)||(input_num!=1&&input_num%2!=0&&input_num%3!=0&&input_num%5!=0&&input_num%7!=0))
		{
			int temp=0,temp1,result=0,counter=0,counter1,product=1,vari_input_num,div_store,store[];
			store=new int[10];
			div_store=-1;
			vari_input_num=input_num;
			while(div_store!=0)
			{
				store[counter]=vari_input_num % 10;
				div_store=vari_input_num / 10;
				vari_input_num=div_store;
				counter++;
			}
			temp1=counter;
			while(temp!=temp1)
			{
				counter1=counter;
				while(counter1!=1)
				{
					product*=10;
					counter1--;
				}
				result+=store[temp]*product;
				product=1;
				counter--;
				temp++;
			}
			if((result==2||result==3||result==5||result==7)||(result!=1&&result%2!=0&&result%3!=0&&result%5!=0&&result%7!=0))
			{
				System.out.println(input_num+" is an Emrip number");
			}
			else
			{
				System.out.println(input_num+" is not an Emrip number");
			}
		}
		else
		{
			System.out.println(input_num+" is not an Emrip number");
		}
	}
}