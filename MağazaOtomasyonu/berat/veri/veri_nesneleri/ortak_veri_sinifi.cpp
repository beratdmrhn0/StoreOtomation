#include "ortak_veri_sinifi.h"

#include <QMetaProperty>

TemelVeriSinifi::TemelVeriSinifi(QObject *parent)
    : QObject{parent}
    , _id{InvalidId}
    , _silindi{false}
{}

IdType TemelVeriSinifi::id() const
{
    return _id;
}

void TemelVeriSinifi::setId(IdType newId)
{
    if (_id == newId)
        return;
    _id = newId;
    emit idDegisti(_id);
}

void TemelVeriSinifi::resetId()
{
    setId(InvalidId);
}

BoolType TemelVeriSinifi::silindi() const
{
    return _silindi;
}

void TemelVeriSinifi::setSilindi(BoolType newSilindi)
{
    if (_silindi == newSilindi)
        return;
    _silindi = newSilindi;
    emit silindiDegisti(_silindi);
}

void TemelVeriSinifi::resetSilindi()
{
    setSilindi(false);
}

void TemelVeriSinifi::geriYuklemeNoktasiOlustur()
{
    // Bu fonksiyon bu nesnenin verilerinin aktif değerlerini saklar.
    // Talep edildiğinde ilkHalineGetir fonksiyonu ile geri yükler.

    // Değişiklikleri izle aktif ise zaten işlemi tekrarlamaya gerek
    // yok.
    if (!_degisiklikleriIzleAktif) {
        // mevcut değişkenlerin tümünün aktif değerlerinin saklanması lazım.
        // QObject sayesinde tüm Propertylerin listesine ulaşılabilir.

        // Meta-nesne nesnenin özellikleri ile ilgili bilgi içeren nesnedir.
        auto metaNesne = this->metaObject();

        // Meta-nesne erişildikten sonra tüm Q_PROPERTY'ler basit bir for
        // döngüsü ile gezilebilir.
        for (auto i = 0; i < metaNesne->propertyCount(); i++) {
            // i. özellik elde ediliyor.
            auto ozellik = metaNesne->property(i);
            // bu özellik QObject'in dinamik özellik sistemine ekleyip
            // değeri saklayalım. Tabi burada özellik adının önüne
            // "_g" öneki eklenmiştir - QString'in arg özelliği sağolsun :).
            // Yani "id" özelliği "_gid" haline gelecektir.
            // Bu fonksiyonun bu kadar uzun olmasının nedeni, setProperty fonksiyonunun
            // char * istemesidir. Bir QString'de char *'a ".toStdString().c_str()" ifadesi
            // ile char * 'a döner.
            setProperty(tr("_g%1").arg(ozellik.name()).toStdString().c_str(), ozellik.read(this));
        }

        _degisiklikleriIzleAktif = true;
    }
}

void TemelVeriSinifi::degisiklikleriKabulEt()
{
    if (_degisiklikleriIzleAktif) {
        for (const auto &ozellik : dynamicPropertyNames()) {
            setProperty(ozellik.data(), {});
        }
        _degisiklikleriIzleAktif = false;
    }
}

void TemelVeriSinifi::geriYukle()
{
    // Eğer değişiklikleri izle aktifse bu işlem yapılabilir.
    if (_degisiklikleriIzleAktif) {
        // Meta-nesne'ye erişelim.
        auto metaNesne = this->metaObject();

        // Özellikler için yine döngü ile erişim yapalım,
        // ancak burada dinamik property'ler ile erişim yapılmalı
        auto dinamikOzellikAdlari = dynamicPropertyNames();

        // Dinamik özellik adları QByteArray olduğu için QString'e
        // çevirmeliyiz.
        for (const auto &ozellikAdi : dinamikOzellikAdlari) {
            // Özellik adını QByteArray'dan QString'e çevirelim.
            QString sOzellikAdi(ozellikAdi);
            // "_g" ön ekini kaldıralım.
            // right fonksiyonu bir metnin sağdan belirtilen karakter
            // kadarını alır.
            sOzellikAdi = sOzellikAdi.right(sOzellikAdi.length() - 2);
            // QString'i char *'a çevirelim.
            auto metin = sOzellikAdi.toStdString().c_str();
            // QMetaProperty'ye erişelim
            auto ozellikIdx = metaNesne->indexOfProperty(metin);

            auto ozellik = metaNesne->property(ozellikIdx);

            // Şimdi özelliğin eski değerini öğrenelim.
            // Özellik adı QByteArray olduğu için .data()
            // fonksiyonu ile char *'a çevirelim.
            auto eskiDeger = property(ozellikAdi.data());

            ozellik.write(this, eskiDeger);

            // Eski değeri silelim. Özellik adı'na geçersiz bir
            // değer atarsanız silinir.
            setProperty(ozellikAdi.data(), {});
        }

        _degisiklikleriIzleAktif = false;
    }
}

QDataStream &operator<<(QDataStream &stream, const TemelVeriSinifi &data)
{
    stream << data._id << data._silindi;
    return stream;
}

QDataStream &operator>>(QDataStream &stream, TemelVeriSinifi &data)
{
    stream >> data._id >> data._silindi;
    return stream;
}
