#pragma once

#include "konteynir.h"

#include "ortak.h"

#define VERI(V) \
using V ## KonteynirType = Konteynir<V>; \
using V ## Ptr = V ## KonteynirType::Ptr; \
using V ## Vektor = V ## KonteynirType::Vektor; \
using V ## Fonksiyon = V ## KonteynirType::Fonksiyon; \
using V ## ZatenVar = V ## KonteynirType::ZatenVarHatasi; \
using V ## Bulunamadi = V ## KonteynirType::KayitBulunamadiHatasi;


VERI(MagazaBilgileri)
VERI(Siparis)
VERI(SiparisUrunu)
VERI(Urunler)
VERI(Musteri)
VERI(UrunYorumu)
VERI(UrunOzellikleri)
VERI(Urunler)
VERI(UrunKategorisi)
