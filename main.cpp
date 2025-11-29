#include "library.h"

int main(){
    BookList books;
    MemberList members;
    StackList stack;
    QueueList queue;

    int pil;
    string id, name, code;

    while(true){
        cout << "\n=== MENU AWAL ===\n";
        cout << "1. Login Admin\n";
        cout << "2. Login Member\n";
        cout << "3. Register Member\n";
        cout << "4. Lihat Buku\n";
        cout << "0. Keluar\nPilih: ";
        cin >> pil; cin.ignore();

        if(pil == 0) break;

        // ===== ADMIN =====
        if(pil == 1){
            string u,p;
            cout << "Username: "; getline(cin,u);
            cout << "Password: "; getline(cin,p);
            if(u=="admin" && p=="admin"){
                int a;
                do{
                    cout << "\n--- Admin Menu ---\n";
                    cout << "1. Tambah Buku\n";
                    cout << "2. Lihat Buku\n";
                    cout << "3. Cari Buku\n";
                    cout << "4. Hapus Buku\n";
                    cout << "5. Lihat Semua Antrian\n";
                    cout << "6. Proses Antrian (Dequeue)\n";
                    cout << "0. Logout\nPilih: ";
                    cin >> a; cin.ignore();

                    if(a == 1){
                        cout << "Kode: "; getline(cin,code);
                        cout << "Judul: "; getline(cin,name);
                        int y; cout << "Tahun: "; cin >> y; cin.ignore();
                        books.addBook({code,name,y});
                    }
                    else if(a == 2) books.displayBooks();
                    else if(a == 3){
                        cout << "Kode cari: "; getline(cin,code);
                        if(books.searchBook(code)) cout << "Ditemukan!\n";
                        else cout << "Tidak ditemukan\n";
                    }
                    else if(a == 4){
                        cout << "Kode hapus: "; getline(cin,code);
                        books.deleteBook(code);
                    }
                    else if(a == 5) queue.displayQueue();
                    else if(a == 6){
                        string mem;
                        string result = queue.dequeue(mem);
                        if(result=="") cout << "Antrian kosong\n";
                        else cout << mem << " meminjam buku " << result << endl;
                    }
                } while(a != 0);
            }
            else cout << "Login salah!\n";
        }

        // ===== LOGIN MEMBER =====
        else if(pil == 2){
            cout << "ID Member: "; getline(cin,id);
            MemberNode *m = members.searchMember(id);
            if(!m){
                cout << "Belum terdaftar! Daftar dulu via menu 3.\n";
            } else {
                int mb;
                do{
                    cout << "\n--- Menu Member ---\n";
                    cout << "1. Lihat Buku\n";
                    cout << "2. Masukkan Buku ke Stack\n";
                    cout << "3. Ajukan Pinjam (Queue)\n";
                    cout << "4. Lihat Antrian Saya\n";
                    cout << "0. Logout\nPilih: ";
                    cin >> mb; cin.ignore();

                    if(mb == 1) books.displayBooks();
                    else if(mb == 2){
                        cout << "Kode buku: "; getline(cin,code);
                        if(books.searchBook(code)) stack.push(code);
                        else cout << "Buku tidak ditemukan\n";
                    }
                    else if(mb == 3){
                        string bk = stack.pop();
                        if(bk == "") cout << "Stack kosong!\n";
                        else queue.enqueue(id, bk);
                    }
                    else if(mb == 4){
                        cout << "Antrian Anda:\n";
                        queue.displayQueueByMember(id);
                    }
                } while(mb != 0);
            }
        }

        // ===== REGISTER =====
        else if(pil == 3){
            cout << "Buat ID: "; getline(cin,id);
            if(members.searchMember(id)){
                cout << "ID sudah dipakai!\n";
            } else {
                cout << "Nama: "; getline(cin,name);
                members.registerMember({id,name});
            }
        }

        // ===== GUEST VIEW =====
        else if(pil == 4){
            books.displayBooks();
        }
    }

    cout << "Program selesai.\n";
    return 0;
}