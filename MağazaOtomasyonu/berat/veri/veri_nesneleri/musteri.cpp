#include "musteri.h"

Musteri::Musteri(QObject *parent)
    : TemelVeriSinifi{parent}
    , _adi{""}
    , _soyadi{""}
    , _adresi{""}
{}

Metin Musteri::adi() const
{
    return _adi;
}

void Musteri::setAdi(const Metin &newAdi)
{
    if (_adi == newAdi)
        return;
    _adi = newAdi;
    emit adiChanged(_adi);
}

void Musteri::resetAdi()
{
    setAdi(""); // TODO: Adapt to use your actual default value
}

Metin Musteri::soyadi() const
{
    return _soyadi;
}

void Musteri::setSoyadi(const Metin &newSoyadi)
{
    if (_soyadi == newSoyadi)
        return;
    _soyadi = newSoyadi;
    emit soyadiChanged(_soyadi);
}

void Musteri::resetSoyadi()
{
    setSoyadi(""); // TODO: Adapt to use your actual default value
}

Metin Musteri::adresi() const
{
    return _adresi;
}

void Musteri::setAdresi(const Metin &newAdresi)
{
    if (_adresi == newAdresi)
        return;
    _adresi = newAdresi;
    emit adresiChanged(_adresi);
}

void Musteri::resetAdresi()
{
    setAdresi(""); // TODO: Adapt to use your actual default value
}

QDataStream &operator<<(QDataStream &stream, const Musteri &data)
{
    stream << (TemelVeriSinifi &) data << data._adi << data._soyadi << data._adresi;
    return stream;
}

QDataStream &operator>>(QDataStream &stream, Musteri &data)
{
    stream >> (TemelVeriSinifi &) data >> data._adi >> data._soyadi >> data._adresi;
    return stream;
}
