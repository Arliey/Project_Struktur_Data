#include "data.h"

void menuAdmin() {
    int pilih;
    do {
        cout << "\n=== MENU ADMIN ===\n";
        cout << "1. Tambah Buku\n";
        cout << "2. Lihat Daftar Buku\n";
        cout << "3. Cari Buku\n";
        cout << "4. Update Buku\n";
        cout << "5. Hapus Buku\n";
        cout << "6. Lihat Semua Peminjaman\n";
        cout << "0. Logout\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            string kode, judul;
            cout << "Kode  : "; cin >> kode;
            cout << "Judul : "; cin.ignore(); getline(cin, judul);
            tambahBuku(kode, judul);
        }

        else if (pilih == 2) {
            BookNode* b = headBook;
            while (b) {
                cout << b->data.kode << " - " << b->data.judul;
                cout << (b->data.dipinjam ? " (Dipinjam)\n" : " (Tersedia)\n");
                b = b->next;
            }
        }

        else if (pilih == 3) {
            string kode;
            cout << "Kode Buku: "; cin >> kode;
            BookNode* b = cariBuku(kode);
            if (b)
                cout << b->data.judul << endl;
            else
                cout << "Tidak ditemukan\n";
        }

        else if (pilih == 4) {
            string kode, judul;
            cout << "Kode Buku: "; cin >> kode;
            cout << "Judul Baru: "; cin.ignore(); getline(cin, judul);
            cout << (updateBuku(kode, judul) ? "Berhasil\n" : "Gagal\n");
        }

        else if (pilih == 5) {
            string kode;
            cout << "Kode Buku: "; cin >> kode;
            cout << (hapusBuku(kode) ? "Berhasil\n" : "Gagal\n");
        }

        else if (pilih == 6) {
            MemberNode* m = headMember;
            while (m) {
                cout << "\nMember: " << m->data.nama << endl;
                LoanNode* L = m->loanHead;
                if (!L) cout << "  Tidak meminjam\n";
                while (L) {
                    cout << "  - " << L->book->data.judul << endl;
                    L = L->nextMember;
                }
                m = m->next;
            }
        }

    } while (pilih != 0);
}
