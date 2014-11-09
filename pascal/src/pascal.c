/*
 ============================================================================
 Name        : pascal.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define N 20
unsigned long long nums[N/2+1];

typedef int bool;
const int n_bits=sizeof(unsigned long long)*8;

size_t highestOneBitPosition(unsigned long long  a) {
    size_t bits=0;
    while (a!=0) {
        ++bits;
        a>>=1;
    };
    return bits;
}
bool multiplication_is_safe(const unsigned long long a,const  unsigned long long b) {
    size_t a_bits=highestOneBitPosition(a), b_bits=highestOneBitPosition(b);
    return (a_bits+b_bits<=n_bits);
}

static void print_n_times(const int ch,const int n)
{
		int i=0;
    for (; i<n; i++) {
         putchar(ch);
    }
}
void print_pascal_line(const int n){


	unsigned long long cur=1,i=1;
	for(;i<=n+1;i++){
		printf("%llu ", cur);
		cur = cur*(n-i+1)/i;

	}
}
void print_pascal_linef(const int n){

	unsigned long long cur=1,i=1;
	nums[0]=1;
	for(;i<=((n+1)/2+(n+1)%2);i++){
		printf("%llu ", cur);
		if(!multiplication_is_safe(cur, (n-i+1)/i))
			printf("overflow! ");
		cur = cur*(n-i+1)/i;
		nums[i]=cur;

	}
	i=1;
	for(;i<=(n+1)/2;i++){
		printf("%llu ", nums[(n+1)/2-i]);

	}
}
void print_pascal_lines(const int n){

	int i=0;
	for(;i<=n;i++){
		print_n_times(' ',n-i);
		print_pascal_linef(i);
		putchar('\n');
	}
}

int main(void) {

	print_pascal_lines(N);

	//printf("%d",sizeof(unsigned long long)*8);
	return EXIT_SUCCESS;
}
