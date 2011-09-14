// Author: Ben Miller <Miller.Benjmn@Gmail.com>, (C) 2010
//
///@file Pawn.h An interface for the %Pawn class

#if !defined(PAWN_H)
#define PAWN_H

#include "Piece.h"

// Pawns
class Pawn : public Piece {
	
	public:
		// valid moves
		std::set<Cell*>* GetValidMoves();
		bool ValidMovesContains(Cell* cell);

	protected:
		Pawn(Cell* cell, int id);
		void UpdateValidMoves();
};
class WhitePawn : public Pawn {
	
	public:
		WhitePawn(Cell* cell, int id);
	
};
class BlackPawn : public Pawn {
	
	public:
		BlackPawn(Cell* cell, int id);

};

#endif

