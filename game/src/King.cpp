// Author: Ben Miller <Miller.Benjmn@Gmail.com>, (C) 2010
//
///@file King.cpp An implementation of the King class

#include "King.h"


// Kings
King::King(Cell* cell) {
	this->cell = cell;
	id = 0;
	type = KING;
	validMoves = new std::set<Cell*>();
}
WhiteKing::WhiteKing(Cell* cell) : King(cell) {
	color = WHITE;
	imageName = W_KING;
}
BlackKing::BlackKing(Cell* cell) : King(cell) {
	color = BLACK;
	imageName = B_KING;
}
std::set<Cell*>* King::GetValidMoves() {
	UpdateValidMoves();
	return validMoves;
}
bool King::ValidMovesContains(Cell* cell) {
	UpdateValidMoves();
	return (validMoves->find(cell) != validMoves->end());
}

void King::UpdateValidMoves() {
	//DbgMsg("King::UpdateValidMoves()");

	validMoves->clear();

	// FdLeft
	if (cell->FdLeft(color) != NULL) {
		// if that cell is empty
		if (cell->FdLeft(color)->GetPiece() == NULL) {
			validMoves->insert(cell->FdLeft(color));
		}
		// or if that cell is another piece
		else if (cell->FdLeft(color)->GetPiece()->GetColor() != color) {
			validMoves->insert(cell->FdLeft(color));
		}
	}
	// Fd
	if (cell->Fd(color) != NULL) {
		// if that cell is empty
		if (cell->Fd(color)->GetPiece() == NULL) {
			validMoves->insert(cell->Fd(color));
		}
		// or if that cell is another piece
		else if (cell->Fd(color)->GetPiece()->GetColor() != color) {
			validMoves->insert(cell->Fd(color));
		}
	}
	// FdRight
	if (cell->FdRight(color) != NULL) {
		// if that cell is empty
		if (cell->FdRight(color)->GetPiece() == NULL) {
			validMoves->insert(cell->FdRight(color));
		}
		// or if that cell is another piece
		else if (cell->FdRight(color)->GetPiece()->GetColor() != color) {
			validMoves->insert(cell->FdRight(color));
		}
	}
	// Left
	if (cell->Left(color) != NULL) {
		// if that cell is empty
		if (cell->Left(color)->GetPiece() == NULL) {
			validMoves->insert(cell->Left(color));
		}
		// or if that cell is another piece
		else if (cell->Left(color)->GetPiece()->GetColor() != color) {
			validMoves->insert(cell->Left(color));
		}
	}
	// Right
	if (cell->Right(color) != NULL) {
		// if that cell is empty
		if (cell->Right(color)->GetPiece() == NULL) {
			validMoves->insert(cell->Right(color));
		}
		// or if that cell is another piece
		else if (cell->Right(color)->GetPiece()->GetColor() != color) {
			validMoves->insert(cell->Right(color));
		}
	}
	// BkLeft
	if (cell->BkLeft(color) != NULL) {
		// if that cell is empty
		if (cell->BkLeft(color)->GetPiece() == NULL) {
			validMoves->insert(cell->BkLeft(color));
		}
		// or if that cell is another piece
		else if (cell->BkLeft(color)->GetPiece()->GetColor() != color) {
			validMoves->insert(cell->BkLeft(color));
		}
	}
	// Bk
	if (cell->Bk(color) != NULL) {
		// if that cell is empty
		if (cell->Bk(color)->GetPiece() == NULL) {
			validMoves->insert(cell->Bk(color));
		}
		// or if that cell is another piece
		else if (cell->Bk(color)->GetPiece()->GetColor() != color) {
			validMoves->insert(cell->Bk(color));
		}
	}
	// BkRight
	if (cell->BkRight(color) != NULL) {
		// if that cell is empty
		if (cell->BkRight(color)->GetPiece() == NULL) {
			validMoves->insert(cell->BkRight(color));
		}
		// or if that cell is another piece
		else if (cell->BkRight(color)->GetPiece()->GetColor() != color) {
			validMoves->insert(cell->BkRight(color));
		}
	}
}

