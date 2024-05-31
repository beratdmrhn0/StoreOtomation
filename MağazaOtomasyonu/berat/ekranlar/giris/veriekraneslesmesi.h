#pragma once

#include <QWidget>

#include <QDebug>

#include "VeriNesnesiAtamaArayuzu.h"

template<class Veri>
concept VeriTuru = std::is_base_of<TemelVeriSinifi, Veri>::value;

template<VeriTuru V>
struct Ekran
{
    using EkranType = std::nullptr_t;
    using EPtr = EkranType *;

    static constexpr char const *yeniSimge = nullptr;
    static constexpr char const *duzenlemeSimge = nullptr;
};

template<VeriTuru V>
struct Esleme
{
    using VeriType = V;
    using VPtr = std::shared_ptr<V>;

    static Ekran<V>::EPtr yeniEkran(const VPtr &veri, QWidget *parent = nullptr)
    {
        auto result = new Ekran<V>::EkranType{parent};
        auto ptr = dynamic_cast<VeriNesnesiAtamaArayuzu *>(result);
        ptr->setVeriNesnesi(veri);
        return result;
    }

    static QPixmap yeniIcinGoruntu() { return QPixmap{Ekran<V>::yeniSimge}; }

    static QPixmap duzenlemeIcinGoruntu() { return QPixmap{Ekran<V>::duzenlemeSimge}; }
};

template<VeriTuru V>
QWidget *veriEkrani(const std::shared_ptr<V> &veri, QWidget *parent = nullptr)
{
    return Esleme<V>::yeniEkran(veri, parent);
}

// Eşlemeler

#include "../../veri/veri_nesneleri/magazabilgileri.h"
#include "mgzekran.h"

template<>
struct Ekran<MagazaBilgileri>
{
    using EkranType = MgzEkran;
    using EPtr = EkranType *;

    static constexpr char const *yeniSimge = ":/simgeler/veri/mgz_ekle.png";
    static constexpr char const *duzenlemeSimge = ":/simgeler/veri/mgz_duzenle.png";
};
