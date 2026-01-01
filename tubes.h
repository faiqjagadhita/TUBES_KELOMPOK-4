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
