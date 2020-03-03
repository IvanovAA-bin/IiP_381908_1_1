#include "Time.h"
#include <cstdlib>
#include <iostream>

//___________________����������� �� ���������
Time::Time()
{
	hou = 0;
	min = 0;
	sec = 0;
}

//___________________����������� �����������
Time::Time(const Time& c)
{
	hou = c.hou;
	min = c.min;
	sec = c.sec;
}

//___________________����������� �������������� ����
Time::Time(int seconds)
{
	seconds = seconds % 86400;
	hou = seconds / 3600;
	min = (seconds - hou * 3600) / 60;
	sec = seconds % 60;
}

//___________________����������� �������������� ���� ��� ����� 11:11:11
Time::Time(const char *str)
{
	int len = (int)strlen(str);
	int count = 0, ch = 0;
	int i = 0, _ch = 0, __ch = 0;
	for (int i = 0; i < len; i++) // ���������� �������� ������ �� ���������� � ��� ����� : 
		if (str[i] == ':')
			count++;
	// � ����������� �� �����, ��������� �������������, ���������� ���������
	switch (count)
	{
		case 0: // � ������, ����� ������ ����� ���: "14", ������ ����� � ������, ��������, "1412" ����� ��� ����� ����� ����������� �������������
			for (i = 0; i < len; i++)
				ch = ch * 10 + str[i] - '0';
			break;

		case 1: // � ������, ����� ������ ����� ���: "14:41"
			i = 0; _ch = 0;
			while (str[i] != ':')
			{
				ch = ch * 10 + str[i] - '0';
				i++;
			}
			ch *= 60;
			i++;
			if (i != len)
			{
				while (str[i] != 0)
				{
					_ch = _ch * 10 + str[i] - '0';
					i++;
				}
			}
			ch += _ch;
			break;

		case 2: // � ������, ����� ������ ����� ���: "14:41:56" (�� ����� ���� ����� ��������)
			_ch = 0; __ch = 0; i = 0;
			while (str[i] != ':')
			{
				ch = ch * 10 + str[i] - '0';
				i++;
			}
			ch *= 3600;
			i++;
			while (str[i] != ':')
			{
				_ch = _ch * 10 + str[i] - '0';
				i++;
			}
			_ch *= 60;
			i++;
			if (i != len)
			{
				while (str[i] != 0)
				{
					__ch = __ch * 10 + str[i] - '0';
					i++;
				}
			}
			ch += _ch + __ch;
			break;

		default: // � ������, ����� ������ ����� ����� ���� ������ ':'
			std::cout << "\n��������� ����� �����������\n";
			break;
	}

	ch = ch % 86400; // ������� � ���������
	hou = ch / 3600;
	min = (ch - hou * 3600) / 60;
	sec = ch % 60;
}

//___________________����������� �������������
Time::Time(int h, int m, int s)
{
	int ch = (h * 3600 + m * 60 + s) % 86400;
	hou = ch / 3600;
	min = (ch - hou * 3600) / 60;
	sec = ch % 60;
}

//__________________����������
Time::~Time()
{
	hou = 0;
	min = 0;
	sec = 0;
}

//____________________________________������

//__________________����� ������� � ������� 00:00:00
void Time::TimeOut(void)
{
	char str[9];
	str[8] = 0; str[2] = ':'; str[5] = ':';
	str[0] = hou / 10 + '0'; str[1] = hou % 10 + '0';
	str[3] = min / 10 + '0'; str[4] = min % 10 + '0';
	str[6] = sec / 10 + '0'; str[7] = sec % 10 + '0';
	std::cout << str <<std::endl;
	return;
}

//____________________________________����������

//__________________���������� ������������
Time& Time::operator=(const Time& c)
{
	hou = c.hou;
	min = c.min;
	sec = c.sec;
	return *this;
}

//__________________���������� �������� ��� ���� �� ������
Time Time::operator+(const Time& c)
{
	Time rs;
	rs.sec = sec + c.sec;
	rs.min = min + c.min + rs.sec / 60;
	rs.sec = rs.sec % 60;
	rs.hou = hou + c.hou + rs.min / 60;
	rs.min = rs.min % 60;
	rs.hou = rs.hou % 24;
	return rs;
}

//__________________���������� �������� ��� ������
Time Time::operator+(int _sec)
{
	Time rs;
	int ch = (hou * 3600 + min * 60 + sec + _sec) % 86400;
	rs.hou = ch / 3600;
	rs.min = (ch - hou * 3600) / 60;
	rs.sec = ch % 60;
	return rs;
}

//__________________���������� ��������� ��� ���� �� ������
Time Time::operator-(const Time& c)
{
	Time rs;
	int tim1 = hou * 3600 + min * 60 + sec;
	int tim2 = c.hou * 3600 + c.min * 60 + c.sec;
	tim1 -= tim2;
	if (tim1 < 0)
		tim1 += (-1 * tim1 / 86400 + 1) * 86400;
	rs.hou = tim1 / 3600;
	rs.min = (tim1- hou * 3600) / 60;
	rs.sec = tim1 % 60;

	return rs;
}

//__________________���������� ��������� ��� ������
Time Time::operator-(int _sec)
{
	Time rs;
	int tim = hou * 3600 + min * 60 + sec;
	tim -= _sec;
	if (tim < 0)
		tim += (-1 * tim / 86400 + 1) * 86400;
	rs.hou = tim / 3600;
	rs.min = (tim - hou * 3600) / 60;
	rs.sec = tim % 60;
	return rs;
}

//__________________���������� �������� >
bool Time::operator>(const Time& c)
{
	int tim1 = hou * 3600 + min * 60 + sec;
	int tim2 = c.hou * 3600 + c.min * 60 + c.sec;
	if (tim1 > tim2)
		return true;
	else
		return false;
}

//__________________���������� �������� >=
bool Time::operator>=(const Time& c)
{
	int tim1 = hou * 3600 + min * 60 + sec;
	int tim2 = c.hou * 3600 + c.min * 60 + c.sec;
	if (tim1 >= tim2)
		return true;
	else
		return false;
}

//__________________���������� �������� <
bool Time::operator<(const Time& c)
{
	int tim1 = hou * 3600 + min * 60 + sec;
	int tim2 = c.hou * 3600 + c.min * 60 + c.sec;
	if (tim1 < tim2)
		return true;
	else
		return false;
}

//__________________���������� �������� <=
bool Time::operator<=(const Time& c)
{
	int tim1 = hou * 3600 + min * 60 + sec;
	int tim2 = c.hou * 3600 + c.min * 60 + c.sec;
	if (tim1 <= tim2)
		return true;
	else
		return false;
}

//__________________���������� �������� ==
bool Time::operator==(const Time& c)
{
	int tim1 = hou * 3600 + min * 60 + sec;
	int tim2 = c.hou * 3600 + c.min * 60 + c.sec;
	if (tim1 == tim2)
		return true;
	else
		return false;
}

//__________________���������� ���������� ������
std::ostream& operator<<(std::ostream& out, Time& c)
{
	if (c.GetHou() >= 0 && c.GetHou() <= 9)
		out << "����� = " << "0" << c.GetHou() << ":";
	else
		out << "����� = " << c.GetHou() << ":";
	
	if (c.GetMin() >= 0 && c.GetMin() <= 9)
		out << "0" << c.GetMin() << ":";
	else
		out << c.GetMin() << ":";

	if (c.GetSec() >= 0 && c.GetSec() <= 9)
		out << "0" << c.GetSec() << '\n';
	else
		out << c.GetSec() << '\n';
	return out;
}

//__________________���������� ���������� �����
std::istream& operator>>(std::istream& in, Time& c)
{
	int _hou, _min, _sec;
	std::cout << "\n������� ���-�� �����: ";
	in >> _hou;
	while (_hou < 0 || _hou > 23)
	{
		std::cout << "������� ����� �� 0� �� 23�: ";
		in >> _hou;
	}

	std::cout << "\n������� ���-�� �����: ";
	in >> _min;
	while (_min < 0 || _min > 59)
	{
		std::cout << "������� ����� �� 0��� �� 59���: ";
		in >> _min;
	}

	std::cout << "\n������� ���-�� ������: ";
	in >> _sec;
	while (_sec < 0 || _sec > 59)
	{
		std::cout << "������� ����� �� 0��� �� 59���: ";
		in >> _sec;
	}

	c.hou = _hou;
	c.min = _min;
	c.sec = _sec;
	return in;
}
