#ifndef Product_h
#define Product_h

#include <string>
using namespace std;

#pragma once
class Product
{
public:
	//Product();
	Product(string name, string category,
		double rate, int quantity);
	Product(const Product &item);
	~Product();

	// Rate
	double GetRate();
	void SetRate(double newRate);
	
	// Quantity
	int GetQuantity();
	void IncrementQuantity(int amount);
	void SetQuantity(int amount);

	// Name - Non edittable
	string GetName();

	// Category - Non edittable
	string GetCategory();

	// Code - Non edittable
	long GetCode();

private:
	double rate;
	int quantity;
	string name;
	string category;
	long long code;
};

#endif