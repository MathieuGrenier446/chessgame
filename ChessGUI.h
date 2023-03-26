#pragma once
#include <QMainWindow>
#include <QApplication>
#include <QHBoxLayout>
#include <QPushButton>
#include <QButtonGroup>
#include <QLabel>
#include <QString>
#include <QVariant>
#include <iostream>
#include "Player.h"
#include "ChessBoard.h"

namespace view { 
    class ChessBoardGUI : public QMainWindow
    {
        Q_OBJECT
        public:
        ChessBoardGUI(QWidget* parent = nullptr);
        ~ChessBoardGUI() override = default;
        void setPieceIcon(int i, int j);

        public slots:
        void updatePieces();

        private:
        QPushButton* board_[8][8];
        Player player_;
        modele::ChessBoard& chessBoard_ = player_.getBoard();
    };
}