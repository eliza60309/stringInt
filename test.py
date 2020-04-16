from random import random
import sys

def leading_digit():
	return int(random() * 9 + 1)
def digit():
	return int(random() * 10)
def rand(length):
	if(int(random() * 2) > 1):
		sign = 1
	else:
		sign = -1
	if(length == 0):
		return 0
	elif(length == 1):
		return digit() * sign
	else:
		num = leading_digit()
		cur = 1
		while(cur < length):
			num *= 10
			num += digit()
			cur += 1
		return num * sign
def printans(*args, **kwargs):
	print(*args, file=sys.stderr, *kwargs)

def print_test():
	for i in range(150):
		num = str(rand(i))
		print("print " + num)
		printans(num)

### main ###

print_test()
