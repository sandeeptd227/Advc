SRC:= $(wildcard *.c)
OBJ:= $(patsubst *.c, *.o, $(SRC)) 

insertion.exe: $(OBJ)
	gcc -o $@ $^


clean:
	rm *.o *.exe

run:
	make && ./insertion.exe
