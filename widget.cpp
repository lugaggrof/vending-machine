#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::check_valid_button()
{
    int value = ui->lcdNumber->value();
    ui->coffee->setDisabled(false);
    ui->tea->setDisabled(false);
    ui->milk->setDisabled(false);

    if (value < 100) {
        ui->coffee->setDisabled(true);
    }
    if (value < 150) {
        ui->tea->setDisabled(true);
    }
    if (value < 200) {
        ui->milk->setDisabled(true);
    }
}

void Widget::reset_lcd_value() {
    ui->lcdNumber->display(0);
    check_valid_button();
}

void Widget::change_lcd_value(int change) {
    ui->lcdNumber->display(ui->lcdNumber->value() + change);
    check_valid_button();
}

void Widget::on_add10_clicked()
{
    change_lcd_value(10);
}

void Widget::on_add50_clicked()
{
    change_lcd_value(50);
}

void Widget::on_add100_clicked()
{
    change_lcd_value(100);
}

void Widget::on_add500_clicked()
{
    change_lcd_value(500);
}

void Widget::on_coffee_clicked()
{
    change_lcd_value(-100);
}

void Widget::on_tea_clicked()
{
    change_lcd_value(-150);
}

void Widget::on_milk_clicked()
{
    change_lcd_value(-200);
}

void Widget::on_reset_clicked()
{
    QMessageBox msgBox;
    int value = ui->lcdNumber->value();
    QString msg = "";
    int changes[4] = {500, 100, 50, 10};
    bool before = false;

    for (int i = 0; i < 4; i++) {
        int count = value / changes[i];
        if (count > 0) {
            if (before) {
                msg += ", ";
            }
            value = value - count * changes[i];
            msg += QString::number(changes[i]);
            msg += "$: ";
            msg += QString::number(count);

            before = true;
        }
    }

    if (msg.length() == 0) {
        msg = "no changes";
    }

    msgBox.setText(msg);
    msgBox.exec();
    reset_lcd_value();
}
