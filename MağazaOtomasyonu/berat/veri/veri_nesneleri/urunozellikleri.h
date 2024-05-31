#ifndef URUNOZELLIKLERI_H
#define URUNOZELLIKLERI_H

#include <QObject>
#include "..\ortak.h"
#include "ortak_veri_sinifi.h"

class UrunOzellikleri : TemelVeriSinifi
{
    Q_OBJECT
public:
    explicit UrunOzellikleri(QObject *parent = nullptr);

    [[nodiscard]] Metin urun() const;

    [[nodiscard]] Metin ozellikler() const;

    [[nodiscard]] Para deger() const;

public slots:
    void setUrun(const Metin &newUrun);
    void resetUrun();

    void setOzellikler(const Metin &newOzellikler);
    void resetOzellikler();

    void setDeger(Para newDeger);
    void resetDeger();

signals:
    void urunChanged(const Metin &urun);

    void ozelliklerChanged(const Metin &ozellikleri);

    void degerChanged(const Para &deger);

private:
    Metin _urun;
    Metin _ozellikler;
    Para _deger;
    Q_PROPERTY(Metin urun READ urun WRITE setUrun RESET resetUrun NOTIFY urunChanged FINAL)
    Q_PROPERTY(Metin ozellikler READ ozellikler WRITE setOzellikler RESET resetOzellikler NOTIFY ozelliklerChanged FINAL)
    Q_PROPERTY(Para deger READ deger WRITE setDeger RESET resetDeger NOTIFY degerChanged FINAL)

    friend QDataStream &operator<<(QDataStream &stream, const UrunOzellikleri &data);
    friend QDataStream &operator>>(QDataStream &stream, UrunOzellikleri &data);
};

#endif // URUNOZELLIKLERI_H
