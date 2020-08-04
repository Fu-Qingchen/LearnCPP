#include<QPoint>
#include<QPainter>
#include<vector>
#include<initializer_list>

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
    void drawPoints(const int);
    void setProbability(std::initializer_list<int>);
private:
    int W;  // Windows Width
    int H;  // Windows Height
    int n;  // N-Line Polygon
    int *probability;    // The probability of each points
    int sum;
    QPoint initPoint = QPoint(1, 1);
    QPointF *refPoint;
    QPainter *painter;
    void getRefPoint();
    void getNextPoint();
    int getRandom();
};

#endif // IFSPOLYGON_H
