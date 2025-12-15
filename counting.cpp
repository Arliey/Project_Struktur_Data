#include "data.h"

int hitungMember() {
    int total = 0;
    MemberNode* m = headMember;
    while (m) {
        total++;
        m = m->next;
    }
    return total;
}
