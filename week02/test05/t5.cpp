#include <iostream>
#include <ctime>
#include <cstdlib>
class Dice
{
	int value; // �ֻ��� ��
public:
	void set_dice_value() // �ֻ��� ���� ������ ���� �� �ֵ���
	{
		/* �� ���� �ڵ� �߰� */
		value = rand() % 6 + 1;
	}
	int get_dice_value()
	{
		return value;
	}
};
int main()
{
	srand(time(NULL));
	Dice dice1;
	Dice dice2;
	dice1.set_dice_value();
	dice2.set_dice_value();
	std::cout << "�� �ֻ��� ��=" << dice1.get_dice_value() +
		dice2.get_dice_value() << std::endl;
	return 0;
}