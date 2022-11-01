#include <gtest.h>
#include "Triangular_matrix.h"
#include "Lent_matrix.h"
#include "Vector.h"
#include "Matrix.h"

using namespace std;

int main(int argc, char **argv)
{

  TLentDynamicMatrix<int> g(6, 3);
  g[0][0] = 4; g[0][1] = 8; g[0][2] = 9; g[0][3] = 6;
  g[1][0] = 7; g[1][1] = 8; g[1][2] = 6; g[1][3] = 5; g[1][4] = 4;
  g[2][0] = 1; g[2][1] = 2; g[2][2] = 3; g[2][3] = 4; g[2][4] = 5; g[2][5] = 6;
  g[3][0] = 7; g[3][1] = 6; g[3][2] = 8; g[3][3] = 3; g[3][4] = 2;
  g[4][0] = 3; g[4][1] = 7; g[4][2] = 2; g[4][3] = 1;

  int n = 3;
  TDynamicVector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    a[i] = i + 1;
  }
  TDynamicVector<int> b = (a * 2);

  TDynamicVector<int> c;

  c = a + b;
  std::cout << "Vector a + b = \n";

  for (auto i = c.begin(); i != c.end(); ++i)
  {
    std::cout << *i << ' ';
  }
  std::cout << std::endl;

  TDynamicMatrix<int> m(n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      m[i][j] = i + j * 3 + 1;

  std::cout << "Matrix m =: \n" << m;
  TDynamicMatrix<int> x(m), res(n);
  std::cout <<"\nMatrix x =: \n" << x;

  res = x * m;
  std::cout << "\nMatrix x * m =: \n" << res;
  //std::cout << res;

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
