#include "Knight.h"

modele::Knight::Knight(char colour)
{
	colour_ = colour;
}

bool modele::Knight::isPathClear(coordinate origin, coordinate destination, std::map<coordinate, std::shared_ptr<Piece>> board)
{
	return true;
}

bool modele::Knight::isMovePossible(coordinate origin, coordinate destination)
{
	coordinate possibleMoves[8] = {coordinate(1,2), coordinate(2,1), coordinate(1,-2), 
	                               coordinate(-1,-2), coordinate(-2,-1), coordinate(2,-1),
	                               coordinate(-2,1), coordinate(-1,2)};

	for(coordinate move : possibleMoves)
	{
		if(xPos(origin) + xPos(move) == xPos(destination) && yPos(origin) + yPos(move) == yPos(destination))
		{
			return true;
		}
	}
	return false;
}