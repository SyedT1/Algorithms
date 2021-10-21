#include <iostream>
using namespace std;
int **multiply(int **A, int **B)
{
    int **K = new int *[2];
    for (int i = 0; i < 2; i++)
        K[i] = new int[2];
    K[0][0] = (A[0][0] * B[0][0]) + (A[0][1] * B[1][0]);
    K[0][1] = (A[0][0] * B[0][1]) + (A[0][1] * B[1][1]);
    K[1][0] = (A[1][0] * B[0][0]) + (A[1][1] * B[1][0]);
    K[1][1] = (A[1][0] * B[0][1]) + (A[1][1] * B[1][1]);
    return K;
}
int **power(int b, int **F, int **M)
{
    if (b > 0)
    {
        if (b & 1)
        {
            int **M_ = multiply(M, F);
            return power(b / 2, multiply(F, F), M_);
        }
        else
        {
            return power(b / 2, multiply(F, F), M);
        }
    }
    else
    {
        return M;
    }
}
int fast_fibonacci(int x)
{
    int **M = new int *[2], **F = new int *[2];
    for (int i = 0; i < 2; i++)
    {
        M[i] = new int[2];
        F[i] = new int[2];
    }
    M[0][0] = 1, M[0][1] = 0, M[1][0] = 0, M[1][1] = 1;
    F[0][0] = 1, F[0][1] = 1, F[1][0] = 1, F[1][1] = 0;
    if (x == 0)
    {
        return 0;
    }
    M = power(x - 1, F, M);
    return M[0][0];
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < 10; i++)
        cout << fast_fibonacci(i) << endl;
}
