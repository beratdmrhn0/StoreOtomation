#ifndef SIPARISURUNU_H
#define SIPARISURUNU_H

#include <QObject>
#include "..\ortak.h"
#include "ortak_veri_sinifi.h"

class SiparisUrunu :public TemelVeriSinifi
{
    Q_OBJECT
public:
    explicit SiparisUrunu(QObject *parent = nullptr);

    [[nodiscard]] Metin siparis() const;

    [[nodiscard]] Metin urun() const;

    [[nodiscard]] Miktar adet() const;

    [[nodiscard]] Para birimFiyat() const;

public slots:

    void setSiparis(const Metin &newSiparis);
    void resetSiparis();

    void setUrun(const Metin &newUrun);
    void resetUrun();

    void setAdet(Miktar newAdet);
    void resetAdet();

    void setBirimFiyat(Para newBirimFiyat);
    void resetBirimFiyat();

signals:
    void siparisChanged(const Metin &siparis);

    void urunChanged(const Metin &urun);

    void adetChanged(const Miktar &adet);

    void birimFiyatChanged( const Para &birimFiyat);

private:
    Metin _siparis;
    Metin _urun;
    Miktar _adet;
    Para _birimFiyat;

    Q_PROPERTY(Metin siparis READ siparis WRITE setSiparis RESET resetSiparis NOTIFY siparisChanged FINAL)
    Q_PROPERTY(Metin urun READ urun WRITE setUrun RESET resetUrun NOTIFY urunChanged FINAL)
    Q_PROPERTY(Miktar adet READ adet WRITE setAdet RESET resetAdet NOTIFY adetChanged FINAL)
    Q_PROPERTY(Para birimFiyat READ birimFiyat WRITE setBirimFiyat RESET resetBirimFiyat NOTIFY birimFiyatChanged FINAL)

    friend QDataStream &operator<<(QDataStream &stream, const SiparisUrunu &data);
    friend QDataStream &operator>>(QDataStream &stream, SiparisUrunu &data);
};

#endif // SIPARISURUNU_H
