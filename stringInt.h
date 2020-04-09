#include <iostream>

class stringInt
{
	private:
	//main string
	char *ptr;
	int size;
	
	public:
	//functions
	stringInt();
	stringInt(const char *);
	~stringInt();
	friend std::ostream& operator<<(std::ostream &out, stringInt &num);
};

std::ostream& operator<<(std::ostream &out, stringInt &num);

