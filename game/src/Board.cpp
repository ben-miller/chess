// Author: Ben Miller <Miller.Benjmn@Gmail.com>, (C) 2010
//
///@file Board.cpp An implementation of the Board class

#include "Board.h"
#include "Pieces.h"

Board::Board() {
	DbgMsg("Board::Board(Piece* emptyPiece)");
	cells = new Cell**[8];
	for (int i = 0; i < 8; i++) {
		cells[i] = new Cell*[8];
		for (int j = 0; j < 8; j++) {
			cells[i][j] = new Cell(this, i, j);
		}
	}
}
Board::~Board() {
	DbgMsg("Board::~Board()");
	for (int i = 0; i < 8; i++) {
	for (int j = 0; j < 8; j++) {
		delete cells[i][j];
	}
	}
}

void Board::BindCellsToPieces(Pieces* pieces) {
	DbgMsg("Board::BindCellsToPieces(Pieces* pieces)");
	
	// White pieces
	cells[6][0]->BindToPiece(pieces->gWhitePawn0());
	cells[6][1]->BindToPiece(pieces->gWhitePawn1());
	cells[6][2]->BindToPiece(pieces->gWhitePawn2());
	cells[6][3]->BindToPiece(pieces->gWhitePawn3());
	cells[6][4]->BindToPiece(pieces->gWhitePawn4());
	cells[6][5]->BindToPiece(pieces->gWhitePawn5());
	cells[6][6]->BindToPiece(pieces->gWhitePawn6());
	cells[6][7]->BindToPiece(pieces->gWhitePawn7());
	
	cells[7][0]->BindToPiece(pieces->gWhiteRook0());
	cells[7][1]->BindToPiece(pieces->gWhiteKnight0());
	cells[7][2]->BindToPiece(pieces->gWhiteBishop0());
	cells[7][3]->BindToPiece(pieces->gWhiteQueen());
	cells[7][4]->BindToPiece(pieces->gWhiteKing());
	cells[7][5]->BindToPiece(pieces->gWhiteBishop1());
	cells[7][6]->BindToPiece(pieces->gWhiteKnight1());
	cells[7][7]->BindToPiece(pieces->gWhiteRook1());
	
	// Black pieces
	cells[1][7]->BindToPiece(pieces->gBlackPawn0());
	cells[1][6]->BindToPiece(pieces->gBlackPawn1());
	cells[1][5]->BindToPiece(pieces->gBlackPawn2());
	cells[1][4]->BindToPiece(pieces->gBlackPawn3());
	cells[1][3]->BindToPiece(pieces->gBlackPawn4());
	cells[1][2]->BindToPiece(pieces->gBlackPawn5());
	cells[1][1]->BindToPiece(pieces->gBlackPawn6());
	cells[1][0]->BindToPiece(pieces->gBlackPawn7());
	
	cells[0][7]->BindToPiece(pieces->gBlackRook0());
	cells[0][6]->BindToPiece(pieces->gBlackKnight0());
	cells[0][5]->BindToPiece(pieces->gBlackBishop0());
	cells[0][4]->BindToPiece(pieces->gBlackKing());
	cells[0][3]->BindToPiece(pieces->gBlackQueen());
	cells[0][2]->BindToPiece(pieces->gBlackBishop1());
	cells[0][1]->BindToPiece(pieces->gBlackKnight1());
	cells[0][0]->BindToPiece(pieces->gBlackRook1());
}

Cell* Board::GetCell(int row, int col) {
	//DbgMsgRC("Board::GetCell(%d, %d)", row, col);
	return cells[row][col];
}
