#ifndef KARGO_H_INCLUDED
#define KARGO_H_INCLUDED
#include <iostream>
#include <string>

#define infoBapak(p) p-> infoBapak
#define infoAnak(p) p -> infoAnak
#define bapakku(p) p -> bapakku
#define bapakNext(p) p-> bapakNext
#define anakNext(p) p-> anakNext
#define anakFirst(a) ((a).anakFirst)
#define bapakFirst(b) ((b).bapakFirst)
#define nil NULL

using namespace std;

struct infotypeArmada{
    string idArmada;
    string asal;
    string tujuan;
    string jenis;
    int durasi;
    int kuota;
    int sisa;
};

struct infotypeKargoy{
    string idBarang;
    string asal;
    string tujuan;
    int berat;
};

typedef struct armada *adrArmada;

struct armada{
    infotypeArmada infoBapak;
    adrArmada bapakNext;
};

typedef struct kargoy *adrKargoy;

struct kargoy{
    infotypeKargoy infoAnak;
    adrKargoy anakNext;
    adrArmada bapakku;
};

struct ortu{
    adrArmada bapakFirst;
};

struct anak{
    adrKargoy anakFirst;
};

void createOrtu(ortu &o);
void createAnak(anak &a);
adrArmada createInfoBapak(infotypeArmada baru);
adrKargoy createInfoAnak(infotypeKargoy baru);
void insertOrtu(ortu &o, adrArmada p); //insertlast
void insertAnak(ortu o, anak &a, adrKargoy q,string idArmada); //insertlast
adrArmada cariBapak(ortu o, string idArmada);
adrKargoy cariAnak(anak a, string idBarang);
adrArmada cariBapaknyaAnak(anak a, ortu o, string idBarang);
void showBapakAnak(ortu o, anak a);
void showAnaknyaBapak(ortu o, anak a, string idArmada);
void hubunginBapakAnak(ortu o, adrKargoy q, string idArmada);
void hapusBapak(ortu &o, anak &a, string idArmada);
void hapusAnak(ortu o, anak &a, string idBarang);
int cariPalingPanjang(ortu o, anak a, string x);
int hitungBapak(ortu o);
int hitungAnak(anak a);
int hitungAnaknyaBapak(ortu o, anak a, string idArmada);
int hitungBeratBapak(ortu o, anak a, string idArmada);
adrArmada terbanyakAnak(ortu o, anak a, int &jumlah);
adrArmada tersedikitAnak(ortu o, anak a, int &jumlah);
bool cekPunyaAnak(ortu o, anak a, string idArmada);
bool apakahAdaArmada(ortu o, anak a, string idArmada);
bool apakahAdaKargo(ortu o, anak a);
void showBapakAja(ortu o, anak a, adrKargoy q);
void rubahBapak(ortu o, anak a, string idArmada, string idBarang);
void rubahBapakCepat(ortu o, anak a, string idBarang);
bool apakahAdaArmadaKeSana(ortu o, string asal, string tujuan);
int menuUtama();
int menuTambah();
int menuEdit();
int menuHapus();
int menuTampil();

#endif // KARGO_H_INCLUDED
