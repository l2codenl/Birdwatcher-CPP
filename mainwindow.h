#include <qwidget.h>
#include <QPalette>
#include <attitude_indicator.h>
#include <speedo_meter.h>

class Plot;
class Knob;
class WheelBox;
class QPallete;
class AttitudeIndicator;
class Speedometer;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget * = NULL);

    void start();

    double amplitude() const;
    double frequency() const;
    double signalInterval() const;

Q_SIGNALS:
    void amplitudeChanged(double);
    void frequencyChanged(double);
    void signalIntervalChanged(double);

private:
    Knob *d_frequencyKnob;
    Knob *d_amplitudeKnob;
    WheelBox *d_timerWheel;
    WheelBox *d_intervalWheel;
    AttitudeIndicator *d_attitude;
    SpeedoMeter *d_speedo;
    Plot *d_plot;
};
