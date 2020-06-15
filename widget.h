#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    static void dengebenxi(double daikuan, double lilv, int months,
                           double &yuegong, double &lixi, double &huankuan);
    static void dengebenjin(double daikuan, double lilv, int months,
                            double &diyiyue, double &dijian, double &lixi, double &huankuan);
    ~Widget();

private slots:
    void on_currentIndex_changed();

    void on_pushButton_queren_clicked();

    void on_comboBox_daikuanLeibie_currentIndexChanged(const QString &arg1);

private:
    Ui::Widget *ui;
    int calcuType;
    int loanType;
};
#endif // WIDGET_H
