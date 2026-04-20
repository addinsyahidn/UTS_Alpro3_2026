#include <iostream>
#include <string>

using namespace std;

int main() {
        system("cls");

        string nomor{0};

        cout << "Masukkan nomor kartu digital: "; cin >> nomor;

        int angka(stoi(nomor.substr(0, 2))), panjang(nomor.size()), total(0);

        cout << "Tipe kartu: " << (angka == 65 ?  "NUSANTARA" : angka == 91 ? "MERDEKA" :  "GARUDA") << endl;

        for (int i(panjang-1); i >= 0; i--) {
            angka = (nomor[i] - '0') * (1 + !((panjang-2-i)%2));
            total += (angka > 9) ? to_string(angka)[0] + to_string(angka)[1] - 2 * '0' : angka;
        }
        
        if (total%10) cout << "Nomor kartu TIDAK VALID.";
        else cout << "Nomor kartu VALID.";

    return 0;
}

/*
Variabel
- angka, untuk string yg diubah ke integer
- panjang, panjang dari nomor yg diinput

Logika
- jika angka == 65, maka Tipe kartu NUSANTARA
- jika angka == 91 , maka Tipe kartu MERDEKA
- lainnya Tipe kartu GARUDA (disoal tidak diminta safety dan test-case juga sudah safe)
- looping for decrement 1, karena diketahui batasnya dan dari indeks akhir ke indeks awal
- '0' != 0, tapi jarak nilai ascii '0' -> '9' == 0 -> 9, jadi char numerik - '0' == nilai numeriknya.
- !((panjang-2-i)%2)), akan menghasilkan 2 jika i berada di selang ke 2 (untuk digit yg dikali 2) dan 1 jika di selang 1
- if (total%10), kalo total ga 10 maka hasilnya != 0 (true) makanya tidak valid
*/