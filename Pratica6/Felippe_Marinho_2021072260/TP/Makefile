# Compilador e flags
CXX = g++
CXXFLAGS = -g --coverage -Wall -O3 -std=c++17
INC_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./obj
BIN_DIR = ./bin

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

# Limpeza dos arquivos objetos e do executável
clean:
	$(RM) -r $(OBJ_DIR)/* $(BIN_DIR)/* coverage/* *.gcda *.gcno

.PHONY: clean