#include <iostream> 
void increment(int x)
{
	++x;
}
int main()
{
	int x = 55;
	std::cout << " Before increment: " << x << std::endl;
	//Before increment: 55
	increment(x);
	std::cout << " After increment: " << x << std::endl;
	//After increment : 55
	system("pause");
	return 0;
}