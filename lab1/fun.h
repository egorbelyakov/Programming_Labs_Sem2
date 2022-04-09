#ifndef FUN_H
#define FUN_H

using namespace std;

namespace fun
{
    struct Complex
    {
        float real;
        float image;
        float n;
    };

   void mod1(int *, int *);
   void mod2(int &, int &);

   void rounding1(float *);
   void rounding2(float &);

   void transp1(int *ta, int *tf);
   void transp2(int (&arr)[3][3], int (&arr2)[3][3]);

   void comp1(Complex *, float *);
   void comp2(Complex &, float &);
}
#endif // FUN_H
