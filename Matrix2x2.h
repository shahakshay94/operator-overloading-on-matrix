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
    double number1, number2, number3, number4;
public:

    virtual ~Matrix2x2();
    Matrix2x2();
    Matrix2x2(double inNumber1, double inNumber2, double inNumber3, double inNumber4);


    Matrix2x2 inverse();
    Matrix2x2 transpose();
    double determinant();
    double trace();
    bool isSymmetric();
    bool isSimilar(Matrix2x2 inputMatrix);

    //MEMBER FUNCTION OVERLOADING
    Matrix2x2& operator = (const Matrix2x2& rhs);

    Matrix2x2 operator+() const;
    Matrix2x2 operator-() const;

    Matrix2x2 operator--(); // prifix decrement operator - passed WITHOUT dummy argument
    Matrix2x2 operator--(int); //postfix decrement operator - passed WITH dummy argument

    Matrix2x2 operator++(int); //postfix increment operator - passed WITH dummy argument
    Matrix2x2 operator++(); // prifix increment operator - passed WITHOUT dummy argument

    double& operator[](const int &inputValue);

    vector<double> operator()(const int &s); // for finding eigenvalues for the matrix
    double operator() ();


    Matrix2x2& operator+=(const Matrix2x2& rhs);
    Matrix2x2& operator+=(const int& inputValue);
    Matrix2x2& operator-=(const int& inputValue);
    Matrix2x2& operator*=(const int& inputValue);
    Matrix2x2& operator/=(const int& inputValue);

    // Non-member operator overloads

    friend Matrix2x2 operator + (const Matrix2x2& lhs, const Matrix2x2& rhs);
    friend Matrix2x2 operator + (const Matrix2x2& lhs, const int &inputValue);
    friend Matrix2x2 operator + (const int &inputValue, const Matrix2x2& rhs);

    friend Matrix2x2 operator - (const Matrix2x2& lhs, const Matrix2x2& rhs);
    friend Matrix2x2 operator - (const Matrix2x2& lhs, const int &inputValue);
    friend Matrix2x2 operator - (const int &inputValue, const Matrix2x2& rhs);

    friend Matrix2x2 operator / (const Matrix2x2& lhs, const int &inputValue);
    friend Matrix2x2 operator / (const int &inputValue, Matrix2x2& rhs);

    friend Matrix2x2 operator * (const Matrix2x2& lhs, const Matrix2x2& rhs);
    friend Matrix2x2 operator * (const Matrix2x2& lhs, const double &inputValue);
    friend Matrix2x2 operator * (const double &inputValue, const Matrix2x2& rhs);

    friend bool operator == (const Matrix2x2& lhs, const Matrix2x2& rhs);

    friend ostream& operator<<(ostream& ostr, const Matrix2x2& rhs);
    friend istream& operator>>(istream& istr, Matrix2x2& rhs);

}; // end of class

#endif //ASSIGNMENT3_MATRIX2X2_H
