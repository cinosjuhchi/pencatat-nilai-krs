#include <iostream>
#include <iomanip>
using namespace std;

int main() {	
	bool status = true;
	int jumlahMenu = 3;
	string menuNames[100] = {"Americano", "Espresso", "Ballerina Cappucino"};
	double menuPrices[100] = {2000, 5000, 7000};
	while(status){
		system("cls");
		int option;
		char lanjut;
		cout<<setfill('=');
		cout<<setw(100)<<"="<<endl;
		cout<<setw(50)<<setfill(' ')<<"Menu"<<endl;
		cout<<setfill('=');
		cout<<setw(100)<<"="<<endl;
		cout<<endl;
		cout<<"1. Daftar Menu"<<endl;
		cout<<"2. Tambah Menu"<<endl;
		cout<<"3. Transaksi Menu"<<endl;
		cout<<"4. Keluar"<<endl;
		cout<<"Masukan Pilihan : ";
		cin >> option;
		switch(option) {
			case 1 : {
				system("cls");
				bool statusPage = true;
				while(statusPage) {
					cout<<setfill(' ');
					cout<<left<<setw(15)<<"No"<<"|"<<left<<setw(30)<<"Menu"<<endl;
					for(int i = 0; i < jumlahMenu; i++) {
						cout<<left<<setw(15)<<i+1<<"|"<<left<<setw(30)<<menuNames[i]<<endl;
					}
					cout << "Lanjut? Y/N : ";
					cin >> lanjut;
					if(toupper(lanjut) == 'N') {
						statusPage = false;
					}
				}				
			}
			break;
			case 2: 
				system("pause");
			break;
			default : {
				bool statusPage = true;
				while(statusPage)
				{
					cout<<"Masukan Pilihan Yang Valid!"<<endl;
					cout<<"Masukan Pilihan : ";
					cin >> option;
					if(option > 0 && option <=4) {
						statusPage = false;
					}
				}
			}
		}
	}	
	
	return 0;
}
