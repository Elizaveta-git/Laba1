#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	List lst;
	int exit = 1;
	while (exit!=0)
	{
		cout << "######################################" << endl;
		lst.menu();
		cin >> exit;
		cout << endl << "######################################" << endl;
		lst.interface(exit);
	}
	return 0;
}