#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    activeBuyButton(money);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff)
{
    money = (money + diff < 0 ? 0:money+diff);

    ui->lcdNumber->display(money);
    // ui->pbCoffee->setEnabled(false);
    activeBuyButton(money); // 잔액 변화에 따라 음료 버튼 활성화/비활성화
}

void Widget::activeBuyButton(int money)
{
    ui->buyCoffee->setEnabled(money >= 100);
    ui->buyTea->setEnabled(money >= 150);
    ui->buyMilk->setEnabled(money >= 200);
}

void Widget::on_coin10_clicked()
{
    changeMoney(10);
}

void Widget::on_coin50_clicked()
{
    changeMoney(50);
}

void Widget::on_coin100_clicked()
{
    changeMoney(100);
}

void Widget::on_coin500_clicked()
{
    changeMoney(500);
}

void Widget::on_buyCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_buyTea_clicked()
{
    changeMoney(-150);
}


void Widget::on_buyMilk_clicked()
{
    changeMoney(-200);
}

void Widget::on_getExchange_clicked()
{
    QMessageBox mb;
    std::string c500 = std::to_string(money / 500);
    money %=500;

    std::string c100 = std::to_string(money/100);
    money %= 100;

    std::string c50 = std::to_string(money/50);
    money %= 50;

    std::string c10 = std::to_string(money/10);

    std::string res = "exchange:\ncoin500: " + c500 +", coin100: "
                      + c100 +", coin50: " + c50 + ", coin10: " + c10;

    mb.information(nullptr, "exchange", res.c_str());
    money = 0;
    ui->lcdNumber->display(money);

}



