#include "shangyedaikuan.h"
#include "ui_shangyedaikuan.h"

#include "shangyedaikuandengebenxi.h"
#include "shangyedaikuandengebenjin.h"
#include "widget.h"

#include <QDebug>

shangyedaikuan::shangyedaikuan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::shangyedaikuan)
{
    ui->setupUi(this);
}

shangyedaikuan::~shangyedaikuan()
{
    delete ui;
}

void shangyedaikuan::on_text_changed(){
    //当输入改变时
    //这里判断是否所有lineEdit都有输入
    //如果有，启用按钮
    //否则，禁用按钮
    bool flag1 = ui->lineEdit_daikuanLilv->text().isEmpty();
    bool flag2 = ui->lineEdit_fangwuDanjia->text().isEmpty();
    bool flag3 = ui->lineEdit_fangwuMianji->text().isEmpty();
    if(!flag1&&!flag2&&!flag3)
    {
        ui->pushButton_kaishiJisuan->setEnabled(true);
    }
    else
    {
        ui->pushButton_kaishiJisuan->setEnabled(false);
    }
}

void shangyedaikuan::on_pushButton_kaishiJisuan_clicked()
{
    //当按钮被点击后
    //这里获取输入的文本  和 combobox的内容
    double fwdj = ui->lineEdit_fangwuDanjia->text().toInt();
    double fwmj = ui->lineEdit_fangwuMianji->text().toInt();
    double dklv = ui->lineEdit_daikuanLilv->text().toDouble()/100/12;
    double ajcs = ui->comboBox_anjieChengshu->currentText().toDouble()/10;
    double ajns = ui->comboBox_anjieNianshu->currentText().toDouble();
    int refundType = ui->comboBox_huankuanFangshi->currentIndex();

    //等额本息
    if(refundType == 0)
    {
        double daikuan = fwdj*fwmj*ajcs;
        double shoufu = fwdj*fwmj*(1-ajcs);

        int months = ajns * 12;

        double yuegong,lixi,huankuan;

        Widget::dengebenxi(daikuan,dklv,months,yuegong,lixi,huankuan);

        qDebug()<<yuegong<<endl;
        qDebug()<<lixi<<endl;
        qDebug()<<huankuan<<endl;

        shangyedaikuandengebenxi*dialog = new shangyedaikuandengebenxi(shoufu,yuegong,daikuan,lixi,huankuan,months);
        dialog->show();
    }
    //等额本金
    else
    {
        double daikuan = fwdj*fwmj*ajcs;
        double shoufu = fwdj*fwmj*(1-ajcs);

        int months = ajns*12;

        double diyiyue, dijian,lixi,huankuan;

        Widget::dengebenjin(daikuan,dklv,months,diyiyue,dijian,lixi,huankuan);
        shangyedaikuandengebenjin*dialog = new shangyedaikuandengebenjin(shoufu,diyiyue,dijian,daikuan,lixi,huankuan,months);
        dialog->show();
    }
}
