     ////////////////////////////////////////////
    //    Juhani Aalto                        //
   //     juhani.aalto@tuni.fi               //
  //      15.12.2022                        //
 //       Hotellihuone varaus v 1.0        //
////////////////////////////////////////////
#include <iostream>

using namespace std;


int main()
{
	//Asetetaan kieleksi suomi :)
	setlocale(LC_ALL, "fi_FI");
	//Asetetaan randille seedi.
	srand((unsigned int)time(NULL));
	
	//int maaraan tallentuu k‰ytt‰j‰n inputti halutuista huoneista
	int maara;
	//int valinta toimii menun 1-3 numeroisena valikkona
	int valinta;
	//Huoneiden m‰‰r‰
	const int huonemaara = (rand() % ((300-40) / 2) + (40 / 2)) * 2;
	//Varatut huoneet
	int vHuoneet = 0;
	//Huoneiden hinnat
	int huonehinnat = rand() % (100-80) + 80;
	//Laskujen loppu summa
	int summa = 0;

	
	cout << "\n Tervetuloa Hotelli Aaltoon :) \n";
	cout << "\n\t Vapaiden huoneiden m‰‰r‰: ";
	//tulostetaan huoneiden m‰‰r‰
	cout << huonemaara <<"\n";
	//tulostetaan huoneiden hinta per yˆ
	cout << "\n\t Hinta yˆlt‰: " << huonehinnat << "\n";
	
	
	cout << "\n Haluatko varata huoneen?";
	//m toimii checkpointtina gotolle
	m:
	cout << "\n\n1) Huonevaraus";
	cout << "\n2) Varauksien loppusumma";
	cout << "\n3) Lopeta\n";
	//k‰ytt‰j‰ valitsee menusta 1-3
	cin >> valinta;
	//switchi vaihtaa case 1-3 v‰lill‰, riippuen k‰ytt‰j‰n inputista
	switch (valinta)
	{
	case 1:

		cout << "Monta huonetta haluaisit varata?: ";
		//asetetaan m‰‰r‰ mit‰ halutaan varata
		cin >> maara;
		// Jos huoneiden m‰‰r‰ - varatut huoneet on suurempi tai yht‰ suuri kuin k‰ytt‰j‰n haluttu varausm‰‰r‰, ohjelma jatkuu.
		if (huonemaara - vHuoneet >= maara)
		{
			// lasketaan varatut huoneet + k‰ytt‰j‰n haluttu m‰‰r‰ ja asetetaan lopputulos vHuoneisiin
			vHuoneet = vHuoneet + maara;
			// lasketaan loppusumma kertomalla huoneiden hinnat halutulla huonem‰‰r‰ll‰, ja asetetaan lopputulos summaan.
			summa = summa + huonehinnat * maara;
			// tulostetaan kuinka monta varattua huonetta on, ja kuinka monta vapaata huonetta lˆytyy.
			cout << "\n\t" << vHuoneet << " varattua huonetta, " << huonemaara - vHuoneet << " vapaata huonetta j‰ljell‰.\n";
			// jos k‰ytt‰j‰ antaa kirjaimia, ohjelma pyyt‰‰ antaa numeroita
			if (cin.fail()) {
				cout << "\n\tAnna numeroita\n ";
			}
			break;

		}
		// jos huoneiden m‰‰r‰ - varatut huoneet on pienempi kun k‰ytt‰j‰n haluttu varausm‰‰r‰ ( eli siis hotelli t‰ynn‰ ), ohjelma tulostaa ett‰ vapaita huoneita ei ole en‰‰n j‰ljell‰
		else
		{ 
			cout << "Vapaita huoneita ei ole en‰‰n jaljella";
			break;
			

	case 2:
		// tulostetaan k‰ytt‰j‰n loppusumma ja kysyt‰‰n haluaisiko h‰n varata lis‰‰ huoneita
		cout << "\nVarauksien loppusummaksi tulee " << summa << " e,\n";
		cout << "Haluaisitko varata lis‰‰ huoneita? \n";
		break;
	case 3:
		// inputtaamalla menussa numero "3" lopettaa ohjelman
		exit(0);
		// jos yll‰olevista caseista mit‰‰n ei tapahdu, ohjelma tulostaa seuraavan
	default:
		cout << "\nValitse listatuista numeroista\n";

		}
	}
	
		// tyhjent‰‰ errorit jotka tapahtuvat kun cin ei onnistu ymm‰rt‰m‰‰n k‰ytt‰j‰n inputtia
	cin.clear();
		// tyhjent‰‰ cinin sis‰llˆn joka olisi tuottanut failuren normaalisti.
	cin.ignore(256, '\n');
	// vie takaisin checkpointtiin "m"
	goto m;
}