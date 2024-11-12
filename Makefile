CC=gcc
SOURCE=cbasex.c
OBJ=$(SOURCE:.c=.o)
EXE=cbasex

all: $(EXE) clean execute

$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $@

.o: .c
	$(CC) -c $< -o $@

clean:
	rm -rf $(OBJ)

execute:
	./$(EXE)