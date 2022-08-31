#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "Tvehicle.h"
#include "Tfactory.h"
#include "Services.h"
#include <iostream>
#include <string>

constexpr int FactoryTabSize = 5;


int readInt();
string readString();
void MainMenu(Tfactory** tab,Tcar_dealer* dealer,TCustomer* customer);
void CarDealerMenu(Tcar_dealer* ,TCustomer* customer);                 //menu Komisu
void FactoryMenu(Tfactory** tab, Tfactory* factory,TCustomer* customer, int factory_index = 0); //menu zarządzania fabryką
void CreateFactory(Tfactory** tab);
void ChooseFactory(Tfactory** tab,TCustomer* customer);
void RepaintVehicle(Tfactory* factory);                                // lakiernik
void BuyCarFromDealer(Tcar_dealer* dealer, TCustomer* customer);       // kupno od komisu
void SellCarToDealer(Tcar_dealer* dealer, TCustomer* customer);        // sprzedarz komisowi
void BuildVehicle(Tfactory* factory);
void DeleteFactory(Tfactory** tab,Tfactory* factory,int factory_index);
void SellCarToCustomer(Tfactory* factory, TCustomer* customer);
void BicycleWorkshop();
#endif //FUNCTIONS_H
