#include "data.h"

int main() {
    int pilih;
    do {
        tampilMenuUtama();
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            string u, p;
            cout << "Username: "; cin >> u;
            cout << "Password: "; cin >> p;
            if (u == "admin" && p == "admin")
                menuAdmin();
            else
                cout << "Login gagal\n";
        }

        else if (pilih == 2) {
            string id;
            cout << "ID Member: ";
            cin >> id;
            MemberNode* m = cariMember(id);
            if (m)
                menuMember(m);
            else
                cout << "Member tidak ditemukan\n";
        }

        else if (pilih == 3) {
            string id, nama;
            cout << "ID   : "; cin >> id;
            cout << "Nama : "; cin.ignore(); getline(cin, nama);
            tambahMember(id, nama);
        }

    } while (pilih != 0);

    return 0;
}
