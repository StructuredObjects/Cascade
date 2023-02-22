#include <stdio.h>
#include <string.h>

int main()
{
	char *test = "help\n";
	if(strstr("hel", test) == 0)
		printf("here");
	return 0;
}
