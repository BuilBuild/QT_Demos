#include "widget.h"
#include "./ui_widget.h"
#include<QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 将表盘，滑块，滚条的valueChanged信号与自定义槽函数关联
    connect(ui->dial, &QDial::valueChanged, this, &Widget::do_valueChanged);
    connect(ui->Slider, &QSlider::valueChanged, this, &Widget::do_valueChanged);
    connect(ui->ScrollBar, &QScrollBar::valueChanged, this, &Widget::do_valueChanged);

    //
    connect(ui->chk_textVisible, &QCheckBox::clicked, this, &Widget::chk_textVisible_clicked);
    connect(ui->chk_invertedAppearance, &QCheckBox::clicked, this, &Widget::chk_invertedAppearance_clicked);
    connect(ui->radio_persent, &QRadioButton::clicked, this, &Widget::radio_persent_clicked);
    connect(ui->radio_value, &QRadioButton::clicked, this, &Widget::radio_value_clicked);

    this->setWindowTitle("Slider ProcessBar");

    ui->dial->setValue(0);
    ui->ScrollBar->setValue(0);
    ui->Slider->setValue(0);
    ui->progressBar->setValue(0);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::do_valueChanged(int changedValue)
{
    ui->progressBar->setValue(changedValue);
    ui->dial->setValue(changedValue);
    ui->ScrollBar->setValue(changedValue);
    ui->Slider->setValue(changedValue);
}

void Widget::chk_textVisible_clicked(bool checked)
{
    ui->progressBar->setTextVisible(checked);
}

void Widget::radio_persent_clicked(bool checked)
{
    ui->progressBar->setFormat("%p%");
}

void Widget::chk_invertedAppearance_clicked(bool checked)
{
    ui->progressBar->setInvertedAppearance(checked);
}

void Widget::radio_value_clicked(bool checked)
{
     ui->progressBar->setFormat("%v");
}
