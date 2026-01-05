#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string>
#include "buku.h"

using namespace std;

struct Member {
    string id;
    string nama;
};

struct MemberNode {
    Member data;
    MemberNode* next;
    struct LoanNode* loanHead;
};

struct LoanNode {
    MemberNode* member;
    BookNode* book;
    LoanNode* nextMember;
    LoanNode* nextBook;
};

extern MemberNode* headMember;

MemberNode* cariMember(string id);
void tambahMember(string id, string nama);

bool pinjamBuku(MemberNode* m, BookNode* b);
bool kembalikanBuku(MemberNode* m, BookNode* b);

void menuAdmin();
void menuMember(MemberNode* m);
void tampilMenuUtama();

#endif
