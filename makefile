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
LIB_FLAGS=
DIRLIB_FLAGS=
INC_FLAGS=-I$(INC_DIR)

# TARGETS
all: $(BIN_DIR)/$(OUTPUT_NAME)
# 	@$(MAKE) --no-print-directory clean-obj
	@$(MAKE) --no-print-directory clean-d

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
UT_SRC_DIR=tests
INC_DIR=inc

# COMPILATION FLAGS
INC_FLAGS=-I$(INC_DIR)

# BUILD NAMES
UT_OUTPUT_NAME=unit-test.exe
UTCPPSOURCES=$(wildcard $(UT_SRC_DIR)/*.cpp)
UTOBJFILES=$(patsubst $(UT_SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(UTCPPSOURCES))

# TARGETS
unit-test: $(BIN_DIR)/$(UT_OUTPUT_NAME)
	@$(MAKE) --no-print-directory clean-d

# LINKING PHASE
$(BIN_DIR)/$(UT_OUTPUT_NAME): $(UTOBJFILES) $(OBJFILES)
	@echo . Gerando executavel final: $@
	@g++ $^ -o $@ $(OBJRESFILES) $(DIRLIB_FLAGS) $(LIB_FLAGS) -Wall

# COMPILATION PHASE
$(OBJ_DIR)/%.o: $(UT_SRC_DIR)/%.cpp
	@echo . Compilando $<
	@g++ -c $< $(INC_FLAGS) -o $@

#
# CLEANING EVERYTHING!
#
clean-exe:
	@echo . Deletando o executavel
# Para o Microsoft Windows!
	@del $(BIN_DIR)\$(OUTPUT_NAME)
	@del $(BIN_DIR)\$(UT_OUTPUT_NAME)
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
