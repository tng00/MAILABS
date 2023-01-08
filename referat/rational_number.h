//
// Created by tngue on 05.01.2023.
//

#ifndef UNTITLED_RATIONAL_NUMBER_H
#define UNTITLED_RATIONAL_NUMBER_H
#include <cassert>

class RationalNumber {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) {
        return (!b) ? a : gcd(b, a % b);
    }

    void reduce() {
        int d = gcd(numerator, denominator);
        numerator /= d;
        denominator /= d;
        if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
    }

public:
    // конструктор
    RationalNumber(int numerator_ = 0, int denominator_ = 1) :
            numerator(numerator_), denominator(denominator_) {
        assert(denominator_ != 0);
        reduce();
    }

    // конструктор копирования
    RationalNumber(const RationalNumber &other) {
        numerator = other.numerator;
        denominator = other.denominator;
    }

    // move конструктор
    RationalNumber(RationalNumber &&other) noexcept {
        numerator = other.numerator;
        denominator = other.denominator;
        other.numerator = 0;
        other.denominator = 1;
    }

    // оператор присваивания
    RationalNumber &operator=(const RationalNumber &other) = default;

    // move оператор присваивания
    RationalNumber &operator=(RationalNumber &&other) noexcept {
        numerator = other.numerator;
        denominator = other.denominator;
        other.numerator = 0;
        other.denominator = 1;
        return *this;
    }

    // фкнкции-члены для получения числителя и знаменателя
    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }

    // унарные +, -
    RationalNumber operator+() const {
        return RationalNumber(numerator, denominator);
    }

    RationalNumber operator-() const {
        return RationalNumber(-numerator, denominator);
    }

    // операторы +=, -=, *=, /=
    RationalNumber &operator+=(const RationalNumber &rhs) {
        numerator = numerator * rhs.denominator + rhs.numerator * denominator;
        denominator *= rhs.denominator;
        reduce();
        return *this;
    }

    RationalNumber &operator-=(const RationalNumber &rhs) {
        numerator = numerator * rhs.denominator - rhs.numerator * denominator;
        denominator *= rhs.denominator;
        reduce();
        return *this;
    }

    RationalNumber &operator*=(const RationalNumber &rhs) {
        numerator *= rhs.numerator;
        denominator *= rhs.denominator;
        reduce();
        return *this;
    }

    RationalNumber &operator/=(const RationalNumber &rhs) {
        int temp = rhs.numerator;
        numerator *= rhs.denominator;
        denominator *= temp;
        reduce();
        return *this;
    }

    // префиксные операторы ++,--
    RationalNumber &operator++() {
        numerator += denominator;
        // здесь нет необходимости вызывать reduce(), так как дробь остаётся несократимой
        return *this;
    }

    RationalNumber &operator--() {
        numerator -= denominator;
        return *this;
    }

    // постфиксные операторы ++, --
    // формально определяются с дополнительным игнорируемым параметром типа int
    RationalNumber operator++(int) {
        RationalNumber prev = *this;
        ++*this;
        return prev;
    }

    RationalNumber operator--(int) {
        RationalNumber prev = *this;
        --*this;
        return prev;
    }

    // операторы сравнения ==, !=
    bool operator==(const RationalNumber &rhs) const {
        return numerator == rhs.Numerator() && denominator == rhs.Denominator();
    }

    bool operator!=(const RationalNumber &rhs) const {
        return !(*this == rhs);
    }

    friend std::istream &operator>>(std::istream &, RationalNumber &);
};

// арифметические операторы +, -, *, /
RationalNumber operator+(const RationalNumber &lhs, const RationalNumber &rhs) {
    RationalNumber result = lhs;
    result += rhs;
    return result;
}

RationalNumber operator-(const RationalNumber &lhs, const RationalNumber &rhs) {
    RationalNumber result = lhs;
    result -= rhs;
    return result;
}

RationalNumber operator*(const RationalNumber &lhs, const RationalNumber &rhs) {
    RationalNumber result = lhs;
    result *= rhs;
    return result;
}

RationalNumber operator/(const RationalNumber &lhs, const RationalNumber &rhs) {
    RationalNumber result = lhs;
    result /= rhs;
    return result;
}

// переопределение ввода и вывода
std::ostream &operator<<(std::ostream &os, const RationalNumber &n) {
    return os << "(" << n.Numerator() << "/" << n.Denominator() << ")";
}

std::istream &operator>>(std::istream &in, RationalNumber &n) {
    in >> n.numerator >> n.denominator;
    return in;
}
#endif //UNTITLED_RATIONAL_NUMBER_H
