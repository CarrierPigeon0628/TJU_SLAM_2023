#include <iostream>
#include <cmath>

using namespace std;

#include <Eigen/Core>
#include <Eigen/Geometry>

using namespace Eigen;

int main(int argc, char **argv) {
  cout.precision(4);

  Vector3d vec(1, 1, 0);
  vec.normalize();
  
  AngleAxisd rotation_vector(M_PI / 36, vec);     //沿 [2^(-0.5), 2^(-0.5), 0] 轴旋转 5 度 (studentId: 2054205)
  
  Matrix3d rotation_matrix = rotation_vector.toRotationMatrix();
  cout << "R =\n" << rotation_matrix << endl;
  
  cout << endl;
  
  cout << "To prove R is a rotation matrix," << endl;
  cout << "R * R^T =\n" << rotation_matrix * rotation_matrix.transpose() << endl;
  cout << "|R| = " << rotation_matrix.determinant() << endl;
  
  cout << endl;
  
  cout << "Transpose =\n" << rotation_matrix.transpose() << endl;
  cout << "Trace = " << rotation_matrix.trace() << endl;
  cout << "Inverse =\n" << rotation_matrix.inverse() << endl;
  cout << "Determinant = " << rotation_matrix.determinant() << endl;
  
  cout << endl;
  
  Quaterniond q = Quaterniond(rotation_matrix);
  cout << "Quaternion [(x,y,z,w) => w + xi + yj + zk] = " << q.coeffs().transpose() << endl;
  return 0;
}
