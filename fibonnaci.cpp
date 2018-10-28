//author: Frank Su 001411435
#include <stdio.h>

unsigned long long fibonnaci(unsigned long long n); //function prototype
int main() {
	int n;
	//prompts user to input integer for fib sequence
	puts("Please enter a positive integer"); 
	scanf_s("%d", &n);
	//prints entire fib sequence with n terms
	printf("The entire fibonnaci sequence with %d terms is: ", n);
	for (int i = 0; i <= n; i++) {
		printf("%d ", fibonnaci(i));
	}
	puts("");
	//prints the nth term of the fib sequence
	printf("The %dth term of the fibonnaci sequence is: %d", n, fibonnaci(n));
}

unsigned long long fibonnaci(unsigned long long n) {
	//initialize integer variables for first 2 terms of fib sequence to be 0 and 1
	unsigned long long x = 0; //can think of x as (nth term - 2)
	unsigned long long y = 1; //can think of y as (nth term - 1)
	//declare integer fib that will hold return value of fibonnaci(n)
	unsigned long long fib;

	//if statements that return first two terms of fibonnaci sequence, which is always 0 and 1
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}

	//for loop with i starting at 2, calcuates fibonnaci value for n that is greater than 1
	for (int i = 2; i <= n; i++) {
		fib = x + y; //fib is result of previous two terms added together
		x = y; //update x so that it now contains next consecutive term
		y = fib; //update y so that it equals fib, which is now the nth term - 1 for next iteration
	}
	return fib;
} 