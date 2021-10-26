//Kalkulator BMR

/**Kalkulator ini akan menghitung BMR lalu menggunakan perhitungan
   tersebut untuk memperkirakan berat badan yang dapat diturunkan
   seseorang selama 1 minggu**/

#include <iostream>
#include <string>
using namespace std;

//Deklarasi struct berupa data yang dibutuhkan
struct Pemakai {
	string nama;
	float berat;
	float tinggi;
	int umur;
	bool gender;
	int olahraga;
	float konsumsi_kalori;
};

int main() {
	int i;
	float bb_turun = 0;
	double BMR = 0;
	//Header
	cout << "KALKULATOR BMR" << endl;
	cout << "Kalkulator BMR untuk menghitung kalori" << endl;
	cout << "========================================" << endl;

	//Proses input data untuk perhitungan BMR
	cout << "\nSilahkan masukkan jumlah orang yang ingin menghitung BMR: ";
	cin >> i;
	Pemakai pemakai[100];//Array digunakan agar dapat Looping struct untuk kasus banyak pengguna


	//Looping untuk memasukkan data apabila data lebih dari 1
	for (int x = 1; x <= i; x++) {
		cout << "\nData orang ke-" << x << endl;
		cout << "Masukkan nama Anda: ";
		cin >> pemakai[x].nama;
		cout << "Apakah Anda seorang Pria?(Ketik 1 jika ya, 0 jika tidak) ";
		cin >> pemakai[x].gender;
		cout << "Masukkan berat Anda: ";
		cin >> pemakai[x].berat;
		cout << "Masukkan tinggi Anda: ";
		cin >> pemakai[x].tinggi;
		cout << "Masukkan umur Anda: ";
		cin >> pemakai[x].umur;
		cout << "Berapa jumlah hari yang Anda habiskan untuk berolahraga dalam 1 minggu: ";
		cin >> pemakai[x].olahraga;
		cout << "Berapa perkiraan jumlah kalori yang Anda konsumsi dalam 1 hari: ";
		cin >> pemakai[x].konsumsi_kalori;
		cout << "=================================================================================================" << endl;
	}
	//Proses seleksi dan perhitungan data
	for (int z = 1; z <= i; z++) {

		//Perhitungan dibagi berdasarkan gender dan aktivitas fisik
		//Seleksi pertama berdasarkan gender
		if (pemakai[z].gender == 1) {
			BMR = BMR + (13.75 * pemakai[z].berat) + (5 * pemakai[z].tinggi) - (6.67 * pemakai[z].umur) + 66;
		}
		else {
			BMR = BMR + (9.56 * pemakai[z].berat) + (1.85 * pemakai[z].tinggi) - (4.68 * pemakai[z].umur) + 655;
		}

		//Seleksi kedua berdasarkan aktivitas fisik
		if (pemakai[z].olahraga >= 1 && pemakai[z].olahraga < 3) {
			BMR = BMR * 1.375;
		}
		else if (pemakai[z].olahraga >= 3 && pemakai[z].olahraga <= 5) {
			BMR = BMR * 1.55;
		}
		else if (pemakai[z].olahraga == 6) {
			BMR = BMR * 1.725;
		}
		else if (pemakai[z].olahraga == 7) {
			BMR = BMR * 1.9;
		}
		else {
			BMR = BMR * 1.2;
		}
		bb_turun = 0.5 * (BMR - pemakai[z].konsumsi_kalori) / 3500;

		//Seleksi untuk output dari program
		if (bb_turun > 0) {
			cout << "BMR yang dimiiki oleh " << pemakai[z].nama << " adalah " << BMR;
			cout << ".\nDengan jumlah BMR tersebut " << pemakai[z].nama << " dapat menurunkan berat badan sebesar " << bb_turun << " Kg setiap minggu" << endl;
			cout << "Tetap semangat berolahraga" << endl;
			cout << "-------------------------------------------------------------------------------------------------" << endl;
		}
		else {
			cout << "BMR yang dimiiki oleh " << pemakai[z].nama << " adalah " << BMR; 
			cout << ".\nDengan jumlah BMR tersebut berat badan Anda akan naik " << -1 * bb_turun << " Kg setiap minggunya" << endl;
			cout << "Cobalah untuk giat berolahraga" << endl;
			cout << "-------------------------------------------------------------------------------------------------" << endl;
		}
		BMR = 0;//Mengembalikan nilai BMR ke 0 agar tidak mengubah nilai BMR selanjutnya
	}
	cout << "TERIMA KASIH TELAH MENGGUNAKAN BMR KALKULATOR" << endl;

	return 0;
}