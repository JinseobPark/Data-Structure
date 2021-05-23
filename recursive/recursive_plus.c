/****************************************************
\file   recursive_plus.c
\author Jinseob Park
\par    email: 0814owl@gmail.com
\brief	다음을 계산하는 순환적인 프로그램을 작성하시오.
	1 + 2 + 3 ... + n
*****************************************************/
#include <stdio.h>
int add_recursive(int n)
{
	if (n <= 1) return 1;
	return n + add_recursive(n - 1);
}

int main(void)
{
	int n = 5;
	printf("add(%d) : %d \n",n, add_recursive(n));
	return 0;
}
