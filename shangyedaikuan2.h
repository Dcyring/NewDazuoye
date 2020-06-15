#ifndef SHANGYEDAIKUAN2_H
#define SHANGYEDAIKUAN2_H

#include <QWidget>

namespace Ui {
class shangyedaikuan2;
}

class shangyedaikuan2 : public QWidget
{
    Q_OBJECT

public:
    explicit shangyedaikuan2(QWidget *parent = nullptr);
    ~shangyedaikuan2();

private slots:
    void on_text_changed();
    void on_pushButton_kaishiJisuan_clicked();

private:
    Ui::shangyedaikuan2 *ui;
};

#endif // SHANGYEDAIKUAN2_H
