#include <iostream>
#include <windows.h>


class Calculator
{
private:
	double num1, num2;
public:
	Calculator(double num1, double num2)
	{
		this->num1 = num1;
		this->num2 = num2;
	}
	double add(double num1, double num2)
	{
		return num1 + num2;
	}
	double multiply(double num1, double num2)
	{
		return num1 * num2;
	}
	double subtract_1_2(double num1, double num2)
	{
		return num1 - num2;
	}
	double subtract_2_1(double num1, double num2)
	{
		return num2 - num1;
	}
	double divide_1_2(double num1, double num2)
	{
		if (num2==0) 
		{
			std::cout << "num2 равно 0 - деление не может быть выполнено" << std::endl; // на случай отсутствия проверки
		}
		else return num1 / num2;
	}
	double divide_2_1(double num1, double num2)
	{
		if (num1 == 0)
		{
			std::cout << "num1 равно 0 - деление не может быть выполнено" << std::endl; // на случай отсутствия проверки
		}
		else return num2 / num1;
	}
	bool set_num1(double num1)
	{
		if (num1 != 0) return true;
		else return false;
	}
	bool set_num2(double num2)
	{
		if (num2 != 0) return true;
		else return false;
	}
};





int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double num1 = 0, num2 = 0;
	Calculator user_num(0,0);
	do
	{
		std::cout << "Введите число num1: ";
		std::cin >> num1;
		std::cout << std::endl;
		if (!user_num.set_num1(num1))
		{
			std::cout << "Не верный ввод, число не может быть равно 0!" << std::endl;
			continue;
		}
		std::cout << "Введите число num2: ";
		std::cin >> num2;
		std::cout << std::endl;
		if (!user_num.set_num2(num2))
		{
			do
			{
				std::cout << "Не верный ввод, число не может быть равно 0!" << std::endl;
				std::cout << "Введите число num2: ";
				std::cin >> num2;
				std::cout << std::endl;
				if (!user_num.set_num2(num2)) continue;
			}
			while (!user_num.set_num2(num2));
		}
		std::cout << "num1 + num2 = " << user_num.add(num1, num2) << std::endl;
		std::cout << "num1 - num2 = " << user_num.subtract_1_2(num1, num2) << std::endl;
		std::cout << "num2 - num1 = " << user_num.subtract_2_1(num1, num2) << std::endl;
		std::cout << "num1 * num2 = " << user_num.multiply(num1, num2) << std::endl;
		std::cout << "num1 / num2 = " << user_num.divide_1_2(num1, num2) << std::endl;
		std::cout << "num2 / num1 = " << user_num.divide_2_1(num1, num2) << std::endl;
	}
	while (1 > 0);
	return 0;
}