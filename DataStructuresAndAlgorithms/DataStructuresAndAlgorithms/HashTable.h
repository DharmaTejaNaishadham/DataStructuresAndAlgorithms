#include <iostream>
#include <string>
using namespace std;

const int HashTableSize = 15;

class HashTable
{
	string key[HashTableSize];
	int value[HashTableSize];

public:
	HashTable()
	{		
		for (int i = 0; i < HashTableSize; i++)
		{
			key[i] = "";
			value[i] = 0;
		}
	}

	void PrintHashTable();	

	string addKeyValue(string keypassed);	

	void addKeyValue(string keypassed, int data);

	int getKeyValue(string keypassed);
};





