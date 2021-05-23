/****************************************************
\file   recursive_fibo.c
\author Jinseob Park
\par    email: 0814owl@gmail.com
\brief	피보나치를 recursive기법으로 계산하는 과정
*****************************************************/
#include <stdio.h>
int fib(int n)
{
    if( n==0 ) return 0;
    if( n==1 ) return 1;
    return (fib(n-1) + fib(n-2));
}
int main(void)
{
	int n = 5;
	printf("fibo(%d) : %d \n",n, fib(n));
	return 0;
}
