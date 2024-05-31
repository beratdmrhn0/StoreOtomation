#ifndef SIPARISURUNUKONTEYNIR_H
#define SIPARISURUNUKONTEYNIR_H

#include <QObject>
#include "../konteynirler.h"

class siparisurunukonteynir : public QObject, public SiparisUrunuKonteynirType
{
    Q_OBJECT
public:
    explicit siparisurunukonteynir(QObject *parent = nullptr);
signals:
    void veriEklendi(const Ptr &veri);
    void veriSilindi(const Ptr &veri);
};

#endif // SIPARISURUNUKONTEYNIR_H
