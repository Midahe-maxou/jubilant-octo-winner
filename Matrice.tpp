#include <string>
#include <array>
#include <tuple>
#include <stdexcept>


using string = std::string;

template<int nb_lignes = 1, int nb_colomns = 1>
class Matrice
{
public:
	Matrice(const std::array<std::array<int, nb_colomns>, nb_lignes>& matrice)
		:m_matrice(matrice)
	{
		m_dimention = std::make_tuple(nb_lignes, nb_colomns);
	}

	Matrice(int n)
	{
		m_dimention = std::make_tuple(nb_lignes, nb_colomns);
		for (int i = 0; i < nb_lignes; i++)
		{
			for (int j = 0; j < nb_colomns; j++)
			{
				matrice(i, j) = n;
			}
		}
	}

	Matrice()
	{
		Matrice(0);
	}

	void add(const Matrice& m)
	{
		if (m_dimention != m.getDimention()) throw std::invalid_argument("Les deux matrices n'ont pas la même taille");


		auto [lignes, colomns] = m_dimention;
		for (int i = 0; i < lignes; i++)
		{
			for (int j = 0; j < colomns; j++)
			{
				m_matrice[i][j] += m[i][j]
			}
		}
	}

	void substract(const Matrice& m)
	{
		add(m.multiply(-1));
	}

	void multiply(int n)
	{
		for (auto& ligne : m_matrice)
		{
			for (int& i : ligne)
			{
				i *= n;
			}
		}
	}

	void multiply(const Matrice& m)
	{

		auto [m_lignes, m_colomns] = m_dimention;
		auto [other_lignes, other_colomns] = m.getDimention();

		if (m_colomns != m_lignes) throw std::invalid_argument(std::to_string(m_lignes) + "x" + std::to_string(m_colomns) + " pas multipliable avec " + std::to_string(other_lignes) + "x" + std::to_string(other_colomns));

		Matrice<m_lignes, other_colomns> matrice


		for (int i = 0; i < m_lignes; i++)
		{
			for (int j = 0; j < other_colomns; j++)
			{
				int somme = 0;
				for (int k = 0; k < m_colomns; k++)
				{
					somme += m_matrice(i, k) * m(k, j);
				}
			}
		}
	}

	void transpose();
	std::tuple<int, int> getDimention();

	int operator()(int i, int j);
	std::array<int, nb_colomns> operator[](int i);

	friend Matrice pow(int n);


private:
	std::tuple<int, int> m_dimention;
	std::array<std::array<int, nb_colomns>, nb_lignes> m_matrice;
};

