#include<iostream>

class SetValue
{
	int x, y;
	/* 이곳에 코드 추가 */
public:
	void setXY(int a, int b) {
		x = a;
		y = b;
	}

	void show() {
		std::cout << "X = " << x << " , Y = " << y << std::endl;

	}
};
int main()
{
	SetValue obj;
	obj.setXY(33, 44);
	obj.show(); // X, Y 출력 함수
	system("pause");
	return 0;
}