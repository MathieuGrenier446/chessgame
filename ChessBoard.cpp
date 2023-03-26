#include "ChessBoard.h"

modele::ChessBoard::ChessBoard()
{
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			coordinate squarePosition(i,j);
			board_[squarePosition] = nullptr;
			placePiece<Fou>('B', coordinate(0, 0));
			placePiece<Fou>('W', coordinate(7, 7));
			placePiece<Tour>('B', coordinate(0, 1));
			placePiece<Tour>('W', coordinate(7, 5));
			placePiece<Knight>('B', coordinate(7, 6));
			placePiece<Knight>('W', coordinate(0, 2));
			placePiece<RoiRAII>('B', coordinate(5, 5));
			placePiece<RoiRAII>('W', coordinate(4, 4));
			placePiece<RoiRAII>('B', coordinate(3, 3));

		}
	}
}

bool modele::ChessBoard::isMoveLegal(coordinate origin, coordinate destination)
{
	std::shared_ptr<Piece> piece = getPiece(origin);
	if(piece != nullptr)
	{
		if(isPieceEnnemy(origin, destination) && piece->isMovePossible(origin, destination))
		{
			return piece->isPathClear(origin, destination, board_);
		}
	}	
	return false;
}

void modele::ChessBoard::movePiece(coordinate origin, coordinate destination)
{
	if(isMoveLegal(origin, destination))
	{
		board_[destination] = std::move(board_[origin]);
	}
}

template <typename T>
void modele::ChessBoard::placePiece(char colour, coordinate position)
{
	T piece = T(colour);
	std::shared_ptr<T> piece_ptr = std::make_shared<T>(piece);
	board_[position] = std::static_pointer_cast<Piece>(piece_ptr);
}

bool modele::ChessBoard::isPieceEnnemy(coordinate origin, coordinate destination)
{
	if(getPiece(destination) != nullptr)
	{
		char con1 = getPiece(destination)->getColour();
		char con2 = getPiece(origin)->getColour();
		char a = 'a';
		return getPiece(destination)->getColour() != getPiece(origin)->getColour();
	}
	return true;
}

bool modele::ChessBoard::isKingInCheck(char colour)
{
	return false;
}
