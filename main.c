#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	FILE *input;  //Ilk önce burada dosyayi isaretlemek icin "pointer" "input" kullaniyoruz.
	
	input = fopen("C:\\Users\\umuto\\OneDrive\\Masaüstü\\Lecture\\C\\Assignments\\2\\input.txt","r"); //Burada isaretlenen dosyayinin dizinini belirtiyoruz ve dosyayi açiyoruz.
																									  //Ve diger "r" argümani okumak için yaziyoruz.	
	
	FILE *encrypted; //Diger bir dosyaya yazdirmak icin bir pointer daha kullaniyoruz.
	
	encrypted = fopen("C:\\Users\\umuto\\OneDrive\\Masaüstü\\Lecture\\C\\Assignments\\2\\encrypted.txt","a"); //Burada append yazilmasinin sebebi; dosyaya eklemektir.
	
	int float_key; //Burada anahtar kaydirma degerini tanimliyoruz.
		
	start_point: 
	printf("Lutfen anahtar kaydirma degerini giriniz: ");
	if(scanf("%d",&float_key) != 1){						//Bu blokta "float_key" degerinin herhangi bir karakter yazilmasini engelliyoruz.
	printf("Sayi girmelisiniz!\n");
	fflush(stdin);
	goto start_point;
}
	
	char characters[50]; //Burada karakterlerde islem yapabilmek icin bir dizi olusturuyoruz.
	int i = 0;		//Döngü için i degiskeni  olusturuyoruz.
	char character; //Burada karakterler için bir degisken olusturuyoruz. 

	while(character != EOF){ //Burada input dosyasinin sonuna gelene kadar döngü devam etsin diyoruz. (EOF = End of File)
	
		character = getc(input);	//Burada karakterleri aliyoruz.
			
		characters[i] = character;	//Burada alinan karakterleri olusturdugumuz diziye ekliyoruz.
		
		if (characters[i] == ' '){   //Burada bosluk karakterini dönüstürmeyi engelliyoruz
			putc(' ',encrypted);	//Bosluk karakterini yeni dosyamiza yazdirdik.
			continue;
		}
		else if(characters[i] == '.'){ //Burada da nokta karakterinin dönüsmesini engelliyoruz.
			putc('.',encrypted);		//Nokta karakterini yeni dosyamiza yazdiriyoruz
			continue;
		}
		
		//printf("%c",characters[i]);
		
		int ASCII_value = characters[i];  //Burada karakterin ASCII degerini aliyoruz.
		
		if(ASCII_value == 10){	
			putc('\n', encrypted);
			continue;
		}
		else if(ASCII_value > 65 && ASCII_value < 90){
			ASCII_value += float_key;					//Bu bloklarda özel karakterleri engelliyoruz
			if(ASCII_value > 97){
				ASCII_value -= 32;
				putc(ASCII_value, encrypted);
				i++;
				continue;
			}
		}
		
		ASCII_value += float_key;    //Burada karakterin ASCII degerini kullanicidan aldigimiz anahtar degerini ekliyoruz.
		
		if(ASCII_value > 122){
			ASCII_value -= 26;
		}
		else if(ASCII_value > 90 && ASCII_value < 97){		//Bu bloklarda büyük ve küçük harf duyarliligini uyduruyoruz
			ASCII_value  -= 26;
		}
		else if(ASCII_value < 65){
			continue;
		}
		//printf("%d\n",ASCII_value);
		
		putc(ASCII_value, encrypted);		//Yeni karakteri yeni dosyamiza ekliyoruz.
		
		i++;			//Döngü sonsuza girmesin diye i degerini 1 artiriyoruz.
};
	return 0;
}
