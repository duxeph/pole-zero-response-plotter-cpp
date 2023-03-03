#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // main connections of events with functions
    connect(ui->plotWidget, SIGNAL(mousePress(QMouseEvent*)), SLOT(mousePlotPressEvent(QMouseEvent*)));
    connect(ui->plotWidget, SIGNAL(mouseMove(QMouseEvent*)), SLOT(mousePlotMoveEvent(QMouseEvent*)));
    connect(ui->plotWidget, SIGNAL(mouseRelease(QMouseEvent*)), SLOT(mousePlotReleaseEvent(QMouseEvent*)));

    ui->statusbar->showMessage("Successfully initialized. Welcome.");
    draw();
}
MainWindow::~MainWindow()
{
    delete ui;
}

double complex_distance(QVector<double> x, double y) {
    // double res = qPow(qPow(y-x[1], 2) + qPow(0-x[0], 2), 0.5);
    // return res; // simply calculates the distance
    return qPow(qPow(y-x[1], 2) + qPow(0-x[0], 2), 0.5);
}
double complex_distanceZ(QVector<double> x, QVector<double> y) {
    return qPow(qPow(y[1]-x[1], 2) + qPow(y[0]-x[0], 2), 0.5);
}
double complex_phase(QVector<double> x, double y) {
    double range_x = x[0], range_y = x[1] - y;
    return qAtan(range_y/range_x);
}
double complex_phaseZ(QVector<double> x, QVector<double> y) {
    double range_x = x[0] - y[0], range_y = x[1] - y[1];
    return qAtan(range_y/range_x);
}

QVector<QVector<double>> MainWindow::get_coordinates(QMouseEvent *e) {
    int x = e->pos().x(), y = e->pos().y();
    double xx = ui->plotWidget->xAxis->pixelToCoord(x), yy = ui->plotWidget->yAxis->pixelToCoord(y);
    if(yy<0) { yy=-yy; } // even if user has clicked to point below origin, we are going to add positive (its conjugate in this case) FIRSTLY.
    QVector<QVector<double>> points = {{xx, yy}, {xx, -yy}}; // pointup, pointdown

    // UPDATE STATUSBAR //
    const char* informative_addition = (poles.size()>zeros.size())?"ZERO (0).":(poles.size()==zeros.size())?"TO SOME CONSTANT.":"INFINITY.";
    ui->statusbar->showMessage("Pole count: "+QString::number(poles.size())+
                               ", Zero count: "+QString::number(zeros.size())+
                               ", Magnitude response is going to "+QString::fromStdString(informative_addition));
    ui->statusbar->showMessage(ui->statusbar->currentMessage()+" "+QString::number(xx)+" "+QString::number(yy)+".");
    return points;
}

void MainWindow::draw() {
    // INITIALIZE (CONTROL) VARIABLES //

    // DRAW POLES&ZEROS ADDED BY USER //
    QVector<double> crossxs = {}, crossys = {}, dotxs = {}, dotys = {};
    for(int i=0; i<poles.size(); i++) { crossxs.append(poles[i][0]); crossys.append(poles[i][1]); }
    for(int i=0; i<zeros.size(); i++) { dotxs.append(zeros[i][0]); dotys.append(zeros[i][1]); }

    ui->plotWidget->addGraph(); ui->plotWidget->graph(0)->setLineStyle(QCPGraph::lsNone); ui->plotWidget->graph(0)->setScatterStyle(QCPScatterStyle::ssCross);
    ui->plotWidget->graph(0)->setData(crossxs, crossys);

    ui->plotWidget->addGraph(); ui->plotWidget->graph(1)->setLineStyle(QCPGraph::lsNone); ui->plotWidget->graph(1)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->plotWidget->graph(1)->setData(dotxs, dotys);

    // CALCULATEALL As&DRAW A (for all points in the origin, from -rR to rR (rR stands for "result range"))
    double max = 0, a, temp;
    QVector<double> resultant = {}, range = {};
    if(currentPlane=='z') {
        if(type=='p') {
            double x, y;
            for(double i=0; i<=2*M_PI; i+=sens) {
                x = qCos(i); y = qSin(i);
                a = 0;
                for(int j=0; j<zeros.size(); j++) {
                    a += complex_phaseZ(zeros[j], {x, y});
                }
                for(int j=0; j<poles.size(); j++) {
                    a -= complex_phaseZ(poles[j], {x, y});
                }
                max = max<a?a:max;
                range.append(i);
                resultant.append(a);
            }
        } else {
            double x, y;
            for(double i=0; i<=2*M_PI; i+=sens) {
                x = qCos(i); y = qSin(i);
                a = 1;
                for(int j=0; j<zeros.size(); j++) {
                    a *= complex_distanceZ(zeros[j], {x, y});
                }
                for(int j=0; j<poles.size(); j++) {
                    temp = complex_distanceZ(poles[j], {x, y});
                    a /= temp!=0?temp:qPow(0.1, 400); // __DBL_MAX__
                }
                max = max<a?a:max;
                range.append(i);
                resultant.append(a);
            }
        }
        ui->plotWidget->addGraph(); ui->plotWidget->graph(2)->setLineStyle(QCPGraph::lsNone);
        // qcpscatterstyle -> circlic, and its diameter is equal to the difference of x axis's points; "2" and "0" (in coordinates) (radius is equal to 1 in coordinates).
        QCPScatterStyle style; style.setShape(QCPScatterStyle::ssCircle); style.setSize(ui->plotWidget->xAxis->coordToPixel(2)-ui->plotWidget->xAxis->coordToPixel(0));
        ui->plotWidget->graph(2)->setScatterStyle(style);
        ui->plotWidget->graph(2)->setData({0}, {0});

        ui->resWidget->xAxis->setRange(0, 2*M_PI);
    } else { // else if(currentPlane=='z')
        if(type=='p') {
            for(double i=-rR; i<=rR; i+=sens) {
                a = 0;
                for(int j=0; j<zeros.size(); j++) {
                    a += complex_phase(zeros[j], i);
                }
                for(int j=0; j<poles.size(); j++) {
                    a -= complex_phase(poles[j], i);
                }
                max = max<a?a:max;
                range.append(i);
                resultant.append(a);
            }
        } else {
            for(double i=-rR; i<=rR; i+=sens) {
                a = 1;
                for(int j=0; j<zeros.size(); j++) {
                    a *= complex_distance(zeros[j], i);
                }
                for(int j=0; j<poles.size(); j++) {
                    temp = complex_distance(poles[j], i);
                    a /= temp!=0?temp:qPow(0.1, 400); // __DBL_MAX__
                }
                max = max<a?a:max;
                range.append(i);
                resultant.append(a);
            }
        }
        ui->resWidget->xAxis->setRange(-rR, rR);
    }
    ui->plotWidget->xAxis->setRange(-pR, pR); ui->plotWidget->yAxis->setRange(-pR, pR);

    if(type=='p') { ui->resWidget->yAxis->setRange(-max*1.5, max*1.5); }
    else { ui->resWidget->yAxis->setRange(0, max*1.5); }
    ui->resWidget->addGraph();
    ui->resWidget->graph(0)->setData(range, resultant);

    ui->plotWidget->replot(); ui->resWidget->replot();
}

void MainWindow::mousePlotReleaseEvent(QMouseEvent* e) {
    QString text = ui->statusbar->currentMessage();
    QList list = text.split(u' ');
    list.removeLast(); list.removeLast();
    ui->statusbar->showMessage(list.join(' '));
}

void MainWindow::on_clearButton_clicked() {
    poles.clear(); zeros.clear(); // simplist operation, clears all and redraws
    ui->plotWidget->clearGraphs();
    ui->statusbar->showMessage("All cleared.");
    draw();
}

void MainWindow::mousePlotMoveEvent(QMouseEvent *e) {
    // if deletion box is checked, no hold&move simply wont work (because user is deleted the point by clicking it! (click -?> hold -> move))
    if((e->buttons() & Qt::LeftButton || e->buttons() & Qt::RightButton) && !ui->deletionBox->isChecked()) {
        QVector<QVector<double>> points = get_coordinates(e);
        QVector<double> pointup = points[0], pointdown = points[1];

        /* operation:
         * if last clicked point is a pole (checked with lastType), check its y component.
         *  if it's equal to zero, then remove it.
         *  else, remove it and its conjugate.
         */
        if(strcmp(lastType, "pole")==0) { // pole - left
            if(poles[poles.size()-1][1]==0) { poles.remove(poles.size()-1); }
            else if(poles[poles.size()-1][1]==-poles[poles.size()-2][1]) { poles.remove(poles.size()-2); poles.remove(poles.size()-1); }
            else { qDebug()<<"[CODE:100] Exceptional case. Check plase."; }

            if(pointup[1]<GHCU) {
                pointup[1] = 0;
                poles.append(pointup);
            } else {
                poles.append(pointup);
                poles.append(pointdown);
            }
        } else { // zero - right
            if(zeros[zeros.size()-1][1]==0) { zeros.remove(zeros.size()-1); }
            else if(zeros[zeros.size()-1][1]==-zeros[zeros.size()-2][1]) { zeros.remove(zeros.size()-2); zeros.remove(zeros.size()-1); }
            else { qDebug()<<"[CODE:101] Exceptional case. Check plase."; }

            if(pointup[1]<GHCU) {
                pointup[1] = 0;
                zeros.append(pointup);
            } else {
                zeros.append(pointup);
                zeros.append(pointdown);
            }
        }
        draw();
    }
}

void MainWindow::mousePlotPressEvent(QMouseEvent *e) {
    if(e->button()==Qt::LeftButton | e->button()==Qt::RightButton) {
        bool deletion = ui->deletionBox->isChecked(); // checks whether deletion box is checked (click is deleting if so)
        QVector<QVector<double>> points = get_coordinates(e);
        QVector<double> pointup = points[0], pointdown = points[1]; // get coordinates (it and it's conjugate)

        /* first operation:
         * check clicked position whether there is also another point (in a circlic region with radius 0.25)
         * if so, remove it by checking (another if) whether its y component is equal to 0 (end).
         *   if so, delete only its itself.
         *   else, delete it and its conjugate {ith index: (x, y), i+1th index (its conjugate): (x, -y)}.
         *  after deletion, if user wants to delete the point, end the process. otherwise, we need to redraw the point, so keep continuing to operation.
         *  *important note: we do that to take the point(s) to the end of the poles/zeros list(s). caution (!), this is a part of the algorithm...
         *  ... we use to apply hold&move (a point) operation.
         * else, keep going to the second operation
         */
        if(e->button()==Qt::LeftButton) {
            for(int i=0; i<poles.size(); i++) {
                if(qFabs(pointup[0]-poles[i][0])<GHCU & qFabs(pointup[1]-poles[i][1])<GHCU) {
                    if(poles[i][1]==0) { poles.remove(i); }
                    else if(poles[i][1]==-poles[i+1][1]) { poles.remove(i+1); poles.remove(i); }
                    else { qDebug()<<"[CODE:200] Exceptional case. Check plase."; }
                    if(!deletion) {
                        if(pointup[1]<GHCU) {
                            pointup[1] = 0;
                            poles.append(pointup);
                        } else {
                            poles.append(pointup);
                            poles.append(pointdown);
                        }
                        lastType = "pole";
                    }
                    draw(); return; // without caring about the deletion box, we are ending the operation (reason is given below).
                    // reason: since there is a point exists already, we rather not add another point to the current location to avoid collusion.
                }
            }
        } else { // else if(e->button()==Qt::RightButton)
            for(int i=0; i<zeros.size(); i++) {
                if(qFabs(pointup[0]-zeros[i][0])<GHCU & qFabs(pointup[1]-zeros[i][1])<GHCU) {
                    if(zeros[i][1]==0) { zeros.remove(i); }
                    else if (zeros[i][1]==-zeros[i+1][1]) { zeros.remove(i+1); zeros.remove(i); }
                    else { qDebug()<<"[CODE:201] Exceptional case. Check plase."; }
                    if(!deletion) {
                        if(pointup[1]<GHCU) {
                            pointup[1] = 0;
                            zeros.append(pointup);
                        } else {
                            zeros.append(pointup);
                            zeros.append(pointdown);
                        }
                        lastType = "zero";
                    }
                    draw(); return; // without caring about the deletion box, we are ending the operation.
                    // reason: since there is a point exists already, we rather not add another point to the current location to avoid collusion.
                }
            }
        }

        /* second operation:
         * check whether added point's y component is higher than 0.25.
         * if so, add it and its conjugate {where its conjugate is (x, -y)} to the marked position.
         * else, make its y component equal to 0, add its itself (not also it's conjugate).
         */
        if(e->button()==Qt::LeftButton) {
            if(pointup[1]>GHCU) { poles.append(pointup); poles.append(pointdown); }
            else { pointup = {pointup[0], 0}; poles.append(pointup); }
            lastType = "pole";
        } else { // else if(e->button()==Qt::RightButton)
            if(pointup[1]>GHCU) { zeros.append(pointup); zeros.append(pointdown); }
            else { pointup = {pointup[0], 0}; zeros.append(pointup); }
            lastType = "zero";
        }
        draw();
    }
}

void MainWindow::on_planeButton_clicked() {
    const char* x;
    if(currentPlane=='z') {
        ui->plotWidget->graph(2)->data().data()->clear();

        currentPlane='s';
        x = "s-plane";
    } else {
        currentPlane='z';
        x = "z-plane";
    }

    ui->planeButton->setText(QString::fromStdString(x));
    draw();
}

void MainWindow::on_sliderScale_valueChanged(int value) {
    // qDebug()<<value;
    pR = value; // ui->sliderScale->value(); // 1 to 10, 5 by default
    rR = 2*pR;

    ui->labelScale->setText("Scale: "+QString::number(value*10)+"%"); // value*100/10
    GHCU = 0.25*qPow((double)value/5, 3/2); // 0.25*(slider.value()*2/10)^0.5 {value in the paranthesis tend to be 1 by default}

    ui->plotWidget->xAxis->setRange(-pR, pR); ui->plotWidget->yAxis->setRange(-pR, pR);
    ui->plotWidget->replot();
    draw();
}

void MainWindow::on_sliderSensitivity_valueChanged(int value) {
    // qDebug()<<value;
    sens = value; // ui->sliderSensitivity->value(); // 1 to 100, 50 by default
    sens /= 1000; // 50 -> 0.050

    ui->labelSensitivity->setText("Sensitivity: "+QString::number(value)+"%"); // value*100/100
    draw();
}

void MainWindow::on_typeButton_clicked() {
    if(type=='p') {
        type = 'm';
        ui->typeButton->setText("Magnitude");
    } else {
        type = 'p';
        ui->typeButton->setText("Phase");
    }
    draw();
}

void MainWindow::resizeEvent(QResizeEvent* event) {
   QMainWindow::resizeEvent(event);
   draw();
}
