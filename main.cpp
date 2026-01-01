#include "tubes.h"

int main() {
    adrPegawai root = NULL;
    loadCSV(root, "data_pegawai.csv");

    bool programJalan = true;

    while (programJalan) {
        int idLogin;
        cout << "\n===== LOGIN PEGAWAI =====\n";
        cout << "Masukkan ID Pegawai (0 untuk keluar): ";
        cin >> idLogin;

        if (idLogin == 0) {
            cout << "Keluar dari program...\n";
            break;
        }

        adrPegawai user = searchBST(root, idLogin);
        if (!user) {
            cout << "ID tidak ditemukan!\n";
            continue;
        }

        bool loginAktif = true;

        /* ================= ADMIN ================= */
        if (user->role == "admin") {
            while (loginAktif) {
                int pilih;
                cout << "\n===== MENU ADMIN =====\n";
                cout << "1. Lihat Profil Saya\n";
                cout << "2. Lihat Daftar Pegawai\n";
                cout << "3. Absensi Masuk\n";
                cout << "4. Riwayat Absensi\n";
                cout << "5. Kelola Pegawai\n";
                cout << "6. Cari Pegawai\n";
                cout << "7. Logout Akun\n";
                cout << "8. Keluar Program\n";
                cout << "Pilih: ";
                cin >> pilih;

                switch (pilih) {
                case 1:
                    cout << "\nID: " << user->id
                         << "\nNama: " << user->nama
                         << "\nJabatan: " << user->jabatan
                         << "\nRole: " << user->role << endl;
                    break;

                case 2:
                    cout << "=================================================================================\n";
                    cout << "| ID   | Nama            | Jabatan           | Role  | Riwayat Absensi            |\n";
                    cout << "=================================================================================\n";
                    inorderBST(root);
                    break;
