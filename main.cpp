#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Fungsi untuk menambahkan catatan ke vector
void tambah_catatan(vector<string> &catatan) {
  string input;
  cout << "Masukkan catatan baru: ";
  getline(cin, input);
  catatan.push_back(input); // Menambahkan catatan ke akhir vector
  cout << "Catatan berhasil ditambahkan.\n";
}

// Fungsi untuk melihat semua catatan di vector
void lihat_catatan(vector<string> &catatan) {
  if (catatan.empty()) { // Jika vector kosong, tidak ada catatan yang ditampilkan
    cout << "Tidak ada catatan yang tersimpan.\n";
  } else { // Jika vector tidak kosong, tampilkan semua catatan
    cout << "Daftar catatan:\n";
    for (int i = 0; i < catatan.size(); i++) {
      cout << i + 1 << ". " << catatan[i] << "\n";
    }
  }
}

// Fungsi untuk mengedit catatan di vector berdasarkan indeks
void edit_catatan(vector<string> &catatan) {
  int indeks;
  string input;
  cout << "Masukkan indeks catatan yang ingin diedit: ";
  cin >> indeks;
  cin.ignore(); // Mengabaikan karakter newline setelah input angka
  if (indeks < 1 || indeks > catatan.size()) { // Jika indeks tidak valid, tampilkan pesan kesalahan
    cout << "Indeks catatan tidak valid.\n";
  } else { // Jika indeks valid, minta input baru dan ganti catatan lama dengan yang baru
    cout << "Masukkan catatan baru: ";
    getline(cin, input);
    catatan[indeks - 1] = input; // Mengganti catatan di indeks yang dipilih dengan input baru
    cout << "Catatan berhasil diedit.\n";
  }
}

// Fungsi untuk mencari catatan di vector berdasarkan kata kunci
void cari_catatan(vector<string> &catatan) {
  string kata_kunci;
  cout << "Masukkan kata kunci yang ingin dicari: ";
  getline(cin, kata_kunci);
  bool ketemu = false; // Variabel untuk menandai apakah kata kunci ditemukan atau tidak
  for (int i = 0; i < catatan.size(); i++) {
    if (catatan[i].find(kata_kunci) != string::npos) { // Jika kata kunci ditemukan di catatan, tampilkan catatan dan indeksnya
      cout << i + 1 << ". " << catatan[i] << "\n";
      ketemu = true; // Ubah variabel menjadi true
    }
  }
  if (!ketemu) { // Jika variabel masih false, berarti kata kunci tidak ditemukan di semua catatan
    cout << "Tidak ada catatan yang mengandung kata kunci tersebut.\n";
  }
}

// Fungsi utama untuk menjalankan program
int main() {
  vector<string> catatan; // Membuat vector untuk menyimpan catatan
  int pilihan; // Membuat variabel untuk menyimpan pilihan menu
  bool selesai = false; // Membuat variabel untuk menandai apakah program selesai atau tidak
  while (!selesai) { // Ulangi selama program belum selesai
    // Tampilkan menu pilihan
    cout << "Menu:\n";
    cout << "1. Tambah catatan\n";
    cout << "2. Lihat semua catatan\n";
    cout << "3. Edit catatan\n";
    cout << "4. Cari catatan\n";
    cout << "5. Keluar\n";
    cout << "Masukkan pilihan Anda: ";
    cin >> pilihan;
    cin.ignore(); // Mengabaikan karakter newline setelah input angka
    switch (pilihan) { // Lakukan aksi berdasarkan pilihan
      case 1: // Jika pilihan 1, panggil fungsi tambah_catatan
        tambah_catatan(catatan);
        break;
      case 2: // Jika pilihan 2, panggil fungsi lihat_catatan
        lihat_catatan(catatan);
        break;
      case 3: // Jika pilihan 3, panggil fungsi edit_catatan
        edit_catatan(catatan);
        break;
      case 4: // Jika pilihan 4, panggil fungsi cari_catatan
        cari_catatan(catatan);
        break;
      case 5: // Jika pilihan 5, ubah variabel selesai menjadi true dan tampilkan pesan keluar
        selesai = true;
        cout << "Terima kasih telah menggunakan program ini.\n";
        break;
      default: // Jika pilihan tidak valid, tampilkan pesan kesalahan
        cout << "Pilihan tidak valid.\n";
        break;
    }
  }
  return 0;
}
