#include "Vehicles.h"
#include "Tfactory.h"
#include "functions.h"
#include <string>

int Tfactory::factory_amount = 0;

int main(int argc, char* argv[]) {
    try{
        auto **FactoryTab = new Tfactory *[FactoryTabSize];    // Tablica fabryk
        for (int i = 0; i < FactoryTabSize; ++i)
            FactoryTab[i] = nullptr;
        auto *customer = new TCustomer();
        auto *car_dealer = new Tcar_dealer();

        if (argc == 2)
            freopen(argv[1], "r", stdin);

        MainMenu(FactoryTab, car_dealer, customer);

        // zwolnienie pamieci
        for (int i = 0; i < FactoryTabSize; ++i) {
            if (FactoryTab[i] != nullptr)
                DeleteFactory(FactoryTab, FactoryTab[i], i);
        }
        delete[] FactoryTab;
        delete customer;
        delete car_dealer;
        return 0;
    }
    catch (bad_alloc &bad) {
        cerr << "Allocation issue caused by: " << bad.what();
    }
}