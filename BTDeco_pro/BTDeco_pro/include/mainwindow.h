#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>

#include <QMainWindow>
#include <QObject>
#include <QAction>
#include <QDialog>
#include <QInputDialog>
#include <QString>
#include <QStringList>
#include <QFileDialog>
#include <QDir>
#include <QPlainTextEdit>
#include <QProcess>
#include "ui_mainwindow.h"

namespace Ui {
class MainWindow;
}
enum class cDomainType
{
    timing=0,
    frequency,
    none
};

enum class cSimulationType
{
    coSimulate=0,
    electricOnly,
    opticalOnly,
    none
};

enum class cOutFileFormat
{
    fmtDotout,
    fmtHspice,
    fmtSpectre,
    none
};

enum class cElectricSimulator
{
    BTDsim,
    Hspice,
    Spectre,
    other
};

enum class cOpticalSimulator
{
    pSim,
    other
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private:
    cDomainType     domainType;
    cDomainType     syncDomainType;
    cSimulationType simulationType;
    cElectricSimulator electricSimulator;
    cOpticalSimulator  opticalSimulator;
    cOutFileFormat  ouputFormat;

    QString netListFileName;
    QString curPath;

    QString opticalToolPath;
    QString selectricToolPath;
    static QProcess* opticalSimulatorProcess;
    static QProcess* electricSimulatorProcess;

    QString tmpElecPath;
    QString tmpOpticalPath;

private:
    void connectAllSlots();

public slots:
    // declared slots functions
    void onOpenNetlist();
    void onSpecifyNetlistChecked();
    void onSpecifyToolChecked();
    void onSelectExternTool();
    void onOpenExternTool();
    void onExtractNetlist();

    ///< simulations
    void onSelectDomainTiming();
    void onSelectDomainFrequen();
    void onSelectConSimulation();
    void onSelectEelectricOnly();
    void onSelectOpticalOnly();
    void onSelectOutFileFormat();
    void onSelectHspiceFormat();
    void onSelectSpectreFormat();
    void onSaveOutputFile();

    ///< settings
    void onSimulatorBTDsim();
    void onSelectSimulatorHspice();
    void onSelectSimulatorSpectre();
    void onSelectSimulatorPsim();
    void onSelectSimulatorOther();

};

#endif // MAINWINDOW_H
