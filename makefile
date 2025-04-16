CXX = g++ # Compilador
CXXFLAGS = -Wall -Wextra -Wpedantic -std=c++17 -I./Ejercicio1 -I./Ejercicio2 # Flags

SRC_DIRS = Ejercicio1 Ejercicio2 Ejercicio3 # Directorio de los source .cpp
OBJ_DIR = obj # Directorio de los archivos .o
BIN_DIR = bin # Directorio de los ejecutables

SRC_FILES2 = $(filter-out Ejercicio3/fight.cpp, $(wildcard Ejercicio1/*.cpp Ejercicio2/*.cpp)) # Archivos source para el ejercicio 2
SRC_FILES3 = $(filter-out Ejercicio2/main.cpp, $(wildcard Ejercicio1/*.cpp Ejercicio2/*.cpp Ejercicio3/*.cpp)) # Archivos source para el ejercicio 3

# De source (.cpp) a object (.o)
# $(patsubst <pattern>, <replacement>, <text>)
OBJ_FILES2 = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES2))
OBJ_FILES3 = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES3)) 

# Ejecutables
TARGET2 = $(BIN_DIR)/main2 
TARGET3 = $(BIN_DIR)/main3

# Reglas de compilación para el ejercicio 2
$(TARGET2): $(OBJ_FILES2) $(OBJ_DIR)/Ejercicio2/main.o
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^  

# Reglas de compilación para el ejercicio 3
$(TARGET3): $(OBJ_FILES3) $(OBJ_DIR)/Ejercicio3/fight.o
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilación de archivos .o
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpieza de los archivos ya generados (borra obj/ y bin/)
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Ejecución
run2: $(TARGET2)
	./$(TARGET2)

run3: $(TARGET3)
	./$(TARGET3)