#include <iostream>

using namespace std;


int main() {
    system("cls");

    string S{0};
    int N(0), A(0), B(0); 
    char temp(0), count(1);

    cin >> N;
    cin >> S;

    for (int i(0); i < N; i++) {
        if (temp == S[i] && count < 3) count++;
        else count = 1;

        if (S[i]=='A')
            A += 3 + (!(count%3) * 2);
        else if (S[i]=='B')
            B += 3 + (!(count%3) * 2);
        else {
            A++; B++;
        }

        temp = S[i];
    }

    cout << "Poin A: " << A << "\nPoin B: " << B << "\n" << (A == B? "Hasil pertandingan Seri!" : A > B ? "Pemenangnya adalah pemain A" : "Pemenangnya adalah pemain B");

    return 0;
}

/*
Variabel
- S (pemenang tiap babak), string karena input dalam char dan ada banyak char jadi perlu array
- N (jumlah babak), int karena babak maksimal tidak diberitau
- A (poin A), int karena bisa menang tiap babak
- B (poin B), int karena bisa menang tiap babak
- temp (nilai sementara), char karena menyimpan alfabet
- count (counter), char karena maks 3 (< 125)

Logika
- Loop for krn ada batasnya, dengan i dimulai dari 0 karena indeks array dimulai dari 0 dan batasnya indeks N-1
- operator if pertama akan mengatur penambahan count dan reset count
- operator if kedua akan "membaca" string dan menentukan siapa pemenang babak ata jika babak seri
- temp akan menyimpan siapa pemenang babak terakhir
- ternary di cout akan menentukan pemenang keseluruhan
*/