#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<stddef.h>

char ad[20];
char soyad[20];
char tel[20];
char adres[20];


FILE *dosya;
FILE *gecici;  //dosya silmek için oluşturuldu.



void musteriEkle()

{

    printf("\nMusteri kayit ekranina hosgeldiniz... \n");
    printf("ad: ");
    scanf("%s",ad);
    printf("soyad: ");
    scanf("%s",soyad);
    printf("tel: ");
    scanf("%s",tel);
    printf("adres: ");
    scanf("%s",adres);

    if((dosya=fopen("musterikayit.txt","a")) != NULL)
    
    {
        
        fprintf(dosya,"%s\t%s\t%s\t%s\n",ad,soyad,tel,adres);

    }

    printf("kayit basariyla eklendi... \n");
    fclose(dosya);


}

void musteriListele()
{
       
       system("cls");

       printf("\nMusteri kayit listeleme ekranina hosgeldiniz... \n");
       printf("Kayitli Musteri bilgileri \n");
       printf("************************** \n");
       printf("Ad\tSoyad\tTel\tAdres\n");

     
       if((dosya=fopen("musterikayit.txt","r")) != NULL)

       {

           strcpy(ad,"");
              strcpy(soyad,"");
                strcpy(tel,"");
                    strcpy(adres,"");

           
           while(!feof(dosya))  // dosya sonuna kadar okuma yapar

           {

               fscanf(dosya,"%s\t%s\t%s\t%s\n",ad,soyad,tel,adres); 

               printf("%s\t%s\t%s\t%s\n",ad , soyad , tel , adres);

           }
             printf("\n************************** \n");

       }

       printf("Listeleme islemi basarili... \n");
       fclose(dosya);


}


void musteriAra()
{
   
   system("cls");
   char isim[20];
   int sonuc;
   sonuc=0;


   printf("\nMusteri kayit arama ekranina hosgeldiniz... \n");
    
   printf("Aranacak Musteri adini giriniz: ");
   scanf("%s",isim);

   printf("\n************************** \n");
   printf("Ad\tSoyad\tTel\tAdres\t");
    
    if((dosya =fopen("musterikayit.txt","r")) != NULL)

    {
        while(!feof(dosya))

        {
            fscanf(dosya,"%s\t%s\t%s\t%s\n",ad,soyad,tel,adres);
            if(strcmp(isim,ad)==0)

            {
                printf("%s\t%s\t%s\t%s\n",ad,soyad,tel,adres);
                fclose(dosya);
                break;

            }

        }
        
        printf("\n************************** \n");

    }

    printf("Arama islemi basarili... \n");
    fclose(dosya);
    if(sonuc==0)
    printf("%s isimli musteri listede yok \n",isim);


}


void  yedekle()

{

  if((dosya=fopen("musterikayit.txt","r")) != NULL)

  {
      if((gecici=fopen("gecici.txt","w")) != NULL)

      {

            while(!feof(dosya))

            {
          
              fscanf(dosya,"%s\t%s\t%s\t%s\n",ad,soyad,tel,adres);

              fprintf(gecici,"%s\t%s\t%s\t%s\n",ad,soyad,tel,adres);
          }

      }

  }

   remove("musterikayit.txt");  // remove() dosyayı siler
   fclose(dosya);
   fclose(gecici);
  


}


void guncelle(char *ptrisim)

{

   if((dosya = fopen("musterikayit.txt" , "w"))!=NULL)

   {

     if((gecici= fopen("gecici.txt" , "r"))!=NULL)

     {

        while(!feof(gecici))

        {

            fscanf(gecici,"%s\t%s\t%s\t%s\n",ad,soyad,tel,adres);

            if(strcmp(ptrisim,ad)==0)
            continue;

            {
                fprintf(dosya,"%s\t%s\t%s\t%s\n",ad,soyad,tel,adres);

            }

        }

     }

     remove("gecici.txt");
     fclose(gecici);
     fclose(dosya);


   }


}


void musterisil()

{

  system("cls");
  char isim[20];
  int sonuc;
  sonuc=0;
   
   printf("silmek istediginiz musterinin adini giriniz: ");
    scanf("%s",isim);

    if ((dosya = fopen("musterikayit.txt","r")) != NULL)

    {
        
            while(!feof(dosya))


            {

                fscanf(dosya,"%s\t%s\t%s\t%s\n",ad,soyad,tel,adres);
                if(strcmp(isim,ad)==0)

                {
                   
                   fclose(dosya);
                   yedekle();
                   guncelle(isim);
                   sonuc=1;
                   break;

                }
     
            }

    }

    fclose(dosya);
    if(sonuc==0)
    printf("%s isimli musteri listede yok \n",isim);
    else
    
      printf("Silme islemi basarili... \n");
    
    


}


int main ()

{
	
 system("color 20");

 int secim= -1;
 while(secim!=0)

 {

    printf("\n1-Yeni Kayit \n");
    printf("2-Kayitlari Listele \n");
    printf("3-Ara \n");
    printf("4-Sil \n");
    printf("5-Guncelle \n");
    printf("6-Yedekle \n");
    printf("0-Cikis \n");
    printf("Seciminiz: ");
    scanf("%d",&secim);
 
    switch(secim)

    {

        case 1:
            musteriEkle();
            break;

        case 2:
            musteriListele();
            break;

        case 3:
            musteriAra();
            break;

        case 4:
            musterisil();
            break;

        
        case 0:
            printf("Cikis yapiliyor...");
            break;

        default:
            printf("Hatali secim!");
            break;
    }
    
 }




    return 0;

}
