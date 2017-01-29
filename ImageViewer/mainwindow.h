#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "image.h"
#include "imagescene.h"

#include <QMainWindow>
#include <QtGui>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    void display(QString str);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent* event);
    void keyPressEvent(QKeyEvent* event);

private slots:

    void on_angleHSlider_valueChanged(int value);

    void on_angleSpinBox_valueChanged(int value);

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionZoomIn_triggered();

    void on_actionZoomOut_triggered();

    void on_actionCrop_triggered(bool checked);

    void on_actionReset_triggered();

    void on_actionHandTool_triggered(bool checked);

    void on_actionZoomInArea_triggered(bool checked);

    void on_toolBar_actionTriggered(QAction*);

    void on_actionRotate_triggered(bool);

    void on_scene_modeChanged(int);

    void on_actionZoomFactor_triggered(bool checked);

    void on_factorSpinBox_valueChanged(double arg1);

    void on_zoomSlider_valueChanged(int value);

    void zoomWithFactor(double factor);

private:
    Ui::MainWindow* ui = 0;
    ImageScene* scene = 0;
    QGraphicsView* gv = 0;
    int gv_lazy_rotation = 0;
    double zoomFactor = 1;

    Image* image = 0;
    void save_changes();
    void lazy_rotate(int value);
    void propagate_lazy_rotate();
    void reset();
};

#endif // MAINWINDOW_H
