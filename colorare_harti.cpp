#include <iostream>
#include <cmath>
#include <string.h>
#include <fstream>
using namespace std;

int st[100], n, nr;
int TARI[10][10];
char culori[5][10]={" ","rosu","galben","albastru","verde"};


void afisare(int k)
{
    cout<<"solutia: "<<nr<<endl;
    for(int i = 1; i<= k; i++){
        cout<<"Tara "<<i<<" are culoarea: "<<culori[st[i]]<<endl;
    }
}


int succesor(int k)
{
    if(st[k]<4)
    {
        st[k]++;
        return 1;
    }
    else return 0;
}

int solutie(int k)
{
        return k==n;
}

int valid(int k){
    for(int i = 1; i<k; i++)
        if(TARI[k][i]&&st[i]==st[k]) return 0;

    return 1;
}

void backtrack(int k)
{
    int as,ev;
    k=1;
    st[k]=0;
    while(k>0)
        {
          do
               { as=succesor(k);
                 if(as) ev=valid(k);
               }
               while(as && !ev);
        if(as)if(solutie(k)) {nr++;afisare(k);}
                else {k++;st[k]=0;}
        else k--;

    }
}



int main(){
    cout << "Cate tari sunt? ";
    cin >> n;
    ifstream f("tari.txt");
    for(int i = 1; i <= n; i++)
        for(int j =1; j <= n; j++)
            f>>TARI[i][j];
    backtrack(n);

    return 0;
}
