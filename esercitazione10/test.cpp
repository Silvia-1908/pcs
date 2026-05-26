#include <iostream>
#include <Eigen/Dense>
#include "algoritmo_gradiente_coniugato.hpp"

using namespace std;
using namespace Eigen;

int main()
{
    const int n = 3;
    const double tol = 1e-12;
    const int maxIter = 10000;
    MatrixXd B = MatrixXd::Random(n, n);
    if (abs(B.determinant()) < 1e-15)
    {
        cout << "Matrice non invertibile" << endl;
        return -1;
    }

    MatrixXd A = B.transpose() * B;
    VectorXd x_ex = VectorXd::Ones(n);
    VectorXd b = A * x_ex;
    VectorXd x0 = VectorXd::Zero(n);
    int it = 0;
	VectorXd res_finale;
    VectorXd x = gradiente_coniugato(A, b, x0, tol, maxIter, it, res_finale);
    cout << "Test gradiente coniugato\n";
    cout << "Cond(A): " << condA(A) << endl;
    cout << "Iterazioni: " << it << endl;
    double err_rel =
        (x_ex.norm() == 0.0)
        ? (x - x_ex).norm()
        : (x - x_ex).norm() / x_ex.norm();
    cout << "Errore relativo: " << err_rel << endl;
	cout << "Residuo finale: " << res_finale.norm() << endl;
    cout << "Soluzione numerica:\n" << x << endl;
    cout << "Soluzione esatta:\n" << x_ex << endl;
    return 0;
}