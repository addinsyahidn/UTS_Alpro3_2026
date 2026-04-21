#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    system("cls");

    string kode, keluar;

    cout << "Masukkan kode parkir digital (10 digit): "; cin >> kode;
    cout << "Masukkan jam keluar (format HHMM): "; cin >> keluar;

    int biaya(0), durasi((stoi(keluar.substr(0, 2)) - stoi(kode.substr(2, 2))) + ceil((stoi(keluar.substr(2)) - stoi(kode.substr(4, 2)))/60.f));

    cout << "\n--- Ringkasan Parkir ---";
    cout << "\nJenis kendaraan: ";

    switch (kode[0]) {
        case '1' : cout << "Mobil"; 
                   biaya = durasi * 3000 + 2000; 
                   break;
        case '2' : cout << "Motor"; 
                   biaya = durasi * 2000 + 1000; 
                   break;
        case '3' : cout << "Bus";
                   biaya = durasi * 7000 + 3000; 
                   break;
    }

    cout << "\nWaktu masuk: " << kode.substr(2, 2) << ':' << kode.substr(4, 2) << "\nWaktu keluar: " << keluar.substr(0, 2) << ':' << keluar.substr(2);
    cout << "\nDurasi parkir: " << durasi << " jam" << "\nLokasi parkir: " << kode.substr(6) << "\nTotal biaya: Rp " << biaya;  
    
    return 0;
}

/*
Variabel
- kode (inputan kode), string agar mudah dilakuakan pemisahan
- keluar (waktu keluar parkir), string agar mudah dilakukan pemisahan
- biaya (biaya parkir), int karena bilangan bulat dan > 125
- durasi (lama parkir), int biar declarenya bisa sekalian sama biaya (walaupun pasti < 125) 

Logika
- Kode menerima input (kode,keluar)
- Deklarasi sekaligus pengisian variabel durasi dengan tipe data float
- waktu akhir-waktu awal
- 60 menit = 1 jam, makanya yg menit dibagi 60
- Ceil di menit karena pengendara yg memasuki waktu jam baru teritung full (agar ga rugi)
- menggunakan switch case di digit pertama karena di testcase sudah safe (digit ke 2 jadi ga penting)
- output jam masuk dan keluar menggunakan substr agar bisa langsung mengambil 2 digit (jika "09" tetap "09" ga jadi "9")
*/
