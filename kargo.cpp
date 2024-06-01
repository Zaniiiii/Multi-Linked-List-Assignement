#include "mll.h"

void createOrtu(ortu &o){
    bapakFirst(o) = nil;
}

void createAnak(anak &a){
    anakFirst(a) = nil;
}

adrArmada createInfoBapak(infotypeArmada baru){
    adrArmada p = new armada;
    infoBapak(p) = baru;
    bapakNext(p) = nil;
    return p;
}

adrKargoy createInfoAnak(infotypeKargoy baru){
    adrKargoy p = new kargoy;
    infoAnak(p) = baru;
    anakNext(p) = nil;
    bapakku(p) = nil;
    return p;
}

void insertOrtu(ortu &o, adrArmada p){
    if (bapakFirst(o) == nil){
        bapakFirst(o) = p;
    } else{
        adrArmada q = bapakFirst(o);
        while (bapakNext(q)!=nil){
            q = bapakNext(q);
        }
        bapakNext(q) = p;
    }
} //insertlast

void insertAnak(ortu o,anak &a, adrKargoy q, string idArmada){
    if (anakFirst(a) == nil){
        anakFirst(a) = q;
    } else{
        adrKargoy p = anakFirst(a);
        while (anakNext(p) != nil){
            p = anakNext(p);
        }
        anakNext(p) = q;
    }
    hubunginBapakAnak(o, q, idArmada);
} //insertlast

void hubunginBapakAnak(ortu o, adrKargoy q, string idArmada){
    if (bapakFirst(o) != nil){
        adrArmada p = cariBapak(o, idArmada);
        if(p != nil && q != nil){
            if(infoBapak(p).sisa >= infoAnak(q).berat){
                bapakku(q) = p;
                infoBapak(p).sisa = infoBapak(p).sisa - infoAnak(q).berat;
                cout << endl << " Data kargo berhasil ditambahkan!" << endl << endl;
            } else{
                cout << endl << " Muatan armada telah penuh" << endl << endl;
            }
        }
    } else {
        cout << endl << " Data armada tidak ditemukan" << endl << endl;
    }
}

adrArmada cariBapak(ortu o, string idArmada){
    if (bapakFirst(o)==nil){
        cout<<" Tidak ada data armada"<<endl;
        return nil;
    } else {
        adrArmada p = bapakFirst(o);
        while(p!= nil && infoBapak(p).idArmada != idArmada){
            p = bapakNext(p);
        }
        return p;
    }
}
adrKargoy cariAnak(anak a, string idBarang){
    if (anakFirst(a) == nil){
        cout<<" Tidak ada data barang"<<endl;
        return nil;
    } else{
        adrKargoy p = anakFirst(a);
        while(p!= nil && infoAnak(p).idBarang != idBarang){
            p = anakNext(p);
        }
        return p;
    }
}

adrArmada cariBapaknyaAnak(anak a, ortu o, string idBarang){
    if(anakFirst(a) == nil){
        cout<<" Tidak ada data barang"<<endl;
        return nil;
    } else if(bapakFirst(o) == nil){
        cout<<" Tidak ada data armada";
        return nil;
    } else {
        adrKargoy p = cariAnak(a, idBarang);
        adrArmada q = bapakku(p);
        return q;
    }
}

int cariPalingPanjang(ortu o, anak a, string x){
    int gede = 0;
    int n = 0;
    string tes;
    if (x == "idarmada"){
        adrArmada p = bapakFirst(o);
        while(p!= nil){
            n = infoBapak(p).idArmada.length();
            if(n > gede){
                gede = n;
            }
            p = bapakNext(p);
        }
        return gede/8;
    } else if (x == "jenisarmada"){
        adrArmada p = bapakFirst(o);
        while(p!= nil){
            n = infoBapak(p).jenis.length();
            if(n > gede){
                gede = n;
            }
            p = bapakNext(p);
        }
        return gede/8;
    } else if (x == "asalarmada"){
        adrArmada p = bapakFirst(o);
        while(p!= nil){
            n = infoBapak(p).asal.length();
            if(n > gede){
                gede = n;
            }
            p = bapakNext(p);
        }
        if(gede == 6||gede == 7){
            gede += 2;
        }
        return gede/8;
    } else if (x == "tujuanarmada"){
        adrArmada p = bapakFirst(o);
        while(p!= nil){
            n = infoBapak(p).tujuan.length();
            if(n > gede){
                gede = n;
            }
            p = bapakNext(p);
        }
        return gede/8;
    } else if (x == "idkargo"){
        adrKargoy q = anakFirst(a);
        while(q!= nil){
            n = infoAnak(q).idBarang.length();
            if(n > gede){
                gede = n;
            }
            q = anakNext(q);
        }
        return gede/8;
    } else if (x == "asalkargo"){
        adrKargoy q = anakFirst(a);
        while(q!= nil){
            n = infoAnak(q).asal.length();
            if(n > gede){
                gede = n;
            }
            q = anakNext(q);
        }
        return gede/8;
    } else if (x == "tujuankargo"){
        adrKargoy q = anakFirst(a);
        while(q!= nil){
            n = infoAnak(q).tujuan.length();
            if(n > gede){
                gede = n;
            }
            q = anakNext(q);
        }
        return gede/8;
    } else if (x =="kuotaarmada"){
        adrArmada p = bapakFirst(o);
        while(p!= nil){
            tes = to_string(infoBapak(p).kuota);
            n = tes.length() + 6;
            if(n > gede){
                gede = n;
            }
            p = bapakNext(p);
        }
        return gede/8;
    } else if (x =="durasiarmada"){
        adrArmada p = bapakFirst(o);
        while(p!= nil){
            tes = to_string(infoBapak(p).durasi);
            n = tes.length() + 6;
            if(n > gede){
                gede = n;
            }
            p = bapakNext(p);
        }
        return gede/8;
    } else if (x == "beratkargo"){
        adrKargoy q = anakFirst(a);
        while(q!= nil){
            tes = to_string(infoAnak(q).berat);
            n = tes.length() + 6;
            if(n > gede){
                gede = n;
            }
            q = anakNext(q);
        }
        return gede/8;
    }
}

bool cekPunyaAnak(ortu o, anak a, string idArmada){
    adrArmada p = cariBapak(o, idArmada);
    adrKargoy q = anakFirst(a);
    while(q!=nil){
        if (bapakku(q)==p){
            return true;
        }
        q = anakNext(q);
    }
    return false;
}

bool apakahAdaKargo(ortu o, anak a){
    adrKargoy p = anakFirst(a);
    while(p!=nil){
        if(bapakku(p)!= nil){
            return true;
        }
        p = anakNext(p);
    }
    return false;
}
void showBapakAnak(ortu o,anak a){
    adrArmada p = bapakFirst(o);
    adrKargoy q = anakFirst(a);
    if(p == nil){
        cout<<" #-------------------------------------#"<<endl;
        cout<<" |          Data Armada Kosong         #"<<endl;
        cout<<" #-------------------------------------#"<<endl;
    } else{
        cout<<" #-------------------------------------#--------------------------------------#"<<endl;
        cout<<" |               Armada                |                Kargo                 |"<<endl;
        cout<<" #-------------------------------------#--------------------------------------#"<<endl;
        while (p!=nil){
            int n = hitungAnaknyaBapak(o, a, infoBapak(p).idArmada);
            q = anakFirst(a);
            int i = 1;
            bool cek = cekPunyaAnak(o,a,infoBapak(p).idArmada);
            if(!cek){
                auto durasi = std::to_string(infoBapak(p).durasi);
                durasi = durasi + " jam";
                auto kuota = std::to_string(infoBapak(p).kuota);
                kuota = kuota + " kg";
                auto sisa = std::to_string(infoBapak(p).sisa);
                sisa = sisa + " kg";
                cout<<" | ID Armada\t: ";
                printf("%-20s", infoBapak(p).idArmada.c_str());
                cout<<" | Tidak mempunyai kargo";
                printf("%-16s");
                cout<<"|"<<endl;
                cout<<" | Jenis\t: ";
                printf("%-20s", infoBapak(p).jenis.c_str());
                cout<<" |";
                printf("%-38s");
                cout<<"|"<<endl;
                cout<<" | Asal\t\t: ";
                printf("%-20s", infoBapak(p).asal.c_str());
                cout<<" |";
                printf("%-38s");
                cout<<"|"<<endl;
                cout<<" | Tujuan\t: ";
                printf("%-20s", infoBapak(p).tujuan.c_str());
                cout<<" |";
                printf("%-38s");
                cout<<"|"<<endl;
                cout<<" | Durasi\t: ";
                printf("%-20s", durasi.c_str());
                cout<<" |";
                printf("%-38s");
                cout<<"|"<<endl;
                cout<<" | Kuota\t: ";
                printf("%-20s", kuota.c_str());
                cout<<" |";
                printf("%-38s");
                cout<<"|"<<endl;
                cout<<" | Sisa kuota\t: ";
                printf("%-20s", sisa.c_str());
                cout<<" |";
                printf("%-38s");
                cout<<"|"<<endl;
                cout<<" #-------------------------------------#--------------------------------------#"<<endl;
            }
            while(q!=nil){
                if (bapakku(q) == p && i == 1 && i == n){
                    auto durasi = std::to_string(infoBapak(p).durasi);
                    durasi = durasi + " jam";
                    auto kuota = std::to_string(infoBapak(p).kuota);
                    kuota = kuota + " kg";
                    auto berat = std::to_string(infoAnak(q).berat);
                    berat = berat + " kg";
                    auto sisa = std::to_string(infoBapak(p).sisa);
                    sisa = sisa + " kg";
                    cout<<" | ID Armada\t: ";
                    printf("%-20s", infoBapak(p).idArmada.c_str());
                    cout<<" | Id Kargo\t: ";
                    printf("%-19s", infoAnak(q).idBarang.c_str());
                    cout<<" |"<<endl;
                    cout<<" | Jenis\t: ";
                    printf("%-20s", infoBapak(p).jenis.c_str());
                    cout<<" | Asal\t\t: ";
                    printf("%-19s", infoAnak(q).asal.c_str());
                    cout<<" |"<<endl;
                    cout<<" | Asal\t\t: ";
                    printf("%-20s", infoBapak(p).asal.c_str());
                    cout<<" | Tujuan\t\t: ";
                    printf("%-19s", infoAnak(q).tujuan.c_str());
                    cout<<" |"<<endl;
                    cout<<" | Tujuan\t: ";
                    printf("%-20s", infoBapak(p).tujuan.c_str());
                    cout<<" | Berat\t\t: ";
                    printf("%-19s", berat.c_str());
                    cout<<" |"<<endl;
                    cout<<" | Durasi\t: ";
                    printf("%-20s", durasi.c_str());
                    cout<<" |";
                    printf("%-38s");
                    cout<<"|"<<endl;
                    cout<<" | Kuota\t: ";
                    printf("%-20s", kuota.c_str());
                    cout<<" |";
                    printf("%-38s");
                    cout<<"|"<<endl;
                    cout<<" | Sisa Kuota\t: ";
                    printf("%-20s", sisa.c_str());
                    cout<<" |";
                    printf("%-38s");
                    cout<<"|"<<endl;
                    cout<<" #-------------------------------------#--------------------------------------#"<<endl;
                    i++;
                } else if (bapakku(q) == p && i == 1){
                    auto durasi = std::to_string(infoBapak(p).durasi);
                    durasi = durasi + " jam";
                    auto kuota = std::to_string(infoBapak(p).kuota);
                    kuota = kuota + " kg";
                    auto berat = std::to_string(infoAnak(q).berat);
                    berat = berat + " kg";
                    auto sisa = std::to_string(infoBapak(p).sisa);
                    sisa = sisa + " kg";
                    cout<<" | ID Armada\t: ";
                    printf("%-20s", infoBapak(p).idArmada.c_str());
                    cout<<" | Id Kargo\t: ";
                    printf("%-19s", infoAnak(q).idBarang.c_str());
                    cout<<" |"<<endl;
                    cout<<" | Jenis\t: ";
                    printf("%-20s", infoBapak(p).jenis.c_str());
                    cout<<" | Asal\t\t: ";
                    printf("%-19s", infoAnak(q).asal.c_str());
                    cout<<" |"<<endl;
                    cout<<" | Asal\t\t: ";
                    printf("%-20s", infoBapak(p).asal.c_str());
                    cout<<" | Tujuan\t\t: ";
                    printf("%-19s", infoAnak(q).tujuan.c_str());
                    cout<<" |"<<endl;
                    cout<<" | Tujuan\t: ";
                    printf("%-20s", infoBapak(p).tujuan.c_str());
                    cout<<" | Berat\t\t: ";
                    printf("%-19s", berat.c_str());
                    cout<<" |"<<endl;
                    cout<<" | Durasi\t: ";
                    printf("%-20s", durasi.c_str());
                    cout<<" |";
                    printf("%-38s");
                    cout<<"|"<<endl;
                    cout<<" | Kuota\t: ";
                    printf("%-20s", kuota.c_str());
                    cout<<" |";
                    printf("%-38s");
                    cout<<"|"<<endl;
                    cout<<" | Sisa Kuota\t: ";
                    printf("%-20s", sisa.c_str());
                    cout<<" |";
                    printf("%-38s");
                    cout<<"|"<<endl;
                    cout<<" |                                     #--------------------------------------|"<<endl;
                    i++;
                } else if (bapakku(q) == p && i == n){
                    auto durasi = std::to_string(infoBapak(p).durasi);
                    durasi = durasi + " jam";
                    auto kuota = std::to_string(infoBapak(p).kuota);
                    kuota = kuota + " kg";
                    auto berat = std::to_string(infoAnak(q).berat);
                    berat = berat + " kg";
                    auto sisa = std::to_string(infoBapak(p).sisa);
                    sisa = sisa + " kg";
                    cout<<" |";
                    printf("%-37s");
                    cout<<"| ID Kargo\t: ";
                    printf("%-19s", infoAnak(q).idBarang.c_str());
                    cout<<" |"<<endl<<" |";
                    printf("%-37s");
                    cout<<"| Asal\t\t: ";
                    printf("%-19s", infoAnak(q).asal.c_str());
                    cout<<" |"<<endl<<" |";
                    printf("%-37s");
                    cout<<"| Tujuan\t\t: ";
                    printf("%-19s", infoAnak(q).tujuan.c_str());
                    cout<<" |"<<endl<<" |";
                    printf("%-37s");
                    cout<<"| Berat\t\t: ";
                    printf("%-19s", berat.c_str());
                    cout<<" |"<<endl<<" |";
                    printf("%-37s");
                    cout<<"|";
                    printf("%-38s");
                    cout<<"|"<<endl;
                    cout<<" |";
                    printf("%-37s");
                    cout<<"|";
                    printf("%-38s");
                    cout<<"|"<<endl;
                    cout<<" |";
                    printf("%-37s");
                    cout<<"|";
                    printf("%-38s");
                    cout<<"|"<<endl;
                    cout<<" #-------------------------------------#--------------------------------------#"<<endl;
                    i++;
                } else if(bapakku(q) == p){
                    auto durasi = std::to_string(infoBapak(p).durasi);
                    durasi = durasi + " jam";
                    auto kuota = std::to_string(infoBapak(p).kuota);
                    kuota = kuota + " kg";
                    auto berat = std::to_string(infoAnak(q).berat);
                    berat = berat + " kg";
                    auto sisa = std::to_string(infoBapak(p).sisa);
                    sisa = sisa + " kg";
                    cout<<" |";
                    printf("%-37s");
                    cout<<"| ID Kargo\t: ";
                    printf("%-19s", infoAnak(q).idBarang.c_str());
                    cout<<" |"<<endl<<" |";
                    printf("%-37s");
                    cout<<"| Asal\t\t: ";
                    printf("%-19s", infoAnak(q).asal.c_str());
                    cout<<" |"<<endl<<" |";
                    printf("%-37s");
                    cout<<"| Tujuan\t\t: ";
                    printf("%-19s", infoAnak(q).tujuan.c_str());
                    cout<<" |"<<endl<<" |";
                    printf("%-37s");
                    cout<<"| Berat\t\t: ";
                    printf("%-19s", berat.c_str());
                    cout<<" |"<<endl<<" |";
                    printf("%-37s");
                    cout<<"|";
                    printf("%-38s");
                    cout<<"|"<<endl;
                    cout<<" |";
                    printf("%-37s");
                    cout<<"|";
                    printf("%-38s");
                    cout<<"|"<<endl;
                    cout<<" |";
                    printf("%-37s");
                    cout<<"|";
                    printf("%-38s");
                    cout<<"|"<<endl;
                    cout<<" |                                     #--------------------------------------|"<<endl;
                    i++;
                }
                q = anakNext(q);
            }
            p = bapakNext(p);
        }
    }
}

void showAnaknyaBapak(ortu o, anak a, string idArmada){
    adrArmada p = cariBapak(o, idArmada);
    adrKargoy q = anakFirst(a);
    if(p == nil){
        cout<<" #-------------------------------------#"<<endl;
        cout<<" |          Data Armada Kosong         #"<<endl;
        cout<<" #-------------------------------------#"<<endl;
    } else{
        cout<<" #-------------------------------------#--------------------------------------#"<<endl;
        cout<<" |               Armada                |                Kargo                 |"<<endl;
        cout<<" #-------------------------------------#--------------------------------------#"<<endl;
        if (p!=nil){
            int n = hitungAnaknyaBapak(o, a, infoBapak(p).idArmada);
            q = anakFirst(a);
            int i = 1;
            bool cek = cekPunyaAnak(o,a,infoBapak(p).idArmada);
            if(!cek){
                auto durasi = std::to_string(infoBapak(p).durasi);
                durasi = durasi + " jam";
                auto kuota = std::to_string(infoBapak(p).kuota);
                kuota = kuota + " kg";
                auto sisa = std::to_string(infoBapak(p).sisa);
                sisa = sisa + " kg";
                cout<<" | ID Armada\t: ";
                printf("%-20s", infoBapak(p).idArmada.c_str());
                cout<<" | Tidak mempunyai kargo";
                printf("%-16s");
                cout<<"|"<<endl;
                cout<<" | Jenis\t: ";
                printf("%-20s", infoBapak(p).jenis.c_str());
                cout<<"|";
                printf("%-38s");
                cout<<" |"<<endl;
                cout<<" | Asal\t\t: ";
                printf("%-20s", infoBapak(p).asal.c_str());
                cout<<"|";
                printf("%-38s");
                cout<<" |"<<endl;
                cout<<" | Tujuan\t: ";
                printf("%-20s", infoBapak(p).tujuan.c_str());
                cout<<"|";
                printf("%-38s");
                cout<<" |"<<endl;
                cout<<" | Durasi\t: ";
                printf("%-20s", durasi.c_str());
                cout<<"|";
                printf("%-38s");
                cout<<" |"<<endl;
                cout<<" | Kuota\t: ";
                printf("%-20s", kuota.c_str());
                cout<<"|";
                printf("%-38s");
                cout<<" |"<<endl;
                cout<<" | Sisa kuota\t: ";
                printf("%-20s", sisa.c_str());
                cout<<"|";
                printf("%-38s");
                cout<<" |"<<endl;
                cout<<" #-------------------------------------#--------------------------------------#"<<endl;
            }
            while(q!=nil){
                if (bapakku(q) == p && i == 1 && i == n){
                    auto durasi = std::to_string(infoBapak(p).durasi);
                    durasi = durasi + " jam";
                    auto kuota = std::to_string(infoBapak(p).kuota);
                    kuota = kuota + " kg";
                    auto berat = std::to_string(infoAnak(q).berat);
                    berat = berat + " kg";
                    auto sisa = std::to_string(infoBapak(p).sisa);
                    sisa = sisa + " kg";
                    cout<<" | ID Armada\t: ";
                    printf("%-20s", infoBapak(p).idArmada.c_str());
                    cout<<"| ID Kargo\t: ";
                    printf("%-19s", infoAnak(q).idBarang.c_str());
                    cout<<"|"<<endl;
                    cout<<" | Jenis\t: ";
                    printf("%-20s", infoBapak(p).jenis.c_str());
                    cout<<" | Asal\t\t: ";
                    printf("%-19s", infoAnak(q).asal.c_str());
                    cout<<"|"<<endl;
                    cout<<"| Asal\t\t: ";
                    printf("%-20s", infoBapak(p).asal.c_str());
                    cout<<" | Tujuan\t\t: ";
                    printf("%-19s", infoAnak(q).tujuan.c_str());
                    cout<<"|"<<endl;
                    cout<<"| Tujuan\t: ";
                    printf("%-20s", infoBapak(p).tujuan.c_str());
                    cout<<"| Berat\t\t: ";
                    printf("%-19s", berat.c_str());
                    cout<<"|"<<endl;
                    cout<<" | Durasi\t: ";
                    printf("%-20s", durasi.c_str());
                    cout<<"|";
                    printf("%-38s");
                    cout<<"|"<<endl;
                    cout<<" | Kuota\t: ";
                    printf("%-20s", kuota.c_str());
                    cout<<"|";
                    printf("%-38s");
                    cout<<"|"<<endl;
                    cout<<" | Sisa Kuota\t: ";
                    printf("%-20s", sisa.c_str());
                    cout<<"|";
                    printf("%-38s");
                    cout<<"|"<<endl;
                    cout<<" #-------------------------------------#--------------------------------------#"<<endl;
                    i++;
                } else if (bapakku(q) == p && i == 1){
                    auto durasi = std::to_string(infoBapak(p).durasi);
                    durasi = durasi + " jam";
                    auto kuota = std::to_string(infoBapak(p).kuota);
                    kuota = kuota + " kg";
                    auto berat = std::to_string(infoAnak(q).berat);
                    berat = berat + " kg";
                    auto sisa = std::to_string(infoBapak(p).sisa);
                    sisa = sisa + " kg";
                    cout<<" | ID Armada\t: ";
                    printf("%-20s", infoBapak(p).idArmada.c_str());
                    cout<<"| ID Kargo\t: ";
                    printf("%-19s", infoAnak(q).idBarang.c_str());
                    cout<<"|"<<endl;
                    cout<<" | Jenis\t: ";
                    printf("%-20s", infoBapak(p).jenis.c_str());
                    cout<<" | Asal\t\t: ";
                    printf("%-19s", infoAnak(q).asal.c_str());
                    cout<<"|"<<endl;
                    cout<<"| Asal\t\t: ";
                    printf("%-20s", infoBapak(p).asal.c_str());
                    cout<<" | Tujuan\t\t: ";
                    printf("%-19s", infoAnak(q).tujuan.c_str());
                    cout<<"|"<<endl;
                    cout<<"| Tujuan\t: ";
                    printf("%-20s", infoBapak(p).tujuan.c_str());
                    cout<<"| Berat\t\t: ";
                    printf("%-19s", berat.c_str());
                    cout<<"|"<<endl;
                    cout<<" | Durasi\t: ";
                    printf("%-20s", durasi.c_str());
                    cout<<"|";
                    printf("%-38s");
                    cout<<"|"<<endl;
                    cout<<" | Kuota\t: ";
                    printf("%-20s", kuota.c_str());
                    cout<<"|";
                    printf("%-38s");
                    cout<<"|"<<endl;
                    cout<<" | Sisa Kuota\t: ";
                    printf("%-20s", sisa.c_str());
                    cout<<"|";
                    printf("%-38s");
                    cout<<"|"<<endl;
                    cout<<" |                                     #--------------------------------------|"<<endl;
                    i++;
                } else if (bapakku(q) == p && i == n){
                    auto durasi = std::to_string(infoBapak(p).durasi);
                    durasi = durasi + " jam";
                    auto kuota = std::to_string(infoBapak(p).kuota);
                    kuota = kuota + " kg";
                    auto berat = std::to_string(infoAnak(q).berat);
                    berat = berat + " kg";
                    auto sisa = std::to_string(infoBapak(p).sisa);
                    sisa = sisa + " kg";
                    cout<<" |";
                    printf("%-37s");
                    cout<<"| ID Kargo\t: ";
                    printf("%-19s", infoAnak(q).idBarang.c_str());
                    cout<<"|"<<endl<<"|";
                    printf("%-37s");
                    cout<<"| Asal\t\t: ";
                    printf("%-19s", infoAnak(q).asal.c_str());
                    cout<<"|"<<endl<<"|";
                    printf("%-37s");
                    cout<<"| Tujuan\t\t: ";
                    printf("%-19s", infoAnak(q).tujuan.c_str());
                    cout<<"|"<<endl<<"|";
                    printf("%-37s");
                    cout<<"| Berat\t\t: ";
                    printf("%-19s", berat.c_str());
                    cout<<"|"<<endl;
                    cout<<"|";
                    printf("%-37s");
                    cout<<"|";
                    printf("%-38s");
                    cout<<"|"<<endl;
                    cout<<"|";
                    printf("%-37s");
                    cout<<"|";
                    printf("%-38s");
                    cout<<"|"<<endl;
                    cout<<"|";
                    printf("%-37s");
                    cout<<"|";
                    printf("%-38s");
                    cout<<"|"<<endl;
                    cout<<" #-------------------------------------#--------------------------------------#"<<endl;
                    i++;
                } else if(bapakku(q) == p){
                    auto durasi = std::to_string(infoBapak(p).durasi);
                    durasi = durasi + " jam";
                    auto kuota = std::to_string(infoBapak(p).kuota);
                    kuota = kuota + " kg";
                    auto berat = std::to_string(infoAnak(q).berat);
                    berat = berat + " kg";
                    auto sisa = std::to_string(infoBapak(p).sisa);
                    sisa = sisa + " kg";
                    cout<<" |";
                    printf("%-38s");
                    cout<<"|";
                    printf("%-36s", infoAnak(q).idBarang.c_str());
                    cout<<"|"<<endl<<" |";
                    printf("%-38s");
                    cout<<"| Asal\t: ";
                    printf("%-41s", infoAnak(q).asal.c_str());
                    cout<<"|"<<endl<<" |";
                    printf("%-38s");
                    cout<<"| Tujuan\t: ";
                    printf("%-39s", infoAnak(q).tujuan.c_str());
                    cout<<"|"<<endl<<"|";
                    printf("%-38s");
                    cout<<"| Berat\t: ";
                    printf("%-40s", berat.c_str());
                    cout<<"|"<<endl;
                    cout<<"|";
                    printf("%-38s");
                    cout<<"|";
                    printf("%-38s");
                    cout<<"|"<<endl;
                    cout<<"|";
                    printf("%-38s");
                    cout<<"|";
                    printf("%-38s");
                    cout<<"|"<<endl;
                    cout<<"|";
                    printf("%-37s");
                    cout<<"|";
                    printf("%-38s");
                    cout<<"|"<<endl;
                    cout<<" |                                                #------------------------------------------------|"<<endl;
                    i++;
                }
                q = anakNext(q);
            }
        }
    }
}

void showBapakAja(ortu o, anak a, adrKargoy q){
    adrArmada p = bapakFirst(o);
    adrKargoy temp = anakFirst(a);
    if(p == nil){
        cout<<" #-------------------------------------#"<<endl;
        cout<<" |          Data Armada Kosong         #"<<endl;
        cout<<" #-------------------------------------#"<<endl;
    } else{
        cout<<" #-------------------------------------#"<<endl;
        cout<<" |               Armada                |"<<endl;
        cout<<" #-------------------------------------#"<<endl;
        if (p!=nil){
            while(p!=nil){
                if (infoAnak(q).asal == infoBapak(p).asal && infoAnak(q).tujuan == infoBapak(p).tujuan){
                    auto durasi = std::to_string(infoBapak(p).durasi);
                    durasi = durasi + " jam";
                    auto kuota = std::to_string(infoBapak(p).kuota);
                    kuota = kuota + " kg";
                    auto berat = std::to_string(infoAnak(q).berat);
                    berat = berat + " kg";
                    auto sisa = std::to_string(infoBapak(p).sisa);
                    sisa = sisa + " kg";
                    cout<<" | ID Armada\t: ";
                    printf("%-20s", infoBapak(p).idArmada.c_str());
                    cout<<" |"<<endl;
                    cout<<" | Jenis\t: ";
                    printf("%-20s", infoBapak(p).jenis.c_str());
                    cout<<" |"<<endl;
                    cout<<" | Asal\t\t: ";
                    printf("%-20s", infoBapak(p).asal.c_str());
                    cout<<" |"<<endl;
                    cout<<" | Tujuan\t: ";
                    printf("%-20s", infoBapak(p).tujuan.c_str());
                    cout<<" |"<<endl;
                    cout<<" | Durasi\t: ";
                    printf("%-20s", durasi.c_str());
                    cout<<" |"<<endl;
                    cout<<" | Kuota\t: ";
                    printf("%-20s", kuota.c_str());
                    cout<<" |"<<endl;
                    cout<<" | Sisa Kuota\t: ";
                    printf("%-20s", sisa.c_str());
                    cout<<" |"<<endl;
                    cout<<" #-------------------------------------#"<<endl;
                }
                p = bapakNext(p);
            }
        }
    }
}
void hapusBapak(ortu &o, anak &a, string idArmada){
    adrArmada p = cariBapak(o, idArmada);
    if (p == nil){
        cout<<" Data armada tidak ada"<<endl;
    } else{
        if(bapakFirst(o) == p){
            bapakFirst(o) = bapakNext(p);
            bapakNext(p) = nil;
            adrKargoy anaknya = anakFirst(a);
            while (anaknya!=nil){
                if (bapakku(anaknya) == p){
                    hapusAnak(o, a, infoAnak(anaknya).idBarang);
                }
                anaknya= anakNext(anaknya);
            }
            delete p;
        } else if(bapakNext(p) == nil){
            adrArmada q = bapakFirst(o);
            while(bapakNext(q) != p){
                q = bapakNext(q);
            }
            bapakNext(q) = nil;
            adrKargoy anaknya = anakFirst(a);
            while (anaknya!=nil){
                if (bapakku(anaknya) == p){
                    hapusAnak(o, a, infoAnak(anaknya).idBarang);
                }
                anaknya= anakNext(anaknya);
            }
            delete p;
        } else{
            adrArmada q = bapakFirst(o);
            while(bapakNext(q) != p){
                q = bapakNext(q);
            }
            bapakNext(q) = bapakNext(p);
            bapakNext(p) = nil;
            adrKargoy anaknya = anakFirst(a);
            while (anaknya!=nil){
                if (bapakku(anaknya) == p){
                    hapusAnak(o, a, infoAnak(anaknya).idBarang);
                }
                anaknya= anakNext(anaknya);
            }
            delete p;
        }
    }
}

void hapusAnak(ortu o, anak &a, string idBarang){
    if(anakFirst(a) == nil){
        cout<<"Tidak ada data barang"<<endl;
    } else{
        adrKargoy p = cariAnak(a, idBarang);
        adrArmada q = cariBapaknyaAnak(a, o, idBarang);
        infoBapak(q).sisa += infoAnak(p).berat;
        if (anakFirst(a) == p){
            anakFirst(a) = anakNext(p);
            anakNext(p) = nil;
            bapakku(p) = nil;
            delete p;
        } else if(anakNext(p) == nil){
            adrKargoy temp = anakFirst(a);
            while(anakNext(temp) != p){
                temp = anakNext(temp);
            }
            anakNext(temp) = nil;
            bapakku(p) = nil;
            delete p;
        } else {
            adrKargoy temp = anakFirst(a);
            while(anakNext(temp) != p){
                temp = anakNext(temp);
            }
            anakNext(temp) = anakNext(p);
            bapakku(p) = nil;
            anakNext(p) = nil;
            delete p;
        }
    }
}

void rubahBapak(ortu o, anak a, string idArmada, string idBarang){
    adrKargoy q = cariAnak(a, idBarang);
    adrArmada p = cariBapak(o, idArmada);
    adrArmada temp = cariBapaknyaAnak(a, o, idBarang);
    infoBapak(temp).sisa += infoAnak(q).berat;
    if (infoAnak(q).asal == infoBapak(p).asal && infoAnak(q).tujuan == infoBapak(p).tujuan){
        bapakku(q) = p;
        infoBapak(p).sisa -= infoAnak(q).berat;
    } else {
        cout<<"Asal dan tujuan armada dengan kargo berbeda!"<<endl;
    }
}

void rubahBapakCepat(ortu o, anak a, string idBarang){
    adrKargoy q = cariAnak(a, idBarang);
    adrArmada p = bapakFirst(o);
    int minim = infoBapak(p).durasi;
    adrArmada temp = cariBapaknyaAnak(a,o,idBarang);
    if (q== nil){
        cout<<"Data kargo ga ada";
    }else {
        if (bapakFirst(o) == nil){
            cout<<"Data armada kosong"<<endl;
        } else {
            infoBapak(temp).kuota += infoAnak(q).berat;
            while (p!= nil){
                if (infoBapak(p).durasi < minim && infoAnak(q).asal == infoBapak(p).asal && infoAnak(q).tujuan == infoBapak(p).tujuan){
                    minim = infoBapak(p).durasi;
                    temp = p;
                }
                p = bapakNext(p);
            }
            bapakku(q) = temp;
            infoBapak(temp).sisa -= infoAnak(q).berat;
        }
    }
}

int hitungBapak(ortu o){
    int i = 0;
    adrArmada p = bapakFirst(o);
    while(p != nil){
        i++;
        p = bapakNext(p);
    }
    return i;
}

int hitungAnak(anak a){
    int i = 0;
    adrKargoy p = anakFirst(a);
    while(p != nil){
        i++;
        p = anakNext(p);
    }
    return i;
}

int hitungAnaknyaBapak(ortu o, anak a, string idArmada){
    int i = 0;
    adrArmada p = cariBapak(o, idArmada);
    adrKargoy q = anakFirst(a);
    while (q != nil){
        if(bapakku(q) == p){
            i++;
        }
        q = anakNext(q);
    }
    return i;
}

int hitungBeratBapak(ortu o, anak a, string idArmada){
    int n = 0;
    adrArmada p = cariBapak(o, idArmada);
    adrKargoy q = anakFirst(a);
    while(q != nil){
        if(bapakku(q) == p){
            n += infoAnak(q).berat;
        }
        q = anakNext(q);
    }
    return n;
}

adrArmada terbanyakAnak(ortu o, anak a, int &jumlah){
    int berat1 = 0;
    int berat2 = 0;
    adrArmada p = bapakFirst(o);
    adrArmada q = bapakFirst(o);
    while(p != nil){
        int temp = hitungAnaknyaBapak(o, a, infoBapak(p).idArmada);
        if(jumlah < temp){
            jumlah = temp;
            berat1 = hitungBeratBapak(o, a, infoBapak(p).idArmada);
            q = p;
        } else if(jumlah == temp){
            berat2 = hitungBeratBapak(o, a, infoBapak(p).idArmada);
            if(berat1 < berat2){
                q = p;
            }
        }
        p = bapakNext(p);
    }
    return q;
}

adrArmada tersedikitAnak(ortu o, anak a, int &jumlah){
    int berat1 = 0;
    int berat2 = 0;
    adrArmada p = bapakFirst(o);
    adrArmada q = bapakFirst(o);
    if(p == nil){
        return p;
    }
    jumlah = hitungAnaknyaBapak(o, a, infoBapak(bapakFirst(o)).idArmada);
    while(p != nil){
        int temp = hitungAnaknyaBapak(o, a, infoBapak(p).idArmada);
        if(jumlah > temp){
            jumlah = temp;
            berat1 = hitungBeratBapak(o, a, infoBapak(p).idArmada);
            q = p;
        } else if (jumlah == temp){
            berat2 = hitungBeratBapak(o, a, infoBapak(p).idArmada);
            if(berat1 > berat2){
                q = p;
            }
        }
        p = bapakNext(p);
    }
    return q;
}

bool apakahAdaArmadaKeSana(ortu o, string asal, string tujuan){
    adrArmada p = bapakFirst(o);
    while(p!= nil){
        if (infoBapak(p).asal == asal&&infoBapak(p).tujuan==tujuan){
            return true;
        }
        p = bapakNext(p);
    }
    return false;
}

bool apakahAdaArmada(ortu o,anak a,string idArmada){
    adrArmada p = bapakFirst(o);
    while(p!= nil){
        if (infoBapak(p).idArmada == idArmada){
            return true;
        }
        p = bapakNext(p);
    }
    return false;
}

int menuUtama(){
    int pilih;
    cout << " #=====================#" << endl;
    cout << " |         MENU        |" << endl;
    cout << " #=====================#" << endl;
    cout << " | 1. Tambah Data      |" << endl;
    cout << " | 2. Edit Data        |" << endl;
    cout << " | 3. Tampilkan Data   |" << endl;
    cout << " | 4. Hapus Data       |" << endl;
    cout << " | 0. Keluar Program   |" << endl;
    cout << " #=====================#" << endl;
    cout << " Pilih menu: ";
    cin >> pilih;
    return pilih;
}

int menuTambah(){
    int pilih;
    cout << " #==========================#" << endl;
    cout << " |      TAMBAHKAN DATA      |" << endl;
    cout << " #==========================#" << endl;
    cout << " | 1. Buat armada baru      |" << endl;
    cout << " | 2. Buat kargo baru       |" << endl;
    cout << " | 0. Kembali ke menu utama |" << endl;
    cout << " #==========================#" << endl;
    cout << " Pilih menu: ";
    cin >> pilih;
    return pilih;
}

int menuEdit(){
    int pilih;
    cout << " #=================================================#" << endl;
    cout << " |                    EDIT DATA                    |" << endl;
    cout << " #=================================================#" << endl;
    cout << " | 1. Ubah armada kargo                            |" << endl;
    cout << " | 2. Ubah pengiriman kargo ke armada paling cepat |" << endl;
    cout << " | 0. Kembali ke menu utama                        |" << endl;
    cout << " #=================================================#" << endl;
    cout << " Pilih menu: ";
    cin >> pilih;
    return pilih;
}

int menuTampil(){
    int pilih;
    cout << " #=============================================================#" << endl;
    cout << " |                        TAMPIL DATA                          |" << endl;
    cout << " #=============================================================#" << endl;
    cout << " | 1. Tampilkan seluruh armada dan muatan                      |" << endl;
    cout << " | 2. Tampilkan armada dengan kargo terbanyak                  |" << endl;
    cout << " | 3. Tampilkan armada dengan kargo tersedikit                 |" << endl;
    cout << " | 4. Tampilkan data armada (berdasarkan asal dan tujuan)      |" << endl;
    cout << " | 5. Tampilkan jumlah armada                                  |" << endl;
    cout << " | 6. Tampilkan jumlah kargo                                   |" << endl;
    cout << " | 7. Tampilkan jumlah kargo pada armada                       |" << endl;
    cout << " | 0. Kembali ke menu utama                                    |" << endl;
    cout << " #=============================================================#" << endl;
    cout << " Pilih menu: ";
    cin >> pilih;
    return pilih;
}

int menuHapus(){
    int pilih;
    cout << " #==================================#" << endl;
    cout << " |            HAPUS DATA            |" << endl;
    cout << " #==================================#" << endl;
    cout << " | 1. Batalkan keberangkatan armada |" << endl;
    cout << " | 2. Batalkan pengiriman kargo     |" << endl;
    cout << " | 0. Kembali ke menu utama         |" << endl;
    cout << " #==================================#" << endl;
    cout << " Pilih menu: ";
    cin >> pilih;
    return pilih;
}
