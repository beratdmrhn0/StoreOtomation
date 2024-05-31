#ifndef MUSTERI_H
#define MUSTERI_H

#include <QObject>
#include "..\ortak.h"
#include "ortak_veri_sinifi.h"

class Musteri : TemelVeriSinifi
{
    Q_OBJECT
public:
    explicit Musteri(QObject *parent = nullptr);

    [[nodiscard]] Metin adi() const;
    [[nodiscard]] Metin soyadi() const;
    [[nodiscard]] Metin adresi() const;

public slots:

    void setAdi(const Metin &newAdi);
    void resetAdi();

    void setSoyadi(const Metin &newSoyadi);
    void resetSoyadi();

    void setAdresi(const Metin &newAdresi);
    void resetAdresi();


signals:
    void adiChanged(const Metin &adi);

    void soyadiChanged(const Metin &soyadi);

    void adresiChanged(const Metin &adresi);

private:
    Metin _adi;
    Metin _soyadi;
    Metin _adresi;

    Q_PROPERTY(Metin adi READ adi WRITE setAdi RESET resetAdi NOTIFY adiChanged FINAL)
    Q_PROPERTY(Metin soyadi READ soyadi WRITE setSoyadi RESET resetSoyadi NOTIFY soyadiChanged FINAL)
    Q_PROPERTY(Metin adresi READ adresi WRITE setAdresi RESET resetAdresi NOTIFY adresiChanged FINAL)

    friend QDataStream &operator<<(QDataStream &stream, const Musteri &data);
    friend QDataStream &operator>>(QDataStream &stream,  Musteri &data);
};

#endif // MUSTERI_H
