#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <time.h>
#include <chrono>

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



//Przypadek 1: 
void GenTab1(int*tab, int n) //generowanie liczb dodatnich z jedną liczbą ujemną pod koniec
{
	srand(time(NULL));
	for(int i=0;i<n;i++)
	{
		tab[i]=rand()%10; //losowanie liczb z przedziału (min, max)
	}
	tab[n-2]=-5;
}

void GenTab2(int*tab, int n) //generowanie liczb dodatnich z jedną liczbą ujemną na początku
{
	srand(time(NULL));
	for(int i=0;i<n;i++)
	{
		tab[i]=rand()%10; 
	}
	tab[2]=-5;
}


//Przypadek 2: 
void GenTab3(int*tab, int n) //generowanie tablicy z połową liczb dodatnich i połową ujemnych (ujemne na początku, dodatnie na końcu)
{
	srand(time(NULL));
	for(int i=0;i<n/2;i++)
	{
		tab[i]=rand()%10-11; //losowanie liczb ujemnych
	}
	for(int i=n/2;i<n;i++)
	{
		tab[i]=rand()%10; //losowanie liczb dodatnich
	}	
}

void GenTab4(int*tab, int n) //generowanie liczb ujemnych z jedną liczbą dodatnią pod koniec
{
	srand(time(NULL));
	for(int i=0;i<n;i++)
	{
		tab[i]=rand()%10-11; //losowanie liczb z przedziału (min, max)
	}
	tab[2]=5;
}

void GenTab5(int *tab,int n)
{
	for(int i=0;i<n;i++)
	{
		if(rand()%2==0) tab[i]=rand()%20-30;
	}
}

//Funkcja rozwiazujaca zadanie
void przesun(int *tab, int n)
{
    int nowa=0; //Nowa wartość do wstawienia
    int akt=0; //dotychczasowa wartość na danym indeksie tablicy
    int poz=0; //indeks tablicy 
    int licz=0, l=0; // licz- licznik liczb ujemnych , l -licznik przesunietych liczb (zabezpieczenie)
	long long lo=0; //lo- licznik operacji przypisania wartosci- pomocny przy wyznaczaniu zlozonosci obliczeniowej 
    for(int i=0;i<n;i++)
    {
        if(tab[i]<0)licz++;
    }
    if(licz!=0&&licz!=n)
	{	
		if(licz< n/2)
		{
			while(l<licz)
	    	{	
	        	while(tab[poz]>=0) {poz++;} //szukanie pozycji pierwszej ujemnej liczby
	        	l++;
	        	nowa=tab[poz];
	        	akt=tab[n-1];
	        	tab[n-1]=nowa;
	        	nowa=akt;
	        	lo++;
	        	for(int j=n-2;j>=poz;j--) //petla przesuwajaca liczby w tablicy od tylu
	        	{
	            	akt=tab[j];
	            	tab[j]=nowa;
	            	nowa=akt;
	            	lo++;
	        	}
	        	poz=0; //przegladam tablice od nowa w poszukiwaniu liczb ujemnych  
	    	}
		}
		else
		{
			licz=n-licz;
			int p=1; //indeks pozycji do zamiany
			while(l<licz)
	    	{	
	        	while(tab[poz]<0) poz++;//szukanie pozycji pierwszej dodatniej liczby 
				l++;
				lo++;
	        	nowa=tab[poz];
	        	akt=tab[p-1];
	        	tab[p-1]=nowa;
	        	nowa=akt;
	        	for(int j=p;j<=poz;j++) //petla przesuwajaca liczby w tablicy
	        	{
	            	akt=tab[j];
	            	tab[j]=nowa;
	            	nowa=akt;
	            	lo++;
	        	}
	        	poz++;
	        	p++;
	        	 //przegladam tablice od nowa w poszukiwaniu liczb ujemnych  
	    	}
		}
    	cout<<"Liczba operacji: "<<lo;
	}
}

int main()
{
	for(int i=10000;i<=500000;i+=10000)
    {
    	int *tab;
		tab=new int[i];
    	GenTab1(tab,i);
		cout<<"n="<<i<<"	";
    	auto start = chrono::high_resolution_clock::now();
		przesun(tab,i);
    	auto end = std::chrono::high_resolution_clock::now();
    	chrono::duration<double, std::milli> elapsed = end - start;
    	cout<<"	Czas wykonywania programu: "<<elapsed.count()<<" ms"<<endl;
    	//cout<<"Zlozonosc pamieciowa w bajtach: "<<sizeof(int)*i+5*sizeof(int)<<endl;
		delete[]tab;	
	}
	
    
    return 0;
}
