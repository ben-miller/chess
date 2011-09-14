# -----------------------------------------------------------------------------
# Generic Variables
# -----------------------------------------------------------------------------
CC = g++
GTKMM = gtkmm-2.4
SIGC = sigc++-2.0
LIBGLADE = libglademm-2.4

FLAGS = -I$(INC_FOLDER) -I$(VIEW_INC_FOLDER) -I$(GAME_INC_FOLDER) -Wall -g -fPIC

#CFLAGS are the -I values needed to compile files using the GTKMM, SIGC, and
#LIBGLADE libraries
CFLAGS = `pkg-config $(GTKMM) $(SIGC) $(LIBGLADE) --cflags`  -I$(IMAGES_FOLDER)

#LIBS are the paths to the static libraries for GTKMM, SIGC, and LIBGLADE needed
#for linking
LIBS = `pkg-config $(GTKMM) $(SIGC) $(LIBGLADE) --libs`

#LIB_FLAGS D_LOG_DOMAIN is used by g_log in the ChessGui library to seperate logging messages from the library
# from logging messages from the students code
#IMPORTANT: You must add a compiler option here for the library to be dynamic
LIB_FLAGS = -DG_LOG_DOMAIN=\"ChessGui\" -fPIC

# -----------------------------------------------------------------------------
# Folder Variables
# -----------------------------------------------------------------------------
VIEW_FOLDER = view
VIEW_INC_FOLDER = $(VIEW_FOLDER)/inc
VIEW_SRC_FOLDER = $(VIEW_FOLDER)/src
VIEW_OBJ_FOLDER = $(VIEW_FOLDER)/obj
IMAGES_FOLDER = $(VIEW_FOLDER)/images

CONTROLLER_FOLDER = controller
SRC_FOLDER = $(CONTROLLER_FOLDER)/src
INC_FOLDER = $(CONTROLLER_FOLDER)/inc
OBJ_FOLDER = $(CONTROLLER_FOLDER)/obj

GAME_FOLDER = game
GAME_INC_FOLDER = $(GAME_FOLDER)/inc
GAME_SRC_FOLDER = $(GAME_FOLDER)/src
GAME_OBJ_FOLDER = $(GAME_FOLDER)/obj

BIN_FOLDER = bin
DOC_FOLDER = doc

# -----------------------------------------------------------------------------
# File Name Variables
# -----------------------------------------------------------------------------
#change this to a dynamic library name
LIBRARY= $(VIEW_FOLDER)/cs240.a
EXE_NAME = $(BIN_FOLDER)/chess
TEST_NAME = $(BIN_FOLDER)/test

LIB_OBJ_FILES = $(VIEW_OBJ_FOLDER)/Chess.o $(VIEW_OBJ_FOLDER)/ChessGui.o \
		$(VIEW_OBJ_FOLDER)/ChessGuiBoard.o $(VIEW_OBJ_FOLDER)/ChessGuiBoardCell.o \
		$(VIEW_OBJ_FOLDER)/ChessGuiImages.o $(VIEW_OBJ_FOLDER)/SelectDialog.o
		
EXE_OBJ_FILES = $(OBJ_FOLDER)/main.o


# -----------------------------------------------------------------------------
# Command Variables
# -----------------------------------------------------------------------------
bin : $(EXE_NAME)

test : $(TEST_NAME)

runtest : $(TEST_NAME)
	@ ./$(TEST_NAME)

run : $(EXE_NAME)
	./$(EXE_NAME)
	
runhh : $(EXE_NAME)
	./$(EXE_NAME)
	
runhc : $(EXE_NAME)
	./$(EXE_NAME)
	
runch : $(EXE_NAME)
	./$(EXE_NAME)
	
runcc : $(EXE_NAME)
	./$(EXE_NAME)
	
memtest: $(EXE_NAME)
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --suppressions=chess.supp $(EXE_NAME)
	
debug : $(EXE_NAME)
	gdb $(EXE_NAME)

doxy : 
	doxygen Doxyfile
	
lib : $(LIBRARY)

clean: 
	-rm -f $(EXE_NAME)
	-rm -f $(EXE_OBJ_FILES)
	-rm -f $(SRC_FOLDER)/*~ $(INC_FOLDER)/*~
	-rm -f $(LIBRARY) $(LIB_OBJ_FILES)
	-rm -f $(VIEW_SRC_FOLDER)/*~ $(VIEW_INC_FOLDER)/*~
	-rm -f $(GAME_SRC_FOLDER)/*~ $(GAME_INC_FOLDER)/*~
	-rm -f $(GAME_OBJ_FOLDER)/*
	-rm -f -r $(DOC_FOLDER)

# -----------------------------------------------------------------------------
# File Construction
# -----------------------------------------------------------------------------
$(EXE_NAME): $(EXE_OBJ_FILES)  $(LIBRARY) \
        $(OBJ_FOLDER)/ChessControllerImpl.o
	$(CC) $(FLAGS) $(CFLAGS) $(LIBS) -o $(EXE_NAME) $(EXE_OBJ_FILES) $(LIBRARY) \
        $(OBJ_FOLDER)/ChessControllerImpl.o \
        $(GAME_OBJ_FOLDER)/ChessGame.o \
        $(GAME_OBJ_FOLDER)/Board.o \
        $(GAME_OBJ_FOLDER)/Cell.o \
        $(GAME_OBJ_FOLDER)/King.o \
        $(GAME_OBJ_FOLDER)/Queen.o \
        $(GAME_OBJ_FOLDER)/Rook.o \
        $(GAME_OBJ_FOLDER)/Knight.o \
        $(GAME_OBJ_FOLDER)/Bishop.o \
        $(GAME_OBJ_FOLDER)/Pawn.o \
        $(GAME_OBJ_FOLDER)/Pieces.o \
        $(GAME_OBJ_FOLDER)/MoveHistory.o
	
$(OBJ_FOLDER)/main.o: $(SRC_FOLDER)/main.cpp
	$(CC) -c $(FLAGS) $(CFLAGS) -o $(OBJ_FOLDER)/main.o $(SRC_FOLDER)/main.cpp
	
	
# Students: Place your makefile commands here

bin/test : $(OBJ_FOLDER)/TestDriver.o \
        $(GAME_OBJ_FOLDER)/ChessGame.o
	$(CC) $(FLAGS) $(CFLAGS) -o bin/test $(OBJ_FOLDER)/TestDriver.o \
        $(GAME_OBJ_FOLDER)/ChessGame.o \
        $(GAME_OBJ_FOLDER)/Board.o \
        $(GAME_OBJ_FOLDER)/Cell.o \
        $(GAME_OBJ_FOLDER)/Pieces.o \
        $(GAME_OBJ_FOLDER)/MoveHistory.o

$(OBJ_FOLDER)/TestDriver.o : $(SRC_FOLDER)/TestDriver.cpp \
        $(GAME_INC_FOLDER)/MyLogger.h
	$(CC) -c $(FLAGS) $(CFLAGS) -o $(OBJ_FOLDER)/TestDriver.o $(SRC_FOLDER)/TestDriver.cpp

$(OBJ_FOLDER)/ChessControllerImpl.o : \
        $(SRC_FOLDER)/ChessControllerImpl.cpp \
        $(INC_FOLDER)/ChessControllerImpl.h \
        $(GAME_INC_FOLDER)/MyLogger.h \
        $(GAME_OBJ_FOLDER)/ChessGame.o
	$(CC) -c $(FLAGS) $(CFLAGS) -o $(OBJ_FOLDER)/ChessControllerImpl.o \
        $(SRC_FOLDER)/ChessControllerImpl.cpp
	
$(GAME_OBJ_FOLDER)/ChessGame.o : \
        $(GAME_INC_FOLDER)/ChessGame.h \
        $(GAME_SRC_FOLDER)/ChessGame.cpp \
        $(GAME_INC_FOLDER)/MyLogger.h \
        $(GAME_OBJ_FOLDER)/Board.o \
        $(GAME_OBJ_FOLDER)/Cell.o \
        $(GAME_OBJ_FOLDER)/Pieces.o \
        $(GAME_OBJ_FOLDER)/MoveHistory.o
	$(CC) -c $(FLAGS) $(CFLAGS) -o $(GAME_OBJ_FOLDER)/ChessGame.o \
        $(GAME_SRC_FOLDER)/ChessGame.cpp
        
$(GAME_OBJ_FOLDER)/Board.o : \
        $(GAME_INC_FOLDER)/Board.h \
        $(GAME_SRC_FOLDER)/Board.cpp \
        $(GAME_INC_FOLDER)/MyLogger.h \
        $(GAME_OBJ_FOLDER)/Cell.o
	$(CC) -c $(FLAGS) $(CFLAGS) -o $(GAME_OBJ_FOLDER)/Board.o \
        $(GAME_SRC_FOLDER)/Board.cpp
        
$(GAME_OBJ_FOLDER)/Cell.o : \
        $(GAME_INC_FOLDER)/Cell.h \
        $(GAME_SRC_FOLDER)/Cell.cpp \
        $(GAME_INC_FOLDER)/MyLogger.h
        #$(GAME_OBJ_FOLDER)/Piece.o (so it's not a cicular dependency)
	$(CC) -c $(FLAGS) $(CFLAGS) -o $(GAME_OBJ_FOLDER)/Cell.o \
        $(GAME_SRC_FOLDER)/Cell.cpp

$(GAME_OBJ_FOLDER)/King.o : \
        $(GAME_INC_FOLDER)/King.h \
        $(GAME_SRC_FOLDER)/King.cpp \
        $(GAME_INC_FOLDER)/Piece.h
	$(CC) -c $(FLAGS) $(CFLAGS) -o $(GAME_OBJ_FOLDER)/King.o \
        $(GAME_SRC_FOLDER)/King.cpp

$(GAME_OBJ_FOLDER)/Queen.o : \
        $(GAME_INC_FOLDER)/Queen.h \
        $(GAME_SRC_FOLDER)/Queen.cpp \
        $(GAME_INC_FOLDER)/Piece.h
	$(CC) -c $(FLAGS) $(CFLAGS) -o $(GAME_OBJ_FOLDER)/Queen.o \
        $(GAME_SRC_FOLDER)/Queen.cpp

$(GAME_OBJ_FOLDER)/Rook.o : \
        $(GAME_INC_FOLDER)/Rook.h \
        $(GAME_SRC_FOLDER)/Rook.cpp \
        $(GAME_INC_FOLDER)/Piece.h
	$(CC) -c $(FLAGS) $(CFLAGS) -o $(GAME_OBJ_FOLDER)/Rook.o \
        $(GAME_SRC_FOLDER)/Rook.cpp

$(GAME_OBJ_FOLDER)/Knight.o : \
        $(GAME_INC_FOLDER)/Knight.h \
        $(GAME_SRC_FOLDER)/Knight.cpp \
        $(GAME_INC_FOLDER)/Piece.h
	$(CC) -c $(FLAGS) $(CFLAGS) -o $(GAME_OBJ_FOLDER)/Knight.o \
        $(GAME_SRC_FOLDER)/Knight.cpp

$(GAME_OBJ_FOLDER)/Bishop.o : \
        $(GAME_INC_FOLDER)/Bishop.h \
        $(GAME_SRC_FOLDER)/Bishop.cpp \
        $(GAME_INC_FOLDER)/Piece.h
	$(CC) -c $(FLAGS) $(CFLAGS) -o $(GAME_OBJ_FOLDER)/Bishop.o \
        $(GAME_SRC_FOLDER)/Bishop.cpp

$(GAME_OBJ_FOLDER)/Pawn.o : \
        $(GAME_INC_FOLDER)/Pawn.h \
        $(GAME_SRC_FOLDER)/Pawn.cpp \
        $(GAME_INC_FOLDER)/Piece.h
	$(CC) -c $(FLAGS) $(CFLAGS) -o $(GAME_OBJ_FOLDER)/Pawn.o \
        $(GAME_SRC_FOLDER)/Pawn.cpp
        
$(GAME_OBJ_FOLDER)/MoveHistory.o : \
        $(GAME_INC_FOLDER)/MoveHistory.h \
        $(GAME_SRC_FOLDER)/MoveHistory.cpp
	$(CC) -c $(FLAGS) $(CFLAGS) -o $(GAME_OBJ_FOLDER)/MoveHistory.o \
        $(GAME_SRC_FOLDER)/MoveHistory.cpp

$(GAME_OBJ_FOLDER)/Pieces.o : \
        $(GAME_INC_FOLDER)/Pieces.h \
        $(GAME_SRC_FOLDER)/Pieces.cpp \
        $(GAME_INC_FOLDER)/MyLogger.h \
        $(GAME_OBJ_FOLDER)/Board.o \
        $(GAME_OBJ_FOLDER)/King.o \
        $(GAME_OBJ_FOLDER)/Queen.o \
        $(GAME_OBJ_FOLDER)/Rook.o \
        $(GAME_OBJ_FOLDER)/Knight.o \
        $(GAME_OBJ_FOLDER)/Bishop.o \
        $(GAME_OBJ_FOLDER)/Pawn.o
	$(CC) -c $(FLAGS) $(CFLAGS) -o $(GAME_OBJ_FOLDER)/Pieces.o \
        $(GAME_SRC_FOLDER)/Pieces.cpp

# -----------------------------------------------------------------------------
# Library Construction
# -----------------------------------------------------------------------------
#This is currently a STATIC library, you must change it to a DYNAMIC library
#You must also add a compiler option to the variable LIB_FLAGS in order for the library to be dynamic
$(LIBRARY): $(LIB_OBJ_FILES) 
	ar rcs $(LIBRARY) $(LIB_OBJ_FILES)

	
########DO NOT DELETE###########################################################################################3
#Below is some Makefile Magic to compile the libraries, you do not need to
#understand or alter it.  If you would like to, look up the Make manual online, it's very comprehensive	
LIBSOURCES = $(foreach file, $(shell ls $(VIEW_SRC_FOLDER)/*.cpp), $(basename $(notdir $(file))))

$(VIEW_OBJ_FOLDER)/%.o : $(VIEW_SRC_FOLDER)/%.cpp $(VIEW_INC_FOLDER)/Inline.h
	$(CC) $(FLAGS) $(LIB_FLAGS) $(CFLAGS) -c -o $@ $< 

  #The following is part of what lets us include Images within the binary. It currently only loads the default
  #"Image not found" icon that we use

INLINE_IMAGES = $(shell ls $(IMAGES_FOLDER)/* )
INLINE_IMAGE_PAIRS =$(foreach file, $(INLINE_IMAGES), $(basename $(notdir $(file)) $(file).* ))	
view/inc/Inline.h: $(INLINE_IMAGES)
	@echo "Updating Images"
	gdk-pixbuf-csource --raw --build-list $(INLINE_IMAGE_PAIRS) > $(VIEW_INC_FOLDER)/Inline.h

