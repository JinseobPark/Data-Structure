/****************************************************
\file   recursive_fill.c
\author Jinseob Park
\par    email: 0814owl@gmail.com
\brief	��ȯ ����� �˰����� ����Ͽ� ���� ä���.������ Ư���� ������ ä��� ����̴�. 
*****************************************************/
#include <stdio.h>
#define WHITE 0
#define BLACK 1
#define YELLOW 2
#define WIDTH 10
#degine HEIGHT 10

int screen[WIDTH][HEIGHT] = {  {2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
						{2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
						{2, 2, 2, 0, 0, 0, 0, 2, 2, 2},
						{2, 2, 2, 2, 0, 0, 0, 2, 2, 2},
						{2, 2, 2, 2, 0, 0, 0, 2, 2, 2},
						{2, 2, 2, 2, 0, 0, 0, 0, 2, 2},
						{2, 2, 2, 2, 0, 2, 2, 2, 2, 2},
						{2, 2, 2, 2, 0, 2, 2, 2, 2, 2},
						{2, 2, 2, 2, 0, 2, 2, 2, 2, 2},
						{2, 2, 2, 2, 2, 2, 2, 2, 2, 2}

};

void print_screen()
{
	int i, j;
	for (i = 0; i < 10; ++i)
	{
		for (j = 0; j < 10; ++j)
		{
			printf("%d ", screen[i][j]);
		}
		printf("\n");
	}
}
//
char read_pixel(int x, int y)
{
	return screen[x][y];
}
//
void write_pixel(int x, int y, int color)
{
	screen[x][y] = color;
}
// ���� ä��� �˰���
void flood_fill(int x, int y)
{
	if (read_pixel(x, y) == WHITE)
	{
		write_pixel(x, y, BLACK);
		//��ȯȣ��
		if(x < (WIDTH-1))
		flood_fill(x+1, y);
		if( x > 0)
		flood_fill(x-1, y);
		if( y < (HEIGHT -1))
		flood_fill(x, y+1);
		if( y > 0)
		flood_fill(x, y-1);
	}
}

int main(void)
{
	flood_fill(5, 4);
	print_screen();
	return 0;
}