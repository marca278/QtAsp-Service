#include <Asp/aspobject.h>

void test2(void)
{
    Asp2<double> a;
    a.print();
    a.setId(23);
    a.print();

    Asp2<int> b;
    b.print();
    b.setId(56);
    b.print();

    Asp2<float> c(24, 45);
    c.print();
}
