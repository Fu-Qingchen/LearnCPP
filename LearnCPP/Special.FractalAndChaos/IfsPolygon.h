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
    IfsPolygon(const int &iW, const int &iH, const int &in, QPainter *ipainter)
        :W(iW), H(iH), n(in), painter(ipainter) {
        for(int i = n; i--;) probability.push_back(i + 1);
        getRefPoint();
    }
    void drawInit() const;
    void drawNext();
    void drawPoints(const int);
    void setProbability(const std::initializer_list<int> &);
private:
    int W;  // Windows Width
    int H;  // Windows Height
    int n;  // N-Line Polygon
    std::vector<int> probability;    // The probability of each points
    double step = 0.5;
    QPoint initPoint = QPoint(1, 1);
    std::vector<QPointF> refPoint;
    QPainter *painter;

    void getRefPoint();
    void getNextPoint();
    int getRandom() const;
};

#endif // IFSPOLYGON_H
