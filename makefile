# -----------------------------------------------------------------------------
# BPM GAME ENGINE MAKEFILE
# Copyright (C) 2020 Fabio Takeshi Ishikawa
# -----------------------------------------------------------------------------

# DIR PATH
BIN_DIR=bin
OBJ_DIR=obj
SRC_DIR=src
INC_DIR=inc

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
	@echo . Generating executable: $@
	@g++ $^ -o $@ $(OBJRESFILES) $(DIRLIB_FLAGS) $(LIB_FLAGS) -Wall

# COMPILATION PHASE
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo . Compiling $<
	@g++ -c $(DEBUG_FLAG) $< $(INC_FLAGS) -o $@ -Wall

var-teste:
	@echo $(BIN_DIR)
	@echo $(OBJ_DIR)
	@echo $(SRC_DIR)
	@echo $(INC_DIR)
	@echo $(OUTPUT_NAME)
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

# -----------------------------------------------------------------------------
# UNIT TEST MAKEFILE
# -----------------------------------------------------------------------------

# DIR PATH
UT_SRC_DIR=tests

UT_OUTPUT_NAME=getest.exe
UT_CPPSOURCES=$(wildcard $(UT_SRC_DIR)/*.cpp)
UT_OBJFILES=$(patsubst $(UT_SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(UT_CPPSOURCES))

# TARGETS
test: $(BIN_DIR)/$(UT_OUTPUT_NAME)
	@$(MAKE) --no-print-directory clean-d

# LINKING PHASE
$(BIN_DIR)/$(UT_OUTPUT_NAME): $(UT_OBJFILES) $(OBJFILES)
	@echo . Generating executable: $@
	@g++ $^ -o $@ $(OBJRESFILES) $(DIRLIB_FLAGS) $(LIB_FLAGS) -Wall

# COMPILATION PHASE
$(OBJ_DIR)/%.o: $(UT_SRC_DIR)/%.cpp
	@echo . Compiling $<
	@g++ -c $< $(INC_FLAGS) -o $@

# -----------------------------------------------------------------------------
# CLEANING EVERYTHING!
# -----------------------------------------------------------------------------

clean-exe:
	@echo . Deleting executable
# Para o Microsoft Windows!
	@del $(BIN_DIR)\$(OUTPUT_NAME)
	@del $(BIN_DIR)\$(UT_OUTPUT_NAME)
# Para o UNIX!
#	rm bin/teste.exe

clean-obj:
	@echo . Deleting object code
# Para o Microsoft Windows!
	@del $(OBJ_DIR)\*.o
# Para o UNIX!
#	rm obj/*.o

clean-d:
	@echo . Deleting temp files
# Para o Microsoft Windows
	@del $(OBJ_DIR)\*.d
# Par ao UNIX
# 	rm $(TMP_DIR)/*

clean-all:
	@echo . Clean all
	@$(MAKE) --no-print-directory clean-exe
	@$(MAKE) --no-print-directory clean-obj
	@$(MAKE) --no-print-directory clean-d

remade:
	@echo REMADE
	@$(MAKE) --no-print-directory clean-all
	@$(MAKE) --no-print-directory all
