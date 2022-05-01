#include <iostream>
#include"Graf.h"
using namespace std;

void dfs(int nod, int a[101][101], int culoare, int cul[], int n, int& ok)
{   // afisam nodul curent
    cul[nod] = culoare;                     // marcam nodul curent ca fiind vizitat, colorat
    for (int i = 1; i <= n; i++)          // parcurgem toti vecinii nodului curent
        if (a[nod][i] == 1) {
            if (cul[i] == 0)                  // daca nodul nu este vizitat
                dfs(i, a, -culoare, cul, n, ok);             // il colorez complementar nodului curent
            else
                if (cul[nod] == cul[i])        // daca a mai fost vizitat, verific sa nu fie colorat la fel ca nodu lcurent
                    ok = 0;                       // in acest caz graful nu e biparti
        }
}
void afisare(int x[], int n, int& ok)
{
    std::cout << 1 << '\n';
    for (int i = 1;i <= n;i++)
        std::cout << x[i] << " ";
    std::cout << x[1];
    std::cout << '\n';
    ok = 1;
}

void back(int k, int n, int a[101][101], int& ok)
{
    int p[20] = { 0 };
    int x[20];
    for(int i=1;i<=n && !ok;i++)
        if (!p[i])
        {
            p[i] = 1;
            x[k] = i;
            if (k == 1 || a[x[k - 1]][x[k]] == 1)
            {
                if (k == n && a[x[k]][x[1]] == 1)
                    afisare(x, n, ok);
                else
                    back(k + 1, n, a, ok);
            }
            p[i] = 0;
        }
}
Graf::Graf()
{
    NrNod = 0;
    a[101][101] = { 0 };
}

Graf::Graf(int n, int m, int x[][101])
{
    NrNod = n;
    NrMuchii = m;
    for (int i = 1; i <= n; i++)
        for (int j = 1;j <= n;j++)
            a[i][j] = x[i][j];
}

Graf::Graf(const Graf& B)
{
    NrNod = B.NrNod;
    NrMuchii = B.NrMuchii;
    for (int i = 1; i <= NrNod; i++)
        for (int j = 1; j <= NrNod; j++)
        {
            a[i][j] = B.a[i][j];
        }
}

Graf::~Graf()
{
}

int Graf::GetNrNod()
{
    return NrNod;
}

int Graf::GetGrad(int x)
{
    int sum = 0;
    for (int i = 1; i <= NrNod; i++)
        if (a[x][i] == 1)
            sum++;
    return sum;
}

bool Graf::Bipartit()
{
    int cul[101] = { 0 };
    int ok;
    int p = 1;
    for (int i = 1; i <= NrNod; i++)
        if (cul[i] == 0) {
            ok = 1;
            dfs(i, a, 1, cul, NrNod, ok);
            p = (p && ok);
        }

    if (p) {                            // daca toate componentele au putut fi colorate
        return true;                   // graful e bipartit
    }
    else
        return false;
}

bool Graf::Hamiltonian(int v[], int n)
{
    if (n != NrNod)
        return false;
    else
    {
        for (int i = 1; i <= NrNod - 1; i++)
            if (a[i][i + 1] == 0)
                return false;
    }
    return true;
}

void Graf::HamiltonianExist(int v[], int n)
{
    int ok = 1;
    back(1, n, a, ok);
    if (ok == 0)
        std::cout << 0 << '\n';
}

ostream& operator<<(ostream& os, Graf& A)
{
    int i, j;
    os << A.NrNod << ' ' << A.NrMuchii << '\n';
    for (i = 1; i <= A.NrNod - 1; i++)
    {
        for (j = i + 1; j <= A.NrNod; j++)
            if (A.a[i][j] == 1)
                os << i << ' ' << j;
        os << '\n';
    }
    return os;
}

istream& operator>>(istream& is, Graf& A)
{
    int x, y;
    is >> A.NrNod;
    is >> A.NrMuchii;
    for (int i = 1; i <= A.NrMuchii; i++)
    {
        is >> x >> y;
        A.a[x][y] = 1;
        A.a[y][x] = 1;
    }
    return is;
}