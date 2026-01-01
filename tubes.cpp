#include "tubes.h"
#include <fstream>
#include <sstream>
#include <iomanip>

// create pegawai
adrPegawai createPegawai(int id, string nama, string jabatan, string role) {
    adrPegawai p = new Pegawai;
    p->id = id;
    p->nama = nama;
    p->jabatan = jabatan;
    p->role = role;
    p->firstAbsensi = NULL; // riwayat absensi awal
    p->left = p->right = NULL;
    return p;
}

// BST
void insertBST(adrPegawai& root, adrPegawai p) {
    if (!root) root = p;
    else if (p->id < root->id) insertBST(root->left, p);
    else insertBST(root->right, p);
}

adrPegawai searchBST(adrPegawai root, int id) {
    if (!root || root->id == id) return root;
    if (id < root->id) return searchBST(root->left, id);
    return searchBST(root->right, id);
}

void inorderBST(adrPegawai root) {
    if (!root) return;

    inorderBST(root->left);

    Absensi* a = root->firstAbsensi;

    if (!a) {
        cout << "| " << setw(4) << root->id
             << " | " << setw(15) << root->nama
             << " | " << setw(16) << root->jabatan
             << " | " << setw(5) << root->role
             << " | " << setw(26) << "-" << " |\n";
    } else {
        bool pertama = true;
        while (a) {
            if (pertama) {
                cout << "| " << setw(4) << root->id
                     << " | " << setw(15) << root->nama
                     << " | " << setw(16) << root->jabatan
                     << " | " << setw(5) << root->role
                     << " | " << setw(10) << a->tanggal
                     << " " << setw(10) << a->jamMasuk << " |\n";
                pertama = false;
            } else {
                cout << "| " << setw(4) << " "
                     << " | " << setw(15) << " "
                     << " | " << setw(16) << " "
                     << " | " << setw(5) << " "
                     << " | " << setw(10) << a->tanggal
                     << " " << setw(10) << a->jamMasuk << " |\n";
            }
            a = a->next;
        }
    }

    cout << "---------------------------------------------------------------------------------\n";

    inorderBST(root->right);
}
