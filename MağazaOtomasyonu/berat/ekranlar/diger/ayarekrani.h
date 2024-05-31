#pragma once

#include <QDialog>

namespace Ui {
class AyarEkrani;
}

class AyarEkrani : public QDialog
{
    Q_OBJECT

public:
    explicit AyarEkrani(QWidget *parent = nullptr);
    ~AyarEkrani();

private slots:
    void on_btnUygula_clicked();

    void on_btnKaydet_clicked();

    void uygula();

private:
    Ui::AyarEkrani *ui;
};
