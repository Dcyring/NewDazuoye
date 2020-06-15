#include "widget.h"
#include "ui_widget.h"

#include "shangyedaikuan.h"
#include "shangyedaikuan2.h"
#include "zuhexingdaikuan.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    loanType=0;
    calcuType=0;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_currentIndex_changed()
{
    loanType=ui->comboBox_daikuanLeibie->currentIndex();
    calcuType=ui->comboBox_jisuanFangshi->currentIndex();
}

void Widget::on_pushButton_queren_clicked()
{
    if(loanType == 2)
    {
        zuhexingdaikuan * widget = new zuhexingdaikuan();
        widget->show();
    }
    else
    {
        if(calcuType == 0)
        {
            shangyedaikuan * widget = new shangyedaikuan();
            widget->show();
        }
        else
        {
            shangyedaikuan2 *widget = new shangyedaikuan2();
            widget->show();
        }
    }
}
void Widget::dengebenxi(double daikuan, double lilv, int months,
                        double &yuegong,double &lixi, double &huankuan)
{

    yuegong =(daikuan * lilv * powl((1 + lilv), months) / (powl((1 + lilv), months) - 1));
    huankuan = yuegong * months;
    lixi = yuegong * months - daikuan;
}

void Widget::dengebenjin(double daikuan, double lilv, int months,
                         double &diyiyue, double &dijian, double &lixi, double &huankuan)
{
    huankuan = 0;
    diyiyue = (daikuan / months) + daikuan * lilv;
    dijian = daikuan / months * lilv;
    double yuegong = diyiyue;
    for(int i = 1; i<= months; ++i){
        huankuan += yuegong;
        yuegong -= dijian;
    }

    lixi = huankuan - daikuan;
}

void Widget::on_comboBox_daikuanLeibie_currentIndexChanged(const QString &arg1)
{
    if(ui->comboBox_daikuanLeibie->currentIndex()==2)ui->comboBox_jisuanFangshi->setEnabled(false);
    else  ui->comboBox_jisuanFangshi->setEnabled(true);

}
