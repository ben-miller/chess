// Author: Ben Miller <Miller.Benjmn@Gmail.com>, (C) 2010
//
///@file Bishop.h An interface for the %Bishop class

#if !defined(BISHOP_H)
#define BISHOP_H

#include "Piece.h"

// Bishops
class Bishop : public Piece {
	
	public:
		// valid moves
		std::set<Cell*>* GetValidMoves();
		bool ValidMovesContains(Cell* cell);

	protected:
		Bishop(Cell* cell, int id);
		void UpdateValidMoves();
};
class WhiteBishop : public Bishop {
	
	public:
		WhiteBishop(Cell* cell, int id);
	
};
class BlackBishop : public Bishop {
	
	public:
		BlackBishop(Cell* cell, int id);

};

#endif

