#include <iostream>
#include <iomanip>
#include <ctime>
#include <fstream>

#define N 8

using namespace std;

void Wypisz(int *tab, int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<setw(4)<<tab[i];
    }
    cout<<endl;
}


void GenTab(int *tab, int n, int min, int max)
{
	srand(time(NULL));
	for(int i=0;i<n;i++)
	{
		tab[i]=rand()%(max+abs(min))-abs(min);
	}
}

void WprowadzTab(int*tab, int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"Podaj wartosc tablicy na indeksie "<<i<<": ";cin>>tab[i];
	}
}


void przesun(int *tab, int n, int*nowa)
{
    int uj=0, dod=0;
    int *dodatnie, *ujemne; //wskazniki do tablic dynamicznych
    for(int i=0;i<n;i++)
    {
        if(tab[i]<0)uj++;
    }
    if(uj!=0&&uj!=n)
    {
    	dod=n-uj;
	    dodatnie=new int[dod];
	    ujemne=new int[uj];
	    int p1=0, p2=0;
	    for(int i=0;i<n;i++)
	    {
	        if(tab[i]<0)
	        {
	            ujemne[p1]=tab[i];
	            p1++;
	        }
	        else 
	        {
	            dodatnie[p2]=tab[i];
	            p2++;
	        }
	    }
	    for(int i=0;i<n;i++)
	    {
	        if(i<dod) nowa[i]=dodatnie[i];
	        if(i>=dod) nowa[i]=ujemne[i-dod];
	    }
	    
    //cout<<"Liczba operacji: "<<lo<<endl;
    
	delete[] dodatnie;
    delete[] ujemne;
	}
	else 
	{
		for(int i=0;i<n;i++) nowa[i]=tab[i];
	}
}

void Menu()
{
	cout<<"Prorgram wykonuje operacje przesuwania liczb ujemnych na koniec zgodnie z kolejnoscia"<<endl;
    cout<<"W jaki sposob wygenerowac tablice? "<<endl;
    cout<<"[1] - wprowadzenie danych z klawiatury"<<endl;
    cout<<"[2] - losowe wartosci z podanego przedzialu"<<endl;
    cout<<"[3] - tablica przykładowa z tresci zadania"<<endl;
    cout<<"[4] - wczytywanie wartosci z pliku tekstowego i wypisywanie wyników do pliku wynikowego"<<endl;
}
void PlikTekstowy()
{
	ifstream in("dane.txt");
	ofstream out("wyniki.txt");
	int n=0, *tab, *nowa;
	if(in.good())
	{
		while(in>>n)
		{
			tab=new int[n]; 
			nowa=new int[n];
			for(int i=0;i<n;i++) nowa[i]={0};
			for(int i=0;i<n;i++) in>>tab[i];
			przesun(tab,n,nowa);
			Wypisz(tab,n);
			Wypisz(nowa,n);
			cout<<"----------------------------------------"<<endl;
			for(int i=0;i<n;i++) out<<nowa[i]<<" ";
			out<<endl;
			delete [] tab;
			delete [] nowa;
		}
		
		in.close();
		out.close();

		
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
			n = 8;
            tab = t; // Statyczna tablica
            break;
		}  
        case 4:
        {
        	PlikTekstowy();
        	return 0;
		}   
    }
    if (wybor != 4) {
        int *nowa = new int[n];
        cout << "Tablica przed przesunieciem: ";
        Wypisz(tab, n);

        przesun(tab, n, nowa);

        cout << "Tablica po przesunieciu: ";
        Wypisz(nowa, n);

        delete[] nowa;
    }

    if (tab != t) delete[] tab;

    return 0;

}

