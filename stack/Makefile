obj= main.o linkstack.o

test : $(obj)
	gcc -g $^ -o $@

main.o : main.c
	gcc -g -c $^

linkstack.o : linkstack.c
	gcc -g -c $^

.PHONY : clean
clean :
	rm -rf $(obj) test

