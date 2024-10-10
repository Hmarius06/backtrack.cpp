#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

struct c
{
    int nr;
    char t[11];
};

c concurenti[30];
int sol[30], m, n, tot=1;

ifstream f("tari.txt");

void citire(c concurenti[], int &n)
{
    f >> n;
    f.get();
    for (int i=1; i<=n; i++)
        { concurenti[i].nr=i;
          f.getline(concurenti[i].t, 11);
        }
    f.close();
}

void afisare_initiala (c concurenti[], int n)
{
    for (int i=1; i<=n; i++)
         cout<<"Concurentul "<<concurenti[i].nr<<" provine din tara "<<concurenti[i].t<<endl;
    cout<<endl;
}


void afisare_solutie()
{
    cout << "Solutia "<<tot<<": "<<endl;
    for (int i=1; i<=m; i++)
        cout <<"concurentul "<< concurenti[sol[i]].nr << " (din tara " << concurenti[sol[i]].t<<")" << endl;
    cout << endl;
}

int succesor (int k)
{
    if (sol[k]<n) { sol[k]++;
                    return 1;
                  }
        else return 0;
}

int valid(int k)
{
    if (k>0 && strcmp(concurenti[sol[k]].t, concurenti[sol[k-1]].t)==0)
        return 0;

    if (k>0 && concurenti[sol[k]].nr<=concurenti[sol[k-1]].nr)
        return 0;

    return 1;
}

void backtracking()
{
    int k=1;
    sol[k]=0;
    while (k>0)
        { int as=1, ev=0;
          while (as && !ev) { as=succesor(k);
                              if (as) ev=valid(k);
                            }
          if (as) { if (k==m) { afisare_solutie();
                                tot++;
                              }
                        else { k++;
                               sol[k]=0;
                             }
                  }
              else k--;
        }
}

int main()
{
    citire(concurenti, n);
    afisare_initiala(concurenti, n);
    cout<<"\nintrodu nr de concurenti care participa in prima zi: ";
    cin>>m;
    backtracking();
    cout<<"\nnumarul total de solutii este: "<<tot-1<< endl;
    return 0;
}
