// Author: Ben Miller <Miller.Benjmn@Gmail.com>, (C) 2010
//
///@file Knight.cpp An implementation of the Knight class

#include "Knight.h"

// Knights
Knight::Knight(Cell* cell, int id) {
	this->cell = cell;
	this->id = id;
	type = KNIGHT;
	validMoves = new std::set<Cell*>();
}
WhiteKnight::WhiteKnight(Cell* cell, int id) : Knight(cell, id) {
	color = WHITE;
	imageName = W_KNIGHT;
}
BlackKnight::BlackKnight(Cell* cell, int id) : Knight(cell, id) {
	color = BLACK;
	imageName = B_KNIGHT;
}
std::set<Cell*>* Knight::GetValidMoves() {
	UpdateValidMoves();
	return validMoves;
}
bool Knight::ValidMovesContains(Cell* cell) {
	UpdateValidMoves();
	return (validMoves->find(cell) != validMoves->end());
}

void Knight::UpdateValidMoves() {
	//DbgMsg("Knight::UpdateValidMoves()");

	validMoves->clear();

	// placeholders for iterating through 
	// possibly valid cells
	Cell* innerIt;
	Cell* outerIt;

	// Fd
	innerIt = cell->Fd(color);
	if (innerIt != NULL) {
		// Fd+FdLeft
		outerIt = innerIt->FdLeft(color);
		if (outerIt != NULL) {
			// if it's an empty piece
			if (outerIt->GetPiece() == NULL) {
				validMoves->insert(outerIt);
			}
			// if it's the other player's piece
			else if (outerIt->GetPiece()->GetColor() != color) {
				validMoves->insert(outerIt);
			}
		}
		// Fd+FdRight
		outerIt = innerIt->FdRight(color);
		if (outerIt != NULL) {
			// if it's an empty piece
			if (outerIt->GetPiece() == NULL) {
				validMoves->insert(outerIt);
			}
			// if it's the other player's piece
			else if (outerIt->GetPiece()->GetColor() != color) {
				validMoves->insert(outerIt);
			}
		}
	}
	// Left
	innerIt = cell->Left(color);
	if (innerIt != NULL) {
		// Left+FdLeft
		outerIt = innerIt->FdLeft(color);
		if (outerIt != NULL) {
			// if it's an empty piece
			if (outerIt->GetPiece() == NULL) {
				validMoves->insert(outerIt);
			}
			// if it's the other player's piece
			else if (outerIt->GetPiece()->GetColor() != color) {
				validMoves->insert(outerIt);
			}
		}
		// Left+BkLeft
		outerIt = innerIt->BkLeft(color);
		if (outerIt != NULL) {
			// if it's an empty piece
			if (outerIt->GetPiece() == NULL) {
				validMoves->insert(outerIt);
			}
			// if it's the other player's piece
			else if (outerIt->GetPiece()->GetColor() != color) {
				validMoves->insert(outerIt);
			}
		}
	}
	// Right
	innerIt = cell->Right(color);
	if (innerIt != NULL) {
		// Right+FdRight
		outerIt = innerIt->FdRight(color);
		if (outerIt != NULL) {
			// if it's an empty piece
			if (outerIt->GetPiece() == NULL) {
				validMoves->insert(outerIt);
			}
			// if it's the other player's piece
			else if (outerIt->GetPiece()->GetColor() != color) {
				validMoves->insert(outerIt);
			}
		}
		// Right+BkRight
		outerIt = innerIt->BkRight(color);
		if (outerIt != NULL) {
			// if it's an empty piece
			if (outerIt->GetPiece() == NULL) {
				validMoves->insert(outerIt);
			}
			// if it's the other player's piece
			else if (outerIt->GetPiece()->GetColor() != color) {
				validMoves->insert(outerIt);
			}
		}
	}
	// Bk
	innerIt = cell->Bk(color);
	if (innerIt != NULL) {
		// Bk+BkLeft
		outerIt = innerIt->BkLeft(color);
		if (outerIt != NULL) {
			// if it's an empty piece
			if (outerIt->GetPiece() == NULL) {
				validMoves->insert(outerIt);
			}
			// if it's the other player's piece
			else if (outerIt->GetPiece()->GetColor() != color) {
				validMoves->insert(outerIt);
			}
		}
		// Bk+BkRight
		outerIt = innerIt->BkRight(color);
		if (outerIt != NULL) {
			// if it's an empty piece
			if (outerIt->GetPiece() == NULL) {
				validMoves->insert(outerIt);
			}
			// if it's the other player's piece
			else if (outerIt->GetPiece()->GetColor() != color) {
				validMoves->insert(outerIt);
			}
		}
	}

}

