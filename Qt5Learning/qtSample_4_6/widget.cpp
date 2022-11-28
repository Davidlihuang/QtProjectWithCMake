#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


///< general combobox
void Widget::on_btn_initCboBox_clicked()
{
    ui->cbb_generaCboBox->clear();
    for(int i =0; i< 20; i++)
    {
        ui->cbb_generaCboBox->addItem(QString("Item %1").arg(i));
    }
}

void Widget::on_btn_clearCboBox_clicked()
{
    ui->cbb_generaCboBox->clear();
}

void Widget::on_cb_isEditable_clicked(bool checked)
{

      ui->cbb_generaCboBox->setEditable(checked);
 }

void Widget::on_cbb_generaCboBox_currentIndexChanged(const QString &arg1)
{
    ui->pte_plainTextEdit->appendPlainText(arg1);
}

///< user data combobox
void Widget::on_btn_initCityNumber_clicked()
{
    QMap<QString, int> CityZone;
    CityZone.insert("北京",10);
    CityZone.insert("上海",21);
    CityZone.insert("天津",22);
    CityZone.insert("大连",411);
    CityZone.insert("锦州",416);
    CityZone.insert("徐州",516);
    CityZone.insert("福州",591);
    CityZone.insert("青岛",532);

    ui->cbb_userDataCboBox->clear();

    foreach(const QString& str, CityZone.keys())
    {
        ui->cbb_userDataCboBox->addItem(str, CityZone.value(str));
    }
}


void Widget::on_cbb_userDataCboBox_currentIndexChanged(const QString &arg1)
{
    QString zone = ui->cbb_userDataCboBox->currentData().toString();
    QString str = QString("地区:%1, 区号: %2").arg(arg1, zone);
    ui->pte_plainTextEdit->appendPlainText(str);
}


///< plaincontext
void Widget::on_btn_addContextToCboBox_clicked()
{
    QTextDocument *doc = ui->pte_plainTextEdit->document();
    if(doc == nullptr) return;
    int count = doc->blockCount();

    ui->cbb_generaCboBox->clear();
    for(int i=0; i< count ; i++)
    {
        QTextBlock textLine = doc->findBlockByNumber(i);
        QString str = textLine.text();
        ui->cbb_generaCboBox->addItem(str);
    }
}

void Widget::on_btn_clearContext_clicked()
{
    ui->pte_plainTextEdit->clear();
}

void Widget::on_cb_isReadOnly_clicked(bool checked)
{
    ui->pte_plainTextEdit->setReadOnly(checked);
}

void Widget::on_pte_plainTextEdit_customContextMenuRequested(const QPoint &pos)
{
    QMenu* menu = ui->pte_plainTextEdit->createStandardContextMenu();
    if(menu)
    {
        menu->exec(pos);
    }
}
