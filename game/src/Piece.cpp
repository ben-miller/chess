/*
// Author: Ben Miller <Miller.Benjmn@Gmail.com>, (C) 2010
//
///@file Piece.cpp An implementation of the Piece class

#include "Piece.h"

Piece::Piece() {
	this->id = id;
	this->type = EMPTY;
	this->imageName = NO_IMAGE;
	this->color = NEITHER;
	this->validMoves = new std::set<Cell*>();
}
Piece::Piece(Cell* cell, int id) {
	this->cell = cell;
	this->id = id;
	this->type = EMPTY;
	this->imageName = NO_IMAGE;
	this->color = NEITHER;
	this->validMoves = new std::set<Cell*>();
}
Piece::~Piece() {
	
	
	
}


void Piece::BindToCell(Cell* cell) {
	this->cell = cell;
}

Cell* Piece::GetCell() {
	return cell;
}
PieceType Piece::GetType() {
	return type;
}
ImageName Piece::GetImageName() {
	//DbgMsg("Piece::GetImageName()");
	return imageName;
}
PieceColor Piece::GetColor() {
	return color;
}
int Piece::GetId() {
	return id;
}


std::set<Cell*>* Piece::ValidMoves() {
	DbgMsg("Piece::ValidMoves()");
	return NULL;
}

bool Piece::ValidMovesContains(Cell* cell) {
	DbgMsg("Piece::ValidMovesContains(Cell* cell)");
	return false;
}
*/
