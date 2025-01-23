#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>

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

void GenTab1(int*tab, int n) //generowanie liczb dodatnich z jedną liczbą ujemną pod koniec
{
	srand(time(NULL));
	for(int i=0;i<n;i++)
	{
		tab[i]=rand()%10; //losowanie liczb z przedziału (min, max)
	}
	tab[n-4]=-5;
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


void przesun(int *tab, int n)
{
    int uj=0, dod=0; long long lo=0;
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
	    int nowa_tab[n];
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
	        lo++;
	    }
	    for(int i=0;i<n;i++)
	    {
	        if(i<dod) nowa_tab[i]=dodatnie[i];
	        if(i>=dod) nowa_tab[i]=ujemne[i-dod];
	        lo++;
	    }
    	cout<<"Liczba operacji: "<<lo<<"	";
    	delete[] dodatnie;
    	delete[] ujemne;
	}
	else Wypisz(tab,n);	    
}

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

void Menu()
{
	cout<<"Prorgram wykonuje operacje przesuwania liczb ujemnych na koniec zgodnie z kolejnoscia"<<endl;
    cout<<"W jaki sposob wygenerowac tablice? "<<endl;
    cout<<"[1] - wprowadzenie danych z klawiatury"<<endl;
    cout<<"[2] - losowe wartosci z podanego przedzialu"<<endl;
    cout<<"[3] - tablica przykładowa z tresci zadania"<<endl;
    
}

int main()
{
    int *tab;
    /*cout<<"Przyapdek 1: "<<endl;
    for(int i=5;i<=5000;i+=5)
    {
    	tab=new int[i];
    	GenTab1(tab,i);
    	przesun(tab,i);
		delete[]tab;	
	}
	cout<<"Przyapdek 2: "<<endl;
    for(int i=5;i<=5000;i+=5)
    {
    	tab=new int[i];
    	GenTab2(tab,i);
    	przesun(tab,i);	
    	delete[]tab;
	}*/
	for(int i=10000;i<=500000;i+=10000)
    {
    	int *tab;
		tab=new int[i];
    	GenTab3(tab,i);
		cout<<"n="<<i<<"	";
    	auto start = chrono::high_resolution_clock::now();
		przesun(tab,i);
    	auto end = std::chrono::high_resolution_clock::now();
    	chrono::duration<double, std::milli> elapsed = end - start;
    	cout<<"	Czas wykonywania programu: "<<elapsed.count()<<" ms"<<"		";
    	cout<<"Zlozonosc pamieciowa w bajtach: "<<3*sizeof(int)*i+5*sizeof(int)<<endl;
		delete[]tab;	
	}
    return 0;
}

