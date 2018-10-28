//author: Frank Su 001411435
#include <stdio.h>

//function prototype to move disks: paramters from left to right: number of disks to move, initial peg, peg used as a temporary
//holding area, peg to which stack of disks are moved to 
void move(int disks, int begin, int temp, int end);

int main() {
	puts("This program will give the solution to the Tower of Hanoi Problem:");
	printf("Please enter the number of disks to be used in the game: ");
	int disks;
	//ask user for input on how many disks in game
	scanf_s("%d", &disks);
	printf("Assume 1 = beginning peg, 2 = middle peg, and 3 = end peg. The solution for a game with %d disks is:\n", disks);
	int begin = 1;
	int temp = 2;
	int end = 3;
	move(disks, begin, temp, end); //call move function using number of disks determined by user input
}

void move(int disks, int begin, int temp, int end) {
	
	//case if only moving one disk from beginning peg to end peg
	if (disks == 1) {
		printf("%d --> %d\n", begin, end);
	}
	else {
		move(disks - 1, begin, end, temp); //moves n-1 disks from beginning peg to temporary peg 
		move(1, begin, temp, end); //moves 1 disk (should be largest) from beginning peg to end peg
		move(disks - 1, temp, begin, end); //moves n-1 disks from temporary peg to end peg
	}
}