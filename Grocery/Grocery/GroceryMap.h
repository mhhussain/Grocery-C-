#ifndef GroceryMap_h
#define GroceryMap_h

#include <vector>
#include "Product.h"

#pragma once
class GroceryMap
{
public:
	GroceryMap(int size);
	~GroceryMap();

	// Get
	Product Get(string key);

	// Put
	void Put(Product product);

	// Search
	vector<Product> Search(string searchstring);

	// Print
	void PrintAll();

private:
	struct HashNode
	{
		HashNode() { }
		string key;
		Product *value;
	};

	int GetHash(string key);

	HashNode **data;
	int tablesize;
};

#endif