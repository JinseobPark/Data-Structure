/****************************************************
\file   recursive_factorial.c
\author Jinseob Park
\par    email: 0814owl@gmail.com
\brief	팩토리얼을 recursive기법으로 계산하는 과정
*****************************************************/
#include <stdio.h>
int factorial(int n)
{
    printf("factorial(%d)\n",n);
    if( n <= 1 ) return(1);
    else return (n * factorial(n-1) );
}

int main(void)
{
	int n = 5;
	printf("%d ! : %d \n",n, factorial(n));
	return 0;
}
