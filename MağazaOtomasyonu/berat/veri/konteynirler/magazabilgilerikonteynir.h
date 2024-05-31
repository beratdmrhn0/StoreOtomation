#ifndef MAGAZABILGILERIKONTEYNIR_H
#define MAGAZABILGILERIKONTEYNIR_H
#include <QObject>
#include "../konteynirler.h"


class MagazaBilgileriKonteynir: public QObject, public MagazaBilgileriKonteynirType
{
     Q_OBJECT
public:
    explicit MagazaBilgileriKonteynir(QObject *parent = nullptr);

signals:
    void veriEklendi(const Ptr &veri);
    void veriSilindi(const Ptr &veri);
};

#endif // MAGAZABILGILERIKONTEYNIR_H
