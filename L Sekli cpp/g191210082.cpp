/******************************************************************************************************************************************************************
**
**															��RENC� ADI=Sevdet I��k
**														��RENC�N�N NUMARASI=G191210082
**													DERS GRUBU=Programlamaya Giri� B Grubu
**
**
******************************************************************************************************************************************************************/

#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

//gotoxy fonksiyonu tan�mlanmas�
void gotoxy(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}

//sahne isimli bir struct olu�turuluyor.
struct sahne
{
	int sahneGenislik;
	int sahneBoy;
	char karakter;
};

//LSekli isimli bir struct olu�turuluyor.
struct LSekli {
	int x;
	int y;
	int boyut;
	char karakter;
};

//sahneyi olu�turan ve geri d�nd�ren fonksiyon
sahne sahneOlustur()
{
	sahne sahne1;
	int genislik1 = 30;
	int genislik2 = 40;
	int genislik3 = 50;
	int randGenislik = rand() % 2 + 1;
	int randKarakter = rand() % 5 + 1;

	//e�er random geni�lik de�erini tutan de�i�kenin de�eri 1 ise sahne geni�li�ine 30 de�eri atan�yor.
	if (randGenislik == 1) {

		sahne1.sahneGenislik = genislik1;
	}
	//e�er random geni�lik de�erini tutan de�i�kenin de�eri 1 ise sahne geni�li�ine 40 de�eri atan�yor.
	else if (randGenislik == 2) {
		sahne1.sahneGenislik = genislik2;
	}
	//e�er random geni�lik de�erini tutan de�i�kenin de�eri 1 ise sahne geni�li�ine 50 de�eri atan�yor.
	else {
		sahne1.sahneGenislik = genislik3;
	}

	sahne1.sahneBoy = rand() % 10 + 20;

	//e�er random karakter de�erini tutan de�i�kenin de�eri 1 ise sahneyi olu�turan karakter '#' olarak atan�yor.
	if (randKarakter == 1) {
		sahne1.karakter = '#';
	}
	//e�er random karakter de�erini tutan de�i�kenin de�eri 2 ise sahneyi olu�turan karakter '*' olarak atan�yor.
	else if (randKarakter == 2) {
		sahne1.karakter = '*';
	}
	//e�er random karakter de�erini tutan de�i�kenin de�eri 3 ise sahneyi olu�turan karakter '$' olarak atan�yor.
	else if (randKarakter == 3) {
		sahne1.karakter = '$';
	}
	//e�er random karakter de�erini tutan de�i�kenin de�eri 4 ise sahneyi olu�turan karakter '+' olarak atan�yor.
	else if (randKarakter == 4) {
		sahne1.karakter = '+';
	}
	//e�er random karakter de�erini tutan de�i�kenin de�eri 5 ise sahneyi olu�turan karakter '@' olarak atan�yor.
	else if(randKarakter==5){
		sahne1.karakter = '@';
	}
	return sahne1;
}
//sahneOlustur fonksiyonunda olu�turulan sahneyi ekrana �izen fonksiyon.
void sahneCiz(sahne sahne1)
{
	//sahnenin en �st sat�r�nda bulunan karakterleri �izer.
	for (int i = 0; i < sahne1.sahneGenislik; i++) {
		cout << sahne1.karakter;
	}
	cout << endl;

	//sahnenin en alt ve en �st sat�r� aras�nda kalan k�sm� �izer.
	for (int i = 0; i < sahne1.sahneBoy - 2; i++) {
		cout << sahne1.karakter;
		//sahnenin en alt ve en �st sat�r� aras�nda kalan k�sm�n bo�luklar�n� �izer.
		for (int j = 0; j < sahne1.sahneGenislik - 2; j++)
		{
			cout << " ";
		}
		cout << sahne1.karakter << endl;
	}
	//sahnenin en alt sat�r�nda bulunan karakterleri �izer.
	for (int i = 0; i < sahne1.sahneGenislik; i++) {
		cout << sahne1.karakter;
	}
}

//L �eklini olu�turan fonksiyon
LSekli lSekliOlustur()
{
	int sekilKarakter;
	LSekli sekil;
	sekil.x = rand() % 20 + 5;
	sekil.y = 3;
	sekil.boyut = 0;
	//�ekil boyut de�eri 4'ten k���kse veya tek say�ysa 13'e kadar olan say�lar aras�ndan random bir say� �ekil boyutuna atan�yor.
	while(sekil.boyut<4||sekil.boyut%2==1){ 
		sekil.boyut = rand() % 13; 
	}
	
	sekilKarakter = rand() % 5 + 1;

	//�ekil karakter de�i�keninin de�eri 1 ise L �eklini olu�turan karaktere '*' de�eri atan�yor.
	if (sekilKarakter == 1) {
		sekil.karakter = '*';
	}
	//�ekil karakter de�i�keninin de�eri 2 ise L �eklini olu�turan karaktere '#' de�eri atan�yor.
	else if (sekilKarakter == 2) {
		sekil.karakter = '#';
	}
	//�ekil karakter de�i�keninin de�eri 3 ise L �eklini olu�turan karaktere '$' de�eri atan�yor.
	else if (sekilKarakter == 3) {
		sekil.karakter = '$';
	}
	//�ekil karakter de�i�keninin de�eri 4 ise L �eklini olu�turan karaktere '+' de�eri atan�yor.
	else if (sekilKarakter == 4) {
		sekil.karakter = '+';
	}
	//�ekil karakter de�i�keninin de�eri 5 ise L �eklini olu�turan karaktere '@' de�eri atan�yor.
	else if(sekilKarakter==5){
		sekil.karakter = '@';
	}

	return sekil;
}

//lSekliOlustur fonksiyonula olu�turulan L �eklini ekrana �izen fonksiyon.
void lSekliCiz(LSekli sekil) {
		gotoxy(sekil.x, sekil.y);
		//l �eklinin en �st k�sm�nda kalan k�sm� �izer.
		for (int i = 0; i < sekil.boyut / 2; i++) {
			cout << sekil.karakter;
		}
		sekil.y++;
		//L �eklinin en �st sat�r�n�n alt�ndan  alt ortadaki d�rtgen bo�lu�a kadar olan k�sm� �izer.
		for (int i = 0; i < sekil.boyut / 2; i++) {
			gotoxy(sekil.x, sekil.y);
			cout << sekil.karakter;
			//L �eklinin en �st sat�r�n�n alt�ndan en alt ortadaki d�rtgen bo�lu�a kadar olan k�sm�n ortas�nda kalan bo�luklar� �izer.
			for (int j = 0; j < sekil.boyut / 3; j++) {
				//e�er �ekil boyutu 4'e e�itse bo�luk b�rak�lmaz
				if (sekil.boyut == 4) {
					continue;
				}
				//e�er �ekil boyutu 6'ya e�itse 1 adet az bo�luk b�rak�l�r.
				else if (sekil.boyut == 6) {
					j++;
				}
				cout << " ";

			}
			cout << sekil.karakter;
			sekil.y++;			
		}
		//L �eklinin alt ortas�nda bulunan d�rtgenin en �st�nde bulunan,bo�luktan sonra olan karakterleri �izer.
		for (int i = 0; i < sekil.boyut / 2; i++) {
			cout << sekil.karakter;
		}
	
		int sayac = sekil.boyut;
		//e�er saya� de�eri 6'dan b�y�kse saya� 2 artt�r�l�r.
		if (sayac >6) {
			sayac+=2;
			//e�er saya� de�eri ba�lang��ta 12 olarak gelmi�se saya� de�eri 1 daha artt�r�l�r.
			if (sayac == 14) {
				sayac++;
			}
		}

		//L �eklinin alt ortas�nda bulunan d�rtgen �izilir.
		for (int i = 0; i <sayac/3; i++) {
			gotoxy(sekil.x, sekil.y);
			cout << sekil.karakter;
			//L �eklinin alt ortas�nda bulunan d�rtgenin ortas�nda bulunan bo�luklar �izilir.
			for (int j = 0; j < sekil.boyut - 2; j++) {
				cout << " ";
			}
			cout << sekil.karakter;
			sekil.y++;
			
		}
		gotoxy(sekil.x, sekil.y);
		//L �eklinin en alt k�sm�nda kalan karakterler �izilir.
		for (int i = 0; i < sekil.boyut; i++) {
			cout <<sekil.karakter;
		}	
}

//L �eklini her �a��r�l��ta bir birim a�a�� g�t�ren fonksiyon.
LSekli lSekliAsagiGotur(LSekli sekil) {
	sekil.y++;
	return sekil;
}


int main()
{
	srand(time(NULL));

	sahne sahne1 = sahneOlustur();
	LSekli sekil = lSekliOlustur();

	//L �eklinin ve sahnenin �izilip,L �eklinin s�rekli olarak a�a�� gitmesini sa�layan s�rekli �al��an d�ng�.
	while (true) {
		system("cls");
		sahneCiz(sahne1);
		lSekliCiz(sekil);
		Sleep(100);
		sekil = lSekliAsagiGotur(sekil);
		
		//e�er �ekil boyutu ve �eklin y de�erinin toplam�n�n bir fazlas� sahnenin en alt sat�r�n�n konumuna e�itse L �ekli tekrardan olu�turulur.
		if(sekil.y+sekil.boyut+1==sahne1.sahneBoy){
			sekil = lSekliOlustur();						
		}								
	}	
	system("pause");
}