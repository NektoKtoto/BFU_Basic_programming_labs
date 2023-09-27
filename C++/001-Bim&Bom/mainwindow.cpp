#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "boll.h"
#include <QPainter>
#include <QMouseEvent>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer;
    timer = new QTimer;
    connect(timer,SIGNAL(timeout()), this, SLOT(update()));
    timer->start(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    //qDebug("paint");
    QPainter painter(this);
    /*
    painter.drawLine(x,y-5,x,y+5);
    painter.drawLine(x-5,y,x+5,y);

    painter.drawLine(0,0,100,100);
    painter.drawEllipse(100,100,20,20);
    */
    if(bing) painter.drawEllipse(bing->x - bing->r/2, bing->y - bing->r/2, bing->r, bing->r);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    event->x();
    //qDebug("x=%d y=%d",event->x(),event->y());
    bing = new Boll;
    bing->x = event->x();
    bing->y = event->y();
    bing->r = 21;
    bing->dx = -10;
    bing->dy = bing->dx;
    repaint();
}

void MainWindow::update()
{
    if(!bing) return;
    QRect rect = contentsRect();
    if(bing->x <= bing->r/2) bing->dx *= -1;
    if(bing->y <= bing->r/2) bing->dy *= -1;
    if(bing->x >= rect.width() - bing->r/2) bing->dx *= -1;
    if(bing->y >= rect.height() - bing->r/2) bing->dy *= -1;
    bing->x += bing->dx;
    bing->y += bing->dy;
    repaint();
}
