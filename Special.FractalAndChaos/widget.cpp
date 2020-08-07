#include "widget.h"
#include "ui_widget.h"
#include <QEvent>
#include "IfsPolygon.h"
#include "ifsleaf.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setPalette(QPalette(Qt::black));
    setAutoFillBackground(true);
}

Widget::~Widget()
{
    delete ui;
}

class Triangle{
public:
    Triangle(QPoint last);
    void drawNext(QPainter *, QPoint *);
private:
    QPoint thisPoint;
    QPoint lastPoint;
};

Triangle::Triangle(QPoint last){
    lastPoint = last;
}

void Triangle::drawNext(QPainter *qp, QPoint *points){
    int temp = rand() % 5;
    double x = (lastPoint.x() + points[temp].x())/2;
    double y = (lastPoint.y() + points[temp].y())/2;
    thisPoint = QPoint(x, y);
    qp->drawPoint(thisPoint);
    lastPoint = thisPoint;
}

void Widget::paintEvent(QPaintEvent *event){
    QPainter *painter = new QPainter(this);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setRenderHint(QPainter::TextAntialiasing);
    int W = this->width();
    int H = this->height();
    QPen pen;
    pen.setWidth(1);
    pen.setColor(QColor(105,156,82));
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::FlatCap);
    pen.setJoinStyle(Qt::BevelJoin);
    painter->setPen(pen);

    // Test IfsPolygon
    IfsPolygon *polygon = new IfsPolygon(W, H, 6, painter);
    polygon->setProbability({1, 2, 3, 4, 5, 6});
    polygon->drawInit();
    polygon->drawPoints(100000);
    delete polygon;

    // Test IfsLeaf
//    IfsLeaf *leaf = new IfsLeaf(W, H, 100000, painter);
//    leaf->draw();
//    delete leaf;
}
