#include<QPoint>
#include<QPainter>
#ifndef IFSPOLYGON_H
#define IFSPOLYGON_H

namespace Ui {
class IfsPolygon;
}

class IfsPolygon{
public:
    IfsPolygon(int n, int W, int H, QPainter *);
    ~IfsPolygon();
    void drawInit();
    void drawNext();
    void drawPoints(int);
private:
    int W;  // Windows Width
    int H;  // Windows Height
    int n;  // N-Line Polygon
    int sum;
    QPoint initPoint = QPoint(W/2, H/2);
    QPointF *refPoint;
    QPainter *painter;
    void getRefPoint();
    void getNextPoint();
};

#endif // IFSPOLYGON_H
