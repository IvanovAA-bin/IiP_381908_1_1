#include "Time.h"
#include <iostream>
#include <clocale>

int main()
{
	setlocale(LC_CTYPE, "Russian");
	Time c1, c2(13425), c3("143:42:1"), c4(21, 45, 2); // ��������������
	c1.TimeOut(); // �������� �������������
	c2.TimeOut();
	c3.TimeOut();
	c4.TimeOut();

	c1 = c4; // �������� ������������ � ���������� ������
	std::cout << c1;

	std::cin >> c1; // �������� ���������� �����

	c4 = c3 + c1; // �������� �������� ��� Time + Time
	std::cout << c4;

	c4 = c4 + 14; // �������� �������� ��� Time + int
	c4.TimeOut();

	c1 = c4 - c3; // �������� ��������� ��� Time - Time
	c1.TimeOut();

	std::cout << std::endl << c1 << c2; // �������� bool ������� 
	if (c1 > c2)
		std::cout << "����� �1 > �2";
	else
		std::cout << "����� �1 <= c2";
}