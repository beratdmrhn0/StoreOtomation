#ifndef URUNLER_H
#define URUNLER_H

#include <QObject>
#include "..\ortak.h"
#include "ortak_veri_sinifi.h"


class Urunler : public TemelVeriSinifi
{
    Q_OBJECT
public:
    explicit Urunler(QObject *parent = nullptr);

    [[nodiscard]] Metin urunAdi() const;

    [[nodiscard]] Metin barkod() const;

    [[nodiscard]] Para fiyati() const;

    [[nodiscard]] Metin aciklama() const;


public slots:

    void setUrunAdi(const Metin &newUrunAdi);
    void resetUrunAdi();

    void setBarkod(const Metin &newBarkod);
    void resetBarkod();

    void setFiyati(Para newFiyati);
    void resetFiyati();

    void setAciklama(const Metin &newAciklama);
    void resetAciklama();

signals:
    void urunAdiChanged(const Metin &urunAdi);

    void barkodChanged(const Metin &barkod);

    void fiyatiChanged(const Para &fiyati);

    void aciklamaChanged(const Metin &aciklama);

private:
    Metin _urunAdi;
    Metin _barkod;
    Para _fiyati;
    Metin _aciklama;

    Q_PROPERTY(Metin urunAdi READ urunAdi WRITE setUrunAdi RESET resetUrunAdi NOTIFY urunAdiChanged FINAL)
    Q_PROPERTY(Metin barkod READ barkod WRITE setBarkod RESET resetBarkod NOTIFY barkodChanged FINAL)
    Q_PROPERTY(Para fiyati READ fiyati WRITE setFiyati RESET resetFiyati NOTIFY fiyatiChanged FINAL)
    Q_PROPERTY(Metin aciklama READ aciklama WRITE setAciklama RESET resetAciklama NOTIFY aciklamaChanged FINAL)

    friend QDataStream &operator<<(QDataStream &stream, const Urunler &data);
    friend QDataStream &operator>>(QDataStream &stream, Urunler &data);
};

#endif // URUNLER_H
