// Author: Ben Miller <Miller.Benjmn@Gmail.com>, (C) 2010
//
///@file Rook.h An interface for the %Rook class

#if !defined(ROOK_H)
#define ROOK_H

#include "Piece.h"

// Rooks
class Rook : public Piece {
	
	public:
		// valid moves
		std::set<Cell*>* GetValidMoves();
		bool ValidMovesContains(Cell* cell);

	protected:
		Rook(Cell* cell, int id);
		void UpdateValidMoves();
		
};
class WhiteRook : public Rook {
	
	public:
		WhiteRook(Cell* cell, int id);
	
};
class BlackRook : public Rook {
	
	public:
		BlackRook(Cell* cell, int id);

};

#endif

