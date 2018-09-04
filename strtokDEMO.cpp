#include <stdio.h>
#include <string.h>
#include <conio.h>
char string[] = "A string\tof ,,tokens\nand some  more tokens";
char seps[]   = " ,\t\n";
char *token;
int main(void)
{
	printf( "Tokens:\n" );
    token = strtok( string, seps );
	while(token !=NULL)
	{
         printf("%s\n",token);
		 token=strtok(NULL,seps);
	}
	getch();
	return 0;
}
