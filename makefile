CXX = g++
CXXFLAGS = -Wall -std=c++17 -I./Ejercicio1 -I./Ejercicio2

# Archivos fuente y binario
SRC_DIRS = Ejercicio1 Ejercicio2 Ejercicio3
OBJ_DIR = obj
BIN_DIR = bin
SRC_FILES = $(wildcard Ejercicio1/*.cpp Ejercicio2/*.cpp Ejercicio3/*.cpp)
OBJ_FILES = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))
TARGET = $(BIN_DIR)/main

# Regla principal
all: $(TARGET)

# Compilación del ejecutable
$(TARGET): $(OBJ_FILES)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilación de archivos objeto
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpieza
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Ejecución
run: $(TARGET)
	./$(TARGET)