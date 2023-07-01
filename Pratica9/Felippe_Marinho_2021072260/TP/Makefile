# Compilador e flags
CXX = g++
CXXFLAGS = -g --coverage -Wall -pg -O3 -std=c++17
INC_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./obj
BIN_DIR = ./bin
TMP_DIR = ./tmp
GPROF_DIR = gprof
REPORT = report.txt

# Nome do executável
TARGET = $(BIN_DIR)/main

# Arquivos fonte e objetos
SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))

# Regra default
all: $(TARGET)

# Regra de compilação
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

# Regra de ligação
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Regra para compilar e executar o programa
run: all
	$(TARGET) 
	$(GPROF_DIR) $(TARGET) gmon.out > $(REPORT)

# Limpeza dos arquivos objetos e do executável
clean:
	$(RM) -r $(TMP_DIR)/* $(OBJ_DIR)/* $(BIN_DIR)/* $(REPORT) coverage/* *.gcda *.gcno

.PHONY: clean