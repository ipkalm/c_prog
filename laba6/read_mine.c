#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int gold;
	FILE *mine = fopen("mine", "r");
	
	fread(&gold, sizeof(int), 1, mine);
	printf("gold in mine = %d\n", gold);
	return 0;
}
