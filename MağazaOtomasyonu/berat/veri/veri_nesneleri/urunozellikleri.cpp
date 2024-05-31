#include "urunozellikleri.h"

UrunOzellikleri::UrunOzellikleri(QObject *parent)
    : TemelVeriSinifi{parent}
    , _urun{""}
    , _ozellikler{""}
    , _deger{0.0}
{}

Metin UrunOzellikleri::urun() const
{
    return _urun;
}

void UrunOzellikleri::setUrun(const Metin &newUrun)
{
    if (_urun == newUrun)
        return;
    _urun = newUrun;
    emit urunChanged(_urun);
}

void UrunOzellikleri::resetUrun()
{
    setUrun({}); // TODO: Adapt to use your actual default value
}

Metin UrunOzellikleri::ozellikler() const
{
    return _ozellikler;
}

void UrunOzellikleri::setOzellikler(const Metin &newOzellikler)
{
    if (_ozellikler == newOzellikler)
        return;
    _ozellikler = newOzellikler;
    emit ozelliklerChanged(_ozellikler);
}

void UrunOzellikleri::resetOzellikler()
{
    setOzellikler(""); // TODO: Adapt to use your actual default value
}

Para UrunOzellikleri::deger() const
{
    return _deger;
}

void UrunOzellikleri::setDeger(Para newDeger)
{
    if (_deger == newDeger)
        return;
    _deger = newDeger;
    emit degerChanged(_deger);
}

void UrunOzellikleri::resetDeger()
{
    setDeger(0.0); // TODO: Adapt to use your actual default value
}


QDataStream &operator<<(QDataStream &stream, const UrunOzellikleri &data)
{
    stream << (TemelVeriSinifi &) data << data._urun << data._deger << data._ozellikler ;
    return stream;
}

QDataStream &operator>>(QDataStream &stream, UrunOzellikleri &data)
{
    stream >> (TemelVeriSinifi &) data >> data._urun >> data._deger >> data._ozellikler ;
    return stream;
}
