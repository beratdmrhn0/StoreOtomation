#include "mgzekran.h"
#include "ekranlar/giris/ui_mgzekran.h"

MgzEkran::MgzEkran(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MgzEkran)
{
    ui->setupUi(this);

    setFocusProxy(ui->leYetkiliKisi);
}

MgzEkran::~MgzEkran()
{
    delete ui;
}

MagazaBilgileriPtr MgzEkran::manav() const
{
    return _manav;
}

void ManavEkran::setManav(const ManavPtr &newManav)
{
    if (_manav == newManav)
        return;
    if (_manav.get() != nullptr) {
        disconnect(_manav.get(), nullptr, ui->leManavAdi, nullptr);
        disconnect(_manav.get(), nullptr, ui->leManavTelefon, nullptr);
        disconnect(_manav.get(), nullptr, ui->pteManavAdresi, nullptr);

        disconnect(ui->leManavAdi, nullptr, _manav.get(), nullptr);
        disconnect(ui->leManavTelefon, nullptr, _manav.get(), nullptr);
        disconnect(ui->pteManavAdresi, nullptr, this, nullptr);
        disconnect(this, nullptr, _manav.get(), nullptr);
    }
    _manav = newManav;
    emit manavDegisti(_manav);
    ui->leManavAdi->setText(_manav->manavAdi());
    ui->leManavTelefon->setText(_manav->manavTelefon());
    ui->pteManavAdresi->setPlainText(_manav->manavAdresi());

    connect(ui->leManavAdi, &QLineEdit::textChanged, _manav.get(), &Manav::setManavAdi);
    connect(ui->leManavTelefon, &QLineEdit::textChanged, _manav.get(), &Manav::setManavTelefon);
    connect(ui->pteManavAdresi,
            &QPlainTextEdit::textChanged,
            this,
            &ManavEkran::adresDegisiminiHallet);
    connect(this, &ManavEkran::adresDegisti, _manav.get(), &Manav::setManavAdresi);
}

void MgzEkran::adresDegisiminiHallet()
{
    if(_manav->manavAdresi() != ui->pteManavAdresi->toPlainText())
        emit adresDegisti(ui->pteManavAdresi->toPlainText());
}

void MgzEkran::setVeriNesnesi(const std::shared_ptr<TemelVeriSinifi> &veri)
{
    setManav(std::static_pointer_cast<MagazaBilgileri>(veri));
}
