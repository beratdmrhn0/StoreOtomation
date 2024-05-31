#ifndef URUNLERKONTEYNIR_H
#define URUNLERKONTEYNIR_H

#include <QObject>
#include "../konteynirler.h"

class urunlerkonteynir : public QObject, public UrunlerKonteynirType
{
    Q_OBJECT
public:
    explicit urunlerkonteynir(QObject *parent = nullptr);
signals:
    void veriEklendi(const Ptr &veri);
    void veriSilindi(const Ptr &veri);
};

#endif // URUNLERKONTEYNIR_H
