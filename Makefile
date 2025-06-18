# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Isrc
GUI_CXXFLAGS = -std=c++11 -Wall -Isrc -Ilibs/imgui -Ilibs/imgui/backends -I/opt/homebrew/include

# Libraries for GUI
GUI_LIBS = -L/opt/homebrew/lib -lglfw -lGLEW -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

# Source files
SRC_DIR = src
OBJ_DIR = obj

DFA_SRC = $(SRC_DIR)/DFA.cpp
PDA_SRC = $(SRC_DIR)/PDA.cpp
NPDA_SRC = $(SRC_DIR)/NPDA.cpp
UI_SRC = $(SRC_DIR)/UI.cpp
MAIN_SRC = $(SRC_DIR)/main.cpp
GUI_SRC = $(SRC_DIR)/main_gui.cpp

IMGUI_SRC_DIR = libs/imgui
IMGUI_BACKENDS_DIR = $(IMGUI_SRC_DIR)/backends

IMGUI_SRCS = \
    $(IMGUI_SRC_DIR)/imgui.cpp \
    $(IMGUI_SRC_DIR)/imgui_demo.cpp \
    $(IMGUI_SRC_DIR)/imgui_draw.cpp \
    $(IMGUI_SRC_DIR)/imgui_tables.cpp \
    $(IMGUI_SRC_DIR)/imgui_widgets.cpp \
    $(IMGUI_BACKENDS_DIR)/imgui_impl_glfw.cpp \
    $(IMGUI_BACKENDS_DIR)/imgui_impl_opengl3.cpp

AUTOMATON_SRCS = $(DFA_SRC) $(PDA_SRC) $(NPDA_SRC)
BASE_SRCS = $(MAIN_SRC) $(AUTOMATON_SRCS) $(UI_SRC)
GUI_SRCS = $(GUI_SRC) $(AUTOMATON_SRCS) $(IMGUI_SRCS)

DFA_OBJ = $(OBJ_DIR)/DFA.o
PDA_OBJ = $(OBJ_DIR)/PDA.o
NPDA_OBJ = $(OBJ_DIR)/NPDA.o
UI_OBJ = $(OBJ_DIR)/UI.o
MAIN_OBJ = $(OBJ_DIR)/main.o
GUI_OBJ = $(OBJ_DIR)/main_gui.o

IMGUI_OBJS = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(notdir $(IMGUI_SRCS)))

AUTOMATON_OBJS = $(DFA_OBJ) $(PDA_OBJ) $(NPDA_OBJ)
BASE_OBJS = $(MAIN_OBJ) $(AUTOMATON_OBJS) $(UI_OBJ)
GUI_OBJS = $(GUI_OBJ) $(AUTOMATON_OBJS) $(IMGUI_OBJS)

# Target executables
DFA_TARGET = dfa_oop
PDA_TARGET = pda_oop
NPDA_TARGET = npda_oop
AUTOMATA_TARGET = DasAutomat
GUI_TARGET = DasAutomatGUI

.PHONY: all clean gui

all: $(AUTOMATA_TARGET) $(GUI_TARGET)

gui: $(GUI_TARGET)

$(GUI_TARGET): $(GUI_OBJS)
	$(CXX) $(GUI_CXXFLAGS) $^ -o $@ $(GUI_LIBS)

$(AUTOMATA_TARGET): $(BASE_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/main_gui.o: $(SRC_DIR)/main_gui.cpp | $(OBJ_DIR)
	$(CXX) $(GUI_CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(IMGUI_SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(GUI_CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(IMGUI_BACKENDS_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(GUI_CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) $(AUTOMATA_TARGET) $(DFA_TARGET) $(PDA_TARGET) $(NPDA_TARGET) $(GUI_TARGET) 