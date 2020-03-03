#ifndef TIME_H
#define TIME_H
#include <iostream>

class Time {
	private:
		int hou;
		int min;
		int sec;

	public:
		//������������
		Time(); // ����������� �� ���������
		Time(const Time& c); // ����������� �����������
		Time(int sec); // ����������� �������������� ���� 
		Time(const char *str); // ����������� �������������� ���� ��� 11:11:11
		Time(int h, int m, int s); // ����������� �������������

		//����������
		~Time(); 

		//������
		void TimeOut(void); // ����� � ������� 11:11:11
		int GetHou() { return hou; } // ��������� ���-�� �����
		int GetMin() { return min; } // ��������� ���-�� �����
		int GetSec() { return sec; } // ��������� ���-�� ������
		int TimeInSec() { return hou * 3600 + min * 60 + sec; } // ��������� ������� � �������� ���������
		void SetHou(int h) { hou = h % 24; } // ������� ���-�� �����
		void SetMin(int m) { min = m % 60; } // ������� ���-�� �����
		void SetSec(int s) { sec = s % 60; } // ������� ���-�� ������

		//����������
		Time& operator= (const Time& c); // ���������� ������������
		Time operator+ (const Time& c); // ���������� �������� ��� ���� �� ������
		Time operator+ (int _sec); // ���������� �������� � ���������
		Time operator- (const Time& c); // ���������� ��������� ��� ���� �� ������
		Time operator- (int _sec); // ���������� ��������� � ���������

		bool operator> (const Time& c); // ���������� �������� >
		bool operator>= (const Time& c); // ���������� �������� >=
		bool operator< (const Time& c); // ���������� �������� <
		bool operator<= (const Time& c); // ���������� �������� <=
		bool operator== (const Time& c); // ���������� �������� ==

		friend std::ostream& operator<< (std::ostream& out, Time& c); // ���������� <<
		friend std::istream& operator>> (std::istream& in, Time& c); // ���������� >>
};

#endif