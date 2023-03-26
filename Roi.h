#pragma once
#include "Piece.h"
#include <exception>
#include <optional>

namespace modele { 
	class Roi : public Piece
	{
		public:
		Roi(){ };
		Roi(char colour);

		virtual char getColour() {return colour_;};
		virtual bool isPathClear(coordinate origin, coordinate destination, std::map<coordinate, std::shared_ptr<Piece>> board);
		virtual bool isMovePossible(coordinate origin, coordinate destination);
		virtual QString getImagePath()
		{
			if(colour_ == 'B')
			{
				return "black_king.png";
			}
			else
			{
				return "white_king.png";
			}
		}

		private:
		static int instanceCount_;
		char colour_;
	};

	class RoiRAII : public Roi
	{
		public:
		RoiRAII(char colour){ 
			try
			{
				roi_ = new Roi(colour);
			}
			catch(std::string& str)
			{
				std::cout << str; 
			}
		};

		~RoiRAII() { delete roi_; }

		private:
		Roi* roi_;
		static int instanceCount_;
	};
}