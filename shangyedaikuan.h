#ifndef SHANGYEDAIKUAN_H
#define SHANGYEDAIKUAN_H

#include <QWidget>

namespace Ui {
class shangyedaikuan;
}

class shangyedaikuan : public QWidget
{
    Q_OBJECT

public:
    explicit shangyedaikuan(QWidget *parent = nullptr);
    ~shangyedaikuan();

private slots:
    void on_text_changed();
    void on_pushButton_kaishiJisuan_clicked();

private:
    Ui::shangyedaikuan *ui;
};

#endif // SHANGYEDAIKUAN_H
