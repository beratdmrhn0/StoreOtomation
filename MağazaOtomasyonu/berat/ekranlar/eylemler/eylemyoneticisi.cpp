#include "eylemyoneticisi.h"

#include "sablonlar.h"

#include "../ekranlar/bilesenler/SARibbon.h"

EylemYoneticisi::EylemYoneticisi(QObject *parent)
    : QObject{parent}
{
    eylemleriHazirla();
}

void EylemYoneticisi::eylemleriHazirla()
{
    _eylemler.push_back(GCEylemi<MagazaBilgileri>::veriGirisEylemi(this));
}

EylemYoneticisi::SelfType &EylemYoneticisi::yonetici()
{
    static SelfType nesne;
    return nesne;
}

void EylemYoneticisi::ribbonAyarla(SARibbonBar* ribbon) {
    QString lastCategoryTitle;
    QString lastPanelTitle;

    SARibbonCategory *lastCat = nullptr;
    SARibbonPannel *lastPannel = nullptr;

    for (auto& [catTitle, panelTitle, action] : _eylemler) {
        if(catTitle != lastCategoryTitle) {
            lastCat = ribbon->addCategoryPage(catTitle);
            lastCategoryTitle = catTitle;
        }
        if (panelTitle != lastPanelTitle) {
            lastPannel = lastCat->addPannel(panelTitle);
            lastPanelTitle = panelTitle;
        }
        lastPannel->addAction(action);
    }

    ribbon->applicationButton()->setText(tr("Dosya"));
}
