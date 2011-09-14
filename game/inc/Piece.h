// Author: Ben Miller <Miller.Benjmn@Gmail.com>, (C) 2010
//
///@file Piece.h A virtual interface for the %Piece class

#if !defined(PIECE_H)
#define PIECE_H

#include <set>
#include "ChessGuiDefines.h"
#include "Cell.h"
#include "MyLogger.h"

///@brief Virtual base class for all %Piece objects
class Piece {

	public:

		///@name Setters
		///@{
			
		/// Change the cell the piece points to. 
		void BindToCell(Cell* cell) {
			this->cell = cell;
		}			
		
		///@}

		///@name Getters
		///@{
		Cell* GetCell() {
			return cell;
		}
		PieceType GetType() {
			return type;
		}
		PieceColor GetColor() {
			return color;
		}
		ImageName GetImageName() {
			return imageName;
		}
		int GetId() {
			return id;
		}
		int GetRow() {
			if (cell == NULL)
				return -1;
			else
				return cell->GetRow();
		}
		int GetCol() {
			if (cell == NULL)
				return -1;
			else
				return cell->GetCol();
		}
		///@}
		
		///@name Valid Moves
		///@{
		
		/// Returns a set of the cells this piece is allowed to move to
		virtual std::set<Cell*>* GetValidMoves() = 0;
		/// @return true if cell is in the set of valid moves
		virtual bool ValidMovesContains(Cell* cell) = 0;
		
		///@}
		
	protected:
		PieceType type;
		PieceColor color;
		ImageName imageName;
		int id;
		
		/// A pointer to the cell this piece is bound to (already exists on heap). 
		Cell* cell;
		
		/// A pointer to a set (allocated by this class) containing the 
		/// cells this piece can move to.  
		///@note This set should never contain the cell this piece is bound to. 
		///@note This set should always be updated when it is called by
		/// GetValidMoves() or ValidMovesContains()
		std::set<Cell*>* validMoves;
		
		/// Update validMoves to match the state of the current board. 
		virtual void UpdateValidMoves() = 0;
};

#endif
