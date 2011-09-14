// Author: Ben Miller <Miller.Benjmn@Gmail.com>, (C) 2010
//
///@file Bishop.cpp An implementation of the Bishop class

#include "Bishop.h"

// Bishops
Bishop::Bishop(Cell* cell, int id) {
	this->cell = cell;
	this->id = id;
	type = BISHOP;
	validMoves = new std::set<Cell*>();
}
WhiteBishop::WhiteBishop(Cell* cell, int id) : Bishop(cell, id) {
	color = WHITE;
	imageName = W_BISHOP;
}
BlackBishop::BlackBishop(Cell* cell, int id) : Bishop(cell, id) {
	color = BLACK;
	imageName = B_BISHOP;
}
std::set<Cell*>* Bishop::GetValidMoves() {
	UpdateValidMoves();
	return validMoves;
}
bool Bishop::ValidMovesContains(Cell* cell) {
	UpdateValidMoves();
	return (validMoves->find(cell) != validMoves->end());
}

void Bishop::UpdateValidMoves() {
	//DbgMsg("Bishop::UpdateValidMoves()");

	validMoves->clear();

	// a placeholder for iterating through 
	// possibly valid cells
	Cell* it;

	// FdLeft
	it = cell;
	while(it->FdLeft(color) != NULL) {
		// if that cell is empty
		if (it->FdLeft(color)->GetPiece() == NULL) {
			validMoves->insert(it->FdLeft(color));
		}
		// or if that cell is another piece
		else if (it->FdLeft(color)->GetPiece()->GetColor() != color) {
			validMoves->insert(it->FdLeft(color));
			break;
		}
		else break;
		it = it->FdLeft(color);
	}
	// FdRight
	it = cell;
	while(it->FdRight(color) != NULL) {
		// if that cell is empty
		if (it->FdRight(color)->GetPiece() == NULL) {
			validMoves->insert(it->FdRight(color));
		}
		// or if that cell is another piece
		else if (it->FdRight(color)->GetPiece()->GetColor() != color) {
			validMoves->insert(it->FdRight(color));
			break;
		}
		else break;
		it = it->FdRight(color);
	}
	// BkLeft
	it = cell;
	while(it->BkLeft(color) != NULL) {
		// if that cell is empty
		if (it->BkLeft(color)->GetPiece() == NULL) {
			validMoves->insert(it->BkLeft(color));
		}
		// or if that cell is another piece
		else if (it->BkLeft(color)->GetPiece()->GetColor() != color) {
			validMoves->insert(it->BkLeft(color));
			break;
		}
		else break;
		it = it->BkLeft(color);
	}
	// BkRight
	it = cell;
	while(it->BkRight(color) != NULL) {
		// if that cell is empty
		if (it->BkRight(color)->GetPiece() == NULL) {
			validMoves->insert(it->BkRight(color));
		}
		// or if that cell is another piece
		else if (it->BkRight(color)->GetPiece()->GetColor() != color) {
			validMoves->insert(it->BkRight(color));
			break;
		}
		else break;
		it = it->BkRight(color);
	}

}

