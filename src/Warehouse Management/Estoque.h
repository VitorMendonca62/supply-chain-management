/******************************************************************************
 * Arquivo     : Estoque.h
 * Autor       : Arthur Marinho
 * Criado em   : 17/06/2025
 * Descrição   : Arquivo de cabeçalho para a classe Estoque (versão refatorada).
 * Representa uma linha de inventário (um produto em um local).
 ******************************************************************************/

#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <iostream>
#include <string>


class Estoque {
private:
    int id_estoque;
    int id_produto;
    int quantidade;
    std::string localizacao_estoque;
    std::string data_ultima_movimentacao; // Mantido da classe ItemEstoque

public:
    // Método de inicialização
    bool init(int idEstoque, int idProduto, int qtd, const std::string& localizacao, const std::string& data);

    // Getters
    int getIdEstoque() const;
    int getIdProduto() const;
    int getQuantidade() const;
    std::string getLocalizacaoEstoque() const;
    std::string getDataUltimaMovimentacao() const;

    // Setters
    void setQuantidade(int nova_quantidade);
    void setLocalizacaoEstoque(const std::string& nova_localizacao);
    void setDataUltimaMovimentacao(const std::string& nova_data);
};

#endif // ESTOQUE_H
