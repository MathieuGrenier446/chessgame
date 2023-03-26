#pragma once
#include "Piece.h"
#include <string>

namespace modele { 
	class Fou : public Piece
	{	
		public:

		Fou(const char colour);

		virtual char getColour()
		{
			return colour_;
		};
		bool isPathClear(coordinate origin, coordinate destination, std::map<coordinate, std::shared_ptr<Piece>> board);
		bool isMovePossible(coordinate origin, coordinate destination);
		QString getImagePath()
		{
			if(colour_ == 'B')
			{
				return "black_bishop.png";
			}
			else
			{
				return "white_bishop.png";
			}
		}

		private:
		char colour_;
		char type_;
	
	};
}