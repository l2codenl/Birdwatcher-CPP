#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class Knob;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Knob *d_frequencyKnob;
    Knob *d_amplitudeKnob;
};

#endif // MAINWINDOW_H
