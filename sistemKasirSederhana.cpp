//sistem kasir menggunakan 

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

//menyimpan data produk

struct Produk {
    string nama;
    int harga;
    int jumlah;
    int subtotal;
};

int main() {
    vector<Produk> keranjang;
    char pilihan;
    int totalKeseluruhan = 0;
    int tunai = 0;
    int kembalian= 0;
    
    cout << "========================================\n";
    cout << "            KASIR MINIMARKET            \n";
    cout << "========================================\n";
    
    //loop product input
    
    do {
        Produk p;
        
        cout << "\nNama Produk        : ";
        getline(cin >> ws, p.nama);
        
        cout << "Harga Satuan(Rp)   : ";
        cin >> p.harga;
        
        cout << "Jumlah Beli        : ";
        cin >> p.jumlah;
        
        p.subtotal = p.harga * p.jumlah;
        keranjang.push_back(p);
        
        cout << "Tambah produk lain?? (y/n): ";
        cin >> pilihan;
        
    } while (pilihan == 'y' || pilihan == 'Y');
    
    //hitung total keseluruhan 
    for (const auto& item : keranjang) {
        totalKeseluruhan += item.subtotal;
    
    }
    
    //input pembayaran uang tunai
    
    cout << "\n========================================\n";
    cout << "TOTAL YANG HARUS DIBAYAR: Rp" << totalKeseluruhan << endl;
    
    do {
        cout << "Uang tunai / bayar      : Rp";
        cin >> tunai;
        if (tunai < totalKeseluruhan) {
            cout << "Uang tidak cukup silahkan masukan dengan benar\n";
        }
    } while(tunai < totalKeseluruhan);
    
    //menghitung kembalian
    
    kembalian = tunai - totalKeseluruhan;
    
    cout << "\n========================================\n";
    cout << "              NOTA PEMBELIAN            \n";
    cout << "========================================\n";
    
    
    cout << left
         << "| " << setw(12) << "Nama Produk"
         << "| Rp" << setw(10) << "Harga"
         << "| " << setw(8) << "Jumlah"
         << "| " << setw(9) << "Subtotal" << " |\n";
    cout << "========================================\n";
    
    for (const auto& item : keranjang) {
        cout << "| " << setw(12) << item.nama
             << "| Rp" << setw(10) << item.harga
             << "| " << setw(8) << item.jumlah
             << "| Rp" << setw(9) << item.subtotal << " |\n";
    }
    
    cout << "========================================\n";
    cout << "| TOTAL KESELURUHAN : Rp" << setw(12) << right << totalKeseluruhan << " |\n";
    cout << "| TUNAI / BAYAR     : Rp" << setw(12) << right << tunai << " |\n";
    cout << "| KEMBALIAN         : Rp" << setw(12) << right << kembalian << " |\n";
    cout << "========================================\n";
    cout << "     TERIMAKASIH SUDAH BERBELANJA       \n";
    cout << "========================================\n";
    
    return 0;
    
}