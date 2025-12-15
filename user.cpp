#include "data.h"

/*PINJAM */
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

/*KEMBALI */
bool kembalikanBuku(MemberNode* m, BookNode* b) {
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
