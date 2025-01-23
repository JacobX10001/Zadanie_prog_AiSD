#include <iostream>
#include <iomanip>

#define N 8

using namespace std;

void Wypisz(int *tab)
{
    for(int i=0;i<N;i++)
    {
        cout<<setw(3)<<tab[i];
    }
    cout<<endl;
}

void przesun(int *tab)
{
    int uj=0, dod=0;
    int *dodatnie, *ujemne; //wskazniki do tablic dynamicznych
    for(int i=0;i<N;i++)
    {
        if(tab[i]<0)uj++;
    }
    if(uj!=0&&uj!=N)
	{
	    dod=N-uj;
	    dodatnie=new int[dod];
	    ujemne=new int[uj];
	    int nowa_tab[N];
	    int p1=0, p2=0;
	    for(int i=0;i<N;i++)
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
	    for(int i=0;i<N;i++)
	    {
	        if(i<dod) nowa_tab[i]=dodatnie[i];
	        if(i>=dod) nowa_tab[i]=ujemne[i-dod];
	    }
	    cout<<"Tablica po wykonaniu operacji: "<<endl;
	    Wypisz(nowa_tab);
    
    delete[] dodatnie;
    delete[] ujemne;
	}
	else Wypisz(tab);
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
    return 0;
}
