#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxEnvelopes(std::vector<std::vector<int>>& en) {
        // Ordena os envelopes por largura crescente e altura decrescente se as larguras forem iguais
        std::sort(en.begin(), en.end(), [](const auto& a, const auto& b) {
            if(a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });

        std::vector<int> ans;
        ans.push_back(en[0][1]);

        for(int i = 1; i < en.size(); i++) {
            if(en[i][1] > ans.back()) 
                ans.push_back(en[i][1]);
            else {
                // Encontra o índice onde a altura atual pode ser colocada na sequência crescente
                int index = std::lower_bound(ans.begin(), ans.end(), en[i][1]) - ans.begin();
                ans[index] = en[i][1];
            }
        }

        return ans.size();
    }
};

int main() {
    Solution sol;
    // Exemplo de teste com envelopes (largura, altura)
    std::vector<std::vector<int>> envelopes = {{5,4}, {6,4}, {6,7}, {2,3}};

    // Chama a função maxEnvelopes e imprime o resultado
    int result = sol.maxEnvelopes(envelopes);
    std::cout << "O número máximo de envelopes que podem ser aninhados é: " << result << std::endl;

    return 0;
}
