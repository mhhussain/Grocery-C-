#include <iostream>
#include <string>
#include <vector>
#include "GroceryMap.h"
#include "Product.h"
#include "Init.h"

using namespace std;

GroceryMap *Inventory = new GroceryMap(100);

void ProgStart();
void ViewMenu();

void ProductSearch();
void AddProduct();
void EditProduct();
void ViewAll();

int main()
{
	LoadResource(Inventory);
	ProgStart();
	cout << endl;

	auto choice = 0;

	do
	{
		ViewMenu();
		cout << ":: ";
		cin >> choice;
		while (!(1 <= choice && choice <= 6))
		{
			cout << "Enter a number between 1 and 6." << endl;
			cout << ":: ";
			cin >> choice;
		}

		switch (choice)
		{
		case 1:
			ProductSearch();
			cout << endl << endl;
			break;
		case 2:
			AddProduct();
			cout << endl << endl;
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			ViewAll();
			break;
		case 6:
			break;
		default:
			break;
		}



	} while (choice != 6);


	/*
	Product a("Apple", "fruit", 0.25, 20);
	Product b("Banana", "fruit", 0.3, 20);

	//Inventory->Put(a);
	Inventory->Put(b);

	AddProduct();

	cout << "world" << endl;


	auto x = Inventory->Get("Apple");
	cout << x.GetName() << endl;
	cout << x.GetRate() << endl;
	cout << x.GetCategory() << endl;

	x.SetRate(5.5);

	cout << x.GetRate() << endl;


	cout << Inventory->Get("Banana").GetName() << endl;
	*/

	
	cout << endl << endl << endl;
	system("PAUSE");

	return 0;
}

void ProgStart()
{
	cout << "*************************************************" << endl;
	cout << "            Grocery Store Simulation" << endl;
	cout << "              by: Mohammed Hussain" << endl;
	cout << "*************************************************" << endl;
}

void ViewMenu()
{
	cout << "What would you like to do." << endl;
	cout << "[1]. Search for products" << endl;
	cout << "[2]. Add product" << endl;
	cout << "[3]. Edit product" << endl;
	cout << "[4]. Delete product" << endl;
	cout << "[5]. View all products" << endl;
	cout << "[6]. Exit" << endl;
}

void ProductSearch()
{
	cout << "Search for product by name or category." << endl;
	cout << ":: ";

	cin.ignore();
	string searchstring;
	getline(cin, searchstring);

	auto productsearch = Inventory->Search(searchstring);
	
	cout << endl;
	cout << "********* Search results *************" << endl << endl;
	for (auto i = 0; i < productsearch.size(); i++)
	{
		cout << "********* Product " << i + 1 << " *************" << endl;
		cout << "Code: " << productsearch[i].GetCode() << endl;
		cout << "Name: " << productsearch[i].GetName() << endl;
		cout << "Categoory: " << productsearch[i].GetCategory() << endl;
		cout << "Price: " << productsearch[i].GetRate() << endl;
		cout << "Quantity: " << productsearch[i].GetQuantity() << endl;
	}
	cout << "********* End Search results *********" << endl << endl;

}

void AddProduct()
{
	string name;
	string category;
	double rate;
	int quantity;

	cin.ignore();
	cout << "Name: ";
	getline(cin, name);
	cout << "Category: ";
	getline(cin, category);
	cout << "Rate: ";
	cin >> rate;
	cout << "Quantity: ";
	cin >> quantity;

	Product p(name, category, rate, quantity);

	try
	{
		Inventory->Put(p);
		cout << "Item added." << endl;
	}
	catch (string s)
	{
		cout << "Product already exists." << endl;
	}
}

void EditProduct()
{
	long code;
	cout << "Enter product code: " << endl;
	cin >> code;


}

void ViewAll()
{
	Inventory->PrintAll();
}