CC=gcc
SOURCE=crfc4648_tests.c
OBJ=$(SOURCE:.c=.o)
EXE=crfc4648_tests

all: $(EXE) clean execute

$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $@

.o: .c
	$(CC) -c $< -o $@

clean:
	rm -rf $(OBJ)

execute:
	./$(EXE)