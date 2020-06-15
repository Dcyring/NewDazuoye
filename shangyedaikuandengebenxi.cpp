#include "shangyedaikuandengebenxi.h"
#include "ui_shangyedaikuandengebenxi.h"

shangyedaikuandengebenxi::shangyedaikuandengebenxi(double shoufu,double yuegong, double daikuan,
                                                   double lx, double huankuan, int month,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::shangyedaikuandengebenxi)
{
    ui->setupUi(this);
    ui->lineEdit_shoufu->setText(QString::number(shoufu,'f',2));
    ui->lineEdit_meiyueYuegong->setText(QString::number(yuegong,'f',2));
    ui->lineEdit_daikuanZonge->setText(QString::number(daikuan,'f',2));
    ui->lineEdit_zhifuLixi->setText(QString::number(lx,'f',2));
    ui->lineEdit_huankuanZonge->setText(QString::number(huankuan,'f',2));
    ui->lineEdit_huankuanYueshu->setText(QString::number(month));
}

shangyedaikuandengebenxi::~shangyedaikuandengebenxi()
{
    delete ui;
}
