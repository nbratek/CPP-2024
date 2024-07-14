#include <iostream>
#include <stdexcept> // std::out_of_range
#include <numeric>   // std::gcd

#include "fraction.h"

#warning "Metody sa do zaimplementowania. Instrukcja w pliku naglowkowym" // po zaimplementowaniu sugeruje usuniecie tej linijki - nie chcemy warningow

Fraction::Fraction(int num, int den) {
    numerator_ = num;
    if (den == 0){
        throw std::invalid_argument("Denominator cannot be 0");
    }
    denominator_ = den;
}

void Fraction::setNumerator(int num) {
    numerator_ = num;
}

void Fraction::setDenominator(int den) {
    if (den == 0){
        throw std::invalid_argument("Denominator cannot be 0");
    }
    denominator_ = den;
}

Fraction Fraction::operator+(const Fraction &fraction2) const {
    int newDen = denominator_ * fraction2.denominator();
    if (newDen == 0){
        throw std::invalid_argument("Denominator cannot be 0");
    }
    int newNom = fraction2.denominator() * numerator_ + denominator_ * fraction2.numerator();
    Fraction newFraction = Fraction(newNom,newDen);
    return reduce(newFraction);
}

Fraction Fraction::reduce( Fraction fraction) {
    int num = fraction.numerator();
    int den = fraction.denominator();
    if (den == 0){
        throw std::invalid_argument("Denominator cannot be 0");
    }
    int gcdval = std::gcd(num, den);
    num /= gcdval;
    den /= gcdval;
    return Fraction(num, den);
}

Fraction Fraction::operator*(const Fraction &fraction2) const {
    int newNum = numerator_ * fraction2.numerator();
    int newDen = denominator_ * fraction2.denominator();
    if (newDen == 0){
        throw std::invalid_argument("Denominator cannot be 0");
    }
    Fraction newFraction = Fraction(newNum, newDen);
    return reduce(newFraction);
}
