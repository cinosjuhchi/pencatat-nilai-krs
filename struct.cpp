#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Krs {
    string mka;
    int sks;
    string nilaiHuruf;
    float harkat;
};

float harkatKRS(string nilai) {
    if (nilai == "A+" || nilai == "a+") return 4.0;
    else if (nilai == "A" || nilai == "a") return 3.5;
    else if (nilai == "B+" || nilai == "b+") return 3.0;
    else if (nilai == "B" || nilai == "b") return 2.5;
    else if (nilai == "C+" || nilai == "c+") return 2.0;
    else if (nilai == "C" || nilai == "c") return 1.5;
    else return 0.0; // jika tidak valid
}


float harkatSks(float harkat, float sks) {
	return harkat * sks;
}


float nilaiIPS(float jumlahHarkatSks, float jumlahSks) {
	return jumlahHarkatSks / jumlahSks;
}


void displayResult(Krs krs[], int n) {
	float jumlahSks = 0;
	float jumlahHarkatSks = 0;
    cout << setfill('-') << setw(100) << "-" << endl;
    cout << setfill(' ');
    cout << "|" << left << setw(20) << "Nama"
         << "|" << left << setw(20) << "SKS"
         << "|" << left << setw(20) << "Nilai"
         << "|" << left << setw(20) << "Harkat"
         << "|" << left << setw(14) << "SKS x Harkat" << "|" <<endl;
    cout << setfill('-') << setw(100) << "-" << endl;
    cout << setfill(' ');
	
	
	
    for (int i = 0; i < n; i++) {
		float harkatISks = harkatSks(krs[i].harkat, krs[i].sks);
		jumlahHarkatSks += harkatISks;
		jumlahSks += krs[i].sks;
        cout << "|" << left << setw(20) << krs[i].mka
             << "|" << left << setw(20) << krs[i].sks
             << "|" << left << setw(20) << krs[i].nilaiHuruf
             << "|" << left << setw(20) << fixed << setprecision(2) << krs[i].harkat
             << "|" << left << setw(14) << harkatISks << "|" <<endl;
          
    }    
    cout << setfill('-') << setw(100) << "-" << endl;
    cout << "IPS : " << nilaiIPS(jumlahHarkatSks, jumlahSks)<<endl;
    cout << endl;
}

int main() {
    const int jumlahMatkul = 3;
    Krs ipk[jumlahMatkul];

    cout << "Selamat datang di penghitung nilai SKS!" << endl;

    for (int i = 0; i < jumlahMatkul; i++) {
        cin.ignore();
        cout << "Masukan nama Matkul : ";
        getline(cin, ipk[i].mka);

        cout << "Masukan jumlah SKS   : ";
        cin >> ipk[i].sks;

        cout << "Masukan nilai huruf (A+, A, B+, B, C+, C): ";
        cin >> ipk[i].nilaiHuruf;

        // konversi nilai huruf ke harkat
        ipk[i].harkat = harkatKRS(ipk[i].nilaiHuruf);
        cout << endl;
    }

    displayResult(ipk, jumlahMatkul);

    cout << "Selesai" << endl;
    return 0;
}
