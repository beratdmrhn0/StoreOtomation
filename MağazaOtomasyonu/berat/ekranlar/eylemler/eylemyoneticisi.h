#pragma once

#include <QAction>
#include <QObject>

class SARibbonBar;

class EylemYoneticisi : public QObject
{
    Q_OBJECT
private:
    explicit EylemYoneticisi(QObject *parent = nullptr);

    void eylemleriHazirla();

public:
    using SelfType = EylemYoneticisi;

    using KategoriType = QString;
    using PanelType = QString;
    using EylemType = QAction *;

    using EylemMetaBilgi = std::tuple<KategoriType, PanelType, EylemType>;
    using Eylemler = std::vector<EylemMetaBilgi>;

    static SelfType &yonetici();

    void ribbonAyarla(SARibbonBar *ribbon);
signals:

private:
    Eylemler _eylemler;
};
