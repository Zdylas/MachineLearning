#include <stdint.h>
#include <stdbool.h>
#include <vector>
#include <iostream>
#include <cassert>

// void assert_parameters
// (
//     const std::vector<float> A, 
//     const std::vector<float> B, 
//     const std::vector<float> C, 
//     const int A_n, 
//     const int B_n
// )
// {
//
// }

void naive_multiplication
(
    const std::vector<float> A, 
    const std::vector<float> B, 
    std::vector<float>& C, 
    const int A_m,
    const int A_n,
    const int B_m,
    const int B_n
)
{
    //assert_parameters(A, B, C, A_n, B_n);
    for (size_t A_i = 0; A_i < A_m; A_i++) {
        for (size_t B_j = 0; B_j < B_n; B_j++) {
            for (size_t A_j = 0; A_j < A_n; A_j++) {
                C[A_i * B_n + B_j] += A[A_i * A_n + A_j] * B[A_j * B_n + B_j];   
            }
        }
    }
}

int main()
{
    int A_m = 2;
    int A_n = 3;
    int B_m = 3;
    int B_n = 2;

    std::vector<float> A = {5, 2, 8, 6, 50, 3};
    std::vector<float> B = {9, 2, 1, 10, 6, 8};
    std::vector<float> C;
    C.resize(A_m*B_n); 

    naive_multiplication(A, B, C, A_m, A_n, B_m, B_n);

    // Default printing of matrix
    std::cout << "[";
    for (size_t i = 0; i < A_m; i++) {
        if (i == 0) {
            std::cout << "[";
        } else {
            std::cout << " ["; 
        }

        for (size_t j = 0; j < B_n; j++) {
            if (j != B_n-1) {
                std::cout << C[i * A_m + j] << ", ";
            } else {
                std::cout << C[i * A_m + j];
            }
        }
        if (i != A_m - 1) {
            std::cout << "]\n";
        } else {
            std::cout << "]";
        }
    }
    std::cout << "]" << std::endl;
    
    return 0; 
}


