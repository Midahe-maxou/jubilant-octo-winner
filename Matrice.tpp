#include <string>
#include <array>
#include <tuple>
#include <stdexcept>
#include <iosfwd>

using string = std::string;

template<int nb_lignes = 1, int nb_columns = 1>
class Matrice
{
public:
	Matrice(const std::array<std::array<int, nb_columns>, nb_lignes>& matrice)
		:m_matrice(matrice)
	{
	}

	Matrice(int n)
	{
		for (int i = 0; i < nb_lignes; i++) {
			for (int j = 0; j < nb_columns; j++) {
				m_matrice(i, j) = n;
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


		int [lignes, columns] = m_dimention;
		for (int i = 0; i < lignes; i++) {
			for (int j = 0; j < columns; j++) {
				m_matrice[i][j] += m[i][j];
			}
		}
	}

	void substract(const Matrice& m)
	{
		add(m.multiply(-1));
	}

	void multiply(int n)
	{
		for (auto& ligne : m_matrice) {
			for (int& i : ligne) {
				i *= n;
			}
		}
	}

	void multiply(const Matrice& m)
	{

		int [m_lignes, m_columns] = m_dimention;
		int [other_lignes, other_columns] = m.getDimention();

		if (m_columns != m_lignes) throw std::invalid_argument(std::to_string(m_lignes) + "x" + std::to_string(m_columns) + " pas multipliable avec " + std::to_string(other_lignes) + "x" + std::to_string(other_columns));

		Matrice<m_lignes, other_columns> matrice;

		for (int i = 0; i < m_lignes; i++) {
			for (int j = 0; j < other_columns; j++) {
				int somme = 0;
				for (int k = 0; k < m_columns; k++) {
					somme += m_matrice(i, k) * m(k, j);
				}
				matrice(i, j) = somme;
			}
		}

		m_matrice = matrice.getMatrice();
		m_dimention = matrice.getDimention();
	}

	void transpose()
	{
		int [lignes, columns] = getDimention();
		Matrice<columns, lignes> matrice;

		for (int i = 0; i < lignes; i++) {
			for (int j = 0; i < columns; j++) {
				matrice(j, i) = m_matrice(i, j);
			}
		}

		m_matrice = matrice.getMatrice();
		m_dimention = matrice.getDimention();
	}

	std::tuple<int, int> getDimention() const noexcept
	{
		return m_dimention;
	}

	std::array<std::array<int, nb_columns>, nb_lignes> getMatrice() const noexcept
	{
		return m_matrice;
	}

	int operator()(int i, int j) const
	{
		return m_matrice[i][j];
	}

	friend std::ostream& operator<<(std::ostream& os, const Matrice<nb_lignes, nb_columns>& matrice)
	{
		auto [lignes, columns] = matrice.getDimention();

		os << "\n{\n";

		for (int i = 0; i < lignes; i++) {
			os << "(";
			for (int j = 0; j < columns; j++) {
				os << std::to_string(matrice(i, j)) << ", ";
			}
			os << ")\n";
		}

		os << "\n }\n";
		return os;
	}

	std::array<int, nb_columns> operator[](int i) const
	{
		return m_matrice[i];
	}

	//friend Matrice pow(int n) const noexcept;


private:
	std::tuple<int, int> m_dimention = std::make_tuple(nb_lignes, nb_columns);
	std::array<std::array<int, nb_columns>, nb_lignes> m_matrice;
};;