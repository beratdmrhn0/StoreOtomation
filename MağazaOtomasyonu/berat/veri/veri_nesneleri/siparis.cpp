#include "siparis.h"

Siparis::Siparis(QObject *parent)
    : TemelVeriSinifi{parent}
    , _tarih{QDateTime::currentDateTime()}
    , _firma{""}
{}

Zaman Siparis::tarih() const
{
    return _tarih;
}

void Siparis::setTarih(const Zaman &newTarih)
{
    if (_tarih == newTarih)
        return;
    _tarih = newTarih;
    emit tarihChanged(_tarih);
}

void Siparis::resetTarih()
{
    setTarih(QDateTime::currentDateTime()); // TODO: Adapt to use your actual default value
}

Metin Siparis::firma() const
{
    return _firma;
}

void Siparis::setFirma(const Metin &newFirma)
{
    if (_firma == newFirma)
        return;
    _firma = newFirma;
    emit firmaChanged(_firma);
}

void Siparis::resetFirma()
{
    setFirma(""); // TODO: Adapt to use your actual default value
}

QDataStream &operator<<(QDataStream &stream, const Siparis &data)
{
    stream << (TemelVeriSinifi &) data << data._tarih << data._firma;
    return stream;
}

QDataStream &operator>>(QDataStream &stream, Siparis &data)
{
    stream >> (TemelVeriSinifi &) data >> data._tarih >> data._firma;
    return stream;
}
