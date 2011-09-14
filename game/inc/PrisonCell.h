/*

// Author: Ben Miller <Miller.Benjmn@Gmail.com>, (C) 2010
//
///@file PrisonCell.h An interface for the PrisonCell class

#if !defined(PRISON_CELL_H)
#define PRISON_CELL_H

#include <string>
#include "Cell.h"
#include "Pieces.h"
#include "MyLogger.h"

///@brief A Cell that holds Pieces. 
class PrisonCell : public Cell {

	public:
		/// Init %PrisonCell w/ each member pointing to its respective piece in pieces. 
		///@note These pieces should already be allocated on the heap. (assert?)
		PrisonCell();

		///@name Setters
		///@{
		void BindToPiece(Piece* piece);
		///@}
		
	private:
		/// This is full of pointers to pieces already existing on the heap. 
		Pieces* pieces;

};

#endif

*/
