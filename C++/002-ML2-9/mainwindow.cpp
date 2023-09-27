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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    int x=-1, y=-1;
    for(int i=0; i < points.size(); ++i)
    {
        if(x>0)
        {
            QPen pen(Qt::gray);
            pen.setWidth(1);
            painter.setPen(pen);
            painter.drawLine(x, y, points[i]->getX(), points[i]->getY());
        }
        x = points[i]->getX();
        y = points[i]->getY();
        points[i]->draw(&painter);
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    Point *p = new Point(event->x(), event->y());
    if(points.size())
    {
        bool flag = true;
        for(int i=0; i < points.size(); ++i)
            if (points[i]->distance2(*p) <= 5)
            {
                delete points[i];
                points.remove(i);
                flag = false;
            }
        if(flag) points.append(p);
    }
    else points.append(p);
    repaint();
}
