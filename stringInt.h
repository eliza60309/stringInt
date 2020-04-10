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
	stringInt(stringInt &);
	stringInt(const char *);
	~stringInt();
	stringInt &operator=(stringInt &);
	stringInt &operator=(const char *);

	private:
	void setArray(const char *);

	friend std::ostream& operator<<(std::ostream &, stringInt &);
	friend std::istream& operator>>(std::ostream &, stringInt &);
};

std::ostream& operator<<(std::ostream &, stringInt &);
std::istream& operator>>(std::istream &, stringInt &);
