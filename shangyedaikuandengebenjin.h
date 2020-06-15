#ifndef SHANGYEDAIKUANDENGEBENJIN_H
#define SHANGYEDAIKUANDENGEBENJIN_H

#include <QDialog>

namespace Ui {
class shangyedaikuandengebenjin;
}

class shangyedaikuandengebenjin : public QDialog
{
    Q_OBJECT

public:
    //首付  首月月供  每月递减  贷款总额  支付利息  还款总额  还款月数
    explicit shangyedaikuandengebenjin(double shoufu,double shouyue,double dijian,
                                       double daikuan, double lx, double huankuan,
                                       int month,QWidget *parent = nullptr);
    ~shangyedaikuandengebenjin();

private:
    Ui::shangyedaikuandengebenjin *ui;
};

#endif // SHANGYEDAIKUANDENGEBENJIN_H
