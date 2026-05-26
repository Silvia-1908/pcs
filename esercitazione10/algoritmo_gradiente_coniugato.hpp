#include <iostream>
#include <Eigen/Dense>
#include <Eigen/SVD>

double condA(const Eigen::MatrixXd& A)
{
    Eigen::JacobiSVD<Eigen::MatrixXd> svd(A);
    Eigen::VectorXd s = svd.singularValues();
    return s.maxCoeff() / s.minCoeff();
}

Eigen::VectorXd gradiente_coniugato(
    const Eigen::MatrixXd& A,
    const Eigen::VectorXd& b,
    Eigen::VectorXd x0,
    double tol,
    int maxIter,
    int& it,
	Eigen::VectorXd& res_finale)
{
    Eigen::VectorXd r = b - A * x0;
    Eigen::VectorXd p = r;
    double res0 = r.norm();
    it = 0;
    while (it < maxIter && r.norm() > tol * res0)
    {
        Eigen::VectorXd Ap = A * p;
        double alpha = r.dot(r) / p.dot(Ap);
        x0 = x0 + alpha * p;
        Eigen::VectorXd r1 = r - alpha * Ap;
        double beta = r1.dot(r1) / r.dot(r);
        p = r1 + beta * p;
        r = r1;
		res_finale = r;
        it++;
    }

    return x0;
}

