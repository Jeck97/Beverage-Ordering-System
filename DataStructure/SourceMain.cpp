#include<iostream>
#include<string>
#include <iomanip>
using namespace std;
#include"Header.h"

void main()
{
	MilkTea purchase;
	int selection, decisionMakeOrder, decisionCategory, endPoint;

	do
	{
	INTERFACE:
		system("cls");
		cout << "\n";
		cout << setw(20) << setfill(' ') << "\0" << "	  Welcome to TiangLive Tea shop\n\n" ;
		cout << setw(20) << setfill('*') << "\0" << "\t(1)	Order from the Main Menu\t" << setw(20) << setfill('*') << "\0" << endl;
		cout << setw(20) << setfill('*') << "\0" << "\t(2)	Choose from a Sorted Menu\t" << setw(20) << setfill('*') << "\0" << endl;
		cout << setw(20) << setfill('*') << "\0" << "\t(3)	Search for your Drink\t\t" << setw(20) << setfill('*') << "\0" << endl;
		cout << setw(20) << setfill('*') << "\0" << "\t(4)	Cancel your Drink\t\t" << setw(20) << setfill('*') << "\0" << endl;
		cout << setw(20) << setfill('*') << "\0" << "\t(5)	End your Order\t\t\t" << setw(20) << setfill('*') << "\0" << endl;
		cout << setfill(' ');
	SELECTION:
		cout << "\n\n\nPlease enter your desired operation	: ";
		cin >> selection;
		switch (selection)
		{
		case 1:
		MAINMENU:
			system("cls");
			purchase.mainMenu(decisionCategory, endPoint);
			if (decisionCategory != 1 && decisionCategory != 2 && decisionCategory != 3 && decisionCategory != 4)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				goto INTERFACE;
			}
			break;

		case 2:
		SORTMENU:
			system("cls");
			purchase.sortMenu(decisionCategory, endPoint);
			if (decisionCategory != 1 && decisionCategory != 2 && decisionCategory != 3)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				goto INTERFACE;
			}
			break;

		case 3:
		SEARCHMENU:
			system("cls");
			purchase.searchMenu(decisionCategory, endPoint);
			if (decisionCategory != 1 && decisionCategory != 2)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				goto INTERFACE;
			}
			break;

		case 4:
			system("cls");
			purchase.cancelOrder();
			goto INTERFACE;

		case 5:
			if (!purchase.empty())
			{
				system("cls");
				purchase.printReceipt();
			}
			cout << "\n\n\nThank You for choosing our shop\n\n\n";
			system("pause");
			return;

		default:
			cout << "\tInvalid input! Please enter again the correct operation based on the number above.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			goto SELECTION;
		}

		if (selection == 1 || selection == 2 || selection == 3)
		{
		MAKEORDER:
			purchase.makeOrder(decisionMakeOrder, endPoint);
			if (!(decisionMakeOrder >= 1 && decisionMakeOrder <= endPoint))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				goto REORDER;
			}

		CUSTOMIZE:
			char decisionCustomize;
			cout << "\nWould you like to customize your drinks? \nIf you choose no, your drink will automatically set to default. (100% sugar, Normal amount of ice) (Y/N)	: ";
			cin >> decisionCustomize;
			if (decisionCustomize == 'y' || decisionCustomize == 'Y')
				purchase.customize();
			else if (decisionCustomize != 'y' && decisionCustomize != 'Y' && decisionCustomize != 'N' && decisionCustomize != 'n')
			{
				cout << "\tInvalid input! Please enter again based on the selection given.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				goto CUSTOMIZE;
			}
			cout << "This order had done!\n\n";

		REORDER:
			char decisionOrder;
			cout << "Do you want to add the order again from ";
			switch (selection)
			{
			case 1: cout << "main";			break;
			case 2: cout << "sorted";		break;
			case 3: cout << "searching";	break;
			}
			cout << " menu ? (Y / N) : ";
			cin >> decisionOrder;
			if (decisionOrder == 'Y' || decisionOrder == 'y')
			{
				switch (selection)
				{
				case 1: goto MAINMENU; break;
				case 2: goto SORTMENU; break;
				case 3: goto SEARCHMENU; break;
				}
			}
			else if (decisionOrder != 'y' && decisionOrder != 'Y' && decisionOrder != 'N' && decisionOrder != 'n')
			{
				cout << "\tInvalid input! Please enter again.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				goto REORDER;
			}
		}
	} while (selection != 4);
}
