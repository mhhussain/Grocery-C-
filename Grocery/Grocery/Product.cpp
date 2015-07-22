#include "Product.h"

Product::Product(string name, string category, double rate, int quantity)
{
	this->name = name;
	this->category = category;
	this->rate = rate;
	this->quantity = quantity;


	string tempcode = "";
	for (auto i = 0; i < name.length(); i++)
	{
		int x = name[i];
		tempcode += to_string(x % 10);
	}

	code = stol(tempcode.substr(0, 7));

	for (auto i = 0; i < category.length(); i++)
	{
		int x = category[i];
		code += x;
	}

	code = stol(tempcode.substr(0, 7));
}

Product::Product(const Product &item)
{
	this->rate = item.rate;
	this->quantity = item.quantity;
	this->name = item.name;
	this->category = item.category;

	this->code = item.code;
}


Product::~Product()
{
}

double Product::GetRate()
{
	return rate;
}

void Product::SetRate(double newRate)
{
	rate = newRate;
}

int Product::GetQuantity()
{
	return quantity;
}

void Product::IncrementQuantity(int amount)
{
	quantity += amount;
}

void Product::SetQuantity(int amount)
{
	quantity = amount;
}

string Product::GetName()
{
	return name;
}

string Product::GetCategory()
{
	return category;
}

long Product::GetCode()
{
	return code;
}
