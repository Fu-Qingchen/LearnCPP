#include<QPoint>
#include<QPainter>

#ifndef IFSLEAF_H
#define IFSLEAF_H

namespace Ui {
class IfsLeaf;
}

class IfsLeaf{
public:
    IfsLeaf(const int &iW, const int &iH, const int &in,QPainter *ipainter)
        :W(iW), H(iH), n(in), painter(ipainter), initPoint(iW/2, iH/2){}
    void draw();

private:
    int n;  // number of points
    int W;  // windows width
    int H;  //windows height
    double parameter[4][6]= {
        {0.85, 0.04, -0.04, 0.85, 0.08, 0.18},
        {0, 0, 0, 0.16, 0.5, 0},
        {0.2, -0.26, 0.23, 0.22, 0.4, 0.05},
        {-0.15, 0.28, 0.26, 0.24, 0.58, -0.09}
    };
    int probability[4] = {85, 1, 7, 7};
    QPointF initPoint;
    QPainter *painter;

    void getNextPoint();
    int getRandom() const;
};

#endif // IFSLEAF_H
