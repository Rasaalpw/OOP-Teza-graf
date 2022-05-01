#include <iostream>
#include "Graf.h"
#include <fstream>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
int main()
{
    char raspuns;
    //int mat[5][5]={ {0,1,1,0,1} , {1,0,0,1,1} , {1,0,1,1,1} , {1,1,1,0,0} , {1,0,1,0,1} };
    Graf a;
    // Graf b(5, 5, mat);
    Graf c(a);
    int v[] = { 1,3,5 };///PENTRU PUNCTUL D
    int w[5];
    int x;

    cout << "Introduceti in aceasta ordine urmatoarele valori pentru numarul de noduri, numarul de muchii, si perechile : " << endl;
    cin >> a;


    while (true)
    {
        cout << '\n';
        
        cout << '\n';
        cout << "a) Returnarea numarului de noduri din graf\n" << endl;
        cout << "b) Returnarea gradului unui nod din graf\n " << endl;
        cout << "c) Verificarea grafului daca este unul de tip bipartit\n" << endl;
        cout << "d) Verificarea grafului daca graful este un ciclu hamiltonian\n" << endl;
        cout << "e) Returnarea unui ciclu hamiltonian din graf, si verificarea existentei acestuia\n" << endl;
        cout << "h-z) Iesirea din program\n" << endl;
        cout << '\n';
        cin >> raspuns;
        if (!(raspuns >= 'a' && raspuns <= 'z'))
        {
            cout << "Nu este o optiune valida!" << endl;
            continue;
        }
        else if (raspuns == 'a')
        {
            std::cout <<"Numarul de noduri din graf este : " << a.GetNrNod() << endl;
        }
        else if (raspuns == 'b')
        {
            cout << "Introduceti un nod din graf : ";
            std::cin >> x;
            std::cout <<"Gradul nodului"<<x<<" este : " << a.GetGrad(x) << endl;
        }
        else if (raspuns == 'c')
        {
            std::cout << a.Bipartit() << endl;
        }
        else if (raspuns == 'd')
        {
            std::cout << a.Hamiltonian(v, 5) << endl;
        }
        else if (raspuns == 'e')/// DE REZOLVAT
        {
            a.HamiltonianExist(w, 5);
        }
        else break;
    }
    return 0;
    

}