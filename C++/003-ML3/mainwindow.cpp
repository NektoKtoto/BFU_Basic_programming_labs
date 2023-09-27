#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "point.h"
#include "rect.h"
#include <QPainter>
#include <QMouseEvent>
#include <QMessageBox>

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
    if(rect) rect->draw(&painter);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(rect)
    {
        point = new Point(event->x(), event->y());
        QMessageBox message;
        message.setStandardButtons(QMessageBox::Ok);
        if(rect->belong(point)) message.setText("Попадание");
        else message.setText("Промах");
        message.exec();
    }
    else
    {
        Point *npoint = new Point(event->x(), event->y());
        if(point)
        {
            rect = new Rect(point, npoint);
            repaint();
        }
        else point = npoint;
    }
}
