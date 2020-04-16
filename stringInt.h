#include <iostream>

class stringInt
{
	private:
	//main string
	bool sign;//false means >= 0 vice versa
	char *ptr;
	
	public:
	//functions
	stringInt();
	stringInt(const stringInt &);
	stringInt(const char *);
	~stringInt();
	stringInt &operator=(const stringInt &);
	stringInt &operator=(const char *);
	
	private:
	void setArray(const char *);

	friend std::ostream& operator<<(std::ostream &, const stringInt &);
	friend std::istream& operator>>(std::ostream &, const stringInt &);
};

std::ostream& operator<<(std::ostream &, const stringInt &);
std::istream& operator>>(std::istream &, stringInt &);
