#include "uygulamaayarlari.h"

#include <QFile>

UygulamaAyarlari::UygulamaAyarlari(QObject *parent)
    : QObject{parent}
{}

UygulamaAyarlari &UygulamaAyarlari::ayarlar()
{
    static UygulamaAyarlari nesne;
    return nesne;
}

QString UygulamaAyarlari::tema()
{
    return _ayarlar.value("Gorunus/Tema", "").toString();
}

QString UygulamaAyarlari::temaQSS()
{
    if (this->tema().isEmpty()) {
        return "";
    }
    QFile f(tr(":/qss/%1.qss").arg(tema()));

    if (f.open(QIODevice::ReadOnly)) {
        QTextStream str(&f);
        QString result = str.readAll();
        f.close();
        return result;
    }
    return "";
}

void UygulamaAyarlari::temaAyarla(const QString &ayar)
{
    if (tema() == ayar) {
        return;
    }
    _ayarlar.setValue("Gorunus/Tema", ayar);
    emit temaDegisti(ayar);
    emit temaQSSDegisti(temaQSS());
}
