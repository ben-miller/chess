// Author: Ben Miller <Miller.Benjmn@Gmail.com>, (C) 2010
//
///@file ChessGame.cpp Implementation of the ChessGame class

#include "ChessGame.h"

ChessGame::ChessGame() {
	//DbgMsg("ChessGame::ChessGame()");
	
	board = new Board();
	pieces = new Pieces(board);
	board->BindCellsToPieces(pieces);
	
	moveHistory = new MoveHistory();
	currentPlayersColor = WHITE;
}
ChessGame::~ChessGame() {
	//DbgMsg("ChessGame::~ChessGame()");
	
	delete board;
	delete pieces;
	delete moveHistory;
	
}


Cell* ChessGame::GetCell(int row, int col) {
	//DbgMsgRC("ChessGame::GetCell(%d, %d)", row, col);
	return board->GetCell( row,col );
}
Piece* ChessGame::GetPiece(int row, int col) {
	//DbgMsgRC("ChessGame::GetPiece(%d, %d)", row, col);
	if (board->GetCell(row, col) == NULL) {
		DbgMsg("error*****: board->GetCell(row, col) == NULL");
		return NULL;
	}
	return board->GetCell( row,col )->GetPiece();
}
Pieces* ChessGame::GetPieces() {
	return pieces;
}

PieceColor ChessGame::GetCurrentPlayersColor() {
	return currentPlayersColor;
}

bool ChessGame::CellHasCurrentPlayersPiece(Cell* cell) {
	return (cell->GetPiece()->GetColor() == currentPlayersColor);
}

MoveRecord* ChessGame::Move(Piece* piece, Cell* destCell) {
	//DbgMsg("ChessGame::Move");
	// we assume destCell is a valid cell
	
	MoveRecord* moveRecord = new MoveRecord(piece, destCell);
	
	// A1, B1
	piece->GetCell()->BindToPiece(NULL);
	// A2, B2
	piece->BindToCell(destCell);
	if (destCell->GetPiece() == NULL) {
		// A3
		destCell->BindToPiece(piece);
	}
	else {
		// B3
		destCell->GetPiece()->BindToCell(NULL);
		// B4
		destCell->BindToPiece(piece);
	}
	
	// now it's the other player's turn
	currentPlayersColor = (currentPlayersColor == WHITE) ? BLACK : WHITE;
	
	return moveRecord;
}
void ChessGame::UndoMove(MoveRecord* moveRecord) {
	//DbgMsg("ChessGame::UndoMove");
	
	// undo everything the given move did
	if (moveRecord->GetDisplacedPiece() == NULL) {
		moveRecord->GetDestCell()->BindToPiece(NULL);
	}
	else {
		moveRecord->GetDestCell()->BindToPiece(moveRecord->GetDisplacedPiece());
		moveRecord->GetDisplacedPiece()->BindToCell(moveRecord->GetDestCell());
	}
	
	moveRecord->GetMovedPiece()->BindToCell(moveRecord->GetHomeCell());
	moveRecord->GetHomeCell()->BindToPiece(moveRecord->GetMovedPiece());
	
	// now it's the other player's turn again
	currentPlayersColor = (currentPlayersColor == WHITE) ? BLACK : WHITE;
	
	// delete the move record created by the last move
	delete moveRecord;
}

bool ChessGame::PlayerInCheck(PieceColor playersColor) {
	//DbgMsg("ChessGame::PlayerInCheck?");
	
	// run through each cell on the board
	for (int i = 0; i < 8; i++) {		
	for (int j = 0; j < 8; j++) {
		// if the cell has the other player's piece
		if (board->GetCell( i,j )->GetPiece() != NULL && 
			board->GetCell( i,j )->GetPiece()->GetColor() != playersColor )
		{
			// if the piece has this player's king's cell as a valid move
			if (playersColor == WHITE &&
				board->GetCell( i,j )->GetPiece()->ValidMovesContains(pieces->gWhiteKing()->GetCell()) )
			{
				return true;
			}
			else if (playersColor == BLACK &&
				board->GetCell( i,j )->GetPiece()->ValidMovesContains(pieces->gBlackKing()->GetCell()) )
			{
				return true;
			}
		}
	}
	}
	
	return false;
}
bool ChessGame::PlayerInCheckMate(PieceColor playersColor) {
	//DbgMsg("ChessGame::PlayerInCheckMate?");
	
	for (int i = 0; i < 8; i++) {
	for (int j = 0; j < 8; j++) {
		// if any pieces of this color still have valid moves
		if (GetPiece( i,j ) != NULL && 
			GetPiece( i,j )->GetColor() == playersColor && 
			!GetValidMoves(GetPiece( i,j ))->empty() )
		{
			// we are not in checkmate
			return false;
		}
	}
	}
	
	// otherwise we are in checkmate
	return true;
}
std::set<Cell*>* ChessGame::GetValidMoves(Piece* piece) {
	//DbgMsg("ChessGame::GetValidMoves");
	
	std::set<Cell*> tmp;
	
	// run through the set of previously valid moves
	std::set<Cell*>* validMoves = piece->GetValidMoves();
	std::set<Cell*>::iterator it = validMoves->begin();
	while (it != validMoves->end()) {
		// if the move won't result in check for the given player, 
		if (!MoveEndsUpInCheck(piece, *it, currentPlayersColor)) {
			// it has passed the final test of becoming a valid move
			tmp.insert(*it);
		}
		it++;
	}
	
	validMoves->swap(tmp);
	
	return validMoves;
}
bool ChessGame::IsValidMove(Piece* piece, Cell* destCell) {
	std::set<Cell*>* validMoves = GetValidMoves(piece);
	return (validMoves->find(destCell) != validMoves->end());
}
bool ChessGame::MoveEndsUpInCheck(Piece* piece, Cell* cell, PieceColor playersColor) {
	//DbgMsg("ChessGame::MoveEndsUpInCheck?");
	
	MoveRecord* moveRecord = Move(piece, cell);
	
	// a variable for telling if the move will end up in check
	bool resultsInCheck;
	
	resultsInCheck = PlayerInCheck(playersColor);
	
	UndoMove(moveRecord);
	
	return resultsInCheck;
}

MoveRecord* ChessGame::PopMostRecentMoveRecord() {
	return moveHistory->PopMostRecentMoveRecord();
}
