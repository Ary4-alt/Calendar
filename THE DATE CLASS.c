
#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;

class date
{
protected:
	int  y, m, d;

public:

	void show()
	{
		if (y < 0 || m < 0 || d < 0)
			cout << " ##:##:##  Negative date ...";
		else
		{
			if (y) cout << y << " year ";
			cout << y << "/" << m << "/" << d;
		}
	}
	void getdate()
	{

		do
		{
			cout << "year :";
			cin >> y;

			if (!(y >= 1900)) cout << "\n Az 1900  Vared Shavad \n";
		} while (y < 1900);

		do
		{
			cout << "month :";
			cin >> m;

			if (!(m >= 1 && m <= 12)) cout << "\n  Az 1 Ta 12 Vared Shavad \n";
		} while (m < 0 || m>12);

		do
		{
			cout << "day :";
			cin >> d;

			if (!(d >= 1 && d <= 31)) cout << "\n  Az 1 Ta 31 Vared Shavad \n";
		} while (d < 1 || d>31);

	}
	date(int a = 0, int b = 0)  // constructor
	{
		{
			y = 1900;	m = a;    d = b;
		}
		do
		{

			m += d / 31;
			d %= 31;
			y += m / 12;
			m %= 12;
			if (m = 0) m = m++;


		} while ((m = 1) || (m = 3) || (m = 5) || (m = 7) || (m = 8) || (m = 10) || (m = 12));



		do
		{

			m += d / 30;
			d %= 30;
			y += m / 12;
			m %= 12;
			if (m = 0) m = m++;


		} while (m = 4 || 6 || 9 || 11);

		do
		{

			m += d / 29;
			d %= 29;
			y += m / 12;
			m %= 12;
			if (m = 0) m = m++;


		} while (m = 2);



		do
		{

			m += d / 28;
			d %= 28;
			y += m / 12;
			m %= 12;
			if (m = 0) m = m++;


		} while (m = 2);
	}


	void Setdate(int a = 0, int b = 0)

	{
		do
		{

			m += d / 31;
			d %= 31;
			y += m / 12;
			m %= 12;
			if (m = 0) m = m++;


		} while ((m = 1) || (m = 3) || (m = 5) || (m = 7) || (m = 8) || (m = 10) || (m = 12));



		do
		{

			m += d / 30;
			d %= 30;
			y += m / 12;
			m %= 12;
			if (m = 0) m = m++;


		} while (m = 4 || 6 || 9 || 11);

		do
		{

			m += d / 29;
			d %= 29;
			y += m / 12;
			m %= 12;
			if (m = 0) m = m++;


		} while (m == 2 && y % 4 == 0);




		do
		{

			m += d / 28;
			d %= 28;
			y += m / 12;
			m %= 12;
			if (m = 0) m = m++;


		} while (m = 2);


	}
	int D_to_d()
	{
		if ((m = 1) || (m = 3) || (m = 5) || (m = 7) || (m = 8) || (m = 10) || (m = 12) && (!(y % 4 == 0)))

			return  d + (m * 31) + y * 365;
	}

	void d_to_D(int day)
	{
		y = day / 365;
		m = (day % 365) / 12;
		d = ((day % 365) % 12);
	}
	int  D_to_d1()
	{
		if ((m = 4 || 6 || 9 || 11) && (!(y % 4 == 0)))

			return  d + (m * 30) + y * 365;
	}

	void d_to_D1(int day)
	{
		y = day / 365;
		m = (day % 365) / 12;
		d = ((day % 365) % 12);
	}
	int D_to_d2()
	{
		if ((m == 2 && y % 4 == 0))

			return  d + (m * 29) + y * 365;
	}

	void d_to_D2(int day)
	{
		y = day / 365;
		m = (day % 365) / 12;
		d = ((day % 365) % 12);
	}
	int D_to_d3()
	{
		if (m == 2)

			return  d + (m * 28) + y * 365;
	}

	void d_to_D3(int day)
	{
		y = day / 365;
		m = (day % 365) / 12;
		d = ((day % 365) % 12);

	}

	date sum(date b)
	{
		date temp;
		temp.d_to_D((D_to_d() + b.D_to_d));

		return temp;
	}

	date operator+(date b)
	{
		date temp;
		temp.d_to_D(D_to_d() + b.D_to_d());
		return temp;
	}
	
	date operator+(int b)
	{
		date temp;
		temp.d_to_D(D_to_d() + b*(365));
		return temp;
	}

	date operator-(date b)
	{
		date temp;
		temp.d_to_D(D_to_d() - b.D_to_d());
		return temp;
	}

	bool operator< (date b) { return (D_to_d()  < b.D_to_d()); }
	bool operator> (date b) { return (D_to_d()  > b.D_to_d()); }
	bool operator<= (date b) { return (D_to_d() <= b.D_to_d()); }
	bool operator>= (date b) { return (D_to_d() >= b.D_to_d()); }
	bool operator== (date b) { return (D_to_d() == b.D_to_d()); }
	bool operator!= (date b) { return (D_to_d() != b.D_to_d()); }
	date operator+=(date b)
	{
		d_to_D(D_to_d() + b.D_to_d());
		return *this;
	}
	void test(int d)
	{
		cout << "\n patrameter d = " << d;
		cout << "\n Attribute  d = " << this->d;
		cout << "\n Attribute  d = " << (*this).d;
	}
};
class dateprime :public date
{
private:
	int d2;
public:
	void month_sheet()
	{
		cout << "d" << "/" << "m" << "/" << "y" << endl;
		cout << "\n_____________________________________________\n";
		switch (m)
		{
		case 1:
			cout << "January" << endl;
			break;

		case 2:
			cout << "February" << endl;
			break;

		case 3:
			cout << "March" << endl;
			break;

		case 4:
			cout << "April" << endl;
			break;

		case 5:
			cout << "May" << endl;
			break;

		case 6:
			cout << "June" << endl;
			break;

		case 7:
			cout << "July" << endl;
			break;

		case 8:
			cout << "August" << endl;
			break;

		case 9:
			cout << "September" << endl;
			break;

		case 10:
			cout << "October" << endl;
			break;

		case 11:
			cout << "November" << endl;
			break;

		case 12:
			cout << "December" << endl;
			break;

		default: cout << "\n\n OUT OF THE MONTH RANGE ";
		}

	}

};
void main()
{
	date d1(2020 / 12 / 20), d2(1989 / 2 / 8), d3;

	cout << "\n\n  D1 = ";   d1.show();
	cout << "\n\n  D2 = ";   d2.show();
	cout << "\n\n  D3 = ";   d3.show();

	cout << "\n\n\n****************************\n\n\n";
	d3 = d1 += d2;

	cout << "\n\n  D1 = ";   d1.show();
	cout << "\n\n  D2 = ";   d2.show();
	cout << "\n\n  D3 = ";   d3.show();

	d1.test(45);
	_getch();
}
