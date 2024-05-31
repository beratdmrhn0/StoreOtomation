#pragma once

#include <QDialog>

#include "../giris/veriekraneslesmesi.h"

namespace Ui {
class YeniVeriGirisEkrani;
}

class YeniVeriGirisEkrani : public QDialog
{
    Q_OBJECT

public:
    explicit YeniVeriGirisEkrani(QWidget *parent = nullptr, QWidget *ekran = nullptr);
    ~YeniVeriGirisEkrani();

    [[nodiscard]] std::shared_ptr<TemelVeriSinifi> veriNesnesi() const;

    template<VeriTuru T>
    void setVeriNesnesi(const std::shared_ptr<T> &newVeriNesnesi)
    {
        auto ataNesne = dynamic_pointer_cast<TemelVeriSinifi>(newVeriNesnesi);
        if (_veriNesnesi == ataNesne)
            return;
        _veriNesnesi = ataNesne;

        _veriNesnesi->geriYuklemeNoktasiOlustur();

        emit veriNesnesiDegisti(_veriNesnesi);

        _veriGirisEkrani = veriEkrani(newVeriNesnesi, this);

        ekraniYerlestir(Esleme<T>::yeniIcinGoruntu());
    }

public slots:
    void ekraniYerlestir(const QPixmap &simge);

signals:
    void veriNesnesiDegisti(std::shared_ptr<TemelVeriSinifi> veriNesnesi);

private:
    Ui::YeniVeriGirisEkrani *ui;

    QWidget *_veriGirisEkrani;
    std::shared_ptr<TemelVeriSinifi> _veriNesnesi;

    Q_PROPERTY(std::shared_ptr<TemelVeriSinifi> veriNesnesi READ veriNesnesi NOTIFY
                   veriNesnesiDegisti FINAL)
};
