#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
using namespace std;
int main()
{
	bool isFire = false; //是否发射了子弹
	bool isKilled = false; //是否击中了目标
	//竖直方向是x轴，水平方向是y轴，向右向下为正
	int x = 5, y = 10; //（x, y）是飞机最左边一个点的坐标
	int nx = 0, ny = 5; //（x, y）是目标的坐标
	srand((unsigned)time(NULL));
	while (true) {
		system("cls"); //清屏
		if (isKilled) //如果目标被命中
		{
			//随机生成一个新目标
			nx = (rand() % 6);//[0, 5]
			ny = (rand() % 9) + 2;//[2, 10]
			//将新目标标记为未被击中
			isKilled = false;
		}
		if (!isKilled)
		{
			//输出目标
			for (int i = 0; i < nx; i++)
				cout << endl;
			for (int i = 0; i < ny; i++)
				cout << " ";
			cout << "+" << endl;
		}
		if (isFire == false) //输出飞机上面的空行
		{
			for (int i = 0; i < x - nx; i++)
				cout << endl;
		}
		else //输出飞机上面的激光竖线
		{
			for (int i = 0; i < x - nx; i++)
			{
				for (int j = 0; j < y; j++)
					cout << " ";
				cout << "  |" << endl;
			}
			//飞机头与目标在一条线上
			if (y + 2 == ny)
				isKilled = true; //击中目标
			isFire = false;
		}
		//下面输出一个飞机图案
		for (int i = 0; i < y; i++)
			cout << " ";
		cout << "  *" << endl;
		for (int i = 0; i < y; i++)
			cout << " ";
		cout << "*****" << endl;
		for (int i = 0; i < y; i++)
			cout << " ";
		cout << " * * " << endl;
		if (kbhit()) //判断是否有输入
		{
			char input = getch(); //根据用户的不同输入来移动，不必输入回车
			switch (input) {
			case 'a':
			case 'A':
				y--;
				break;
			case 'd':
			case 'D':
				y++;
				break;
			case 'w':
			case 'W':
				x--;
				break;
			case 's':
			case 'S':
				x++;
				break;
			case ' ':
				isFire = true;
			}
		}
	}
	return 0;
}
