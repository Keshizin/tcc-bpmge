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
DFILES=$(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.d,$(CPPSOURCES))

# COMPILATION FLAGS
LIB_FLAGS=-lopengl32 -lglu32 -lgdi32
DIRLIB_FLAGS=
INC_FLAGS=-I$(INC_DIR)
DEBUG_FLAG=-DDEBUG_MODE

# TARGETS
all: $(BIN_DIR)/$(OUTPUT_NAME)
	@$(MAKE) --no-print-directory clean-d

# LINKING PHASE
$(BIN_DIR)/$(OUTPUT_NAME): $(OBJFILES)
	@echo . Gerando executavel final: $@
	@g++ $^ -o $@ $(OBJRESFILES) $(DIRLIB_FLAGS) $(LIB_FLAGS) -Wall

# COMPILATION PHASE
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo . Compilando $<
	@g++ -c $(DEBUG_FLAG) $< $(INC_FLAGS) -o $@

var-teste:
	@echo $(OUTPUT_NAME)
	@echo $(BIN_DIR)
	@echo $(OBJ_DIR)
	@echo $(SRC_DIR)
	@echo $(INC_DIR)
	@echo $(CPPSOURCES)
	@echo $(OBJFILES)
	@echo $(OBJRESFILES)
	@echo $(DFILES)
	@echo $(LIB_FLAGS)
	@echo $(DIRLIB_FLAG)
	@echo $(INC_FLAGS)

-include $(DFILES)

$(OBJ_DIR)/%.d: $(SRC_DIR)/%.cpp
# 	@echo . Gerando arquivos .d (dependencias - GCC) $<
	@g++ -c $< -MM -MT 'obj/$*.o obj/$*.d ' -MD $(INC_FLAGS) -o $@

#
# UNIT TEST COMPILATION
#

# DIR PATH
UNIT_TEST_SRC_DIR=tests

# BUILD NAMES
UNIT_TEST_OUTPUT_NAME=unit-test.exe
UNIT_TEST_CPPSOURCES=$(wildcard $(UNIT_TEST_SRC_DIR)/*.cpp)
UNIT_TEST_OBJFILES=$(patsubst $(UNIT_TEST_SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(UNIT_TEST_CPPSOURCES))

# TARGETS
unit-test: $(BIN_DIR)/$(UNIT_TEST_OUTPUT_NAME)
	@$(MAKE) --no-print-directory clean-d

# LINKING PHASE
$(BIN_DIR)/$(UNIT_TEST_OUTPUT_NAME): $(UNIT_TEST_OBJFILES) $(OBJFILES)
	@echo . Gerando executavel final: $@
	@g++ $^ -o $@ $(OBJRESFILES) $(DIRLIB_FLAGS) $(LIB_FLAGS) -Wall

# COMPILATION PHASE
$(OBJ_DIR)/%.o: $(UNIT_TEST_SRC_DIR)/%.cpp
	@echo . Compilando $<
	@g++ -c $< $(INC_FLAGS) -o $@

#
# CLEANING EVERYTHING!
#
clean-exe:
	@echo . Deletando o executavel
# Para o Microsoft Windows!
	@del $(BIN_DIR)\$(OUTPUT_NAME)
	@del $(BIN_DIR)\$(UNIT_TEST_OUTPUT_NAME)
# Para o UNIX!
#	rm bin/teste.exe

clean-obj:
	@echo . Deletando codigo-objetos
# Para o Microsoft Windows!
	@del $(OBJ_DIR)\*.o
# Para o UNIX!
#	rm obj/*.o

clean-d:
	@echo . Deletando makefiles temporarios
# Para o Microsoft Windows
	@del $(OBJ_DIR)\*.d
# Par ao UNIX
# 	rm $(TMP_DIR)/*

clean-all:
	@echo . Limpando tudo
	@$(MAKE) --no-print-directory clean-exe
	@$(MAKE) --no-print-directory clean-obj
	@$(MAKE) --no-print-directory clean-d

remade:
	@echo REMADE
	@$(MAKE) --no-print-directory clean-all
	@$(MAKE) --no-print-directory all
