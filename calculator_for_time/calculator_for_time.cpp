#include <iostream>
using namespace std;
int main(void)
{
	cout << "this program is a calculator ";
	cout << "\nfor time. you can add two or more";
	cout << "\ntimes to each other\n"<<endl<<endl;


	int ch[3] = { 0 };
	int hour = 0, minute = 0, second = 0, i = 0;
	cout << "i-> " << i << endl;
	for (int j = 0; j < 3; j++)
	{
		cin >> ch[j];
		if (ch[0] == -1)
			break;
	}
	while (ch[0] != -1)
	{
		second += ch[2];
		minute += ch[1];
		hour += ch[0];
		cout << "-----\n";
		cout << "i-> " << i++ << endl;
		for (int j = 0; j < 3; j++)
		{
			cin >> ch[j];
			if (ch[0] == -1)
				break;
		}
	}
	minute += second / 60;
	second %= 60;

	hour += minute / 60;
	minute %= 60;

	cout << "\n-_-_-_-_\n"<<endl;
	cout << "answer: " << endl;
	cout << hour << " : " << minute << " : " << second << endl;


	return 0;
}