// Author: Ben Miller <Miller.Benjmn@Gmail.com>, (C) 2010
//
///@file Pawn.cpp An implementation of the Pawn class

#include "Pawn.h"

// Pawns
Pawn::Pawn(Cell* cell, int id) {
	this->cell = cell;
	this->id = id;
	type = PAWN;
	validMoves = new std::set<Cell*>();
}
WhitePawn::WhitePawn(Cell* cell, int id) : Pawn(cell, id) {
	color = WHITE;
	imageName = W_PAWN;
}
BlackPawn::BlackPawn(Cell* cell, int id) : Pawn(cell, id) {
	color = BLACK;
	imageName = B_PAWN;
}
std::set<Cell*>* Pawn::GetValidMoves() {
	//DbgMsg("Pawn::ValidMoves()");
	UpdateValidMoves();
	
	return validMoves;
}
bool Pawn::ValidMovesContains(Cell* cell) {
	UpdateValidMoves();
	//DbgMsg("Pawn::ValidMovesContains(Cell* cell)? " << (validMoves->find(cell) != validMoves->end()));
	
	return (validMoves->find(cell) != validMoves->end());
}

void Pawn::UpdateValidMoves() {
	//DbgMsg("Pawn::UpdateValidMoves()");

	validMoves->clear();

	// Fd
	if (cell->Fd(color) != NULL && 
		cell->Fd(color)->GetPiece() == NULL )
	{
		validMoves->insert(cell->Fd(color));

		// if the pawn is in the starting position, 
		// we can move forward 2
		if ((color == WHITE && cell->GetRow() == 6) || 
			(color == BLACK && cell->GetRow() == 1) )
		{
			if (cell->Fd(color)->Fd(color)->GetPiece() == NULL)
				validMoves->insert(cell->Fd(color)->Fd(color));
		}
	}

	// FdLeft
	if (cell->FdLeft(color) != NULL && 
		cell->FdLeft(color)->GetPiece() != NULL && 
		cell->FdLeft(color)->GetPiece()->GetColor() != color )
	{
		validMoves->insert(cell->FdLeft(color));
	}

	// FdRight
	if (cell->FdRight(color) != NULL &&
		cell->FdRight(color)->GetPiece() != NULL && 
		cell->FdRight(color)->GetPiece()->GetColor() != color )
	{
		validMoves->insert(cell->FdRight(color));
	}

}


