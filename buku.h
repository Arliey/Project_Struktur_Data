#ifndef BUKU_H
#define BUKU_H

#include <string>
using namespace std;

/* forward declaration */
struct LoanNode;

/* ====== PARENT BUKU ====== */
struct Book {
    string kode;
    string judul;
    bool dipinjam;
};

struct BookNode {
    Book data;
    BookNode* next;
    LoanNode* loanHead;
};

/* ====== HEAD BUKU ====== */
extern BookNode* headBook;

/* ====== FUNGSI BUKU ====== */
BookNode* cariBuku(string kode);
void tambahBuku(string kode, string judul);

#endif
