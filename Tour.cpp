#include "Tour.h"

modele::Tour::Tour(char colour)
{
	colour_ = colour;
}

bool modele::Tour::isPathClear(coordinate origin, coordinate destination, std::map<coordinate, std::shared_ptr<Piece>> board)
{
	int xDirection = xPos(origin) != xPos(destination) ? 1 : 0;
	int yDirection = yPos(origin) != yPos(destination) ? 1 : 0;

	for(int i = 0; i < abs(xPos(origin) - xPos(destination)); i++)
	{
		for(int j = 0; j < abs(yPos(origin) - yPos(destination)); j++)
		{
			if(!(board[coordinate(xPos(origin) + xDirection * i, yPos(origin) + yDirection * j)] == nullptr))
			{
				return false;
			}
		}
	}
	return true;
}

bool modele::Tour::isMovePossible(coordinate origin, coordinate destination)
{
	if((xPos(origin) == xPos(destination)) && (yPos(origin) != yPos(destination)))
	{
		return true;
	}
	else if (yPos(origin) == yPos(destination) && xPos(origin) != xPos(destination))
	{
		return true;
	}
	return  false;
}

