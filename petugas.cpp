#include "data.h"

MemberNode* headMember = NULL;
BookNode* headBook = NULL;

void tambahMember(string id, string nama) {
    MemberNode* baru = new MemberNode;
    baru->data.id = id;
    baru->data.nama = nama;
    baru->loanHead = NULL;
    baru->next = headMember;
    headMember = baru;
}

MemberNode* cariMember(string id) {
    MemberNode* p = headMember;
    while (p) {
        if (p->data.id == id)
            return p;
        p = p->next;
    }
    return NULL;
}

void tambahBuku(string kode, string judul) {
    BookNode* baru = new BookNode;
    baru->data.kode = kode;
    baru->data.judul = judul;
    baru->data.dipinjam = false;
    baru->loanHead = NULL;
    baru->next = headBook;
    headBook = baru;
}

BookNode* cariBuku(string kode) {
    BookNode* p = headBook;
    while (p) {
        if (p->data.kode == kode)
            return p;
        p = p->next;
    }
    return NULL;
}

/*BookNode* cariBukuJudul(string judul) {
    BookNode* p = headBook;
    while (p) {
        if (p->data.judul == judul)
            return p;
        p = p->next;
    }
    return NULL;
}
*/
bool updateBuku(string kode, string judulBaru) {
    BookNode* b = cariBuku(kode);
    if (!b) return false;
    b->data.judul = judulBaru;
    return true;
}

bool hapusBuku(string kode) {
    BookNode* curr = headBook;
    BookNode* prev = NULL;

    while (curr && curr->data.kode != kode) {
        prev = curr;
        curr = curr->next;
    }

    if (!curr || curr->data.dipinjam)
        return false;

    if (!prev)
        headBook = curr->next;
    else
        prev->next = curr->next;

    delete curr;
    return true;
}
