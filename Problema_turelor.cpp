#include <iostream>
#include <cmath>
using namespace std;

int st[100], n, k,sol=0;

void afisare(int k)
{
    cout<<"\nSolutia "<<sol<<":"<<endl;
    for(int i=1;i<=n;i++)
    {
        for (int j=1; j<=k; j++)
            if (st[i]==j) cout<<"T";
                else cout<<"*";
        cout<< endl;
    }

}

int succesor(int k)
{
    if(st[k]<n)
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

int valid(int k)
{
    for(int i=1;i<k;i++)
        if(st[k]==st[i]) return 0;

}

void bt()
{
    k=1;
    st[k]=0;
    while(k>0)
        { int as=1, ev=0;
          while(as && !ev)
               { as=succesor(k);
                 if(as) ev=valid(k);
               }
        if(as){ if(solutie(k)) {sol++;
                                afisare(k);
                                }
            else {
                k++;
                st[k]=0;
            }
        }
        else k--;
    }
}

int main()
{
    cout << "Introduceti valoarea: ";
    cin >> n;
    bt();
    cout<<"\nSunt "<<sol<<" solutii";
    return 0;
}
