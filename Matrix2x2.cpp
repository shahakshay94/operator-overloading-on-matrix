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
#include <cmath>
#include <sstream>


using namespace std;
static float eps = 1.0e-6;

/**
 * Default destructor
 */
Matrix2x2::~Matrix2x2() = default;

/**
 * Default constructor which sets all values to sero
 */
Matrix2x2::Matrix2x2() : position00(0), position01(0), position10(0), position11(0) {}

/**
 * Normal Constructor which initializes four values passes as parameters
 * @param p00
 * @param p01
 * @param p10
 * @param p11
 */
Matrix2x2::Matrix2x2(double p00, double p01, double p10, double p11) {
    position00 = p00;
    position01 = p01;
    position10 = p10;
    position11 = p11;
}

/**
 * Assignment operator
 * @param rhs
 * @return
 */
Matrix2x2 &Matrix2x2::operator=(const Matrix2x2 &rhs) {
    this->position00 = rhs.position00;
    this->position01 = rhs.position01;
    this->position10 = rhs.position10;
    this->position11 = rhs.position11;

    return *this;
}

/**
 * positive signed
 * @return positive signed append Matrix
 */
Matrix2x2 Matrix2x2::operator+() const {

    double finalNumber1 = +this->position00;
    double finalNumber2 = +this->position01;
    double finalNumber3 = +this->position10;
    double finalNumber4 = +this->position11;
    Matrix2x2 finalMatrix(finalNumber1, finalNumber2, finalNumber3, finalNumber4);
    return finalMatrix;
}

/**
 * Negates the matrix
 * @return negative signed matrix
 */
Matrix2x2 Matrix2x2::operator-() const {
    return Matrix2x2(-this->position00, -this->position01, -this->position10, -this->position11);
}

/**
 * Prefix operator
 * @return Matrix after decrement
 */
Matrix2x2 Matrix2x2::operator--() {
    return *this = *this - 1;
}

/**
 * Prefix operator
 * @return
 */
Matrix2x2 Matrix2x2::operator++() {
    return *this = *this + 1;
}

/**
 * Postfix increment operator
 * @return matrix after incerement
 */
Matrix2x2 Matrix2x2::operator++(int) {
    Matrix2x2 temp = *this;
    *this = *this + 1;
    return temp;
}

/**
 * Prefix decrement operator
 * @return matrix after decrement
 */
Matrix2x2 Matrix2x2::operator--(int) {
    Matrix2x2 temp = *this;
    *this = *this - 1;
    return temp;
}

/**
 * Compund assignment plus operator
 * @param rhs Matrix
 * @return this += rhs
 */
Matrix2x2 &Matrix2x2::operator+=(const Matrix2x2 &rhs) {

    this->position00 += rhs.position00;
    this->position01 += rhs.position01;
    this->position10 += rhs.position10;
    this->position11 += rhs.position11;
    return *this;
}

/**
 * Compound assignment plus operator
 * @param rhs Matrix
 * @return this += x
 */
Matrix2x2 &Matrix2x2::operator+=(const int &inputValue) {

    this->position00 += inputValue;
    this->position01 += inputValue;
    this->position10 += inputValue;
    this->position11 += inputValue;
    return *this;
}

/**
 * Compound assignment subtract operator
 * @param rhs Matrix
 * @return this -= rhs
 */
Matrix2x2 &Matrix2x2::operator-=(const int &inputValue) {

    this->position00 -= inputValue;
    this->position01 -= inputValue;
    this->position10 -= inputValue;
    this->position11 -= inputValue;
    return *this;
}

/**
 * Compound assignment subtract operator
 * @param rhs Matrix
 * @return this -= x
 */
Matrix2x2 &Matrix2x2::operator-=(const Matrix2x2 &rhs) {
    this->position00 -= rhs.position00;
    this->position01 -= rhs.position01;
    this->position10 -= rhs.position10;
    this->position11 -= rhs.position11;
    return *this;
}

/**
 * Compound assignment multiply operator
 * @param inputValue
 * @return this *= inputValue
 */
Matrix2x2 &Matrix2x2::operator*=(const int &inputValue) {
    this->position00 *= inputValue;
    this->position01 *= inputValue;
    this->position10 *= inputValue;
    this->position11 *= inputValue;
    return *this;
}

/**
 * Compound assignment subtract operator
 * @param rhs Matrix
 * @return this *= x
 */
Matrix2x2 &Matrix2x2::operator*=(const Matrix2x2 &rhs) {
    this->position00 = (this->position00 * rhs.position00) + (this->position01 * rhs.position10);
    this->position01 = (this->position00 * rhs.position01) + (this->position01 * rhs.position11);
    this->position10 = (this->position10 * rhs.position00) + (this->position11 * rhs.position10);
    this->position11 = (this->position10 * rhs.position01) + (this->position11 * rhs.position11);
    return *this;
}

/**
 * Compound assignment divide operator
 * @param inputValue a const integer
 * @return this /= inputValue
 */
Matrix2x2 &Matrix2x2::operator/=(const int &inputValue) {
    this->position00 /= inputValue;
    this->position01 /= inputValue;
    this->position10 /= inputValue;
    this->position11 /= inputValue;
    return *this;
}

/**
 * Compound assignment divide operator
 * @param rhs Matrix
 * @return this /= rhs
 */
Matrix2x2 &Matrix2x2::operator/=(const Matrix2x2 &rhs) {
    Matrix2x2 temp = rhs;
    *this = *this * temp.inverse();
    return *this;
}

/**
 * Returns the value as per the position.
 * This is similar to 1-D array, where we get element using index/position
 * @param pos index value
 * @return element at that position in 2-d array
 */
double &Matrix2x2::operator[](const int &pos) {
    switch (pos) {
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

/**
 * Calculate the eigen values of the matrix
 * @param inputValue
 * @return result vector which holds the eigen values
 */
vector<double> Matrix2x2::operator()(const int &inputValue) {
    Matrix2x2 temp = *this;
    double tempTrace = temp.trace();
    double tempDet = temp.determinant();
    vector<double> result;
    double delta = ((tempTrace * tempTrace) - (4 * tempDet));

    if (delta >= 0) {
        double firstValue = ((tempTrace + sqrt(delta)) / 2);
        double secondValue = ((tempTrace - sqrt(delta)) / 2);
        result.push_back(firstValue);
        result.push_back(secondValue);
    }

    if (delta < 0) {
        double firstValue = temp.trace() / 2;
        double secondValue1 = +(sqrt(-delta) / 2);
        double secondValue2 = -(sqrt(-delta) / 2);
        if (inputValue == 1) {
            result.push_back(firstValue);
            result.push_back(secondValue1);
        }
        else {
            result.push_back(firstValue);
            result.push_back(secondValue2);
        }
    }

    return result;
}

/**
 * Determinant
 * @return
 */
double Matrix2x2::operator()() {
    return this->determinant();
}

/**
 * Inverse the matrix
 * @return inversed matrix
 */
Matrix2x2 Matrix2x2::inverse() {
    double k = this->determinant();
    if (k == 0) throw overflow_error("Inversion condition not met.");
    return Matrix2x2(this->position11 * 1 / k, -this->position01 * 1 / k, -this->position10 * 1 / k, this->position00 * 1 / k);

}

/**
 * Transpose the matrix
 * @return transposed matrix
 */
Matrix2x2 Matrix2x2::transpose() {
    if(abs(this->determinant()) <= eps) throw overflow_error("Inverse undefined");
    return  Matrix2x2(this->position00, this->position10, this->position01, this->position11);;
}

/**
 * Calculate the determinant of the matrix
 * @return determinant value
 */
double Matrix2x2::determinant() {
    double result = 0;
    result = (this->position00 * this->position11) - (this->position01 * this->position10);
    return result;
}

/**
 * Checks the symmetricity of the matrix
 * @return true if symmetric
 */
bool Matrix2x2::isSymmetric() {
    return this->position01 == this->position10;
}

/**
 * check the similarity with the input matrix
 * @param inputMatrix
 * @return true if similar with another matrix
 */
bool Matrix2x2::isSimilar(Matrix2x2 inputMatrix) {
    return (this->determinant() == inputMatrix.determinant()) && (this->trace() == inputMatrix.trace());
}

/**
 * Calculate trace value
 * @return trace value
 */
double Matrix2x2::trace() {
    return this->position00 + this->position11;
}

//Binary Operators starts

/**
 * Add two matrices
 * @param lhs
 * @param rhs
 * @return
 */
Matrix2x2 operator+(const Matrix2x2 &lhs, const Matrix2x2 &rhs) {
    return Matrix2x2(lhs.position00 + rhs.position00, lhs.position01 + rhs.position01, lhs.position10 + rhs.position10, lhs.position11 + rhs.position11);
}

/**
 * Add matrix with an integer
 * @param lhs this matrix
 * @param inputValue
 * @return
 */
Matrix2x2 operator+(const Matrix2x2 &lhs, const int &inputValue) {
    return Matrix2x2(lhs.position00 + inputValue, lhs.position01 + inputValue, lhs.position10 + inputValue, lhs.position11 + inputValue);
}

/**
 * Add matrix with an integer
 * @param inputValue
 * @param rhs matrix
 * @return
 */
Matrix2x2 operator+(const int &inputValue, const Matrix2x2 &rhs) {
    return operator+(rhs, inputValue);
}

/**
 * Subtracts two matrices
 * @param lhs
 * @param rhs
 * @return
 */
Matrix2x2 operator-(const Matrix2x2 &lhs, const Matrix2x2 &rhs) {
    return Matrix2x2(lhs.position00 - rhs.position00, lhs.position01 - rhs.position01, lhs.position10 - rhs.position10, lhs.position11 - rhs.position11);
}

/**
 * Subtract the integer from matrix
 * @param lhs
 * @param inputValue
 * @return
 */
Matrix2x2 operator-(const Matrix2x2 &lhs, const int &inputValue) {
    return Matrix2x2(lhs.position00 - inputValue, lhs.position01 - inputValue, lhs.position10 - inputValue, lhs.position11 - inputValue);
}

/**
 * Subtract matrix from integer
 * @param inputValue
 * @param rhs
 * @return
 */
Matrix2x2 operator-(const int &inputValue, const Matrix2x2 &rhs) {
    return Matrix2x2(inputValue - rhs.position00, inputValue - rhs.position01, inputValue - rhs.position10, inputValue - rhs.position11);
}

/**
 * Multiple two matrices
 * @param lhs
 * @param rhs
 * @return
 */
Matrix2x2 operator*(const Matrix2x2 &lhs, const Matrix2x2 &rhs) {
    double p1 = (lhs.position00 * rhs.position00) + (lhs.position01 * rhs.position10);
    double p2 = (lhs.position00 * rhs.position01) + (lhs.position01 * rhs.position11);
    double p3 = (lhs.position10 * rhs.position00) + (lhs.position11 * rhs.position10);
    double p4 = (lhs.position10 * rhs.position01) + (lhs.position11 * rhs.position11);

    Matrix2x2 result(p1, p2, p3, p4);

    return result;
}

/**
 * Multiply a const integer with matrix
 */
Matrix2x2 operator*(const Matrix2x2 &lhs, const double &inputValue) {
    return Matrix2x2(lhs.position00 * inputValue, lhs.position01 * inputValue, lhs.position10 * inputValue, lhs.position11 * inputValue);
}

/**
 * Multiply a const integer with matrix
 */
Matrix2x2 operator*(const double &inputValue, const Matrix2x2 &rhs) {
    return operator*(rhs, inputValue);
}

/**
 * Divide two matrices
 */
Matrix2x2 operator/(const Matrix2x2 &lhs, const int &inputValue) {
    if(abs(inputValue) <= eps) throw overflow_error("Division by zero");
    return Matrix2x2(lhs.position00 / inputValue, lhs.position01 / inputValue, lhs.position10 / inputValue, lhs.position11 / inputValue);
}

/**
 * Divide a const integer with matrix
 */
Matrix2x2 operator/(const int &inputValue, Matrix2x2 &rhs) {
    return operator*(inputValue, rhs.inverse());
}

/**
 * Divide a const integer with matrix
 */
Matrix2x2 operator/(const Matrix2x2 &lhs, const Matrix2x2 &rhs) {
    Matrix2x2 temp = rhs;
    Matrix2x2 resultMatrix = lhs * temp.inverse();
    return resultMatrix;
}

//Binary operator ends

/**
 *
 * @param lhs
 * @param rhs
 * @return
 */
bool operator==(const Matrix2x2 &lhs, const Matrix2x2 &rhs) {
    return lhs.position00 == rhs.position00 && lhs.position01 == rhs.position01 && lhs.position10 == rhs.position10 && lhs.position11 == rhs.position11;
}

/**
 * Output stream customised to print the 2d matrix in specific format.
 */
ostream &operator<<(ostream &outputStream, const Matrix2x2 &rhs) {
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

    if (s4.length() > max1) {
        max1 = static_cast<int>(s4.length() + 3);
    }
    else{
        max1 = static_cast<int>(s3.length() + 3);
    }

    if (s2.length() > max) {
        max = static_cast<int>(s2.length() + 3);
    }
    else{
        max = static_cast<int>(s1.length() + 3);
    }

    cout << "|" << setw(max) << fixed << setprecision(2) << rhs.position00 << " " << setw(max1) << rhs.position01 << "|" << endl;
    cout << "|" << setw(max + max1 + 2) << "|" << endl;
    cout << "|" << setw(max) << fixed << setprecision(2) << rhs.position10 << " " << setw(max1) << rhs.position11 << "|" << endl;
    return outputStream;
}

/**
 * To get the four values for the 2d matrix
 * @param inputStream
 * @param rhs
 * @return
 */
istream &operator>>(istream &inputStream, Matrix2x2 &rhs) {
    cout << "To create te following 2X2 matrix:" << endl;
    cout << "|a   b|" << endl;
    cout << "|     |" << endl;
    cout << "|c   d|" << endl;
    cout << "enter four numbers a,b,c,d in that order:" << endl;

    inputStream >> rhs.position00 >> rhs.position01 >> rhs.position10 >> rhs.position11;
    return inputStream;
}