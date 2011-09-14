// Author: Ben Miller <Miller.Benjmn@Gmail.com>, (C) 2010
//
///@file Cell.cpp An implementation of the Cell class

#include "Piece.h"
#include "Board.h"

Cell::Cell() {
	board = NULL;
	piece = NULL;
	row = -1;
	col = -1;
}
Cell::Cell(Board* board, int row, int col) : 
		board(board), row(row), col(col) {
	//DbgMsg("Cell::Cell(Piece* piece)");
	piece = NULL;
	
}
Cell::~Cell() {
	//DbgMsg("Cell::~Cell()");
	
	
	
}

void Cell::BindToPiece(Piece* piece) {
	//DbgMsg("Cell::BindToPiece(Piece* piece)");
	//DbgMsg("  " << piece);
	this->piece = piece;
}

Piece* Cell::GetPiece() {
	//DbgMsg("Cell::GetPiece()");
	//DbgMsg("  " << piece);
	return piece;
}
int Cell::GetRow() {
	return row;
}
int Cell::GetCol() {
	return col;
}






Cell* Cell::FdLeft(PieceColor color) {
	assert(this != NULL);
	
	if (Fd(color) != NULL) {
		return Fd(color)->Left(color);
	}
	else return NULL;
}
Cell* Cell::Fd(PieceColor color) {
	assert(this != NULL);
	assert(0 <= row && row <= 7);
	assert(0 <= col && col <= 7);
	
	if (color == WHITE) {
		if (row > 0)
			return board->GetCell( row-1,col );
		else return NULL;
	}
	else {
		if (row < 7)
			return board->GetCell( row+1,col );
		else return NULL;
	}
}
Cell* Cell::FdRight(PieceColor color) {
	assert(this != NULL);
	
	if (Fd(color) != NULL) {
		return Fd(color)->Right(color);
	}
	else return NULL;
}
Cell* Cell::Left(PieceColor color) {
	assert(this != NULL);
	assert(0 <= row && row <= 7);
	assert(0 <= col && col <= 7);
	
	if (color == WHITE) {
		if (col > 0)
			return board->GetCell( row,col-1 );
		else return NULL;
	}
	else {
		if (col < 7)
			return board->GetCell( row,col+1 );
		else return NULL;
	}
}
Cell* Cell::Right(PieceColor color) {
	assert(this != NULL);
	assert(0 <= row && row <= 7);
	assert(0 <= col && col <= 7);
	
	if (color == WHITE) {
		if (col < 7)
			return board->GetCell( row,col+1 );
		else return NULL;
	}
	else {
		if (col > 0)
			return board->GetCell( row,col-1 );
		else return NULL;
	}
}
Cell* Cell::BkLeft(PieceColor color) {
	assert(this != NULL);
	
	if (Bk(color) != NULL) {
		return Bk(color)->Left(color);
	}
	else return NULL;
}
Cell* Cell::Bk(PieceColor color) {
	assert(this != NULL);
	assert(0 <= row && row <= 7);
	assert(0 <= col && col <= 7);
	
	if (color == WHITE) {
		if (row < 7)
			return board->GetCell( row+1,col );
		else return NULL;
	}
	else {
		if (row > 0)
			return board->GetCell( row-1,col );
		else return NULL;
	}
}
Cell* Cell::BkRight(PieceColor color) {
	assert(this != NULL);
	
	if (Bk(color) != NULL) {
		return Bk(color)->Right(color);
	}
	else return NULL;
}

