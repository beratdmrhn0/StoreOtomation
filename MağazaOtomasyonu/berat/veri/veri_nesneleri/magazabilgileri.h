#ifndef MAGAZABILGILERI_H
#define MAGAZABILGILERI_H

#include <QObject>

#include "..\ortak.h"
#include "ortak_veri_sinifi.h"

class MagazaBilgileri : public TemelVeriSinifi
{
    Q_OBJECT
public:
    explicit MagazaBilgileri(QObject *parent = nullptr);

    [[nodiscard]] Metin yetkiliKisi() const;


    [[nodiscard]] Metin adresi() const;


    [[nodiscard]] Metin telefon() const;


public slots:
    void setYetkiliKisi(const Metin &newYetkiliKisi);
    void resetYetkiliKisi();
    void setAdresi(const Metin &newAdresi);
    void resetAdresi();
    void setTelefon(const Metin &newTelefon);
    void resetTelefon();

signals:


    void yetkiliKisiChanged(const Metin &yetkiliKisi);

    void adresiChanged(const Metin &adresi);

    void telefonChanged(const Metin &telefon);

private:
    Metin _yetkiliKisi;
    Metin _adresi;
    Metin _telefon;

    Q_PROPERTY(Metin yetkiliKisi READ yetkiliKisi WRITE setYetkiliKisi RESET resetYetkiliKisi NOTIFY yetkiliKisiChanged FINAL)
    Q_PROPERTY(Metin adresi READ adresi WRITE setAdresi RESET resetAdresi NOTIFY adresiChanged FINAL)
    Q_PROPERTY(Metin telefon READ telefon WRITE setTelefon RESET resetTelefon NOTIFY telefonChanged FINAL)

    friend QDataStream &operator<<(QDataStream &stream, const MagazaBilgileri &data);
    friend QDataStream &operator>>(QDataStream &stream, MagazaBilgileri &data);
};



#endif // MAGAZABILGILERI_H
