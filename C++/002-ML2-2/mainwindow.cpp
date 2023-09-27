#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "point.h"
#include <QPainter>
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    i = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    QPen pen(Qt::black);
    pen.setWidth(1);
    painter.setPen(pen);
    for(Point *p : points)
        if(p)
        {
            int k = p->getW(),
                j = p->getI();
            if(j%2 == 1)
            {
                painter.drawLine(p->getX()-(k-1), p->getY()-(k-1), p->getX()+k, p->getY()+k);
                painter.drawLine(p->getX()+k, p->getY()-(k-1), p->getX()-(k-1), p->getY()+k);
            }
            else
            {
                painter.drawLine(p->getX()-k, p->getY()-k, p->getX()+k, p->getY()+k);
                painter.drawLine(p->getX()+k, p->getY()-k, p->getX()-k, p->getY()+k);
            }
        }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(i<10)
    {
        points[i] = new Point(event->x(), event->y(), i);
        if(i%2 == 1) points[i]->setW(1 + (i+1)/2);
        else points[i]->setW(1 + i/2);
        i++;
        repaint();
    }
}
