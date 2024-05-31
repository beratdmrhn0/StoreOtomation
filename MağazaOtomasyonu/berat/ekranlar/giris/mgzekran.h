#pragma once

#include <QWidget>

#include "VeriNesnesiAtamaArayuzu.h"

#include "../../veri/konteynirler.h"

#include "../../veri/veri_nesneleri/magazabilgileri.h".h"

namespace Ui {
class MgzEkran;
}

class MgzEkran : public QWidget, public VeriNesnesiAtamaArayuzu
{
    Q_OBJECT

public:
    explicit MgzEkran(QWidget *parent = nullptr);
    ~MgzEkran();

    [[nodiscard]] MagazaBilgileriPtr magaza() const;

public slots:
    void setManav(const MagazaBilgileriPtr &newmagaza);

    void adresDegisiminiHallet();

signals:
    void manavDegisti(MagazaBilgileriPtr manav);
    void adresDegisti(const QString &adres);

private:
    Ui::MgzEkran *ui;

    MagazaBilgileriPtr _manav;

    Q_PROPERTY(MagazaBilgileriPtr manav READ manav WRITE setManav NOTIFY manavDegisti FINAL)

    // VeriNesnesiAtamaArayuzu interface
public:
    void setVeriNesnesi(const std::shared_ptr<TemelVeriSinifi> &veri);
};
