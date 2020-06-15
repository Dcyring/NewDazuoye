#include "zuhexingdaikuan.h"
#include "ui_zuhexingdaikuan.h"
#include "shangyedaikuandengebenxi.h"
#include "shangyedaikuandengebenjin.h"
#include "widget.h"

zuhexingdaikuan::zuhexingdaikuan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::zuhexingdaikuan)
{
    ui->setupUi(this);
}

zuhexingdaikuan::~zuhexingdaikuan()
{
    delete ui;
}

void zuhexingdaikuan::on_text_changed(){
    //当输入改变时
    //这里判断是否所有lineEdit都有输入
    //如果有，启用按钮
    //否则，禁用按钮
    bool flag1 = ui->lineEdit_shangyeDaikuane->text().isEmpty();
    bool flag2 = ui->lineEdit_shangdaiLilv->text().isEmpty();
    bool flag3 = ui->lineEdit_gongjijinDaikuane->text().isEmpty();
    bool flag4 = ui->lineEdit_gongjijinLilv->text().isEmpty();
    if(!flag1&&!flag2&&!flag3&&!flag4)
    {
        ui->pushButton_kaishiJisuan->setEnabled(true);
    }
    else
    {
        ui->pushButton_kaishiJisuan->setEnabled(false);
    }
}

void zuhexingdaikuan::on_pushButton_kaishiJisuan_clicked()
{
    //当按钮被点击后
    //这里获取输入的文本  和 combobox的内容
    double sydke = ui->lineEdit_shangyeDaikuane->text().toInt();
    double gjjdke = ui->lineEdit_gongjijinDaikuane->text().toInt();
    double sdlv = ui->lineEdit_shangdaiLilv->text().toDouble()/100/12;
    double gjjlv = ui->lineEdit_gongjijinLilv->text().toDouble()/100/12;
    double ajns = ui->comboBox_anjieNianshu->currentText().toDouble();
    int refundType = ui->comboBox_huankuanFangshi->currentIndex();

    //等额本息
    if(refundType == 0){
        double shoufu = 0;

        int months = ajns * 12;

        double yuegong,lixi,huankuan;

        double yuegong1, yuegong2,lixi1,huankuan1,lixi2,huankuan2;

        Widget::dengebenxi(sydke,sdlv,months,yuegong1,lixi1,huankuan1);
        Widget::dengebenxi(gjjdke,gjjlv,months,yuegong2,lixi2,huankuan2);

        yuegong = yuegong1 + yuegong2;
        lixi = lixi1 + lixi2;
        huankuan = huankuan1 + huankuan2;

        shangyedaikuandengebenxi*dialog = new shangyedaikuandengebenxi(shoufu,yuegong,sydke+gjjdke,lixi,huankuan,months);
        dialog->show();
    }
    //等额本金
    else{
        double shoufu = 0;

        int months = ajns*12;

        double diyiyue, dijian,lixi,huankuan;

        double diyiyue1, dijian1,lixi1,huankuan1;

        double diyiyue2, dijian2,lixi2,huankuan2;

        Widget::dengebenjin(sydke,sdlv,months,diyiyue1,dijian1,lixi1,huankuan1);
        Widget::dengebenjin(gjjdke,gjjlv,months,diyiyue2,dijian2,lixi2,huankuan2);

        diyiyue = diyiyue1 + diyiyue2;
        dijian = dijian1 + dijian2;
        huankuan = huankuan1 + huankuan2;
        lixi = lixi1 + lixi2;

        shangyedaikuandengebenjin*dialog = new shangyedaikuandengebenjin(shoufu,diyiyue,dijian,sydke + gjjdke,lixi,huankuan,months);
        dialog->show();
    }
}
