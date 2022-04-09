#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class IGeoFig
{
public:
    virtual double square() = 0;
    virtual double perimeter() = 0;
};

class CVector2D
{
public:
    double x, y;
};

class PhysObject
{
public:
    virtual double mass() const = 0;
    virtual bool operator== (const PhysObject& ob) const = 0;
    virtual bool operator< (const PhysObject& ob) const = 0;
};

class Printable
{
public:
    virtual void draw() = 0;
};

class DialogInitiable
{
    virtual void initFromDialog() = 0;
};

class BaseObject
{
public:
    virtual const char* classname() = 0;
    virtual int size() = 0;
};

class Gexagon: public IGeoFig, public CVector2D, public PhysObject, public Printable, public DialogInitiable, public BaseObject
{
private:
    CVector2D v1, v2, v3, v4, v5, v6;
    double mass_;
public:
    Gexagon()
    {
        v1.x = 0;
        v1.y = 0;
        v2.x = 0;
        v2.y = 0;
        v3.x = 0;
        v3.y = 0;
        v4.x = 0;
        v4.y = 0;
        v5.x = 0;
        v5.y = 0;
        v6.x = 0;
        v6.y = 0;
        mass_ = 0;
    }

    Gexagon(const double &x1, const double &y1, const double &x2, const double &y2,const double &x3, const double &y3, const double &x4, const double &y4, const double &x5, const double &y5, const double &x6, const double &y6, double mass) {
        v1.x = x1;
        v1.y = y1;
        v2.x = x2;
        v2.y = y2;
        v3.x = x3;
        v3.y = y3;
        v4.x = x4;
        v4.y = y4;
        v5.x = x5;
        v5.y = y5;
        v6.x = x6;
        v6.y = y6;
        mass_ = mass;
    }

    void initFromDialog() override
    {
        cout << "Enter coordinates" << endl;
        cin >> v1.x >> v1.y >> v2.x >> v2.y>> v3.x >> v3.y>> v4.x >> v4.y>> v5.x >> v5.y>> v6.x >> v6.y;
        cout << "Enter mass" << endl;
        cin >> mass_;
    }

    double square() override
    {
        return 3 * sqrt(3) *  pow(sqrt(pow(abs(v2.x - v1.x),2) + pow(abs(v2.y - v1.y),2)), 2);
    }

    double perimeter() override
    {
        return sqrt(pow(abs(v2.x - v1.x),2) + pow(abs(v2.y - v1.y),2)) * 6;
    }

    double mass() const override
    {
        return mass_;
    }

    bool operator == (const PhysObject &o) const override
    {
        return (mass_ == o.mass());
    }

    bool operator < (const PhysObject &o) const override
    {
        return (mass_ < o.mass());
    }

    void draw() override
    {
        cout << "Coordinates :(" << v1.x << ", " << v1.y << ") (" << v2.x << ", " << v2.y << ") (" << v3.x << ", " << v3.y << ") (" << v4.x << ", " << v4.y << ") (" << v5.x << ", " << v5.y << ") (" << v6.x << ", " << v6.y << ')' << endl;
        cout << "Mass: " << mass_ << endl;
    }

    const char* classname() override
    {
        return "Gexagon";
    }

    int size() override
    {
        int tmp = sizeof(*this);
        return tmp;
    }
};

class Triangle: public IGeoFig, public CVector2D, public PhysObject, public Printable, public DialogInitiable, public BaseObject {
private:
    CVector2D v1, v2, v3;
    double mass_;
public:
    Triangle() {
        v1.x = 0;
        v1.y = 0;
        v2.x = 0;
        v2.y = 0;
        v3.x = 0;
        v3.y = 0;
        mass_ = 0;
    }

    Triangle(const double &x1, const double &y1, const double &x2, const double &y2, const double &x3, const double &y3,
             double mass) {
        v1.x = x1;
        v1.y = y1;
        v2.x = x2;
        v2.y = y2;
        v3.x = x3;
        v3.y = y3;
        mass_ = mass;
    }

    void initFromDialog() override
    {
        cout << "Enter coordinates" << endl;
        cin >> v1.x >> v1.y >> v2.x >> v2.y >> v3.x >> v3.y;
        cout << "Enter mass" << endl;
        cin >> mass_;
    }

    double square() override
    {
       return (sqrt(3) / 4) * pow(sqrt(pow(abs(v2.x - v1.x),2) + pow(abs(v2.y - v1.y),2)), 2);
    }

    double perimeter() override
    {
        return sqrt(pow(abs(v2.x - v1.x),2) + pow(abs(v2.y - v1.y),2)) * 3;
    }

    double mass() const override
    {
        return mass_;
    }

  /*  CVector2D position() override
    {
        CVector2D res;
        res.x = (v1.x + v2.x) / 2;
        res.y = v1.y + (1 / 3) * (sqrt(3) / 2) * sqrt(pow(abs(v2.x - v1.x),2) + pow(abs(v2.y - v1.y),2));
        return res;
    }*/

    bool operator == (const PhysObject &o) const override
    {
        return (mass_ == o.mass());
    }

    bool operator < (const PhysObject &o) const override
    {
        return (mass_ < o.mass());
    }

    void draw() override
    {
        cout << "Coordinates :(" << v1.x << ", " << v1.y << ") (" << v2.x << ", " << v2.y << ") (" << v3.x << ", " << v3.y << ')' << endl;
        cout << "Mass: " << mass_ << endl;
    }

    const char* classname() override
    {
        return "Triangle";
    }

    int size() override
    {
        int tmp = sizeof(*this);
        return tmp;
    }
};

class Menu
{
private:
    vector<Gexagon> gex;
    vector<Triangle> tri;
    int opt;
public:
    void showm()
    {
        cout << "1 - Add Triangle\n 2 - Add Gexagon\n 3 - Show figures\n 4 - Show total area of figures\n 5 - Show total perimeter\n 6 - Show total memory\n 7 - Sort figures by mass\n 8 - Stop" << endl;
    }

    void f()
    {
        Gexagon g;
        Triangle t;
        double per = 0, area = 0, m = 0;
        int size = 0;
        cin >> opt;

        switch(opt)
        {
            case 1:
                t.initFromDialog();
                tri.push_back(t);
                break;

            case 2:
                g.initFromDialog();
                gex.push_back(g);
                break;

            case 3:
                for (int i = 0; i < gex.size(); i++) {
                    cout << " Gexagon" << endl;
                    gex[i].draw();
                    cout << endl;
                }
                for (int i = 0; i < tri.size(); i++) {
                    cout << " Triangle" << endl;
                    tri[i].draw();
                    cout << endl;
                }
                break;

            case 4:
                for (int i = 0; i < gex.size(); i++)
                {
                    area += gex[i].square();
                }

                for (int i = 0; i < tri.size(); ++i) {
                    area += tri[i].square();
                }
                cout << "Total area = " << area << endl;
                break;

            case 5:
                for (int i = 0; i < gex.size(); i++)
                {
                    per += gex[i].perimeter();
                }

                for (int i = 0; i < tri.size(); ++i) {
                    per += tri[i].perimeter();
                }
                cout << "Total perimeter = " << area << endl;
                break;

            case 6:
                for (int i = 0; i < gex.size(); i++)
                {
                    size += gex[i].size();
                }

                for (int i = 0; i < tri.size(); ++i) {
                    size += tri[i].size();
                }
                cout << "Total size = " << area << endl;
                break;

            case 7:
                sort(tri.begin(), tri.end());
                break;

            case 8:
                exit(0);
                break;

            default:
                cout << "Error";
        }
    }
};

int  main()
{
    Menu menu;
    menu.showm();
    while(true)
    {
        menu.f();
    }
    return 0;
}