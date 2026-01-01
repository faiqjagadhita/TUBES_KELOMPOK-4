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
