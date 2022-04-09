#include "fun.h"
#include<iostream>

namespace fun
{
    void mod1(int *ta, int *tb)
    {
        if(*ta > *tb)
            *ta = *ta % *tb;
        else
            *tb = *tb % *ta;
    }

    void mod2(int &ta, int &tb)
    {
        if(ta > tb)
            ta = ta % tb;
        else
            tb = tb % ta;
    }

    void rounding1(float *ta)
    {
        if(*ta >= 0)
        {
            *ta = *ta + 0.5;
        }
        else
        {
            *ta = *ta - 0.5;
        }
        *ta = int(*ta);
    }

    void rounding2(float &ta)
    {
        if(ta >= 0)
        {
            ta = ta + 0.5;
        }
        else
        {
            ta = ta - 0.5;
        }
        ta = int(ta);
    }

    void transp1(int *ta, int *tf)
    {
        for(int i = 0; i < 3; i++)
            for(int j = 2; j >= 0; j--)
                tf[i * 3 + j] = ta[j * 3 + i];
    }

    void transp2(int (&arr)[3][3], int (&arr2)[3][3])
    {
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                arr2[i][j] = arr[j][i];
    }

    void comp1(Complex *tcomp, float *k)
    {
        tcomp -> real = (tcomp -> real) * (*k);
        tcomp -> image = (tcomp -> image) * (*k);
    }

    void comp2(Complex &tcomp, float &k)
    {
        tcomp.real = (tcomp.real) * (k);
        tcomp.image = (tcomp.image) * (k);
    }
}


