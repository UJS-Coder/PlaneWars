#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h> 

int main()
{
	int isFire = 0;	//是否发射了子弹 
	int isKilled = 0;	//是否击中了目标 

	//竖直方向是x轴，水平方向是y轴，向右向下为正 
	int x = 5, y = 10;	//（x, y）是飞机最左边一个点的坐标 
	int nx = 0, ny = 5; // 一个靶子，放在第一行，ny列上

	srand((unsigned)time(NULL));

	int i, j;

	while (1)
	{
		system("cls");	//清屏
		if (isKilled) 	//如果目标被命中 
		{
			//随机生成一个新目标 
			nx = (rand() % 6);//[0, 5] 
			ny = (rand() % 9) + 2;//[2, 10] 
			//将新目标标记为未被击中 
			isKilled = 0;
		}
		if (!isKilled)
		{
			//输出目标 
			for (j = 0; j < nx; j++)
				printf("\n");
			for (j = 0; j < ny; j++)
				printf(" ");
			printf("+\n");
		}

		if (isFire == 0)	//输出飞机上面的空行
		{
			for (i = 0; i < x - nx; i++)
				printf("\n");
		}
		else   // 输出飞机上面的激光竖线
		{
			for (i = 0; i < x - nx; i++)
			{
				for (j = 0; j < y; j++)
					printf(" ");
				printf("  |\n");
			}
			//飞机头与目标在一条线上 
			if (y + 2 == ny)
				isKilled = 1;	//击中目标
			isFire = 0;
		}

		//下面输出一个飞机图案
		for (j = 0; j < y; j++)
			printf(" ");
		printf("  *\n");
		for (j = 0; j < y; j++)
			printf(" ");
		printf("*****\n");
		for (j = 0; j < y; j++)
			printf(" ");
		printf(" * * \n");


		if (kbhit())	//判断是否有输入
		{
			char input = getch();	//根据用户的不同输入来移动，不必输入回车
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
				isFire = 1;
			}
		}
	}
	return 0;
}
