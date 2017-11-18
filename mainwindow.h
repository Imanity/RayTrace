#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QPainter>

#include "raytracer.h"
#include "perspectivecamera.h"

#define WIDTH 600
#define HEIGHT 600

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    QColor **img;
    RayTracer rt;
    Scene scene;
    PerspectiveCamera camera;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setPoint(int x, int y, QColor c);
    void refresh();
    void initializeScene();

protected:
    void paintEvent(QPaintEvent *e);

private:
    Ui::MainWindow *ui;

    double a;
    void mouseReleaseEvent(QMouseEvent *e);
};

#endif // MAINWINDOW_H
