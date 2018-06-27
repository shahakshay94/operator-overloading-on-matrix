//
// Created by akshay on 26/06/18.
//

#include "Matrix2x2.h"
#include <iomanip>
#include <iostream>

using namespace std;

Matrix2x2::Matrix2x2(double i1, double i2, double i3, double i4) {
    p1 = i1;
    p2 = i2;
    p3 = i3;
    p4 = i4;
}

Matrix2x2 Matrix2x2::inverse() {
    double k = this->determinant();
    if( k == 0) throw overflow_error("Inversion condition not met.");
    return Matrix2x2(this->p4*1/k,-this->p2*1/k,-this->p3*1/k, this->p1*1/k);
}

bool Matrix2x2::isSymmetric() {
    return false;
}

bool Matrix2x2::isSimilar(Matrix2x2 x2) {
    return false;
}

double Matrix2x2::determinant() {
    return ((this->p1*this->p4) - (this->p2*this->p3));
}

double Matrix2x2::trace() {
    return (this->p1 + this->p4);
}

/*Matrix2x2 &Matrix2x2::operator=(const int &val) {
    return <#initializer#>;
}

Matrix2x2 &Matrix2x2::operator+=(const int &val) {
    return <#initializer#>;
}

Matrix2x2 &Matrix2x2::operator-=(const int &val) {
    return <#initializer#>;
}

Matrix2x2 &Matrix2x2::operator*=(const int &val) {
    return <#initializer#>;
}

Matrix2x2 &Matrix2x2::operator/=(const int &val) {
    return <#initializer#>;
}

Matrix2x2 &Matrix2x2::operator=(const Matrix2x2 &rhs) {
    return <#initializer#>;
}

Matrix2x2 &Matrix2x2::operator+=(const Matrix2x2 &rhs) {
    return <#initializer#>;
}

Matrix2x2 &Matrix2x2::operator-=(const Matrix2x2 &rhs) {
    return <#initializer#>;
}

Matrix2x2 &Matrix2x2::operator*=(const Matrix2x2 &rhs) {
    return <#initializer#>;
}

Matrix2x2 &Matrix2x2::operator/=(const Matrix2x2 &rhs) {
    return <#initializer#>;
}

Matrix2x2 &Matrix2x2::operator++() {
    return <#initializer#>;
}

Matrix2x2 &Matrix2x2::operator--() {
    return <#initializer#>;
}

vector<double> Matrix2x2::operator()(const int &s) {
    return vector<double>();
}

double Matrix2x2::operator()() {
    return 0;
}

double &Matrix2x2::operator[](const int &s) {
    return <#initializer#>;
}

const double &Matrix2x2::operator[](const int &s) const {
    return <#initializer#>;
}*/

Matrix2x2 Matrix2x2::operator+() const {
    return * this;
}

Matrix2x2 Matrix2x2::operator-() const {
    return Matrix2x2(-this->p1,-this->p2,-this->p3,-this->p4);
}

Matrix2x2 Matrix2x2::operator++(int) {
    return Matrix2x2();
}

Matrix2x2 Matrix2x2::operator--(int) {
    return Matrix2x2();
}

Matrix2x2 operator+(const Matrix2x2 &lhs, const Matrix2x2 &rhs) {
    return Matrix2x2();
}

Matrix2x2 operator+(const Matrix2x2 &lhs, const int &val) {
    return Matrix2x2(lhs.p1+val,lhs.p2+val,lhs.p3+val,lhs.p4+val);
}

Matrix2x2 operator+(const int &val, const Matrix2x2 &rhs) {
    return operator+(rhs,val);
}

Matrix2x2 operator-(const Matrix2x2 &lhs, const Matrix2x2 &rhs) {
    return Matrix2x2();
}

Matrix2x2 operator-(const Matrix2x2 &lhs, const int &val) {
    return Matrix2x2(lhs.p1-val,lhs.p2-val,lhs.p3-val,lhs.p4-val);
}

Matrix2x2 operator-(const int &val, const Matrix2x2 &rhs) {
    return operator+(-rhs,val);
}

Matrix2x2 operator*(const Matrix2x2 &lhs, const Matrix2x2 &rhs) {
    double p1_new = lhs.p1*rhs.p1 + lhs.p2*rhs.p3;
    double p2_new = lhs.p1*rhs.p2 + lhs.p2*rhs.p4;
    double p3_new = lhs.p3*rhs.p1 + lhs.p4*rhs.p3;
    double p4_new = lhs.p3*rhs.p2 + lhs.p4*rhs.p4;
    return Matrix2x2(p1_new,p2_new,p3_new,p4_new);
}

Matrix2x2 operator*(const Matrix2x2 &lhs, const int &val) {
    return Matrix2x2();
}

Matrix2x2 operator*(const int &val, const Matrix2x2 &rhs) {
    return Matrix2x2();
}

Matrix2x2 operator/(const Matrix2x2 &lhs, const Matrix2x2 &rhs) {
    return Matrix2x2();
}

Matrix2x2 operator/(const Matrix2x2 &lhs, const int &val) {
    return Matrix2x2();
}

Matrix2x2 operator/(const int &val, const Matrix2x2 &rhs) {
    return Matrix2x2();
}

bool operator==(const Matrix2x2 &lhs, const Matrix2x2 &rhs) {
   return (lhs.p1 == rhs.p1) && (lhs.p2 == rhs.p2) && (lhs.p3 == rhs.p3) && (lhs.p4 == rhs.p4);
}

bool operator==(const Matrix2x2 &lhs, const int &val) {
    return false;
}

bool operator==(const int &val, const Matrix2x2 &rhs) {
    return false;
}

bool operator!=(const Matrix2x2 &lhs, const Matrix2x2 &rhs) {
    return false;
}

bool operator!=(const Matrix2x2 &lhs, const int &val) {
    return false;
}

bool operator!=(const int &val, const Matrix2x2 &rhs) {
    return false;
}

bool operator<(const Matrix2x2 &lhs, const Matrix2x2 &rhs) {
    return false;
}

bool operator<(const Matrix2x2 &lhs, const int &val) {
    return false;
}

bool operator<(const int &val, const Matrix2x2 &rhs) {
    return false;
}

bool operator<=(const Matrix2x2 &lhs, const Matrix2x2 &rhs) {
    return false;
}

bool operator<=(const Matrix2x2 &lhs, const int &val) {
    return false;
}

bool operator<=(const int &val, const Matrix2x2 &rhs) {
    return false;
}

bool operator>(const Matrix2x2 &lhs, const Matrix2x2 &rhs) {
    return false;
}

bool operator>(const Matrix2x2 &lhs, const int &val) {
    return false;
}

bool operator>(const int &val, const Matrix2x2 &rhs) {
    return false;
}

bool operator>=(const Matrix2x2 &lhs, const Matrix2x2 &rhs) {
    return false;
}

bool operator>=(const Matrix2x2 &lhs, const int &val) {
    return false;
}

bool operator>=(const int &val, const Matrix2x2 &rhs) {
    return false;
}

/*istream &operator>>(std::istream &istr, Matrix2x2 &rhs) {
    return <#initializer#>;
}*/

ostream &operator<<(std::ostream &ostr, const Matrix2x2 &rhs) {
    cout << "|" << rhs.p1 << setw(5) << rhs.p2 << "|" << endl;
    cout << "|" << setw(7) << "|"<<endl;
    cout << "|" << rhs.p3 << setw(5) << rhs.p4 << "|" << endl;
    return ostr;
}

Matrix2x2::~Matrix2x2() = default;

Matrix2x2::Matrix2x2():p1(0),p2(0),p3(0),p4(0){}

Matrix2x2 &Matrix2x2::operator=(const Matrix2x2 &rhs) {
    this->p1=rhs.p1;
    this->p2=rhs.p2;
    this->p3=rhs.p3;
    this->p4=rhs.p4;
    return *this;
}

Matrix2x2::Matrix2x2(const Matrix2x2 &rhs) {
    this->p1=rhs.p1;
    this->p2=rhs.p2;
    this->p3=rhs.p3;
    this->p4=rhs.p4;
};
