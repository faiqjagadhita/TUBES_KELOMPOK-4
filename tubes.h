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
