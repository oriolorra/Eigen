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
  Matrix3f T_S_B;

  T_B_O <<  cos(theta), sin(theta), p_origin[0], -sin(theta), cos(theta), p_origin[1], 0, 0, 1; 
  cout << "\nHomogeneous matrix base to origin:" << endl << T_B_O << std::endl;

  T_S_B << cos(beta), sin(beta), m_base[0], -sin(beta), cos(beta), m_base[1], 0, 0, 1;
  cout << "\nHomogeneous matrix sensor to base:" << endl << T_S_B << std::endl;

  cout << "\nVector q in origin in homogeneous:" << endl << T_B_O * T_S_B * q_sensor << endl;
  cout << "\nI have multiplied the homogeneous matrix Base to Origin, the homogeneous matrix Sensor to Base and the Vector q in Sensor coordinates" << endl;

  cout << "\nVector q in base in homogeneous:" << endl << T_S_B * q_sensor << endl;
  cout << "\nI have multiplied the homogeneous matrix Sensor to Base and the Vector q in Sensor coordinates\n\n" << endl;
}
