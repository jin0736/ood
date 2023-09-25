#include <stdio.h>
void show(char* text)
{
	printf("String: %s\n", text);
}
void show(int number)
{
	printf("Number: %d\n", number);
}
int main()
{
	char* text = "Hello, World!";
	int number = 10;
	show(text);
	show(number);
	return 0;
}