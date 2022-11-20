#include "dialog.h"
#include "ui_dialog.h"
#include <QDir>
#include <QString>
#include <QFileDialog>
#include <QInputDialog>
#include <QFontDialog>
#include <QColorDialog>
#include <QPlainTextEdit>
#include <QObject>
#include <QMessageBox>
#include <QColor>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_btnQuestion_clicked()
{
    QString dialogTitle("Question消息框");
    QString infoContent("文件已经被修改，是否保存修改");

    QMessageBox::StandardButton defaultBtn = QMessageBox::NoButton;
    QMessageBox::StandardButton resultBtn;
    resultBtn = QMessageBox::question(
                this, dialogTitle, infoContent,
                QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel,
                defaultBtn);
    if(resultBtn == QMessageBox::Yes)
    {
        ui->plainTextEdit->appendPlainText("Question消息框： yes");
    }
    else if(resultBtn == QMessageBox::No)
    {
        ui->plainTextEdit->appendPlainText("Question消息框： no");
    }
    else if(resultBtn == QMessageBox::Cancel)
    {
        ui->plainTextEdit->appendPlainText("Question消息框： cancel");
    }
    else
    {
        ui->plainTextEdit->appendPlainText("Question消息框： 无选择");
    }
}

void Dialog::on_btnCirtical_clicked()
{
    QString title("critical massage");
    QString strinfo("critical error!");
    //QMessageBox::critical(this, title, strinfo);
    QMessageBox::critical(this, title,strinfo,
                          QMessageBox::Yes,
                          QMessageBox::NoButton);
}

void Dialog::on_btnInformation_clicked()
{
    QString title = "information dialog";
    QString info = "文件已经打开，字体大小已经设置";
    QMessageBox::information(this, title, info);
}

void Dialog::on_btnWarning_clicked()
{
    QString title9("warning dialog");
    QString info("some warning message!");
    QMessageBox::warning(this, title9, info);
}

void Dialog::on_btnAbout_clicked()
{
    QString title("About");
    QString strinfo("dialog学习demo");
    QMessageBox::about(this , title, strinfo);
}

void Dialog::on_btnAboutQt_clicked()
{
    QString title("about qt");
    QMessageBox::aboutQt(this, title);
}
//input Dialog
void Dialog::on_btnInputStr_clicked()
{
    QString title = "Input dialog";
    QString txtLabel = "please input text:";
    QString defaultConten = "new file.txt";
    QLineEdit::EchoMode echomode = QLineEdit::Normal;
    //QLineEdit::EchoMode echomode = QLineEdit::Password; //密码输入

    bool ok = false;
    QString text =
            QInputDialog::getText(this, title, txtLabel, echomode, defaultConten, &ok);
    if(ok && !text.isEmpty())
    {
        ui->plainTextEdit->appendPlainText(text);
    }
}

void Dialog::on_btnInputInt_clicked()
{
    QString title("Int dialog");
    QString info("set the font size:");
    int defaultVal = ui->plainTextEdit->font().pointSize();

    bool ok = false;
    int minValue = 6, maxValue = 50, step = 1;

    int inputValue = QInputDialog::getInt(this,title, info, defaultVal,
                                          minValue, maxValue, step, &ok);
    if(ok)
    {
        QFont font = ui->plainTextEdit->font();
        font.setPointSize(inputValue);
        ui->plainTextEdit->setFont(font);
    }
}

void Dialog::on_btnInputDouble_clicked()
{
    QString title("Double Dialog");
    QString txtLabel("input double data:");
    float defaultVal = 3.13;
    float minVal = 0, maxVal = 10000;
    int decimals = 2;

    bool ok =false;
    float data = QInputDialog::getDouble(this, title, txtLabel,
                                  defaultVal, minVal,maxVal, decimals,
                                  &ok);
    if(ok)
    {
        QString str(QString::asprintf("输入一个浮点数%.2f",data));
        ui->plainTextEdit->appendPlainText(str);
    }
}

void Dialog::on_btnInputItem_clicked()
{
    QStringList items;
    items<< "优秀" << "良好" << "合格" << "不合格";

    QString title("Item dialog");
    QString label("选择级别:");

    int curIndex = 0;
    bool editable = true;
    bool ok = false;
    QString text = QInputDialog::getItem(this, title, label, items, curIndex, editable, &ok);
    if(ok &&!text.isEmpty())
    {
        ui->plainTextEdit->appendPlainText(text);
    }
}

// fileDialog
void Dialog::on_btnOpenFile_clicked()
{
    QString curPath = QDir::currentPath();
    QString fdlgTitle(tr("选择一个文件"));
    QString filter("文本文件(*.txt);;"
                   "图片文件(*.jpg *.gif *.png);;"
                   "所有文件(*.*)");
    QString curFileName = QFileDialog::getOpenFileName(this,
        fdlgTitle, curPath, filter);
    if(!curFileName.isEmpty())
    {
        ui->plainTextEdit->appendPlainText(curFileName);
    }
}

void Dialog::on_btnOpenMulitFile_clicked()
{
    QString curPath = QDir::currentPath();
    QString fdlgTitle(tr("选择一个文件"));
    QString filter("文本文件(*.txt);;"
                   "图片文件(*.jpg *.gif *.png);;"
                   "所有文件(*.*)");
    QStringList curFileNames = QFileDialog::getOpenFileNames(this,
        fdlgTitle, curPath, filter);

    for(int i= 0; i< curFileNames.count(); i++)
    {
        ui->plainTextEdit->appendPlainText(curFileNames[i]);
    }
}
void Dialog::on_btnSelectExistDir_clicked()
{
    QString curPath = QCoreApplication::applicationDirPath();
    QString dialogTile = "选择一个已经存在的目录";
    QString selExistDir = QFileDialog::getExistingDirectory(this,
                                                            dialogTile,
                                                            curPath,
                                                            QFileDialog::ShowDirsOnly);
    if(!selExistDir.isEmpty())
    {
        ui->plainTextEdit->appendPlainText(selExistDir);
    }
}
void Dialog::on_btnSaveFile_clicked()
{
    QString curPath = QCoreApplication::applicationDirPath();
    QString dialogTile("保存文件");
    QString filter("h文件(*.h *.hpp);;"
                   "c++文件(*.cc *.cpp);;"
                   "所有文件(*.*)");
    QString saveFileName = QFileDialog::getSaveFileName(this,
                                                        dialogTile,
                                                        curPath,
                                                        filter);
    if(!saveFileName.isEmpty())
    {
        ui->plainTextEdit->appendPlainText(saveFileName);
    }
}


// QColorDialog
void Dialog::on_btnSelectColor_clicked()
{
    QPalette pal = ui->plainTextEdit->palette();
    QColor cr = pal.color(QPalette::Text);//现有文字的颜色
    //<选择颜色
    QColor curColor = QColorDialog::getColor(cr, this, "选择颜色");
    if(curColor.isValid())
    {
        pal.setColor(QPalette::Text, curColor);
        ui->plainTextEdit->setPalette(pal);
    }

}

// QFontDialog
void Dialog::on_btnSelectFont_clicked()
{
    QFont curfon = ui->plainTextEdit->font();
    bool ok = false;
    QFont font = QFontDialog::getFont(&ok, curfon);
    if(ok)
    {
        ui->plainTextEdit->setFont(font);
    }
}

void Dialog::on_btnClearText_clicked()
{
    ui->plainTextEdit->clear();
}

