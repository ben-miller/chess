// Author: Ben Miller <Miller.Benjmn@Gmail.com>, (C) 2010
//
///@file MoveHistory.h An interface for the %Move & %MoveHistory classes

#include <stack>

class Cell;
class Piece;

class MoveRecord {

	public:
		MoveRecord(Piece* piece, Cell* destCell) {
			this->homeCell = piece->GetCell();
			this->destCell = destCell;
			this->movedPiece = piece;
			this->displacedPiece = destCell->GetPiece();
		}

		Cell* GetHomeCell() {
			return homeCell;
		}
		Cell* GetDestCell() {
			return destCell;
		}
		Piece* GetMovedPiece() {
			return movedPiece;
		}
		Piece* GetDisplacedPiece() {
			return displacedPiece;
		}

	private:
		// store information on all pieces involves in the move
		Cell* homeCell;
		Cell* destCell;
		Piece* movedPiece;
		Piece* displacedPiece;
};

class MoveHistory {

	public:
		MoveHistory() {

			moves = new std::stack<MoveRecord*>();

		}

		void AddMove(Piece* piece, Cell* destCell) {

			MoveRecord* move = new MoveRecord(piece, destCell);
			moves->push(move);

		}

		MoveRecord* PopMostRecentMoveRecord() {
			MoveRecord* top = moves->top();
			moves->pop();
			return top;
		}

	private:
		std::stack<MoveRecord*>* moves;

};


