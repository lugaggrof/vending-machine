#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_add10_clicked();

    void on_add50_clicked();

    void on_add500_clicked();

    void on_add100_clicked();

    void on_coffee_clicked();

    void on_tea_clicked();

    void on_milk_clicked();

    void check_valid_button();

    void change_lcd_value(int change);

    void reset_lcd_value();

    void on_reset_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
