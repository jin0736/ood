#include<iostream>

class SetValue
{
	int x, y;
	/* �̰��� �ڵ� �߰� */
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
	obj.show(); // X, Y ��� �Լ�
	system("pause");
	return 0;
}