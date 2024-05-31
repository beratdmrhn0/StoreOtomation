#include "ayarekrani.h"
#include "ui_ayarekrani.h"

#include "../../ayarlar/uygulamaayarlari.h"

AyarEkrani::AyarEkrani(QWidget *parent )
    : QDialog(parent)
    , ui(new Ui::AyarEkrani)
{
    ui->setupUi(this);

    // İlk olarak ayarlı temayı yükleyelim
    setStyleSheet(UygulamaAyarlari::ayarlar().temaQSS());
    // Sonra ayar değişikliklerinde otomatik olarak değişikliği uygulayalım.
    connect(&UygulamaAyarlari::ayarlar(),
            &UygulamaAyarlari::temaQSSDegisti,
            this,
            &AyarEkrani::setStyleSheet);

    QStringList temalar{"Yok",
                        "Amoled",
                        "Aqua",
                        "Konsol Stili",
                        "Koyu Elegan",
                        "Manjaro",
                        "Materyal Koyu",
                        "Ubuntu"};
    QStringList temaDegerleri{"",
                              "amoled",
                              "aqua",
                              "console_style",
                              "elegant_dark",
                              "manjaro_mix",
                              "material_dark",
                              "ubuntu"};

    for (auto i = 0; i < temalar.size(); i++) {
        auto item = new QListWidgetItem(temalar[i]);
        item->setData(Qt::UserRole, temaDegerleri[i]);
        ui->lstTemalar->addItem(item);
        if (UygulamaAyarlari::ayarlar().tema() == temaDegerleri[i]) {
            ui->lstTemalar->setCurrentItem(item);
        }
    }
}

AyarEkrani::~AyarEkrani()
{
    delete ui;
}

void AyarEkrani::on_btnUygula_clicked()
{
    uygula();
}

void AyarEkrani::on_btnKaydet_clicked()
{
    uygula();
    close();
}

void AyarEkrani::uygula()
{
    UygulamaAyarlari::ayarlar().temaAyarla(
        ui->lstTemalar->currentItem()->data(Qt::UserRole).toString());
}
