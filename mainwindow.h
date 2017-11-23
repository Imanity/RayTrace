#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QPainter>
#include <QTimer>
#include <QDebug>

#include "raytracer.h"
#include "perspectivecamera.h"
#include "orthogonalcamera.h"
#include "pointlight.h"

#define WIDTH 600
#define HEIGHT 600

#define PERSPECTIVE_CAMERA 0
#define ORTHOGONAL_CAMERA 1

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    QColor **img;
    RayTracer rt;
    Scene scene;
    PerspectiveCamera p_camera;
    OrthogonalCamera o_camera;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setPoint(int x, int y, QColor c);
    void refresh();
    void initializeScene();

protected:
    void paintEvent(QPaintEvent *e);
    void keyReleaseEvent(QKeyEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

private:
    void goAhead();
    void goBack();
    void turnLeft();
    void turnRight();

private:
    Ui::MainWindow *ui;

    int camera_type;
    Vec3 camera_pos, camera_forward, camera_up;
    double speed;
    double angle;
};

#endif // MAINWINDOW_H
