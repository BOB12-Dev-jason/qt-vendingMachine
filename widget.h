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
    ~Widget();

    int money {0};

    void changeMoney(int diff);
    void activeBuyButton(int money);

private slots:
    void on_coin10_clicked();

    void on_coin50_clicked();

    void on_coin100_clicked();

    void on_coin500_clicked();

    void on_buyCoffee_clicked();

    void on_buyTea_clicked();

    void on_buyMilk_clicked();

    void on_getExchange_clicked();


private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
