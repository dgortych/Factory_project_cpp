#ifndef FUNCTIONS_CPP_H
#define FUNCTIONS_CPP_H
#include "functions.h"
#include <new>

int choice;

int readInt() {
    string line;
    getline(cin, line);
    return atoi(line.c_str());
}
string readString() {
    string line;
    getline(cin, line);
    return line;
}
void MainMenu(Tfactory** tab,Tcar_dealer* dealer,TCustomer* customer){
    int Mchoice;
    do{
         cout<< "\n---====== MENU GlOWNE =====---\n"
                "1: Stworz nowa fabryke\n"
                "2: Wybierz istniejaca fabryke\n"
                "3: Odwiedz komis samochodowy\n"
                "4: Odwiedz warsztat rowerowy\n"
                "5: Wyjdz z programu\n"
                "6: Rzuc wyjatek bad_alloc\n"
                "Podejmij decyzje wpisujac odpowiedni numer opcji:\n";
        Mchoice = readInt();
        switch(Mchoice) {
            case 1:  try{ CreateFactory(tab); }
            catch(user_action_warning &ex){
            cout<<ex.message<<endl; }
                    break;
            case 2:  try{ ChooseFactory(tab,customer); }
            catch(user_action_warning &ex){
            cout<<ex.message<<endl;}
                    break;
            case 3: CarDealerMenu(dealer,customer);
                break;
            case 4: BicycleWorkshop();
                    break;
            case 5: break;
            case 6: throw bad_alloc();
            default:cout<<"Wybrano niepoprawny numer, sprobuj ponownie!!\n";
                    break;
        }
    }while( Mchoice != 5 );
}

void FactoryMenu(Tfactory** tab, Tfactory* factory,TCustomer* customer, int factory_index ){
    int Fchoice;
    do {
        cout<<
            "\nZnajdujesz sie w fabryce:"<<factory->get_brand()<<
            "\n---====== MENU FABRYKI =====---\n"
            "1: Zbuduj pojazd\n"
            "2: Wyswietl dokladne infromacje o pojazdach\n"
            "3: Sprzedaj samochod\n"
            "4: Przemaluj pojazd\n"
            "5: Usun fabryke\n"
            "6: Wroc do menu glownego\n"
            "Podejmij decyzje wpisujac odpowiedni numer opcji:\n";
        Fchoice = readInt();
        switch (Fchoice) {
            case 1:  BuildVehicle(factory);
                break;
            case 2:  try{factory->print_vehicles();}
            catch(user_action_warning &ex){
            cout<<ex.message<<endl;}
                break;
            case 3:  try{SellCarToCustomer(factory, customer);}
            catch(user_action_warning &ex){
            cout<<ex.message<<endl;}
                break;
            case 4:  try{RepaintVehicle(factory);}
            catch(user_action_warning &ex){
            cout<<ex.message<<endl;}
                break;
            case 5: try{DeleteFactory(tab, factory, factory_index);}
            catch(user_action_warning &ex){
            cout<<ex.message<<endl;}
                break;
            case 6: break;
            default: cout<<"Wybrano niepoprawny numer!! Sprobuj ponownie\n";
                break;
        }
    }while ( !(Fchoice == 5 || Fchoice == 6) );
}
void CarDealerMenu(Tcar_dealer* ,TCustomer* customer){

    int Cchoice;
    auto* CarDealer = new Tcar_dealer();         // dodanie do komisu gotowych samochodow dla mozliwosci ich kupna
    CarDealer->fill_with_vehicles();

    do {
        cout<<
            "Witaj w komisie! W czym moge pomoc?\n"
            "\n---====== MENU KOMISU =====---\n"
            "1: Kup samochod\n"
            "2: Sprzedaj samochod\n"
            "3: Opusc komis\n"
            "Podejmij decyzje:\n";
        Cchoice = readInt();
        switch (Cchoice) {
            case 1:  try{BuyCarFromDealer(CarDealer, customer);}
            catch(user_action_warning &ex){
            cout<<ex.message<<endl;}
                break;
            case 2:  try{SellCarToDealer(CarDealer, customer);;}
            catch(user_action_warning &ex){
            cout<<ex.message<<endl;}
                break;
            case 3: break;
            default: cout<<"Wybrano niepoprawny numer!!\n";
                break;
        }
    }while(Cchoice != 3 );
}

void CreateFactory(Tfactory** tab){
    if(Tfactory::factory_amount >= FACTORY_SIZE )
        throw user_action_warning("Nie mozna utworzyc wiecej fabryk,usun istniejaca i sprobuj ponownie\n");

    Tfactory::factory_amount++;
    string name;
    cout<<"Podaj nazwe fabryki:\n";
    name = readString();

    auto* factory = new Tfactory(name);
    for(int i = 0 ; i < FACTORY_SIZE; ++i ){
        if(tab[i] == nullptr) {
            tab[i] = factory;
            break;
        }
    }
    cout<<"Pomyslnie utworzono fabryke\n";
}

void ChooseFactory(Tfactory** tab,TCustomer* customer){
    int CFchoice;
    if(Tfactory::factory_amount == 0)
        throw user_action_warning("Nie utworzono zadnej fabryki, stworz nowa i sprobuj ponownie!\n");

    cout<<"Utworzone fabryki:\n";
    for(int i = 0; i < FactoryTabSize; ++i) {
        if( tab[i] != nullptr ) {
            cout << i+1 <<"."<<tab[i]->get_brand()<<endl;
        }
    }
    cout << "Wybierz numer fabryki ktora cie interesuje:\n";
    do { CFchoice = readInt();
         if(tab[CFchoice - 1] == nullptr || CFchoice > FactoryTabSize || CFchoice < 1)
            cout << "Wybrano niepoprawny numer!! Sproboj ponownie:\n";
    }while(tab[CFchoice - 1] == nullptr || CFchoice > FactoryTabSize || CFchoice < 1);

    FactoryMenu(tab, tab[CFchoice - 1], customer, CFchoice - 1);
}

void SellCarToCustomer(Tfactory* factory, TCustomer* customer){
    if(factory->get_vehicle_amount() == 0)
        throw user_action_warning("Nie zbudowano zadnego samochodu, zbuduj nowy i sproboj ponownie!\n");

    int length , car_choice;
    factory->print_vehicles_short();
    cout<<"Wybierz numer interesujacego cie pojazdu:\n";

    do { car_choice = readInt();
        if(car_choice <= 0 || car_choice > FACTORY_SIZE || factory->get_vehicle(car_choice - 1) == nullptr )
        cout<<"Wybrano niepoprawny numer, sprobuj ponownie!:\n";
    }while(car_choice <= 0 || car_choice > FACTORY_SIZE || factory->get_vehicle(car_choice - 1) == nullptr );

    cout<<"Wprowadz dlugosc jazdy testowej w km bez jednostki:\n";
    do { length = readInt();
         if(length < 0 || length > 200)
             cout<<"Wprowadzono niepoprawna wartosc! Wybierz liczbe calkowita z zakresu <0,200> Sprobuj ponownie:\n";
    }while(length < 0 || length > 200);

    factory->get_vehicle(car_choice - 1)->drive(length);
    do {
        cout << "Pomyslnie zrealizowano jazde, czy decydujesz sie na sprzedaz?  \n"
                "1.TAK \n"
                "2.NIE \n"
                "Wprowadz odpowiedni numer opcji\n";
        choice = readInt();
        if(choice != 1 && choice != 2)
            cout<<"Wprowadzono niepoprawny numer, sprobuj ponownie!\n";
    }while( choice != 1 && choice != 2 );

    if(choice == 1 ) {
        Tvehicle* tmp = factory->sell_vehicle(car_choice - 1 );

        try{customer->add_vehicle(tmp);}
        catch(user_action_warning &ex){
            cout<<ex.message<<endl;
            return;
        }
        cout << "Pomyslnie sprzedano pojazd\n";
    }else
        cout<<"Dziekujemy za wizyte i zapraszamy ponownie!!\n";
}

void RepaintVehicle(Tfactory* factory){
    if(factory->get_vehicle_amount() == 0)
        throw user_action_warning("Zaden pojazd nie istnieje, zbuduj nowy przed kolejnymi odwiedzinami lakiernika\n");

    int car_choice;
    string newcolor;
    cout<<"Witaj u lakiernika, wybierz pojazd do przemalowania\n";
    factory->print_vehicles_short();
    cout<<"Wprowadz odpowniedni numer pojazdu:\n";
    do {
        car_choice = readInt();
        if(car_choice <= 0 || car_choice > FACTORY_SIZE || factory->get_vehicle(car_choice - 1) == nullptr )
            cout<<"Wybrano niepoprawny numer, sprobuj ponownie:\n";
    }while(car_choice <= 0 || car_choice > FACTORY_SIZE || factory->get_vehicle(car_choice - 1) == nullptr );

    cout<<"Podaj nowy kolor:\n";
    newcolor = readString();

    Tvehicle_painter::change_color(factory->get_vehicle(car_choice - 1), newcolor);
    cout<<"Pomyslnie przemalowano pojazd,zapraszamy ponownie\n";
}

void BuyCarFromDealer(Tcar_dealer* dealer, TCustomer* customer){
    if(dealer->get_vehicle_amount() == 0)
        throw user_action_warning("Nie posiadamy zadnego pojazdu na stanie.Przepraszamy\n");

    int length, car_choice;
    dealer->print_vehicles();
    cout<<"Wybierz numer interesujacego cie pojazdu: \n";
    do { car_choice = readInt();
         if(car_choice <= 0 || car_choice > FACTORY_SIZE || dealer->get_vehicle(car_choice - 1) == nullptr )
         cout<<"Wybrano niepoprawny numer, sprobuj ponownie!:\n";
    }while(car_choice <= 0 || car_choice > FACTORY_SIZE || dealer->get_vehicle(car_choice - 1) == nullptr );

    cout<<"Wprowadz dlugosc jazdy testowej w km bez jednostki:\n";
    do { length = readInt();
        if(length < 0 || length > 200)
            cout<<"Wprowadzono niepoprawna wartosc! Wybierz liczbe calkowita z zakresu <0,200> Sprobuj ponownie:\n";
    }while(length < 0 || length > 200);

    dealer->get_vehicle(car_choice - 1)->drive(length);
     cout << "Pomyslnie zrealizowano jazde, cena pojazdu to "<<
     dealer->calculate_price(car_choice - 1)<<" zl\n"
     "Czy decydujesz sie na kupno?\n"
     "1.TAK \n"
     "2.NIE \n";
    do { choice = readInt();
         if( choice != 1 && choice != 2)
            cout<<"Wprowadzono niepoprawny numer, sprobuj ponownie!:\n";
    }while( choice != 1 && choice != 2);

    if(choice == 1) {
        Tvehicle* tmp = dealer->sell_vehicle(car_choice - 1 );
        tmp->change_mileage();
        try{customer->add_vehicle(tmp);}
        catch(user_action_warning &ex){
            cout<<ex.message<<endl;
            return;
        }
        cout << "Dziekujemy za zakup i zapraszamy ponownie!!\n";
    }
    else
        cout<<"Dziekujemy za wizyte i zapraszamy ponownie!!\n";
}

void SellCarToDealer(Tcar_dealer* dealer, TCustomer* customer) {
    if (customer->get_vehicle_amount() == 0)
        throw user_action_warning("Nie posiadasz zadnego samochodu do sprzedazy\n");

    int car_choice;
    float price;
    customer->print_vehicles_short();
    cout << "Wybierz numer pojazdu do sprzedania:\n";
    do {
        car_choice = readInt();
        if (car_choice <= 0 || car_choice > FACTORY_SIZE || customer->get_vehicle(car_choice - 1) == nullptr)
            cout << "Wybrano niepoprawny numer, sprobuj ponownie!:\n";
    } while (car_choice <= 0 || car_choice > FACTORY_SIZE || customer->get_vehicle(car_choice - 1) == nullptr);

    price = customer->get_vehicle(car_choice - 1)->calculate_price();
    customer->get_vehicle(car_choice - 1)->set_owner("Komis");
    try{ dealer->add_vehicle(customer->sell_vehicle(car_choice - 1, 20)); }
    catch(user_action_warning &ex){
        cout<<ex.message<<endl;
        return;
    }
    cout << "\nPomyslnie sfinalizowano sprzedaz\n"
            "Zarobiono "<<price<<" zl\n";
}
void BuildVehicle(Tfactory* factory) {
    string color,model;
    int doors, basket_choice, capacity_choice;
    Tvehicle* vehicle_wsk;
    do {
        cout <<
             "Wybierz interesujacy cie pojazd:\n"
             "1: Samochod\n"
             "2: Rower\n"
             "3: Motocykl\n"
             "Wprowadz odpowiedni numer:\n";
        choice = readInt();
        if (choice != 1 && choice != 2 && choice != 3)
            cout << "Podano niepoprawny numer! Sprobuj ponownie\n";
    }while(choice != 1 && choice != 2 && choice != 3);

    cout<<"Podaj model pojazdu:\n";
    model = readString();
    cout<<"Podaj kolor pojazdu:\n";
    color = readString();
    if( choice == 1 ) {
        cout << "Podaj liczbe drzwi:\n";
        do{ doors = readInt();
             if(doors <= 0 || doors > 10)
                 cout<<"Podano niepoprawna liczbe!! Dopuszczalny zakres to <0,10>\n"
                       "Sprobuj ponownie:\n";
        }while(doors <= 0 || doors > 10);
    }
    else if(choice == 2) {
         cout << "Czy wyposazyc rower w koszyk?:\n"
                     "1.TAK \n"
                     "2.NIE \n"
                    "Wprowadz numer opcji:";
            do {basket_choice = readInt();
                 if (basket_choice == 1){
                        cout << "Dostepne rozmiary:\n"
                        "5l , 11l\n"
                        "Podaj wybrana wartosc rozmiaru bez jednostki:\n";
                        do{ capacity_choice = readInt();
                            if(  capacity_choice != 5 && capacity_choice != 11 )
                            cout << "Podano niepoprawna wartosc!! Sprobuj ponownie wprowadzajac wartosc 5 lub 11:\n";
                        }while( capacity_choice != 5 && capacity_choice != 11);
                  }else if(basket_choice != 2)
                        cout << "Podano niepoprawny numer! Sproboj ponownownie:\n";
           }while(basket_choice != 2 && basket_choice != 1);
    }
    switch(choice) {
        case 1:{ Tcar car;
                 vehicle_wsk = &car;
                 try{ factory->add_vehicle( vehicle_wsk->make_vehicle(color,factory->get_brand(),model,doors) ); }
                 catch(user_action_warning &ex){
                 cout<<ex.message<<endl;
                 return;}
                 } break;
        case 2:{ Tbike bike;
                 vehicle_wsk = &bike;
                 try{ factory->add_vehicle(vehicle_wsk->make_vehicle(color, factory->get_brand(), model, capacity_choice)); }
                 catch(user_action_warning &ex){
                 cout<<ex.message<<endl;
                 return;}
                 } break;
        case 3:{ Tmotor_bike motor_bike;
                 vehicle_wsk = &motor_bike;
                 try{factory->add_vehicle( vehicle_wsk->make_vehicle(color,factory->get_brand(),model) ); }
                 catch(user_action_warning &ex){
                 cout<<ex.message<<endl;
                 return;}
                 } break;
        default: break;
    }
    cout<<"Pomyslnie utworzono pojazd\n";
}
void DeleteFactory(Tfactory** tab,Tfactory* factory,int factory_index){
    if(Tfactory::factory_amount == 0)
        throw user_action_warning("Zadna fabryka nie istnieje");

    Tfactory::factory_amount--;
    delete factory;
    tab[factory_index] = nullptr;
    cout<<"Pomyslnie usunieto fabryke";
}

void BicycleWorkshop(){
    int capacity_choice,Bchoice;
    string color,model;
    cout<<"Witaj w warsztacie, mozesz tu skonstruowac rower a nastepnie zmodyfikowac go."<<endl;
    cout<<"Rozpocznij od podania modelu roweru:"<<endl;
    model = readString();
    cout<<"Teraz podaj kolor:"<<endl;
    color = readString();
    auto* Bike = new Tbike(color,"selfmade",model,0,"JA");
    cout<<"Oto twoj utworzony rower:"<<endl;
    Bike->print_vehicle();
    do {
            cout <<
                 "Wybierz co chcesz zrobic z rowerem:\n"
                 "1: Dodaj koszyk\n"
                 "2: Sprawdz numer seryjny koszyka\n"
                 "3: Przemaluj rower\n"
                 "4: Wyswietl specyfikacje roweru\n"
                 "5: Zostaw go w swietym spokoju\n"
                 "Podejmij decyzje:\n";
        Bchoice = readInt();
        if (Bchoice == 1) {
            cout << "Dostepne rozmiary:\n"
                    "5l , 11l\n"
                    "Podaj wybrana wartosc rozmiaru bez jednostki:\n";
            do {
                capacity_choice = readInt();
                if (capacity_choice != 5 && capacity_choice != 11)
                    cout << "Podano niepoprawna wartosc!! Sprobuj ponownie wprowadzajac wartosc 5 lub 11:\n";
            } while (capacity_choice != 5 && capacity_choice != 11);

            Bike->get_basket()->set_capacity(capacity_choice);
            Bike->set_capacity(capacity_choice);
            cout << "Pomyslnie dodano koszyk\n";
        }
        else if(Bchoice == 2){
            if(!Bike->get_basket()->is_basket()) {
                cout << "Rower nie posiada koszyka";
                continue;
            }
            cout << "Numer seryjny to: ";
            Bike->get_basket()->get_serial_number();
        }
        else if(Bchoice == 3){
         cout<<"Podaj nowy kolor: "<<endl;
         color = readString();
         Tvehicle_painter::paint_bike(Bike,color);
         cout << "Pomyslnie przemalowano rower\n";
        } else if(Bchoice == 4) {
            Bike->print_vehicle();
        }
        else if(Bchoice != 5)
            cout << "Podano niepoprawny numer! Sprobuj ponownie\n";
    }while (Bchoice != 5);

    delete Bike;
}

#endif //FUNCTIONS_CPP_H
