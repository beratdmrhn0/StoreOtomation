#ifndef URUNOZELLIKLERIKONTEYNIR_H
#define URUNOZELLIKLERIKONTEYNIR_H

#include <QObject>
#include "../konteynirler.h"

class urunozelliklerikonteynir : public QObject, public UrunKategorisiKonteynirType
{
    Q_OBJECT
public:
    urunozelliklerikonteynir(QObject *parent = nullptr);
signals:
    void veriEklendi(const Ptr &veri);
    void veriSilindi(const Ptr &veri);
};

#endif // URUNOZELLIKLERIKONTEYNIR_H
