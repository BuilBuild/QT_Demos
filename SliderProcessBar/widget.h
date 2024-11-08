#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
private slots:
    void do_valueChanged(int);
    void chk_textVisible_clicked(bool);
    void radio_persent_clicked(bool);
    void chk_invertedAppearance_clicked(bool);
    void radio_value_clicked(bool);
};
#endif // WIDGET_H
