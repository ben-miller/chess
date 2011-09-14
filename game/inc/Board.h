// Author: Ben Miller <Miller.Benjmn@Gmail.com>, (C) 2010
//
///@file Board.h An interface for the Board class

#if !defined(BOARD_H)
#define BOARD_H

#include <string>
#include "Cell.h"
#include "Piece.h"
#include "MyLogger.h"

class Pieces;

///@brief An interface for the Board class
///
/// This class represents a chess board whose 64 cells (and therefore pieces) can be acessed via row & column indeces
class Board {

	public:
		/// Allocates an 8x8 array of Cell pointers and the respective Cells on the heap
		/// Each of these Cells is initialized to point to emptyPiece
		///@note IMPORTANT: This is only part of the board's initialization. After declaring a 
		/// Pieces object, we need to call BindCellsToPieces to finish setting the board. 
		Board();
		/// Deletes the Cells and the array of Cell pointers
		~Board();
		
		///  Binds each cell to a piece in pieces
		void BindCellsToPieces(Pieces* pieces);

		///@param row and @param col correspond to those used in ChessController
		Cell* GetCell(int row, int col);
		
		/// toString method
		std::string& toString(int numTabs);
	
	private:
		/// Points to array of %Cell pointers
		Cell*** cells;
};

#endif

