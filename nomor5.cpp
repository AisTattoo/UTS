#include <iostream>
using namespace std;

// Deklarasi struktur untuk Circular Single Linked List
struct dataFilm{
string namaFilm;
int durasi;
int harga;

dataFilm *next;
};

dataFilm* kepala, *ekor, *nodeBaru, *saatIni, *hapus;

// Membuat Circular Single Linked List
void createCircularSingleLinkedList(string dataBaru[3]){

kepala = new dataFilm();
kepala->namaFilm = dataBaru[0];
kepala->durasi = stoi(dataBaru[1]);
kepala->harga = stoi(dataBaru[2]);
ekor = kepala;
ekor->next = kepala;

}

// add first
void addFirst( string data[3] ){
if( kepala == NULL ){
cout << "Buat Linked List dulu!!" << endl;
}else{
nodeBaru = new dataFilm();
nodeBaru->namaFilm = data[0];
nodeBaru->durasi = stoi(data[1]);
nodeBaru->harga = stoi(data[2]);
nodeBaru->next = kepala;
ekor->next = nodeBaru;
kepala = nodeBaru;
}
}

// add Last
void addLast( string data[3] ){
if( kepala == NULL ){
cout << "Buat Linked List dulu!!" << endl;
}else{
nodeBaru = new dataFilm();
nodeBaru->namaFilm = data[0];
nodeBaru->durasi = stoi(data[1]);
nodeBaru->harga = stoi(data[2]);
nodeBaru->next = kepala;
ekor->next = nodeBaru;
ekor = nodeBaru;
}
}

// add Middle
void addMiddle(string data[3], int posisi)
{
if( kepala == NULL ){
cout << "Buat Linked List dulu!!" << endl;
}else{
if( posisi == 1 ){
cout << "Posisi satu bukan posisi tengah!!!" << endl;
}else{
nodeBaru = new dataFilm();
nodeBaru->namaFilm = data[0];
nodeBaru->durasi = stoi(data[1]);
nodeBaru->harga = stoi(data[2]);
// tranversing
  int nomor = 1;
  saatIni = kepala;
  while (nomor < posisi - 1)
  {
    saatIni = saatIni->next;
    nomor++;
  }
  nodeBaru->next = saatIni->next;
  saatIni->next = nodeBaru;
}
}
}

void printCircular()
{
if( kepala == NULL ){
cout << "Buat Linked List dulu!!" << endl;
}else{
cout << "Data Film " << endl;
cout << "_________________________________________________________________" << endl;
cout << "| Nama Film\t\t\t| Durasi\t\t| Harga\t|" << endl;
cout << "_________________________________________________________________" << endl;
saatIni = kepala;
while (saatIni->next != kepala)
{
// print
cout << "| " << saatIni->namaFilm << "\t\t\t| " << saatIni->durasi << "\t\t\t| " << saatIni->harga << "|" << endl;
saatIni = saatIni->next;
}
cout << "| " << saatIni->namaFilm << "\t\t\t| " << saatIni->durasi << "\t\t\t| " << saatIni->harga << "|" << endl;
cout << "_________________________________________________________________" << endl;
}
}

int main(){
string dataBaru[4] = {"Endgame", "181", "125000"};
createCircularSingleLinkedList(dataBaru);

printCircular();

string data[4] = {"Spiderman", "148", "100000"};
addFirst(data);

printCircular();

string data2[4] = {"Interstellar", "169", "175000"};
addLast(data2);

printCircular();

string data3[4] = {"Inception", "148", "190000"};
addMiddle(data3, 5);

printCircular();
}