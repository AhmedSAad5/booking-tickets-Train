#include <iostream>
using namespace std;
struct Carriage
{
	int c;
	float p;
	bool b;
};
int carriage(Carriage a[], int x)
{
	int n = 1;
	cout << "Enter 1 to book a ticket." << endl;
	cout << "Enter 2 to cancel a ticket." << endl;
	cout << "Enter 3 to show available seats." << endl;
	cout << "Enter 4 to print profits in detail." << endl;
	cout << "Enter 0 to exit." << endl;
	cin >> n;
	cout << "Your choice: " << n << endl;
	cout << "----------------------------------------" << endl;
	return n;
}
void book(Carriage a[], int y)
{
	Carriage x;
	cout << "Enter the class: ";
	cin >> x.c;
	for (int i = 0; i < 30 * y; i++)
	{
		if (a[i].c == x.c)
		{
			cout << "This class in carriage#" << i / 30 + 1;
			cout << " From seat " << i + 1 << " to " << i + 30;
			cout << " the ticket cost " << a[i].p << " to book enter 1." << endl;
			cin >> x.b;
			if (x.b == 1)
			{
				cout << "Enter the seat: ";
				cin >> x.c;
				if (a[x.c - 1].b == 1)
				{
					cout << "This seat is booked up." << endl;
				}
				else
				{
					a[x.c - 1].b = 1;
					cout << "Done." << endl;
				}
			}
			break;
		}
	}
}
void cancel(Carriage a[])
{
	int x;
	cout << "Enter the seat: ";
	cin >> x;
	a[x - 1].b = 0;
	cout << "Done." << endl;
}
void show(Carriage a[], int x)
{
	cout << "These seats is available. ";
	for (int i = 0; i < 30 * x; i++)
	{
		if (a[i].b == 0)
		{
			cout << i + 1 << " ";
		}
	}
	cout << endl;
}
void detail(Carriage a[], int x)
{
	int c = 0;
	float p = 0;
	for (int i = 0; i < 30 * x; i++)
	{
		if (a[i].b == 1)
		{
			p += a[i].p;
			c++;
		}
	}
	cout << c << " tickets have been sold and 10% profit was earned on each ticket " << p * .10 << " that profit was used to develop carriages." << endl;
}
int main()
{
	int x, b = 1;
	Carriage y;
	cout << "Enter the number of carriages: ";
	cin >> x;
	Carriage* a = new Carriage[x * 30];
	for (int i = 1; i <= x; i++)
	{
		cout << "Carriage#" << i << endl;
		cout << "Enter class: ";
		cin >> y.c;
		cout << "Enter price: ";
		cin >> y.p;
		for (int j = (i - 1) * 30; j < 30 * i; j++)
		{
			a[j].c = y.c;
			a[j].p = y.p;
			a[j].b = 0;
		}
	}
	cout << "**************************************" << endl;
	while (b != 0)
	{
		b = carriage(a, x);
		switch (b)
		{
		case 1:
			book(a, x);
			break;
		case 2:
			cancel(a);
			break;
		case 3:
			show(a, x);
			break;
		case 4:
			detail(a, x);
			break;
		default:
			break;
		}
	}

}