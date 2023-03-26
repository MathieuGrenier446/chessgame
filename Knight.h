#pragma once
#include "Piece.h"

namespace modele{ 
	class Knight : public Piece
	{
		public:

		Knight(char colour);

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
				return "black_knight.png";
			}
			else
			{
				return "white_knight.png";
			}
		}

		private:
		char colour_;
		char type_;
	};
}