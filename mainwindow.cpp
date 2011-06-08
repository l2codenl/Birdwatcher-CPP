#include "mainwindow.h"
#include "plot.h"
#include "knob.h"
#include "wheelbox.h"
#include <qwt_scale_engine.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qwt_dial.h>
#include <qwt_dial_needle.h>
#include <qtimer.h>
#include <qwt_analog_clock.h>

MainWindow::MainWindow(QWidget *parent):
    QWidget(parent)
{
    QwtDial *dial = NULL;
    QwtDial *sdial = NULL;

    const double intervalLength = 10.0; // seconds
    this->setStyleSheet("background-color: #333; color: #EAEAEA;");
    d_plot = new Plot(this);
    d_plot->setIntervalLength(intervalLength);

    d_amplitudeKnob = new Knob("Amplitude", 0.0, 200.0, this);
    d_amplitudeKnob->setValue(160.0);

    d_frequencyKnob = new Knob("Frequency [Hz]", 0.1, 20.0, this);
    d_frequencyKnob->setValue(17.8);

    d_intervalWheel = new WheelBox("Displayed [s]", 1.0, 100.0, 1.0, this);
    d_intervalWheel->setValue(intervalLength);

    d_timerWheel = new WheelBox("Sample Interval [ms]", 0.0, 20.0, 0.1, this);
    d_timerWheel->setValue(10.0);

    d_speedo = new SpeedoMeter(this);
    d_speedo->setRange(0.0, 2000.0);
    d_speedo->setScale(-1, 2, 250);

    QTimer *timer = new QTimer(d_speedo);
    timer->connect(timer, SIGNAL(timeout()),
        this, SLOT(changeSpeed()));
    timer->start();

    sdial = d_speedo;

    d_attitude = new AttitudeIndicator();
    QTimer *gradientTimer = new QTimer(d_attitude);
    gradientTimer->connect(gradientTimer, SIGNAL(timeout()),
        this, SLOT(changeGradient()));
    gradientTimer->start(100);

    QTimer *angleTimer = new QTimer(d_attitude);
    angleTimer->connect(angleTimer, SIGNAL(timeout()),
        this, SLOT(changeAngle()));
    angleTimer->start(100);

    dial = d_attitude;
    dial->setReadOnly(true);
    dial->scaleDraw()->setPenWidth(3);
    dial->setLineWidth(1);
    dial->setFrameShadow(QwtDial::Sunken);


    QVBoxLayout* vLayout1 = new QVBoxLayout();
    vLayout1->addWidget(d_intervalWheel);
    vLayout1->addWidget(d_timerWheel);
    vLayout1->addStretch(10);
    vLayout1->addWidget(d_amplitudeKnob);
    vLayout1->addWidget(d_frequencyKnob);


    QGridLayout *grid = new QGridLayout();
    grid->setSpacing(5);
    grid->setMargin(0);
    grid->addWidget(dial, 1, 0, 1, 1, 0);
    grid->addWidget(sdial, 2, 0, 1, 1, 0);


    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(d_plot, 10);
    layout->addLayout(vLayout1);
    layout->addLayout(grid, 3);

    connect(d_amplitudeKnob, SIGNAL(valueChanged(double)),
        SIGNAL(amplitudeChanged(double)));
    connect(d_frequencyKnob, SIGNAL(valueChanged(double)),
        SIGNAL(frequencyChanged(double)));
    connect(d_timerWheel, SIGNAL(valueChanged(double)),
        SIGNAL(signalIntervalChanged(double)));

    connect(d_intervalWheel, SIGNAL(valueChanged(double)),
        d_plot, SLOT(setIntervalLength(double)) );
}

void MainWindow::start()
{
    d_plot->start();
}

double MainWindow::frequency() const
{
    return d_frequencyKnob->value();
}

double MainWindow::amplitude() const
{
    return d_amplitudeKnob->value();
}

double MainWindow::signalInterval() const
{
    return d_timerWheel->value();
}

void MainWindow::changeSpeed()
{

    if(d_speedo->value() > 1900){
        d_speedo->setValue(d_speedo->value() - 100);
    } else if(d_speedo->value() < 400) {
        d_speedo->setValue(d_speedo->value() + 100);
    }

}

