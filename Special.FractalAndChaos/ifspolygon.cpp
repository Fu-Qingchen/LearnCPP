#include"IfsPolygon.h"
#include<QtMath>
#include<cstdlib>
#include<iostream>
#include<numeric>

IfsPolygon::IfsPolygon(int n, int W, int H, QPainter *painter){
    this->n = n;
    this->W = W;
    this->H = H;
    this->painter = painter;
    probability = new int[n]{0};
    for(int i = 0; i < n; i++){
        probability[i] = i + 1;
    }
    getRefPoint();
    drawInit();
}

IfsPolygon::~IfsPolygon(){
    delete refPoint;
    delete probability;
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
    int temp = getRandom();
    std::cout << temp << " ";
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

void IfsPolygon::drawPoints(const int pointNumber){
    for(int i = 0; i < pointNumber; i++){
        drawNext();
    }
}

void IfsPolygon::setProbability(std::initializer_list<int> il){
    auto iter = il.begin();
    for(int i = 0; i < n; i++){
        if(iter != il.end()){
            probability[i] = *iter++;
        }else{
            probability[i] = 1;
        }
    }
}

int IfsPolygon::getRandom(){
    int number = 0;
    for(int i = 0; i < n; i++){
        number += probability[i];
    }
    int temp = rand() % number, i = 0;
    for(;temp >= 0; ++i){
        temp -= probability[i];
    }
    return i - 1;
}
