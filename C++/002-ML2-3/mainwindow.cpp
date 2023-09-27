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
    for(Point *p : points) if(p) p->draw(&painter);
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
