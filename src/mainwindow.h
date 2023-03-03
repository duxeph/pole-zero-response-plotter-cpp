#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QtMath>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // declaration(s) of main process's variable(s)
    QVector<QVector<double>> poles = {}, zeros = {};
    double GHCU = 0.25; // global hold control unit

    // declaration(s) of control variable(s)
    char* lastType;
    char type = 'm', currentPlane = 's';

    double sens = 0.05; // period of the points in the origin (result plot becomes MORE SENSITIVE as sensitivity INCREASES)
    int pR = 5; // plot widget range (where user is able to click)
    int rR = 10; // result widget range (where user observe the result)

private slots:
    void draw();
    QVector<QVector<double>> get_coordinates(QMouseEvent *e);

    void on_clearButton_clicked();
    void on_planeButton_clicked();

    void mousePlotPressEvent(QMouseEvent *e);
    void mousePlotMoveEvent(QMouseEvent *e);
    void mousePlotReleaseEvent(QMouseEvent *e);

    void on_sliderScale_valueChanged(int value);
    void on_sliderSensitivity_valueChanged(int value);

    void on_typeButton_clicked();
    void resizeEvent(QResizeEvent* event);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
