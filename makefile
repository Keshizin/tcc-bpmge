# BPM Game Engine Compilation File!

# DIR PATH
BIN_DIR=bin
OBJ_DIR=obj
SRC_DIR=src
INC_DIR=inc

# BUILD NAMES
OUTPUT_NAME=game.exe
CPPSOURCES=$(wildcard $(SRC_DIR)/*.cpp)
OBJFILES=$(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(CPPSOURCES))
OBJRESFILES=

# COMPILATION FLAGS
LIB_FLAGS=
DIRLIB_FLAGS=
INC_FLAGS=-I$(INC_DIR)

# TARGETS
all: $(BIN_DIR)/$(OUTPUT_NAME)

# LINKING PHASE
$(BIN_DIR)/$(OUTPUT_NAME): $(OBJFILES)
	@echo . Gerando executavel final: $@
	@g++ $^ -o $@ $(OBJRESFILES) $(DIRLIB_FLAGS) $(LIB_FLAGS) -Wall

# COMPILATION PHASE
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo . Compilando $<
	@g++ -c $< $(INC_FLAGS) -o $@

var-teste:
	@echo $(OUTPUT_NAME)
	@echo $(BIN_DIR)
	@echo $(OBJ_DIR)
	@echo $(SRC_DIR)
	@echo $(INC_DIR)
	@echo $(CPPSOURCES)
	@echo $(OBJFILES)
	@echo $(OBJRESFILES)
	@echo $(LIB_FLAGS)
	@echo $(DIRLIB_FLAG)
	@echo $(INC_FLAGS)

clean-exe:
	@echo . Deletando o executavel
# Para o Microsoft Windows!
	del $(BIN_DIR)\$(OUTPUT_NAME)
# Para o UNIX!
#	rm bin/teste.exe

clean-obj:
	@echo . Deletando codigo-objetos
# Para o Microsoft Windows!
	del $(OBJ_DIR)\*.o
# Para o UNIX!
#	rm obj/*.o

clean-all:
	@echo . Limpando tudo
	$(MAKE) clean-exe
	$(MAKE) clean-obj

remade:
	@echo REMADE
	$(MAKE) clean-all
	$(MAKE) all
