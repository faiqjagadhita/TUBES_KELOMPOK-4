# Laporan Pembuatan Aplikasi Data Pegawai dengan Struktur Organisasi Tree & Sistem Absensi

## 1. Anggota Kelompok

Nama : Rahmat Ahdaf Albariza      /103112430003

Nama : Fa'iq Jagadhita Hardiana   /103112430015

Nama : Arzaqi Fatih Muttaqin      /103112430092

Kelas : 12-IF-05


## 2. Latar Belakang
Aplikasi Data Pegawai dengan Struktur Organisasi Tree & Sistem Absensi ini adalah untuk membantu pengelolaan data pegawai agar lebih rapi, terstruktur, dan mudah diakses. Dalam aplikasi ini, data pegawai disusun menggunakan binary tree agar penyimpanan dan pencarian data dapat dilakukan secara lebih teratur. Selain itu, setiap pegawai memiliki data absensi masing-masing yang disimpan menggunakan multi linked list, sehingga satu pegawai dapat memiliki banyak catatan absensi yang saling terhubung tanpa tercampur dengan data pegawai lain.

## 3. Usecase Diagram

![](output/1.png)

Penjelasan :

Actor :
Admin & User Biasa

Usecase :
ada 11 Usecase dimana yang bisa diakses oleh kedua aktor itu ada melihat profil, melakukkan absensi, melihat riwayat absensi, melakukan Logout, dan keluar program . Sementara usecase yang hanya bisa di akses oleh admin itu ada melihat daftar pegawai, mencari pegawai, mengelola pegawai dimana di dalam mengelola pegawai bisa tambah pegawai, ubah pegawai, dan hapus pegawai.

## 4. Pembagian Tugas
### 4.1 Tugas yang dikerjakan bersama
- seluruh isi file tubes.h atau headernya dikerjakan bersama
- seluruh isi file main.cpp dikerjakan bersama
- usecase diagram dikerjakan bersama
- laporan dikerjakan bersama

### 4.2 Tugas yang dikerjakan oleh Rahmat Ahdaf Albariza di file tubes.cpp
- Membuat fungsi void inorderBST
- Membuat fungsi adrPegawai findMin
- Membuat fungsi adrPegawai hapusPegawai
- Membuat fungsi void hapusPegawai
- Membuat fungsi void cariPegawai
- Membuat fungsi void saveCSVHelper dan void saveCSV

### 4.3 Tugas yang dikerjakan oleh Fa'iq Jagadhita Hardiana di file tubes.cpp
- Membuat fungsi void tambahPegawai
- Membuat fungsi void ubahPegawai
- Membuat fungsi void tambahAbsensi
- Membuat fungsi void tampilAbsensi
- Membuat fungsi void loadCSV

### 4.4 Tugas yang dikerjakan oleh Arzaqi Fatih Muttaqin di file tubes.cpp
- Membuat fungsi adrPegawai createPegawai
- Membuat fungsi void insertBST
- Membuat fungsi adrPegawai searchBST

## 5. Kesuliatan Selama Mengerjakan Tugas Besar
- Komunikasi Antar Anggota
  jadi karena banyaknya hari libur dan banyak yang pulang ke rumah masing-masing membuat komunikasi kami dalam mengerjakan tubes kurang baik.
- Database CSV
  Membaca dan menyimpan data absensi pegawai dari/ke CSV dengan format yang konsisten cukup sulit, karena baru pertama kali.

## 6. Program/Codingan
### 6.1 tubes.h
```cpp
#ifndef TUBES_H
#define TUBES_H

#include <iostream>
#include <string>
using namespace std;

/* ===== ABSENSI (Linked List) ===== */
struct Absensi {
    string tanggal;
    string jamMasuk;
    Absensi* next;
};

// Pegawai (BST)
struct Pegawai {
    int id;
    string nama;
    string jabatan;
    string role;
    Absensi* firstAbsensi;
    Pegawai* left;
    Pegawai* right;
};

typedef Pegawai* adrPegawai;

// BST
adrPegawai createPegawai(int id, string nama, string jabatan, string role);
void insertBST(adrPegawai& root, adrPegawai p);
adrPegawai searchBST(adrPegawai root, int id);
void inorderBST(adrPegawai root);

// khusus admin
void tambahPegawai(adrPegawai& root);
void ubahPegawai(adrPegawai root);
adrPegawai findMin(adrPegawai root);
adrPegawai hapusPegawai(adrPegawai root, int id);
void hapusPegawai(adrPegawai &root);
void cariPegawai(adrPegawai root);

/* ===== ABSENSI ===== */
void tambahAbsensi(adrPegawai p, string tanggal, string jam);
void tampilAbsensi(adrPegawai p);

/* ===== FILE ===== */
void loadCSV(adrPegawai& root, string filename);
void saveCSV(adrPegawai root, string filename);

#endif
```

Penjelasan : 

File tubes.h merupakan header file yang berfungsi sebagai pusat deklarasi struktur data dan prototipe fungsi yang digunakan dalam program Aplikasi Data Pegawai. Header ini dirancang untuk memisahkan antara deklarasi dan implementasi program, sehingga meningkatkan keterbacaan kode, kemudahan pemeliharaan, serta penerapan konsep modular dalam pemrograman C++.

Pada bagian awal, didefinisikan struktur Absensi yang direpresentasikan menggunakan Linked List. Struktur ini menyimpan informasi tanggal dan jam masuk pegawai, serta pointer next yang menunjuk ke data absensi berikutnya. Dengan menggunakan linked list, setiap pegawai dapat memiliki jumlah data absensi yang dinamis (tidak terbatas), sesuai dengan konsep relasi one-to-many antara pegawai dan absensi.

Struktur Pegawai merepresentasikan data utama pegawai dan diorganisasikan menggunakan Binary Search Tree (BST). Setiap node Pegawai menyimpan atribut berupa id, nama, jabatan, dan role (admin atau user), serta pointer firstAbsensi yang menunjuk ke linked list absensi milik pegawai tersebut. Selain itu, terdapat pointer left dan right yang digunakan untuk membentuk struktur BST berdasarkan id pegawai, sehingga proses pencarian, penambahan, dan penghapusan data dapat dilakukan secara efisien.

Tipe data adrPegawai didefinisikan sebagai pointer ke struktur Pegawai untuk mempermudah penulisan dan pemanggilan fungsi. Selanjutnya, dideklarasikan fungsi-fungsi dasar BST seperti createPegawai, insertBST, searchBST, dan inorderBST. Fungsi-fungsi ini digunakan untuk membuat node pegawai baru, menyisipkan data ke dalam BST, mencari pegawai berdasarkan ID, serta menampilkan data pegawai secara terurut.

Bagian khusus admin menyediakan fungsi-fungsi pengelolaan data pegawai, antara lain tambahPegawai, ubahPegawai, hapusPegawai, dan cariPegawai. Fungsi findMin digunakan sebagai pendukung dalam proses penghapusan node BST, khususnya saat menghapus node yang memiliki dua anak. Dengan adanya pemisahan fitur admin ini, sistem mampu menerapkan konsep hak akses (role-based access control) secara sederhana.

Selanjutnya, pada bagian ABSENSI, dideklarasikan fungsi tambahAbsensi dan tampilAbsensi. Fungsi tambahAbsensi digunakan untuk menambahkan data absensi baru ke linked list milik pegawai tertentu, sedangkan tampilAbsensi berfungsi untuk menampilkan seluruh riwayat absensi dari pegawai tersebut. Implementasi ini menunjukkan penggunaan kombinasi struktur data BST dan Multi Linked List (satu tingkat) dalam satu sistem.

Terakhir, bagian FILE berisi deklarasi fungsi loadCSV dan saveCSV yang digunakan untuk membaca dan menyimpan data pegawai ke dalam file CSV. Fungsi loadCSV bertugas memuat data awal pegawai dari file ke dalam BST saat program dijalankan, sedangkan saveCSV digunakan untuk menyimpan kembali data pegawai ke dalam file saat program selesai. Dengan fitur ini, data pegawai dapat disimpan secara permanen dan digunakan kembali pada eksekusi program berikutnya.

### 6.2 tubes.cpp
[Penjelasan tentang unguided kedua, termasuk kode dan cara implementasinya.]

### 6.3 main.cpp
[Penjelasan tentang unguided ketiga, termasuk aplikasi atau pengembangan lebih lanjut yang Anda lakukan.]

### 6.4 data_pegawai
[Penjelasan tentang unguided ketiga, termasuk aplikasi atau pengembangan lebih lanjut yang Anda lakukan.]

## 7. Referensi
1. [Buku atau artikel yang Anda gunakan untuk referensi, jika ada]
2. [Sumber lain yang relevan dengan topik praktikum ini]
