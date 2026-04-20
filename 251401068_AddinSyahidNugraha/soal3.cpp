#include <iostream>
#include <string>

using namespace std;

int main() {
    system("cls");

    string kode;

    cout << "Massukkan kode transaksi (8 digit): "; cin >> kode;

    char hri(kode[1]-'0'), lyl(kode[3]-'0');

    cout << "Jenis Hari: " << (hri==1 ? "Hari kerja" : hri==2 ? "Akhir pekan" : "Hari libur nasional")
         << "\nJenis Pelanggan: " << (lyl==1 ? "Biasa" : lyl==2 ? "Silver" : "Gold") << endl;

    int jumB(stoi(kode.substr(4))), poin(lyl * (1 + (hri>2)) + (hri>1) + !(hri^2||lyl^3));

    cout << "Jumlah Belanja: Rp " << jumB  * 100000 << "\nTotal poin: " << poin * jumB << endl;

    return 0;
}

/*
Variabel
- hri (hari), dalam char karena pasti < 125

- lyl (loyalitas), dalam char karena pasti < 125

- jumB (jumlah belanja), dalam int karena bisa > 125

- poin (total poin), dalam int karena bisa > 125

Logika
- '0' != 0, tapi jarak nilai ascii '0' -> '9' == 0 -> 9, jadi char numerik - '0' = nilai numeriknya. 

- Ternary operator digunakan krn akan langsung mengembalikan nilai jadi bisa diletak di cout

- Bentuk dasar :
  kondisi ? jika benar : jika salah
  Bentuk campur :
  kondisi 1 ? jika benar : kondisi 2 ? jika benar : jika salah

- lyl * (1 + (hri>2)) + (hri>1) + (hri == 2 & lyl == 3), ini rumus dari poin yang memenuhi persyaratannya
  hri(1), poin = lyl  
  hri(2), poin = lyl + 1 + !(hri^2||lyl^3)
  hri(3), poin = 2 * lyl + 1

- Jumlah belanja = kode digit 5 - 8 * 100000 
*/