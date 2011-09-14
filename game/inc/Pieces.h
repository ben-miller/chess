// Author: Ben Miller <Miller.Benjmn@Gmail.com>, (C) 2010
//
///@file Pieces.h An interface for the Pieces class, a structured container of Piece objects. 

#if !defined(PIECES_H)
#define PIECES_H

#include "Board.h"
#include "Piece.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Pawn.h"
#include "MyLogger.h"

///@brief A class that instantiates and/or points to each piece on a chess board. 
/// This class is used by the ChessGame and PrisonCell classes to hold Piece objects. 
class Pieces {

	public:
		/// Empty Constructor
		Pieces();
		/// Alloc piece objects on heap (initially pointing to nothing)
		Pieces(Board* board);
		
		/// Sets appropriate member to piece
		void AddPiece(Piece* piece);

		///@name King Getters
		///@{
		Piece* gWhiteKing();
		Piece* gBlackKing();
		///@}
	
		///@name Queen Getters
		///@{
		Piece* gWhiteQueen();
		Piece* gBlackQueen();
		///@}
	
		///@name Rook Getters
		///@{
		Piece* gWhiteRook0();
		Piece* gWhiteRook1();
		Piece* gBlackRook0();
		Piece* gBlackRook1();
		///@}
	
		///@name Knight Getters
		///@{
		Piece* gWhiteKnight0();
		Piece* gWhiteKnight1();
		Piece* gBlackKnight0();
		Piece* gBlackKnight1();
		///@}
	
		///@name Bishop Getters
		///@{
		Piece* gWhiteBishop0();
		Piece* gWhiteBishop1();
		Piece* gBlackBishop0();
		Piece* gBlackBishop1();
		///@}
	
		///@name Pawn Getters
		///@{
		Piece* gWhitePawn0();
		Piece* gWhitePawn1();
		Piece* gWhitePawn2();
		Piece* gWhitePawn3();
		Piece* gWhitePawn4();
		Piece* gWhitePawn5();
		Piece* gWhitePawn6();
		Piece* gWhitePawn7();

		Piece* gBlackPawn0();
		Piece* gBlackPawn1();
		Piece* gBlackPawn2();
		Piece* gBlackPawn3();
		Piece* gBlackPawn4();
		Piece* gBlackPawn5();
		Piece* gBlackPawn6();
		Piece* gBlackPawn7();
		///@}

	private:
		Piece* whiteKing;
		Piece* blackKing;

		Piece* whiteQueen;
		Piece* blackQueen;

		Piece* whiteRook0;
		Piece* whiteRook1;
		Piece* blackRook0;
		Piece* blackRook1;

		Piece* whiteBishop0;
		Piece* whiteBishop1;
		Piece* blackBishop0;
		Piece* blackBishop1;

		Piece* whiteKnight0;
		Piece* whiteKnight1;
		Piece* blackKnight0;
		Piece* blackKnight1;

		Piece* whitePawn0;
		Piece* whitePawn1;
		Piece* whitePawn2;
		Piece* whitePawn3;
		Piece* whitePawn4;
		Piece* whitePawn5;
		Piece* whitePawn6;
		Piece* whitePawn7;
		Piece* blackPawn0;
		Piece* blackPawn1;
		Piece* blackPawn2;
		Piece* blackPawn3;
		Piece* blackPawn4;
		Piece* blackPawn5;
		Piece* blackPawn6;
		Piece* blackPawn7;

};

#endif


