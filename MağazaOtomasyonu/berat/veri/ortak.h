#pragma once

#include "qtypes.h"

#include <QDate>
#include <QString>

using CounterType = quint64;    //! Yazılımda kullanılacak sayaç veri türü
using IdType = quint64;         //! Yazılımda kullanılacak Id veri türü
using BoolType = bool;          //! Yazılımda kullanılacak Evet/Hayır veri türü
using Metin = QString;          //! Yazılımda kullanılacak metin veri türü
using DateType = QDate;         //! Yazılımda kullanılacak Tarih veri türü
using TimeType = QTime;         //! Yazılımda kullanılacak Zaman Veri Türü
using Zaman = QDateTime; //! Yazılımda kullanılacak Tarih Saat veri türü
using Para = qreal;     //! Yazılımda kullanılacak Parasal veri türü
using Miktar = qreal;       //! Yazılımda kullanılacak miktar veri türü
using Puan = qreal;

constexpr CounterType InvalidCounter = 0xFFFFFFFFFFFFFFFF; //! Geçersiz Sayaç sabiti
constexpr IdType InvalidId = 0xFFFFFFFFFFFFFFFF;           //! Geçersiz Id sabiti
constexpr Miktar InvalidAmount = 0.;    //! Geçersiz Miktar sabiti
constexpr Puan InvalidPoint = 0.;    //! Geçersiz Puan sabiti

class MagazaBilgileri;  //
class UrunKategorisi;   //
class Urunler;          //
class UrunOzellikleri;  //
class Musteri;          //
class Siparis;          //
class SiparisUrunu;     //
class UrunYorumu;       //
class ortak_veri_sinifi;//
