#pragma once

#include <QObject>

#include <QDataStream>
#include "..\ortak.h"

/**
 * @class TemelVeriSınıfı
 * @brief Yazılımdaki tüm veri nesneleri için temel sınıf.
 *
 * Bu sınıf manav yazılımındaki tüm veri nesnelerinin temelini oluşturmaktadır. Buı sayede
 * Tüm veri sınıflarına id, silindi desteği kazandırılmıştır. Ayrıca, Qt'nın dinamik özelik
 * oluşturabilme yeteneği sayesinde bu sınıftan oluşturulan nesnelerin mevcur özelliklerine
 * (değişkenlerine) ait değerler saklanarak değişiklikleri izleme modu açılabilmektedir. Bu
 * mod açıldığında nesnede yapılan değişiklikler geri alınabilmektedir. Detaylı açıklama
 * İlgili fonksiyonlarda verilmiştir.
 *
 */
class TemelVeriSinifi : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief TemelVeriSinifi İlklendiricisi
     *
     * Bu fonksiyon temel veri sınıfıa ait bir nesneyi ilklendirir. Standart Qt ilklendiricilerinde
     * olduğu gibi parent pointerı içermektedir. Ayrıca, id için geçersiz, silindi içinde false
     * değerlerini atar.
     *
     * @param parent Varsayılan Qt İlklendirme parametresi.
     */
    explicit TemelVeriSinifi(QObject *parent = nullptr);

    /**
     * @brief id Bu sınıftan oluşan nesnelerin ayırtedicisi.
     *
     * Bu sınıftan veya alt sınıflarından türetilen nesneler için ayırt edici bir özellik ekler.
     *
     * @return Aktif nesnenin ayırt edici değeri.
     */
    [[nodiscard]] IdType id() const;

    /**
     * @brief silindi Bu sınıfı silinmiş olarak işaretler.
     *
     * Bu yazılımda kullanıcının girdiği hiçbir veri *gerçek* anlamda silinmemektedir. Bunun
     * yerine silinmiş olarak işaretlenmekte ve hesaplamalardan çıkarılmaktadır.
     * Bu okuyucu fonksiyon nesnenin silinmiş olarak işaretlenip işaretlenmediğini gösterir.
     *
     * @return Nesne silinmiş olarak işaretlenmişse true, aksi halde false.
     */
    [[nodiscard]] BoolType silindi() const;

public slots:
    /**
     * @brief setId Nesnenin ayırt edici özelliğini atar.
     *
     * Nesnenin ayırt edici özelliğini newId parametresi ile belirtilen değere atar.
     *
     * @param newId Nesnenin yeni ayırt edici değeri.
     */
    void setId(IdType newId);

    /**
     * @brief resetId Nesnenin ayırt edici özelliğini sıfırlar.
     *
     * Bu fonksiyon id değerini geçersiz hale getirerek sıfırlar.
     */
    void resetId();

    /**
     * @brief setSilindi Nesneyi silinmek üzere işaretler/işaretini kaldırır
     *
     * Bu fonksiyon bir nesnenin silinmek üzere işaretlenmesini veya silinmek üzere işaretlenmiş
     * bir nesnenin işaretinin kaldırılmasını sağlar.
     *
     * @param newSilindi True ise nesne silinmek üzere işaretlenir, False ise silinmiş nesnenin işareti kaldırılır.
     *
     * @note Silinmek üzere işaretlenmiş nesneler üzerinde True değerinin, silinmen üzere işaretlenmemiş nesnelerin
     * üzerinde de False değerinin hiç bir etkisi yoktur.
     */
    void setSilindi(BoolType newSilindi);

    /**
     * @brief resetSilindi Nesnenin silinmek üzere konulmuş işaretini kaldırır.
     *
     * @note Silinmek üzere işaretlenmemiş nesneler üzerinde hiçbir etkisi yoktur.
     */
    void resetSilindi();

    /**
     * @brief geriYuklemeNoktasiOlustur Nesnenin aktif durumunu kaydeder.
     *
     * Bu fonksiyon nesnenin mevcut değişkenlerinin durumunu kaydederek bir geri dönme noktası oluşturur.
     * Eğer nesnenin değerlerinin geri döndürülmesi isteniyorsa geriYukle fonksiyonu, aksi halde
     * degisiklikleriKabulEt fonksiyonu kullanılabilir.
     *
     * @note Mevcut durumda sadece 1 geri yükleme noktası oluşturulmaktadır. Bu fonksiyonun iki defa
     * (arada geriYukle veya degisiklikleriKabulEt fonksiyonu kullanılmadan) çağırılmasının bir etkisi
     * olmayacaktır.
     */
    void geriYuklemeNoktasiOlustur();

    /**
     * @brief degisiklikleriKabulEt Nesnede yapılan değişiklikleri kabul eder.
     *
     * Bu fonksiyon geri yükleme noktası oluşturulmuş bir nesnede yapılan değişiklikleri kabul ederek,
     * geri yükleme nokasını siler. Bu sayede, nesne üzerinde yeniden geri yükleme noktası oluşturulmasını
     * sağlar.
     */
    void degisiklikleriKabulEt();

    /**
     * @brief geriYukle Nesnede yapılan değişiklikleri geri alır.
     *
     * Bu fonksiyon nesneyi en son geri yükleme noktasındaki haline geri getirir.
     */
    void geriYukle();

signals:
    /**
     * @brief idDegisti Nesnenin id değeri değiştiğinde tetiklenecek sinyal.
     *
     * Bu sinyal nesnenin id değeri değiştiğini Qt'nin sunduğu sinyal mekanizmasına bildirir.
     *
     * @param id Nesnenin yeni id değeri.
     */
    void idDegisti(IdType id);

    /**
     * @brief silindiDegisti Nesnenin silinmek üzere işareti değiştiğinde çalışacak sinyal.
     *
     * Bu sinyal nesnenin silinme durumu değiştiğini Qt'nin sunduğu sinyal mekanizmasına bildirir.
     *
     * @param silindi True ise nesne silinmiştir, False ise geri yüklenmiştir.
     */
    void silindiDegisti(BoolType silindi);

private:
    IdType _id;        //! Nesnenin id değerini tutan değişken.
    BoolType _silindi; //! Nesnenin silinmek üzere işatlenip işaretlenmediğini tutan değişken.

    BoolType _degisiklikleriIzleAktif; //! Değişiklik izlemenin açık olup olmadığını gösteren değişken.

    Q_PROPERTY(IdType id READ id WRITE setId RESET resetId NOTIFY idDegisti FINAL)
    Q_PROPERTY(BoolType silindi READ silindi WRITE setSilindi RESET resetSilindi NOTIFY
                   silindiDegisti FINAL)

    /**
     * @brief operator << Temel veri sınıfından oluşan nesneyi serileştirir.
     *
     * Bu operatör fonksiyonu, bir temel veri sınıfı nesnesini QDataStream aracılığı ile serileştirmek
     * amacıyla kullanılır.
     *
     * @param stream Serileştirmede kullanılacak QDataStream nesnesi
     * @param data Serileştirilecek Temel Veri Sınıfı nesnesi
     *
     * @return Serileştirmede kullanılacak ve veri nesnesi aktarılmış QDataStream nesnesi.
     */
    friend QDataStream &operator<<(QDataStream &stream, const TemelVeriSinifi &data);

    /**
     * @brief operator >> Serileştirilmiş bir Temel Veri Nesnesini belleğe geri yükler.
     *
     * Bu operatör fonksiyonu, serileştirilmiş bir Temel Veri Nesnesini belleğe geri
     * yüklemek amacıyla kullanılır.
     *
     * @param stream Geri yüklemede kullanılacak QDataStream Nesnesi
     * @param data Geri yüklenecek Temel Veri Sınıfı Nesnesi
     *
     * @return Geri yüklemede kullanılacak ve Ürün Sınıfı okunmuş QDataStream Nesnesi
     */
    friend QDataStream &operator>>(QDataStream &stream, TemelVeriSinifi &data);
};
