#include <iostream>
#include <string>
#include <locale>
using namespace std;

int p, l, t, lantai;
int plafon, keramik, tembok, atap, tukang, semen;

void input_rumah(){
	cout << "Panjang rumah: ";
	cin >> p;

	cout << "Lebar rumah: ";
	cin >> l;

	cout << "Tinggi rumah: ";
	cin >> t;

	cout << "Jumlah lantai: ";
	cin >> lantai;
}

void input_biaya(){
	cout << "Harga plafon per m^2: ";
	cin >> plafon;

	cout << "Harga keramik per m^2: ";
	cin >> keramik;

	cout << "Harga tembok per m^2: ";
	cin >> tembok;

	cout << "Harga atap per m^2: ";
	cin >> atap;

	cout << "Jasa tukang per m^2: ";
	cin >> tukang;

	cout << "Harga semen dll per m^2: ";
	cin >> semen;
}

void hitung(){
	int luas_datar = p * l;
	int luas_tembok_lebar = l * t;
	int luas_tembok_panjang = p * t;
	int luas_permukaan = 2 * ((p*l) + (p*t) + (l*t));
	int harga_plafon = luas_datar * plafon * lantai;
	int harga_keramik = luas_datar * keramik * lantai;
	int harga_tembok_lebar = luas_tembok_lebar * tembok * 2 * lantai;
	int harga_tembok_panjang = luas_tembok_panjang * tembok * 2 * lantai;
	int harga_atap = luas_datar * atap;
	int harga_semen_dll = luas_permukaan * semen;
	int harga_tukang = luas_permukaan * tukang;

	std::cout.imbue(std::locale("id_ID.utf8"));
	cout << endl << "Menghitung biaya-biaya..." << endl;
	cout << "Luas permukaan rumah: " << luas_permukaan << endl;
	cout << "Luas tembok sisi panjang: " << luas_tembok_panjang << endl;
	cout << "Luas tembok sisi lebar: " << luas_tembok_lebar << endl;
	cout << "Luas keempat tembok: " << luas_tembok_lebar + luas_tembok_panjang << endl;
	cout << "Luas plafon dan keramik: " << luas_datar << endl << endl;

	cout << "Biaya plafon adalah Rp " << harga_plafon << " untuk rumah berlantai " << lantai << endl;
	cout << "Biaya keramik adalah Rp " << harga_keramik << " untuk rumah berlantai " << lantai << endl;
	cout << "Biaya tembok sisi lebar adalah Rp " << harga_tembok_lebar << " untuk rumah berlantai " << lantai << endl;
	cout << "Biaya tembok sisi panjang adalah Rp " << harga_tembok_panjang << " untuk rumah berlantai " << lantai << endl;
	cout << "Biaya atap adalah Rp " << harga_atap << " untuk rumah berlantai " << lantai << endl;
	cout << "Biaya semen dll adalah Rp " << harga_semen_dll << " untuk rumah berlantai " << lantai << endl;
	cout << "Biaya tukang adalah Rp " << harga_tukang << " untuk rumah berlantai " << lantai << endl;
	cout << "Total biaya: Rp " << harga_plafon + harga_keramik + harga_tembok_lebar 
			+ harga_tembok_panjang + harga_atap + harga_semen_dll + harga_tukang << endl;;
}

void fulangi(){
	string ulangi;

	cout << endl << "Ganti detail rumah, biaya, selesai atau hitung baru? " << endl << "[rumah|biaya|selesai|baru] ";
	cin >> ulangi;

	if (ulangi == "rumah"){
		cout << "Masukkan ulang detail rumah:" << endl;
		input_rumah();
		hitung();
	} else if (ulangi == "biaya"){
		cout << "Masukkan ulang detail biaya:" << endl;
		input_biaya();
		hitung();
	} else if (ulangi == "baru"){
		cout << "Memulai hitungan baru..." << endl;
		input_rumah();
		input_biaya();
		hitung();
	} else if (ulangi == "selesai" || ulangi == ""){
		cout << "Selesai" << endl;
		return;
	}

	fulangi();
}

int main(){
	cout << "Membuat Rumah Kubus atau Balok 101" << endl << endl;

	input_rumah();
	input_biaya();
	hitung();
	fulangi();

	return 0;
}
