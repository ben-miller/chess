// Author: Ben Miller <Miller.Benjmn@Gmail.com>, (C) 2010
//
///@file Knight.h An interface for the %Knight class

#if !defined(KNIGHT_H)
#define KNIGHT_H

#include "Piece.h"

// Knights
class Knight : public Piece {
	
	public:
		// valid moves
		std::set<Cell*>* GetValidMoves();
		bool ValidMovesContains(Cell* cell);

	protected:
		Knight(Cell* cell, int id);
		void UpdateValidMoves();
		
};
class WhiteKnight : public Knight {
	
	public:
		WhiteKnight(Cell* cell, int id);
	
};
class BlackKnight : public Knight {
	
	public:
		BlackKnight(Cell* cell, int id);

};

#endif

