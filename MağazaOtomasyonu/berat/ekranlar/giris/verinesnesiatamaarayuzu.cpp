#include "verinesnesiatamaarayuzu.h"

VeriNesnesiAtamaArayuzu::VeriNesnesiAtamaArayuzu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::VeriNesnesiAtamaArayuzu)
{
    ui->setupUi(this);
}

VeriNesnesiAtamaArayuzu::~VeriNesnesiAtamaArayuzu()
{
    delete ui;
}
