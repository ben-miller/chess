// Author: Ben Miller <Miller.Benjmn@Gmail.com>, (C) 2010
//
///@file Rook.cpp An implementation of the Rook class

#include "Rook.h"

// Rooks
Rook::Rook(Cell* cell, int id) {
	this->cell = cell;
	this->id = id;
	type = ROOK;
	validMoves = new std::set<Cell*>();
}
WhiteRook::WhiteRook(Cell* cell, int id) : Rook(cell, id) {
	//DbgMsg("WhiteRook::WhiteRook(Cell* cell, int id)");
	color = WHITE;
	imageName = W_ROOK;
}
BlackRook::BlackRook(Cell* cell, int id) : Rook(cell, id) {
	color = BLACK;
	imageName = B_ROOK;
}
std::set<Cell*>* Rook::GetValidMoves() {
	UpdateValidMoves();
	return validMoves;
}
bool Rook::ValidMovesContains(Cell* cell) {
	UpdateValidMoves();
	return (validMoves->find(cell) != validMoves->end());
}

void Rook::UpdateValidMoves() {
	//DbgMsg("Rook::UpdateValidMoves()");

	validMoves->clear();

	// a placeholder for iterating through 
	// possibly valid cells
	Cell* it;
	
	// Fd
	it = cell;
	while(it->Fd(color) != NULL) {
		// if that cell is empty
		if (it->Fd(color)->GetPiece() == NULL) {
			validMoves->insert(it->Fd(color));
		}
		// or if that cell is another piece
		else if (it->Fd(color)->GetPiece()->GetColor() != color) {
			validMoves->insert(it->Fd(color));
			break;
		}
		else break;
		it = it->Fd(color);
	}
	// Left
	it = cell;
	while(it->Left(color) != NULL) {
		// if that cell is empty
		if (it->Left(color)->GetPiece() == NULL) {
			validMoves->insert(it->Left(color));
		}
		// or if that cell is another piece
		else if (it->Left(color)->GetPiece()->GetColor() != color) {
			validMoves->insert(it->Left(color));
			break;
		}
		else break;
		it = it->Left(color);
	}
	// Right
	it = cell;
	while(it->Right(color) != NULL) {
		// if that cell is empty
		if (it->Right(color)->GetPiece() == NULL) {
			validMoves->insert(it->Right(color));
		}
		// or if that cell is another piece
		else if (it->Right(color)->GetPiece()->GetColor() != color) {
			validMoves->insert(it->Right(color));
			break;
		}
		else break;
		it = it->Right(color);
	}
	// Bk
	it = cell;
	while(it->Bk(color) != NULL) {
		// if that cell is empty
		if (it->Bk(color)->GetPiece() == NULL) {
			validMoves->insert(it->Bk(color));
		}
		// or if that cell is another piece
		else if (it->Bk(color)->GetPiece()->GetColor() != color) {
			validMoves->insert(it->Bk(color));
			break;
		}
		else break;
		it = it->Bk(color);
	}

}

