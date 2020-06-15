#ifndef SHANGYEDAIKUANDENGEBENXI_H
#define SHANGYEDAIKUANDENGEBENXI_H

#include <QDialog>

namespace Ui {
class shangyedaikuandengebenxi;
}

class shangyedaikuandengebenxi : public QDialog
{
    Q_OBJECT

public:
    //计算结果 首付 每月月供 贷款总额 支付利息 还款总额 还款月数
    explicit shangyedaikuandengebenxi(double shoufu,double yuegong, double daikuan,
                                      double lx, double huankuan, int month,QWidget *parent = nullptr);
    ~shangyedaikuandengebenxi();

private:
    Ui::shangyedaikuandengebenxi *ui;
};

#endif // SHANGYEDAIKUANDENGEBENXI_H
