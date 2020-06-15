#ifndef ZUHEXINGDAIKUAN_H
#define ZUHEXINGDAIKUAN_H

#include <QWidget>

namespace Ui {
class zuhexingdaikuan;
}

class zuhexingdaikuan : public QWidget
{
    Q_OBJECT

public:
    explicit zuhexingdaikuan(QWidget *parent = nullptr);
    ~zuhexingdaikuan();

private slots:
    void on_text_changed();
    void on_pushButton_kaishiJisuan_clicked();

private:
    Ui::zuhexingdaikuan *ui;
};

#endif // ZUHEXINGDAIKUAN_H
