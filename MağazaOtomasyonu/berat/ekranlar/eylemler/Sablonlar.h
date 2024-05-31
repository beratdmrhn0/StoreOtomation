#pragma once

#include <tuple>

#include "../ekranlar/giris/veriekraneslesmesi"
#include "../veri/veritabani.h"
#include "../ekranlar/diger/yeniverigirisekrani.h"
#include "qaction.h"

using Action = QAction;
using ActionPtr = Action *;
using CategoryType = QString;
using PanelType = QString;
using ActInfoType = std::tuple<CategoryType, PanelType, ActionPtr>;

template<VeriTuru V>
struct GCEylemi
{
    using Veri = V;
    using VeriPtr = std::shared_ptr<Veri>;
    using Ekran = Ekran<V>::EkranType;
    using EkranPtr = Ekran *;

    static ActInfoType veriGirisEylemi(QObject *parent = nullptr)
    {
        return std::make_tuple(QString(""), QString(""), nullptr);
    }
};

template<>
struct GCEylemi<MagazaBilgileri>
{
    static ActInfoType veriGirisEylemi(QObject *parent = nullptr)
    {
        QAction *action = new QAction();
        action->setText(QObject::tr("Yeni Manav Girişi"));
        action->setIcon(QPixmap::fromImage(QImage(Ekran<MagazaBilgileri>::yeniSimge)));
        QObject::connect(action, &QAction::triggered, [](bool checked) {
            auto veri = VeriTabani::vt().magaza().yeni_yer_olustur();
            auto yeniVeriGirisEkrani = YeniVeriGirisEkrani();

            yeniVeriGirisEkrani.setVeriNesnesi(veri);

            auto sonuc = yeniVeriGirisEkrani.exec();

            if (sonuc == QDialog::Accepted)
            {
                VeriTabani::vt().manav().ekle(veri);
            }
        });
        action->setShortcut(QKeySequence("Ctrl+G,M"));
        return std::make_tuple(QObject::tr("Manav İşlemleri"), QObject::tr("Veri Girişi"), action);
    }
};
