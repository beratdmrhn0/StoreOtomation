#include "urunyorumu.h"

UrunYorumu::UrunYorumu(QObject *parent)
    : TemelVeriSinifi{parent}
    , _siparis{""}
    , _urunAdi{""}
    , _yorum{""}
    , _puan{InvalidPoint}
{}

Metin UrunYorumu::siparis() const
{
    return _siparis;
}

void UrunYorumu::setSiparis(const Metin &newSiparis)
{
    if (_siparis == newSiparis)
        return;
    _siparis = newSiparis;
    emit siparisChanged(_siparis);
}

void UrunYorumu::resetSiparis()
{
    setSiparis(""); // TODO: Adapt to use your actual default value
}

Metin UrunYorumu::urunAdi() const
{
    return _urunAdi;
}

void UrunYorumu::setUrunAdi(const Metin &newUrunAdi)
{
    if (_urunAdi == newUrunAdi)
        return;
    _urunAdi = newUrunAdi;
    emit urunAdiChanged(_urunAdi);
}

void UrunYorumu::resetUrunAdi()
{
    setUrunAdi(""); // TODO: Adapt to use your actual default value
}

Metin UrunYorumu::yorum() const
{
    return _yorum;
}

void UrunYorumu::setYorum(const Metin &newYorum)
{
    if (_yorum == newYorum)
        return;
    _yorum = newYorum;
    emit yorumChanged(_yorum);
}

void UrunYorumu::resetYorum()
{
    setYorum(""); // TODO: Adapt to use your actual default value
}

Puan UrunYorumu::puan() const
{
    return _puan;
}

void UrunYorumu::setPuan(Puan newPuan)
{
    if (_puan == newPuan)
        return;
    _puan = newPuan;
    emit puanChanged(_puan);
}

void UrunYorumu::resetPuan()
{
    setPuan(InvalidPoint); // TODO: Adapt to use your actual default value
}

Metin UrunYorumu::kullaniciAdi() const
{
    return _kullaniciAdi;
}

void UrunYorumu::setKullaniciAdi(const Metin &newKullaniciAdi)
{
    if (_kullaniciAdi == newKullaniciAdi)
        return;
    _kullaniciAdi = newKullaniciAdi;
    emit kullaniciAdiChanged(_kullaniciAdi);
}

void UrunYorumu::resetKullaniciAdi()
{
    setKullaniciAdi(""); // TODO: Adapt to use your actual default value
}


QDataStream &operator<<(QDataStream &stream, const UrunYorumu &data)
{
    stream << (TemelVeriSinifi &) data << data._urunAdi << data._kullaniciAdi << data._puan << data._siparis << data._yorum;
    return stream;
}

QDataStream &operator>>(QDataStream &stream, UrunYorumu &data)
{
    stream >> (TemelVeriSinifi &) data >> data._urunAdi >> data._kullaniciAdi >> data._puan >> data._siparis >> data._yorum;
    return stream;
}
