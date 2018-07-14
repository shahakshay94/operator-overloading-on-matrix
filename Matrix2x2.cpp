//
// Created by akshay on 26/06/18.
//

#include "Matrix2x2.h"
#include <iomanip>
#include <iostream>
#include <math.h>       /* sqrt */
#include <sstream>

using namespace std;

Matrix2x2::~Matrix2x2() = default;

Matrix2x2::Matrix2x2() :number1(0), number2(0), number3(0), number4(0){}

Matrix2x2::Matrix2x2(double inNumber1, double inNumber2, double inNumber3, double inNumber4) {
    number1 = inNumber1;
    number2 = inNumber2;
    number3 = inNumber3;
    number4 = inNumber4;
}

Matrix2x2 Matrix2x2::inverse() {
    double k = this->determinant();
    if( k == 0) throw overflow_error("Inversion condition not met.");
    return Matrix2x2(this->number4*1/k,-this->number2*1/k,-this->number3*1/k, this->number1*1/k);

}

Matrix2x2 Matrix2x2::transpose(){
    double finalNumber1 = this->number1;
    double finalNumber2 = this->number3;
    double finalNumber3 = this->number2;
    double finalNumber4 = this->number4;

    Matrix2x2 finalMatrix(finalNumber1, finalNumber2, finalNumber3, finalNumber4);

    return finalMatrix;
}

double Matrix2x2::determinant() {
    double result = 0;
    result = (this->number1 * this->number4) - (this->number2 * this->number3);
    return result;
}

bool Matrix2x2::isSymmetric(){
    return this->number2 == this->number3;
}

bool Matrix2x2::isSimilar(Matrix2x2 inputMatrix){
    return (this->determinant() == inputMatrix.determinant()) && (this->trace() == inputMatrix.trace());
}

ostream &operator<<(ostream &ostr, const Matrix2x2 &rhs) {
    //cout << to_string(rhs.values[1][0]);
    string s = to_string(rhs.number3);
    stringstream ss(s);

    string token;

    while (getline(ss, token, '.'))
    {
        //cout << "token: " <<token << endl;
        break;
    }
    string s1 = to_string(int(rhs.number1));
    //string s2 = to_string(int(rhs.values[1][0]));
    string s2 = token;
    string s3 = to_string(int(rhs.number2));
    string s4 = to_string(int(rhs.number4));
    int max = static_cast<int>(s1.length());
    int max1 = static_cast<int>(s3.length());
    if (s2.length() > max) {
        max = static_cast<int>(s2.length() + 3);
    }
    else
        max = static_cast<int>(s1.length() + 3);
    if (s4.length() > max1) {
        max1 = static_cast<int>(s4.length() + 3);
    }
    else
        max1 = static_cast<int>(s3.length() + 3);

    //cout << max<<endl;
    //cout << max1 << endl;
    cout << "|" <<setw(max)<<fixed<< setprecision(2)<<rhs.number1 << " " <<setw(max1)<< rhs.number2<<"|"<<endl;
    cout <<"|"<< setw(max + max1+2)<<"|"<<endl;
    cout << "|" << setw(max) << fixed<< setprecision(2)<< rhs.number3 << " " << setw(max1) << rhs.number4<<"|" << endl;
    return ostr;
}
istream &operator>>(istream &istr, Matrix2x2 &rhs) {
    istr >> rhs.number1 >> rhs.number2 >> rhs.number3 >> rhs.number4;
    return istr;
}

bool operator == (const Matrix2x2& lhs, const Matrix2x2& rhs){
    bool checkFirstNumber = lhs.number1 == rhs.number1;
    bool checkSecondNumber = lhs.number2 == rhs.number2;
    bool checkThirdNumber = lhs.number3 == rhs.number3;
    bool checkFourthNumber = lhs.number4 == rhs.number4;

    return checkFirstNumber && checkSecondNumber && checkThirdNumber && checkThirdNumber && checkFourthNumber;

}

double Matrix2x2::trace(){

    double finalResult;

    finalResult = this->number1 + this->number4;

    return finalResult;
}

Matrix2x2 operator * (const Matrix2x2& lhs, const Matrix2x2& rhs){
    double finalNumber1 = (lhs.number1 * rhs.number1) + (lhs.number2 * rhs.number3);
    double finalNumber2 = (lhs.number1 * rhs.number2) + (lhs.number2 * rhs.number4);
    double finalNumber3 = (lhs.number3 * rhs.number1) + (lhs.number4 * rhs.number3);
    double finalNumber4 = (lhs.number3 * rhs.number2) + (lhs.number4 * rhs.number4);

    Matrix2x2 finalMatrix(finalNumber1, finalNumber2, finalNumber3, finalNumber4);

    return finalMatrix;
}

Matrix2x2 operator * (const Matrix2x2 &lhs, const double &inputValue){
    double finalNumber1 = lhs.number1 * inputValue;
    double finalNumber2 = lhs.number2 * inputValue;
    double finalNumber3 = lhs.number3 * inputValue;
    double finalNumber4 = lhs.number4 * inputValue;

    Matrix2x2 finalMatrix(finalNumber1, finalNumber2, finalNumber3, finalNumber4);

    return finalMatrix;
}

Matrix2x2 operator * (const double &inputValue, const Matrix2x2 &rhs){
    return operator*(rhs,inputValue);
}

Matrix2x2 operator + (const Matrix2x2 &lhs, const Matrix2x2 & rhs){
    double finalNumber1 = lhs.number1 + rhs.number1;
    double finalNumber2 = lhs.number2 + rhs.number2;
    double finalNumber3 = lhs.number3 + rhs.number3;
    double finalNumber4 = lhs.number4 + rhs.number4;

    Matrix2x2 finalMatrix(finalNumber1, finalNumber2, finalNumber3, finalNumber4);

    return finalMatrix;
}
Matrix2x2 operator + (const Matrix2x2 &lhs, const int &inputValue){
    double finalNumber1 = lhs.number1 + inputValue;
    double finalNumber2 = lhs.number2 + inputValue;
    double finalNumber3 = lhs.number3 + inputValue;
    double finalNumber4 = lhs.number4 + inputValue;

    Matrix2x2 finalMatrix(finalNumber1, finalNumber2, finalNumber3, finalNumber4);

    return finalMatrix;
}

Matrix2x2 operator + (const int &inputValue, const Matrix2x2 &rhs){
    return operator+ (rhs, inputValue);
}

Matrix2x2 operator - (const Matrix2x2 &lhs, const Matrix2x2 & rhs){
    double finalNumber1 = lhs.number1 - rhs.number1;
    double finalNumber2 = lhs.number2 - rhs.number2;
    double finalNumber3 = lhs.number3 - rhs.number3;
    double finalNumber4 = lhs.number4 - rhs.number4;

    Matrix2x2 finalMatrix(finalNumber1, finalNumber2, finalNumber3, finalNumber4);

    return finalMatrix;
}

Matrix2x2 operator - (const Matrix2x2 &lhs, const int &inputValue){
    double finalNumber1 = lhs.number1 - inputValue;
    double finalNumber2 = lhs.number2 - inputValue;
    double finalNumber3 = lhs.number3 - inputValue;
    double finalNumber4 = lhs.number4 - inputValue;

    Matrix2x2 finalMatrix(finalNumber1, finalNumber2, finalNumber3, finalNumber4);

    return finalMatrix;
}

Matrix2x2 operator - (const int &inputValue, const Matrix2x2 &rhs){
    double finalNumber1 = inputValue - rhs.number1;
    double finalNumber2 = inputValue - rhs.number2;
    double finalNumber3 = inputValue - rhs.number3;
    double finalNumber4 = inputValue - rhs.number4;

    Matrix2x2 finalMatrix(finalNumber1, finalNumber2, finalNumber3, finalNumber4);

    return finalMatrix;
}

Matrix2x2 operator / (const Matrix2x2 &lhs, const int &inputValue){
    double finalNumber1 = lhs.number1 / inputValue;
    double finalNumber2 = lhs.number2 / inputValue;
    double finalNumber3 = lhs.number3 / inputValue;
    double finalNumber4 = lhs.number4 / inputValue;

    Matrix2x2 finalMatrix(finalNumber1, finalNumber2, finalNumber3, finalNumber4);

    return finalMatrix;
}

Matrix2x2 operator / (const int &inputValue, Matrix2x2 &rhs){
    return operator * (inputValue, rhs.inverse());
}

Matrix2x2& Matrix2x2:: operator=(const Matrix2x2 &rhs){
    this->number1 = rhs.number1;
    this->number2 = rhs.number2;
    this->number3 = rhs.number3;
    this->number4 = rhs.number4;

    return *this;
}

//postfix increment
Matrix2x2 Matrix2x2::operator++(int){
    Matrix2x2 temp = *this;
    *this = *this + 1;
    return temp;
}

//prefix increment
Matrix2x2 Matrix2x2::operator++(){
    return *this = *this + 1;
}

//postfix decrement
Matrix2x2 Matrix2x2::operator--(int){
    Matrix2x2 temp = *this;
    *this = *this - 1;
    return temp;
}

//prefix decrement
Matrix2x2 Matrix2x2::operator--(){
    return *this = *this - 1;
}

Matrix2x2 Matrix2x2::operator-()const{

    double finalNumber1 = -this->number1;
    double finalNumber2 = -this->number2;
    double finalNumber3 = -this->number3;
    double finalNumber4 = -this->number4;

    Matrix2x2 finalMatrix(finalNumber1, finalNumber2, finalNumber3, finalNumber4);

    return finalMatrix;


}
vector<double> Matrix2x2::operator()(const int &inputValue) {
    Matrix2x2 tempMatrix = *this;
    double tempTrace = tempMatrix.trace();
    double tempDet = tempMatrix.determinant();
    vector<double> result;
    double delta = ((tempTrace * tempTrace) - (4 * tempDet));

    if (delta >= 0)
    {
        double firstValue = ((tempTrace + sqrt(delta)) / 2);
        double secondValue = ((tempTrace - sqrt(delta)) / 2);
        result.push_back(firstValue);
        result.push_back(secondValue);
    }

    if (delta < 0)
    {
        double firstValue = tempMatrix.trace() / 2;
        double secondValue1 = +(sqrt(-delta) / 2);
        double secondValue2 = -(sqrt(-delta) / 2);
        if (inputValue == 1)
        {
            result.push_back(firstValue);
            result.push_back(secondValue1);
        }
        else
        {
            result.push_back(firstValue);
            result.push_back(secondValue2);
        }
    }

    return result;
}

Matrix2x2 Matrix2x2::operator+()const{

    double finalNumber1 = +this->number1;
    double finalNumber2 = +this->number2;
    double finalNumber3 = +this->number3;
    double finalNumber4 = +this->number4;

    Matrix2x2 finalMatrix(finalNumber1, finalNumber2, finalNumber3, finalNumber4);

    return finalMatrix;


}

double &Matrix2x2::operator[](const int &val){
    switch (val)
    {
        case 0:
            return this->number1;
        case 1:
            return this->number2;
        case 2:
            return this->number3;
        case 3:
            return this->number4;
        default:
            throw invalid_argument("index out of bound");
    }
}

double Matrix2x2::operator()(){
    return this->determinant();
}

Matrix2x2 &Matrix2x2::operator+=(const Matrix2x2 &rhs) {

    this->number1 += rhs.number1;
    this->number2 += rhs.number2;
    this->number3 += rhs.number3;
    this->number4 += rhs.number4;
    return *this;
}

Matrix2x2 &Matrix2x2::operator+=(const int& inputValue) {

    this->number1 += inputValue;
    this->number2 += inputValue;
    this->number3 += inputValue;
    this->number4 += inputValue;
    return *this;
}
Matrix2x2 &Matrix2x2::operator-=(const int& inputValue) {

    this->number1 -= inputValue;
    this->number2 -= inputValue;
    this->number3 -= inputValue;
    this->number4 -= inputValue;
    return *this;
}
Matrix2x2 &Matrix2x2::operator*=(const int & inputValue){
    this->number1 *= inputValue;
    this->number2 *= inputValue;
    this->number3 *= inputValue;
    this->number4 *= inputValue;
    return *this;
}
Matrix2x2 &Matrix2x2::operator/=(const int & inputValue){
    this->number1 /= inputValue;
    this->number2 /= inputValue;
    this->number3 /= inputValue;
    this->number4 /= inputValue;
    return *this;
}