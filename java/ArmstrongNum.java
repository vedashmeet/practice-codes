public class ArmstrongNum
{
	public static void main(String[] args)
	{
		int temp,result=0,temp1,counter=0,product=1,input_num,vari_input_num,div_store,store[];
		store=new int[10];
		input_num=7;								//Input
		vari_input_num=input_num;
		div_store=-1;
		while(div_store!=0)
		{
			store[counter]=vari_input_num % 10;
			div_store=vari_input_num / 10;
			vari_input_num=div_store;
			counter++;
		}
		temp1=counter;
		while(counter!=0)
		{
			temp=temp1;
			while(temp!=0)
			{
				product*=store[counter-1];
				temp--;
			}
			result+=product;
			product=1;			
			counter--;
		}
		if(input_num==result)
		{
			System.out.println("Armstrong Number of "+input_num+" is "+result);
		}
		else
		{
			System.out.println("Armstrong Number of "+input_num+" is not valid");
		}
	}
}