// Author: Ben Miller <Miller.Benjmn@Gmail.com>, (C) 2010
//
///@file Pieces.cpp An implementation of the Pieces class, a structured container of Piece objects. 

#include "Pieces.h"

Pieces::Pieces() {
	whiteKing = NULL;
	blackKing = NULL;

	whiteQueen = NULL;
	blackQueen = NULL;

	whiteRook0 = NULL;
	whiteRook1 = NULL;
	blackRook0 = NULL;
	blackRook1 = NULL;

	whiteBishop0 = NULL;
	whiteBishop1 = NULL;
	blackBishop0 = NULL;
	blackBishop1 = NULL;

	whiteKnight0 = NULL;
	whiteKnight1 = NULL;
	blackKnight0 = NULL;
	blackKnight1 = NULL;

	whitePawn0 = NULL;
	whitePawn1 = NULL;
	whitePawn2 = NULL;
	whitePawn3 = NULL;
	whitePawn4 = NULL;
	whitePawn5 = NULL;
	whitePawn6 = NULL;
	whitePawn7 = NULL;
	blackPawn0 = NULL;
	blackPawn1 = NULL;
	blackPawn2 = NULL;
	blackPawn3 = NULL;
	blackPawn4 = NULL;
	blackPawn5 = NULL;
	blackPawn6 = NULL;
	blackPawn7 = NULL;
}

Pieces::Pieces(Board* board) {
	
	whiteKing = new WhiteKing(board->GetCell( 7,4 ));
	blackKing = new BlackKing(board->GetCell( 0,4 ));

	whiteQueen = new WhiteQueen(board->GetCell( 7,3 ));
	blackQueen = new BlackQueen(board->GetCell( 0,3 ));

	whiteRook0 = new WhiteRook(board->GetCell( 7,0 ), 0);
	whiteRook1 = new WhiteRook(board->GetCell( 7,7 ), 1);
	blackRook0 = new BlackRook(board->GetCell( 0,7 ), 0);
	blackRook1 = new BlackRook(board->GetCell( 0,0 ), 1);

	whiteKnight0 = new WhiteKnight(board->GetCell( 7,1 ), 0);
	whiteKnight1 = new WhiteKnight(board->GetCell( 7,6 ), 1);
	blackKnight0 = new BlackKnight(board->GetCell( 0,6 ), 0);
	blackKnight1 = new BlackKnight(board->GetCell( 0,1 ), 1);

	whiteBishop0 = new WhiteBishop(board->GetCell( 7,2 ), 0);
	whiteBishop1 = new WhiteBishop(board->GetCell( 7,5 ), 1);
	blackBishop0 = new BlackBishop(board->GetCell( 0,5 ), 0);
	blackBishop1 = new BlackBishop(board->GetCell( 0,2 ), 1);

	whitePawn0 = new WhitePawn(board->GetCell( 6,0 ), 0);
	whitePawn1 = new WhitePawn(board->GetCell( 6,1 ), 1);
	whitePawn2 = new WhitePawn(board->GetCell( 6,2 ), 2);
	whitePawn3 = new WhitePawn(board->GetCell( 6,3 ), 3);
	whitePawn4 = new WhitePawn(board->GetCell( 6,4 ), 4);
	whitePawn5 = new WhitePawn(board->GetCell( 6,5 ), 5);
	whitePawn6 = new WhitePawn(board->GetCell( 6,6 ), 6);
	whitePawn7 = new WhitePawn(board->GetCell( 6,7 ), 7);
	blackPawn0 = new BlackPawn(board->GetCell( 1,7 ), 0);
	blackPawn1 = new BlackPawn(board->GetCell( 1,6 ), 1);
	blackPawn2 = new BlackPawn(board->GetCell( 1,5 ), 2);
	blackPawn3 = new BlackPawn(board->GetCell( 1,4 ), 3);
	blackPawn4 = new BlackPawn(board->GetCell( 1,3 ), 4);
	blackPawn5 = new BlackPawn(board->GetCell( 1,2 ), 5);
	blackPawn6 = new BlackPawn(board->GetCell( 1,1 ), 6);
	blackPawn7 = new BlackPawn(board->GetCell( 1,0 ), 7);
	
}


void Pieces::AddPiece(Piece* piece) {
	
	switch (piece->GetType()) {
		
		case KING:
			if (piece->GetColor() == WHITE)
				whiteKing = piece;
			else
				blackKing = piece;
			break;
		
		case QUEEN:
			if (piece->GetColor() == WHITE)
				whiteQueen = piece;
			else
				blackQueen = piece;
			break;
			
		case ROOK:
			if (piece->GetColor() == WHITE) {
				if (piece->GetId() == 0)
					whiteRook0 = piece;
				else
					whiteRook1 = piece;
			}
			else {
				if (piece->GetId() == 0)
					blackRook0 = piece;
				else
					blackRook1 = piece;
			}
			break;
		
		case KNIGHT:
			if (piece->GetColor() == WHITE) {
				if (piece->GetId() == 0)
					whiteKnight0 = piece;
				else
					whiteKnight1 = piece;
			}
			else {
				if (piece->GetId() == 0)
					blackKnight0 = piece;
				else
					blackKnight1 = piece;
			}
			break;
		
		case BISHOP:
			if (piece->GetColor() == WHITE) {
				if (piece->GetId() == 0)
					whiteBishop0 = piece;
				else
					whiteBishop1 = piece;
			}
			else {
				if (piece->GetId() == 0)
					blackBishop0 = piece;
				else
					blackBishop1 = piece;
			}
			break;
			
		case PAWN:
			if (piece->GetColor() == WHITE) {
				switch (piece->GetId()) {
					case 0:
						piece = whitePawn0;
						break;
					case 1:
						piece = whitePawn1;
						break;
					case 2:
						piece = whitePawn2;
						break;
					case 3:
						piece = whitePawn3;
						break;
					case 4:
						piece = whitePawn4;
						break;
					case 5:
						piece = whitePawn5;
						break;
					case 6:
						piece = whitePawn6;
						break;
					case 7:
						piece = whitePawn7;
						break;
				}
			}
			else {
				switch (piece->GetId()) {
					case 0:
						piece = blackPawn0;
						break;
					case 1:
						piece = blackPawn1;
						break;
					case 2:
						piece = blackPawn2;
						break;
					case 3:
						piece = blackPawn3;
						break;
					case 4:
						piece = blackPawn4;
						break;
					case 5:
						piece = blackPawn5;
						break;
					case 6:
						piece = blackPawn6;
						break;
					case 7:
						piece = blackPawn7;
						break;
				}
			}
			break;
		
	}
	
	
}

Piece* Pieces::gWhiteKing() {
	return whiteKing;
}
Piece* Pieces::gBlackKing() {
	return blackKing;
}

Piece* Pieces::gWhiteQueen() {
	return whiteQueen;
}
Piece* Pieces::gBlackQueen() {
	return blackQueen;
}

Piece* Pieces::gWhiteRook0() {
	return whiteRook0;
}
Piece* Pieces::gWhiteRook1() {
	return whiteRook1;
}
Piece* Pieces::gBlackRook0() {
	return blackRook0;
}
Piece* Pieces::gBlackRook1() {
	return blackRook1;
}

Piece* Pieces::gWhiteKnight0() {
	return whiteKnight0;
}
Piece* Pieces::gWhiteKnight1() {
	return whiteKnight1;
}
Piece* Pieces::gBlackKnight0() {
	return blackKnight0;
}
Piece* Pieces::gBlackKnight1() {
	return blackKnight1;
}

Piece* Pieces::gWhiteBishop0() {
	return whiteBishop0;
}
Piece* Pieces::gWhiteBishop1() {
	return whiteBishop1;
}
Piece* Pieces::gBlackBishop0() {
	return blackBishop0;
}
Piece* Pieces::gBlackBishop1() {
	return blackBishop1;
}

Piece* Pieces::gWhitePawn0() {
	return whitePawn0;
}
Piece* Pieces::gWhitePawn1() {
	return whitePawn1;
}
Piece* Pieces::gWhitePawn2() {
	return whitePawn2;
}
Piece* Pieces::gWhitePawn3() {
	return whitePawn3;
}
Piece* Pieces::gWhitePawn4() {
	return whitePawn4;
}
Piece* Pieces::gWhitePawn5() {
	return whitePawn5;
}
Piece* Pieces::gWhitePawn6() {
	return whitePawn6;
}
Piece* Pieces::gWhitePawn7() {
	return whitePawn7;
}

Piece* Pieces::gBlackPawn0() {
	return blackPawn0;
}
Piece* Pieces::gBlackPawn1() {
	return blackPawn1;
}
Piece* Pieces::gBlackPawn2() {
	return blackPawn2;
}
Piece* Pieces::gBlackPawn3() {
	return blackPawn3;
}
Piece* Pieces::gBlackPawn4() {
	return blackPawn4;
}
Piece* Pieces::gBlackPawn5() {
	return blackPawn5;
}
Piece* Pieces::gBlackPawn6() {
	return blackPawn6;
}
Piece* Pieces::gBlackPawn7() {
	return blackPawn7;
}



