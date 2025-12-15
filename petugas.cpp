#include "data.h"

/*GLOBAL HEAD*/
MemberNode* headMember = NULL;
BookNode* headBook = NULL;

/*TAMBAH MEMBER */
void tambahMember(string id, string nama) {
    MemberNode* baru = new MemberNode;
    baru->data.id = id;
    baru->data.nama = nama;
    baru->loanHead = NULL;
    baru->next = headMember;
    headMember = baru;
}

/*TAMBAH BUKU */
void tambahBuku(string kode, string judul) {
    BookNode* baru = new BookNode;
    baru->data.kode = kode;
    baru->data.judul = judul;
    baru->data.dipinjam = false;
    baru->loanHead = NULL;
    baru->next = headBook;
    headBook = baru;
}

/*CARI MEMBER */
MemberNode* cariMember(string id) {
    MemberNode* p = headMember;
    while (p) {
        if (p->data.id == id)
            return p;
        p = p->next;
    }
    return NULL;
}

/* ====== CARI BUKU ====== */
BookNode* cariBuku(string kode) {
    BookNode* p = headBook;
    while (p) {
        if (p->data.kode == kode)
            return p;
        p = p->next;
    }
    return NULL;
}
