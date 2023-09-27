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
            painter.drawLine(p->getX()-1, p->getY()-1, p->getX()+1, p->getY()+1);
            painter.drawLine(p->getX()+1, p->getY()-1, p->getX()-1, p->getY()+1);
        }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(i<10)
    {
        points[i] = new Point(event->x(), event->y());
        i++;
        repaint();
    }
}
