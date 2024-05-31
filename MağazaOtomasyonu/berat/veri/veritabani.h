#ifndef VERITABANI_H
#define VERITABANI_H

#include <QObject>

#include "konteynirler/magazabilgilerikonteynir.h"
#include "konteynirler/musterikonteynir.h"
#include "konteynirler/sipariskonteynir.h"
#include "konteynirler/siparisurunukonteynir.h"
#include "konteynirler/urunkategorisikonteynir.h"
#include "konteynirler/urunlerkonteynir.h"
#include "konteynirler/urunozelliklerikonteynir.h"

class veritabani :public QObject
{
    Q_OBJECT
private:
    explicit veritabani(QObject *parent = nullptr);

public:
    static veritabani &vt();

    MagazaBilgileriKonteynir &magazaBilgileri();
    musterikonteynir &musteri();
    sipariskonteynir &siparis();
    siparisurunukonteynir &siparisUrunu();
    urunkategorisikonteynir &urunKategorisi();
    urunlerkonteynir &urunler();
    urunozelliklerikonteynir &urunOzellikleri();

public slots:
    void yukle(const QString &dosyaYolu);
    void kaydet(const QString &dosyaYolu = "");

signals:

private:

    MagazaBilgileriKonteynir _magazaBilgileri;
    musterikonteynir _musteri;
    sipariskonteynir _siparis;
    siparisurunukonteynir _siparisUrunu;
    urunkategorisikonteynir _urunKategorisi;
    urunlerkonteynir _urunler;
    urunozelliklerikonteynir _urunOzellikleri;

    QString _sonDosyaYolu;

    friend QDataStream &operator<<(QDataStream &stream, const veritabani &data);
    friend QDataStream &operator>>(QDataStream &stream, veritabani &data);

};

#endif // VERITABANI_H




