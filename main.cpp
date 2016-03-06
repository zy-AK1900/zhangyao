#include<iostream>
using namespace std;


void main()
{
	int a, b, i, f, t;
	for (i = 0; i < 30; i++)
	{

		a = rand() % 100;
		b = rand() % 100;
		if (a < b)
		{
			t = a;
			a = b;
			b = t;
		}
		cout << a;

		f = rand() % 4;
		switch (f)
		{
		case 0:cout << '+'; break;
		case 1:cout << '-'; break;
		case 2:cout << '*'; break;
		case 3:cout << '/'; break;
		}
		if (f % 4 == 3)
			b++;
		cout << b << '=' << endl;
	}
}