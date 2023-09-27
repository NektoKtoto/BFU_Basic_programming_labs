#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "point.h"
#include "rect.h"
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
    for(Rect *r : crects) r->draw(&painter);
    for(Rect *r : rects) r->draw(&painter);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    Point *npoint = new Point(event->x(), event->y());
    if(event->modifiers() & Qt::ControlModifier)
        if(point)
        {
            rects.append(new Rect(point, npoint));
            point = nullptr;
            repaint();
        }
        else point = npoint;
    else if(rects.size())
    {
        QVector<int>j;
        for(int i=0; i < rects.size(); ++i)
            if(rects[i]->belong(npoint)) j.append(i);
        if(j.size()-1)
        {
            Rect *r = new Rect(rects[j[0]], rects[j[1]], j.size());
            for(int i=2; i < j.size(); ++i)
                r = new Rect(rects[j[i]], r, j.size());
            crects.append(r);
            for(int i=0; i < crects.size()-1; ++i)
                for(int k = i+1 ; k < crects.size(); ++k)
                    if(crects[i]->getC() > crects[k]->getC())
                    {
                        r = crects[i];
                        crects[i] = crects[k];
                        crects[k] = r;
                    }
            repaint();
        }
    }
}
