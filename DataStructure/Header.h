#ifndef MILKTEA_H
#define MILKTEA_H
#define MENU_SIZE 40

class MilkTea
{
private:
	struct order
	{
		string code;
		string name;
		double price;
		int soldNum; //销量 (will update at "Done")
		int sugar = 100;
		string ice = "Normal";
		string addOn[3];
		int addOnNum = 0;//加料次数 (will use for calculation of add-on) *RM1 per add-on
		order *next;
	};
	order *pnew;
	order *phead;
	order *pcurrent;
	order Array[MENU_SIZE];
	int numItem;

public:
	MilkTea();
	~MilkTea();
	void mainMenu(int&, int&);
	void sortMenu(int&, int&);
	void searchMenu(int&, int&);
	void cancelOrder();
	void printReceipt();
	void makeOrder(int&, int);
	void customize();
	bool empty();
};
#endif