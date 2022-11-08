#include <iostream>
#include <string>

#include "HashTable.h"

using namespace std;

int main() 
{

	HashTable<string> ht;

	string value;
	string hello = "hello";

	int collisions = 0;
	
	/*for (int i = 0; i < 100; i++)
	{
		ht.insert(i, hello, collisions);
		if (i % 10 == 0) 
		{
			cout << "Collisions so far: " << collisions << endl;
			cout << "Current alpha: " << ht.alpha() << endl;
		}
		
	}*/
	for (int i = 0; i < 100; i++) 
	{
		int random = rand() % 1000;
		ht.insert(random, hello, collisions);
		if (i % 10 == 0) 
		{
			cout << "Collisions so far: " << collisions << endl;
			cout << "Current alpha: " << ht.alpha() << endl;
		}
	}


}

