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
