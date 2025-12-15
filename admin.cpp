#include "data.h"

void menuAdmin() {
    int pilih;
    do {
        cout << "\n--- MENU ADMIN ---\n";
        cout << "1. Tambah Buku\n";
        cout << "2. Lihat Semua Buku\n";
        cout << "3. Lihat Semua Peminjaman\n";
        cout << "0. Logout\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            string kode, judul;
            cout << "Kode Buku : "; cin >> kode;
            cout << "Judul Buku: "; cin.ignore(); getline(cin, judul);
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
