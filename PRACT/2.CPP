// Overloading the arithmetic operators in FLOAT class

#include<iostream.h>
#include<conio.h>

class FLOAT
 {
        private:
         float m_float;
        public:
         FLOAT(){}
         FLOAT(float f)  { m_float = f; }
         void set(float f) { m_float = f; }
         void get();
         void Show();

         FLOAT operator + (FLOAT);
         FLOAT operator - (FLOAT);
         FLOAT operator * (FLOAT);
         FLOAT operator / (FLOAT);
 };

FLOAT FLOAT::operator + (FLOAT mf)
 { return FLOAT(m_float + mf.m_float); }

FLOAT FLOAT::operator - (FLOAT mf)
 { return FLOAT(m_float - mf.m_float); }

FLOAT FLOAT::operator * (FLOAT mf)
 { return FLOAT(m_float * mf.m_float); }

FLOAT FLOAT::operator / (FLOAT mf)
 { return FLOAT(m_float / mf.m_float); }

void FLOAT::Show()
 {  cout << m_float; }

void FLOAT::get()
 {
        cout << "Enter a floating point number : ";
        cin >> m_float;
 }

void main()
 {
        FLOAT f1, f2, f3;

        f1.get(); f2.get();

        f3 = f1 + f2; f1.Show(); cout << " + "; f2.Show(); cout << " = "; f3.Show(); cout << '\n';
        f3 = f1 - f2; f1.Show(); cout << " - "; f2.Show(); cout << " = "; f3.Show(); cout << '\n';
        f3 = f1 * f2; f1.Show(); cout << " * "; f2.Show(); cout << " = "; f3.Show(); cout << '\n';
        f3 = f1 / f2; f1.Show(); cout << " / "; f2.Show(); cout << " = "; f3.Show(); cout << '\n';
        getch();
 }