#include <vector>
#include <climits>  

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        // Chama a função principal recursiva com os índices inicial e final 
        return maxSubArray(nums, 0, nums.size() - 1);
    }

    int maxSubArray(std::vector<int>& A, int L, int R) {
        // Verifica se o intervalo é válido
        if (L > R)
            return INT_MIN;  // Retorna um valor muito pequeno se o intervalo não é válido

        int mediana = (L + R) / 2;
        int somaL = 0, somaR = 0;

        // Calcula a soma máxima do lado esquerdo
        for (int i = mediana - 1, soma = 0; i >= L; i--)
            soma += A[i],  // Acumula a soma ao percorrer do meio para a esquerda
            somaL = std::max(somaL, soma);  

        // Calcula a soma máxima do lado direito
        for (int i = mediana + 1, soma = 0; i <= R; i++)
            soma += A[i],  // Acumula a soma ao percorrer do meio para a direita
            somaR = std::max(somaR, soma);  

        // Retorna o máximo somaL, somaR e somaM
        return std::max({maxSubArray(A, L, mediana - 1), maxSubArray(A, mediana + 1, R), somaL + A[mediana] + somaR});
    }
};
