#include "Fou.h"

modele::Fou::Fou(const char colour)
{
	colour_ = colour;
}

bool modele::Fou::isPathClear(coordinate origin, coordinate destination, std::map<coordinate, std::shared_ptr<Piece>> board)
{
	int xDirection = xPos(origin) < xPos(destination) ? 1 : -1;
	int yDirection = yPos(origin) < yPos(destination) ? 1 : -1;

	for(int i = 1; i < abs(xPos(origin)-xPos(destination)); i++)
	{
		for(int j = 1; j < abs(yPos(origin) - yPos(destination)); j++)
		{
			if(!(board[coordinate(xPos(origin) + xDirection * i, yPos(origin) + yDirection * j)] == nullptr))
			{
				return false;
			}
		}
	}
	return true;
};

bool modele::Fou::isMovePossible(coordinate origin, coordinate destination)
{
	return abs(xPos(origin) - xPos(destination)) == abs(yPos(origin) - yPos(destination));
};

