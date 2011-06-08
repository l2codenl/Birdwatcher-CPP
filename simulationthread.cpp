#include "simulationthread.h"
#include "signaldata.h"
#include <qwt_dial.h>
#include <qwt_math.h>
#include <math.h>

SimulationThread::SimulationThread(QObject *parent):
    QwtSamplingThread(parent),
    d_frequency(5.0),
    d_amplitude(20.0)
{
}

void SimulationThread::setFrequency(double frequency)
{
    d_frequency = frequency;
}

double SimulationThread::frequency() const
{
    return d_frequency;
}

void SimulationThread::setAmplitude(double amplitude)
{
    d_amplitude = amplitude;
}

double SimulationThread::amplitude() const
{
    return d_amplitude;
}

void SimulationThread::sample(double elapsed)
{
    if ( d_frequency > 0.0 )
    {
        const QPointF s(elapsed, value(elapsed));
        SignalData::instance().append(s);
    }
}

double SimulationThread::value(double timeStamp) const
{
    const double period = 1.0 / d_frequency;

    const double x = ::fmod(timeStamp, period);
    const double v = abs(d_amplitude * sin(x / period * 2 * M_PI)) *1000;

    return v;
}

void SimulationThread::SetToDial(QwtDial *d, double value){
    d->setValue(value);
}
