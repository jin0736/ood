#include <stdio.h>
void show(char* text)
{
	printf("String: %s\n", text);
}
void show(int number)
{
	printf("Number: %d\n", number);
}

//c에서는 함수 오버로딩이 지원되지 않아 같은 이름의 함수 2개가 있을 수 없다.
int main()
{
	char* text = "Hello, World!";
	int number = 10;
	show(text);
	show(number);
	return 0;
}