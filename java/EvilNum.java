public class EvilNum
{
	public static void main(String[] args)
	{
		int decimal_number=Integer.parseInt(args[0]);
		int counter2=0,vari_input_num,div_store1=-1,store,counter=0,counter1,div_store,decimal,result_binary=0,binary_store[];
		binary_store=new int[10];
		decimal=decimal_number;
		while(decimal_number!=0)
		{
			div_store=decimal_number/2;
			binary_store[counter]=decimal_number%2;
			decimal_number=div_store;
			counter++;
		}
		while(counter!=0)
		{
			counter1=counter;
			while(counter1!=1)
			{
				binary_store[counter-1]*=10;
				counter1--;
			}
			result_binary+=binary_store[counter-1];
			counter--;
		}
		vari_input_num=result_binary;
		while(div_store1!=0)
		{
			store=vari_input_num % 10;
			div_store1=vari_input_num / 10;
			vari_input_num=div_store1;
			counter++;
			if(store==1)
			{
				counter2++;
			}
		}
		if(counter2%2==0)
		{
			System.out.println(decimal+" is an Evil Number");
		}
		else
		{
			System.out.println(decimal+" is not an Evil Number");
		}
	}
}