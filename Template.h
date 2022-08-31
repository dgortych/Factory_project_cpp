#ifndef GORTYCHDAMIAN_ETAP2_TEMPLATE_H
#define GORTYCHDAMIAN_ETAP2_TEMPLATE_H
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct user_action_warning{
    string message;
    explicit user_action_warning(string msg) : message(move(msg)) {}
};

constexpr int SIZE = 10;

template<typename T> class Conteiner;
template<typename T>
ostream & operator<<(ostream &screen,const Conteiner<T> &container);

template<typename T>
class Conteiner{

    T* tab;
    int tab_size;

public:
    T & operator[](int index);
    friend ostream & operator<<<>(ostream &screen,const Conteiner<T> &container);

    explicit Conteiner(int size = SIZE);
    void add(T item);
    void remove(){ delete[] tab;}
    void resize(int newSize);
    void clear();
    int size() const { return tab_size; }
};

template<typename T>
T & Conteiner<T>::operator[](int index){
    if(index < 0 ) return tab[tab_size + index];
    return tab[index];
}

template<typename T>
ostream & operator<<(ostream &screen,const Conteiner<T> &container){
    for(int i = 0; i < container.tab_size; ++i)
        screen<<container.tab[i]<<" ";
    return screen;
}

template<typename T>
Conteiner<T>::Conteiner(int size) : tab_size(size){
     tab = new T[tab_size];
     clear();
}

template<typename T>
void Conteiner<T>::clear(){
    for(int i =0; i<tab_size; ++i)
        tab[i] = 0;
}
template<typename T>
void Conteiner<T>::add(T item){
    if(tab[tab_size - 1] != 0)
        cout<<"pelna";
    for(int i = 0; i < tab_size;++i){
        if(tab[i] == 0 ){
            tab[i] = item;
            break;
        }
    }
}
template<typename T>
void Conteiner<T>::resize(int newSize){
    T* newArr = new T[newSize];
    for(int i = 0; i < newSize;++i)
        if(i < tab_size )
            newArr[i]=tab[i];
        else
            newArr[i]=0;

    tab_size = newSize;
    delete [] tab;
    tab = newArr;
}


#endif //GORTYCHDAMIAN_ETAP2_TEMPLATE_H
