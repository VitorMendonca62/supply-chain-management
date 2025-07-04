/******************************************************************************
 * Arquivo     : vendor_service.h
 * Autor       : Luís Moreira
 * Criado em   : 04/07/2025
 * Descrição   : Arquivo de header envolvendo a classe VendorService
 *
 * Projeto     : Projeto prático de EDOO
 *
 * Histórico de Modificações:
 *  - 04/07/2025: Versão inicial (Luís Moreira)
 ******************************************************************************/

#include <iostream>

#ifndef VENDOR_SERVICE_H
#define VENDOR_SERVICE_H

#include "../shared/Service_view.h"

class VendorService :: public ServiceView {
  VendorService() = default;

  void create() override;
  void getAll() override;
  void getOne() override;
  // void update() override;
  // void deleteVendor() override;
  
  void updatePhoneNumberVendor();
  void updateEmailVendor();  
  
  ~VendorService() override = default;       
}


#endif