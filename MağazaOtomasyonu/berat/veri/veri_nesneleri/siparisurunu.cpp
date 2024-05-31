#include "siparisurunu.h"

SiparisUrunu::SiparisUrunu(QObject *parent)
    : TemelVeriSinifi{parent}
    , _siparis{""}
    , _urun{""}
    , _adet{InvalidAmount}
    , _birimFiyat{0.0}
{}

Metin SiparisUrunu::siparis() const
{
    return _siparis;
}

void SiparisUrunu::setSiparis(const Metin &newSiparis)
{
    if (_siparis == newSiparis)
        return;
    _siparis = newSiparis;
    emit siparisChanged(_siparis);
}

void SiparisUrunu::resetSiparis()
{
    setSiparis(""); // TODO: Adapt to use your actual default value
}

Metin SiparisUrunu::urun() const
{
    return _urun;
}

void SiparisUrunu::setUrun(const Metin &newUrun)
{
    if (_urun == newUrun)
        return;
    _urun = newUrun;
    emit urunChanged(_urun);
}

void SiparisUrunu::resetUrun()
{
    setUrun(""); // TODO: Adapt to use your actual default value
}

Miktar SiparisUrunu::adet() const
{
    return _adet;
}

void SiparisUrunu::setAdet(Miktar newAdet)
{
    if (_adet == newAdet)
        return;
    _adet = newAdet;
    emit adetChanged (_adet);
}

void SiparisUrunu::resetAdet()
{
    setAdet(InvalidAmount); // TODO: Adapt to use your actual default value
}

Para SiparisUrunu::birimFiyat() const
{
    return _birimFiyat;
}

void SiparisUrunu::setBirimFiyat(Para newBirimFiyat)
{
    if (_birimFiyat == newBirimFiyat)
        return;
    _birimFiyat = newBirimFiyat;
    emit birimFiyatChanged(_birimFiyat);
}

void SiparisUrunu::resetBirimFiyat()
{
    setBirimFiyat(0.0); // TODO: Adapt to use your actual default value
}

QDataStream &operator<<(QDataStream &stream, const SiparisUrunu &data)
{
    stream << (TemelVeriSinifi &) data << data._siparis << data._urun << data._adet << data._birimFiyat;
    return stream;
}

QDataStream &operator>>(QDataStream &stream, SiparisUrunu &data)
{
    stream >> (TemelVeriSinifi &) data >> data._siparis >> data._urun >> data._adet >> data._birimFiyat;
    return stream;
}
