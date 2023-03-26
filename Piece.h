#pragma once
#include <tuple>
#include <string>
#include <map>
#include <memory>
#include <QString>
#include <iostream>

namespace modele { 
	class Piece
	{
		public:
		using coordinate = std::tuple<int, int>;

		Piece(){};
		Piece(const char colour)
		{
			colour_ = colour;
		}
	
		virtual bool isPathClear(coordinate origin, coordinate destination, std::map<coordinate, std::shared_ptr<Piece>> board) = 0;
		virtual bool isMovePossible(coordinate origin, coordinate destination)= 0;
		virtual char getColour() { return colour_; };
		virtual QString getImagePath(){ return "a"; };

		protected:

		virtual int xPos(coordinate position) { return std::get<0>(position); }
		virtual int yPos(coordinate position) { return std::get<1>(position); }

		private:
		char colour_;
	};
}