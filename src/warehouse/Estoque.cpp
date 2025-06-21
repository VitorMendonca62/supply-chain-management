/******************************************************************************
 * Arquivo     : Estoque.cpp
 * Autor       : Arthur Marinho
 * Criado em   : 17/06/2025
 * Descrição   : Arquivo de implementação para a classe Estoque (versão refatorada).
 ******************************************************************************/

#include "Estoque.h"

// --- Definições dos Métodos da Classe Estoque ---


bool Estoque::init(int idEstoque, int idProduto, int qtd, const std::string& localizacao, const std::string& data) {
    id_estoque = idEstoque;
    id_produto = idProduto;
    quantidade = qtd;
    localizacao_estoque = localizacao;
    data_ultima_movimentacao = data;
    return true;
}

// Getters
int Estoque::getIdEstoque() const {
    return id_estoque;
}

int Estoque::getIdProduto() const {
    return id_produto;
}

int Estoque::getQuantidade() const {
    return quantidade;
}

std::string Estoque::getLocalizacaoEstoque() const {
    return localizacao_estoque;
}

std::string Estoque::getDataUltimaMovimentacao() const {
    return data_ultima_movimentacao;
}

// Setters
void Estoque::setQuantidade(int nova_quantidade) {
    quantidade = nova_quantidade;
}

void Estoque::setLocalizacaoEstoque(const std::string& nova_localizacao) {
    localizacao_estoque = nova_localizacao;
}

void Estoque::setDataUltimaMovimentacao(const std::string& nova_data) {
    data_ultima_movimentacao = nova_data;
}