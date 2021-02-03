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
    ~Tacquisto(){
      //
    }
    void stampa() const{
        cout << nomeProdotto;
        switch(tipoProdotto){
            case 0:{
                cout << " (MUSICA) ";
                break;
            }
            case 1:{
                cout << " (LIBRI) ";
                break;
            }
            case 2:{
                cout << " (TECH) ";
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
    ~Tnodo(){
      //
    }
    void stampa() const{
        dato.stampa();
    }
} Tnodo;

int random(int max, int min);
void newAcquisto(Tacquisto* a);
void addAcquisto(Tnodo* neg[], int dim, Tacquisto a);
void stampaNegozi(Tnodo* neg[], int dim);
int contaAcquisti(Tnodo* neg[], int dim, Tprodotto tp);


int main() {
    Tnodo* negozio[DIM];
    for (int i=0; i<DIM; i++) { negozio[i] = NULL; }
    Tacquisto o;
    for (int i=0; i<5; i++) {
        newAcquisto(&o); 
        addAcquisto(negozio, DIM, o); 
    }
    stampaNegozi(negozio, DIM);
    /*
    cout << contaAcquisti(negozio, DIM, LIBRI);
    return 0;
  */
 system("PAUSE");
}

int random(int max, int min){
  return rand() % (max - min + 1) + min;
}

void newAcquisto(Tacquisto* a){
  //tipoProdotto
  switch(random(2, 0)){
      case 0:{
          a->tipoProdotto = MUSICA;
          break;
      }
      case 1:{
          a->tipoProdotto = LIBRI;
          break;
      }
      case 2:{
          a->tipoProdotto = TECH;
          break;
      }
  }
  //quantita
  do{
    cout << "Quantità: ";
    cin >> a->quantita;
  }while(a->quantita < 1 || a->quantita > 10);
  //prezzo
  a->prezzo = (random(9999, 500)/100.00);
  //nomeProdotto
  cout << "Nome prodotto: ";
  cin >> a->nomeProdotto;
}

void addAcquisto(Tnodo* neg[], int dim, Tacquisto a){
  int x = 0;//random(dim-1, 0);
  Tnodo* q = new Tnodo();
  q->dato = a;
  q->next = neg[x];
  neg[x] = q;
}

void stampaNegozi(Tnodo* neg[], int dim){
  int i;
  for(i = 0; i<dim-1; i++){
    Tnodo* q = neg[i];
    while(q != NULL){
      q->stampa();
      cout << endl;
      q = q->next;
    }
    cout << endl;
  }
}