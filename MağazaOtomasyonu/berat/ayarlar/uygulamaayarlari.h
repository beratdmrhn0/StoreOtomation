#pragma once

#include <QObject>
#include <QSettings>

class UygulamaAyarlari : public QObject
{
    Q_OBJECT
private:
    explicit UygulamaAyarlari(QObject *parent = nullptr);

public:
    static UygulamaAyarlari &ayarlar();

    [[nodiscard]] QString tema();
    [[nodiscard]] QString temaQSS();

public slots:
    void temaAyarla(const QString &ayar);

signals:
    void temaDegisti(const QString &yeniTema);
    void temaQSSDegisti(const QString &yeniQSS);

private:
    QSettings _ayarlar;
};
