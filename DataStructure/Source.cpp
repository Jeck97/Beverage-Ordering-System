#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;
#include"Header.h"

MilkTea::MilkTea()
{
	phead = NULL;
	numItem = 0;
	pcurrent = phead; //this pcurrent is always point to the last node in the order link list
}

MilkTea::~MilkTea()
{}

void MilkTea::mainMenu(int& decisionCategory, int& endPoint)
{
	char menuType;
	ifstream infile("AllMenu.txt"); //already modify to use one input file
	for (int i = 0; infile >> Array[i].code >> Array[i].name >> Array[i].price >> Array[i].soldNum; i++) {} //input all the elements into array
	infile.close();
	cout << "\n\t\t" << setw(65) << setfill('*') << "\0" << endl;
	cout << "\t\t*\t\t\t\t\t\t\t\t*" << endl;
	cout << "\t\t*" << setw(10) << setfill(' ') << "\0" << "\t     CATEGORY OF BEVERAGE\t\t\t*" << endl;
	cout << "\t\t*\t\t\t\t\t\t\t\t*"<< endl;
	cout << "\t\t*" << setw(10) << setfill(' ') << "\0" << "\t(1)	Milk Tea\t\t\t\t*" << endl;
	cout << "\t\t*" << setw(10) << setfill(' ') << "\0" << "\t(2)	Caffeine\t\t\t\t*" << endl;
	cout << "\t\t*" << setw(10) << setfill(' ') << "\0" << "\t(3)	Fruit Juice\t\t\t\t*" << endl;
	cout << "\t\t*" << setw(10) << setfill(' ') << "\0" << "\t(4)	Smoothie\t\t\t\t*" << endl;
	cout << "\t\t*\t\t\t\t\t\t\t\t*" << endl;
	cout << "\t\t" << setw(65) << setfill('*') << "\0" << endl;
	cout << "\n\n**You may press other key to go back to main menu**" << endl;
	cout << "Please choose the category		: ";
	cin >> decisionCategory;
	switch (decisionCategory)
	{
	case 1: menuType = 'A'; break;
	case 2: menuType = 'B'; break;
	case 3: menuType = 'C'; break;
	case 4: menuType = 'D'; break;
	default: return;
	}

	endPoint = 0;			 //use to record the quantity of element in the submenu
	for (int a = 0; a < MENU_SIZE;a++)
	{
		if (Array[a].code[0] == menuType) //compare the first character in the string with the selected character "menuType"
		{
			Array[endPoint] = Array[a]; //move the selected element to the front of array
			endPoint++;
		}
	}
	system("cls");
	cout << endl << setfill(' ') << "\t\tOPTION" << setw(8) << "CODE\t" << setw(30) << left << "DRINK'S NAME" << right << setw(12) << "PRICE(RM)" << endl;
	for (int i = 0; i < endPoint; i++)
		cout <<"\t\t"<< setw(2) << i + 1 << ")" << setw(10) << Array[i].code << "\t" << setw(30) << left << Array[i].name << right << setprecision(2) << fixed << setw(10) << Array[i].price << endl;
}

void MilkTea::sortMenu(int& decisionCategory, int& endPoint)
{
	endPoint = MENU_SIZE; //initialize the quantitiy of the sorted menu
	int sortType;
	ifstream infile("AllMenu.txt");
	for (int i = 0; infile >> Array[i].code >> Array[i].name >> Array[i].price >> Array[i].soldNum; i++) {}
	infile.close();
	cout << "\t\t\tCATEGORY OF SORT\n" << endl;
	cout << "\t\t(1) Sorting by Drinks' Name		(Alphabetically)" << endl;
	cout << "\t\t(2) Sorting by Drinks' Price		(Numerically)" << endl;
	cout << "\t\t(3) Sorting by Hot Selling Drinks" << endl;
	cout << "\n*Press other key to go back to main menu*" << endl;
	cout << "Please choose the category		: ";
	cin >> decisionCategory;
	if (decisionCategory == 1 || decisionCategory == 2 || decisionCategory == 3)
	{
		cout << "\tPlease choose the type of sorting\n\t";
		if (decisionCategory == 1 || decisionCategory == 2)
			cout << "(1)	Ascending\n\t(2)	Descending\n";
		else
			cout << "(1) Hottest\n\t(2) Not Popular\n";
	SORTTYPE:
		cout << "\tOption	: ";
		cin >> sortType;
		if (sortType != 1 && sortType != 2)
		{
			cout << "\tInvalid input! Please enter again.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			goto SORTTYPE;
		}
	}
	switch (decisionCategory)
	{
	case 1:
		//sort by bubble sort
		//algorithm of bubble sort used
		//for (int i = 0; i < n - 1; i++) {
		//	for (int j = 0; j < n - 1 - i; j++) {
		//		if (list[j] > list[j + 1]) {
		//			temp = list[j];
		//			list[j] = list[j + 1];
		//			list[j + 1] = temp;
		//		}
		//		for (int a = 0; a < n; a++)
		//			cout << list[a] << " ";
		//		cout << endl;
		//	}
		//	cout << endl;
		//}
		for (int a = 0; a < MENU_SIZE - 1; a++)
		{
			for (int b = 0; b < MENU_SIZE - 1 - a; b++)
			{
				bool stop = true; //set break point for the loop
				for (int c = 0; stop; c++)
				{
					if (Array[b].name.compare(c, 1, Array[b + 1].name, c, 1) != 0) //compare the current string and next string which only compare at position c (c th) and only compare with one char each other
					{																//if the char compare is not same will enter this selection condition else c++ to compare next char
						if ((sortType == 1) && (Array[b].name.compare(c, 1, Array[b + 1].name, c, 1) > 0)) //ascending
						{
							order temp = Array[b]; //exchange all elements in the this struct array (not only exchange between Array.name)
							Array[b] = Array[b + 1];
							Array[b + 1] = temp;
						}
						else if ((sortType == 2) && (Array[b].name.compare(c, 1, Array[b + 1].name, c, 1) < 0)) //descending
						{
							order temp = Array[b];
							Array[b] = Array[b + 1];
							Array[b + 1] = temp;
						}
						stop = false; //after exchange then stop this loop
					}
				}
			}
		}
		break;

	case 2:
		for (int i = 1; i < MENU_SIZE; i++)
		{
			//sort by insertion sort
			//algorithm of insertion sort used
			//int list[n] = { 8,5,6,4,2,3,7,9,0,1 }, next, i, j;
			//for (int a = 0; a < n; a++)
			//	cout << list[a] << " ";
			//cout << endl;
			//for (i = 1; i < n; i++) {
			//	next = list[i];
			//	j = i;
			//	while (next < list[j - 1] && j != 0) {
			//		list[j] = list[j - 1];
			//		j--;
			//		list[j] = next;
			//	}
			//}
			//for (int a = 0; a < n; a++)
			//	cout << list[a] << " ";
			//cout << endl;

			double next = Array[i].price;
			int j = i;
			
			while ((next < Array[j - 1].price && j != 0) && (sortType == 1))
			{
				order temp = Array[j];
				Array[j] = Array[j - 1];
				Array[j - 1] = temp;
				j--;
			}
			while ((next > Array[j - 1].price && j != 0) && (sortType == 2))
			{
				order temp = Array[j];
				Array[j] = Array[j - 1];
				Array[j - 1] = temp;
				j--;
			}
			
		}
		break;

	case 3:
		//sort by simple sort
		//algorithm of simple sort used
		//int list[n] = { 5,6,9,7,5,4,2,4,0,11 };
		//int i, j, locMin, min;
		//for (i = 0; i < n - 1; i++) {
		//	locMin = i;
		//	min = list[locMin];
		//	for (j = i + 1; j < n; j++) {
		//		if (list[j] < min) {
		//			locMin = j;
		//			min = list[locMin];
		//		}
		//	}
		//	list[locMin] = list[i];
		//	list[i] = min;
		//}
		//for (int a = 0; a < n; a++)
		//	cout << list[a] << " ";
		//cout << endl;
		for (int i = 0; i < MENU_SIZE - 1; i++)
		{
			int locationNumber = i;
			order number = Array[locationNumber];
			for (int j = i + 1; j < MENU_SIZE; j++)
			{
				if ((number.soldNum < Array[j].soldNum) && (sortType == 1))
				{
					locationNumber = j;
					number = Array[locationNumber];
				}
				
				else if((number.soldNum > Array[j].soldNum) && (sortType == 2))
				{
					locationNumber = j;
					number = Array[locationNumber];
				}
			}
			Array[locationNumber] = Array[i];
			Array[i] = number;
		}
		break;

	default: return;
	}
	system("cls");
	cout << endl << setfill(' ') << "\t\tOPTION" << setw(8) << "CODE\t" << setw(30) << left << "DRINK'S NAME" << right << setw(12) << "PRICE(RM)";
	if (decisionCategory == 3)
		cout << setw(12) << "SOLD(CUP)" << endl;
	cout << endl;

	for (int i = 0; i < endPoint; i++)
	{
		cout << "\t\t" << setw(2) << i + 1 << ")" << setw(10) << Array[i].code << "\t" << setw(30) << left << Array[i].name << right << setprecision(2) << fixed << setw(10) << Array[i].price;
		if (decisionCategory == 3)
			cout << setw(10) << Array[i].soldNum;
		cout << endl;
	}
}

void MilkTea::searchMenu(int& decisionCategory, int& endPoint)
{
	char desicionResearch;
	string searchName;
	double searchPrice;
	ifstream infile("AllMenu.txt");
	for (int i = 0; infile >> Array[i].code >> Array[i].name >> Array[i].price >> Array[i].soldNum; i++) {}
	infile.close();
	cout << "\t\t  CATEGORY OF SEARCH\n" << endl;
	cout << "\t(1)	Search by Drink's Name" << endl;
	cout << "\t(2)	Search by Drink's Price" << endl;
	cout << "\n*Press other key to go back to main menu*" << endl;
	cout << "Please choose the category : ";
	cin >> decisionCategory;
SEARCH:
	switch (decisionCategory)
	{
	case 1:
		//use the string compare algorithm
		cout << "\tPlease enter the drink's name you want to search (CAPITAL FORM ONLY): ";
		cin >> searchName;
		endPoint = 0; //record the quantity of search result
		for (int i = 0; i < MENU_SIZE; i++)
		{
			if (Array[i].name.size() >= searchName.size())
			{
				for (int j = 0; j <= Array[i].name.size() - searchName.size(); j++)
				{
					if (Array[i].name.compare(j, searchName.size(), searchName) == 0)
					{
						Array[endPoint] = Array[i]; //move the selected element to the front of array
						endPoint++;
						break;
					}
				}
			}
		}
		break;

	case 2:
	SEARCH_PRICE:
		cout << "\tPlease enter the drink's price you want to search: ";
		cin >> searchPrice;
		if (searchPrice < 0 || cin.fail())
		{
			cout << "\tInvalid input! Please enter again.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			goto SEARCH_PRICE;
		}

		//use bubble sort to sort the array first
		for (int a = 0; a < MENU_SIZE - 1; a++)
		{
			for (int b = 0; b < MENU_SIZE - 1 - a; b++)
			{
				if (Array[b].price > Array[b + 1].price)
				{
					order temp = Array[b];
					Array[b] = Array[b + 1];
					Array[b + 1] = temp;
				}
			}
		}

		//search by Sequantial Search : Ordered List
		//algorithm of Ordered List Searching used
		//bool Sequential::SequentialSearch(int array[], int SIZE, int target, int& locWanted) {
		//	int index;
		//	bool found;
		//	if (target < array[SIZE - 1]) {
		//		index = 0;
		//		while (target > array[index])
		//			index++;
		//	}
		//	else
		//		index = SIZE - 1;
		//	if (target == array[index])
		//		found = true;
		//	else
		//		found = false;
		//	locWanted = index;
		//	return found;
		//}

		if (searchPrice < Array[MENU_SIZE - 1].price)
		{
			endPoint = 0;
			while (searchPrice >= Array[endPoint].price)
				endPoint++;
		}
		else
			endPoint = MENU_SIZE;
		break;

	default: return;
	}
	if (endPoint == 0)
	{
		cout << "Target not found! Please enter new target.\n";
		goto SEARCH;
	}
	else
	{
		system("cls");
		cout << endl << setfill(' ') << "\t\tOPTION" << setw(8) << "CODE\t" << setw(30) << left << "DRINK'S NAME" << right << setw(12) << "PRICE(RM)" << endl;
		for (int i = 0; i < endPoint; i++)
			cout << "\t\t" << setw(2) << i + 1 << ")" << setw(10) << Array[i].code << "\t" << setw(30) << left << Array[i].name << right << setprecision(2) << fixed << setw(10) << Array[i].price << endl;

		cout << endl << "There are " << endPoint << " result(s) ";
		switch (decisionCategory)
		{
		case 1: cout << "which contains the \"" << searchName << "\""; break;
		case 2: cout << "which below or equal RM " << fixed << setprecision(2) << searchPrice; break;
		}
		cout << " had found.\n";

	RESEARCH:
		cout << "Do you want to research? (Y/N): ";
		cin >> desicionResearch;
		if (desicionResearch == 'Y' || desicionResearch == 'y')
			goto SEARCH;
		else if (desicionResearch != 'Y' && desicionResearch != 'y'&&desicionResearch != 'N' && desicionResearch != 'n')
		{
			cout << "\tInvalid input! Please enter again based on the selection given.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			goto RESEARCH;
		}
	}
}

void MilkTea::cancelOrder()
{
	int endPoint, decisionCategory;
	char decisionDelete;
	bool pass = false;
	bool passUndo = false;
	order *ptraverse;
	order *pbefore = NULL;
	order *pdelete = NULL;

DELETE:
	if (phead == NULL)
	{
		cout << "You have no drinks ordered!\n";
		if (pdelete != NULL)
		{
			cout << "The order had cancelled!\n";
			cout << "Enter X for undo or other key to go back to main menu: ";
			cin >> decisionDelete;
			if (decisionDelete != 'X' && decisionDelete != 'x')
				return;
			goto UNDO;
		}
		system("pause");
		return;
	}
	else
	{
		ptraverse = phead;
		cout << "\tDRINK(s) YOUR ORDERED " << endl;
		cout << "OPTION" << setw(8) << "CODE\t" << setw(30) << left << "DRINK'S NAME" << right << setw(12) << "PRICE(RM)" << setw(12) << "SUGAR(%)" << setw(10) << "ICE" << setw(25) << "ADD-ON(s)" << endl;
		for (endPoint = 0; ptraverse != NULL; endPoint++, ptraverse = ptraverse->next)
		{
			cout << setw(2) << endPoint + 1 << ")" << setw(10) << ptraverse->code << "\t" << setw(30) << left << ptraverse->name << right << setprecision(2) << fixed << setw(10) << ptraverse->price;
			cout << setw(11) << ptraverse->sugar << setw(16) << ptraverse->ice << setw(19);

			//to cout add-on in different situation (assume add-on items can repeat)
			if (ptraverse->addOn[0] != "" && ptraverse->addOn[1] != "" && ptraverse->addOn[2] != "") //if three addOn string are not empty
			{
				if (ptraverse->addOn[0] == ptraverse->addOn[1] && ptraverse->addOn[0] == ptraverse->addOn[2])
					cout << ptraverse->addOn[0] << " x 3" << endl;
				else if (ptraverse->addOn[0] == ptraverse->addOn[1])
					cout << ptraverse->addOn[0] << " x 2" << endl << setw(102) << ptraverse->addOn[2] << " x 1" << endl;
				else if (ptraverse->addOn[0] == ptraverse->addOn[2])
					cout << ptraverse->addOn[0] << " x 2" << endl << setw(102) << ptraverse->addOn[1] << " x 1" << endl;
				else
					cout << ptraverse->addOn[0] << " x 1" << endl << setw(102) << ptraverse->addOn[1] << " x 1" << endl << setw(102) << ptraverse->addOn[2] << " x 1" << endl;
			}
			else if (ptraverse->addOn[0] != "" && ptraverse->addOn[1] != "" && ptraverse->addOn[2] == "") //if both of addOn string are not empty
			{
				if (ptraverse->addOn[0] == ptraverse->addOn[1])
					cout << ptraverse->addOn[0] << " x 2" << endl;
				else
					cout << ptraverse->addOn[0] << " x 1" << endl << setw(102) << ptraverse->addOn[1] << " x 1" << endl;
			}
			else if (ptraverse->addOn[0] != "" && ptraverse->addOn[1] == "" && ptraverse->addOn[2] == "") //if only one addOn string is not empty
				cout << ptraverse->addOn[0] << " x 1" << endl;
			else if (ptraverse->addOn[0] == "" && ptraverse->addOn[1] == "" && ptraverse->addOn[2] == "") //if all addOn string are empty
				cout << "*No Add-on*" << endl;
		}

		if (pass) //prenvent enter this selection in first the delete action
		{
			cout << "The order had cancelled! (Enter X to undo)\n";
		REDELETE1:
			cout << "Do you want to cancel other order? (Y/N/X): ";
			cin >> decisionDelete;
			switch (decisionDelete)
			{
			case 'X': case 'x':
			UNDO:
				if (pdelete->next == phead)
					phead = pdelete;
				else
					pbefore->next = pdelete;
				pass = false;
				passUndo = true;
				system("cls");
				goto DELETE;

			case 'Y': case 'y': delete pdelete; break;
			case 'N': case 'n': delete pdelete; return;
			default:
				cout << "\tInvalid input! Please enter again.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				goto REDELETE1;
			}
		}
		else if (passUndo)
		{
			cout << "The delete action had undo!\n";
		REDELETE2:
			cout << "Do you want to cancel other order? (Y/N): ";
			cin >> decisionDelete;
			switch (decisionDelete)
			{
			case 'Y': case 'y': break;
			case 'N': case 'n': return;
			default:
				cout << "\tInvalid input! Please enter again.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				goto REDELETE2;
			}
		}

		cout << "\n*Press other key to go back to main menu*" << endl;
		cout << "Please choose the drinks that you want to cancel: ";
		cin >> decisionCategory;
		if (decisionCategory < 1 || decisionCategory > endPoint || cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return;
		}
		pdelete = phead;
		for (int i = 1; i < decisionCategory; i++)
		{
			pbefore = pdelete;
			pdelete = pdelete->next;
		}
		if (pdelete == phead)
			phead = phead->next;
		else
			pbefore->next = pdelete->next;
		system("cls");
		pass = true;
		passUndo = false;
		goto DELETE;
	}
}

void MilkTea::printReceipt()
{

	order *ptraverse = phead;
	double totalPrice = 0;
	fstream file;

	file.open("AllMenu.txt", ios::in);
	for (int i = 0; file >> Array[i].code >> Array[i].name >> Array[i].price >> Array[i].soldNum; i++) {}
	file.close();

	cout << "\tYOUR ORDERED DRINK(s)" << endl;
	cout << "ORDER" << setw(8) << "CODE\t" << setw(30) << left << "DRINK'S NAME" << right << setw(12) << "PRICE(RM)" << setw(12) << "SUGAR(%)" << setw(10) << "         ICE" << setw(20) << "ADD-ON(s)" << endl;
	for (int i = 0; ptraverse != NULL; i++, ptraverse = ptraverse->next)
	{
		cout << setw(2) << i + 1 << ")" << setw(10) << ptraverse->code << "\t" << setw(30) << left << ptraverse->name << right << setprecision(2) << fixed << setw(10) << ptraverse->price;
		cout << setw(11) << ptraverse->sugar << setw(16) << ptraverse->ice << setw(19);

		if (ptraverse->addOn[0] != "" && ptraverse->addOn[1] != "" && ptraverse->addOn[2] != "")
		{
			if (ptraverse->addOn[0] == ptraverse->addOn[1] && ptraverse->addOn[0] == ptraverse->addOn[2])
				cout << ptraverse->addOn[0] << " x 3" << endl;
			else if (ptraverse->addOn[0] == ptraverse->addOn[1])
				cout << ptraverse->addOn[0] << " x 2" << endl << setw(102) << ptraverse->addOn[2] << " x 1" << endl;
			else if (ptraverse->addOn[0] == ptraverse->addOn[2])
				cout << ptraverse->addOn[0] << " x 2" << endl << setw(102) << ptraverse->addOn[1] << " x 1" << endl;
			else
				cout << ptraverse->addOn[0] << " x 1" << endl << setw(102) << ptraverse->addOn[1] << " x 1" << endl << setw(102) << ptraverse->addOn[2] << " x 1" << endl;
		}
		else if (ptraverse->addOn[0] != "" && ptraverse->addOn[1] != "" && ptraverse->addOn[2] == "")
		{
			if (ptraverse->addOn[0] == ptraverse->addOn[1])
				cout << ptraverse->addOn[0] << " x 2" << endl;
			else
				cout << ptraverse->addOn[0] << " x 1" << endl << setw(102) << ptraverse->addOn[1] << " x 1" << endl;
		}
		else if (ptraverse->addOn[0] != "" && ptraverse->addOn[1] == "" && ptraverse->addOn[2] == "")
			cout << ptraverse->addOn[0] << " x 1" << endl;
		else if (ptraverse->addOn[0] == "" && ptraverse->addOn[1] == "" && ptraverse->addOn[2] == "")
			cout << setw(20) << right << "*No Add-on*" << endl;
		totalPrice += ptraverse->price;

		//update sold quantity
		file.open("AllMenu.txt", ios::out);
		for (int j = 0; j < MENU_SIZE; j++)
		{
			if (Array[j].code == ptraverse->code)
				Array[j].soldNum++;
			file << Array[j].code << " " << left << setw(35) << Array[j].name << " " << right << setw(5) << fixed << setprecision(2) << Array[j].price << " " << setw(3) << Array[j].soldNum << endl;
		}
		file.close();
	}
	cout << setfill('_') << setw(106) << "\n";
	cout << "TOTAL PRICE" << setfill(' ') << setw(40) << setprecision(2) << fixed << "RM " << totalPrice << endl;

	ptraverse = phead;
	file.open("Receipt.txt", ios::out);
	file << "\tYOUR ORDERED DRINK(s)" << endl;
	file << "ORDER" << setw(8) << "CODE\t" << setw(30) << left << "DRINK'S NAME" << right << setw(12) << "PRICE(RM)" << setw(12) << "SUGAR(%)" << setw(10) << "         ICE" << setw(20) << "ADD-ON(s)" << endl;
	for (int i = 0; ptraverse != NULL; i++, ptraverse = ptraverse->next)
	{
		file << setw(2) << i + 1 << ")" << setw(10) << ptraverse->code << "\t" << setw(30) << left << ptraverse->name << right << setprecision(2) << fixed << setw(10) << ptraverse->price;
		file << setw(11) << ptraverse->sugar << setw(16) << ptraverse->ice << setw(19);

		if (ptraverse->addOn[0] != "" && ptraverse->addOn[1] != "" && ptraverse->addOn[2] != "")
		{
			if (ptraverse->addOn[0] == ptraverse->addOn[1] && ptraverse->addOn[0] == ptraverse->addOn[2])
				file << ptraverse->addOn[0] << " x 3" << endl;
			else if (ptraverse->addOn[0] == ptraverse->addOn[1])
				file << ptraverse->addOn[0] << " x 2" << endl << setw(102) << ptraverse->addOn[2] << " x 1" << endl;
			else if (ptraverse->addOn[0] == ptraverse->addOn[2])
				file << ptraverse->addOn[0] << " x 2" << endl << setw(102) << ptraverse->addOn[1] << " x 1" << endl;
			else
				file << ptraverse->addOn[0] << " x 1" << endl << setw(102) << ptraverse->addOn[1] << " x 1" << endl << setw(102) << ptraverse->addOn[2] << " x 1" << endl;
		}
		else if (ptraverse->addOn[0] != "" && ptraverse->addOn[1] != "" && ptraverse->addOn[2] == "")
		{
			if (ptraverse->addOn[0] == ptraverse->addOn[1])
				file << ptraverse->addOn[0] << " x 2" << endl;
			else
				file << ptraverse->addOn[0] << " x 1" << endl << setw(102) << ptraverse->addOn[1] << " x 1" << endl;
		}
		else if (ptraverse->addOn[0] != "" && ptraverse->addOn[1] == "" && ptraverse->addOn[2] == "")
			file << ptraverse->addOn[0] << " x 1" << endl;
		else if (ptraverse->addOn[0] == "" && ptraverse->addOn[1] == "" && ptraverse->addOn[2] == "")
			file << setw(20) << right << "*No Add-on*" << endl;
	}
	file << setfill('_') << setw(106) << "\n";
	file << "TOTAL PRICE" << setfill(' ') << setw(40) << setprecision(2) << fixed << "RM " << totalPrice << endl;
	file.close();
}

void MilkTea::makeOrder(int& decisionMakeOrder, int endPoint)
{
	pnew = new order; //create new node
	cout << "\n\n**You may press other key to cancel the order**" << endl;
	cout << "Please choose your desired order		: ";
	cin >> decisionMakeOrder;
	if (decisionMakeOrder >= 1 && decisionMakeOrder <= endPoint)
	{
		//insert the data of order make by user 
		pnew->code = Array[decisionMakeOrder - 1].code;
		pnew->name = Array[decisionMakeOrder - 1].name;
		pnew->price = Array[decisionMakeOrder - 1].price;
		//connect the new node into linked list according to the situation below
		if (phead == NULL)
		{
			pnew->next = phead;
			phead = pnew;
		}
		else
		{
			pnew->next = pcurrent->next;
			pcurrent->next = pnew;
		}
		pcurrent = pnew;
		numItem++;
	}
	else
		cout << "This order had been cancelled..." << endl;
}

void MilkTea::customize()
{
	system("cls");
	char decisionAddOn;
	int decisionSugar, decisionIce, decisionAddOnItem;

	//update the sugar in the last node of the linked list
	cout << "Please choose your options for the amount of the sugar\n";
	cout << "\t(1)	125% \n\t(2)	100% \n\t(3)	75% \n\t(4)	50% \n\t(5)	No sugar\n";
SUGAR:
	cout << "How many percentage of sugar do you want in your drink?: ";
	cin >> decisionSugar;
	switch (decisionSugar)
	{
	case 1: pcurrent->sugar = 125;	break;
	case 2: pcurrent->sugar = 100;	break;
	case 3: pcurrent->sugar = 75;	break;
	case 4: pcurrent->sugar = 50;	break;
	case 5: pcurrent->sugar = 0;	break;
	default:
		cout << "\tInvalid input! Please enter again beased on the number given above.\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		goto SUGAR;
	}

	//update the ice in the last node of the linked list
	cout << "\nPlease choose the option for the amount of ice\n";
	cout << "\t(1)	Extra More\n\t(2)	More\n\t(3)	Normal\n\t(4)	Less\n\t(5)	No ice\n";
ICE:
	cout << "How many ice do you want in your drink?: ";
	cin >> decisionIce;
	switch (decisionIce)
	{
	case 1: pcurrent->ice = "Extra More";	break;
	case 2: pcurrent->ice = "More";			break;
	case 3: pcurrent->ice = "Normal";		break;
	case 4: pcurrent->ice = "Less";			break;
	case 5: pcurrent->ice = "No Ice";		break;
	default:
		cout << "\tInvalid input! Please enter again beased on the number given above.\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		goto ICE;
	}

	//update the add-on in the last node of the linked list
	cout << "\nPlease choose the option for your Add-On\n";
	cout << "\t(1) Boba\t\t\t\tRM 1.00\n";
	cout << "\t(2) Grass Pudding\t\t\tRM 1.00\n";
	cout << "\t(3) Pudding\t\t\t\tRM 1.00\n";
	cout << "\t(4) Coconut Jelly\t\t\tRM 1.00\n";
	cout << "\t(5) Ice cream\t\t\t\tRM 1.00\n";
	cout << "\t(6) No Add-On\n";
	do
	{
	ADD_ON_ITEM:
		cout << "What do you want to add-on? (You can only choose " << 3 - pcurrent->addOnNum << " now): ";
		cin >> decisionAddOnItem;
		switch (decisionAddOnItem)
		{
		case 1: pcurrent->addOn[pcurrent->addOnNum] = "Boba";			break;
		case 2: pcurrent->addOn[pcurrent->addOnNum] = "Grass Pudding";	break;
		case 3: pcurrent->addOn[pcurrent->addOnNum] = "Pudding";		break;
		case 4: pcurrent->addOn[pcurrent->addOnNum] = "Coconut Jelly";	break;
		case 5: pcurrent->addOn[pcurrent->addOnNum] = "Ice cream";		break;
		case 6: return;
		default:
			cout << "\tInvalid input! Please enter again based on the number given above.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			goto ADD_ON_ITEM;
		}

	ADD_ON_AGAIN:
		if (pcurrent->addOnNum < 2)
		{
			cout << "\tDo you want to Add-On again? (Y/N): ";
			cin >> decisionAddOn;
			if (decisionAddOn != 'y' && decisionAddOn != 'Y' && decisionAddOn != 'N' && decisionAddOn != 'n')
			{
				cout << "\tInvalid input! Please enter again based on the number given above.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				goto ADD_ON_AGAIN;
			}
		}
		pcurrent->addOnNum++; //update addOnNum
	} while ((decisionAddOn == 'Y' || decisionAddOn == 'y') && pcurrent->addOnNum < 3);
}

bool MilkTea::empty()
{
	return (phead == NULL);
}