#include"ifsleaf.h"
#include<numeric>
#include<iostream>

IfsLeaf::IfsLeaf(const int &W, const int &H, const int &n,QPainter *painter){
    this->W = W;
    this->H = H;
    this->n = n;
    this->painter = painter;
    initPoint = QPoint(W/2, H/2);
}

void IfsLeaf::draw(){
    painter->drawPoint(initPoint);
    for(int i = 0; i < n; ++i){
        getNextPoint();
    }
}

int IfsLeaf::getRandom(){
    int number = 0;
    for(int i = 0; i < 4; i++){
        number += probability[i];
    }
    int temp = rand() % number, i = 0;
    for(;temp >= 0; ++i){
        temp -= probability[i];
    }
    std::cout << i - 1;
    return i - 1;
}

void IfsLeaf::getNextPoint(){
    int randNumber = getRandom();
    std::cout << randNumber <<std::endl;
    double x = parameter[randNumber][0]*initPoint.x()*1.0/W + parameter[randNumber][1]*(H - initPoint.y()*1.0)/H + parameter[randNumber][4];
    double y = parameter[randNumber][2]*initPoint.x()*1.0/W + parameter[randNumber][3]*(H - initPoint.y()*1.0)/H + parameter[randNumber][5];
    initPoint = QPointF(x*W, H - y*H);
    painter->drawPoint(initPoint);
}
