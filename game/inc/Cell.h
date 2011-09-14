// Author: Ben Miller <Miller.Benjmn@Gmail.com>, (C) 2010
//
///@file Cell.h An interface for the Cell class

#if !defined(CELL_H)
#define CELL_H

#include "MyLogger.h"

class Piece;
class Board;

enum PieceType {KING, QUEEN, ROOK, KNIGHT, BISHOP, PAWN};
enum PieceColor {WHITE, BLACK};

///@brief An interface for the %Cell class that holds a piece (real or empty).
/// This class also has directional functions for adjacent cells. 
class Cell {

	public:
		Cell();
		///@param piece is the Piece object to which this %Cell will point.
		Cell(Board* board, int row, int col);
		///@note This dtor does nothing special, as %Cell allocates nothing on the heap.
		~Cell();
		
		///@name Setters
		///@{
		void BindToPiece(Piece* piece);
		///@}
		
		///@name Getters
		///@{
		Piece* GetPiece();
		int GetRow();
		int GetCol();
		///@}

		///@name Directional Methods
		/// These return the adjacent cell in the respective direction, 
		/// or NULL if that cell doesn't exist. 
		///@{
		Cell* FdLeft(PieceColor color);
		Cell* Fd(PieceColor color);
		Cell* FdRight(PieceColor color);
		Cell* Left(PieceColor color);
		Cell* Right(PieceColor color);
		Cell* BkLeft(PieceColor color);
		Cell* Bk(PieceColor color);
		Cell* BkRight(PieceColor color);
		///@}

	protected:
		int row;
		int col;
		Board* board;
		Piece* piece;

};

#endif
