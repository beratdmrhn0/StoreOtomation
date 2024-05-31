#pragma once

#include "../../veri/veri_nesneleri/ortak_veri_sinifi.h"
#include <memory>

class VeriNesnesiAtamaArayuzu
{
public:
    virtual void setVeriNesnesi(const std::shared_ptr<TemelVeriSinifi> &veri) = 0;
};
