#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
int st[100],n,nr,m[100];

void afisare(int v[100],int k)
{
    for(int i=1;i<=k;i++)
        cout<<m[v[i]]<<" ";
    cout<<endl;
}
int succesor(int v[100], int k)
{
    if(v[k]<n) {v[k]++; return 1;}
        else return 0;
}
int valid(int v[100], int k)
{
    for(int i=1;i<k;i++)
        if(v[i]==v[k])return 0;
    if(k>1)
    {
        if( m[st[k]]%2==0 && m[st[k-1]]%2==0 )return 0;
        if( m[st[k]]%2!=0 && m[st[k-1]]%2!=0 )return 0;
    }
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
            if(solutie(k))afisare(st,k);
            else {k++; st[k]=0;}
        else k--;
    }
}

int main()
{
    cout<<"n=";cin>>n;
    cout<<"Introduceti nr: "<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<i<<": ";cin>>m[i];
    }
    backtrack();


return 0;
}
