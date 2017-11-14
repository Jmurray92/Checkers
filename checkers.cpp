#include "checkers.h"
Piece Pieces[8][8];
int startX=0,startY=0,endX=0,endY=0,BLACKMOVES=0;
bool arraySetUp=false;
bool blackHasMoved=false;
bool turn = true;
string colorChange;
Piece::Piece()
{

}
bool canMove(int startx, int starty, int endx, int endy)
{
    if(Pieces[starty][startx].getColor()=="null")
    {
        qDebug()<<" 1 IF";
        return(false);
    }
    if(Pieces[endy][endx].getColor()!="null")
    {
        qDebug()<<" 2 IF";
        return(false);
    }
    if(Pieces[endy][endx].getColor()=="empty")
    {
        qDebug()<<" 3 IF";
        return(false);
    }
    if(Pieces[starty][startx].getColor()=="empty")
    {
        qDebug()<<" 4 IF";
        return(false);
    }
    if(starty<0||starty>7)
    {
        qDebug()<<" 5 IF";
        return(false);
    }
    if(startx<0||startx>7)
    {
        qDebug()<<" 6 IF";
        return(false);
    }
    if(endy<0||endy>7)
    {
        qDebug()<<" 7 IF";
        return(false);
    }
    if(endx<0||endx>7)
    {
        qDebug()<<" 8 IF";
        return(false);
    }
    if(Pieces[starty][startx].getColor()=="red"&&Pieces[starty][startx].getIsKing()!=true)
    {
        if(starty<endy)
        {
            qDebug()<<" 9 IF";
            return(false);
        }
    }
    if(Pieces[starty][startx].getColor()=="black"&&Pieces[starty][startx].getIsKing()!=true)
    {
        if(starty>endy)
        {
            qDebug()<<" 10 IF";
            return(false);
        }
    }
    if(abs(startx-endx)!=1&&Pieces[starty][startx].getIsKing()!=true)
    {
        if(abs(startx-endx)==2)
        {
            int checkx=0,checky=0;
            checkx = startx+(endx-startx)/2;
            checky = starty+(endy-starty)/2;
            if(Pieces[checky][checkx].getColor()!="null"&&(Pieces[starty][startx].getColor()!=Pieces[checky][checkx].getColor()))
            {
                qDebug()<<" 12 IF";
                Pieces[checky][checkx].setColor("null");
                return(true);
            }
        }
        qDebug()<<"13 IF";
        return(false);
    }
    if(abs(starty-endy)!=1&&Pieces[starty][startx].getIsKing()!=true)
    {
        qDebug()<<" 11 IF";
        if(abs(starty-endy)==2)
        {
            int checkx=0,checky=0;
            checkx = startx+(endx-startx)/2;
            checky = starty+(endy-starty)/2;
            if(Pieces[checky][checkx].getColor()!="null"&&(Pieces[starty][startx].getColor()!=Pieces[checky][checkx].getColor()))
            {
                qDebug()<<" 12 IF";
                Pieces[checky][checkx].setColor("null");
                return(true);

            }

        }
        qDebug()<<" 14 IF";
        return(false);
        if(abs(starty-endy)!=1&&Pieces[starty][startx].getIsKing()==true)
        {
            int checkx=0,checky=0;
            checkx = startx+(endx-startx)/2;
            checky = starty+(endy-starty)/2;
            if(Pieces[checky][checkx].getColor()!="null"&&(Pieces[starty][startx].getColor()!=Pieces[checky][checkx].getColor()))
            {
                qDebug()<<" KING IF 1";
                Pieces[checky][checkx].setColor("null");
                return(true);

            }
            qDebug()<<"15 IF";
            return(false);
        }

    }
    if(abs(startx-endx)==2&&Pieces[startY][startX].getIsKing()==true)
    {
        qDebug()<<"KING IF 2";
        int checkx=0,checky=0;
        checkx = startx+(endx-startx)/2;
        checky = starty+(endy-starty)/2;
        if(Pieces[checky][checkx].getColor()!="null")
        {
            if((Pieces[starty][startx].getColor()!=Pieces[checky][checkx].getColor()))
            {
            qDebug()<<" KING IF 3";
            Pieces[checky][checkx].setColor("null");
            return(true);
            }
            else
            {
                return(false);
            }

        }
        return(false);
    }
    if(abs(startx-endx)!=1&&abs(startx-endx)!=2)
    {
        qDebug()<<"16 IF";
        return(false);
    }
    if(abs(starty-endy)!=1&&abs(starty-endy)!=2)
    {
        qDebug()<<"17 IF";
        return(false);
    }
    return(true);
}
bool Piece::getIsKing()
{
    return isKing;
}
std::string Piece::getColor()
{
    return color;
}
void Piece::setColor(std::string c)
{
    color = c;
}
void Piece::setX(int xx)
{
    x = xx;
}
void Piece::setY(int yy)
{
    y=yy;
}
int Piece::getX()
{
    return x;
}
int Piece::getY()
{
    return y;
}
void Piece::setIsKing(bool king)
{
    isKing = king;
}
bool randomAI()
{
    qDebug()<<BLACKMOVES<<" count ";
    BLACKMOVES++;
    srand(time(NULL));
    qDebug()<<rand()%8;
    startY=rand()%8;
    qDebug()<<rand()%8;
    startX=rand()%8;
    qDebug()<<rand()%8;
    endY=rand()%8;
    qDebug()<<rand()%8;
    endX=rand()%8;
    if(startX==endX||startY==endY)
    {
        randomAI();
    }
    if(Pieces[startY][startX].getColor()=="black")
    {
        if(canMove(startX,startY,endX,endY)==true)
        {
            qDebug()<<Pieces[startY][startX].getIsKing();
            colorChange=Pieces[startY][startX].getColor();
            Pieces[endY][endX].setColor(colorChange);
            Pieces[endY][endX].setIsKing(Pieces[startY][startX].getIsKing());
            Pieces[startY][startX].setColor("null");
            if(endY==0)
            {
                Pieces[endY][endX].setIsKing(true);
            }
            qDebug()<<Pieces[endY][endX].getIsKing();
            blackHasMoved=true;
        }
    }
    return(blackHasMoved);
}
void SetArray()
{
    int i,j;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(i==0&&(j==0||j==2||j==4||j==6||j==8))
            {
                Pieces[i][j].setColor("black");
                Pieces[i][j].setX(j);
                Pieces[i][j].setY(i);
            }
            if(i==1&&(j==1||j==3||j==5||j==7))
            {
                Pieces[i][j].setColor("black");
                Pieces[i][j].setX(j);
                Pieces[i][j].setY(i);
            }
            if(i==2&&(j==0||j==2||j==4||j==6||j==8))
            {
                Pieces[i][j].setColor("black");
                Pieces[i][j].setX(j);
                Pieces[i][j].setY(i);
            }
            if(i==3&&(j==1||j==3||j==5||j==7))
            {
                Pieces[i][j].setColor("null");
                Pieces[i][j].setX(j);
                Pieces[i][j].setY(i);
            }
            if(i==4&&(j==0||j==2||j==4||j==6||j==8))
            {
                Pieces[i][j].setColor("null");
                Pieces[i][j].setX(j);
                Pieces[i][j].setY(i);
            }
            if(i==5&&(j==1||j==3||j==5||j==7))
            {
                Pieces[i][j].setColor("red");
                Pieces[i][j].setX(j);
                Pieces[i][j].setY(i);
            }
            if(i==6&&(j==0||j==2||j==4||j==6||j==8))
            {
                Pieces[i][j].setColor("red");
                Pieces[i][j].setX(j);
                Pieces[i][j].setY(i);
            }
            if(i==7&&(j==1||j==3||j==5||j==7))
            {
                Pieces[i][j].setColor("red");
                Pieces[i][j].setX(j);
                Pieces[i][j].setY(i);
            }
        }
    }
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(Pieces[i][j].getColor()!="null"&&Pieces[i][j].getColor()!="red"&&Pieces[i][j].getColor()!="black")
            {
                Pieces[i][j].setColor("empty");
            }
        }
    }

}
void Piece::draw(QPainter* paint, int x, int y)
{
    qDebug() <<"Piece PaintEvent";
    int i,j;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {

            if(Pieces[i][j].getColor()=="red")
            {
                paint->setBrush(Qt::red);
                paint->drawEllipse(QPoint(Pieces[i][j].getX()*80+80/2,Pieces[i][j].getY()*80+80/2),80/2-4,80/2-4);
            }
            if(Pieces[i][j].getColor()=="black")
            {
                paint->setBrush(Qt::black);
                paint->drawEllipse(QPoint(Pieces[i][j].getX()*80+80/2,Pieces[i][j].getY()*80+80/2),80/2-4,80/2-4);
            }
        }
    }

}

Checkers::Checkers(QWidget *parent)
    : QMainWindow(parent)
{
    qDebug() << "Constructor";
    resize(80*8,80*8);

}

void Checkers::paintEvent(QPaintEvent* e)
{
    int x,y;
    qDebug() << "PaintEvent";
    QPainter p(this);
    for(y=0;y<8;y++)
    {
        for(x=0;x<8;x++)
        {
            if(y==0&&(x==0||x==2||x==4||x==6||x==8))
            {
                p.fillRect(QRect(80*x,80*y,80,80),Qt::gray);
            }
            if(y==1&&(x==1||x==3||x==5||x==7))
            {
                p.fillRect(QRect(80*x,80*y,80,80),Qt::gray);
            }
            if(y==2&&(x==0||x==2||x==4||x==6||x==8))
            {
                p.fillRect(QRect(80*x,80*y,80,80),Qt::gray);
            }
            if(y==3&&(x==1||x==3||x==5||x==7))
            {
                p.fillRect(QRect(80*x,80*y,80,80),Qt::gray);
            }
            if(y==4&&(x==0||x==2||x==4||x==6||x==8))
            {
                p.fillRect(QRect(80*x,80*y,80,80),Qt::gray);
            }
            if(y==5&&(x==1||x==3||x==5||x==7))
            {
                p.fillRect(QRect(80*x,80*y,80,80),Qt::gray);
            }
            if(y==6&&(x==0||x==2||x==4||x==6||x==8))
            {
                p.fillRect(QRect(80*x,80*y,80,80),Qt::gray);
            }
            if(y==7&&(x==1||x==3||x==5||x==7))
            {
                p.fillRect(QRect(80*x,80*y,80,80),Qt::gray);
            }
            if(y==8&&(x==0||x==2||x==4||x==6||x==8))
            {
                p.fillRect(QRect(80*x,80*y,80,80),Qt::gray);
            }
        }
    }
    if(!arraySetUp)
    {
        SetArray();
        arraySetUp=true;
    }
    int i,j;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {

            if(Pieces[i][j].getColor()=="red")
            {
                p.setBrush(Qt::red);
                p.drawEllipse(QPoint(Pieces[i][j].getX()*80+80/2,Pieces[i][j].getY()*80+80/2),80/2-4,80/2-4);
            }
            if(Pieces[i][j].getColor()=="black")
            {
                p.setBrush(Qt::black);
                p.drawEllipse(QPoint(Pieces[i][j].getX()*80+80/2,Pieces[i][j].getY()*80+80/2),80/2-4,80/2-4);
            }
        }
    }
}
void Checkers::mousePressEvent(QMouseEvent* e)
{
    qDebug()<<e->x()/80;
    qDebug()<<e->y()/80;
    startX=e->x()/80;
    startY=e->y()/80;
}
void Checkers::mouseReleaseEvent(QMouseEvent* e)
{
    qDebug()<<e->x()/80;
    qDebug()<<e->y()/80;
    endX=e->x()/80;
    endY=e->y()/80;
    if(turn==true&&Pieces[startY][startX].getColor()=="red")
    {
        if(canMove(startX,startY,endX,endY))
        {
            qDebug()<<Pieces[startY][startX].getIsKing();
            colorChange=Pieces[startY][startX].getColor();
            Pieces[endY][endX].setColor(colorChange);
            Pieces[endY][endX].setIsKing(Pieces[startY][startX].getIsKing());
            Pieces[startY][startX].setColor("null");
            if(endY==0)
            {
                Pieces[endY][endX].setIsKing(true);
            }
            qDebug()<<Pieces[endY][endX].getIsKing();
            repaint();
            /*while(blackHasMoved==false)
            {
            randomAI();
            }
            blackHasMoved=false;
            repaint();*/
            turn=!turn;
        }
        else
        {
            qDebug()<<"Not a move";
        }

    }
    if(turn==false&&Pieces[startY][startX].getColor()=="black")
    {
        if(canMove(startX,startY,endX,endY)==true)
        {
            colorChange=Pieces[startY][startX].getColor();
            Pieces[endY][endX].setColor(colorChange);
            Pieces[endY][endX].setIsKing(Pieces[startY][startX].getIsKing());
            Pieces[startY][startX].setColor("null");
            if(endY==7)
            {
                Pieces[endY][endX].setIsKing(true);
            }
            repaint();
            turn = !turn;
        }
        else
        {
            qDebug()<<"Not a move";
        }
    }
    setWindowTitle("Red's Turn");
}

Checkers::~Checkers()
{

}
Piece::~Piece()
{

}
