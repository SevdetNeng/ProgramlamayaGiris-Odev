/******************************************************************************************************************************************************************
**
**															ÖÐRENCÝ ADI=Sevdet Iþýk
**														ÖÐRENCÝNÝN NUMARASI=G191210082
**													DERS GRUBU=Programlamaya Giriþ B Grubu
**
**
******************************************************************************************************************************************************************/

#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

//gotoxy fonksiyonu tanýmlanmasý
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

//sahne isimli bir struct oluþturuluyor.
struct sahne
{
	int sahneGenislik;
	int sahneBoy;
	char karakter;
};

//LSekli isimli bir struct oluþturuluyor.
struct LSekli {
	int x;
	int y;
	int boyut;
	char karakter;
};

//sahneyi oluþturan ve geri döndüren fonksiyon
sahne sahneOlustur()
{
	sahne sahne1;
	int genislik1 = 30;
	int genislik2 = 40;
	int genislik3 = 50;
	int randGenislik = rand() % 2 + 1;
	int randKarakter = rand() % 5 + 1;

	//eðer random geniþlik deðerini tutan deðiþkenin deðeri 1 ise sahne geniþliðine 30 deðeri atanýyor.
	if (randGenislik == 1) {

		sahne1.sahneGenislik = genislik1;
	}
	//eðer random geniþlik deðerini tutan deðiþkenin deðeri 1 ise sahne geniþliðine 40 deðeri atanýyor.
	else if (randGenislik == 2) {
		sahne1.sahneGenislik = genislik2;
	}
	//eðer random geniþlik deðerini tutan deðiþkenin deðeri 1 ise sahne geniþliðine 50 deðeri atanýyor.
	else {
		sahne1.sahneGenislik = genislik3;
	}

	sahne1.sahneBoy = rand() % 10 + 20;

	//eðer random karakter deðerini tutan deðiþkenin deðeri 1 ise sahneyi oluþturan karakter '#' olarak atanýyor.
	if (randKarakter == 1) {
		sahne1.karakter = '#';
	}
	//eðer random karakter deðerini tutan deðiþkenin deðeri 2 ise sahneyi oluþturan karakter '*' olarak atanýyor.
	else if (randKarakter == 2) {
		sahne1.karakter = '*';
	}
	//eðer random karakter deðerini tutan deðiþkenin deðeri 3 ise sahneyi oluþturan karakter '$' olarak atanýyor.
	else if (randKarakter == 3) {
		sahne1.karakter = '$';
	}
	//eðer random karakter deðerini tutan deðiþkenin deðeri 4 ise sahneyi oluþturan karakter '+' olarak atanýyor.
	else if (randKarakter == 4) {
		sahne1.karakter = '+';
	}
	//eðer random karakter deðerini tutan deðiþkenin deðeri 5 ise sahneyi oluþturan karakter '@' olarak atanýyor.
	else if(randKarakter==5){
		sahne1.karakter = '@';
	}
	return sahne1;
}
//sahneOlustur fonksiyonunda oluþturulan sahneyi ekrana çizen fonksiyon.
void sahneCiz(sahne sahne1)
{
	//sahnenin en üst satýrýnda bulunan karakterleri çizer.
	for (int i = 0; i < sahne1.sahneGenislik; i++) {
		cout << sahne1.karakter;
	}
	cout << endl;

	//sahnenin en alt ve en üst satýrý arasýnda kalan kýsmý çizer.
	for (int i = 0; i < sahne1.sahneBoy - 2; i++) {
		cout << sahne1.karakter;
		//sahnenin en alt ve en üst satýrý arasýnda kalan kýsmýn boþluklarýný çizer.
		for (int j = 0; j < sahne1.sahneGenislik - 2; j++)
		{
			cout << " ";
		}
		cout << sahne1.karakter << endl;
	}
	//sahnenin en alt satýrýnda bulunan karakterleri çizer.
	for (int i = 0; i < sahne1.sahneGenislik; i++) {
		cout << sahne1.karakter;
	}
}

//L þeklini oluþturan fonksiyon
LSekli lSekliOlustur()
{
	int sekilKarakter;
	LSekli sekil;
	sekil.x = rand() % 20 + 5;
	sekil.y = 3;
	sekil.boyut = 0;
	//þekil boyut deðeri 4'ten küçükse veya tek sayýysa 13'e kadar olan sayýlar arasýndan random bir sayý þekil boyutuna atanýyor.
	while(sekil.boyut<4||sekil.boyut%2==1){ 
		sekil.boyut = rand() % 13; 
	}
	
	sekilKarakter = rand() % 5 + 1;

	//þekil karakter deðiþkeninin deðeri 1 ise L þeklini oluþturan karaktere '*' deðeri atanýyor.
	if (sekilKarakter == 1) {
		sekil.karakter = '*';
	}
	//þekil karakter deðiþkeninin deðeri 2 ise L þeklini oluþturan karaktere '#' deðeri atanýyor.
	else if (sekilKarakter == 2) {
		sekil.karakter = '#';
	}
	//þekil karakter deðiþkeninin deðeri 3 ise L þeklini oluþturan karaktere '$' deðeri atanýyor.
	else if (sekilKarakter == 3) {
		sekil.karakter = '$';
	}
	//þekil karakter deðiþkeninin deðeri 4 ise L þeklini oluþturan karaktere '+' deðeri atanýyor.
	else if (sekilKarakter == 4) {
		sekil.karakter = '+';
	}
	//þekil karakter deðiþkeninin deðeri 5 ise L þeklini oluþturan karaktere '@' deðeri atanýyor.
	else if(sekilKarakter==5){
		sekil.karakter = '@';
	}

	return sekil;
}

//lSekliOlustur fonksiyonula oluþturulan L þeklini ekrana çizen fonksiyon.
void lSekliCiz(LSekli sekil) {
		gotoxy(sekil.x, sekil.y);
		//l þeklinin en üst kýsmýnda kalan kýsmý çizer.
		for (int i = 0; i < sekil.boyut / 2; i++) {
			cout << sekil.karakter;
		}
		sekil.y++;
		//L þeklinin en üst satýrýnýn altýndan  alt ortadaki dörtgen boþluða kadar olan kýsmý çizer.
		for (int i = 0; i < sekil.boyut / 2; i++) {
			gotoxy(sekil.x, sekil.y);
			cout << sekil.karakter;
			//L þeklinin en üst satýrýnýn altýndan en alt ortadaki dörtgen boþluða kadar olan kýsmýn ortasýnda kalan boþluklarý çizer.
			for (int j = 0; j < sekil.boyut / 3; j++) {
				//eðer þekil boyutu 4'e eþitse boþluk býrakýlmaz
				if (sekil.boyut == 4) {
					continue;
				}
				//eðer þekil boyutu 6'ya eþitse 1 adet az boþluk býrakýlýr.
				else if (sekil.boyut == 6) {
					j++;
				}
				cout << " ";

			}
			cout << sekil.karakter;
			sekil.y++;			
		}
		//L Þeklinin alt ortasýnda bulunan dörtgenin en üstünde bulunan,boþluktan sonra olan karakterleri çizer.
		for (int i = 0; i < sekil.boyut / 2; i++) {
			cout << sekil.karakter;
		}
	
		int sayac = sekil.boyut;
		//eðer sayaç deðeri 6'dan büyükse sayaç 2 arttýrýlýr.
		if (sayac >6) {
			sayac+=2;
			//eðer sayaç deðeri baþlangýçta 12 olarak gelmiþse sayaç deðeri 1 daha arttýrýlýr.
			if (sayac == 14) {
				sayac++;
			}
		}

		//L Þeklinin alt ortasýnda bulunan dörtgen çizilir.
		for (int i = 0; i <sayac/3; i++) {
			gotoxy(sekil.x, sekil.y);
			cout << sekil.karakter;
			//L Þeklinin alt ortasýnda bulunan dörtgenin ortasýnda bulunan boþluklar çizilir.
			for (int j = 0; j < sekil.boyut - 2; j++) {
				cout << " ";
			}
			cout << sekil.karakter;
			sekil.y++;
			
		}
		gotoxy(sekil.x, sekil.y);
		//L þeklinin en alt kýsmýnda kalan karakterler çizilir.
		for (int i = 0; i < sekil.boyut; i++) {
			cout <<sekil.karakter;
		}	
}

//L Þeklini her çaðýrýlýþta bir birim aþaðý götüren fonksiyon.
LSekli lSekliAsagiGotur(LSekli sekil) {
	sekil.y++;
	return sekil;
}


int main()
{
	srand(time(NULL));

	sahne sahne1 = sahneOlustur();
	LSekli sekil = lSekliOlustur();

	//L þeklinin ve sahnenin çizilip,L þeklinin sürekli olarak aþaðý gitmesini saðlayan sürekli çalýþan döngü.
	while (true) {
		system("cls");
		sahneCiz(sahne1);
		lSekliCiz(sekil);
		Sleep(100);
		sekil = lSekliAsagiGotur(sekil);
		
		//eðer þekil boyutu ve þeklin y deðerinin toplamýnýn bir fazlasý sahnenin en alt satýrýnýn konumuna eþitse L þekli tekrardan oluþturulur.
		if(sekil.y+sekil.boyut+1==sahne1.sahneBoy){
			sekil = lSekliOlustur();						
		}								
	}	
	system("pause");
}