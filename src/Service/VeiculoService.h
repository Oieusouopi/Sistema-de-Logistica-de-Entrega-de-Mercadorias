//
// Created by eec on 19/06/25.
//

#ifndef VEICULOSERVICE_H
#define VEICULOSERVICE_H
#include <string>
#include <vector>

#include "../Model/Local.h"
#include "../Model/Veiculo.h"

enum EnumResultadoCriacaoVeiculo {
    SUCESSO_CRIACAO_DO_VEICULO,
    PLACA_DUPLICADA,
};

class VeiculoService {

    public:
        EnumResultadoCriacaoVeiculo criar(Veiculo& veiculo);
        std::vector<Veiculo> listar();
        bool excluir(std::string placa);
        void updateStatus(std::string placa, bool status);
        void updateLocalAtual(std::string placa, Local local);
        bool validarPlaca(std::string placa);
    private:
        std::vector<Veiculo> veiculos;
};

#endif //VEICULOSERVICE_H
