#include"IfsPolygon.h"
#include<QtMath>
#include<cstdlib>
#include<iostream>

IfsPolygon::IfsPolygon(int n, int W, int H, QPainter *painter){
    this->n = n;
    this->W = W;
    this->H = H;
    this->painter = painter;
    getRefPoint();
    drawInit();
}

IfsPolygon::~IfsPolygon(){
    delete refPoint;
}

void IfsPolygon::getRefPoint(){
    refPoint = new QPointF[n];
    double R = W > H ? H*1.0/2 : W*1.0/2;
    for(int i = 0; i < n; i++){
        *(refPoint + i) = QPointF(
                    W*1.0/2 + R*qCos(i*2*M_PI/n - M_PI/2),
                    H*1.0/2 + R*qSin(i*2*M_PI/n - M_PI/2));
        std::cout << refPoint[i].x() << ", " << refPoint[i].y() << std::endl;
    }
}

void IfsPolygon::getNextPoint(){
    int temp = rand() % n;
    double x = (initPoint.x() + refPoint[temp].x())/2;
    double y = (initPoint.y() + refPoint[temp].y())/2;
    QPoint thisPoint(x, y);
    painter->drawPoint(thisPoint);
    initPoint = thisPoint;
}

void IfsPolygon::drawInit(){
    painter->drawPoints(refPoint, n);
    painter->drawPoint(initPoint);
}

void IfsPolygon::drawNext(){
    getNextPoint();
    painter->drawPoint(initPoint);
}

void IfsPolygon::drawPoints(int pointNumber){
    for(int i = 0; i < pointNumber; i++){
        drawNext();
    }
}
