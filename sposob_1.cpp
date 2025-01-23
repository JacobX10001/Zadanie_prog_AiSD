#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <fstream>

#define N 8

using namespace std;


//Funkcja wypisujaca tablice
void Wypisz(int *tab, int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<setw(4)<<tab[i];
    }
    cout<<endl;
}

void GenTab(int*tab, int n, int min, int max)
{
	srand(time(NULL));
	for(int i=0;i<n;i++)
	{
		tab[i]=rand()%(max+abs(min))-abs(min); //losowanie liczb z przedziału (min, max)
	}
}

void WprowadzTab(int*tab, int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"Podaj wartosc tablicy na indeksie "<<i<<": ";cin>>tab[i];
	}
}

//Funkcja rozwiazujaca zadanie
void przesun(int *tab, int n)
{
    int nowa=0; //Nowa wartość do wstawienia
    int akt=0; //dotychczasowa wartość na danym indeksie tablicy
    int poz=0; //indeks tablicy 
    int licz=0, l=0; // licz- licznik liczb ujemnych , l -licznik przesunietych liczb (zabezpieczenie)
	//int lo=0; //lo- licznik operacji przypisania wartosci- pomocny przy wyznaczaniu zlozonosci obliczeniowej 
    for(int i=0;i<n;i++)
    {
        if(tab[i]<0)licz++;
    }
    if(licz!=0&&licz!=n)
    {
	    while(l<licz)
	    {
	        while(tab[poz]>=0) poz++; //szukanie pozycji pierwszej ujemnej liczby
	        l++;
			//lo++; 
	        nowa=tab[poz];
	        akt=tab[n-1];
	        tab[n-1]=nowa;
	        nowa=akt;
	        for(int j=n-2;j>=poz;j--) //petla przesuwajaca liczby w tablicy od tylu
	        {
	            akt=tab[j];
	            tab[j]=nowa;
	            nowa=akt;
	            //lo++;
	        }
	        poz=0; //przegladam tablice od nowa w poszukiwaniu liczb ujemnych  
	    }
	}
    cout<<"Tablica po wykonaniu operacji: "<<endl;
    Wypisz(tab,n);
    //cout<<"Liczba operacji: "<<lo<<endl;
}

void Menu()
{
	cout<<"Prorgram wykonuje operacje przesuwania liczb ujemnych na koniec zgodnie z kolejnoscia"<<endl;
    cout<<"W jaki sposob wygenerowac tablice? "<<endl;
    cout<<"[1] - wprowadzenie danych z klawiatury"<<endl;
    cout<<"[2] - losowe wartosci z podanego przedzialu"<<endl;
    cout<<"[3] - tablica przykladowa z tresci zadania"<<endl;
    cout<<"[4] - Wczytywanie tablicy z pliku tekstowego i wypisanie tablicy wynikowej do innego pliku"<<endl;  
}

void PlikTekstowy()
{
	ifstream in("dane.txt");
	ofstream out("wyniki.txt");
	int n, *tab;
	if(in.good())
	{
		while(!in.eof())
		{
			in>>n;
			tab=new int[n]; 
			for(int i=0;i<n;i++) in>>tab[i];
			przesun(tab,n);
			for(int i=0;i<n;i++) out<<tab[i]<<" ";
			out<<endl;
			delete [] tab;
		}
		
	}
	else cout<<"Brak pliku!"<<endl;
}



int main()
{
    int *tab, n, wybor;
	int t[8]={-10,5,8,-4,1,3,0,-7};
    Menu();
    cin>>wybor;
    switch(wybor)
    {
    	case 1:
    	{
			cout<<"Podaj rozmiar tablicy: ";cin>>n;
    		tab=new int[n];
    		WprowadzTab(tab,n);
    		break;
		}
		case 2:
		{
			cout<<"Podaj rozmiar tablicy: ";cin>>n;
    		tab=new int[n];
    		int min, max;
    		cout<<"Podaj maksymalna wartosc przedzialu losowania: ";cin>>max;
    		cout<<"Podaj minimalna wartosc przedzialu losowania:";cin>>min;
    		GenTab(tab,n,min,max);
    		break;
		}
		case 3:
		{
			n=8;	
		}
		case 4:
		{
			PlikTekstowy();
			cout<<"Utworzono plik wyniki.txt"<<endl;	
		}	
	}
    if(wybor!=3&&wybor!=4)
	{
		cout<<"Tablica przed wykonaniem operacji: "<<endl;
    	Wypisz(tab,n);
    	przesun(tab,n);
	}
	else if(wybor!=4) 
	{
		cout<<"Tablica przed wykonaniem operacji: "<<endl;
    	Wypisz(t,n);
    	przesun(t,n);
	}
    return 0;
}
