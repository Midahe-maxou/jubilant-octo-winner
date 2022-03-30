#pragma once
#ifndef MATRICE_HPP
#define MATRICE_HPP

#include <array>
#include <tuple>

template<int i, int j = 1>
class Matrice
{
public:
	Matrice(const std::array<std::array<int, j>, i>& matrice);
	Matrice(int n);
	
	void add(Matrice m);
	void substract(Matrice m);
	void multiply(int n);
	void multiply(Matrice m);
	void transpose();
	std::tuple<int, int> getDimention();

	void operator()(int i, int j);

	friend Matrice pow(int n);
	

private:
	std::tuple<int, int> dimention = std::make_tuple(i ,j);
	std::array<std::array<int, j>, i> matrice;
};


#endif //MATRICE_HPP