// Online C++ compiler to run C++ program online
#include <iostream>
#include <cstdlib>
#define DIM 2
using namespace std;

typedef enum Tprodotto { MUSICA, LIBRI, TECH } Tprodotto;
typedef struct Tacquisto{
    char nomeProdotto[20];
    unsigned int quantita;
    float prezzo;
    Tprodotto tipoProdotto;
    Tacquisto () {
        nomeProdotto[0] = '\0';
        quantita = 0;
        prezzo = 0.0;
        tipoProdotto = TECH;
    }
    void stampa() const{
        cout << nomeProdotto;
        switch(tipoProdotto){
            case 0:{
                cout << " (MUSICA) ";
                break;
            }
            case 1:{
                cout << " (LIBRI) "
                break;
            }
            case 2:{
                cout << " (TECH) "
                break;
            }
        }
        cout << "QTA=" << quantita;
        cout << "prezzo=" << prezzo;
    }
} Tacquisto;
typedef struct Tnodo {
    Tacquisto dato;
    Tnodo* next;
    Tnodo () {
        dato = Tacquisto();
        next = NULL;
    }
    Tnodo (Tacquisto a, Tnodo* n) {
        dato = a;
        next = n;
    }
    void stampa() const{
        dato.stampa();
    }
} Tnodo;


int main() {
    Tnodo* negozio[DIM];
    for (int i=0; i<DIM; i++) { negozio[i] = NULL; }
    Tacquisto o;
    for (int i=0; i<5; i++) {newAcquisto(&o); addAcquisto(negozio, DIM, o); }
    stampaNegozi(negozio, DIM);
    cout << contaAcquisti(negozio, DIM, LIBRI);
    return 0;
}