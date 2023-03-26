#pragma once
#include <map>
#include <memory>
#include <iostream>
#include "Fou.h"
#include "Knight.h"
#include "Tour.h"
#include "Roi.h"

namespace modele { 
	using coordinate = std::tuple<int, int>;

	class ChessBoard
	{
		public:
		ChessBoard();
	
		std::shared_ptr<Piece>& operator[](coordinate position)
		{
			return board_[position];
		}
	
		bool isMoveLegal(coordinate origin, coordinate destination);
		void movePiece(coordinate origin, coordinate destination);
		bool isKingInCheck(char colour);
	
		std::shared_ptr<Piece> getPiece(coordinate position) { return board_[position]; };

		protected:
		std::map<coordinate, std::shared_ptr<Piece>> board_;

		private:
		bool isPieceEnnemy(coordinate origin, coordinate destination);
		template <typename T>
		void placePiece(char colour, coordinate position);
	};
}