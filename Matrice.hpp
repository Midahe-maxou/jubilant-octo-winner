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

	std::tuple<int, int> getDimention() const noexcept;
	std::array<std::array<int, nb_colomns>, nb_lignes> getMatrice() const noexcept;

	void operator()(int i, int j) const;
	std::array<int, nb_colomns> operator[](int i) const;

	//friend std::ostream& operator<<(std::ostream& os, const Matrice<nb_lignes, nb_columns>& matrice);

	//friend Matrice pow(int n) const;
	

private:
	std::tuple<int, int> m_dimention;
	std::array<std::array<int, nb_colomns>, nb_lignes> m_matrice;
};


#endif //MATRICE_HPP