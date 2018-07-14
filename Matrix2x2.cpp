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
#include "Matrix2x2.h"
#include <iomanip>
#include <iostream>
#include <math.h>
#include <sstream>


using namespace std;
static float eps = 1.0e-6;

Matrix2x2::~Matrix2x2() = default;

Matrix2x2::Matrix2x2() : position00(0), position01(0), position10(0), position11(0) {}

Matrix2x2::Matrix2x2(double p00, double p01, double p10, double p11) {
    position00 = p00;
    position01 = p01;
    position10 = p10;
    position11 = p11;
}

Matrix2x2 Matrix2x2::inverse() {
    double k = this->determinant();
    if (k == 0) throw overflow_error("Inversion condition not met.");
    return Matrix2x2(this->position11 * 1 / k, -this->position01 * 1 / k, -this->position10 * 1 / k, this->position00 * 1 / k);

}

Matrix2x2 Matrix2x2::transpose() {
    if(abs(this->determinant()) <= eps) throw overflow_error("Inverse undefined");
    double finalNumber1 = this->position00;
    double finalNumber2 = this->position10;
    double finalNumber3 = this->position01;
    double finalNumber4 = this->position11;

    Matrix2x2 finalMatrix(finalNumber1, finalNumber2, finalNumber3, finalNumber4);

    return finalMatrix;
}

double Matrix2x2::determinant() {
    double result = 0;
    result = (this->position00 * this->position11) - (this->position01 * this->position10);
    return result;
}

bool Matrix2x2::isSymmetric() {
    return this->position01 == this->position10;
}

bool Matrix2x2::isSimilar(Matrix2x2 inputMatrix) {
    return (this->determinant() == inputMatrix.determinant()) && (this->trace() == inputMatrix.trace());
}

ostream &operator<<(ostream &ostr, const Matrix2x2 &rhs) {
    string s = to_string(rhs.position10);
    stringstream ss(s);

    string token;

    while (getline(ss, token, '.')) {
        break;
    }
    string s1 = to_string(int(rhs.position00));
    string s2 = token;
    string s3 = to_string(int(rhs.position01));
    string s4 = to_string(int(rhs.position11));
    int max = static_cast<int>(s1.length());
    int max1 = static_cast<int>(s3.length());
    if (s2.length() > max) {
        max = static_cast<int>(s2.length() + 3);
    } else
        max = static_cast<int>(s1.length() + 3);
    if (s4.length() > max1) {
        max1 = static_cast<int>(s4.length() + 3);
    } else
        max1 = static_cast<int>(s3.length() + 3);

    //cout << max<<endl;
    //cout << max1 << endl;
    cout << "|" << setw(max) << fixed << setprecision(2) << rhs.position00 << " " << setw(max1) << rhs.position01 << "|"
         << endl;
    cout << "|" << setw(max + max1 + 2) << "|" << endl;
    cout << "|" << setw(max) << fixed << setprecision(2) << rhs.position10 << " " << setw(max1) << rhs.position11 << "|"
         << endl;
    return ostr;
}

istream &operator>>(istream &istr, Matrix2x2 &rhs) {
    cout << "To create te following 2X2 matrix:" << endl;
    cout << "|a   b|"<<endl;
    cout << "|     |"<<endl;
    cout << "|c   d|"<<endl;
    cout << "enter four numbers a,b,c,d in that order:" << endl;

    istr >> rhs.position00 >> rhs.position01 >> rhs.position10 >> rhs.position11;
    return istr;
}

bool operator==(const Matrix2x2 &lhs, const Matrix2x2 &rhs) {
    bool checkFirstNumber = lhs.position00 == rhs.position00;
    bool checkSecondNumber = lhs.position01 == rhs.position01;
    bool checkThirdNumber = lhs.position10 == rhs.position10;
    bool checkFourthNumber = lhs.position11 == rhs.position11;

    return checkFirstNumber && checkSecondNumber && checkThirdNumber && checkThirdNumber && checkFourthNumber;

}

double Matrix2x2::trace() {

    double finalResult;

    finalResult = this->position00 + this->position11;

    return finalResult;
}

Matrix2x2 operator*(const Matrix2x2 &lhs, const Matrix2x2 &rhs) {
    double finalNumber1 = (lhs.position00 * rhs.position00) + (lhs.position01 * rhs.position10);
    double finalNumber2 = (lhs.position00 * rhs.position01) + (lhs.position01 * rhs.position11);
    double finalNumber3 = (lhs.position10 * rhs.position00) + (lhs.position11 * rhs.position10);
    double finalNumber4 = (lhs.position10 * rhs.position01) + (lhs.position11 * rhs.position11);

    Matrix2x2 finalMatrix(finalNumber1, finalNumber2, finalNumber3, finalNumber4);

    return finalMatrix;
}

Matrix2x2 operator*(const Matrix2x2 &lhs, const double &inputValue) {
    double finalNumber1 = lhs.position00 * inputValue;
    double finalNumber2 = lhs.position01 * inputValue;
    double finalNumber3 = lhs.position10 * inputValue;
    double finalNumber4 = lhs.position11 * inputValue;

    Matrix2x2 finalMatrix(finalNumber1, finalNumber2, finalNumber3, finalNumber4);

    return finalMatrix;
}

Matrix2x2 operator*(const double &inputValue, const Matrix2x2 &rhs) {
    return operator*(rhs, inputValue);
}

Matrix2x2 operator+(const Matrix2x2 &lhs, const Matrix2x2 &rhs) {
    double finalNumber1 = lhs.position00 + rhs.position00;
    double finalNumber2 = lhs.position01 + rhs.position01;
    double finalNumber3 = lhs.position10 + rhs.position10;
    double finalNumber4 = lhs.position11 + rhs.position11;

    Matrix2x2 finalMatrix(finalNumber1, finalNumber2, finalNumber3, finalNumber4);

    return finalMatrix;
}

Matrix2x2 operator+(const Matrix2x2 &lhs, const int &inputValue) {
    double finalNumber1 = lhs.position00 + inputValue;
    double finalNumber2 = lhs.position01 + inputValue;
    double finalNumber3 = lhs.position10 + inputValue;
    double finalNumber4 = lhs.position11 + inputValue;

    Matrix2x2 finalMatrix(finalNumber1, finalNumber2, finalNumber3, finalNumber4);

    return finalMatrix;
}

Matrix2x2 operator+(const int &inputValue, const Matrix2x2 &rhs) {
    return operator+(rhs, inputValue);
}

Matrix2x2 operator-(const Matrix2x2 &lhs, const Matrix2x2 &rhs) {
    double finalNumber1 = lhs.position00 - rhs.position00;
    double finalNumber2 = lhs.position01 - rhs.position01;
    double finalNumber3 = lhs.position10 - rhs.position10;
    double finalNumber4 = lhs.position11 - rhs.position11;

    Matrix2x2 finalMatrix(finalNumber1, finalNumber2, finalNumber3, finalNumber4);

    return finalMatrix;
}

Matrix2x2 operator-(const Matrix2x2 &lhs, const int &inputValue) {
    double finalNumber1 = lhs.position00 - inputValue;
    double finalNumber2 = lhs.position01 - inputValue;
    double finalNumber3 = lhs.position10 - inputValue;
    double finalNumber4 = lhs.position11 - inputValue;

    Matrix2x2 finalMatrix(finalNumber1, finalNumber2, finalNumber3, finalNumber4);

    return finalMatrix;
}

Matrix2x2 operator-(const int &inputValue, const Matrix2x2 &rhs) {
    double finalNumber1 = inputValue - rhs.position00;
    double finalNumber2 = inputValue - rhs.position01;
    double finalNumber3 = inputValue - rhs.position10;
    double finalNumber4 = inputValue - rhs.position11;

    Matrix2x2 finalMatrix(finalNumber1, finalNumber2, finalNumber3, finalNumber4);

    return finalMatrix;
}

Matrix2x2 operator/(const Matrix2x2 &lhs, const int &inputValue) {
    if(abs(inputValue) <= eps) throw overflow_error("Division by zero");
    double finalNumber1 = lhs.position00 / inputValue;
    double finalNumber2 = lhs.position01 / inputValue;
    double finalNumber3 = lhs.position10 / inputValue;
    double finalNumber4 = lhs.position11 / inputValue;

    Matrix2x2 finalMatrix(finalNumber1, finalNumber2, finalNumber3, finalNumber4);

    return finalMatrix;
}

Matrix2x2 operator/(const int &inputValue, Matrix2x2 &rhs) {
    return operator*(inputValue, rhs.inverse());
}

Matrix2x2 &Matrix2x2::operator=(const Matrix2x2 &rhs) {
    this->position00 = rhs.position00;
    this->position01 = rhs.position01;
    this->position10 = rhs.position10;
    this->position11 = rhs.position11;

    return *this;
}

//postfix increment
Matrix2x2 Matrix2x2::operator++(int) {
    Matrix2x2 temp = *this;
    *this = *this + 1;
    return temp;
}

//prefix increment
Matrix2x2 Matrix2x2::operator++() {
    return *this = *this + 1;
}

//postfix decrement
Matrix2x2 Matrix2x2::operator--(int) {
    Matrix2x2 temp = *this;
    *this = *this - 1;
    return temp;
}

//prefix decrement
Matrix2x2 Matrix2x2::operator--() {
    return *this = *this - 1;
}

Matrix2x2 Matrix2x2::operator-() const {

    double finalNumber1 = -this->position00;
    double finalNumber2 = -this->position01;
    double finalNumber3 = -this->position10;
    double finalNumber4 = -this->position11;

    Matrix2x2 finalMatrix(finalNumber1, finalNumber2, finalNumber3, finalNumber4);

    return finalMatrix;


}

vector<double> Matrix2x2::operator()(const int &inputValue) {
    Matrix2x2 tempMatrix = *this;
    double tempTrace = tempMatrix.trace();
    double tempDet = tempMatrix.determinant();
    vector<double> result;
    double delta = ((tempTrace * tempTrace) - (4 * tempDet));

    if (delta >= 0) {
        double firstValue = ((tempTrace + sqrt(delta)) / 2);
        double secondValue = ((tempTrace - sqrt(delta)) / 2);
        result.push_back(firstValue);
        result.push_back(secondValue);
    }

    if (delta < 0) {
        double firstValue = tempMatrix.trace() / 2;
        double secondValue1 = +(sqrt(-delta) / 2);
        double secondValue2 = -(sqrt(-delta) / 2);
        if (inputValue == 1) {
            result.push_back(firstValue);
            result.push_back(secondValue1);
        } else {
            result.push_back(firstValue);
            result.push_back(secondValue2);
        }
    }

    return result;
}

Matrix2x2 Matrix2x2::operator+() const {

    double finalNumber1 = +this->position00;
    double finalNumber2 = +this->position01;
    double finalNumber3 = +this->position10;
    double finalNumber4 = +this->position11;

    Matrix2x2 finalMatrix(finalNumber1, finalNumber2, finalNumber3, finalNumber4);

    return finalMatrix;


}

double &Matrix2x2::operator[](const int &val) {
    switch (val) {
        case 0:
            return this->position00;
        case 1:
            return this->position01;
        case 2:
            return this->position10;
        case 3:
            return this->position11;
        default:
            throw invalid_argument("index out of bound");
    }
}

double Matrix2x2::operator()() {
    return this->determinant();
}

Matrix2x2 &Matrix2x2::operator+=(const Matrix2x2 &rhs) {

    this->position00 += rhs.position00;
    this->position01 += rhs.position01;
    this->position10 += rhs.position10;
    this->position11 += rhs.position11;
    return *this;
}

Matrix2x2 &Matrix2x2::operator+=(const int &inputValue) {

    this->position00 += inputValue;
    this->position01 += inputValue;
    this->position10 += inputValue;
    this->position11 += inputValue;
    return *this;
}

Matrix2x2 &Matrix2x2::operator-=(const int &inputValue) {

    this->position00 -= inputValue;
    this->position01 -= inputValue;
    this->position10 -= inputValue;
    this->position11 -= inputValue;
    return *this;
}

Matrix2x2 &Matrix2x2::operator*=(const int &inputValue) {
    this->position00 *= inputValue;
    this->position01 *= inputValue;
    this->position10 *= inputValue;
    this->position11 *= inputValue;
    return *this;
}

Matrix2x2 &Matrix2x2::operator/=(const int &inputValue) {
    this->position00 /= inputValue;
    this->position01 /= inputValue;
    this->position10 /= inputValue;
    this->position11 /= inputValue;
    return *this;
}

Matrix2x2 &Matrix2x2::operator-=(const Matrix2x2 &rhs) {
    this->position00 -= rhs.position00;
    this->position01 -= rhs.position01;
    this->position10 -= rhs.position10;
    this->position11 -= rhs.position11;
    return *this;
}

Matrix2x2 &Matrix2x2::operator*=(const Matrix2x2 &rhs) {
    this->position00 = (this->position00 * rhs.position00) + (this->position01 * rhs.position10);
    this->position01= (this->position00 * rhs.position01) + (this->position01 * rhs.position11);
    this->position10 = (this->position10 * rhs.position00) + (this->position11 * rhs.position10);
    this->position11 = (this->position10 * rhs.position01) + (this->position11 * rhs.position11);
    return *this;
}

Matrix2x2 &Matrix2x2::operator/=(const Matrix2x2 &rhs) {
    Matrix2x2 temp = rhs;
    *this = *this * temp.inverse();
    return *this;
}

Matrix2x2 operator/(const Matrix2x2 &lhs, const Matrix2x2 &rhs) {
    Matrix2x2 temp = rhs;
    Matrix2x2 resultMatrix = lhs * temp.inverse();
    return resultMatrix;
}
