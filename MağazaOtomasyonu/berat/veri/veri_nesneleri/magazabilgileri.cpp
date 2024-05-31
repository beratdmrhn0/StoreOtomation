#include "magazabilgileri.h"

MagazaBilgileri::MagazaBilgileri(QObject *parent)
    : TemelVeriSinifi{parent}
    , _yetkiliKisi{""}
    , _adresi{""}
    , _telefon{""}
{}


Metin MagazaBilgileri::yetkiliKisi() const
{
    return _yetkiliKisi;
}

void MagazaBilgileri::setYetkiliKisi(const Metin &newYetkiliKisi)
{
    if (_yetkiliKisi == newYetkiliKisi)
        return;
    _yetkiliKisi = newYetkiliKisi;
    emit yetkiliKisiChanged(_yetkiliKisi);
}

void MagazaBilgileri::resetYetkiliKisi()
{
    setYetkiliKisi(""); // TODO: Adapt to use your actual default value
}

Metin MagazaBilgileri::adresi() const
{
    return _adresi;
}

void MagazaBilgileri::setAdresi(const Metin &newAdresi)
{
    if (_adresi == newAdresi)
        return;
    _adresi = newAdresi;
    emit adresiChanged(_adresi);
}

void MagazaBilgileri::resetAdresi()
{
    setAdresi(""); // TODO: Adapt to use your actual default value
}

Metin MagazaBilgileri::telefon() const
{
    return _telefon;
}

void MagazaBilgileri::setTelefon(const Metin &newTelefon)
{
    if (_telefon == newTelefon)
        return;
    _telefon = newTelefon;
    emit telefonChanged(_telefon);
}

void MagazaBilgileri::resetTelefon()
{
    setTelefon(""); // TODO: Adapt to use your actual default value
}
QDataStream &operator<<(QDataStream &stream, const MagazaBilgileri &data)
{
    stream << (TemelVeriSinifi &) data << data._yetkiliKisi << data._adresi << data._telefon;
    return stream;
}

QDataStream &operator>>(QDataStream &stream, MagazaBilgileri &data)
{
    stream >> (TemelVeriSinifi &) data >> data._yetkiliKisi << data._adresi << data._telefon;
    return stream;
}
