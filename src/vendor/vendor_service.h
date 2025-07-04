/******************************************************************************
 * Arquivo     : vendor_service.h
 * Autor       : Luís Moreira
 * Criado em   : 04/07/2025
 * Descriçao   : Arquivo de header envolvendo a classe VendorService
 *
 * Projeto     : Projeto prático de EDOO
 *
 * Histórico de Modificações:
 *  - 04/07/2025: Versao inicial (Luís Moreira)
 ******************************************************************************/

#include <iostream>

#ifndef VENDOR_SERVICE_H
#define VENDOR_SERVICE_H

#include "../shared/Service.h"

class VendorService : public Service
{
public:
  VendorService() = default;

  void create() override;
  void getAll() override;
  void getOne() override;
  void update() override;
  void deleteItem() override;

  void updatePhoneNumberVendor();
  void updateEmailVendor();

  ~VendorService() override = default;
};

#endif