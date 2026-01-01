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

void ubahPegawai(adrPegawai root) {
    int id, pilihMenu;
    adrPegawai p;
    char pilih;

    while (true) {
        cout << "Masukkan ID Pegawai: ";
        cin >> id;

        p = searchBST(root, id);
        if (!p) {
            cout << "ID tidak ada!\n";
            cout << "Masukkan ID lagi? (y/n): ";
            cin >> pilih;

            if (pilih == 'n' || pilih == 'N')
                return;
        } else {
            break;
        }
    }

    cin.ignore();

    bool selesai = false;
    while (!selesai) {
        cout << "\n===== MENU UBAH DATA PEGAWAI =====\n";
        cout << "1. Ubah Nama\n";
        cout << "2. Ubah Jabatan\n";
        cout << "3. Ubah Role\n";
        cout << "4. Selesai\n";
        cout << "Pilih: ";
        cin >> pilihMenu;
        cin.ignore();

        switch (pilihMenu) {
        case 1:
            cout << "Nama Baru: ";
            getline(cin, p->nama);
            cout << "Nama berhasil diubah!\n";
            break;

        case 2: {
            bool valid = false;
            while (!valid) {
                string jabatanBaru;
                cout << "Jabatan Baru: ";
                getline(cin, jabatanBaru);
                if (jabatanBaru == "Direktur Utama") {
                    // Cek apakah sudah ada Direktur Utama selain p
                    bool adaDirektur = false;
                    adrPegawai stack[100];
                    int top = -1;
                    adrPegawai curr = root;

                    while (curr || top != -1) {
                        while (curr) {
                            stack[++top] = curr;
                            curr = curr->left;
                        }
                        curr = stack[top--];

                        if (curr != p && curr->jabatan == "Direktur Utama") {
                            adaDirektur = true;
                            break;
                        }
                        curr = curr->right;
                    }
                    if (adaDirektur) {
                        cout << "Gagal! Sudah ada Direktur Utama lain.\n";
                        cout << "Masukkan jabatan lagi!\n";
                        continue; // suruh input ulang jabatan
                    }
                }

                // Jika lolos cek, ubah jabatan
                p->jabatan = jabatanBaru;
                cout << "Jabatan berhasil diubah!\n";
                valid = true;
            }
            break;
        }



        case 3:
            cout << "Role Baru (admin/user biasa): ";
            getline(cin, p->role);
            cout << "Role berhasil diubah!\n";
            break;

        case 4:
            selesai = true;
            cout << "Selesai mengubah data pegawai.\n";
            break;

        default:
            cout << "Pilihan tidak valid!\n";
        }
    }
}

adrPegawai findMin(adrPegawai root) {
    while (root->left) root = root->left;
    return root;
}

adrPegawai hapusPegawai(adrPegawai root, int id) {
    if (!root) return root;

    if (id < root->id)
        root->left = hapusPegawai(root->left, id);
    else if (id > root->id)
        root->right = hapusPegawai(root->right, id);
    else {
        if (!root->left) {
            adrPegawai temp = root->right;
            delete root;
            return temp;
        }
        if (!root->right) {
            adrPegawai temp = root->left;
            delete root;
            return temp;
        }

        adrPegawai temp = findMin(root->right);
        root->id = temp->id;
        root->nama = temp->nama;
        root->jabatan = temp->jabatan;
        root->role = temp->role;
        root->right = hapusPegawai(root->right, temp->id);
    }
    return root;
}

void hapusPegawai(adrPegawai &root) {
    int id;
    adrPegawai cek;
    char pilih;

    while (true) {
        cout << "Masukkan ID Pegawai yang akan dihapus: ";
        cin >> id;

        cek = searchBST(root, id);
        if (!cek) {
            cout << "ID tidak ada!\n";
            cout << "Coba lagi? (y/n): ";
            cin >> pilih;

            if (pilih == 'n' || pilih == 'N')
                return;
        } else {
            break;
        }
    }

    root = hapusPegawai(root, id);
    cout << "Pegawai berhasil dihapus.\n";
}

void cariPegawai(adrPegawai root) {
    int id;
    adrPegawai p;
    char pilih;

    while (true) {
        cout << "Masukkan ID Pegawai: ";
        cin >> id;

        p = searchBST(root, id);
        if (!p) {
            cout << "ID tidak ada!\n";
            cout << "Cari lagi? (y/n): ";
            cin >> pilih;

            if (pilih == 'n' || pilih == 'N')
                return;
        } else {
            break;
        }
    }

    cout << "\n===== DATA PEGAWAI =====\n";
    cout << "ID      : " << p->id << endl;
    cout << "Nama    : " << p->nama << endl;
    cout << "Jabatan : " << p->jabatan << endl;
    cout << "Role    : " << p->role << endl;

    cout << "\n===== RIWAYAT ABSENSI =====\n";

    if (p->firstAbsensi == NULL) {
        cout << "Belum ada riwayat absensi.\n";
    } else {
        Absensi* a = p->firstAbsensi;
        int no = 1;
        while (a) {
            cout << no++ << ". "
                 << a->tanggal << " | "
                 << a->jamMasuk << endl;
            a = a->next;
        }
    }
}

// Menambahkan Absensi
void tambahAbsensi(adrPegawai p, string tanggal, string jam) {
    Absensi* a = new Absensi;
    a->tanggal = tanggal;
    a->jamMasuk = jam;
    a->next = NULL;

    if (!p->firstAbsensi) {
        // Jika belum ada absensi sama sekali
        p->firstAbsensi = a;
    } else {
        // Cari node terakhir
        Absensi* curr = p->firstAbsensi;
        while (curr->next) {
            curr = curr->next;
        }
        // Tambahkan di akhir
        curr->next = a;
    }
}
