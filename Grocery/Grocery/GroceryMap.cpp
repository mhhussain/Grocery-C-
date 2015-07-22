#include <iostream>
#include "GroceryMap.h"

GroceryMap::GroceryMap(int size)
{
	tablesize = size;
	data = new HashNode*[tablesize];

	for (auto i = 0; i < tablesize; i++)
	{
		data[i] = NULL;
	}
}

GroceryMap::~GroceryMap()
{
	for (auto i = 0; i < tablesize; i++)
	{
		delete data[i];
	}

	delete[] data;
}

Product GroceryMap::Get(string key)
{
	auto hashvalue = GetHash(key);
	
	if (data[hashvalue] != NULL)
	{
		if (data[hashvalue]->key == key)
		{
			return *(data[hashvalue]->value);
		}
		else
		{
			hashvalue++;
			for (auto i = 0; i < tablesize; i++, hashvalue++)
			{
				if (data[hashvalue % tablesize]->key == key)
				{
					return *(data[hashvalue % tablesize]->value);
				}
			}
		}
	}

	throw "No product found";
}

void GroceryMap::Put(Product product)
{
	auto newproduct = new Product(product);
	auto hashvalue = GetHash(newproduct->GetName());

	if (data[hashvalue] == NULL)
	{
		auto *tempproduct = new HashNode();
		tempproduct->key = newproduct->GetName();
		tempproduct->value = newproduct;

		data[hashvalue] = tempproduct;
	}
	else if (data[hashvalue]->key == newproduct->GetName())
	{
		throw "Product already exists.";
	}
	else
	{
		hashvalue++;
		for (auto i = 0; i < tablesize; i++, hashvalue++)
		{
			if (data[hashvalue % tablesize] == NULL)
			{
				auto *tempproduct = new HashNode();
				tempproduct->key = newproduct->GetName();
				tempproduct->value = newproduct;

				data[hashvalue] = tempproduct;

				return;
			}
		}
	}
}

vector<Product> GroceryMap::Search(string searchstring)
{
	vector<Product> results;

	for (auto i = 0; i < tablesize; i++)
	{
		if (data[i] == NULL)
		{
			continue;
		}

		auto name = data[i]->value->GetName();
		auto category = data[i]->value->GetCategory();
		
		if (searchstring == name
			|| searchstring == category)
		{
			results.push_back(*(data[i]->value));
		}
	}

	return results;
}

void GroceryMap::PrintAll()
{
	for (auto i = 0; i < tablesize; i++)
	{
		if (data[i] != NULL)
		{
			cout << data[i]->value->GetName() << endl;
			cout << data[i]->value->GetCategory() << endl;
			cout << data[i]->value->GetRate() << endl;
			cout << data[i]->value->GetQuantity() << endl;
		}
	}
}

// Private
int GroceryMap::GetHash(string key)
{
	int hash = 0;
	for (auto i = 0; i < key.length(); i++)
	{
		hash += key[i];
	}

	return hash % tablesize;
}