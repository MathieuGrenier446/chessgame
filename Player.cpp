#include "Player.h"

view::Player::Player()
{
	chessBoard_ = modele::ChessBoard();
}

void view::Player::makeMove(modele::coordinate origin, modele::coordinate destination)
{
	chessBoard_.movePiece(origin, destination);
	emit updatePieces();
}

void view::Player::spaceClicked(modele::coordinate position)
{
	clickedSpaces_.push_back(position);

	if(clickedSpaces_.size() > 1)
	{
		makeMove(clickedSpaces_[0], clickedSpaces_[1]);
		clickedSpaces_.clear();
	}
}