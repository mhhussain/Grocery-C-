#ifndef Init_H
#define Init_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Product.h"
#include "GroceryMap.h"
using namespace std;

void LoadResource(GroceryMap *resource)
{
	// Load initial resources
	ifstream fin;
	fin.open("PreInitData");

	vector<Product> results;

	while (!fin.eof())
	{
		string input;
		while (getline(fin, input))
		{
			stringstream sin(input);

			string item;
			double rate;
			int quantity;
			string name;
			string category;
			
			getline(sin, item, ',');
			name = item;
			getline(sin, item, ',');
			category = item;
			getline(sin, item, ',');
			rate = stod(item);
			getline(sin, item, ',');
			quantity = stoi(item);
			

			auto newproduct = new Product(name, category, rate, quantity);

			results.push_back(*newproduct);
		}
		
	}

	for (auto i = 0; i < results.size(); i++)
	{
		resource->Put(results[i]);
	}
}

#endif