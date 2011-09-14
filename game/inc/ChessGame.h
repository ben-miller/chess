// Author: Ben Miller <Miller.Benjmn@Gmail.com>, (C) 2010
//
///@file ChessGame.h Interface for the ChessGame class

#if !defined(CHESS_GAME_H)
#define CHESS_GAME_H

#include "Cell.h"
#include "PrisonCell.h"
#include "Piece.h"
#include "Pieces.h"
#include "Board.h"
#include "MoveHistory.h"
#include "MyLogger.h"

///@brief Main interface for the backend implementation of the chess game
///
/// This is the main interface for the backend implementation of the chess game
/// and is meant to be used by ChessControllerImpl
class ChessGame {

	public:
		/// Allocates a Board, a collection of Pieces,
		/// an empty Piece, and a PrisonCell on the heap
		ChessGame();
		
		/// Calls destructors on each heap-allocated member
		~ChessGame();
		
		///@name Getters (to be used by ChessControllerImpl)
		///@{

		/// Returns a pointer to the Cell of the respective row and column.
		///@param row and @param col correspond to those used in ChessController
		Cell* GetCell(int row, int col);
		/// Returns a pointer to the Piece held in the respective row and column.
		///@param row and @param col correspond to those used in ChessController
		Piece* GetPiece(int row, int col);
		
		Pieces* GetPieces();
		
		PieceColor GetCurrentPlayersColor();
		
		///@}
		
		///@return true if cell contains a piece of the player whose
		/// turn it is
		bool CellHasCurrentPlayersPiece(Cell* cell);
		
		/// Moves piece to destCell
		///@param piece
		///@param destCell
		///@todo have Move return a MoveRecord*
		MoveRecord* Move(Piece* piece, Cell* destCell);
		void UndoMove(MoveRecord* record);
		
		/// Checks if this player is in check
		bool PlayerInCheck(PieceColor playersColor);
		bool PlayerInCheckMate(PieceColor playersColor);
		
		/// Returns a new set of valid cells we can move to, 
		/// based on whether those moves will result in the 
		/// mover going into check. 
		std::set<Cell*>* GetValidMoves(Piece* piece);
		bool IsValidMove(Piece* piece, Cell* destCell);
		
		///@return true if the specified move will result in check for the given player
		bool MoveEndsUpInCheck(Piece* piece, Cell* cell, PieceColor playersColor);
		
		MoveRecord* PopMostRecentMoveRecord();
		
	private:
		Board* board;
		Pieces* pieces;
		
		PieceColor currentPlayersColor;
		MoveHistory* moveHistory;

};

#endif
