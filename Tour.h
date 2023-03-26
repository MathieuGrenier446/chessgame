#pragma once
#include "Piece.h"

namespace modele { 
	class Tour : public Piece
	{
		public:

		Tour(char colour);

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
				return "black_tower.png";
			}
			else
			{
				return "white_tower.png";
			}
		}

		private:
		char colour_;
		char type_;
	};
}