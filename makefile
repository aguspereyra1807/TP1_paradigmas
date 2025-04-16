CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic -std=c++17 -I./Ejercicio1 -I./Ejercicio2

SRC_DIRS = Ejercicio1 Ejercicio2 Ejercicio3
OBJ_DIR = obj
BIN_DIR = bin

# Archivos fuente
SRC_FILES2 = $(filter-out Ejercicio3/fight.cpp, $(wildcard Ejercicio1/*.cpp Ejercicio2/*.cpp))
SRC_FILES3 = $(filter-out Ejercicio2/main.cpp, $(wildcard Ejercicio1/*.cpp Ejercicio2/*.cpp Ejercicio3/*.cpp))

# De source a object (.o)
OBJ_FILES2 = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES2))
OBJ_FILES3 = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES3))

# Ejecutables
TARGET2 = $(BIN_DIR)/main2
TARGET3 = $(BIN_DIR)/main3

# Regla por defecto
all: $(TARGET2) $(TARGET3)

# Regla para compilar ejercicio 2
$(TARGET2): $(OBJ_FILES2)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para compilar ejercicio 3
$(TARGET3): $(OBJ_FILES3)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilación de objetos
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpieza
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Ejecuciones
run2: $(TARGET2)
	./$(TARGET2)

run3: $(TARGET3)
	./$(TARGET3)
