SRC:= $(wildcard *.c)
OBJ:= $(patsubst *.c, *.o, $(SRC)) 

steganography.exe: $(OBJ)
	gcc -o $@ $^


clean:
	rm *.o *.exe

run:
	make && ./steganography.exe
