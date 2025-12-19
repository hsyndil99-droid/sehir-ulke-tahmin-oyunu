#include <stdio.h>
#include <time.h>              //srand fonksiyonu için gerekli
#include <stdlib.h>            //srand fonksiyonu için gerekli
#include <locale.h>            //türkçe çıktı karakterler için gerekli
#include <string.h>            //dizilerdeki işlemler için gerekli              
#include <ctype.h>             //tahmin kelimelerindeki harfleri büyütmek için gerekli[toupper()]
#include "sehirler_ulkeler.h"  

int rastgele(int x);
void temizle(char x[]);
int ipucu(int i_mod,int i_uzunluk,int i_harf,char i_dogru_cevap[],char i_bolge[],char i_gorunen[]);


int main(void) {
	setlocale(LC_ALL, "Turkish");       //Türkçe karakterleri terminalde doğru gösterir.
	srand(time(NULL));
	
	
	//KURALLAR

	printf("---Şehir/Ülke Tahmin Oyununa Hoşgeldiniz---\n\n\a");
	printf("Oyuna başlamadan önce genel kuralları görmek için ENTER'a basınız.\n");
	getchar();
	printf("Oyuna 150 puan ile başlıyorsunuz.\n");
	printf("Her bilmediğiniz turda 10 puan kaybedersiniz.\n");
	printf("Ayrıca puan kullanarak ipucu alabilirsiniz.\n");
	printf("Her modda yalnızca 3 ipucu vardır.\n");
	printf("Puanınız veya hakkınız bittiğinde oyun sonlanır.\n\n");
	printf("Tahmin yapacağınız kelimelerde lütfen Türkçe karakter(ç,ğ,ı,ö,ş,ü,Ç,Ğ,İ,Ö,Ş,Ü) kullanmayınız.\n");
	printf("İZMİR yerine Izmir, Çin halk cumhuriyeti yerine Cin Halk Cumhuriyeti vb.\n\n");
	printf("Oyun modu seçmek için ENTER'a basın.\n\n");
	getchar();
	
	
	
	// Mod seçimi ve rastgele şehir/ülke seçilmesi
	
	printf("Şehir modu için '1' tuşlayınız.\t\t\tÜlke modu için '2' tuşlayınız.\n");
	int secim = getchar();
	
	char dogru_cevap[50];
	char dogru[50];
	char bolge[50];
	int mod,indeks,hak,puan=150;
	
	switch(secim){
		case '1':
			printf("\n\n\nŞehir modunda 7 hakkınız vardır.\n");
			printf("Şehir Modu Başlatılıyor...\n\n\n");
			
			indeks=rastgele(81);                                             //Rastgele şehir seçildi.  
			strcpy(dogru_cevap, Sehirler[indeks].teknik_ad);                 //Şehir ile birlikte teknik isim ve bulunduğu bölge değişkene atandı.
			strcpy(dogru,Sehirler[indeks].gorsel_ad);
			strcpy(bolge,Sehirler[indeks].bolge);
			hak=7;
			mod=1;
			
			break;
		case '2':
			printf("\n\n\nÜlke modunda 10 hakkınız vardır.\n");
			printf("Ülke Modu Başlatılıyor...\n\n\n");
			
			indeks=rastgele(196);                                            //Rastgele ülke seçildi.
			strcpy(dogru_cevap, Ulkeler[indeks].teknik_ad);                  //Ülke ile birlikte teknik isim ve bulunduğu kıta değişkene atandı.
			strcpy(dogru,Ulkeler[indeks].gorsel_ad);
			strcpy(bolge,Ulkeler[indeks].bolge);
			hak=10;
			mod=2;
			
			break;
		default:
            printf("\nHata: Geçersiz seçim. Programdan çıkılıyor.\n");       
            mod=0;
            break;
	}
	if(mod == 0){
	}
	else{
	
	printf("***********************************************************************************************************************\n\n\n");
	//Oyun Başlangıç ekranı
	
	if(mod == 1){
		printf("Şehir:");
	}
	else{
		printf("Ülke:");
	}
	
	int i,harf=0,uzunluk=strlen(dogru_cevap);         //Seçilen cevap harf sayısınca alt tire(_) ile ekrana yazdırıldı. 
	char gorunen[50];                                 //Ayrıca ekrana yazılan alt tireli gizli cevap gorunen değişkenine olduğu gibi yazıldı.
	for(i=0;i<uzunluk;i++){                           //Bunun sebebi ipucu sayfasında daha rahat işlem yapabilmek için.
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
	gorunen[uzunluk] = '\0';       //Gorunen değişkeninin son satırına \0 eklenerek  tam bir string yapılmıştır.
	
	printf("(%d)",harf);
	printf("\t\t\t\tPuan: %d\tKalan Hak: %d\tİpucu kullanmak için '1' yazıp ENTER'a basınız.\n",puan,hak);
	printf("\n\nLütfen tahmininizi yazınız:\t");
	
	while (getchar() != '\n' && getchar() != EOF);   //Önceden kalan enter tuşlarını siler.
	
	char tahmin[50];
	
	while(hak>0 && puan>0){
		fgets(tahmin,50,stdin);   //Kullanıcıdan tahmin alınır.
		temizle(tahmin);          //Burada bütün harfler büyütülür ve fgets fonk. yüzünden string sonunda olan \n karakteri \0 ile değiştirilir.
		
		if( strcmp(tahmin,"1") == 0 ){      //İpucu sayfası açılır.
			puan -= ipucu(mod,uzunluk,harf,dogru_cevap,bolge,gorunen);
			printf("\t\t\t\tPuan: %d\tKalan Hak: %d\n\n",puan,hak);
			
		}
		else{
			if( strcmp(tahmin,dogru_cevap) == 0 ){
				if(mod == 1){	
				    printf("Tebrikler. Doğru cevabı (%s) %d. denemede buldunuz.  Kazanılan Puan: %d",dogru,8-hak,puan);
				}
				else{
					printf("Tebrikler. Doğru cevabı (%s) %d. denemede buldunuz.  Kazanılan Puan: %d",dogru,11-hak,puan);
				}
				break;
			}
			else{
				hak--;
				puan-=10;
				if(hak != 0){
				    printf("Yanlış cevap. Tekrar deneyiniz.\t\tPuan: %d\tKalan Hak: %d\n\n",puan,hak);
				    printf("***********************************************************************************************************************\n");
				}
				
			}
		}
	}
	
	if(hak == 0){
		printf("Hakkınız bitti.Doğru cevap:\t%s",dogru);
	}
	else if(puan == 0){
		printf("Puanınız bitti.Doğru cevap:\t%s",dogru);
	}
	}
	getchar();
	return 0;
}

//rastgele sayı üretildi
int rastgele(int x){
	
	int random = rand() % x;	
	return random;
}



//Kullanıcıdan alınan tahmin kelimesinin bütün harfleri büyütülür ayrıca string içinde bulunan \n karakteri \0 ile değiştirilir. 
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




//İpucu sayfası
int ipucu(int i_mod,int i_uzunluk,int i_harf,char i_dogru_cevap[],char i_bolge[],char i_gorunen[]){
	
	printf("Seçmek istediğiniz ipucunun numarasını giriniz:\n\n");
	
	static int ipucu_2=1, ipucu_3=1;
	




    //İpucular
	printf("-1-\t(10 Puan)\tRastgele bir harf göster.\n");
	
	
	if(ipucu_2 == 1){
    	printf("-2-\t(15 Puan)\tİlk harfi göster.\t\t\t(Bir kez kullanılabilir)\n");
	}
	else{
		printf("Bu ipucu kullanıldı.\n");
	}
	
	
	if(ipucu_3 == 1){
    	if(i_mod == 1){
	    	printf("-3-\t(20 Puan)\tŞehrin bulunduğu bölgeyi göster.\t(Bir kez kullanılabilir)\n");
	    }
	    else{
    	    printf("-3-\t(20 Puan)\tÜlkenin bulunduğu kıtayı göster.\t(Bir kez kullanılabilir)\n");		
	    }	
	}
	else{
		printf("Bu ipucu kullanıldı.\n");
	}
	
	printf("-4-\tGeri dön.\n");
	
	
	
	
	
	
	int a = getchar();
	int sayi,p;
	
	switch(a){
		case '1':	                                        //Rastgele bir harf gösterir.
		    sayi = rand() % i_uzunluk;                      //Birden fazla kez kullanılabilir.
     	    while(i_dogru_cevap[sayi] == ' '){              //10 puan karşılığında kullanılır.
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
	        
	    case '2':                                          //İlk harfi gösterir.
	    	if(ipucu_2 == 1){                              //Bir kez kullanılabilir.
	    		if(i_gorunen[0] == '_'){                   //Eğer rastgele harfte ilk harf çıkmışsa kullanılamaz.
				    i_gorunen[0]=i_dogru_cevap[0];         //15 puan karşılığında kullanılır.
	    		    printf("%s",i_gorunen);	
				    printf("(%d)",i_harf);
				
	                p=15;
	                ipucu_2=0;
				}
				else{
					printf("Bu ipucu kullanılamıyor.");
					p=0;
				}
	    		
			}
			else{
				printf("\nBu ipucu kullanıldı.\n");
				p=0;
			}
		   
	        break;
	    
		case '3':                                           //Şehrin bulunduğu bölgeyi gösterir.
		    if(ipucu_3 == 1){                               //Ülkenin bulunduğu kıtayı gösterir.
		    	if(i_mod == 1){                             //Bir kez kullanılabilir.
		    		printf("%s Bölgesi",i_bolge);           //20 puan karşılığında kullanılır.
				}
				else{
					printf("%s",i_bolge);
				}
		    	p=20;
		    	ipucu_3=0;
			}    
			else{
				printf("\nBu ipucu kullanıldı.\n");
				p=0;
			}
			break;
			
		case '4':
			p=0;
			break;
			
		default:
			printf("\nHata: Geçersiz seçim. İpucu sayfasından çıkılıyor.\n");
			p=0;
			break;
	    
	}
	while (getchar() != '\n' && getchar() != EOF);
	
	return p;
}


