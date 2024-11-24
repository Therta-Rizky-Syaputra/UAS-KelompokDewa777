#include <iostream>
#include <string>
using namespace std;

struct Tiket {
    string namaPenumpang;
    string kelasKereta;
    string jadwalKeberangkatan;
    int harga;
};

const int MAX_TIKET = 100;
Tiket daftarTiket[MAX_TIKET];
int jumlahTiket = 0;

void pesanTiket() {
    if (jumlahTiket < MAX_TIKET) {
        Tiket tiketBaru;
        cout << "=======================================\n";
        cout << "|   Loket Stasiun Kereta Api Karawang  |\n";
        cout << "=======================================\n";
        cout << "Masukkan nama penumpang: ";
        cin.ignore();
        getline(cin, tiketBaru.namaPenumpang);

        cout << "Pilih jadwal keberangkatan: \n";
        cout << "1. Karawang - Cikarang   | 08:00\n";
        cout << "2. Karawang - Purwakarta | 10:00\n";
        cout << "3. Karawang - Bandung    | 12:00\n";
        cout << "4. Karawang - Semarang   | 14:00\n";
        cout << "Pilihan (1-4): ";
        int pilihanJadwal;
        cin >> pilihanJadwal;

        switch (pilihanJadwal) {
            case 1:
                tiketBaru.jadwalKeberangkatan = "Karawang - Cikarang   |08:00";
                break;
            case 2:
                tiketBaru.jadwalKeberangkatan = "Karawang - Purwakarta | 10:00";
                break;
            case 3:
                tiketBaru.jadwalKeberangkatan = "Karawang - Bandung    |12:00";
                break;
            case 4:
                tiketBaru.jadwalKeberangkatan = "Karawang - semarang   | 14:00";
                break;
            default:
                cout << "Pilihan jadwal tidak valid, tiket gagal ditambahkan!\n";
                return;
        }

   cout << "1. Tiket Ekonomi   (Rp. 50,000)" << endl;
    cout << "2. Tiket Bisnis    (Rp. 100,000)" << endl;
    cout << "3. Tiket Eksekutif (Rp. 150,000)" << endl;
    cout << "======================================" << endl;

        int pilihanKelas;
        cin >> pilihanKelas;

        switch (pilihanKelas) {
            case 1:
                tiketBaru.kelasKereta = "Ekonomi";
                tiketBaru.harga = 50000;
                break;
            case 2:
                tiketBaru.kelasKereta = "Bisnis";
                tiketBaru.harga = 100000;
                break;
            case 3:
                tiketBaru.kelasKereta = "Eksekutif";
                tiketBaru.harga = 150000;
                break;
            default:
                cout << "Kelas tidak valid, tiket gagal ditambahkan!\n";
                return;
        }

        daftarTiket[jumlahTiket++] = tiketBaru;
        cout << "Tiket berhasil ditambahkan!\n";
    } else {
        cout << "Data tiket penuh!\n";
    }
}

void tampilkanTiket() {
    if (jumlahTiket == 0) {
        cout << "Belum ada tiket yang dipesan.\n";
        return;
    }

    cout << "Daftar Tiket yang Dipesan:\n";
    for (int i = 0; i < jumlahTiket; i++) {
        cout << i + 1 << ". Nama: " << daftarTiket[i].namaPenumpang << "\n"
             << " Jadwal: " << daftarTiket[i].jadwalKeberangkatan << "\n"
             << " Kelas: " << daftarTiket[i].kelasKereta << "\n"
             << "Harga: " << daftarTiket[i].harga << " IDR\n";
    }
}

void hapusTiket() {
    if (jumlahTiket == 0) {
        cout << "Belum ada tiket yang dipesan.\n";
        return;
    }

    tampilkanTiket();
    cout << "Pilih nomor tiket yang ingin dihapus: ";
    int nomorTiket;
    cin >> nomorTiket;

    if (nomorTiket > 0 && nomorTiket <= jumlahTiket) {
        for (int i = nomorTiket - 1; i < jumlahTiket - 1; i++) {
            daftarTiket[i] = daftarTiket[i + 1];
        }
        jumlahTiket--;
        cout << "Tiket berhasil dihapus!\n";
    } else {
        cout << "Nomor tiket tidak valid!\n";
    }
}

int main() {
    int pilihan;
    do {
        cout << "=======================================\n";
        cout << "   Loket Stasiun Kereta Api Karawang   \n";
        cout << "=======================================\n";
        cout << "1. Pesan Tiket\n";
        cout << "2. Lihat Tiket\n";
        cout << "3. Hapus Tiket\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                pesanTiket();
                break;
            case 2:
                tampilkanTiket();
                break;
            case 3:
                hapusTiket();
                break;
            case 4:
                cout << "Terima kasih telah menggunakan sistem pemesanan tiket.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 4);

    return 0;
}
