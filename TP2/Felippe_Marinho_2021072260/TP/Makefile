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

# Nome do executável
TARGET = $(BIN_DIR)/fecho

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
	@echo $(ANSI_GREEN) "Para executar o programa diretamente, digite:" $(ANSI_DEFAULT)
	@echo $(ANSI_YELLOW) "----- ./bin/fecho 'ENTRADA.txt' -----" $(ANSI_DEFAULT)
	@echo ""
	@echo $(ANSI_GREEN) "Para executar o programa e desenhar o fecho, digite:" $(ANSI_DEFAULT)
	@echo $(ANSI_YELLOW) "----- ./bin/fecho 'ENTRADA.txt' -d -----" $(ANSI_DEFAULT)
	@echo ""
	@echo $(ANSI_GREEN) "Para executar o programa e gerar os Logs para gráficos da Análise Experimental, digite:" $(ANSI_DEFAULT)
	@echo $(ANSI_YELLOW) "----- ./bin/fecho 'ENTRADA.txt' -l -----" $(ANSI_DEFAULT)
	@echo ""

# Regra para compilar e executar o programa, coloque o caminho até o arquivo de entrada 
# entre aspas após o comando. Exemplo: $(TARGET) "c:/Users/usuario/Desktop/entradas/entdouble.s1.n5.i.in"
run: all
	@$(TARGET) "../../ENTRADATESTE.txt" 
	@$(GPROF_DIR) $(TARGET) gmon.out > $(REPORT)
	@echo ""
	@echo -e -n $(ANSI_GREEN)
	@echo -n "√ "
	@echo $(ANSI_GREEN) "Relatório gerado com sucesso!" $(ANSI_DEFAULT)
	@echo ""

# Limpeza dos arquivos objetos e do executável
clean:
	@$(RM) -r $(OBJ_DIR)/* $(BIN_DIR)/* $(REPORT) coverage/* *.gcda *.gcno
	@echo ""
	@echo $(ANSI_RED) "----- Arquivos objetos e executáveis removidos! -----" $(ANSI_DEFAULT)
	@echo ""

.PHONY: clean