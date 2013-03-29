obj= main.o linklist.o

test : $(obj)
	gcc -g $^ -o $@

main.o : main.c
	gcc -g -c $^

linklist.o : linklist.c
	gcc -g -c $^

.PHONY : clean
clean :
	rm -rf $(obj) test

