#include "HashTable.h"

void HashTable::PrintHashTable()
{
	for (int i = 0; i < HashTableSize; i++)
	{
		cout << "#" << i << "\tKey:" << key[i] << "\tValue:" << value[i] << "\n";
	}
}

string HashTable::addKeyValue(string keypassed)
{
	for (int i = 0; i < HashTableSize; i++)
	{
		//1st entry of the key
		if (key[i] == "")
		{
			key[i] = keypassed;
			value[i] = 1;

			return "";
		}

		//collision :O
		else if (key[i] == keypassed)
		{
			value[i] += 1;

			return keypassed;
		}
	}
}

void HashTable::addKeyValue(string keypassed, int data)
{
	for (int i = 0; i < HashTableSize; i++)
	{
		//1st entry of the key
		if (key[i] == "")
		{
			key[i] = keypassed;
			value[i] = data;

			break;
		}

		//collision :O
		else if (key[i] == keypassed)
		{
			value[i] += data;

			break;
		}
	}
}

int HashTable::getKeyValue(string keypassed)
{
	for (int i = 0; i < HashTableSize; i++)
	{
		if (strcmp((char*)key[i].c_str(), (char*)keypassed.c_str()) == 0)
		{
			return value[i];
		}
	}

	return NULL;
}