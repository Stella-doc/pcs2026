//test gradiente coniugato
//PER COMPILARE EIGEN  g++ -I /usr/include/eigen3 test_gradiente_coniugato.cpp
#include <iostream>
#include "gradiente_coniugato.h"

int main(){
	int n= 5;
	Eigen::MatrixXd R = Eigen::MatrixXd::Random(n,n); //R^t*R garantisce solo la semidefinita positività
	Eigen::MatrixXd A = R.transpose()*R + Eigen::MatrixXd::Identity(n,n)*0.1; //aggiungo la matrice diagonale 0.1 per far si che sia di rnago 
																			//massimo e quindi garantire la positività della matrice
	Eigen::VectorXd x0 = Eigen::VectorXd::Zero(n);
	Eigen::VectorXd b = Eigen::VectorXd::Random(n);
	Eigen::VectorXd res = b-A*x0;
	double res_norm_0 = res.norm();
	const double res_tol =  1.0e-12;
	
	Eigen::VectorXd x = gradiente_coniugato(A, b, x0, res_norm_0, res_tol);
	std::cout<< x<< "\n";
	return 0;
}