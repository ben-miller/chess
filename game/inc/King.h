// Author: Ben Miller <Miller.Benjmn@Gmail.com>, (C) 2010
//
///@file King.h An interface for the King class

#if !defined(KING_H)
#define KING_H

#include "Piece.h"

class King : public Piece {

	public:
		// valid moves
		std::set<Cell*>* GetValidMoves();
		bool ValidMovesContains(Cell* cell);
	
	protected:
		King(Cell* cell);
		void UpdateValidMoves();

};
class WhiteKing : public King {
	
	public:
		WhiteKing(Cell* cell);
	
};
class BlackKing : public King {
	
	public:
		BlackKing(Cell* cell);

};

#endif

