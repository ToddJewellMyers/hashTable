//Todd J Myers

#include <iostream>
#include <queue>
#include "Record.h"

using namespace std;

#define MAXHASH 1000

template <class T>
class HashTable
{
private:
	Record<T> array[MAXHASH];
public:
	template<class T>
	friend ostream& operator<<(ostream& os, const HashTable<T>& ht);

	HashTable()
	{

	}

	bool insert(int key, T value, int& collisions)
	{
		T duplicate;
		if (key < 0 || find(key, duplicate) == true)
		{
			return false;
		}
		else 
		{
			Record<T> newrecord(key, value);

			int index = hashmodulo(key); //HASH1 FUNCTION CALL
			//int index = hashknuth(key); //HASH2 FUNCTION CALL

			//table slot is taken, find new index
			if (array[index].getKey() != -1)
			{
				collisions++;

				int newindex = probelinear(index, collisions); //PROBE1 FUNCTION CALL
				//int newindex = probequadratic(index, collisions); //PROBE2 FUNCTION CALL

				//table is full
				if (newindex == -1)
				{
					return false;
				}
				//suitable slot found, insert
				else
				{
					array[newindex] = newrecord;
					return true;
				}

			}
			//table slot is not taken, insert
			else 
			{
				array[index] = newrecord;
				return true;
			}
		}
	}

	bool remove(int key, T& value)
	{
		int index = hashmodulo(key);
		//int index = hashknuth(key);
		if (array[index].getKey() == key) 
		{
			value = array[index].getValue();
			array[index].setKey(-1);
			array[index].setValue("NULL");
			return true;
		}
		else 
		{
			for (int i = 0; i < MAXHASH; i++) 
			{
				if (array[i].getKey() == key)
				{
					value = array[i].getValue();
					array[i].setKey(-1);
					array[i].setValue("NULL");
					return true;
				}
			}
			return false;
		}
	}

	bool find(int key, T& value) 
	{
		int index = hashmodulo(key);
		//int index = hashknuth(key);
		if (array[index].getKey() == key)
		{
			value = array[index].getValue();
			return true;
		}
		else 
		{
			for (int i = 0; i < MAXHASH; i++)
			{
				if (array[i].getKey() == key) 
				{
					value = array[i].getValue();
					return true;
				}
			}
			return false;
		}
	}

	float alpha() 
	{
		int entries = 0;
		for (int i = 0; i < MAXHASH; i++)
		{
			if (array[i].getKey() != -1)
			{
				entries++;
			}
		}

		return (float)entries / (float)MAXHASH;
	}

	Record<T>* getArray() 
	{
		return array;
	}

	int getMAXHASH() 
	{
		return MAXHASH;
	}

	//HASH/PROBE FUNCTIONS
	// 
	//hash function 1: modulo
	int hashmodulo(int key)
	{
		return key % MAXHASH;
	}

	//hash function 2: knuth variation of modulo
	int hashknuth(int key)
	{
		return (key * (key + 3)) % MAXHASH;
	}

	//probe function 1: linear
	int probelinear(int index, int& collisions)
	{
		//probe from index given by hash to end of list
		for (int i = index + 1; i < MAXHASH; i++) 
		{
			if (array[i].getKey() == -1) 
			{
				return i;
			}
			collisions++;
		}
		//probe from beginning of list to index given by hash
		for (int i = 0; i < index; i++)
		{
			if (array[i].getKey() == -1) 
			{
				return i;
			}
			collisions++;
		}
		return -1;
	}

	//probe function 2: quadratic
	int probequadratic(int index, int& collisions) 
	{
		for (int i = 0; i < MAXHASH; i++) 
		{
			int newindex = (index + i * i) % MAXHASH;
			if (array[newindex].getKey() == -1)
			{
				return newindex;
			}
			collisions++;
		}
		return -1;
	}
};

template <class T> ostream& operator<<(ostream& os, const HashTable<T>& ht)
{
	HashTable<T> hashtable = ht;

	for (int i = 0; i < hashtable.getMAXHASH(); i++) 
	{
		if (hashtable.getArray()[i].getKey() != -1)
		{
			os << "Index: " << i << "     Key: " << hashtable.getArray()[i].getKey() << "  Value: " << hashtable.getArray()[i].getValue() << endl;
		}
	}

	return os;
}
