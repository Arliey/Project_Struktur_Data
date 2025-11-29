#include "library.h"

BookList::BookList() { head = tail = NULL; }
BookList::~BookList() {
    while (head) {
        BookNode* p = head;
        head = head->next;
        delete p;
    }
}
bool BookList::isEmpty() { return head == NULL; }

void BookList::insertLast(Book b) {
    BookNode* node = new BookNode{b, NULL, NULL};
    if (isEmpty()) {
        head = tail = node;
    } else {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    cout << "Buku ditambahkan!\n";
}

BookNode* BookList::search(string code) {
    BookNode* p = head;
    while (p) {
        if (p->data.code == code) return p;
        p = p->next;
    }
    return NULL;
}

void BookList::remove(string code) {
    BookNode* p = search(code);
    if (!p) { cout << "Tidak ditemukan.\n"; return; }

    if (p == head) head = p->next;
    if (p == tail) tail = p->prev;
    if (p->prev) p->prev->next = p->next;
    if (p->next) p->next->prev = p->prev;
    delete p;
    cout << "Buku dihapus!\n";
}

void BookList::display() {
    if (isEmpty()) { cout << "Belum ada buku.\n"; return; }

    BookNode* p = head;
    while (p) {
        cout << p->data.code << " | " << p->data.title << " | " << p->data.year << endl;
        p = p->next;
    }
}

MemberList::MemberList() { head = NULL; }
MemberList::~MemberList() {
    while (head) {
        MemberNode* p = head;
        head = head->next;
        delete p;
    }
}
bool MemberList::isEmpty() { return head == NULL; }

void MemberList::insertFirst(Member m) {
    MemberNode* node = new MemberNode{m, head};
    head = node;
    cout << "Anggota ditambahkan!\n";
}

MemberNode* MemberList::search(string id) {
    MemberNode* p = head;
    while (p) {
        if (p->data.id == id) return p;
        p = p->next;
    }
    return NULL;
}

void MemberList::remove(string id) {
    MemberNode* p = head;
    MemberNode* prev = NULL;
    while (p) {
        if (p->data.id == id) break;
        prev = p;
        p = p->next;
    }
    if (!p) { cout << "Tidak ditemukan.\n"; return; }

    if (prev == NULL) head = p->next;
    else prev->next = p->next;
    delete p;
    cout << "Anggota dihapus!\n";
}

void MemberList::display() {
    if (isEmpty()) { cout << "Belum ada anggota.\n"; return; }
    MemberNode* p = head;
    while (p) {
        cout << p->data.id << " | " << p->data.name << endl;
        p = p->next;
    }
}

StackList::StackList() { top = NULL; }
bool StackList::isEmpty() { return top == NULL; }

void StackList::push(string code) {
    StackNode* node = new StackNode{code, top};
    top = node;
    cout << "Buku dimasukkan ke stack.\n";
}

string StackList::pop() {
    if (isEmpty()) return "";
    StackNode* p = top;
    string code = p->code;
    top = top->next;
    delete p;
    return code;
}

void StackList::display() {
    if (isEmpty()) { cout << "Stack kosong.\n"; return; }
    StackNode* p = top;
    while (p) {
        cout << p->code << endl;
        p = p->next;
    }
}

QueueList::QueueList() { front = rear = NULL; }
bool QueueList::isEmpty() { return front == NULL; }

void QueueList::enqueue(string code) {
    QueueNode* node = new QueueNode{code, NULL};
    if (isEmpty()) front = rear = node;
    else {
        rear->next = node;
        rear = node;
    }
    cout << "Masuk antrian!\n";
}

string QueueList::dequeue() {
    if (isEmpty()) return "";
    QueueNode* p = front;
    string code = p->code;
    front = front->next;
    if (!front) rear = NULL;
    delete p;
    return code;
}

void QueueList::display() {
    if (isEmpty()) { cout << "Antrian kosong.\n"; return; }
    QueueNode* p = front;
    while (p) {
        cout << p->code << endl;
        p = p->next;
    }
}