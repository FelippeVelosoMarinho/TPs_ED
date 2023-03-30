#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa main.c
# Autor	: Felippe Veloso Marinho (felippe.veloso15@gmail.com)
# Historico	: 2023-28-03 - arquivo criado
#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#		: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
GPROF = gprof
OBJS = $(OBJ)/main.o $(OBJ)/fat.o $(OBJ)/fibonacci.o $(OBJ)/tmp.o
HDRS = $(INC)/fat.h $(INC)/fibonacci.h $(INC)/tmp.h
CFLAGS = -Wall -pg -c -I$(INC)
REPORT = report.txt

EXE = $(BIN)/main

run:  $(EXE) 
	$(EXE) -b -n 5
	$(EXE) -a -n 5
	$(GPROF) $(EXE) gmon.out > $(REPORT)

$(BIN)/main: $(OBJS)
	$(CC) -pg -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.c
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.c 

$(OBJ)/fat.o: $(HDRS) $(SRC)/fat.c
	$(CC) $(CFLAGS) -o $(OBJ)/fat.o $(SRC)/fat.c 

$(OBJ)/fibonacci.o: $(HDRS) $(SRC)/fibonacci.c
	$(CC) $(CFLAGS) -o $(OBJ)/fibonacci.o $(SRC)/fibonacci.c 

$(OBJ)/tmp.o: $(HDRS) $(SRC)/tmp.c
	$(CC) $(CFLAGS) -o $(OBJ)/tmp.o $(SRC)/tmp.c 

clean:
	rm -f $(EXE) $(OBJS) $(REPORT) gmon.out 
