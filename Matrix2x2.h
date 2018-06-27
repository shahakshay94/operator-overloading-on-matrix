//
// Created by akshay on 26/06/18.
//

#ifndef ASSIGNMENT3_MATRIX2X2_H
#define ASSIGNMENT3_MATRIX2X2_H

#include <string>
#include <vector>

using namespace std;
class Matrix2x2 {
private:
    double p1,p2,p3,p4;
public:
    virtual ~Matrix2x2();

    Matrix2x2();

    Matrix2x2(double i1, double i2, double i3, double i4);

    Matrix2x2(const Matrix2x2 &);

    Matrix2x2 inverse();

    bool isSymmetric();

    bool isSimilar(Matrix2x2 x2);

    double determinant();

    double trace();


    // Member operator overloads
    Matrix2x2& operator=(const int& val);
    Matrix2x2& operator+=(const int& val);
    Matrix2x2& operator-=(const int& val);
    Matrix2x2& operator*=(const int& val);
    Matrix2x2& operator/=(const int& val);

    Matrix2x2& operator=(const Matrix2x2& rhs);
    Matrix2x2& operator+=(const Matrix2x2& rhs);
    Matrix2x2& operator-=(const Matrix2x2& rhs);
    Matrix2x2& operator*=(const Matrix2x2& rhs);
    Matrix2x2& operator/=(const Matrix2x2& rhs);

    Matrix2x2& operator++();
    Matrix2x2& operator--(); 

    vector<double> operator()(const int &s); // returns the deter version of this Matrix2x2
    double operator()(); // returns the deter version of this Matrix2x2

    //read and write operation for positions in matrix2x2
    double& operator[](const int &s);
    const double& operator[](const int &s) const;

    // The following operators are usually overloaded as members
    Matrix2x2 operator+() const;
    Matrix2x2 operator-() const;

    Matrix2x2 operator++(int);
    Matrix2x2 operator--(int);


    // Non-member operator overloads
    friend Matrix2x2 operator+(const Matrix2x2& lhs, const Matrix2x2& rhs);
    friend Matrix2x2 operator+(const Matrix2x2& lhs, const int& val);
    friend Matrix2x2 operator+(const int& val, const Matrix2x2& rhs);

    friend Matrix2x2 operator-(const Matrix2x2& lhs, const Matrix2x2& rhs);
    friend Matrix2x2 operator-(const Matrix2x2& lhs, const int& val);
    friend Matrix2x2 operator-(const int& val, const Matrix2x2& rhs);

    friend Matrix2x2 operator*(const Matrix2x2& lhs, const Matrix2x2& rhs);
    friend Matrix2x2 operator*(const Matrix2x2& lhs, const int& val);
    friend Matrix2x2 operator*(const int& val, const Matrix2x2& rhs);

    friend Matrix2x2 operator/(const Matrix2x2& lhs, const Matrix2x2& rhs);
    friend Matrix2x2 operator/(const Matrix2x2& lhs, const int& val);
    friend Matrix2x2 operator/(const int& val, const Matrix2x2& rhs);

    friend bool operator==(const Matrix2x2& lhs, const Matrix2x2& rhs);
    friend bool operator==(const Matrix2x2& lhs, const int& val);
    friend bool operator==(const int& val, const Matrix2x2& rhs);

    friend bool operator!=(const Matrix2x2& lhs, const Matrix2x2& rhs);
    friend bool operator!=(const Matrix2x2& lhs, const int& val);
    friend bool operator!=(const int& val, const Matrix2x2& rhs);

    friend bool operator<(const Matrix2x2& lhs, const Matrix2x2& rhs);
    friend bool operator<(const Matrix2x2& lhs, const int& val);
    friend bool operator<(const int& val, const Matrix2x2& rhs);

    friend bool operator<=(const Matrix2x2& lhs, const Matrix2x2& rhs);
    friend bool operator<=(const Matrix2x2& lhs, const int& val);
    friend bool operator<=(const int& val, const Matrix2x2& rhs);

    friend bool operator>(const Matrix2x2& lhs, const Matrix2x2& rhs);
    friend bool operator>(const Matrix2x2& lhs, const int& val);
    friend bool operator>(const int& val, const Matrix2x2& rhs);

    friend bool operator>=(const Matrix2x2& lhs, const Matrix2x2& rhs);
    friend bool operator>=(const Matrix2x2& lhs, const int& val);
    friend bool operator>=(const int& val, const Matrix2x2& rhs);

    friend istream& operator>>(std::istream& istr, Matrix2x2& rhs);
    friend ostream& operator<<(std::ostream& ostr, const Matrix2x2& rhs);

}; // end of class



#endif //ASSIGNMENT3_MATRIX2X2_H
