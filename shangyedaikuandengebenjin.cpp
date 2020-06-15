#include "shangyedaikuandengebenjin.h"
#include "ui_shangyedaikuandengebenjin.h"

shangyedaikuandengebenjin::shangyedaikuandengebenjin(double shoufu,double shouyue,double dijian,
                                                     double daikuan, double lx, double huankuan,
                                                     int month,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::shangyedaikuandengebenjin)
{
    ui->setupUi(this);
    ui->lineEdit_shoufu->setText(QString::number(shoufu,'f',2));
    ui->lineEdit_meiyueYuegong->setText(QString::number(shouyue,'f',2));
    ui->lineEdit_meiyueDijian->setText(QString::number(dijian,'f',2));
    ui->lineEdit_daikuanZonge->setText(QString::number(daikuan,'f',2));
    ui->lineEdit_zhifuLixi->setText(QString::number(lx,'f',2));
    ui->lineEdit_huankuanZonge->setText(QString::number(huankuan,'f',2));
    ui->lineEdit_huankuanYueshu->setText(QString::number(month));
}

shangyedaikuandengebenjin::~shangyedaikuandengebenjin()
{
    delete ui;
}

