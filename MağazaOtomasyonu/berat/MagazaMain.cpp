#include "MagazaMain.h"
#include "./ui_MagazaMain.h"

#include "ayarlar/uygulamaayarlari.h"

#include "eylemler/eylemyoneticisi.h"

MagazaMain::MagazaMain(QWidget *parent)
    : SARibbonMainWindow(parent)
    , ui(new Ui::MagazaMain)
{
    ui->setupUi(this);
    // İlk olarak ayarlı temayı yükleyelim
    setStyleSheet(UygulamaAyarlari::ayarlar().temaQSS());

    setRibbonTheme(RibbonThemeWindows7);

    EylemYoneticisi::yonetici().ribbonAyarla(ribbonBar());

    // Sonra ayar değişikliklerinde otomatik olarak değişikliği uygulayalım.
    connect(&UygulamaAyarlari::ayarlar(),
            &UygulamaAyarlari::temaQSSDegisti,
            this,
            &MagazaMain::setStyleSheet);
}

MagazaMain::~MagazaMain()
{
    delete ui;
}


/*

#include "manavmain.h"
#include "./ui_manavmain.h"

#include "ayarlar/uygulamaayarlari.h"

#include "eylemler/eylemyoneticisi.h"

ManavMain::ManavMain(QWidget *parent)
    : SARibbonMainWindow(parent)
    , ui(new Ui::ManavMain)
{
    ui->setupUi(this);
    // İlk olarak ayarlı temayı yükleyelim
    setStyleSheet(UygulamaAyarlari::ayarlar().temaQSS());

    setRibbonTheme(RibbonThemeWindows7);

    EylemYoneticisi::yonetici().ribbonAyarla(ribbonBar());

    // Sonra ayar değişikliklerinde otomatik olarak değişikliği uygulayalım.
    connect(&UygulamaAyarlari::ayarlar(),
            &UygulamaAyarlari::temaQSSDegisti,
            this,
            &ManavMain::setStyleSheet);
}

ManavMain::~ManavMain()
{
    delete ui;
}


*/
