#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
private slots:
    void setFontColor();
    void chkItalic_clicked(bool checked);
    void chkUnderLine_clicked(bool checked);
    void chkBold_clicked(bool checked);
    void btnClear_cliecked();



};
#endif // DIALOG_H
