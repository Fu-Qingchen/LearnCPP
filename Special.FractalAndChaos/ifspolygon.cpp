#include"IfsPolygon.h"
#include<QtMath>
#include<cstdlib>
#include<iostream>
#include<numeric>


void IfsPolygon::getRefPoint(){
    double R = W > H ? H*1.0/2 : W*1.0/2;
    for(int i = 0; i < n; i++){
        refPoint.push_back(QPointF(
                    W*1.0/2 + R*qCos(i*2*M_PI/n - M_PI/2),
                    H*1.0/2 + R*qSin(i*2*M_PI/n - M_PI/2)));
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

void IfsPolygon::drawInit() const{
    for(auto point:refPoint){
        painter->drawPoint(point);
    }
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

void IfsPolygon::setProbability(const std::initializer_list<int> &il){
    auto iter = il.begin();
    for(int i = 0; i < n; i++){
        if(iter != il.end()){
            probability[i] = *iter++;
        }else{
            probability[i] = 1;
        }
    }
}

int IfsPolygon::getRandom() const{
    int number = 0;
    for(int i = 0; i < n; i++){
        number += probability[i];
    }
    int temp = rand() % number, i = 0;
    for(;temp >= 0; ++i){
        temp -= probability[i];
    }
    std::cout << i - 1 << std::endl;
    return i - 1;
}
