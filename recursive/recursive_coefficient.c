/****************************************************
\file   recursive_coefficient.c
\author Jinseob Park
\par    email: 0814owl@gmail.com
\brief	recursive를 활용한 이항계수 계산법
*****************************************************/
#include <stdio.h>
int coefficient(int n, int k)
{
	if (k == 0 || n == k) return 1;
	else
	{
		return (coefficient(n - 1, k - 1) + coefficient(n - 1, k));
	}
}

int main(void)
{
	int n = 5, k = 3;
	printf("coefficient(%d C %d) : %d \n",n, k coefficient(n, k));
	return 0;
}
