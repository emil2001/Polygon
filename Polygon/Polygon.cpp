

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

int main()
{
    struct point
    {
        double x, y;
        point* p;
    };
    srand(time(NULL));
    point* f, * c, * n;
    int N, chk =0;
    double v1x,v1y, v2x,v2y;
    ofstream fout("output.txt");
    cin >> N;
    f = new point;
    f->x = (double)rand() / RAND_MAX * 100;
    f->y = (double)rand() / RAND_MAX * 100;
    f->p = NULL;
    c = f;
    for (int i = 1; i < N; i++)
    {
        n = new point;
        n->x = (double)rand() / RAND_MAX * 100;;
        n->y = (double)rand() / RAND_MAX * 100;
        c->p = n;
        c = n;
    }
    c->p = f;
    for (int i = 0; i <= N; i++)
    {
        fout << f->x << " " << f->y << endl;
        n = f->p;
        v1x = n->x - f->x;
        v1y = n->y - f->y;
        c = n;
        if (chk == N-2 || chk == 0)
        {
            chk = 0;
            for (int i = 0; i < N - 2; i++)
            {
                c = c->p;
                v2x = c->x - f->x;
                v2y = c->y - f->y;
                if (v1x * v2y - v1y * v2x >= 0)
                {
                    chk += 1;
                }
            }
        }
        f = n;
    }
    if (chk == N-2 || chk == 0) fout << "Convex" << endl;
    else fout << "Concave" << endl;
    fout.close();
}

