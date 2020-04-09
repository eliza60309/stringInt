#include <iostream>
#include "stringInt.h"

stringInt::stringInt()
{
	(*this).ptr = (char *)std::malloc(1);
	(*this).ptr[0] = '0';
}

stringInt::stringInt(const char *c)
{
	(*this).size = 0;
	int string_size = 0;
	bool lead_zero = true;
	int last_lead_zero = -1;
	for(int i = 0; c[i] != '\0'; i++)
	{
		string_size++;
		if(c[i] >= '0' && c[i] <= '9')
		{
			if(!lead_zero)(*this).size++;
			else if(c[i] > '0')
			{
				lead_zero = false;
				(*this).size++;
			}
			else last_lead_zero = i;
		}
		else
		{
			break;
		}
	}
	if(lead_zero)
	{
		(*this).size = 1;
	}
	(*this).ptr = (char *)std::malloc((*this).size);
	*(*this).ptr = '0';
	for(int i = 0, j = string_size - 1; j != last_lead_zero; j--)
	{
		if(c[i] >= '0' && c[i] <= '9')
		{
			(*this).ptr[i] = c[j];
			i++;
		}
	}
}

stringInt::~stringInt()
{
	std::free((*this).ptr);
}

std::ostream& operator<<(std::ostream &out, stringInt &num)
{
	for(int i = 0; i < num.size; i++)
	{
		out << num.ptr[num.size - i - 1];
	}
	return out;
}
