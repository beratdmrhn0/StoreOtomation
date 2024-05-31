#include "urunkategorisi.h"

UrunKategorisi::UrunKategorisi(QObject *parent)
    : TemelVeriSinifi{parent}
    , _kategori{""}
{}

Metin UrunKategorisi::kategori() const
{
    return _kategori;
}

void UrunKategorisi::setKategori(const Metin &newKategori)
{
    if (_kategori == newKategori)
        return;
    _kategori = newKategori;
    emit kategoriChanged(_kategori);
}

void UrunKategorisi::resetKategori()
{
    setKategori(""); // TODO: Adapt to use your actual default value
}

QDataStream &operator<<(QDataStream &stream, const UrunKategorisi &data)
{
    stream << (TemelVeriSinifi &) data << data._kategori;
    return stream;
}

QDataStream &operator>>(QDataStream &stream, UrunKategorisi &data)
{
    stream >> (TemelVeriSinifi &) data >> data._kategori;
    return stream;
}
