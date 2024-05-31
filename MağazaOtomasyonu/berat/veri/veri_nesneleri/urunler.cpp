#include "urunler.h"

Urunler::Urunler(QObject *parent)
    : TemelVeriSinifi{parent}
    , _urunAdi{""}
    , _barkod{""}
    , _fiyati{0.0}
    , _aciklama{""}
{}

Metin Urunler::urunAdi() const
{
    return _urunAdi;
}

void Urunler::setUrunAdi(const Metin &newUrunAdi)
{
    if (_urunAdi == newUrunAdi)
        return;
    _urunAdi = newUrunAdi;
    emit urunAdiChanged(_urunAdi);
}

void Urunler::resetUrunAdi()
{
    setUrunAdi(""); // TODO: Adapt to use your actual default value
}

Metin Urunler::barkod() const
{
    return _barkod;
}

void Urunler::setBarkod(const Metin &newBarkod)
{
    if (_barkod == newBarkod)
        return;
    _barkod = newBarkod;
    emit barkodChanged(_barkod);
}

void Urunler::resetBarkod()
{
    setBarkod(""); // TODO: Adapt to use your actual default value
}

Para Urunler::fiyati() const
{
    return _fiyati;
}

void Urunler::setFiyati(Para newFiyati)
{
    if (_fiyati == newFiyati)
        return;
    _fiyati = newFiyati;
    emit fiyatiChanged(_fiyati);
}

void Urunler::resetFiyati()
{
    setFiyati(0.0); // TODO: Adapt to use your actual default value
}

Metin Urunler::aciklama() const
{
    return _aciklama;
}

void Urunler::setAciklama(const Metin &newAciklama)
{
    if (_aciklama == newAciklama)
        return;
    _aciklama = newAciklama;
    emit aciklamaChanged(_aciklama);
}

void Urunler::resetAciklama()
{
    setAciklama(""); // TODO: Adapt to use your actual default value
}

QDataStream &operator<<(QDataStream &stream, const Urunler &data)
{
    stream << (TemelVeriSinifi &) data << data._urunAdi << data._barkod << data._fiyati << data._aciklama;
    return stream;
}

QDataStream &operator>>(QDataStream &stream, Urunler &data)
{
    stream >> (TemelVeriSinifi &) data >> data._urunAdi >> data._barkod >> data._fiyati >> data._aciklama;
    return stream;
}
