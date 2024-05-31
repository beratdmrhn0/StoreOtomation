#ifndef URUNYORUMU_H
#define URUNYORUMU_H

#include <QObject>
#include "..\ortak.h"
#include "ortak_veri_sinifi.h"

class UrunYorumu :public TemelVeriSinifi
{
    Q_OBJECT
public:
    explicit UrunYorumu(QObject *parent = nullptr);

    Metin siparis() const;


    Metin urunAdi() const;

    Metin yorum() const;

    Puan puan() const;


    Metin kullaniciAdi() const;

public slots:
    void setSiparis(const Metin &newSiparis);
    void resetSiparis();

    void setUrunAdi(const Metin &newUrunAdi);
    void resetUrunAdi();

    void setYorum(const Metin &newYorum);
    void resetYorum();

    void setPuan(Puan newPuan);
    void resetPuan();

    void setKullaniciAdi(const Metin &newKullaniciAdi);
    void resetKullaniciAdi();

signals:
    void siparisChanged(const Metin &siparis);

    void urunAdiChanged(const Metin urunAdi);

    void yorumChanged(const Metin &yorum);

    void puanChanged(Puan puan);

    void kullaniciAdiChanged(const Metin &kullaniciAdi);

private:
    Metin _siparis;
    Metin _urunAdi;
    Metin _yorum;
    Puan _puan;
    Metin _kullaniciAdi;

    Q_PROPERTY(Metin siparis READ siparis WRITE setSiparis RESET resetSiparis NOTIFY siparisChanged FINAL)
    Q_PROPERTY(Metin urunAdi READ urunAdi WRITE setUrunAdi RESET resetUrunAdi NOTIFY urunAdiChanged FINAL)
    Q_PROPERTY(Metin yorum READ yorum WRITE setYorum RESET resetYorum NOTIFY yorumChanged FINAL)
    Q_PROPERTY(Puan puan READ puan WRITE setPuan RESET resetPuan NOTIFY puanChanged FINAL)
    Q_PROPERTY(Metin kullaniciAdi READ kullaniciAdi WRITE setKullaniciAdi RESET resetKullaniciAdi NOTIFY kullaniciAdiChanged FINAL)

    friend QDataStream &operator<<(QDataStream &stream, const UrunYorumu &data);
    friend QDataStream &operator>>(QDataStream &stream, UrunYorumu &data);
};

#endif // URUNYORUMU_H
