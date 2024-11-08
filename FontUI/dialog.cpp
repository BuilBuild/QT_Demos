#include "dialog.h"
#include "./ui_dialog.h"
#include<QDebug>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    // 颜色设置
    connect(ui->radioBlack, &QRadioButton::clicked, this, &Dialog::setFontColor);
    connect(ui->radioBlue, &QRadioButton::clicked, this, &Dialog::setFontColor);
    connect(ui->radioRed, &QRadioButton::clicked, this, &Dialog::setFontColor);

    // 复选框字体样式
    connect(ui->checkItalic, &QCheckBox::clicked, this, &Dialog::chkItalic_clicked);
    connect(ui->checkUnderLine, &QCheckBox::clicked, this, &Dialog::chkUnderLine_clicked);
    connect(ui->checkBold, &QCheckBox::clicked, this, &Dialog::chkBold_clicked);

    // 清除输入框内容
    connect(ui->pushClear, &QPushButton::clicked, this, &Dialog::btnClear_cliecked);


}

Dialog::~Dialog()
{
    delete ui;
}




void Dialog::setFontColor()
{
    QPalette plet=ui->plainTextEdit->palette();
    if(ui->radioBlack->isChecked())
        plet.setColor(QPalette::Text, Qt::black);
    else if(ui->radioBlue->isChecked())
        plet.setColor(QPalette::Text, Qt::blue);
    else
        plet.setColor(QPalette::Text, Qt::red);
    ui->plainTextEdit->setPalette(plet);

}

void Dialog::chkItalic_clicked(bool checked)
{
    QFont font = ui->plainTextEdit->font();
    font.setItalic(checked);
    ui->plainTextEdit->setFont(font);

}

void Dialog::chkUnderLine_clicked(bool checked)
{
    QFont font = ui->plainTextEdit->font();
    font.setUnderline(checked);
    ui->plainTextEdit->setFont(font);
}

void Dialog::chkBold_clicked(bool checked)
{
    QFont font = ui->plainTextEdit->font();
    font.setBold(checked);
    ui->plainTextEdit->setFont(font);
}

void Dialog::btnClear_cliecked()
{
    ui->plainTextEdit->clear();
}
