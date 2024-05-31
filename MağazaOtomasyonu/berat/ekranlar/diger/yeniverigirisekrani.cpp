#include "yeniverigirisekrani.h"
#include "ui_yeniverigirisekrani.h"

#include <QPixmap>
#include "../../ayarlar/uygulamaayarlari.h"

YeniVeriGirisEkrani::YeniVeriGirisEkrani(QWidget *parent, QWidget *ekran)
    : QDialog(parent)
    , ui(new Ui::YeniVeriGirisEkrani)
    , _veriGirisEkrani{ekran}
{
    ui->setupUi(this);

    if (_veriGirisEkrani != nullptr)
        _veriGirisEkrani->setParent(this);

    // İlk olarak ayarlı temayı yükleyelim
    setStyleSheet(UygulamaAyarlari::ayarlar().temaQSS());
    // Sonra ayar değişikliklerinde otomatik olarak değişikliği uygulayalım.
    connect(&UygulamaAyarlari::ayarlar(),
            &UygulamaAyarlari::temaQSSDegisti,
            this,
            &YeniVeriGirisEkrani::setStyleSheet);
}

YeniVeriGirisEkrani::~YeniVeriGirisEkrani()
{
    delete ui;
}

std::shared_ptr<TemelVeriSinifi> YeniVeriGirisEkrani::veriNesnesi() const
{
    return _veriNesnesi;
}

void YeniVeriGirisEkrani::ekraniYerlestir(const QPixmap &simge)
{
    ui->gelecekNesne->addWidget(_veriGirisEkrani);
    ui->lblIslemSimgesi->setPixmap(simge);

    setMinimumWidth(_veriGirisEkrani->minimumWidth() + 192);
    setMinimumHeight(_veriGirisEkrani->minimumHeight() + 10);
    setMaximumWidth(_veriGirisEkrani->maximumWidth() + 192);
    setMaximumHeight(_veriGirisEkrani->maximumHeight() + 10);

    setTabOrder(_veriGirisEkrani, ui->btnKaydet);
    setTabOrder(ui->btnKaydet, ui->btnGeriAl);
    setTabOrder(ui->btnGeriAl, ui->btnIptal);

    _veriGirisEkrani->setFocus();
}
