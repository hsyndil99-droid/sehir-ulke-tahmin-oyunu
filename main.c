#include <stdio.h>
#include <time.h>              //srand fonksiyonu için gerekli
#include <stdlib.h>            //srand fonksiyonu için gerekli
#include <locale.h>            //türkçe çýktý karakterler için gerekli
#include <string.h>            //dizilerdeki iþlemler için gerekli              
#include <ctype.h>             //tahmin kelimelerindeki harfleri büyütmek için gerekli[toupper()]
#include "sehirler_ulkeler.h"  

int rastgele(int x);
void temizle(char x[]);
int ipucu(int i_mod,int i_uzunluk,int i_harf,char i_dogru_cevap[],char i_bolge[],char i_gorunen[]);


int main(void) {
	setlocale(LC_ALL, "Turkish");       //Türkçe karakterleri terminalde doðru gösterir.
	srand(time(NULL));
	
	
	//KURALLAR

	printf("---Þehir/Ülke Tahmin Oyununa Hoþgeldiniz---\n\n\a");
	printf("Oyuna baþlamadan önce genel kurallarý görmek için ENTER'a basýnýz.\n");
	getchar();
	printf("Oyuna 150 puan ile baþlýyorsunuz.\n");
	printf("Her bilmediðiniz turda 10 puan kaybedersiniz.\n");
	printf("Ayrýca puan kullanarak ipucu alabilirsiniz.\n");
	printf("Her modda yalnýzca 3 ipucu vardýr.\n");
	printf("Puanýnýz veya hakkýnýz bittiðinde oyun sonlanýr.\n\n");
	printf("Tahmin yapacaðýnýz kelimelerde lütfen Türkçe karakter(ç,ð,ý,ö,þ,ü,Ç,Ð,Ý,Ö,Þ,Ü) kullanmayýnýz.\n");
	printf("ÝZMÝR yerine Izmir, Çin halk cumhuriyeti yerine Cin Halk Cumhuriyeti vb.\n\n");
	printf("Oyun modu seçmek için ENTER'a basýn.\n\n");
	getchar();
	
	
	
	// Mod seçimi ve rastgele þehir/ülke seçilmesi
	
	printf("Þehir modu için '1' tuþlayýnýz.\t\t\tÜlke modu için '2' tuþlayýnýz.\n");
	int secim = getchar();
	
	char dogru_cevap[50];
	char dogru[50];
	char bolge[50];
	int mod,indeks,hak,puan=150;
	
	switch(secim){
		case '1':
			printf("\n\n\nÞehir modunda 7 hakkýnýz vardýr.\n");
			printf("Þehir Modu Baþlatýlýyor...\n\n\n");
			
			indeks=rastgele(81);                                             //Rastgele þehir seçildi.  
			strcpy(dogru_cevap, Sehirler[indeks].teknik_ad);                 //Þehir ile birlikte teknik isim ve bulunduðu bölge deðiþkene atandý.
			strcpy(dogru,Sehirler[indeks].gorsel_ad);
			strcpy(bolge,Sehirler[indeks].bolge);
			hak=7;
			mod=1;
			
			break;
		case '2':
			printf("\n\n\nÜlke modunda 10 hakkýnýz vardýr.\n");
			printf("Ülke Modu Baþlatýlýyor...\n\n\n");
			
			indeks=rastgele(196);                                            //Rastgele ülke seçildi.
			strcpy(dogru_cevap, Ulkeler[indeks].teknik_ad);                  //Ülke ile birlikte teknik isim ve bulunduðu kýta deðiþkene atandý.
			strcpy(dogru,Ulkeler[indeks].gorsel_ad);
			strcpy(bolge,Ulkeler[indeks].bolge);
			hak=10;
			mod=2;
			
			break;
		default:
            printf("\nHata: Geçersiz seçim. Programdan çýkýlýyor.\n");       
            mod=0;
            break;
	}
	if(mod == 0){
	}
	else{
	
	printf("***********************************************************************************************************************\n\n\n");
	//Oyun Baþlangýç ekraný
	
	if(mod == 1){
		printf("Þehir:");
	}
	else{
		printf("Ülke:");
	}
	
	int i,harf=0,uzunluk=strlen(dogru_cevap);         //Seçilen cevap harf sayýsýnca alt tire(_) ile ekrana yazdýrýldý. 
	char gorunen[50];                                 //Ayrýca ekrana yazýlan alt tireli gizli cevap gorunen deðiþkenine olduðu gibi yazýldý.
	for(i=0;i<uzunluk;i++){                           //Bunun sebebi ipucu sayfasýnda daha rahat iþlem yapabilmek için.
		if(dogru_cevap[i] == ' '){
			printf(" ");
			gorunen[i]=' ';
		}
		else{
			printf("_");
			gorunen[i]='_';
			harf++;
		}
	}
	gorunen[uzunluk] = '\0';       //Gorunen deðiþkeninin son satýrýna \0 eklenerek  tam bir string yapýlmýþtýr.
	
	printf("(%d)",harf);
	printf("\t\t\t\tPuan: %d\tKalan Hak: %d\tÝpucu kullanmak için '1' yazýp ENTER'a basýnýz.\n",puan,hak);
	printf("\n\nLütfen tahmininizi yazýnýz:\t");
	
	while (getchar() != '\n' && getchar() != EOF);   //Önceden kalan enter tuþlarýný siler.
	
	char tahmin[50];
	
	while(hak>0 && puan>0){
		fgets(tahmin,50,stdin);   //Kullanýcýdan tahmin alýnýr.
		temizle(tahmin);          //Burada bütün harfler büyütülür ve fgets fonk. yüzünden string sonunda olan \n karakteri \0 ile deðiþtirilir.
		
		if( strcmp(tahmin,"1") == 0 ){      //Ýpucu sayfasý açýlýr.
			puan -= ipucu(mod,uzunluk,harf,dogru_cevap,bolge,gorunen);
			printf("\t\t\t\tPuan: %d\tKalan Hak: %d\n\n",puan,hak);
			
		}
		else{
			if( strcmp(tahmin,dogru_cevap) == 0 ){
				if(mod == 1){	
				    printf("Tebrikler. Doðru cevabý (%s) %d. denemede buldunuz.  Kazanýlan Puan: %d",dogru,8-hak,puan);
				}
				else{
					printf("Tebrikler. Doðru cevabý (%s) %d. denemede buldunuz.  Kazanýlan Puan: %d",dogru,11-hak,puan);
				}
				break;
			}
			else{
				hak--;
				puan-=10;
				if(hak != 0){
				    printf("Yanlýþ cevap. Tekrar deneyiniz.\t\tPuan: %d\tKalan Hak: %d\n\n",puan,hak);
				    printf("***********************************************************************************************************************\n");
				}
				
			}
		}
	}
	
	if(hak == 0){
		printf("Hakkýnýz bitti.Doðru cevap:\t%s",dogru);
	}
	else if(puan == 0){
		printf("Puanýnýz bitti.Doðru cevap:\t%s",dogru);
	}
	}
	return 0;
}

//rastgele sayý üretildi
int rastgele(int x){
	
	int random = rand() % x;	
	return random;
}



//Kullanýcýdan alýnan tahmin kelimesinin bütün harfleri büyütülür ayrýca string içinde bulunan \n karakteri \0 ile deðiþtirilir. 
void temizle(char x[]){
	
	int tahmin_uzunluk = strlen(x);
	
	if (x[tahmin_uzunluk - 1] == '\n') {
        x[tahmin_uzunluk - 1] = '\0';
        tahmin_uzunluk--;
    }
    
	int j;    
	for(j=0;j<tahmin_uzunluk;j++){
    	x[j] = toupper(x[j]);
	}
}




//Ýpucu sayfasý
int ipucu(int i_mod,int i_uzunluk,int i_harf,char i_dogru_cevap[],char i_bolge[],char i_gorunen[]){
	
	printf("Seçmek istediðiniz ipucunun numarasýný giriniz:\n\n");
	
	static int ipucu_2=1, ipucu_3=1;
	




    //Ýpucular
	printf("-1-\t(10 Puan)\tRastgele bir harf göster.\n");
	
	
	if(ipucu_2 == 1){
    	printf("-2-\t(15 Puan)\tÝlk harfi göster.\t\t\t(Bir kez kullanýlabilir)\n");
	}
	else{
		printf("Bu ipucu kullanýldý.\n");
	}
	
	
	if(ipucu_3 == 1){
    	if(i_mod == 1){
	    	printf("-3-\t(20 Puan)\tÞehrin bulunduðu bölgeyi göster.\t(Bir kez kullanýlabilir)\n");
	    }
	    else{
    	    printf("-3-\t(20 Puan)\tÜlkenin bulunduðu kýtayý göster.\t(Bir kez kullanýlabilir)\n");		
	    }	
	}
	else{
		printf("Bu ipucu kullanýldý.\n");
	}
	
	printf("-4-\tGeri dön.\n");
	
	
	
	
	
	
	int a = getchar();
	int sayi,p;
	
	switch(a){
		case '1':	                                        //Rastgele bir harf gösterir.
		    sayi = rand() % i_uzunluk;                      //Birden fazla kez kullanýlabilir.
     	    while(i_dogru_cevap[sayi] == ' '){              //10 puan karþýlýðýnda kullanýlýr.
	   	    	sayi = rand() % i_uzunluk;                         
	        }		        
		    if(i_gorunen[sayi] == '_'){
	        	i_gorunen[sayi] = i_dogru_cevap[sayi];
	            printf("%s",i_gorunen);
                printf("(%d)",i_harf);
				}
			else{
				while(i_gorunen[sayi] != '_'){              
					sayi = rand() % i_uzunluk;
				}				
				i_gorunen[sayi] = i_dogru_cevap[sayi];
		        printf("%s",i_gorunen);
	            printf("(%d)",i_harf);
		    }
            p=10;
            
	        break;
	        
	    case '2':                                          //Ýlk harfi gösterir.
	    	if(ipucu_2 == 1){                              //Bir kez kullanýlabilir.
	    		if(i_gorunen[0] == '_'){                   //Eðer rastgele harfte ilk harf çýkmýþsa kullanýlamaz.
				    i_gorunen[0]=i_dogru_cevap[0];         //15 puan karþýlýðýnda kullanýlýr.
	    		    printf("%s",i_gorunen);	
				    printf("(%d)",i_harf);
				
	                p=15;
	                ipucu_2=0;
				}
				else{
					printf("Bu ipucu kullanýlamýyor.");
					p=0;
				}
	    		
			}
			else{
				printf("\nBu ipucu kullanýldý.\n");
			}
		   
	        break;
	    
		case '3':                                           //Þehrin bulunduðu bölgeyi gösterir.
		    if(ipucu_3 == 1){                               //Ülkenin bulunduðu kýtayý gösterir.
		    	if(i_mod == 1){                             //Bir kez kullanýlabilir.
		    		printf("%s Bölgesi",i_bolge);           //20 puan karþýlýðýnda kullanýlýr.
				}
				else{
					printf("%s",i_bolge);
				}
		    	p=20;
		    	ipucu_3=0;
			}    
			else{
				printf("\nBu ipucu kullanýldý.\n");
			}
			break;
			
		case '4':
			p=0;
			break;
			
		default:
			printf("\nHata: Geçersiz seçim. Ýpucu sayfasýndan çýkýlýyor.\n");
			p=0;
			break;
	    
	}
	while (getchar() != '\n' && getchar() != EOF);
	
	return p;
}
