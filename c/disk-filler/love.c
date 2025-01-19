#include<stdio.h>
#include<stdint.h>
int main()
{
	int flag = 1;
	FILE* fp;
	fp = fopen("love.txt", "w");
	uint64_t x = 0x0000000000000000;
	while(x <= 0xFFFFFFFFFFFFFFFF)
	{
		if(flag == 1)
			fputs("1", fp);
		else
			fputs("0", fp);
		flag = -flag;
		if(x % 32 == 31)
			fputs("\n", fp);
		x++;
	}
	fclose(fp);
	return 0;
} 
