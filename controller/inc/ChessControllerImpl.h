#ifndef CHESS_CONTROLLER_IMPL_H
#define CHESS_CONTROLLER_IMPL_H

#include "ChessController.h"
#include "ChessGame.h"
#include "ChessGuiDefines.h"
#include "MyLogger.h"

class ChessControllerImpl : public ChessController
{
public:
	///Constructor
	ChessControllerImpl();
	ChessControllerImpl(ChessGame* game);
	~ChessControllerImpl();

	/**
	 * Indicate to the player that the user clicked on the given
	 * row and column with the mouse.
	 */
	void on_CellSelected(int row, int col, int button);
	
	///@param row where drag began
	///@param col where drag began
	void on_DragStart(int row,int col);

	///@param row where drag ended
	///@param col where drag ended
	///@return true if the drag resulted in a successful drop
	bool on_DragEnd(int row,int col);

	/**
	 * Handle when the user selected the new game button.
	 */
	void on_NewGame();

	/**
	 * Handle when the user selected the save game button.
	 */
	void on_SaveGame();

	/**
	 * Handle when the user selected the save game as button.
	 */
	void on_SaveGameAs();

	/**
	 * Handle when the user selected the load game button.
	 */
	void on_LoadGame();

	/**
	 * Handle when the user selected the undo move button.
	 */
	void on_UndoMove();
		
	/**
	 * Handle when the user selects to quit the game, either through the
	 * quit button, the close X button, or the file menu.
	 */
	void on_QuitGame();
		
	/**
	 * Handle when a timer event has been signaled.
	 */
	void on_TimerEvent();
	
	/**
	 * Set the ChessView that this ChessController will handle inputs for.
	 */
	void SetView(ChessView* view);
	
private:
	ChessGame* game;
	ChessView* view;
	Piece* selectedPiece;
	Cell* currentCell;
	
	void UpdateView();
	void HighlightValidMoves(Piece* piece);
	///@note not currently using this function; also, this uses the old
	/// way of finding valid moves
	void UnHighlightValidMoves(Piece* piece);
};

#endif

