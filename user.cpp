#include "data.h"

bool pinjamBuku(MemberNode* m, BookNode* b) {
    if (!m || !b || b->data.dipinjam)
        return false;

    LoanNode* L = new LoanNode;
    L->member = m;
    L->book = b;

    L->nextMember = m->loanHead;
    m->loanHead = L;

    L->nextBook = b->loanHead;
    b->loanHead = L;

    b->data.dipinjam = true;
    return true;
}

bool kembalikanBuku(MemberNode* m, BookNode* b) {
    if (!m || !b) return false;

    LoanNode* curr = m->loanHead;
    LoanNode* prev = NULL;

    while (curr && curr->book != b) {
        prev = curr;
        curr = curr->nextMember;
    }

    if (!curr) return false;

    if (!prev)
        m->loanHead = curr->nextMember;
    else
        prev->nextMember = curr->nextMember;

    b->loanHead = NULL;
    b->data.dipinjam = false;

    delete curr;
    return true;
}

void menuMember(MemberNode* m) {
    int pilih;
    do {
        cout << "\n=== MENU MEMBER ===\n";
        cout << "1. Lihat Daftar Buku\n";
        cout << "2. Pinjam Buku\n";
        cout << "3. Kembalikan Buku\n";
        cout << "4. Buku yang Dipinjam\n";
        cout << "0. Logout\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            BookNode* b = headBook;
            while (b) {
                cout << b->data.kode << " - " << b->data.judul;
                cout << (b->data.dipinjam ? " (Dipinjam)\n" : " (Tersedia)\n");
                b = b->next;
            }
        }

        else if (pilih == 2) {
            string kode;
            cout << "Kode Buku: ";
            cin >> kode;
            BookNode* b = cariBuku(kode);
            cout << (pinjamBuku(m, b) ? "Berhasil\n" : "Gagal\n");
        }

        else if (pilih == 3) {
            string kode;
            cout << "Kode Buku: ";
            cin >> kode;
            BookNode* b = cariBuku(kode);
            cout << (kembalikanBuku(m, b) ? "Berhasil\n" : "Gagal\n");
        }

        else if (pilih == 4) {
            LoanNode* L = m->loanHead;
            if (!L) cout << "Tidak ada\n";
            while (L) {
                cout << "- " << L->book->data.judul << endl;
                L = L->nextMember;
            }
        }

    } while (pilih != 0);
}
