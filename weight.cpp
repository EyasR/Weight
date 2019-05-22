//University of Washington Bothell - CSSE
// CSS342C : Proffesor Munehiro Fukuda
// Created by Eyas Rashid on 1/10/2019
//
// Purpose: this program overloads Math, Comparison, Assignment
// Steam I/O operators to work with weight objects (lbs , oz).

#include <iostream>
#include "weight.h"

using namespace std;

// constructor
weight::weight() {
    w_ounces = 0;
}

// constructor
weight::weight(int pounds) {
    w_ounces = netWeight(pounds, 0);
}

// constructor
weight::weight(int pounds, int ounces) {
    w_ounces = netWeight(pounds, ounces);
}

// converts (pound , ounces) into (ounces)
int weight::netWeight(int pounds, int ounces) {
    return (pounds * 16) + ounces;
}

// gets  pound value of object
int weight::getPounds() {
    return w_ounces / 16;
}

// gets ounce value of object
int weight::getOunces() {
    return w_ounces % 16;
}

// converts net weight back to pounds and ounces
weight weight::netWeight_backToLbsOz(int ounces) const {
    int lbs = ounces / 16;
    int oz = ounces % 16;

    weight modWeight(lbs, oz);
    return modWeight;
}

// operator over load for output stream
ostream &operator<<(ostream &output, weight w) {
    if (w.getPounds() == 0) {
        output << w.getOunces() << " Oz";
    } else if (w.getOunces() == 0) {
        output << w.getPounds() << " lbs";
    } else {
        output << w.getPounds() << " lbs " << w.getOunces() << " Oz";
    }
    return output;
}

// operator overload for input stream
istream &operator>>(istream &input, weight &w) {
    int pounds = 0;
    int ounces = 0;
    input >> pounds;
    input >> ounces;
    w.w_ounces = (pounds * 16) + ounces;

    return input;
}

// operator overload for +
weight weight::operator+(const weight &w) {
    int weight1 = w.w_ounces;
    int weight2 = this->w_ounces;
    return netWeight_backToLbsOz(weight1 + weight2);
}

// operator overload for -
weight weight::operator-(const weight &w) {
    int weight1 = this->w_ounces;
    int weight2 = w.w_ounces;
    return netWeight_backToLbsOz(weight1 - weight2);
}

// operator overload for *
weight weight::operator*(const double &w) const {
    int ounces = this->w_ounces;
    ounces *= w;
    return netWeight_backToLbsOz(ounces);
}

// operator overload for / (object / object)
double weight::operator/(const weight &w) const {
    double left_Operand = this->w_ounces;
    double right_Operand = w.w_ounces;
    if (right_Operand == 0) {
        cout << "Error, you cannot divide by zero." << endl;
    }

    return left_Operand / right_Operand;
}

// operator overload for / (object / double)
weight weight::operator/(const double &w) const {
    int ounces = this->w_ounces;
    if (w == 0) {
        cout << "Error, you cannot divide by zero." << endl;
    }
    ounces /= w;
    return netWeight_backToLbsOz(ounces);
}

// operator overload for unary negation (converts object (lb,oz) to negative values)
weight weight::operator-() const {
    return netWeight_backToLbsOz(-w_ounces);
}

// operator overload for ==
bool weight::operator==(const weight &w) const {
    return this->w_ounces == w.w_ounces;
}

// operator overload for !=
bool weight::operator!=(const weight &w) const {
    return this->w_ounces != w.w_ounces;
}

// operator overload for >
bool weight::operator>(const weight &w) const {
    return this->w_ounces > w.w_ounces;
}

// operator overload for <
bool weight::operator<(const weight &w) const {
    return this->w_ounces < w.w_ounces;
}

// operator overload for >=
bool weight::operator>=(const weight &w) const {
    return this->w_ounces >= w.w_ounces;
}

// operator overload for <=
bool weight::operator<=(const weight &w) const {
    return this->w_ounces <= w.w_ounces;
}

// operator overload for +=
weight &weight::operator+=(const weight &w) {
    w_ounces += w.w_ounces;
    return *this;
}

// operator overload for -=
weight &weight::operator-=(const weight &w) {
    w_ounces -= w.w_ounces;
    return *this;
}

// operator overload for *=
weight &weight::operator*=(const double &w) {
    int ounces = this->w_ounces;
    ounces *= w;
    *this = netWeight_backToLbsOz(ounces);
    return *this;
}

// operator overload for /=
weight &weight::operator/=(const double &w) {
    double ounces = this->w_ounces;
    ounces /= w;
    *this = netWeight_backToLbsOz(ounces);
    return *this;
}

