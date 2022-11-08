using namespace std;

template<class T>
class Record
{
private:
	int key;
	T value;

public:
	Record() 
	{
		key = -1;
		value = "NULL";
	}

	Record(int key, T value) 
	{
		this->key = key;
		this->value = value;
	}

	int getKey() 
	{
		return key;
	}

	T getValue() 
	{
		return value;
	}

	void setKey(int key)
	{
		this->key = key;
	}

	void setValue(T value) 
	{
		this->value = value;
	}

	void printrecord()
	{
		cout << "Key: " << key << endl;
		cout << "Value: " << value << endl;
	}
};
