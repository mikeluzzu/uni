/*Scrivi un programma in C++ che funge da convertitore di valute semplice. L'utente dovrà inserire
un valore in Euro e scegliere la valuta di destinazione (Dollari USA, Yen Giapponesi, o Sterline
Britanniche) tramite un menu numerato. Il programma dovrà poi visualizzare l'importo convertito
sapendo che: 1 euro = 1.08 dollari USA, 168.22 Yen Giappo, 0.86 Sterline Bri ish

*/

#include <iostream>
using namespace std;

int main(){
	float valore;
	int valutaTarget;
	
	cout << "Inserisci il valore da convertire:\n";
	cout << "1.Dollari USA, 2.YEN Giapponesi, 3.Sterline\n";
	cin >> valore;
	cout << "Inserisci la valuta da convertire:\n";
	cin >> valutaTarget;
	float convert;
	switch (valutaTarget){
		case 1:
			convert = valore * 1.08;
			break;
		case 2:
			convert = valore * 168.22;
			break;
		case 3:
			convert = valore * 0.86;
			break;
		default:
			cout << "Errore. Inserisci un input valido.";
			
	}
	cout << convert << endl;  
	return 0;
}
