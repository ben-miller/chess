// Author: Ben Miller <Miller.Benjmn@Gmail.com>, (C) 2010
//
///@file Queen.cpp An implementation of the Queen class

#include "Queen.h"

// Queens
Queen::Queen(Cell* cell) {
	this->cell = cell;
	id = 0;
	type = QUEEN;
	validMoves = new std::set<Cell*>();
}
WhiteQueen::WhiteQueen(Cell* cell) : Queen(cell) {
	color = WHITE;
	imageName = W_QUEEN;
}
BlackQueen::BlackQueen(Cell* cell) : Queen(cell) {
	color = BLACK;
	imageName = B_QUEEN;
}
std::set<Cell*>* Queen::GetValidMoves() {
	UpdateValidMoves();
	return validMoves;
}
bool Queen::ValidMovesContains(Cell* cell) {
	UpdateValidMoves();
	//DbgMsg("Queen::ValidMovesContains(Cell* cell)? " << (validMoves->find(cell) != validMoves->end()));
	return (validMoves->find(cell) != validMoves->end());
}

void Queen::UpdateValidMoves() {
	//DbgMsg("Queen::UpdateValidMoves()");

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

