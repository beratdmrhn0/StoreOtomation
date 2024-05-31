#pragma once

#include <QMainWindow>
#include "ekranlar/bilesenler/SARibbon.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MagazaMain;
}
QT_END_NAMESPACE

class MagazaMain : public SARibbonMainWindow
{
    Q_OBJECT

public:
    MagazaMain(QWidget *parent = nullptr);
    ~MagazaMain();

private slots:

private:
    Ui::MagazaMain *ui;
};
