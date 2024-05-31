#ifndef URUNKATEGORISIKONTEYNIR_H
#define URUNKATEGORISIKONTEYNIR_H

#include <QObject>
#include "../konteynirler.h"

class urunkategorisikonteynir : public QObject, public UrunKategorisiKonteynirType
{
    Q_OBJECT
public:
     explicit urunkategorisikonteynir(QObject *parent = nullptr);
signals:
    void veriEklendi(const Ptr &veri);
    void veriSilindi(const Ptr &veri);
};

#endif // URUNKATEGORISIKONTEYNIR_H
