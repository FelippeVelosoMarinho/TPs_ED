# Compilador e flags
CXX = g++
CXXFLAGS = -g -Wall -pg -O3 -std=c++17 
INC_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./obj
TMP_DIR = ./tmp
GPROF_DIR = gprof
BIN_DIR = ./bin
REPORT = ./tmp/analise.out
COMPACTED = ./compactado.wg
DESCOMPACTED = ./descompactado.txt
TABLE_AUX = ./tmp/tabela.bin
LOG = ./tmp/huffmanLog.out

# Nome do executável
TARGET = $(BIN_DIR)/main

# Arquivos fonte e objetos
SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))

# Cores para o terminal
ANSI_RED = '\033[0;31m'     #cd3131
ANSI_GREEN = '\033[0;32m'   #0dbd79
ANSI_YELLOW = '\033[0;33m'  #e5e510
ANSI_DEFAULT = '\033[0;0m'  #


# Regra default
all: $(TARGET)
	@$(GPROF_DIR) $(TARGET) gmon.out > $(REPORT)

# Regra de compilação
 $(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@
	@echo $(ANSI_YELLOW) "Compilando o arquivo $<..." $(ANSI_DEFAULT)

# Regra de ligação
$(TARGET): $(OBJECTS)
	@$(CXX) $(CXXFLAGS) $^ -o $@ -lgraph
	@echo $(ANSI_YELLOW) "Gerando o executável $@..." $(ANSI_DEFAULT)
	@echo ""
	@echo -e -n $(ANSI_GREEN)
	@echo -n " √ "
	@echo $(ANSI_GREEN) "Concluído!" $(ANSI_DEFAULT)
	@echo ""
	@echo $(ANSI_GREEN) "Para executar o programa e compactar, digite:" $(ANSI_DEFAULT)
	@echo $(ANSI_YELLOW) "----- ./bin/main 'TEXTO.txt' 'INFO_ARQUIVO.txt' -c -----" $(ANSI_DEFAULT)
	@echo ""

# Regra para compilar e executar o programa, coloque o caminho até o arquivo de entrada 
# entre aspas após o comando. Exemplo: $(TARGET) "c:/Users/usuario/Desktop/entradas/text.txt" "c:/Users/usuario/Desktop/entradas/INFO_ARQUIVO.txt" -c
run: all
	@$(TARGET) 'TEXTO.txt' 'INFO_ARQUIVO.txt' -c
	@$(GPROF_DIR) $(TARGET) gmon.out > $(REPORT)
	@echo ""
	@echo -e -n $(ANSI_GREEN)
	@echo -n "√ "
	@echo $(ANSI_GREEN) "Relatório gerado com sucesso!" $(ANSI_DEFAULT)
	@echo ""

# Limpeza dos arquivos objetos e do executável
clean:
	@$(RM) -r $(OBJ_DIR)/* $(BIN_DIR)/* $(COMPACTED) $(DESCOMPACTED) $(LOG) $(TABLE_AUX) $(REPORT) coverage/* *.gcda *.gcno
	@echo ""
	@echo -e -n $(ANSI_RED)
	@echo -n "X "
	@echo $(ANSI_RED) "Arquivos objetos e executáveis removidos!" $(ANSI_DEFAULT)
	@echo ""

.PHONY: clean