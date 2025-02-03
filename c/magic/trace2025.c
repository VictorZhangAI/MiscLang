#include<stdio.h>

/*0 = chopsticks
  1 = cup
  2 = spoon*/
  
int set[3];
int hand[2];

void fill(int x, int y, int z)
{
	set[0] = x;
	set[1] = y;
	set[2] = z;
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swap_left(int item)
{
	if(set[0] == item)
		return;
	else
		(set[1] == item) ? swap(&set[1], &set[0]) : swap(&set[2], &set[1]);
}

void swap_right(int item)
{
	if(set[2] == item)
		return;
	else
		(set[1] == item) ? swap(&set[1], &set[2]) : swap(&set[0], &set[1]);
}

void take()
{
	hand[0] = set[0];
	hand[1] = set[2];
}

#define TRY(X, Y, Z) \
	fill((X), (Y), (Z)); \
	swap_left(0); \
	swap_right(1); \
	swap_left(2); \
	take(); \
	printf("%d\n", hand[1]);

int main()
{
	//permutation of 0 1 2: 3!=6
	//enumerate all possibilities
	TRY(0,1,2);
	TRY(0,2,1);
	TRY(1,0,2);
	TRY(1,2,0);
	TRY(2,0,1);
	TRY(2,1,0);
	return 0;
} 
