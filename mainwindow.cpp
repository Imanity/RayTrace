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

    camera_type = PERSPECTIVE_CAMERA;
    camera_pos = Vec3(20, 0, 5);
    camera_forward = Vec3(-1, 0, 0);
    camera_up = Vec3(0, 0, 1);

    speed = 0.5;
    angle = 4;

    initializeScene();
    refresh();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e) {
    Q_UNUSED(e);

    camera_type = 1 - camera_type;
    refresh();
    update();
}

void MainWindow::keyReleaseEvent(QKeyEvent *e) {
    switch (e->key()) {
    case Qt::Key_W:
        goAhead();
        break;
    case Qt::Key_A:
        turnLeft();
        break;
    case Qt::Key_S:
        goBack();
        break;
    case Qt::Key_D:
        turnRight();
        break;
    default:
        break;
    }
    refresh();
    update();
}

void MainWindow::goAhead() {
    camera_pos = camera_pos.add(camera_forward.multiply(speed));
}

void MainWindow::goBack() {
    camera_pos = camera_pos.add(camera_forward.multiply(speed).negate());
}

void MainWindow::turnLeft() {
    double x = camera_forward.x;
    double y = camera_forward.y;
    double theta = angle * 3.1416 / 180;
    double x_ = x * cos(theta) - y * sin(theta);
    double y_ = x * sin(theta) + y * cos(theta);
    camera_forward.x = x_;
    camera_forward.y = y_;
}

void MainWindow::turnRight() {
    double x = camera_forward.x;
    double y = camera_forward.y;
    double theta = -angle * 3.1416 / 180;
    double x_ = x * cos(theta) - y * sin(theta);
    double y_ = x * sin(theta) + y * cos(theta);
    camera_forward.x = x_;
    camera_forward.y = y_;
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
    p_camera = PerspectiveCamera(camera_pos, camera_forward, camera_up, 45);
    o_camera = OrthogonalCamera(camera_pos, camera_forward, camera_up, 16, 16);
    for (int i = 0; i < WIDTH; ++i) {
        for (int j = 0; j < HEIGHT; ++j) {
            Ray ray;
            if (camera_type == PERSPECTIVE_CAMERA) {
                ray = p_camera.generateRay((double)i / (double)WIDTH, (double)j / (double)HEIGHT);
            } else {
                ray = o_camera.generateRay((double)i / (double)WIDTH, (double)j / (double)HEIGHT);
            }
            img[j][i] = rt.rayTrace(scene, ray, 0);
        }
    }
}

void MainWindow::initializeScene() {
    // Add Planes
    Plane planes[6];
    // Floor
    planes[0] = Plane(Vec3(0, 0, 1), 0);
    planes[0].setColor(100, 100, 100);
    // Ceil
    planes[1] = Plane(Vec3(0, 0, -1), 15);
    planes[1].setColor(230, 230, 250);
    // Left
    planes[2] = Plane(Vec3(0, 1, 0), 10);
    planes[2].setColor(255, 180, 190);
    // Right
    planes[3] = Plane(Vec3(0, -1, 0), 10);
    planes[3].setColor(100, 90, 200);
    // Back
    planes[4] = Plane(Vec3(1, 0, 0), 10);
    planes[4].setColor(200, 200, 200);
    // Front
    planes[5] = Plane(Vec3(-1, 0, 0), 10);
    planes[5].setColor(200, 200, 200);
    // Plane: kd = 1, ks = 0
    for (int i = 0; i < 6; ++i) {
        planes[i].n = 16;
        planes[i].kd = 1;
        planes[i].ks = 0;
        scene.addPlane(planes[i]);
    }

    // Add Spheres
    Sphere spheres[2];
    // Left ball
    spheres[0] = Sphere(Vec3(3, -3, 3), 3);
    spheres[0].setColor(0, 200, 0);
    // Right ball with texture
    spheres[1] = Sphere(Vec3(-3, 5, 3), 3);
    spheres[1].setColor(200, 0, 0);
    spheres[1].usingTexture = true;
    spheres[1].texture = ChessTexture(6);
    // Ball: kd = 0.7, ks = 0.5
    for (int i = 0; i < 2; ++i) {
        spheres[i].n = 10;
        spheres[i].kd = 0.7;
        spheres[i].ks = 0.5;
        scene.addSphere(spheres[i]);
    }

    // Add Point Light
    scene.light = PointLight(QColor(255, 255, 255), Vec3(3, 0, 10));
}
