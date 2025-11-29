#include "library.h"

// ===== BOOK DLL =====
BookList::BookList(){ head = tail = NULL; }

bool BookList::isEmpty(){ return head == NULL; }

void BookList::addBook(Book data){
    BookNode *node = new BookNode{data, NULL, NULL};
    if(isEmpty()) head = tail = node;
    else {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    cout << "Buku berhasil ditambahkan!\n";
}

void BookList::displayBooks(){
    if(isEmpty()) {
        cout << "Tidak ada buku.\n";
        return;
    }
    BookNode *p = head;
    while(p){
        cout << p->data.code << " - " << p->data.title << " (" 
             << p->data.year << ")\n";
        p = p->next;
    }
}

BookNode* BookList::searchBook(string code){
    BookNode *p = head;
    while(p){
        if(p->data.code == code) return p;
        p = p->next;
    }
    return NULL;
}

void BookList::deleteBook(string code){
    BookNode *p = searchBook(code);
    if(!p){
        cout << "Buku tidak ditemukan.\n";
        return;
    }
    if(p == head) head = p->next;
    if(p == tail) tail = p->prev;
    if(p->prev) p->prev->next = p->next;
    if(p->next) p->next->prev = p->prev;
    delete p;
    cout << "Buku berhasil dihapus!\n";
}


// ===== MEMBER SLL =====
MemberList::MemberList(){ head = NULL; }

bool MemberList::isEmpty(){ return head == NULL; }

void MemberList::registerMember(Member data){
    MemberNode *node = new MemberNode{data, head};
    head = node;
    cout << "Registrasi sukses! ID: " << data.id << endl;
}

MemberNode* MemberList::searchMember(string id){
    MemberNode *p = head;
    while(p){
        if(p->data.id == id) return p;
        p = p->next;
    }
    return NULL;
}

void MemberList::displayMembers(){
    MemberNode *p = head;
    while(p){
        cout << p->data.id << " - " << p->data.name << endl;
        p = p->next;
    }
}


// ===== STACK =====
StackList::StackList(){ top = NULL; }

bool StackList::isEmpty(){ return top == NULL; }

void StackList::push(string code){
    StackNode *node = new StackNode{code, top};
    top = node;
    cout << "Buku masuk stack.\n";
}

string StackList::pop(){
    if(isEmpty()) return "";
    StackNode *p = top;
    string code = p->bookCode;
    top = top->next;
    delete p;
    return code;
}

void StackList::displayStack(){
    if(isEmpty()) { cout << "Stack kosong.\n"; return; }
    StackNode *p = top;
    while(p){
        cout << p->bookCode << endl;
        p = p->next;
    }
}


// ===== QUEUE =====
QueueList::QueueList(){ front = rear = NULL; }

bool QueueList::isEmpty(){ return front == NULL; }

void QueueList::enqueue(string memberID, string bookCode){
    QueueNode *node = new QueueNode{memberID, bookCode, NULL};
    if(isEmpty()) front = rear = node;
    else {
        rear->next = node;
        rear = node;
    }
    cout << "Permintaan peminjaman masuk antrian.\n";
}

string QueueList::dequeue(string &outMember){
    if(isEmpty()) return "";
    QueueNode *p = front;
    string code = p->bookCode;
    outMember = p->memberID;
    front = front->next;
    if(!front) rear = NULL;
    delete p;
    return code;
}

void QueueList::displayQueue(){
    if(isEmpty()) { cout << "Antrian kosong.\n"; return; }
    QueueNode *p = front;
    while(p){
        cout << p->memberID << " → " << p->bookCode << endl;
        p = p->next;
    }
}

void QueueList::displayQueueByMember(string memberID){
    QueueNode *p = front;
    bool found = false;
    while(p){
        if(p->memberID == memberID){
            cout << p->bookCode << endl;
            found = true;
        }
        p = p->next;
    }
    if(!found) cout << "Tidak ada antrian.\n";
}