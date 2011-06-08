#include <qwt_sampling_thread.h>
#include <qwt_dial.h>

class SimulationThread : public QwtSamplingThread
{
    Q_OBJECT

public:
    SimulationThread(QObject *parent = NULL);

    double frequency() const;
    double amplitude() const;

public Q_SLOTS:
    void setAmplitude(double);
    void setFrequency(double);
    void SetToDial(QwtDial*, double);

protected:
    virtual void sample(double elapsed);

private:
    virtual double value(double timeStamp) const;

    double d_frequency;
    double d_amplitude;
};
