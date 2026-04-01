#include <iostream>
#include <cmath>
#pragma once

template<typename I> requires std::integral<I>
class rational
{
	I num_;
	I den_;
	bool is_inf_ = false;
	bool is_nan_ = false;
	
public:
	/* Variabili booleane inf e nan */
	bool inf() const {return is_inf_;}
	bool nan() const {return is_nan_;}
	
	/* Costruttore di default */
	rational()
		: num_(I{0}), den_(I{1})
	{}
	
	/* Costruttore user-defined */
	rational(const I& pnum_, const I& pden_)
	{
		if (pden_ == 0 && pnum_ == 0) {
			is_nan_ = true;
			is_inf_ = false;
			num_ = 0;
			den_ = 0; }
		else if (pden_ == 0 && pnum_ != 0) {
			is_inf_ = true;
			is_nan_ = false;
			num_ = 1;
			den_ = 0; }
		else {
			is_inf_ = false;
			is_nan_ = false;
			num_ = pnum_;
			den_ = pden_;
		if (den_ < 0){
			num_ = -num_;
			den_ = -den_; }
		}
	}
	
	/* Massimo comune divisore */
	I mcd(I a, I b) {
		while (b != 0) {
			I temp = b;
			b = a % b;
			a = temp;
		}
		return a;
	}
	/* Minimo comune multiplo */
	I mcm(I a, I b) {
		return abs(a * b) / mcd(a, b);
	}
	
	/* Creo una funzione che semplifica ai minimi termini */
	void semplifica() {
		I maxdivisore = mcd(num_, den_);
		num_ /= maxdivisore;
		den_ /= maxdivisore;
	}
		
	I num() const {return num_; }
	I den() const {return den_; }
	
	/* Implementazione canonica dell'incremento */
	rational<I>& operator+=(const rational<I>& other) {
		if (is_nan_ || other.is_nan_) {
			is_nan_ = true;
			num_ = 0;
			den_ = 0;
		    return *this;}
		if (is_inf_ || other.is_inf_) {
			is_inf_ = true;
			num_ = 1;
			den_ = 0;
			return *this;}
		I maxdivisore = mcd(den_, other.den_);
		I new_num_ = num_ * (other.den_ / maxdivisore) + other.num_ * (den_ / maxdivisore);
		I new_den_ = mcm(den_, other.den_);
		num_ = new_num_;
		den_ = new_den_;
		semplifica();
		return *this;
	}
	
	/* Implementazione canonica della somma */
	rational<I> operator+(const rational<I>& other) const {
		rational ret = *this;
		ret += other;
		return ret;
	}
	
	/* Implementazione canonica del decremento */
	rational<I> operator-=(const rational<I>& other) {
		if (is_inf_ && other.is_inf_) {
			is_nan_ = true;
			is_inf_ = false;
			num_ = 0;
			den_ = 0;
		    return *this;}
		else if (is_nan_ || other.is_nan_) {
			is_nan_ = true;
			num_ = 0;
			den_ = 0;
			return *this;}
		else if (is_inf_ || other.is_inf_) {
			is_inf_ = true;
			num_ = 1;
			den_ = 0;
			return *this;}
		I maxdivisore = mcd(den_, other.den_);
		I new_num_ = num_ * (other.den_ / maxdivisore) - other.num_ * (den_ / maxdivisore);
		I new_den_ = mcm(den_, other.den_);
		num_ = new_num_;
		den_ = new_den_;
		semplifica();
		return *this;
	}
	
	/* Implementazione canonica della sottrazione */
	rational<I> operator-(const rational<I>& other) const {
		rational ret = *this;
		ret -= other;
		return ret;
	}
	
	/* Implementazione canonica di " *= " */
	rational<I> operator*=(const rational<I>& other) {
		if ((is_inf_ && other.num_ == 0) || (num_ == 0 && other.is_inf_)) {
			is_nan_ = true;
			num_ = 0;
			den_ = 0;
			return *this;}
		else if (is_nan_ || other.is_nan_) {
			is_nan_ = true;
			num_ = 0;
			den_ = 0;
		    return *this;}
		else if (is_inf_ || other.is_inf_) {
			is_inf_ = true;
			num_ = 1;
			den_ = 0;
			return *this;}
		num_ *= other.num_;
		den_ *= other.den_;
		semplifica();
		return *this;
	}
	
	/* Implementazione canonica del prodotto */
	rational<I> operator*(const rational<I>& other) const{
		rational ret = *this;
		ret *= other;
		return ret;
	}
	
	/* Implementazione canonica di " /= " */
	rational<I> operator/=(const rational<I>& other) {
		if (is_inf_ && other.is_inf_) {
			is_nan_ = true;
			num_ = 0;
			den_ = 0;
			return *this;}
		else if (num_ == 0 && other.num_ == 0) {
			is_nan_ = true;
			num_ = 0;
			den_ = 0;
			return *this;}
		else if (is_nan_ || other.is_nan_) {
			is_nan_ = true;
			num_ = 0;
			den_ = 0;
		    return *this;}
		else if (is_inf_ || other.is_inf_) {
			is_inf_ = true;
			num_ = 1;
			den_ = 0;
			return *this;}
		if (other.num_ == 0) {
			is_inf_ = true;
		}
		num_ *= other.den_;
		den_ *= other.num_;
		semplifica();
		return *this;
	}
	
	/* Implementazione canonica della divisione */
	rational<I> operator/(const rational<I>& other) const{
		rational ret = *this;
		ret /= other;
		return ret;
	}
};

template<typename I>
std::ostream&
operator<<(std::ostream& os, const rational<I>& r)
{
	if (r.nan()) {
		os << "NaN" ;
	}
	else if (r.inf()) {
		os << "Inf" ;
	}
	else {
		os << "(" << r.num() << "/" << r.den() << ")";
	}
	return os;
}
		
			