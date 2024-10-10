#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
int st[100],n,nr,c1,c2;

void afisare(int v[100],int k)
{
    for(int i=1;i<=k;i++)
        cout<<v[i]<<" ";
    cout<<endl;
}
int succesor(int v[100], int k)
{
    if(v[k]<n) {v[k]++; return 1;}
        else return 0;
}
int valid(int v[100], int k)
{
    if(k==2)if(v[k]!=c1)return 0;
    if(k==n-1)if(v[k]!=c2)return 0;
    for(int i=1;i<k;i++)
        if(v[i]==v[k])return 0;
    return 1;
}
int solutie(int k)
{
    return k==n;
}
void backtrack()
{int k,as,ev;
    k=1;st[k]=0;
    while(k>0)
    {
        do
        {
            as=succesor(st,k);

            if(as) ev=valid(st,k);
        }
        while(as && !ev);
        if(as)
            if(solutie(k)){nr++;afisare(st,k);}
            else {k++; st[k]=0; }
        else k--;
    }
}
int main()
{
    cout<<"n=";cin>>n;
    cout<<"c1=";cin>>c1;
    cout<<"c2=";cin>>c2;
    if(n>3)backtrack();
    cout<<"nr de solutii="<<nr<<endl;


return 0;
}
