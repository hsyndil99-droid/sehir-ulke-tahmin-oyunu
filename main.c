#include <stdio.h>
#include <time.h>            
#include <stdlib.h>          
#include <locale.h>          
#include <string.h>          
#include <ctype.h>           
#include <windows.h>         
#include <conio.h>  
#include "sehirler_ulkeler.h" 
#define EKRAN_GENISLIGI 120

void gotoxy(int x, int y);
void renkDegistir(int renkKodu);
void ortayaYaz(char *metin, int y, int renk);
void kurallariGoster();
void skoruKaydet(char *isim, int puan, int mod);
void puanTablosunuGoster();
void temizle(char x[]);
int rastgele(int x);
int ipucu(int i_mod, int i_uzunluk, char i_dogru_cevap[], char i_gorunen[], int *ip1, int *ip2, int *ip3);



// --- ANA PROGRAM ---

int main(void){
    system("mode con: cols=120 lines=35");
    system("chcp 1254");
    setlocale(LC_ALL, "Turkish");
    srand(time(NULL));
    char oyuncuIsmi[50];
    int isimGirildi = 0;

    while (1) {
        // --- ISIM GIRISI (Eger girilmemisse veya degistirilmisse) ---
        if (isimGirildi == 0){
            system("cls");
            
            ortayaYaz("ŞEHİR / ÜLKE TAHMİN OYUNUNA HOŞGELDİNİZ!", 10, 11);
            ortayaYaz("LÜFTEN İSMİNİZİ GİRİN (Tek kelime)", 12, 15);
            gotoxy(55, 14); 
            scanf("%s", oyuncuIsmi);
            temizle(oyuncuIsmi);
            while (getchar() != '\n'); //Bellekte biriken enterları siliyor
            kurallariGoster();
            isimGirildi = 1;
        }

        system("cls");
        
        // İsmi en üstte gösteriyoruz
        char isimBar[50];
        sprintf(isimBar, "AKTİF OYUNCU: %s", oyuncuIsmi);
        ortayaYaz(isimBar, 1, 14);

        ortayaYaz("===== ANA MENÜ =====", 5, 11);
        ortayaYaz("[1] ŞEHİR MODU", 10, 15);
        ortayaYaz("[2] ÜLKE MODU", 12, 15);
		ortayaYaz("[3] OYUNCU DEĞİŞTİR", 16, 10);
        ortayaYaz("[4] PUAN TABLOSU", 18, 14);
	    ortayaYaz("[5] KURALLARI TEKRAR OKU", 20, 7);
        ortayaYaz("[0] ÇIKIŞ", 24, 12);
        
        int secim = getch();

        if (secim == '0') break;                              // Oyundan çıkılır
        if (secim == '3'){ isimGirildi = 0; continue; }       // Başa dönüp isim isteyecek
        if (secim == '4'){ puanTablosunuGoster(); continue; } // Puan tablosunu açacak
        if (secim == '5'){ kurallariGoster(); continue; }     // Kuralları tekrar gösterecek
        
        
        char dogru_cevap[50], dogru[50], bolge[50];
        int mod, hak, puan = 150;

        if (secim == '1'){
            int idx = rastgele(81);
            strcpy(dogru_cevap, Sehirler[idx].teknik_ad);
            strcpy(dogru, Sehirler[idx].gorsel_ad);
            strcpy(bolge, Sehirler[idx].bolge);
            hak = 7;
			mod = 1;
        } 
		else if (secim == '2'){
            int idx = rastgele(196);
            strcpy(dogru_cevap, Ulkeler[idx].teknik_ad);
            strcpy(dogru, Ulkeler[idx].gorsel_ad);
            strcpy(bolge, Ulkeler[idx].bolge);
            hak = 10;
			mod = 2;
        } 
		else continue;

        char gorunen[50], hatali_tahminler[1000] = "";
        int i, harf = 0, uzunluk = strlen(dogru_cevap);
        int ip1 = 1, ip2 = 1, ip3 = 1;
        int bolge_acik = 0;
        for(i = 0; i < uzunluk; i++){
            if(dogru_cevap[i] == ' '){
            	gorunen[i] = ' ';
			}
            else{
			    gorunen[i] = '_';
			    harf++;
			}
        }
        gorunen[uzunluk] = '\0';

        while(hak > 0 && puan > 0){
            system("cls");
            
            // Her ekranın en üstünde Oyuncu ismi sabit
            sprintf(isimBar, "OYUNCU: %s", oyuncuIsmi);
            ortayaYaz(isimBar, 1, 14);

            if (mod == 1){
                ortayaYaz("MOD: ŞEHİR TAHMİNİ", 3, 11);
            } 
			else{
                ortayaYaz("MOD: ÜLKE TAHMİNİ", 3, 11);
            }
            
            char istatistik[100];
            sprintf(istatistik, "PUAN: %d | HAK: %d", puan, hak);
            ortayaYaz(istatistik, 5, 10);

            char gizli[100];
            sprintf(gizli,"%s (%d Harf)", gorunen, harf);
            ortayaYaz(gizli,8,14);

            if(bolge_acik){
                char bolgeyazdir[100];
                if(mod == 1){
                	sprintf(bolgeyazdir, "(Bölge: %s Bölgesi)", bolge);
				}
				else{
					sprintf(bolgeyazdir, "(Kıta: %s Kıtası)", bolge);
				}
                
                ortayaYaz(bolgeyazdir, 10, 13);
            }

            if(strlen(hatali_tahminler) > 0){
                ortayaYaz("YANLIŞ TAHMİNLER:", 19, 12);
                ortayaYaz(hatali_tahminler, 20, 8);
            }

            ortayaYaz("Tahmininiz: ", 14, 15);
            ortayaYaz("İpucu için '1' yazıp ENTER'a basınız.", 16, 8);
            ortayaYaz("Çıkış için '0' yazıp ENTER'a basınız.", 17,8);
            gotoxy(66,14);
            renkDegistir(15);
            char tahmin[50];
            fgets(tahmin, 50, stdin);
            temizle(tahmin);

            if(strcmp(tahmin, "1") == 0) {
                int p_eksi = ipucu(mod, uzunluk, dogru_cevap, gorunen, &ip1, &ip2, &ip3);
                puan -= p_eksi;
                if(p_eksi == 20){
                	bolge_acik = 1;
				} 
            } 
            else if(strcmp(tahmin, "0") == 0) break;
			else if(strcmp(tahmin, dogru_cevap) == 0){
                system("cls");
                
                ortayaYaz("TEBRİKLER KAZANDINIZ!", 12, 10);
                char final_mesaj[100];
                sprintf(final_mesaj, "Cevap: %s | Kazanılan Puan: %d", dogru, puan);
                ortayaYaz(final_mesaj, 14, 14);
                ortayaYaz("Devam etmek için bir tuşa basınız.",16,8);
                
                skoruKaydet(oyuncuIsmi, puan, mod);
                getch(); 
				break;
            } 
			else{
                hak--;
				puan -= 10;
                strcat(hatali_tahminler, tahmin); 
				strcat(hatali_tahminler, " - ");
				gotoxy(66,14);
				renkDegistir(12);
				printf("YANLIŞ!                                               ");
				Sleep(700);
            }
        }
        if(hak <= 0 || puan <= 0){
            system("cls");
            
            if(puan <= 0){
                ortayaYaz("PUANINIZ BİTTİ! KAYBETTİNİZ.", 12, 12); // Kırmızı/Gri renk tonu
            } 
            else{
                ortayaYaz("HAKKINIZ BİTTİ! KAYBETTİNİZ.", 12, 12);
            }
            
            char kayip_mesaj[100];
            sprintf(kayip_mesaj, "Doğru Cevap: %s", dogru);
            ortayaYaz(kayip_mesaj, 14, 15);
            ortayaYaz("Devam etmek için bir tuşa basınız.",16,8);
            
            skoruKaydet(oyuncuIsmi, 0, mod);
            getch();
        }
    }
    return 0;
}



// --- GÖRSEL YARDIMCI FONKSİYONLAR ---

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void renkDegistir(int renkKodu){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), renkKodu);
    
    // --- STANDART RENK KODLARI ---
    // 0  : Siyah 
    // 1  : Koyu Mavi
    // 2  : Koyu Yeşil
    // 3  : Koyu Turkuaz
    // 4  : Koyu Kırmızı
    // 5  : Koyu Mor
    // 6  : Kirli Sarı / Zeytin Yeşili
    // 7  : Standart Beyaz (Griye yakın)
    // 8  : Gri 
    // 9  : Parlak Mavi
    // 10 : Parlak Yeşil 
    // 11 : Parlak Turkuaz 
    // 12 : Parlak Kırmızı 
    // 13 : Parlak Mor / Pembe
    // 14 : Parlak Sarı 
    // 15 : Parlak Beyaz 
}

void ortayaYaz(char *metin, int y, int renk){          
    int uz = strlen(metin);
    int x = (EKRAN_GENISLIGI - uz) / 2;
    if (x < 0) x = 0;
    renkDegistir(renk);
    gotoxy(x, y);
    printf("%s", metin);
}



// --- KURALLAR SAYFASI ---

void kurallariGoster(){
    system("cls");
    
    ortayaYaz("==============================================", 5, 11);
    ortayaYaz("        OYUN KURALLARI VE BİLGİLERİ          ", 6, 14);
    ortayaYaz("==============================================", 7, 11);
    
    ortayaYaz("1. Her oyuna 150 PUAN ile başlarsınız.", 10, 15);
    ortayaYaz("2. Yanlış tahminlerinizde 10 PUAN ve 1 HAK kaybedersiniz.", 12, 15);
    ortayaYaz("3. Şehir modunda 7, Ülke modunda 10 hakkınız vardır.", 14, 15);
    ortayaYaz("4. İpucu marketinden puan karşılığı yardım alabilirsiniz.", 16, 15);
    ortayaYaz("5. Puanınız veya Hakkınız biterse oyun sona erer.", 18, 12); 
    
    ortayaYaz("6. Kazandığınız puanlar mod bazlı olarak Puan Tablosuna kaydedilir.", 21, 10); 
    
    ortayaYaz("Devam etmek için bir tuşa basın...", 26, 8);
    getch();
}



// --- DOSYA İŞLEMLERİ VE PUAN TABLOSU ---

void skoruKaydet(char *isim, int puan, int mod){
    FILE *dosya = fopen("puan_tablosu.txt", "r");
    struct Oyuncu oyuncular[100];
    int sayac = 0, bulundu = 0;
    int i; 

    if (dosya != NULL){
        while (fscanf(dosya, "%s %d %d %d %d", oyuncular[sayac].isim, 
                      &oyuncular[sayac].sehir_oyun, &oyuncular[sayac].sehir_puan, 
                      &oyuncular[sayac].ulke_oyun, &oyuncular[sayac].ulke_puan) != EOF) {
            
            if (strcmp(oyuncular[sayac].isim, isim) == 0) {
                if (mod == 1) { 
                    oyuncular[sayac].sehir_oyun++;
                    oyuncular[sayac].sehir_puan += puan;
                } else { 
                    oyuncular[sayac].ulke_oyun++;
                    oyuncular[sayac].ulke_puan += puan;
                }
                bulundu = 1;
            }
            sayac++;
        }
        fclose(dosya);
    }

    if (bulundu == 0){
        strcpy(oyuncular[sayac].isim, isim);
        oyuncular[sayac].sehir_oyun = 0;
        oyuncular[sayac].sehir_puan = 0;
        oyuncular[sayac].ulke_oyun = 0;
        oyuncular[sayac].ulke_puan = 0;

        if (mod == 1) {
            oyuncular[sayac].sehir_oyun = 1;
            oyuncular[sayac].sehir_puan = puan;
        } else {
            oyuncular[sayac].ulke_oyun = 1;
            oyuncular[sayac].ulke_puan = puan;
        }
        sayac++;
    }

    dosya = fopen("puan_tablosu.txt", "w");
    if (dosya != NULL){
        for (i = 0; i < sayac; i++) {
            fprintf(dosya, "%s %d %d %d %d\n", oyuncular[i].isim, 
                    oyuncular[i].sehir_oyun, oyuncular[i].sehir_puan, 
                    oyuncular[i].ulke_oyun, oyuncular[i].ulke_puan);
        }
        fclose(dosya);
    }
}

void puanTablosunuGoster(){
    system("cls");
    
    FILE *dosya = fopen("puan_tablosu.txt", "r");
    
	
	ortayaYaz("========================= PUAN TABLOSU =========================", 4, 14);
	
	char baslik[100] = "İSİM               | ŞEHİR (Oyun/Puan) | ÜLKE (Oyun/Puan)   |  TOPLAM PUAN";
    int baslikUzunluk = strlen(baslik);
    int tabloBaslangicX = (EKRAN_GENISLIGI - baslikUzunluk) / 2;
    renkDegistir(11);
    gotoxy(tabloBaslangicX, 7);
    printf("%s", baslik);
    renkDegistir(8);
    gotoxy(tabloBaslangicX, 8);
    int k;
    for(k=0; k<baslikUzunluk; k++){
    	printf("-");
	} 
    
    if (dosya == NULL){
        ortayaYaz("Henüz kayıtlı skor yok!", 11, 12);
    } else{
        char isim[50];
        int sOyun, sPuan, uOyun, uPuan, satir = 10;
        while (fscanf(dosya, "%s %d %d %d %d", isim, &sOyun, &sPuan, &uOyun, &uPuan) != EOF) {
            if(strlen(isim) > 18){
            	isim[18] = '\0'; 
			} 
            int toplam = sPuan + uPuan;
            renkDegistir(15);
            gotoxy(tabloBaslangicX, satir++);
            printf("%-19s|  %3d / %-10d |  %3d / %-11d |  %d", isim, sOyun, sPuan, uOyun, uPuan, toplam);
        }
        fclose(dosya);
    }
    ortayaYaz("Menüye dönmek için herhangi bir tuşa basin...", 32, 8);
    getch();
}



// --- OYUN YARDIMCI FONKSIYONLARI ---

int rastgele(int x){
	return rand() % x;
}

void temizle(char x[]){
    int u = strlen(x);
    if (x[u - 1] == '\n'){
    	x[u - 1] = '\0';
	} 
    
    int j;
    for (j = 0; j<u; j++) {
        unsigned char c = (unsigned char)x[j];
        
        if (c == 'i') x[j] = 'İ';      // i -> İ
        else if (c == 253) x[j] = 'I'; // ı -> I
        else if (c == 'ş') x[j] = 'Ş'; // ş -> Ş
        else if (c == 'ğ') x[j] = 'Ğ'; // ğ -> Ğ
        else if (c == 'ç') x[j] = 'Ç'; // ç -> Ç
        else if (c == 'ö') x[j] = 'Ö'; // ö -> Ö
        else if (c == 'ü') x[j] = 'Ü'; // ü -> Ü
        else {x[j] = toupper(c);} 
    }
}

int ipucu(int i_mod, int i_uzunluk, char i_dogru_cevap[], char i_gorunen[], int *ip1, int *ip2, int *ip3) {
    system("cls");
    
    ortayaYaz("--- İPUCU MARKETİ ---", 3, 14);
    
    
  
  
    if(*ip1 == 1){
		ortayaYaz("[1] Rastgele Harf Aç (10 Puan)", 7, 7);
	}
    else{
    	ortayaYaz("[1] Tüm harfler açıldı", 7, 8);
	} 
    
    
    
    if(*ip2 == 1){
    	ortayaYaz("[2] İlk Harfi Göster (15 Puan)", 9, 7);
	} 
    else{
    	ortayaYaz("[2] Bu ipucu kullanıldı", 9, 8);
	} 
    
    
    char buffer[100];
    if(*ip3 == 1){
    	if(i_mod == 1){
    		sprintf(buffer, "[3] %s Göster (20 Puan)", "Bölgeyi");
		}
		else{
			sprintf(buffer, "[3] %s Göster (20 Puan)", "Kıtayı");
		}
		ortayaYaz(buffer, 11, 7);
	} 
    else{
		ortayaYaz("[3] Bu ipucu kullanıldı", 11, 8);
	} 
    
    
    
    ortayaYaz("[4] İptal / Geri Dön", 14, 11);
    
    
    
    int a = getch();
    int k,p = 0;
    switch(a){
        case '1':
            if(*ip1 == 1){
                int var_mi = 0;
                for(k = 0; k < i_uzunluk; k++){
                	if(i_gorunen[k] == '_'){
                		var_mi++;
					}
				} 
                if(var_mi > 1){
                    int sayi = rand() % i_uzunluk; 
                    while(i_dogru_cevap[sayi] == ' ' || i_gorunen[sayi] != '_'){
                        sayi = rand() % i_uzunluk;
                    }
                    i_gorunen[sayi] = i_dogru_cevap[sayi];
                    p = 10;
                }
                else{
                	int sayi = rand() % i_uzunluk; 
                    while(i_dogru_cevap[sayi] == ' ' || i_gorunen[sayi] != '_'){
                        sayi = rand() % i_uzunluk;
                    }
                    i_gorunen[sayi] = i_dogru_cevap[sayi];
                    p = 10;
                	*ip1 = 0;
				}
            }
            else{
            	ortayaYaz("Tüm harfler zaten açıldı", 16, 12);
                Sleep(1000);
			}
			break;
			
        case '2':
            if(*ip2 == 1 && i_gorunen[0] == '_'){ 
			    i_gorunen[0] = i_dogru_cevap[0]; 
				p = 15; 
				*ip2 = 0;
			}
			else{
				if(*ip2 == 0){
					ortayaYaz("Bu ipucu zaten kullanıldı", 16, 12);
                	Sleep(1000);
				}
				else{
					ortayaYaz("Bu ipucu kullanılamıyor", 16, 12);
                	Sleep(1000);
				}
			}
            break;
            
        case '3':
            if(*ip3 == 1){
			    p = 20;
				*ip3 = 0;
			}
			else{
				ortayaYaz("Bu ipucu zaten kullanıldı", 16, 12);
                	Sleep(1000);
			}
            break;
    }
    return p;
}
