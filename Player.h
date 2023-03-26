#pragma once
#include "ChessBoard.h"
#include <QObject>
#include <vector>

namespace view { 
	class Player : public QObject
	{
		Q_OBJECT
		public:
		Player();
		void spaceClicked(modele::coordinate position);
		void makeMove(modele::coordinate origin, modele::coordinate destination);
		modele::ChessBoard& getBoard() { return chessBoard_; }

		signals:
		void updatePieces();


		private:
		modele::ChessBoard chessBoard_;
		std::vector<modele::coordinate> clickedSpaces_;

	};
}