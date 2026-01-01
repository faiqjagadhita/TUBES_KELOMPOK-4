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

                case 3: {
                    string tanggal, jam;
                    cin.ignore();

                    cout << "Masukkan Tanggal (YYYY-MM-DD): ";
                    getline(cin, tanggal);

                    cout << "Masukkan Jam Masuk (HH:MM): ";
                    getline(cin, jam);

                    tambahAbsensi(user, tanggal, jam);
                    saveCSV(root, "data_pegawai.csv");
                    cout << "Absensi berhasil!\n";
                    break;
                }

                case 4:
                    tampilAbsensi(user);
                    break;

                case 5: { // KELOLA PEGAWAI
                    bool kelola = true;
                    while (kelola) {
                        int kp;
                        cout << "\n===== KELOLA PEGAWAI =====\n";
                        cout << "1. Tambah Pegawai\n";
                        cout << "2. Ubah Pegawai\n";
                        cout << "3. Hapus Pegawai\n";
                        cout << "4. Kembali ke Menu Admin\n";
                        cout << "Pilih: ";
                        cin >> kp;

                        switch (kp) {
                        case 1:
                            tambahPegawai(root);
                            saveCSV(root, "data_pegawai.csv");
                            break;

                        case 2:
                            ubahPegawai(root);
                            saveCSV(root, "data_pegawai.csv");
                            break;

                        case 3:
                            hapusPegawai(root);
                            saveCSV(root, "data_pegawai.csv");
                            break;

                        case 4:
                            kelola = false;
                            break;

                        default:
                            cout << "Pilihan tidak valid!\n";
                        }
                    }
                    break;
                }

                case 6:
                    cariPegawai(root);
                    saveCSV(root, "data_pegawai.csv");
                    break;

                case 7:
                    cout << "Logout akun...\n";
                    loginAktif = false;
                    break;

                case 8:
                    cout << "Keluar dari program...\n";
                    loginAktif = false;
                    programJalan = false;
                    break;

                default:
                    cout << "Pilihan tidak valid!\n";
                }
            }
        }

        // ================= USER =================
        else {
            while (loginAktif) {
                int pilih;
                cout << "\n===== MENU USER BIASA =====\n";
                cout << "1. Lihat Profil Saya\n";
                cout << "2. Absensi Masuk\n";
                cout << "3. Riwayat Absensi\n";
                cout << "4. Logout Akun\n";
                cout << "5. Keluar Program\n";
                cout << "Pilih: ";
                cin >> pilih;

                switch (pilih) {
                case 1:
                    cout << "\nID: " << user->id
                         << "\nNama: " << user->nama
                         << "\nJabatan: " << user->jabatan
                         << "\nRole: " << user->role << endl;
                    break;

                case 2: {
                    string tanggal, jam;
                    cin.ignore();

                    cout << "Masukkan Tanggal (YYYY-MM-DD): ";
                    getline(cin, tanggal);

                    cout << "Masukkan Jam Masuk (HH:MM): ";
                    getline(cin, jam);

                    tambahAbsensi(user, tanggal, jam);
                    saveCSV(root, "data_pegawai.csv");
                    cout << "Absensi berhasil!\n";
                    break;
                }

                case 3:
                    tampilAbsensi(user);
                    break;
