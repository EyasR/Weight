//University of Washington Bothell - CSSE
// CSS342C : Proffesor Munehiro Fukuda
// Created by Eyas Rashid on 1/10/2019
//
// Purpose: this program overloads Math, Comparison, Assignment
// Steam I/O operators to work with weight objects (lbs , oz).

#ifndef LAB1_EYASRASHID_WEIGHT_H
#define LAB1_EYASRASHID_WEIGHT_H
#include <iostream>
using namespace std;

class weight {

    // input/output operators overload
    friend ostream &operator << (ostream &output, weight w);
    friend istream &operator >> (istream &input, weight &w);

private:

    int w_ounces;
    // converts (pound , ounces) into (ounces)
    int netWeight(int pounds, int ounces);
    // converts (ounces) back to (pound , ounces)
    weight netWeight_backToLbsOz(int ounces) const;

public:
    // constructors
    weight();
    weight(int pounds);
    weight(int pounds, int ounces);

   // member functions
   int getPounds();
   int getOunces();

   // math operators overload
   weight operator+( const weight& );
   weight operator-( const weight& );
   weight operator*( const double& ) const;
   double operator/( const weight& ) const;
   weight operator/( const double& ) const;
   weight operator-( ) const;

   // assignment operators overload
   bool operator==( const weight& ) const;
   bool operator!=( const weight& ) const;
   bool operator>( const weight& ) const;
   bool operator<( const weight& ) const;
   bool operator>=( const weight& ) const;
   bool operator<=( const weight& ) const;

   // comparison operators overload
   weight& operator+=( const weight& );
   weight& operator-=( const weight& );
   weight& operator*=( const double& );
   weight& operator/=( const double& );
};


#endif //LAB1_EYASRASHID_WEIGHT_H
