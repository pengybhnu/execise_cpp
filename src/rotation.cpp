#include <Eigen/Dense>
#include <iostream>
using namespace Eigen;

// Function to rotate a segment around its base point
void rotateSegment(Vector2d& p1, Vector2d& p2, double angle) {
  // Translate the segment so that the base point becomes the origin
  p2 -= p1;

  // Create the rotation matrix
  Rotation2D<double> rot(angle);

  // Rotate the segment
  p2 = rot * p2;

  // Translate the segment back to its original position
  p2 += p1;
  Vector2d offset(100.0, 200.0);
  p2 += offset;
  p1 += offset;
}

int main() {
  Vector2d p1(1.0, 1.0);
  Vector2d p2(2.0, 2.0);

  // Rotate the segment by 45 degrees around its base point
  rotateSegment(p1, p2, M_PI / 4.0);
  std::cout << p1 << " -> " << p2 << std::endl;
  return 0;
}