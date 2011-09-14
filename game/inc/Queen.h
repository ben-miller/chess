// Author: Ben Miller <Miller.Benjmn@Gmail.com>, (C) 2010
//
///@file Queen.h An interface for the %Queen class

#if !defined(QUEEN_H)
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece {
	
	public:
		// valid moves
		std::set<Cell*>* GetValidMoves();
		bool ValidMovesContains(Cell* cell);

	protected:
		Queen(Cell* cell);
		void UpdateValidMoves();
		
};
class WhiteQueen : public Queen {
	
	public:
		WhiteQueen(Cell* cell);
	
};
class BlackQueen : public Queen {
	
	public:
		BlackQueen(Cell* cell);

};

#endif

