#ifndef SIPARISKONTEYNIR_H
#define SIPARISKONTEYNIR_H

#include <QObject>
#include "../konteynirler.h"

class sipariskonteynir : public QObject, public SiparisKonteynirType
{
    Q_OBJECT
public:
    explicit sipariskonteynir(QObject *parent = nullptr);

signals:
    void veriEklendi(const Ptr &veri);
    void veriSilindi(const Ptr &veri);

};

#endif // SIPARISKONTEYNIR_H
