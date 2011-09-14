
#include "ChessControllerImpl.h"

ChessControllerImpl::ChessControllerImpl()
{
	DbgMsg("ChessControllerImpl::ChessControllerImpl()");
	selectedPiece = NULL;
}

ChessControllerImpl::ChessControllerImpl(ChessGame* game)
{
	DbgMsg("ChessControllerImpl::ChessControllerImpl(ChessGame* game)");
	selectedPiece = NULL;
	this->game = game;
}

ChessControllerImpl::~ChessControllerImpl()
{
	DbgMsg("ChessControllerImpl::~ChessControllerImpl()");
}


void ChessControllerImpl::on_CellSelected(int row, int col, int button)
{
	//DbgMsgRCB("ChessControllerImpl::on_CellSelected(%d, %d, %d)", row, col, button);
	
	// update currentCell
	currentCell = game->GetCell( row,col );
	
	// if a piece hasn't been selected
	if (selectedPiece == NULL) {
		// (nothing should be highlighted)
		
		// if we hit an empty cell
		if (currentCell->GetPiece() == NULL) {
			// keep it null
		}
		// if we hit a piece of our own color
		else if (currentCell->GetPiece()->GetColor() == game->GetCurrentPlayersColor()) {
			// set selectedPiece to currentCell's piece
			selectedPiece = currentCell->GetPiece();
		}
		// if we hit the other player's piece
		else {
			// keep it null
		}
	}
	// if we hit the already selected cell
	else if (currentCell == selectedPiece->GetCell()) {
		
		// clear selectedPiece
		selectedPiece = NULL;
	}
	// a cell has been selected and we hit something other than
	//   the cell of our selectedPiece
	else {
		
		// if the current cell is a valid move for the selected piece
		if (game->IsValidMove(selectedPiece, currentCell)) {
			// move selectedPiece to currentCell
			game->Move(selectedPiece, currentCell);
			if (game->PlayerInCheck(game->GetCurrentPlayersColor())) {
				if (game->GetCurrentPlayersColor() == WHITE) {
					DbgMsg("White in check!");
				}
				else {
					DbgMsg("Black in check!");
				}
				
				// check to see if current player is in check mate
				if (game->PlayerInCheckMate(game->GetCurrentPlayersColor())) {
					DbgMsg("Check Mate! *************************************************");
				}
			}
			
			// clear selectedPiece
			selectedPiece = NULL;
		}
		// otherwise the currentCell is an invalid move
		else {
			// if we hit an empty cell
			if (currentCell->GetPiece() == NULL) {
				
				// clear selectedPiece
				selectedPiece = NULL;
			}
			// if we hit a piece of our own color
			else if (currentCell->GetPiece()->GetColor() == game->GetCurrentPlayersColor()) {
				
				// set selectedPiece to currentCell's piece
				selectedPiece = currentCell->GetPiece();
				
			}
			// if we hit the other player's piece
			else {
				
				// clear selectedPiece
				selectedPiece = NULL;
				
			}
			
		}
		
	}
			
	// update view
	///@todo maybe speed up how we do this?
	UpdateView();
		
	if (selectedPiece == NULL) {
		//DbgMsg("selectedPiece (after): NULL");
	}
	else {
		//DbgMsgRC("selectedPiece (after): (%d, %d)", selectedPiece->GetRow(), selectedPiece->GetCol());
	}
	
}


void ChessControllerImpl::on_DragStart(int row,int col)
{
	DbgMsgRC("ChessControllerImpl::on_DragStart(%d, %d)", row, col);
	// if the current cell is a valid cell for this player, 
		// set selectedCell to this cell
		// highlight valid moves
}


bool ChessControllerImpl::on_DragEnd(int row,int col)
{
	DbgMsgRC("ChessControllerImpl::on_DragEnd(%d, %d)", row, col);
	// set currentCell to this cell
	// if currentCell is in the valid moves for selectedCell
		// move selectedCell to currentCell
		// clear selectedCell
		// unhighlight valid moves
	// otherwise
		// do nothing: keep highlighted, keep selectedCell
		
	return false;
}


void ChessControllerImpl::on_NewGame()
{
	DbgMsg("ChessControllerImpl::on_NewGame()");
	UpdateView();
	// reset ChessGame
}


void ChessControllerImpl::on_SaveGame()
{
	DbgMsg("ChessControllerImpl::on_SaveGame()");
}


void ChessControllerImpl::on_SaveGameAs()
{
	DbgMsg("ChessControllerImpl::on_SaveGameAs()");
}


void ChessControllerImpl::on_LoadGame()
{
	DbgMsg("ChessControllerImpl::on_LoadGame()");
}


void ChessControllerImpl::on_UndoMove()
{
	DbgMsg("ChessControllerImpl::on_UndoMove()");
	//game->UndoMove(game->PopMostRecentMoveRecord());
	//UpdateView();
}


void ChessControllerImpl::on_QuitGame()
{
	DbgMsg("ChessControllerImpl::on_QuitGame()");
}

	
void ChessControllerImpl::on_TimerEvent()
{
	//DbgMsg("ChessControllerImpl::on_TimerEvent()");
}


void ChessControllerImpl::SetView(ChessView* view)
{
	DbgMsg("ChessControllerImpl::SetView(ChessView* view)");
	this->view = view;
}

void ChessControllerImpl::HighlightValidMoves(Piece* piece)
{
	//DbgMsg("ChessControllerImpl::HighlightValidMoves(Piece* piece)");
	
	std::set<Cell*>* tmp = game->GetValidMoves(piece);
	//std::set<Cell*>* tmp = piece->GetValidMoves();
	
	// filter valid moves so king won't go in check
	//game->FilterValidMoves(&tmp);
	
	std::set<Cell*>::iterator it = tmp->begin();
	while (it != tmp->end()) {
		view->HighlightSquare( (*it)->GetRow(),(*it)->GetCol(), GREEN_SQUARE);
		it++;
	}
}

/*
void ChessControllerImpl::UnHighlightValidMoves(Piece* piece)
{
	//DbgMsg("ChessControllerImpl::UnHighlightValidMoves(Piece* piece)");
	std::set<Cell*>* tmp = piece->GetValidMoves();
	std::set<Cell*>::iterator it = tmp->begin();
	while (it != tmp->end()) {
		view->UnHighlightSquare( (*it)->GetRow(),(*it)->GetCol() );
		it++;
	}
}
*/

void ChessControllerImpl::UpdateView()
{
	//DbgMsg("ChessControllerImpl::UpdateView()");
	
	// run through each cell
	for (int i = 0; i < 8; i++) {
	for (int j = 0; j < 8; j++) {
		// clear highlighted squares
		view->UnHighlightSquare( i,j );
		
		// place pieces where they should be
		if (game->GetPiece( i,j ) == NULL) {
			view->ClearPiece( i,j );
		}
		else {
			view->PlacePiece( i,j, game->GetPiece( i,j )->GetImageName());
		}
	}
	}
	
	// highlight selected piece & its valid moves
	if (selectedPiece != NULL) {
		view->HighlightSquare( selectedPiece->GetRow(),selectedPiece->GetCol(), BLUE_SQUARE);
		HighlightValidMoves(selectedPiece);
	}
	
}

