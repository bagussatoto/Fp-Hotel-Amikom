/*

Nama Anggota Kelompok  

Bagus Budi Satoto	|	21.11.4076 
ALDYANSA	        |	21.11.4055 
Fajar Rizki	Y   	|	21.11.4095 
Arya Manunggal  	|	21.11.4058 
Achmad Fadillah P	|	21.11.4093 

*/

#include <iostream>               // header file untuk input/output
#include <windows.h>              // header file untuk windows
#include <ctime>                // header file untuk waktu
#define MAX 100                 // maksimal array
using namespace std;            // namespace STD_OUTPUT_HANDLER

int i;                      // variabel untuk looping
time_t now = time(0);           // variabel untuk waktu
char* dt = ctime(&now);         // variabel untuk waktu
struct kamar {              // struktur untuk kamar
    int kamar;              // variabel untuk nomor kamar
    int ranjang;            // variabel untuk nomor ranjang
    string fixkam;          // variabel untuk keterangan kamar
    int harga_kamar;            // variabel untuk harga kamar
}kmr;                       // nama variabel untuk struktur kamar

struct form {               // struktur untuk form
    int no_kamar[MAX];      // variabel untuk nomor kamar
    int lama;           // variabel untuk lama
    double diskon;      // variabel untuk diskon
}frm;               // nama variabel untuk struktur Form

struct data{                        // struktur untuk data
    int total, bayar, lunas;        // variabel untuk total, bayar, lunas
    int um;                         // variabel untuk uang muka
    int kurang[MAX];            // variabel untuk kurang
    string input, nama;         // variabel untuk input, nama
}psn;                       // nama variabel untuk struktur data

struct tampung{                             // struktur untuk tampung 
  string customer[MAX], alamat, lp;         // variabel untuk customer, alamat, lp
  int id_customer[MAX];                     // variabel untuk id customer
  char hp[20];                          // variabel untuk hp
} biodata;                          // nama variabel untuk struktur tampung

struct queue {                                                                                      // struktur untuk queue
    int awal, akhir, id, utang, lunas;                                                              // variabel untuk awal, akhir, id, utang, lunas
    string customer;                                                                                    // variabel untuk customer
    string daftar [MAX]={"Standart","Deluxe","Premium","Suite","Presidensial"};                     // variabel untuk daftar
    string DafSort [MAX]={"Standart\t       Double Bed","Standart\t       Single Bed",              
                       "Deluxe\t\t       Double Bed","Deluxe\t\t       Single Bed",
                       "Premium\t\t       Single Bed", "Premium\t\t       Double Bed",
                       "Suite\t\t       Single Bed", "Suite\t\t       Double Bed",
                       "Presidensial\t       Double Bed", "Presidensial\t       Single Bed"};
    string harga [MAX]={"Rp.   900.000 / Hari","Rp.   800.000 / Hari",                              // variabel untuk harga kamar
                        "Rp.   450.000 / Hari", "Rp.   400.000 / Hari", 
                        "Rp. 3.000.000 / Hari","Rp. 2.400.000 / Hari",
                        "Rp.   250.000 / Hari", "Rp.   200.000 / Hari",
                        "Rp. 1.800.000 / Hari","Rp. 1.500.000 / Hari",};
    int no_kmr;                                                                                     // variabel untuk nomor kamar
}antri;                                                                                     // nama variabel untuk struktur queue   

struct hapus {                      // struktur untuk hapus
    int pilihan;                    // variabel untuk pilihan
    string data;                    // variabel untuk data
}hps;                               // nama variabel untuk struktur hapus

// queue

void setcolor(unsigned short color) {                   // fungsi untuk set color
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);       // variabel untuk handle
    SetConsoleTextAttribute(hCon,color);}               // variabel untuk set color

void init(void) {                        // fungsi untuk inisialisasi
    antri.awal=-1;                      // inisialisasi awal
    antri.akhir=-1;                     // inisialisasi akhir
}

bool penuh(){                           // fungsi untuk penuh
    if(antri.akhir==MAX-1){             // jika akhir sama dengan maksimal array
        return true;                    
    } else {                            // jika tidak tersedia!
        return false;                   // maka false
    }                                   
}

bool kosong() {                         // fungsi untuk kosong
    if(antri.akhir==MAX-1) {                // jika akhir sama dengan maksimal array
        return true;                
    } else {
        return false;
    }
}

// tampilkan data pesanan
void tampilData() {
    setcolor(14);cout<<"\n\n\t\t     Data Pesanan ";setcolor(7);                                    
    cout<<"\n ======================================================================\n\n";
    if(!kosong()) {
        for(i=antri.awal; i<antri.akhir; i++) {                                                         
            cout<<"  ["<< i+1 <<"] "<<" ID "<<biodata.id_customer[i]<<" atas nama "<<biodata.customer[i]<<" di kamar no "<<frm.no_kamar[i]<<".\n";
        }
    }else{
    	cin.ignore();
		cout<<"\n  Belum Ada Pemesan";
	}
}

// fungsi untuk dequeue
void dequeue(){                 
    if(!kosong()){
    	setcolor(14);cout<<"\n\n\t\t     Hapus Reservasi ";setcolor(7);                             //fungsi hapus 
    	cout<<"\n ======================================================================\n\n";         
        cout<<"  Pemesan atas nama "<<biodata.customer[antri.awal]<<" telah dihapus.\n\n";
        for(i=antri.awal; i<antri.akhir; i++){
            biodata.id_customer[i]=biodata.id_customer[i+1];
            biodata.customer[i]=biodata.customer[i+1];
            frm.no_kamar[i]=frm.no_kamar[i+1];
            psn.kurang[i]=psn.kurang[i+1];
        }
        antri.akhir--;
        tampilData();
    } else {
        cout<<"  Pesanan Kosong";
    }
}

// selection sort 

void sort(){                                                // fungsi sort
int i,t,min;
string temp,temp2;
for(i=0;i<10;i++){
    min = i;
     for(t=i;t<10;t++){
        if(antri.DafSort[min]>antri.DafSort[t])
     min=t;}
        if(antri.DafSort[i] != antri.DafSort[min]){
        temp=antri.DafSort[i];
        antri.DafSort[i]=antri.DafSort[min];
        antri.DafSort[min]=temp;
        }
    }
}

void sorting(){                                         // fungsi sorting
int i,t,min;
string temp,temp2;
for(i=0;i<5;i++){
    min = i;
    for(t=i;t<5;t++){
        if(antri.daftar[min]>antri.daftar[t])
            min=t;
    }
    if(antri.daftar[i] != antri.daftar[min]){
        temp=antri.daftar[i];
        antri.daftar[i]=antri.daftar[min];
        antri.daftar[min]=temp;
    }
  }
}

// sequential searching 

void searching(){               // fungsi searching
	int i , posisi;
	string search;
	
	system("cls");
    setcolor(14);cout<<"\n\n\t     Cari Reservasi";setcolor(7);                             
    cout<<"\n ======================================================================";
    cout <<"\n\n   Masukan nama yang ingin dicari = ";cin >> search;
	
	i=0 ;
	posisi = 0;
	
	while(i<MAX-1 && biodata.customer[i]!=search) {
		i++;
    }
	if(biodata.customer[i]!=search) {
		setcolor(4);cout <<"\n  Data Tidak Di temukan\n\n";setcolor(7);
	} else if(biodata.customer[i]==search) {
		posisi=i+1;
		cout <<"\n  Data ditemukan diurutan "<<posisi;
        cout <<"\n  Atas nama ";setcolor(14);setcolor(7);cout<<search<<" ada di kamar no ";setcolor(14);
        cout<<frm.no_kamar[i]<<endl<<endl;setcolor(7);
	}   
}

// menu

void tipeKamar(){                                                                           //fungsi menu tipe kamar
tipe:               
    setcolor(14);cout<<"\n\n\t       Silakan Pilih Tipe Bed Yang Anda Inginkan";setcolor(7);       
    cout<<"\n ======================================================================";
    cout<<"\n\t\t| 1 | Single";
    cout<<"\n\t\t| 2 | Double";
    cout<<"\n ======================================================================";
    cout<<"\n\t\tMasukan Pilihan : ";cin>>kmr.ranjang;cout<<endl;
               
    if(kmr.kamar==1 && kmr.ranjang==1)
    {
        kmr.fixkam="Deluxe Dengan Single Bed";
        kmr.harga_kamar=800000;
    }
    else if(kmr.kamar==1 && kmr.ranjang==2)
    {
        kmr.fixkam="Deluxe Dengan Double Bed";
        kmr.harga_kamar=900000;                  
    }
    else if(kmr.kamar==2 && kmr.ranjang==1)
    {
        kmr.fixkam="Premium Dengan Single Bed";
        kmr.harga_kamar=400000;                  
    }
    else if(kmr.kamar==2 && kmr.ranjang==2)
    {
        kmr.fixkam="Premium Dengan Double Bed";
        kmr.harga_kamar=450000;                  
    } 
    else if(kmr.kamar==3 && kmr.ranjang==1)
    {
        kmr.fixkam="Presidential Dengan Single Bed";
        kmr.harga_kamar=2400000;                  
    }
    else if(kmr.kamar==3 && kmr.ranjang==2)
    {
        kmr.fixkam="Presidential Dengan Double Bed";
        kmr.harga_kamar=3000000;                  
    }
    else if(kmr.kamar==4 && kmr.ranjang==1)
    {
        kmr.fixkam="Standart Dengan Single Bed";
        kmr.harga_kamar=200000;                
    }
    else if(kmr.kamar==4 && kmr.ranjang==2)
    {
        kmr.fixkam="Standart Dengan Double Bed";
        kmr.harga_kamar=250000;                
    }
    else if(kmr.kamar==5 && kmr.ranjang==1)
    {
        kmr.fixkam="Suite Dengan Single Bed";
        kmr.harga_kamar=1500000;                
    }
    else if(kmr.kamar==5 && kmr.ranjang==2)
    {
        kmr.fixkam="Suite Dengan Double Bed";
        kmr.harga_kamar=1800000;                
    }
    else
    {
    	cin.ignore();
        cout<<"\n\t\tMaaf pilihan Anda tidak tersedia!";
		cout<<"\n\t\tTekan Enter untuk mengulangi";
		cin.get();
		goto tipe;
    }
	kam:
    system("cls"); 
    setcolor(14);cout<<"\n\n\n\t\t\tSilakan Mengisi Form Berikut";setcolor(7);
    cout<<"\n=================================================================================";

     if(!penuh()) {
        cout<<"\n\t\tPilih No. Kamar [1-100]     : "; cin>>antri.no_kmr;
        frm.no_kamar[antri.akhir] = antri.no_kmr;
        if( antri.no_kmr > 0 && antri.no_kmr <= 100 ){
            cout<<"\n\t\tMenginap Lebih Dari 5 Hari diskon 2%";
        } else {
            cout<<"\n\tNomer kamar tidak tersedia!\n";system("pause");goto kam;
        }
    }else{
        cout<<"\t\tKamar penuh!\n";
    }
    cout<<"\n\t\tLama Menginap               : "; cin>>frm.lama;
               
    if(frm.lama>=5)
    {
            frm.diskon=0.02;
    }
    else
    {
            frm.diskon=0;
    }
    cout<<" ======================================================================";       
    system("cls"); 
		setcolor(14);cout<<"\n\n\n\n\t\t\tData Pemesanan Kamar"<<endl;setcolor(7);
		cout<<" ======================================================================";
		cout<<"\n\t\tNama Pemesan     : "<<antri.customer;
		cout<<"\n\t\tID Pemesan       : "<<antri.id;
		cout<<"\n\t\tAlamat           : "<<biodata.alamat;
		cout<<"\n\t\tNo Telp/HP       : "<<biodata.hp;
		cout<<"\n\t\tTipe Kamar       : "<<kmr.fixkam;
		cout<<"\n\t\tNo. Kamar        : "<<antri.no_kmr;
        cout<<"\n\t\tLama Menginap    : "<<frm.lama<<" Hari";
        cout<<"\n\t\tTanggal Check In : "<<dt;
        cout<<"\t\tHarga Perhari    : Rp. "<<kmr.harga_kamar;
        cout<<"\n\t\tHarga Kamar Total: Rp. "<<frm.lama*kmr.harga_kamar;
        int total = frm.lama*kmr.harga_kamar;
        cout<<"\n\t\tDiskon           : Rp. "<<frm.diskon*total<<endl;
        psn.total=total - (frm.diskon*total);
        cout<<" ======================================================================";
        cout<<"\n\n\t\tBiaya Total      : Rp. "<<psn.total;
        cout<<"\n\t\tUang Muka        : Rp. ";cin>>psn.um;

        if(!penuh()) {
            psn.kurang[antri.akhir]=psn.total-psn.um;
            if(psn.total>=psn.um)
            {
                cout<<"\n\t\tKekurangan       : Rp. "<<psn.kurang[antri.akhir];
                
            }
            else
            {
               cout<<"\n\t\tKembali          : Rp. "<<psn.kurang[antri.akhir]*(-1);
            }
            antri.akhir++;
        }

        cout<<"\n ======================================================================";
               
        cout<<"\n\n\t\tTerima Kasih Telah Memilih";setcolor(14);cout<<" Hotel Amikom Jogja";setcolor(7);
        cout<<"\n\t\t   Sebagai Tempat Peristirahatan Anda\n";      
}

void mainMenu(){
flower:
    system("cls");  
    setcolor(14);cout<<"\n\n\t       Silakan Pilih Tipe Kamar Yang Anda Inginkan";setcolor(7);
    cout<<"\n ======================================================================\n";
	sorting();
	for(int i=0;i<5;i++){
        cout<<"\t\t| "<<i+1<<" | "<<antri.daftar[i]<<endl;
    }
    cout<<"\n ======================================================================";
    cout<<"\n\t\tMasukan Pilihan (1/2/3/4/5): ";cin>>kmr.kamar;
	if(kmr.kamar >5) {
		cin.ignore();
		cout<<"\n\t\tMaaf pilihan Anda tidak tersedia!";
		cout<<"\n\t\tTekan Enter untuk mengulangi";
		cin.get();
		goto flower;
	}else{
		tipeKamar();
	}
    
}

void inqueue(){
	Form:
    setcolor(14);cout<<"\n\n\n\n\t\t   Silakan Isi Form Berikut ini";setcolor(7);
    cout<<"\n ======================================================================";cout<<endl;
  
    if(!penuh()) {
		cout<<"\n\t\tID Pemesan  			: ";(cin>>antri.id).get();
		biodata.id_customer[antri.akhir]=antri.id;
		cout<<"\t\tNama Pemesan	   		: ";getline(cin, antri.customer);
		biodata.customer[antri.akhir]=antri.customer;
        cout<<"\t\tJenis Kelamin [L/P]             : "; cin>>biodata.lp;
		if(biodata.lp == "L" | biodata.lp == "l" | biodata.lp == "P" | biodata.lp == "p" ){
		cout<<"\t\tNomor Telepon/HP                : "; cin>>biodata.hp;
        cout<<"\t\tAlamat                          : "; cin>>biodata.alamat;
		}else{
			cout<<"\n\tInput salah, silakan ulangi untuk keamanan\n\n";
			system("pause");system("cls");goto Form;
		}
        cout<<" ======================================================================";
        mainMenu();
    } else {
        cout<<"\t\tKamar penuh!\n";
    }
}

void bayar() {
    setcolor(14);cout<<"\n\n\n\n\t\t   Pelunasan Pembayaran";setcolor(7);
    cout<<"\n ======================================================================";cout<<endl;
    if(!kosong()) {
        for(i=antri.awal; i<antri.akhir; i++) {
            if(psn.kurang[i]<0) {
                psn.kurang[i]=0;
                cout<<"  ["<< i+1 <<"] "<<" Atas nama "<<biodata.customer[i]<<" pembayaran kurang "<<psn.kurang[i]<<".\n";
            } else {
                cout<<"  ["<< i+1 <<"] "<<" Atas nama "<<biodata.customer[i]<<" pembayaran kurang "<<psn.kurang[i]<<".\n";
            }   
        }

        input:
        cout<<"\n  Lakukan pelunasan . . .\n";

         pelunasan:
            cout<<"\n  Pelunasan atas nama : "; cin>>psn.nama;
            for (i=antri.awal; i<antri.akhir; i++)
            {
                if(psn.nama==biodata.customer[i]) {
                    cout<<"  Belum lunas : "<<psn.kurang[i];
                    cout<<"\n  Bayar : "; cin>>psn.bayar;
                    psn.lunas=psn.kurang[i]-psn.bayar;
                    if (psn.lunas==0)
                    {
                        cout<<"\n  Pembayaran atas nama "<<biodata.customer[i]<<" telah lunas!\n\n";
                        psn.kurang[i]=0;
                    } else if(psn.kurang[i]>psn.bayar) {
                        cout<<"\n  Pembayaran atas nama "<<biodata.customer[i]<<" kurang Rp. "<<psn.lunas<<".\n\n";
                        psn.kurang[i]=psn.lunas;
                    }  else if(psn.kurang[i]<psn.bayar) {
                        cout<<"\n  Pembayaran atas nama "<<biodata.customer[i]<<" telah lunas! \n  Kembalian Rp. "<<psn.lunas*(-1)<<".\n\n";
                        psn.kurang[i]=0;
                    } else {
                    }
                } 
            }

    }else{
        cout<<"\n  Belum Ada Pemesan";
    }
}

int main() {
    string pilih;
    system("cls");
	setcolor(14);cout<<"\n\n\n\t     -! FINAL PROJECT STRUKTUR DATA !-\n\n";
	cout<<"\n\t\t      -! Anggota !- \n\n\t\t";
	cout <<"\n\t\t		-!  Bagus Budi Satoto	|	21.11.4076 \n\n\t\t\t";setcolor(7);
	cout <<"\n\t\t		-!  ALDYANSA		|	21.11.4055 \n\n\t\t\t";setcolor(6);
	cout <<"\n\t\t		-!  Fajar Rizki	Y	|	21.11.4095 \n\n\t\t\t";setcolor(5);
	cout <<"\n\t\t		-!  Arya Manunggal	|	21.11.4058 \n\n\t\t\t";setcolor(3);
	cout <<"\n\t\t		-!  Achmad Fadillah P	|	21.11.4093 \n\n\t\t\t";setcolor(3);
	setcolor(12);cout<<"\n\n\n\t     -! KELOMPOK 1 !-\n\n";
	for (int i = 0; i<7;i++){
	Sleep(250);
	cout<<".";}
	Sleep(2000);
    main:
    system("cls");
	setcolor(4);cout <<"\n\t\t=========================================\n";
 	setcolor(14);cout <<"\n\t\t    Selamat Datang di Hotel Amikom Jogja\n";
 	cout <<"\n\t\t      Jalan Condong Catur, Yogyakarta\n";
	setcolor(4);cout <<"\n\t\t=========================================\n\n";setcolor(7);
    setcolor(14);cout<<"\t\t\t\t  MENU\n\n";setcolor(7);
    cout<<" ======================================================================\n";
	cout<<"\t  | 1 | Daftar Tipe Kamar\n";
    cout<<"\t  | 2 | Pesan Kamar\n";
    cout<<"\t  | 3 | Data Pesanan\n";
    cout<<"\t  | 4 | Hapus Reservasi\n";
    cout<<"\t  | 5 | Cari Reservasi\n";
    cout<<"\t  | 6 | Pelunasan Pembayaran\n";
    cout<<"\t  | 7 | Keluar\n";
    cout<<" ======================================================================\n";
    cout<<"    Masukkan Pilihan Anda [1 s/d 7] : ";
    cin>>pilih;
    
    if (pilih == "1"){
    	system("cls");
    	sort();
    	setcolor(14);cout<<"\n\n\t\t      Daftar Tipe Kamar dan Harga\n\n";setcolor(7);
        cout<<"\n ======================================================================\n";
    	for(int i=0;i<10;i++){
            cout<<" | "<<i+1<<" |\t"<<antri.DafSort[i]<<"\t   "<<antri.harga[i]<<endl;
        }
    	cout<<"\n ======================================================================\n\n";
    	cin.ignore();
        cout<<"  Tekan Enter untuk ke Menu";
        cin.get();
    	goto main;
	}
	else if (pilih == "2"){
		system("cls");
        inqueue();
        cout<<"\n ======================================================================\n";
        cin.ignore();
        cout<<"\n  Tekan Enter untuk ke Menu";
        cin.get();
        goto main;
	}
	else if (pilih == "3"){
		 system("cls");
        tampilData();
        cout<<"\n ======================================================================\n";
        cin.ignore();
        cout<<"\n  Tekan Enter untuk ke Menu";
        cin.get();
        goto main;
	}
	else if (pilih == "4"){
		system("cls");
        dequeue();
        cout<<"\n ======================================================================\n";
        cin.ignore();
        cout<<"\n  Tekan Enter untuk ke Menu";
        cin.get();
        goto main;
	}
	else if (pilih == "5"){
		searching();
		cout<<"\n ======================================================================\n";
        cin.ignore();
        cout<<"\n  Tekan Enter untuk ke Menu";
        cin.get();
		goto main;
	}
    else if (pilih == "6"){
        system("cls");
        bayar();
        cout<<"\n ======================================================================\n";
        cin.ignore();
        cout<<"\n  Tekan Enter untuk ke Menu";
        cin.get();
        goto main;
    }
	else if (pilih == "7"){
			cout<<"\n\n\t\tTerima Kasih Telah Memilih";setcolor(14);cout<<" Hotel Amikom Jogja";setcolor(7);
        cout<<"\n\t\t   Sebagai Tempat Peristirahatan Anda\n\n";system("pause"); system("cls");
	}
	else{
		cout<<"\n\tInput Salah \n\n\n";system("pause");
        goto main;
	}
    return 0;
}
