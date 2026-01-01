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
