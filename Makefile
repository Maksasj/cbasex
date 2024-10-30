CC=gcc
SOURCE=crfc4648_example.c
OBJ=$(SOURCE:.c=.o)
EXE=crfc4648_example

all: $(EXE) clean execute

$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $@

.o: .c
	$(CC) -c $< -o $@

clean:
	rm -rf $(OBJ)

execute:
	./$(EXE)