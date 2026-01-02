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
Actor : Admin & User Biasa
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
= Membuat fungsi void insertBST
= Membuat fungsi adrPegawai searchBST

## 5. Unguided
### 5.1 Unguided 1
[Penjelasan tentang unguided pertama, termasuk kode yang telah diimplementasikan oleh Anda.]

### 5.2 Unguided 2
[Penjelasan tentang unguided kedua, termasuk kode dan cara implementasinya.]

### 5.3 Unguided 3
[Penjelasan tentang unguided ketiga, termasuk aplikasi atau pengembangan lebih lanjut yang Anda lakukan.]

## 6. Kesimpulan
[Isi dengan kesimpulan dari seluruh praktikum ini, apakah tujuan praktikum tercapai, dan bagaimana Anda mengimplementasikan dan memahami teori yang dipelajari.]

## 7. Referensi
1. [Buku atau artikel yang Anda gunakan untuk referensi, jika ada]
2. [Sumber lain yang relevan dengan topik praktikum ini]
