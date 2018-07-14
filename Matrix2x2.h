/**
 * @author Akshay Shah
 * @date 14 July 2018
 * Assignment 3 of COMP 5421 Summer '18
 * @class Matrix2x2
 * This class contains some member functions as well as non-member functions.
 * All binary operators are non-member functions
 * All unary, compound assignments operators are member functions
 *
 */

#ifndef ASSIGNMENT3_MATRIX2X2_H
#define ASSIGNMENT3_MATRIX2X2_H

#include <string>
#include <vector>

using namespace std;

class Matrix2x2 {
private:
    double position00, position01, position10, position11; // values represented as positions in 2D Matrix
public:

    //Default destructor
    virtual ~Matrix2x2();

    //Default constructor which sets all four entries to zero.
    Matrix2x2();

    //Normal Constructor which accepts initial values for all four entries as parameters
    Matrix2x2(double p00, double p01, double p10, double p11);

    //MEMBER FUNCTION OVERLOADING
    Matrix2x2 &operator=(const Matrix2x2 &rhs); // default assigment operator

    Matrix2x2 operator+() const; // +M
    Matrix2x2 operator-() const; //-M

    Matrix2x2 operator--(); // prefix decrement operator, --M
    Matrix2x2 operator++(); // prefix increment operator, ++M

    Matrix2x2 operator--(int); //returns this Matrix before decrement, basically postfix operator, M--
    Matrix2x2 operator++(int); //returns this Fraction before increment, basically postfix operator, M++


    Matrix2x2 &operator+=(const Matrix2x2 &rhs); // M += M'
    Matrix2x2 &operator+=(const int &inputValue); // M += x

    Matrix2x2 &operator-=(const Matrix2x2 &rhs);// M -= M'
    Matrix2x2 &operator-=(const int &inputValue);// M -= x

    Matrix2x2 &operator*=(const Matrix2x2 &rhs);// M *= M'
    Matrix2x2 &operator*=(const int &inputValue);// M *= x

    Matrix2x2 &operator/=(const Matrix2x2 &rhs);// M /= M'
    Matrix2x2 &operator/=(const int &inputValue);// M /= x

    // throws out_of_bound exception
    double &operator[](const int &inputValue); // to get particular position for 2d Matrix. Just like in 1-D array

    vector<double> operator()(const int &s); // for finding eigenvalues for the matrix
    double operator()(); // same as determinant method

    Matrix2x2 inverse(); // inverse the matrix
    Matrix2x2 transpose(); // transpose the matrix

    double determinant(); // returns the determinant value of the matrix
    double trace(); // returns p00 + p11

    bool isSymmetric(); // find matrix is symmetric or not by checking p01 == p10
    bool isSimilar(Matrix2x2 inputMatrix); // find the similarity of the matrix to other matrix passed.

    // Non-member operator overloads

    friend Matrix2x2 operator+(const Matrix2x2 &lhs, const Matrix2x2 &rhs); // M + M'
    friend Matrix2x2 operator+(const Matrix2x2 &lhs, const int &inputValue); // M + x
    friend Matrix2x2 operator+(const int &inputValue, const Matrix2x2 &rhs); // x + M

    friend Matrix2x2 operator-(const Matrix2x2 &lhs, const Matrix2x2 &rhs); // M - M'
    friend Matrix2x2 operator-(const Matrix2x2 &lhs, const int &inputValue); // M - x
    friend Matrix2x2 operator-(const int &inputValue, const Matrix2x2 &rhs); // x- M

    friend Matrix2x2 operator/(const Matrix2x2 &lhs, const Matrix2x2 &rhs); // M / M'
    friend Matrix2x2 operator/(const Matrix2x2 &lhs, const int &inputValue); // M / x
    friend Matrix2x2 operator/(const int &inputValue, Matrix2x2 &rhs); // x / M

    friend Matrix2x2 operator*(const Matrix2x2 &lhs, const Matrix2x2 &rhs); // M * M'
    friend Matrix2x2 operator*(const Matrix2x2 &lhs, const double &inputValue); // M * x
    friend Matrix2x2 operator*(const double &inputValue, const Matrix2x2 &rhs); // x * M

    friend bool operator==(const Matrix2x2 &lhs, const Matrix2x2 &rhs); // if M == M

    friend ostream &operator<<(ostream &ostr, const Matrix2x2 &rhs); // output stream to print Matrix in certain format
    friend istream &operator>>(istream &istr, Matrix2x2 &rhs); // to get the input values from user for Marix

}; // end of class

#endif //ASSIGNMENT3_MATRIX2X2_H
