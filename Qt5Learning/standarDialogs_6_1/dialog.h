#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

public slots:
    void on_btnQuestion_clicked();
    void on_btnCirtical_clicked();
    void on_btnInformation_clicked();
    void on_btnWarning_clicked();
    void on_btnAbout_clicked();
    void on_btnAboutQt_clicked();

    void on_btnInputStr_clicked();
    void on_btnInputDouble_clicked();
    void on_btnInputInt_clicked();
    void on_btnInputItem_clicked();

    void on_btnOpenFile_clicked();
    void on_btnSaveFile_clicked();
    void on_btnOpenMulitFile_clicked();
    void on_btnSelectExistDir_clicked();
    void on_btnSelectColor_clicked();
    void on_btnSelectFont_clicked();

    void on_btnClearText_clicked();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
