#ifndef MUSTERIKONTEYNIR_H
#define MUSTERIKONTEYNIR_H

#include <QObject>
#include "..\konteynirler.h"

class musterikonteynir : public QObject, public MusteriKonteynirType
{
    Q_OBJECT
public:
    explicit musterikonteynir(QObject *parent = nullptr);

signals:
    void veriEklendi(const Ptr &veri);
    void veriSilindi(const Ptr &veri);
};

#endif // MUSTERIKONTEYNIR_H
