#include "mainwindow.h"
//#include "ui_mainwindow.h"
#include <QObject>

QProcess* MainWindow::opticalSimulatorProcess = nullptr;
QProcess* MainWindow::electricSimulatorProcess = nullptr;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    curPath = QDir::currentPath();
    opticalToolPath = curPath;
    simulResultOutPath = curPath;
    ui->txedt_msg->appendPlainText("BTD Electric and optical mixed simulator");

    ///< open netlist
    ui->rbtn_specifyNetlist->setChecked(true);
    ui->gb_specifyNetlist->setEnabled(true);
    ui->rbtn_specifyTools->setChecked(false);
    ui->gb_specifyTools->setEnabled(false);
    ui->ledt_openNetlist->setText(curPath+"/example.sp");

    ///< Domain type init as timing
    ui->rbtn_domainTiming->setChecked(true);
    ui->rbtn_domainFrequency->setChecked(false);
    domainType = cDomainType::timing;


    ///< simulation type init as cosimulation
    ui->rbtn_simulTypeCoSimule->setChecked(true);
    ui->rbtn_simuTypeElectOnly->setChecked(false);
    ui->rbtn_simuTypeOpticalOnly->setChecked(false);
    simulationType = cSimulationType::coSimulate;


    ///< output file type
    ui->rbtn_outFileFormat->setChecked(true);
    ui->rbtn_hspiceFormat->setChecked(false);
    ui->rbtn_spectreFormat->setChecked(false);
    ouputFormat = cOutFileFormat::fmtDotout;
    ui->ledt_outputFile->setText(simulResultOutPath);

    connectAllSlots(); //connect all signals and slots

}

MainWindow::~MainWindow()
{
    delete ui;
}

///< slots realize
void MainWindow::onOpenNetlist()
{
    QString curPath = QDir::currentPath();
    QString title("Select the target netlist");
    //QString fileter("Spice(*.sp);;Spectre(*.scs);;文本文件(*.txt);;所有文件(*.*)");
    QString fileter("*.sp;;*.scs;;*.txt;;所有文件(*.*)");
    QString netListFileName = QFileDialog::getOpenFileName(this, title, curPath, fileter);

    if(!netListFileName.isEmpty())
    {
        QString relativePath = netListFileName.replace(curPath,"");
        ui->txedt_msg->appendPlainText(netListFileName);
        ui->ledt_openNetlist->setText(netListFileName);
    }
}

void MainWindow::onSpecifyNetlistChecked()
{
    if(ui->rbtn_specifyNetlist->isChecked())
    {
        ui->gb_specifyNetlist->setEnabled(true);
        ui->gb_specifyTools->setEnabled(false);
        ui->rbtn_specifyTools->setChecked(false);

    }
}

void MainWindow::onSpecifyToolChecked()
{
    if(ui->rbtn_specifyTools->isChecked())
    {
        ui->ledt_execToolPath->setText(opticalToolPath);
        ui->gb_specifyNetlist->setEnabled(false);
        ui->gb_specifyTools->setEnabled(true);
        ui->rbtn_specifyNetlist->setChecked(false);
        ui->ledt_extractNetlist->setText(curPath+"/netlist.sp");
    }
}
void MainWindow::onSelectExternTool()
{
    QString curPath = QDir::currentPath();
    QString title("choose extern excute tool");
    QString fileter("*.exe;;所有文件(*.*)");
    opticalToolPath = QFileDialog::getOpenFileName(this, title, curPath, fileter);

    if(!opticalToolPath.isEmpty())
    {
        ui->ledt_execToolPath->setText(opticalToolPath);
        ui->txedt_msg->appendPlainText("Select Optical Simluator: ");
        ui->txedt_msg->appendPlainText(opticalToolPath);
    }
}
void MainWindow::onOpenExternTool()
{
    QProcess process;
    process.start("tasklist");
    process.waitForFinished();
    QByteArray result = process.readAllStandardOutput();
    if(-1 == result.indexOf("pSim.exe") && !opticalToolPath.isEmpty())
    {
        opticalSimulatorProcess = new QProcess(this);
        ui->txedt_msg->appendPlainText("start up externel optical simulator tool");
        ui->txedt_msg->appendPlainText(opticalToolPath);

        opticalSimulatorProcess->start(opticalToolPath);
        opticalSimulatorProcess->waitForFinished();
        result = opticalSimulatorProcess->readAllStandardOutput();
        ui->txedt_msg->appendPlainText(QString::fromLocal8Bit(result));
    }
    else
    {
        qDebug("pSim already running!\n");
    }
}

void MainWindow::onExtractNetlist()
{

}

///< simulations
void MainWindow::onSelectDomainTiming()
{
    domainType = cDomainType::timing;
}
void MainWindow::onSelectDomainFrequen()
{
    domainType = cDomainType::frequency;
}

void MainWindow::onSelectConSimulation()
{
    simulationType = cSimulationType::coSimulate;
}
void MainWindow::onSelectEelectricOnly()
{
    simulationType = cSimulationType::electricOnly;
}
void MainWindow::onSelectOpticalOnly()
{
    simulationType = cSimulationType::opticalOnly;
}

void MainWindow::onSelectOutFileFormat()
{
    ouputFormat = cOutFileFormat::fmtDotout;
}
void MainWindow::onSelectHspiceFormat()
{
    ouputFormat = cOutFileFormat::fmtHspice;
}
void MainWindow::onSelectSpectreFormat()
{
    ouputFormat = cOutFileFormat::fmtSpectre;
}

void MainWindow::onSaveOutputFile()
{

}
///< settings
void MainWindow::onSimulatorBTDsim()
{
    electricSimulator = cElectricSimulator::BTDsim;
}


void MainWindow::onSelectSimulatorHspice()
{
    electricSimulator = cElectricSimulator::Hspice;
}

void MainWindow::onSelectSimulatorSpectre()
{
    electricSimulator = cElectricSimulator::Spectre;
}

void MainWindow::onSelectSimulatorPsim()
{
    opticalSimulator = cOpticalSimulator::pSim;
}

void MainWindow::onSelectSimulatorOther()
{
    opticalSimulator = cOpticalSimulator::other;
}

void MainWindow::connectAllSlots()
{
    QObject::connect(ui->btn_openNetlist,
                     SIGNAL(clicked()),
                     this,
                     SLOT(onOpenNetlist()));

    QObject::connect(ui->rbtn_specifyNetlist,
                     SIGNAL(clicked()),
                     this,
                     SLOT(onSpecifyNetlistChecked()));

    QObject::connect(ui->rbtn_specifyTools,
                     SIGNAL(clicked()),
                     this,
                     SLOT(onSpecifyToolChecked()));
    QObject::connect(ui->btn_execToolBrower,
                     SIGNAL(clicked()),
                     this,
                     SLOT(onSelectExternTool()));

    QObject::connect(ui->btn_execTools,
                     SIGNAL(clicked()),
                     this,
                     SLOT(onOpenExternTool()));
    ///< simulation
    QObject::connect(ui->rbtn_domainTiming,
                     SIGNAL(clicked()),
                     this,
                     SLOT(onSelectDomainTiming()));
    QObject::connect(ui->rbtn_domainFrequency,
                     SIGNAL(clicked()),
                     this,
                     SLOT(onSelectDomainFrequen()));
    QObject::connect(ui->rbtn_simulTypeCoSimule,
                     SIGNAL(clicked()),
                     this,
                     SLOT(onSelectConSimulation()));
    QObject::connect(ui->rbtn_simuTypeElectOnly,
                     SIGNAL(clicked()),
                     this,
                     SLOT(onSelectEelectricOnly()));
    QObject::connect(ui->rbtn_simuTypeOpticalOnly,
                     SIGNAL(clicked()),
                     this,
                     SLOT(onSelectOpticalOnly()));
    QObject::connect(ui->rbtn_outFileFormat,
                     SIGNAL(clicked()),
                     this,
                     SLOT(onSelectOutFileFormat()));
    QObject::connect(ui->rbtn_hspiceFormat,
                     SIGNAL(clicked()),
                     this,
                     SLOT(onSelectHspiceFormat()));
    QObject::connect(ui->rbtn_spectreFormat,
                     SIGNAL(clicked()),
                     this,
                     SLOT(onSelectSpectreFormat()));
    QObject::connect(ui->btn_outputFile,
                     SIGNAL(clicked()),
                     this,
                     SLOT(onSaveOutputFile()));

    ///< settings
    QObject::connect(ui->rbtn_BTDsim,
                     SIGNAL(clicked()),
                     this,
                     SLOT(onSimulatorBTDsim()));
    QObject::connect(ui->rbtn_Hspice,
                     SIGNAL(clicked()),
                     this,
                     SLOT(onSelectSimulatorHspice()));
    QObject::connect(ui->rbtn_Spectre,
                     SIGNAL(clicked()),
                     this,
                     SLOT(onSelectSimulatorSpectre()));
    QObject::connect(ui->rbtn_opticalSetSimulatorPsim,
                     SIGNAL(clicked()),
                     this,
                     SLOT(onSelectSimulatorPsim()));
    QObject::connect(ui->rbtn_opticalSetSimulatorOther,
                     SIGNAL(clicked()),
                     this,
                     SLOT(onSelectSimulatorOther()));


}

