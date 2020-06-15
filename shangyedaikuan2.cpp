#include "shangyedaikuan2.h"
#include "ui_shangyedaikuan2.h"
#include "shangyedaikuandengebenxi.h"
#include "shangyedaikuandengebenjin.h"
#include "widget.h"

shangyedaikuan2::shangyedaikuan2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::shangyedaikuan2)
{
    ui->setupUi(this);
}

shangyedaikuan2::~shangyedaikuan2()
{
    delete ui;
}

void shangyedaikuan2::on_text_changed(){
    //当输入改变时
    //这里判断是否所有lineEdit都有输入
    //如果有，启用按钮
    //否则，禁用按钮
    bool flag1 = ui->lineEdit_daikuanLilv->text().isEmpty();
    bool flag2 = ui->lineEdit_daikuanZonge->text().isEmpty();
    if(!flag1&&!flag2){
        ui->pushButton_kaishiJisuan->setEnabled(true);
    }
    else{
        ui->pushButton_kaishiJisuan->setEnabled(false);
    }
}

void shangyedaikuan2::on_pushButton_kaishiJisuan_clicked()
{
    //当按钮被点击后
    //这里获取输入的文本  和 combobox的内容
    double dkze = ui->lineEdit_daikuanZonge->text().toInt();
    double dklv = ui->lineEdit_daikuanLilv->text().toDouble()/100/12;
    double ajns = ui->comboBox_anjieNianshu->currentText().toDouble();
    int refundType = ui->comboBox_huankuanFangshi->currentIndex();

    //等额本息
    if(refundType == 0){
        double shoufu = 0;

        int months = ajns * 12;

        double yuegong,lixi,huankuan;

        Widget::dengebenxi(dkze,dklv,months,yuegong,lixi,huankuan);
        shangyedaikuandengebenxi*dialog = new shangyedaikuandengebenxi(shoufu,yuegong,dkze,lixi,huankuan,months);
        dialog->show();
    }
    //等额本金
    else{
        double shoufu = 0;

        int months = ajns*12;

        double diyiyue, dijian,lixi,huankuan;

        Widget::dengebenjin(dkze,dklv,months,diyiyue,dijian,lixi,huankuan);
        shangyedaikuandengebenjin*dialog = new shangyedaikuandengebenjin(shoufu,diyiyue,dijian,dkze,lixi,huankuan,months);
        dialog->show();
    }
}
