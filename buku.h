#ifndef BUKU_H
#define BUKU_H

#include <string>
using namespace std;

struct LoanNode;

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

extern BookNode* headBook;

BookNode* cariBuku(string kode);
BookNode* cariBukuJudul(string judul);

void tambahBuku(string kode, string judul);
bool updateBuku(string kode, string judulBaru);
bool hapusBuku(string kode);

#endif
