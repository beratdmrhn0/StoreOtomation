#ifndef SIPARIS_H
#define SIPARIS_H

#include <QObject>
#include "..\ortak.h"
#include "ortak_veri_sinifi.h"

class Siparis : public TemelVeriSinifi
{
    Q_OBJECT
public:
    explicit Siparis(QObject *parent = nullptr);
    [[nodiscard]] Zaman tarih() const;
    [[nodiscard]] Metin firma() const;

public slots:
    void setTarih(const Zaman &newTarih);
    void resetTarih();
    void setFirma(const Metin &newFirma);
    void resetFirma();

signals:
    void tarihChanged(const Zaman &tarih);

    void firmaChanged(const Metin &firma);

private:
    Zaman _tarih;
    Metin _firma;

    Q_PROPERTY(Zaman tarih READ tarih WRITE setTarih RESET resetTarih NOTIFY tarihChanged FINAL)
    Q_PROPERTY(Metin firma READ firma WRITE setFirma RESET resetFirma NOTIFY firmaChanged FINAL)

    friend QDataStream &operator<<(QDataStream &stream, const Siparis &data);
    friend QDataStream &operator>>(QDataStream &stream, Siparis &data);
};

#endif // SIPARIS_H
