#include <iostream>
#include <string>
using namespace std;

// Deklarasi double linked list
struct DataFilm {
    string namaFilm;
    int durasi;
    int harga;
    DataFilm* kembali;
    DataFilm* lanjut;
};

DataFilm* kepala = NULL, * ekor = NULL, * saatIni = NULL, * nodeBaru = NULL, * hapus = NULL, * setelahNode = NULL;

// Membuat Double Linked List
void createDoubleLinkedList(string data[3]) {
    nodeBaru = new DataFilm();
    nodeBaru->namaFilm = data[0];
    nodeBaru->durasi = stoi(data[1]);
    nodeBaru->harga = stoi(data[2]);
    nodeBaru->kembali = NULL;
    nodeBaru->lanjut = NULL;

    if (kepala == NULL) {
        kepala = nodeBaru;
        ekor = nodeBaru;
    }
    else {
        ekor->lanjut = nodeBaru;
        nodeBaru->kembali = ekor;
        ekor = nodeBaru;
    }
}

// Menghitung Double Linked List
int countDoubleLinkedList()
{
    if (kepala == NULL) {
        return 0;
    }
    else {
        saatIni = kepala;
        int jumlah = 0;
        while (saatIni != NULL) {
            jumlah++;
            //step
            saatIni = saatIni->lanjut;
        }
        return jumlah;
    }
}


// Remove First
void removeFirst()
{
    if (kepala == NULL) {
        cout << "Double Linked List belum dibuat!!!";
    }
    else {
        hapus = kepala;
        kepala = kepala->lanjut;
        if (kepala != NULL) {
            kepala->kembali = NULL;
        }
        else {
            ekor = NULL;
        }
        delete hapus;
    }
}

// Remove Last
void removeLast()
{
    if (kepala == NULL) {
        cout << "Double Linked List belum dibuat!!!";
    }
    else {
        hapus = ekor;
        ekor = ekor->kembali;
        if (ekor != NULL) {
            ekor->lanjut = NULL;
        }
        else {
            kepala = NULL;
        }
        delete hapus;
    }
}

// Remove Middle
void removeMiddle(int posisi) {
    if (kepala == NULL) {
        cout << "Double Linked List belum dibuat!!!";
    }
    else {
        if (posisi == 1 || posisi == countDoubleLinkedList()) {
            cout << "Posisi bukan posisi tengah!!" << endl;
        }
        else if (posisi < 1 || posisi > countDoubleLinkedList()) {
            cout << "Posisi diluar jangkauan!!" << endl;
        }
        else {
            int nomor = 1;
            saatIni = kepala;
            while (nomor < posisi - 1) {
                saatIni = saatIni->lanjut;
                nomor++;
            }
            hapus = saatIni->lanjut;
            setelahNode = hapus->lanjut;
            saatIni->lanjut = setelahNode;
            setelahNode->kembali = saatIni;
            delete hapus;
        }
    }
}

// Print Double Linked List
void printDoubleLinkedList()
{
    if (kepala == NULL) {
        cout << "Double Linked List belum dibuat!!!";
    }
    else {
        cout << "Jumlah Data : " << countDoubleLinkedList() << endl;
        cout << "Isi Data : " << endl;
        saatIni = kepala;
        while (saatIni != NULL) {
            // print
            cout << "Nama Film : " << saatIni->namaFilm << endl;
            cout << "Durasi : " << saatIni->durasi << " menit" << endl;
            cout << "Harga : Rp. " << saatIni->harga << endl;
            cout << "\n";
            //step
            saatIni = saatIni->lanjut;
        }
    }
}

int main() {
    string newData[3] = { "Vina", "120", "50000" };
    createDoubleLinkedList(newData);

    newData[0] = "Dilan 1945";
    newData[1] = "90";
    newData[2] = "35000";
    createDoubleLinkedList(newData);

    newData[0] = "Laskar Pelangi";
    newData[1] = "100";
    newData[2] = "45000";
    createDoubleLinkedList(newData);

    newData[0] = "The Architecture of Love";
    newData[1] = "110";
    newData[2] = "55000";
    createDoubleLinkedList(newData);

    printDoubleLinkedList();

    removeMiddle(2);
    printDoubleLinkedList();

    removeFirst();
    printDoubleLinkedList();

    removeLast();
    printDoubleLinkedList();

    return 0;
}