#include <iostream>
#include <cstring>
#include <cctype>
#include <utility>

using namespace std;

#include "fraction.h"

#ifdef UNIMPLEMENTED_classFraction
#ifdef _MSC_FULL_VER // if Visual Studio Compiler
    #pragma message ("Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym")
#else
    #warning "Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym"
#endif // #ifdef _MSC_FULL_VER
#endif // #ifdef UNIMPLEMENTED_classFraction

int Fraction::removedFractions_ = 0;


Fraction::Fraction(int num, int denom, std::string name) :
    numerator_(num), denominator_(denom), fractionName_(std::move(name)){

}

int Fraction::getNumerator() const{
    return numerator_;
}

int Fraction::getDenominator() const{
    return denominator_;
}

void Fraction::setNumerator(int num) {
    numerator_ = num;
}

void Fraction::setDenominator(int denom) {
    denominator_ = denom;
}

void Fraction::print() const {
    cout << numerator_ << "/" << denominator_ << "\n";
}

int Fraction::removedFractions() {
    return removedFractions_;
}

Fraction::~Fraction() {
    removedFractions_++;

}

void Fraction::save(ostream &os) const {
    os << numerator_ << "/" << denominator_;
}

void Fraction::load(istream &is) {
    char slash;
    is >> numerator_ >> slash >> denominator_;

}

string Fraction::getFractionName() const {
    return fractionName_;
}

int Fraction::getInvalidDenominatorValue() {
    return invalidDenominatorValue;
}









