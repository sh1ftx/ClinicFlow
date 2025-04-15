# Diretórios
SRC_DIR := src
BUILD_DIR := build
INCLUDE_DIR := include
DATA_DIR := data

# Arquivos fonte
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(SRC_FILES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Nome do executável
EXEC := hospital_simulator

# Flags de compilação
CXX := g++
CXXFLAGS := -std=c++17 -I$(INCLUDE_DIR)

# Regras de construção
$(BUILD_DIR)/$(EXEC): $(OBJ_FILES)
	$(CXX) $(OBJ_FILES) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza
clean:
	rm -rf $(BUILD_DIR)/*

.PHONY: clean
