#include <iostream>
#include <iomanip>

#define N 8

using namespace std;


//Funkcja wypisujaca tablice
void Wypisz(int *tab)
{
    for(int i=0;i<N;i++)
    {
        cout<<setw(4)<<tab[i];
    }
    cout<<endl;
}

//Funkcja rozwiazujaca zadanie
void przesun(int *tab)
{
    int nowa=0; //Nowa wartość do wstawienia
    int akt=0; //dotychczasowa wartość na danym indeksie tablicy
    int poz=0; //indeks tablicy 
    int licz=0, l=0; // licz- licznik liczb ujemnych , l -licznik przesunietych liczb (zabezpieczenie)
	//int lo=0; //lo- licznik operacji przypisania wartosci- pomocny przy wyznaczaniu zlozonosci obliczeniowej 
    for(int i=0;i<N;i++)
    {
        if(tab[i]<0)licz++;
    }
    if(licz!=0&&licz!=N)
	{	
		while(l<licz)
    	{	
        	while(tab[poz]>=0) poz++; //szukanie pozycji pierwszej ujemnej liczby
        	l++;
        	nowa=tab[poz];
        	akt=tab[N-1];
        	tab[N-1]=nowa;
        	nowa=akt;
        	for(int j=N-2;j>=poz;j--) //petla przesuwajaca liczby w tablicy od tylu
        	{
            	akt=tab[j];
            	tab[j]=nowa;
            	nowa=akt;
        	}
        	poz=0; //przegladam tablice od nowa w poszukiwaniu liczb ujemnych  
    	}
    	cout<<"Tablica po wykonaniu operacji: "<<endl;
    	Wypisz(tab);
	}
}

int main()
{
    int tab[N]={-10,5,8,-4,1,3,0,-7};
    int tab2[N]={10,-5,-8,4,-1,-3,0,-7};
    int tab3[N]={-5,7,-3,18,0,-20,5,12};
    cout<<"Tablica 1 przed wykonaniem operacji: "<<endl;
    Wypisz(tab);
    przesun(tab);
    cout<<"Tablica 2 przed wykonaniem operacji: "<<endl;
    Wypisz(tab2);
    przesun(tab2);
    cout<<"Tablica 3 przed wykonaniem operacji: "<<endl;
    Wypisz(tab3);
    przesun(tab3);
    return 0;
}
