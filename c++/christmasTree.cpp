#include<iostream>

using namespace std;
class ChristmasTree
{
	public	: void display();
};
inline void ChristmasTree :: display()
{
	int block = 7, space = block, star = 0;
	for(int countBlock = 1; countBlock <= block; countBlock++, star += 2, space--)
	{
		for(int countLines = 1; countLines <= block; countLines++)
		{
			for(int countSpace = 1; countSpace <= (space - 1)+(block - countLines); countSpace++)
				cout<< " ";
			for(int countStar = 1; countStar <= 2 * countLines + star - 1; countStar++)
				cout<< "*";
			cout<< endl;
		}
	}
	for(int count = 1; count <= 3; count++)
	{
		for(int countSp = 1; countSp <= 2 * block - 3; countSp++)
			cout<< " ";
		if(count < 3)
			cout<< "|||";
		else
			cout<<"===";
		cout<<endl;
	}
}
int main()
{
	ChristmasTree ct;
	ct.display();
	return 0;
}
