
#include <iostream>


using namespace std;


 // "normale", unverwaltete Klasse
class Punkt
{
public:
	int x;
	int y;
};


// Verwaltet Klasse mit dem Schlüsselwort "ref" davor
// funktioniert ersmal nur so weil ich als Project ein "CLR-Projekt" erstellt habe
ref class VerwalteterPunkt
{
public:
	int x;
	int y;
};





int main()
{
	cout << "Programm zu veralteten Klassen" << endl << endl;

	// Verwendung der unverwalteten Klase auf dem Stack (Stapelspeicher)
	Punkt p1;
	p1.x = 1;
	p1.y = 2;
	cout << "(" << p1.x << "," << p1.y << ")" << endl;


	// Verwendung der unverwalteten Klasse auf dem Heap (Haufenspeicher)
	Punkt* p2 = new Punkt;
	// Same shit
	(*p2).x = 10;
	p2->y = 20;
	cout << "(" << p2->x << "," << p2->y << ")" << endl;
	delete p2;


	// Vewrwendung der verwalteten Klasse (gc garbage collected -> Speicher wird automatisch aufgeräumt)
	VerwalteterPunkt^ p3 = gcnew VerwalteterPunkt;
	
	(*p3).x = 100;	// geht hier so aber auch
	p3->y = 200;
	cout << "(" << p3->x << "," << p3->y << ")" << endl;
	
	// Speicherfreigabe entfällt wegen gc


	// wird so wohl nicht wirklich in der Praxis umgesetzt
	// geht auch so , aber man verliert dann ja die Vorteile, wegen gc (sollte aufn Stack liegen)
	VerwalteterPunkt p4;
	p4.x = 1000;
	p4.y = 2000;
	cout << "(" << p4.x << "," << p4.y << ")" << endl;



	system("pause");
	return 0;
}