#pragma once
#ifndef MATRICE_HPP
#define MATRICE_HPP

#include <array>
#include <tuple>

template<int nb_lignes = 1, int nb_colomns = 1>
class Matrice
{
public:
	Matrice(const std::array<std::array<int, nb_colomns>, nb_lignes>& matrice);
	Matrice(int n);
	Matrice();

	void add(const Matrice& m);
	void substract(const Matrice& m);
	void multiply(int n);
	void multiply(const Matrice& m);
	void transpose();
	std::tuple<int, int> getDimention();

	void operator()(int i, int j);
	std::array<int, nb_colomns> operator[](int i);

	friend Matrice pow(int n);
	

private:
	std::tuple<int, int> m_dimention;
	std::array<std::array<int, nb_colomns>, nb_lignes> m_matrice;
};


#endif //MATRICE_HPP