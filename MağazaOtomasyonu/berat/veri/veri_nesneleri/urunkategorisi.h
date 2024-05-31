#ifndef URUNKATEGORISI_H
#define URUNKATEGORISI_H

#include <QObject>
#include "..\ortak.h"
#include "ortak_veri_sinifi.h"

class UrunKategorisi :public TemelVeriSinifi
{
    Q_OBJECT
public:
    explicit UrunKategorisi(QObject *parent = nullptr);

    Metin kategori() const;

public slots:
    void setKategori(const Metin &newKategori);
    void resetKategori();
signals:
    void kategoriChanged(const Metin &kategori);

private:
    Metin _kategori;
    Q_PROPERTY(Metin kategori READ kategori WRITE setKategori RESET resetKategori NOTIFY kategoriChanged FINAL)

    friend QDataStream &operator<<(QDataStream &stream, const UrunKategorisi &data);
    friend QDataStream &operator>>(QDataStream &stream, UrunKategorisi &data);
};

#endif // URUNKATEGORISI_H
