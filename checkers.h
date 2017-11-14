#ifndef CHECKERS_H
#define CHECKERS_H

#include <QMainWindow>
#include <QDebug>   //give me cout for graphics
#include <QPainter>
#include <QMouseEvent>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Piece
{
public:
    Piece();
    bool isKing=false;
    std::string color;
    std::string getColor();
    int x,y;
    void setX(int xx);
    void setY(int yy);
    int getX();
    int getY();
    void setColor(std::string color);
    bool getIsKing();
    void setIsKing(bool king);
    //void Piece::draw(QPainter* paint, int x, int y);
    void draw(QPainter* paint, int x, int y);
    bool canMove(int startx, int starty, int endx, int endy);
    ~Piece();
};
class Checkers : public QMainWindow
{
    Q_OBJECT
public:
    Checkers(QWidget *parent = 0);
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent*e);
    void mouseReleaseEvent(QMouseEvent*e);
    ~Checkers();
};
#endif // CHECKERS_H
