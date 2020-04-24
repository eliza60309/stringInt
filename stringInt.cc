#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include "stringInt.h"

stringInt::stringInt()
{
	(*this).ptr = (char *)std::malloc(2);
	(*this).ptr[0] = '0';
	(*this).ptr[1] = '\0';
	(*this).sign = false;
}

stringInt::stringInt(const stringInt &num)
{
	(*this).setArray(num.ptr);
	(*this).sign = num.sign;
}

stringInt::stringInt(const char *c)
{
	(*this).setArray(c);

}

stringInt::~stringInt()
{
	std::free((*this).ptr);
}

stringInt &stringInt::operator=(const stringInt &num)
{
	(*this).setArray(num.ptr);
	return *this;
}

stringInt &stringInt::operator=(const char *c)
{
	(*this).setArray(c);
	return *this;
}

/*stringInt &stringInt::operator+(const stringInt &num)
{
	if(num.sign == (*this).sign)return (*this).add(num);
	else return (*this).sub(num);
}*/

void stringInt::setArray(const char *c)
{
	bool lead_zero = true, number = false;
	std::vector<char> v;
	(*this).sign = false;
	for(int i = 0; c[i] != '\0'; i++)
	{
		if(c[i] >= '0' && c[i] <= '9')
		{
			number = true;
			if(!lead_zero)v.push_back(c[i]);
			else if(c[i] > '0')
			{
				lead_zero = false;
				v.push_back(c[i]);
			}
		}
		else if(!number && c[i] == '-')(*this).sign = true;
		else break;
	}
	if(v.empty())v.push_back('0');
	(*this).ptr = (char *)std::malloc(v.size() + 1);
	*(*this).ptr = '0';
	for(int i = 0; i < v.size(); i++)
		(*this).ptr[i] = v[v.size() - i - 1];
	(*this).ptr[v.size()] = '\0'; 
}

bool stringInt::greater(const stringInt &num)
{
	int size = 0;
	for(int i = 0;; i++)
	{
		if((*this).ptr[i] == 0)
		{
			if(num.ptr[i] == 0)
			{
				size = i;
				break;
			}
			else return false;
		}
		else if(num.ptr[i] == 0)return true;
	}
	for(int i = size; i >= 0; i--)
	{
		if((*this).ptr[i] > num.ptr[i])return true;
		else if((*this).ptr[i] < num.ptr[i])return false;
	}
	return false;
}

std::ostream& operator<<(std::ostream &out, const stringInt &num)
{
	int size = 0;
	if(num.sign)out << "-";
	for(int i = 0; num.ptr[i] != '\0'; i++)size++;
	for(int i = 0; i < size; i++)
	{
		out << num.ptr[size - i - 1];
	}
	return out;
}

std::istream& operator>>(std::istream &in, stringInt &num)
{
	std::string s;
	char c;
	if(!in.eof())
	{
		in >> c;
		if(in.good())
		{
			if(c == '-')s.push_back(c);
			else in.putback(c);
		}
	}
	while(!in.eof())
	{
		if(std::isdigit(in.peek()))
		{
			in >> c;
			s.push_back(c);
		}
		else break;
	/*
		if(in.peek() == '\n')break;
		in >> c;
		if(in.fail())break;
		if(std::isdigit(c))s.push_back(c);
		else
		{
			in.putback(c);
			break;
		}
	*/
	}
	num = s.c_str();
	return in;
}
