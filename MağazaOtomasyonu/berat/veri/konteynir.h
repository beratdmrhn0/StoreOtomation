#pragma once

#include "ortak.h"

/**
 * @brief Konteynır sınıfı prototip tanımı
 *
 * Bu tanım izleyen iki fonksiyon prototipi için yapılmıştır. Tanımlanma sebebi
 * C/C++ derleyicisinin izleyen iki fonksiyon prototipini sınıf içinde ayırt edememesidir.
 */
template<class T>
class Konteynir;

/**
 * @brief operator << Konteynır serileştirme operatör fonksiyonu
 *
 * Bu fonksiyon bir konteynır sınıfı nesnesini QDataStream nesnesi aracılığıyla serileştirmek için
 * kullanılır.
 *
 * @param stream Serileştirmede kullanılacak QDataStream Sınıfı
 * @param data Serileştirilecek Konteynır Sınıfı Nesnesi (şablon sınıf)
 * @return Konteynır sınıfı serileştirilmiş QDataStream sınıfı nesnesi.
 */
template<class U>
QDataStream &operator<<(QDataStream &stream, const Konteynir<U> &data);

/**
 * @brief operator << Serileştirilmiş Konteynır nesnesini geri yükleme operatör fonksiyonu
 *
 * Bu fonksiyon serileştirilmiş bir konteynır sınıfı nesnesini QDataStream nesnesi aracılığıyla belleğe
 * getirmek için kullanılır.
 *
 * @param stream Geri Yüklemede kullanılacak QDataStream Sınıfı
 * @param data Geri yüklenecek Konteynır Sınıfı Nesnesi (şablon sınıf)
 * @return Konteynır sınıfı geri yüklenmiş QDataStream sınıfı nesnesi.
 */
template<class U>
QDataStream &operator>>(QDataStream &stream, Konteynir<U> &data);

/**
 * @class Konteynir
 * @brief Konteynir sınıfı
 *
 * Bu sınıf yazılım içerisinde tanımlanmış olan veri sınıflarına ait nesnelerden, birden fazlasını
 * saklamak amacıyla nesneler oluşturmak için kullanılır. Konteynır nesneleri belirli sadece
 * tanımlandıkları sınıflara ait nesneleri tutmakla kalmayıp, bu nesneler üzerinde arama, silme
 * gibi işlemleri de gerçekleştirecek şekilde tasarlanmışlardır.
 *
 * Bu sınıf tüm veri nesneleri için aynı kod yapısına sahip olacağı için şablon olarak tasarlanmış olup,
 * kullanıldığında ilgili sınıfa ait nesneleri tutacak ve işleyecek şekilde C++ derleyicisi tarafından
 * modifiye edilecektir.
 *
 * @note Her konteynır sınıfı nesnesi kendi içerisinde bir sayaç mekanizması sunmaktadır. Bu sayacın amacı eklenen
 * tüm nesnelere otomatik olarak id değeri atanmasıdır. Sınıfın tasarımı farklı iki nesneye hiç bir
 * zaman aynı id değerini vermeyecek şekilde yapılmıştır. Bu sayede, konteynır sınıflarında saklanan
 * hiçbir nesne aynı türdeki farklı bir nesne ile aynı id değerine sahip olamaz.
 *
 * @note Konteynır sınıfının sakladığı nesneler doğrudan silinmeyecek, bunun yerine silinmek üzere işaretlenecektir.
 * Yazılımcı talep ederse silinmek üzere işaretlenmiş nesneleri tamamen silebilir veya işaretini kaldırabilir.
 *
 * @note Konteynır sınıfının sakladığı bir nesne silindiğinde, silinen nesneye ait id değeri artık kullanılamayacaktır.
 */
template<class T>
class Konteynir
{
public:
    using Veri = T; //! Bu sınıf kapsamında kullanılacak veri türü için takma isim.
    using Ptr = std::shared_ptr<
        Veri>; //! Veri nesnesinin kopyasının oluşmaması için kullanılacak pointer türü için takma isim.
    using Vektor = QVector<
        Ptr>; //! Saklanacak olan nesne pointerlarının vektörü (hem veri saklamada hem de arama sonuçlarında kullanılacaktır)
    using Fonksiyon = std::function<BoolType(
        const Ptr &data)>; //! Saklanan verilerin filtrelenmesi için kullanılacak fonksiyon türü
    using Iterator = typename Vektor::
        iterator; //! Oluşturulan vektörlerin içerisinde ileri doğru gezebilmek için kullanılacak döngü türü

    /**
     * @class ZatenVarHatasi
     * @brief ZatenVarHatasi sınıfı
     *
     * Konteynır'a eklenmeye çalışılan veri sınıfı nesnesi, konteynırda olduğunda oluşturulacak olan hata nesnelerine
     * ait sınıf.
     *
     * Bu sınıf std::logic_error sınıfından türetilmiştir. Bu türetmenin sebebi, std::logic_error'un bir mesaj mekanizması
     * sunması ve sözü geçen hatanın bir mantık hatası olmasıdır.
     */
    class ZatenVarHatasi : public std::logic_error
    {
    public:
        ZatenVarHatasi()
            : std::logic_error(QObject::tr("Eklenecek Kayıt Zaten var").toStdString())
        {}
    };

    /**
     * @class KayitBulunamadiHatasi
     * @brief KayitBulunamadiHatasi sınıfı
     *
     * Konteynır'dan silinmeye çalışılan veri sınıfı nesnesi, konteynırda bulunamadığında oluşturulacak olan hata nesnelerine
     * ait sınıf.
     *
     * Bu sınıf std::logic_error sınıfından türetilmiştir. Bu türetmenin sebebi, std::logic_error'un bir mesaj mekanizması
     * sunması ve sözü geçen hatanın bir mantık hatası olmasıdır.
     */
    class KayitBulunamadiHatasi : public std::logic_error
    {
    public:
        KayitBulunamadiHatasi()
            : std::logic_error(QObject::tr("Kayit Bulunamadi!").toStdString())
        {}
    };

    /**
     * @brief Konteynir Sınıfı İlklendiricisi
     *
     * Bu ilklendirici konteynır sınıfının içerdiği vektör nesnesini boş olarak ve sayaç değerini de geçersiz olarak
     * başlatmaya yarayacaktır.
     */
    Konteynir()
        : _sayac(InvalidCounter)
    {}

    /**
     * @brief arama Konteynırın sakladığı nesnelerde arama yapma fonksiyonu
     *
     * Bu fonksiyon konteynır nesnesinin içerdiği nesne vektörünün herbir elemanını, tanım kümesinde belirtilen
     * arama fonksiyonundan geçirerek, arama fonksiyonun true döndürdüğü nesnelerden oluşan yeni bir vektör oluşturmak
     * için kullanılmaktadır.
     *
     * @note Elde edilecek arama sonucu vektöründe silinecek olarak işaretlenmiş nesneler bulunmayacaktır.
     *
     * @param f Aramada kullanılacak fonksiyon.
     * @return Belirtilen fonksiyonu true olarak döndüren nesnelerin vektörü (vektör boş olabilir, kontrol sorumluluğu programcıya bırakılmıştır).
     */
    Vektor arama(Fonksiyon f)
    {
        Vektor sonuc;
        for (auto &i : _veriler) {
            if (f(i) && !i->silindi()) {
                sonuc.push_back(i);
            }
        }
        return sonuc;
    }

    /**
     * @brief IdyeGoreAra Konteynır'ın içerdiği nesneler üzerinde id araması yapan fonksiyon
     *
     * Bu fonksiyon hızlı bir şekilde konteynır'ın içerdiği nesneleri id'sine göre arayıp
     * geri döndürür.
     *
     * @note Silinmek üzere işaretlenmiş nesnelere bu fonksiyon aracılığı ile ulaşılamaz.
     *
     * @param id Aranacak nesnenin id'si
     * @return Aranan nesne veya nullptr (nullptr kontrolü programcıya bırakılmıştır)
     */
    Ptr IdyeGoreAra(IdType id)
    {
        for (auto &i : _veriler) {
            if (i->id() == id && !i->silindi()) {
                return i;
            }
        }
        return nullptr;
    }

    /**
     * @brief geriDonusumKutusu Silinmek üzere işaretli nesneleri öğrenmek için kullanılan fonksiyon
     *
     * Bu fonksiyon aracılığı ile bu konteynır nesnesinde silinmek üzere işaretlenmiş olan nesnelerin
     * bir vektörü öğrenilebilir.
     *
     * @return Silinmek üzere işaretlenmiş nesnelerin vektörü (vektör boş olabilir, kontrol sorumluluğu programcıya bırakılmıştır).
     */
    Vektor geriDonusumKutusu()
    {
        Vektor sonuc;
        for (auto &i : _veriler) {
            if (i->silindi()) {
                sonuc.append(i);
            }
        }
        return sonuc;
    }

    /**
     * @brief silme Nesneyi silmek üzere işaretleme fonksiyonu
     *
     * Bu fonksiyon bu konteynır nesnesinde saklanan bir nesneyi silmek üzere işaretler. İşaretlenecek olan nesne
     * id değeri aracılığı ile bulunur.
     *
     * @param tanimlayici Silinmek üzere işaretlenecek nesnenin id değeri
     */
    void silme(IdType tanimlayici)
    {
        for (auto i = _veriler.begin(); i != _veriler.end(); i++) {
            auto &veri = *i;
            if (veri->id() == tanimlayici && !veri->silindi()) {
                veri->setSilindi(true);
                emit veriSilindi(veri);
                break;
            }
        }
        throw KayitBulunamadiHatasi();
    }

    /**
     * @brief ekle Konteynır'a yeni nesne ekler
     *
     * Bu fonksiyon konteynır'a yeni nesne eklemek için kullanılacak fonksiyon. Bu fonksiyon aynı id'ye sahip iki farklı nesnenin
     * eklenmesine izin vermeyecektir. Ayrıca ekleme işlemi başarı ile tamamlanırsa nesnenin id değerini otomatik olarak konteynır'ın
     * sayacının bir fazlasına atanacaktır.
     *
     * @note Eklenecek olan nesnenin zaten bir id değeri varsa bu id değeri kontrol edilecek ve konteynır'ın sayaç değeri
     * güncellenecektir.
     *
     * @param eklenecek Konteynır'a eklenecek olan nesnenin pointer'ı.
     */
    void ekle(Ptr eklenecek)
    {
        if (eklenecek->id() == InvalidId) {
            _veriler.append(eklenecek);
            if (_sayac == InvalidCounter) {
                _sayac = 0;
            }
            eklenecek->setId(++_sayac);
            emit veriEklendi(eklenecek);
        } else {
            auto aramasonucu = arama(
                [eklenecek](const Ptr &i) { return i->id() == eklenecek->id(); });
            // arama sonucunun 0 veya boş olmasını bekliyoruz...
            if (aramasonucu.empty()) {
                _veriler.push_back(eklenecek);
                _sayac = std::max(_sayac, eklenecek->id());
                emit veriEklendi(eklenecek);
            } else {
                throw ZatenVarHatasi();
            }
        }
    }

    /**
     * @brief yeni_yer_olustur Bellekte yeni bir nesne oluşturur
     *
     * Bu fonksiyon bellekte yeni bir nesne oluşturmak amacı ile kullanılacak fonksiyon.
     * Bu fonksiyon oluşturulan pointer'ın otomatik silinebilmesi için C++ 2011 standardında tanıtılan
     * akıllı pointer mekanizmasını kullanmaktadır.
     *
     * @return Yeni oluşturulmuş nesnenin akıllı pointerı.
     */
    Ptr yeni_yer_olustur() { return std::make_shared<Veri>(); }

    // Sinyal bağlantıları için sanal fonksiyonlar oluşturuluyor
    virtual void veriEklendi(const Ptr &veri) = 0;
    virtual void veriSilindi(const Ptr &veri) = 0;

private:
    CounterType _sayac; //! Konteynır nesnesinin id sayaç değeri
    Vektor _veriler;    //! Konteynır nesnesinin saklayacağı nesneleri tutacak vektör nesnesi

    /**
     * @brief operator << Konyeynır sınıfını serileştirir.
     *
     * Bu operatör fonksiyonu QDataStream kullanarak konteynır nesnesini serileştirir.
     *
     * @param stream Serileştirmede kullanılacak olan QDataStream nesnesi
     * @param data Serileştirilecek olan Konteynır nesnesi
     * @return Serileştirmede kullanıldıktan ve konteynır nesnesinin serileştirilmiş halini içeren QDataStream nesnesi
     */
    friend QDataStream &operator<<(QDataStream &stream, const Konteynir<T> &data)
    {
        stream << data._sayac << data._veriler;
        return stream;
    }

    /**
     * @brief operator >> Serileştirilmiş bir Konyeynır sınıfını nesnesini belleğe geri yükler.
     *
     * Bu operatör fonksiyonu QDataStream kullanarak serileştirilmiş bir konteynır nesnesini belleğe geri yükler.
     *
     * @param stream Geri yüklemede kullanılacak olan QDataStream nesnesi
     * @param data Geri yüklenecek olan Konteynır nesnesi
     * @return Geri yüklemede kullanıldıktan ve konteynır nesnesinin geri yüklenmiş halini içeren QDataStream nesnesi
     */
    friend QDataStream &operator>>(QDataStream &stream, Konteynir<T> &data)
    {
        stream >> data._sayac >> data._veriler;
        return stream;
    }
};

/**
 * @brief operator << Veri nesnelerinin pointerlarını serileştiren fonksiyon
 *
 * Bu fonksiyon veri nesnelerinin pointer'larının gösterdiği bellek bölgesindeki veriyi serileştirir. Temel olarak
 * pointer'ın gösterdiği bellek adresine giderek ilgili sınıfın serileştirme fonksiyonu çalıştırılır.
 *
 * @param stream Serileştirmede kullanılacak olan QDataStream nesnesi
 * @param data Serileştirilecek olan veri pointerı
 * @return Serileştirmede kullanıldıktan ve nesne pointerının serileştirilmiş halini içeren QDataStream nesnesi
 */
template<class T>
QDataStream &operator<<(QDataStream &stream, const std::shared_ptr<T> &data)
{
    stream << *data;
    return stream;
}

/**
 * @brief operator >> Serileştirilmiş Veri nesnelerini belleğe geri yükleyen fonksiyon
 *
 * Bu fonksiyon serileştirilmiş veri nesnelerini belleğe geri yükler. Temel olarak
 * bellekte yeni bir nesne oluşturup ilgili sınıfın geri yükleme fonksiyonunu çalıştırır.
 *
 * @param stream Geri yüklemede kullanılacak olan QDataStream nesnesi
 * @param data Geri yüklenecek olan veri pointerı
 * @return Geri yüklemede kullanıldıktan ve nesne pointerını belleğe getirilmiş halini içeren QDataStream nesnesi
 */
template<class T>
QDataStream &operator>>(QDataStream &stream, std::shared_ptr<T> &data)
{
    data = std::make_shared<T>();
    stream >> *data;
    return stream;
}
