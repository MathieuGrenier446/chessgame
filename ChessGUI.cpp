#include "ChessGUI.h"

view::ChessBoardGUI::ChessBoardGUI(QWidget* parent) : QMainWindow(parent)
{
    chessBoard_ = modele::ChessBoard();
    auto widgetPrincipal = new QWidget(this);
    auto layoutPrincipal = new QGridLayout(widgetPrincipal);

    layoutPrincipal->setSpacing(0);
    layoutPrincipal->setVerticalSpacing(0);

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            board_[i][j] = new QPushButton(this);
            board_[i][j]->setFixedSize(70, 70);
            if((i+j) % 2 == 0)
            {
                board_[i][j]->setStyleSheet("border: 0px ; background: #FF5DA8");
            }
            else
            {
                board_[i][j]->setStyleSheet("border: 0px ; background: #FFFEFC");
            }
            layoutPrincipal->addWidget(board_[i][j], j, i);
            QObject::connect(board_[i][j], &QPushButton::clicked, &player_, [this, i, j]() { player_.spaceClicked(modele::coordinate(i, j)); });
            
            setPieceIcon(i, j);
        }
    }
    QObject::connect(&player_, &Player::updatePieces, this, &ChessBoardGUI::updatePieces);
    setCentralWidget(widgetPrincipal);
}

void view::ChessBoardGUI::setPieceIcon(int i, int j)
{
    if(chessBoard_.getPiece(modele::coordinate(i,j)))
    {
        QString image_path = chessBoard_.getPiece(modele::coordinate(i,j))->getImagePath();
        board_[i][j]->setIcon(QIcon(QPixmap(image_path)));
    }
    else
    {
        board_[i][j]->setIcon(QIcon());
    }
}


void view::ChessBoardGUI::updatePieces()
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            setPieceIcon(i, j);
        }
    }

}

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    view::ChessBoardGUI gui;
    gui.show();
    return app.exec();
}
