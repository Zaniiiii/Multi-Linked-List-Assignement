#include "kargo.h"

using namespace std;

int main()
{
    cout << " #=======================================#" << endl;
    cout << " | TUGAS BESAR MATA KULIAH STRUKTUR DATA |" << endl;
    cout << " |           STRUKTUR 1: KARGO           |" << endl;
    cout << " #=======================================#" << endl;
    cout << " |                  oleh:                |" << endl;
    cout << " |       HAMDAN AZANI (1301213029)       |" << endl;
    cout << " |    ADHISTIANITA S. H. (1301213039)    |" << endl;
    cout << " #=======================================#" << endl;

    cout << endl << " Tekan ENTER untuk melanjutkan...";
    if(cin.get() == '\n'){
        system("cls");
    }

    ortu o;
    anak a;
    adrArmada p = nil;
    adrKargoy q = nil;
    infotypeArmada armada;
    infotypeKargoy kargo;
    int menu1, menu2, n, x;
    string confirm;


    createOrtu(o);
    createAnak(a);

    menu1 = menuUtama();
    while(true){
        system("cls");
        switch(menu1){
            case 0:
                {
                    cout << " ================================" << endl;
                    cout << "  ANDA TELAH KELUAR DARI PROGRAM " << endl;
                    cout << " ================================" << endl;
                    return 0;
                }
            case 1:
                {
                    menu2 = menuTambah();
                    system("cls");
                    switch(menu2){
                        case 0:
                            {
                                menu1 = menuUtama();
                                break;
                            }
                        case 1:
                            {
                                cout << " Jumlah data armada yang akan ditambahkan : ";
                                cin >> n;
                                for(int i = 1; i <= n; i++){
                                    cout << endl << " ======================= Armada " << i << " ========================" << endl;
                                    cout << " ID Armada\t\t\t: ";
                                    cin >> armada.idArmada;
                                    cout << " Asal Armada\t\t\t: ";
                                    getline(cin, armada.asal);
                                    getline(cin, armada.asal);
                                    cout << " Tujuan Armada\t\t\t: ";
                                    getline(cin, armada.tujuan);
                                    cout << " Jenis Armada\t\t\t: ";
                                    getline(cin, armada.jenis);
                                    cout << " Durasi Pengiriman (dalam jam)\t: ";
                                    cin >> armada.durasi;
                                    cout << " Kuota Kargo (dalam kg)\t\t: ";
                                    cin >> armada.kuota;
                                    armada.sisa = armada.kuota;
                                    cout << " =========================================================" << endl << endl;
                                    insertOrtu(o, createInfoBapak(armada));
                                }
                                cout << "                 DATA BERHASIL DITAMBAHKAN!" << endl << endl;
                                break;
                            }
                        case 2:
                            {
                                cout << " Jumlah data kargo yang akan ditambahkan : ";
                                cin >> n;
                                for(int i = 1; i <= n; i++){
                                    cout << endl << " =================== Kargo " << i << " ====================" << endl;
                                    cout << " ID Kargo\t\t: ";
                                    cin >> kargo.idBarang;
                                    cout << " Asal Kargo\t\t: ";
                                    getline(cin, kargo.asal);
                                    getline(cin, kargo.asal);
                                    cout << " Tujuan Kargo\t\t: ";
                                    getline(cin, kargo.tujuan);
                                    cout << " Berat Kargo (dalam kg)\t: ";
                                    cin >> kargo.berat;
                                    cout << " ================================================" << endl << endl;
                                    q = createInfoAnak(kargo);
                                    if(!apakahAdaArmadaKeSana(o, kargo.asal, kargo.tujuan)){
                                        cout << endl << " Tidak ada armada yang sesuai dengan asal dan tujuan kargo" << endl << endl;
                                    } else if(bapakFirst(o) != nil){
                                        showBapakAja(o, a, q);
                                        string masukID;
                                        cout << " Pilih ID Armada untuk kargo\t: ";
                                        cin >>  masukID;
                                        insertAnak(o, a, q, masukID);
                                    } else {
                                        cout << endl << "PERINGATAN: Data armada kosong!" << endl << endl;
                                    }
                                    if(cin.get() == '\n' && i != n){
                                        cout << " Tekan ENTER untuk melanjutkan...";
                                        cin.ignore();
                                        system("cls");
                                    }
                                }

                                break;
                            }
                        default:
                            {
                                cout << " Input tidak tepat. Memulai ulang program." << endl << endl;
                                break;
                            }
                    }
                    break;
                }
            case 2:
                {
                    menu2 = menuEdit();
                    system("cls");
                    switch(menu2){
                        case 0:
                            {
                                menu1 = menuUtama();
                                break;
                            }
                        case 1:
                            {
                                cout << " =======================================" << endl;
                                cout << "          UBAH PENGIRIMAN KARGO         " << endl;
                                cout << " =======================================" << endl << endl;
                                if(anakFirst(a) == nil){
                        cout << endl << " ========== Data kargo kosong ==========" << endl << endl;
                                    break;
                                }
                                cout << " Masukkan ID Kargo: ";
                                cin >> kargo.idBarang;
                                cout << endl << " Menampilkan armada dengan asal dan tujuan yang sama" << endl;
                                q = cariAnak(a, kargo.idBarang);
                                showBapakAja(o, a, q);
                                cout << endl << " Pilih ID Armada: ";
                                cin >> armada.idArmada;
                                if(!apakahAdaArmada(o,a,armada.idArmada)){
                                    cout << " ================= Armada tidak ditemukan ================" << endl << endl;
                                } else {
                                    rubahBapak(o, a, armada.idArmada, kargo.idBarang);
                                    cout << endl << " =======================================" << endl;
                                    cout << "           PERUBAHAN BERHASIL           " << endl;
                                    cout << " =======================================" << endl << endl;
                                }
                                break;
                            }
                        case 2:
                            {
                                cout << " =======================================" << endl;
                                cout << "       PERCEPAT PENGIRIMAN KARGOMU      " << endl;
                                cout << " =======================================" << endl << endl;
                                if(anakFirst(a) == nil){
                                cout << " ========== Data kargo kosong ==========" << endl << endl;
                                    break;
                                }
                                cout << " Masukkan ID Kargo: ";
                                cin >> kargo.idBarang;
                                rubahBapakCepat(o, a, kargo.idBarang);
                                cout << endl << " =======================================" << endl;
                                cout << "           PERUBAHAN BERHASIL           " << endl;
                                cout << " =======================================" << endl << endl;
                                break;
                            }
                        default:
                            {
                                cout << " Input tidak tepat. Memulai ulang program." << endl << endl;
                                break;
                            }
                    }
                    break;
                }
            case 3:
                {
                    menu2 = menuTampil();
                    system("cls");
                    switch(menu2){
                        case 0:
                            {
                                menu1 = menuUtama();
                                break;
                            }
                        case 1:
                            {
                                showBapakAnak(o, a);
                                break;
                            }
                        case 2:
                            {
                                cout << " ===========================================" << endl;
                                cout << "  MENAMPILKAN ARMADA DENGAN KARGO TERBANYAK" << endl;
                                cout << " ===========================================" << endl << endl;
                                x = 0;
                                p = terbanyakAnak(o, a, x);
                                if(p == nil){
                                    cout << " =========== Data armada kosong ============" << endl << endl;
                                    break;
                                } else if(anakFirst(a) == nil){
                                    cout << " ============ Data kargo kosong ============" << endl << endl;
                                    break;
                                }
                                armada = infoBapak(p);
                                cout << " ============== Info Armada ================" << endl;
                                cout << " ID \t\t: " << armada.idArmada << endl;
                                cout << " Jenis \t\t: " << armada.jenis << endl;
                                cout << " Asal \t\t: " << armada.asal << endl;
                                cout << " Tujuan \t: " << armada.tujuan << endl;
                                cout << " Durasi \t: " << armada.durasi << " jam" << endl;
                                cout << " Kuota \t\t: " << armada.kuota << " kg" << endl;
                                cout << " ===========================================" << endl;
                                cout << " Jumlah \t: " << x << " kargo"<< endl;
                                cout << " Bobot Total\t: " << hitungBeratBapak(o, a, armada.idArmada) << " kg"<< endl;
                                cout << " ===========================================" << endl << endl;
                                break;
                            }
                        case 3:
                            {
                                cout << " ============================================" << endl;
                                cout << "  MENAMPILKAN ARMADA DENGAN KARGO TERSEDIKIT" << endl;
                                cout << " ============================================" << endl << endl;
                                x = 0;
                                p = tersedikitAnak(o, a, x);
                                if(p == nil){
                                    cout << " =========== Data armada kosong ============" << endl << endl;
                                    break;
                                }
                                armada = infoBapak(p);
                                cout << " =============== Info Armada ================" << endl;
                                cout << " ID \t\t: " << armada.idArmada  << endl;
                                cout << " Jenis \t\t: " << armada.jenis << endl;
                                cout << " Asal \t\t: " << armada.asal << endl;
                                cout << " Tujuan \t: " << armada.tujuan << endl;
                                cout << " Durasi \t: " << armada.durasi << " jam" << endl;
                                cout << " Kuota \t\t: " << armada.kuota << " kg" <<endl;
                                cout << " ============================================" << endl;
                                cout << " Jumlah \t: " << x << " kargo"<< endl;
                                cout << " Bobot Total\t: " << hitungBeratBapak(o, a, armada.idArmada) << " kg"<< endl;
                                cout << " ============================================" << endl << endl;
                                break;
                            }
                        case 4:
                            {
                                cout << " =====================================================" << endl;
                                cout << "  MENAMPILKAN ARMADA DENGAN ASAL DAN TUJUAN YANG SAMA " << endl;
                                cout << " =====================================================" << endl << endl;
                                if(bapakFirst(o) == nil){
                                    cout << " ================= Data armada kosong ================" << endl << endl;
                                    break;
                                }
                                cout << "  Asal Armada\t: ";
                                getline(cin, kargo.asal);
                                getline(cin, kargo.asal);
                                cout << "  Tujuan Armada\t: ";
                                getline(cin, kargo.tujuan);
                                cout<<endl;
                                q = createInfoAnak(kargo);
                                if(!apakahAdaArmadaKeSana(o, kargo.asal, kargo.tujuan)){
                                    cout << " ================= Tidak ada armada yang menuju ke sana ================" << endl << endl;
                                } else if(q != nil) {
                                    showBapakAja(o, a, q);
                                }
                                cout << endl << " =====================================================" << endl << endl;
                                break;
                            }
                        case 5:
                            {
                                cout << " ====================================" << endl;
                                cout << "  MENAMPILKAN JUMLAH ARMADA SAAT INI " << endl;
                                cout << " ====================================" << endl;
                                cout << "  Jumlah: " << hitungBapak(o) << endl;
                                cout << " ====================================" << endl << endl;
                                break;
                            }
                        case 6:
                            {
                                cout << " =====================================" << endl;
                                cout << "   MENAMPILKAN JUMLAH KARGO SAAT INI " << endl;
                                cout << " =====================================" << endl;
                                cout << "  Jumlah: " << hitungAnak(a) << endl;
                                cout << " =====================================" << endl << endl;
                                break;
                            }
                        case 7:
                            {
                                cout << " ======================================" << endl;
                                cout << "  MENAMPILKAN JUMLAH KARGO PADA ARMADA " << endl;
                                cout << " ======================================" << endl << endl;
                                if(bapakFirst(o) == nil){
                                cout << " ========= Data armada kosong =========" << endl << endl;
                                    break;
                                }
                                cout << " Masukkan ID Armada\t: ";
                                cin >> armada.idArmada;
                                cout << " Jumlah\t\t\t: " << hitungAnaknyaBapak(o, a, armada.idArmada) << endl;
                                cout << endl << " =======================================" << endl;
                                break;
                            }
                        default:
                            {
                                cout << " Input tidak tepat. Memulai ulang program." << endl << endl;
                                break;
                            }
                    }
                    break;
                }
            case 4:
                {
                    menu2 = menuHapus();
                    system("cls");
                    switch(menu2){
                        case 0:
                            {
                                menu1 = menuUtama();
                                break;
                            }
                        case 1:
                            {
                                cout << " ===============================" << endl;
                                cout << "  BATALKAN KEBERANGKATAN ARMADA " << endl;
                                cout << " ===============================" << endl << endl;
                                if(bapakFirst(o) == nil){
                                cout << " ====== Data armada kosong =====" << endl << endl;
                                    break;
                                }
                                cout << " ID Armada\t: ";
                                cin >> armada.idArmada;
                                p = cariBapak(o, armada.idArmada);
                                if (p == nil){
                                    cout << endl << "   Data Armada tidak ditemukan " << endl << endl;
                                }else {
                                    hapusBapak(o, a, armada.idArmada);
                                    cout << endl << " ===============================" << endl;
                                    cout << "      DATA BERHASIL DIHAPUS!    " << endl;
                                    cout << " ===============================" << endl << endl;
                                }
                                break;
                            }
                        case 2:
                            {
                                cout << " ================================" << endl;
                                cout << "     BATALKAN PENGIRIMAN KARGO" << endl;
                                cout << " ================================" << endl << endl;
                                if(anakFirst(a) == nil){
                                cout << " ======= Data kargo kosong ======" << endl << endl;
                                    break;
                                }
                                cout << " ID Kargo\t: ";
                                cin >> kargo.idBarang;
                                q = cariAnak(a, kargo.idBarang);
                                if (q== nil){
                                    cout << endl << " == Data kargo tidak ditemukan ==" << endl << endl;
                                } else {
                                    hapusAnak(o, a, kargo.idBarang);
                                    cout << endl << " ===============================" << endl;
                                    cout << "      DATA BERHASIL DIHAPUS!    " << endl;
                                    cout << " ===============================" << endl << endl;
                                }
                                break;
                            }
                        default:
                            {
                                cout << " Input tidak tepat. Memulai ulang program." << endl << endl;
                                break;
                            }
                    }
                    break;
                }
            default:
                {
                    cout << " Input tidak tepat. Mohon ulang kembali." << endl << endl;
                    break;
                }
        }
        if(menu2 != 0){
            cout << " Kembali ke menu utama? (Y/N)\n > ";
            cin >> confirm;
            cout << endl;
            if(confirm == "Y" || confirm == "y"){
                system("cls");
                menu1 = menuUtama();
            } else {
                menu1 = 0;
            }
        }
    }

    return 0;
}
