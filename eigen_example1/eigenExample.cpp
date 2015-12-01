//Std 
#include <iostream>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#include <cstdlib>

//eigen
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Geometry>
using Eigen::MatrixXd;

using namespace std;
using namespace Eigen;

int main()
{
  float theta = 28.0*M_PI/180;
  float beta = 41.0*M_PI/180;

  Vector3f p_origin(10.8, -2.7, 1.0);
  Vector3f m_base(3.1, 1.2, 1.0);
  Vector3f q_sensor(12.0, 3.0, 1.0);


  Matrix3f T_B_O;
  T_B_O(0,0) = cos(theta);
  T_B_O(1,0) = -sin(theta);
  T_B_O(0,1) = sin(theta);
  T_B_O(1,1) = cos(theta);
  T_B_O(2,0) = 0.0;
  T_B_O(2,1) = 0.0;
  T_B_O(0,2) = 10.8;
  T_B_O(1,2) = -2.7;
  T_B_O(2,2) = 1.0;

  cout << "\nHomogeneous matrix base to origin:" << endl << T_B_O << std::endl;

  Matrix3f T_S_B;
  T_S_B(0,0) = cos(beta);
  T_S_B(1,0) = -sin(beta);
  T_S_B(0,1) = sin(beta);
  T_S_B(1,1) = cos(beta);
  T_S_B(2,0) = 0.0;
  T_S_B(2,1) = 0.0;
  T_S_B(0,2) = 3.1;
  T_S_B(1,2) = 1.2;
  T_S_B(2,2) = 1.0;
  
  cout << "\nHomogeneous matrix sensor to base:" << endl << T_S_B << std::endl;

  cout << "\nq in origin in homogeneous:" << endl << T_B_O * T_S_B * q_sensor << endl;
  cout << "\nq in base in homogeneous:" << endl << T_S_B * q_sensor << endl;



}