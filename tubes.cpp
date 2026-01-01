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

// Khusus Untuk Admin
void tambahPegawai(adrPegawai& root) {
    int id;
    string nama, jabatan, role;
    char pilih;

    while (true) {
        cout << "ID Pegawai: ";
        cin >> id;

        if (searchBST(root, id)) {
            cout << "ID sudah terpakai!\n";
            cout << "Masukkan ID lagi? (y/n): ";
            cin >> pilih;

            if (pilih == 'n' || pilih == 'N')
                return;
        } else {
            break;
        }
    }

    cin.ignore();
    cout << "Nama Pegawai: ";
    getline(cin, nama);

    bool adaDirektur;
    do {
        adaDirektur = false;
        cout << "Jabatan: ";
        getline(cin, jabatan);

        if (jabatan == "Direktur Utama") {
            adrPegawai stack[100];
            int top = -1;
            adrPegawai curr = root;

            while (curr || top != -1) {
                while (curr) {
                    stack[++top] = curr;
                    curr = curr->left;
                }
                curr = stack[top--];

                if (curr->jabatan == "Direktur Utama") {
                    adaDirektur = true;
                    break;
                }
                curr = curr->right;
            }

            if (adaDirektur) {
                cout << "Direktur Utama sudah ada!\n";
                cout << "Masukkan jabatan lagi? (y/n): ";
                cin >> pilih;
                cin.ignore();

                if (pilih == 'n' || pilih == 'N')
                    return;
            }
        }

    } while (jabatan == "Direktur Utama" && adaDirektur);

    cout << "Role (admin/user biasa): ";
    getline(cin, role);

    adrPegawai p = createPegawai(id, nama, jabatan, role);
    insertBST(root, p);

    cout << "Pegawai berhasil ditambahkan!\n";
}
