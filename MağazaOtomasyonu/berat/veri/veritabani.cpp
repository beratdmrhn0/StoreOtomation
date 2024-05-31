#include "veritabani.h"
#include <QFile>

#include "konteynirler/magazabilgilerikonteynir.h"
#include "konteynirler/musterikonteynir.h"
#include "konteynirler/sipariskonteynir.h"
#include "konteynirler/siparisurunukonteynir.h"
#include "konteynirler/urunkategorisikonteynir.h"
#include "konteynirler/urunlerkonteynir.h"
#include "konteynirler/urunozelliklerikonteynir.h"



veritabani::veritabani(QObject *parent)
    : QObject{parent}
    , _sonDosyaYolu{""}
{}

veritabani &veritabani::vt()
{
    static veritabani nesne;
    return nesne;
}



MagazaBilgileriKonteynir &veritabani::magazaBilgileri()
{
    return _magazaBilgileri;
}
musterikonteynir &veritabani::musteri()
{
    return _musteri;
}
sipariskonteynir &veritabani::siparis()
{
    return _siparis;
}
siparisurunukonteynir &veritabani::siparisUrunu()
{
    return _siparisUrunu;
}
urunkategorisikonteynir &veritabani::urunKategorisi()
{
    return _urunKategorisi;
}
urunlerkonteynir &veritabani::urunler()
{
    return _urunler;
}
urunozelliklerikonteynir &veritabani::urunOzellikleri()
{
    return _urunOzellikleri;
}

void veritabani::yukle(const QString &dosyaYolu)
{
    if (!dosyaYolu.isEmpty()) {
        QFile dosya(dosyaYolu);
        if (dosya.open(QIODevice::ReadOnly)) {
            QDataStream stream(&dosya);
            stream >> *this;
            _sonDosyaYolu = dosyaYolu;
            dosya.close();
        }
    }
}

void veritabani::kaydet(const QString &dosyaYolu)
{
    QFile dosya;
    if (dosyaYolu.isEmpty()) {
        dosya.setFileName(_sonDosyaYolu);
    } else {
        dosya.setFileName(dosyaYolu);
    }

    if (dosya.open(QIODevice::WriteOnly)) {
        QDataStream stream(&dosya);
        stream << *this;
        if (!dosyaYolu.isEmpty()) {
            _sonDosyaYolu = dosyaYolu;
        }
        dosya.close();
    }
}

QDataStream &operator<<(QDataStream &stream, const veritabani &data)
{
    stream << data._magazaBilgileri << data._musteri << data._siparis
           << data._siparisUrunu << data._urunKategorisi << data._urunler
           << data._urunOzellikleri;
    return stream;
}
QDataStream &operator>>(QDataStream &stream, veritabani &data)
{
    stream >> data._magazaBilgileri  >> data._musteri
           >> data._siparis >> data._siparisUrunu >> data._urunKategorisi
           >> data._urunler >>data._urunOzellikleri;
    return stream;
}
