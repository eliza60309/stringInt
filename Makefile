.PHONY: clean all run

all:
	g++ -o a.out main.cc stringInt.cc


clean:
	rm a.out 
clean_test:
	rm test ans myans

run:
	make all
	python test.py > test 2> ans 
	./a.out < test > myans
	make clean
	@echo 'testing'
	@diff myans ans 
	@echo 'test passed'
	make clean_test
