#include "library.h"

int main() {
    BookList books;
    MemberList members;
    StackList stack;
    QueueList queue;

    int menu, submenu;
    string code, title, id, name;
    int year;

    do {
        cout << "\nMenu Utama\n"
             << "1. Kelola Buku\n"
             << "2. Kelola Anggota\n"
             << "3. Stack Buku Sementara\n"
             << "4. Queue Antrian Peminjaman\n"
             << "0. Keluar\n"
             << "Pilih: ";
        cin >> menu;
        cin.ignore();

        switch(menu) {
        case 1:
            do {
                cout << "\nMenu Buku\n"
                     << "1. Tambah Buku\n"
                     << "2. Tampilkan Buku\n"
                     << "3. Cari Buku\n"
                     << "4. Hapus Buku\n"
                     << "0. Kembali\nPilih: ";
                cin >> submenu;
                cin.ignore();

                if (submenu == 1) {
                    cout << "Kode: "; getline(cin, code);
                    cout << "Judul: "; getline(cin, title);
                    cout << "Tahun: "; cin >> year; cin.ignore();
                    books.insertLast({code,title,year});
                } 
                else if (submenu == 2) books.display();
                else if (submenu == 3) {
                    cout << "Masukkan kode: "; getline(cin, code);
                    if (books.search(code)) cout << "Ditemukan!\n";
                    else cout << "Tidak ditemukan!\n";
                }
                else if (submenu == 4) {
                    cout << "Masukkan kode: "; getline(cin, code);
                    books.remove(code);
                }

            } while (submenu != 0);
            break;

        case 2:
            do {
                cout << "\nMenu Anggota\n"
                     << "1. Tambah\n"
                     << "2. Tampilkan\n"
                     << "3. Cari\n"
                     << "4. Hapus\n"
                     << "0. Kembali\nPilih: ";
                cin >> submenu;
                cin.ignore();

                if (submenu == 1) {
                    cout << "ID: "; getline(cin, id);
                    cout << "Nama: "; getline(cin, name);
                    members.insertFirst({id,name});
                }
                else if (submenu == 2) members.display();
                else if (submenu == 3) {
                    cout << "ID cari: "; getline(cin, id);
                    if (members.search(id)) cout << "Ditemukan!\n";
                    else cout << "Tidak ditemukan!\n";
                }
                else if (submenu == 4) {
                    cout << "ID hapus: "; getline(cin, id);
                    members.remove(id);
                }

            } while (submenu != 0);
            break;

        case 3:
            do {
                cout << "\nStack\n"
                     << "1. Push Buku\n"
                     << "2. Pop Buku\n"
                     << "3. Lihat Stack\n"
                     << "0. Kembali\nPilih: ";
                cin >> submenu;
                cin.ignore();

                if (submenu == 1) {
                    cout << "Kode buku: "; getline(cin, code);
                    stack.push(code);
                }
                else if (submenu == 2) {
                    string result = stack.pop();
                    if (result == "") cout << "Stack kosong.\n";
                    else cout << "Pop: " << result << endl;
                }
                else if (submenu == 3) stack.display();

            } while (submenu != 0);
            break;

        case 4:
            do {
                cout << "\nQueue\n"
                     << "1. Tambah antrian\n"
                     << "2. Proses antrian\n"
                     << "3. Lihat antrian\n"
                     << "0. Kembali\nPilih: ";
                cin >> submenu;
                cin.ignore();

                if (submenu == 1) {
                    cout << "Kode buku: "; getline(cin, code);
                    queue.enqueue(code);
                }
                else if (submenu == 2) {
                    string result = queue.dequeue();
                    if (result == "") cout << "Antrian kosong.\n";
                    else cout << "Diproses: " << result << endl;
                }
                else if (submenu == 3) queue.display();

            } while (submenu != 0);
            break;
        }

    } while (menu != 0);

    cout << "Program selesai!\n";
    return 0;
}