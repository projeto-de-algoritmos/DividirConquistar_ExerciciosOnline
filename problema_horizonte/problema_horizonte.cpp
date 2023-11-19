class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // Fila de prioridade para armazenar pares (altura, final) dos edifícios.
        priority_queue<pair<int, int>> altura;
        
        // Vetor que armazenará os pontos do contorno.
        vector<vector<int>> skyline;
        
        // Índice para percorrer os edifícios.
        int posicao = 0;
        
        // A posicao x atual, inicializada com a posicaoição x do primeiro edifício.
        int distancia_atual = buildings[0][0];

        // Loop principal para percorrer todos os edifícios e construir o contorno.
        while (posicao < buildings.size() or not altura.empty()) {
            // Verifica se a próxima posicaoição é o início de um novo edifício.
            if (altura.empty()) {
                // Se a fila de prioridade estiver vazia, preenche a lacuna entre edifícios.
                int proximoL = buildings[posicao][0];
                while (posicao < buildings.size() and buildings[posicao][0] == proximoL) {
                    altura.push({buildings[posicao][2], buildings[posicao][1]});
                    posicao++;
                }
                // Adiciona o primeiro ponto do contorno.
                skyline.push_back({proximoL, altura.top().first});
                distancia_atual = proximoL;
                continue;
            }

            // Altura antes da próxima posicaoição atual posicaosível ser escolhida.
            int altura_atual = altura.top().first;

            // Verifica se há edifícios a serem adicionados.
            if (posicao < buildings.size()) {
                int proximoL = buildings[posicao][0];
                int edificio = altura.top().second;

                // Adiciona os edifícios na próxima posicaoição x.
                if (proximoL <= edificio) {
                    while (posicao < buildings.size() and buildings[posicao][0] == proximoL) {
                        altura.push({buildings[posicao][2], buildings[posicao][1]});
                        posicao++;
                    }
                    distancia_atual = proximoL;
                } else {
                    // Caso contrário, move-se para o final deste bloco.
                    distancia_atual = edificio;
                    // Remove os edifícios atuais e expirados.
                    while (not altura.empty() and altura.top().second <= distancia_atual)
                        altura.pop();
                }
            } else {
                // Fornece a próxima posicaosível altura e define o ponto final.
                distancia_atual = altura.top().second;
                while (not altura.empty() and altura.top().second <= distancia_atual)
                    altura.pop();
            }

            // Se a fila de prioridade estiver vazia, adiciona ponto de contorno com altura 0.
            if (altura.empty()) {
                skyline.push_back({distancia_atual, 0});
                continue;
            }

            // Se houver uma mudança na altura, adiciona ponto de contorno.
            if (altura.top().first != altura_atual)
                skyline.push_back({distancia_atual, altura.top().first});
        }

        // Retorna o contorno construído.
        return skyline;
    }
};
