#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    img = new QColor *[HEIGHT];
    for (int i = 0; i < HEIGHT; ++i) {
        img[i] = new QColor[WIDTH];
    }
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            img[i][j] = QColor(255, 255, 255);
        }
    }

    initializeScene();
    refresh();
    a = 3.141593;
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e) {
    Q_UNUSED(e);
    a += 0.08;
    camera = PerspectiveCamera(Vec3(-5, 0, 5), Vec3(cos(a), sin(a), 0), Vec3(0, 0, 1), 90);
    refresh();
    update();
}

MainWindow::~MainWindow() {
    for (int i = 0; i < HEIGHT; ++i) {
        delete img[i];
        img[i] = NULL;
    }
    delete img;
    img = NULL;
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *e) {
    Q_UNUSED(e);

    QPainter painter(this);
    for (int i = 0; i < WIDTH; ++i) {
        for (int j = 0; j < HEIGHT; ++j) {
            painter.setPen(img[j][i]);
            painter.drawPoint(i, j);
        }
    }
}

void MainWindow::setPoint(int x, int y, QColor c) {
    img[y][x] = c;
}

void MainWindow::refresh() {
    for (int i = 0; i < WIDTH; ++i) {
        for (int j = 0; j < HEIGHT; ++j) {
            Ray ray = camera.generateRay((double)i / (double)WIDTH, (double)j / (double)HEIGHT);
            img[j][i] = rt.rayTrace(scene, ray);
        }
    }
}

void MainWindow::initializeScene() {
    Plane planes[5];
    planes[0] = Plane(Vec3(0, 0, 1), 0);
    planes[1] = Plane(Vec3(0, 0, -1), 20);
    planes[2] = Plane(Vec3(0, 1, 0), 10);
    planes[3] = Plane(Vec3(0, -1, 0), 10);
    planes[4] = Plane(Vec3(1, 0, 0), 10);
    planes[0].setColor(100, 100, 100);
    planes[1].setColor(230, 230, 250);
    planes[2].setColor(255, 180, 190);
    planes[3].setColor(100, 90, 200);
    planes[4].setColor(230, 230, 250);
    for (int i = 0; i < 5; ++i) {
        scene.addPlane(planes[i]);
    }
    camera = PerspectiveCamera(Vec3(-5, 0, 5), Vec3(-1, 0, 0), Vec3(0, 0, 1), 90);
}
