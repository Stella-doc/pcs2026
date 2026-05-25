//gradiente coniugato
#pragma once
#include <iostream>
#include <Eigen/Dense>
#include <Eigen/SVD>

//se è tropponlento fai con l0erroe assoluto invece che con quello relativo

Eigen::VectorXd
gradiente_coniugato(Eigen::MatrixXd A,Eigen::VectorXd b,Eigen::VectorXd x0, double res_norm_0, const double res_tol){
	Eigen::VectorXd x = x0;
	Eigen::VectorXd res = b-A*x; //residuo iniziale
	Eigen::VectorXd p=res;
	
	int k=0;
	while (res.norm()>res_tol*res_norm_0){
		double alpha_k = ((p.transpose()*res)/(p.transpose()*A*p)).value();
		x= x0 + alpha_k*p;
		res = b - A*x;
		double beta_k = ((p.transpose()*A*res)/(p.transpose()*A*p)).value();
	
		p= res - beta_k*p;
		x0=x;
		k=k+1;
	}
	return x;
}