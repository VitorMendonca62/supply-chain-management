/******************************************************************************
 * Arquivo     : Estoque.cpp
 * Autor       : Gemini
 * Criado em   : 17/06/2025
 * Descrição   : Arquivo de implementação para as classes Estoque e ItemEstoque.
 ******************************************************************************/

#include "Estoque.h"
#include <string>
#include <vector>

// --- Definições dos Métodos da Classe ItemEstoque ---

bool ItemEstoque::init(int id, int idProd, int idEst, int qtd, const std::string& data) {
    id_item_estoque = id;
    id_produto = idProd;
    id_estoque = idEst;
    quantidade = qtd;
    data_ultima_movimentacao = data;
    return true;
}

// Getters
int ItemEstoque::getIdItemEstoque() const {
    return id_item_estoque;
}

int ItemEstoque::getIdProduto() const {
    return id_produto;
}

int ItemEstoque::getIdEstoque() const {
    return id_estoque;
}

int ItemEstoque::getQuantidade() const {
    return quantidade;
}

std::string ItemEstoque::getDataUltimaMovimentacao() const {
    return data_ultima_movimentacao;
}

// Setters
void ItemEstoque::setQuantidade(int nova_qtd) {
    quantidade = nova_qtd;
}

void ItemEstoque::setDataUltimaMovimentacao(const std::string& nova_data) {
    data_ultima_movimentacao = nova_data;
}


// --- Definições dos Métodos da Classe Estoque ---

bool Estoque::init(int id, const std::string& nome, const std::string& localizacao) {
    id_estoque = id;
    nome_estoque = nome;
    localizacao_estoque = localizacao;
    return true;
}

// Getters
int Estoque::getIdEstoque() const {
    return id_estoque;
}

std::string Estoque::getNomeEstoque() const {
    return nome_estoque;
}

std::string Estoque::getLocalizacaoEstoque() const {
    return localizacao_estoque;
}

const std::vector<ItemEstoque>& Estoque::getItems() const {
    return items;
}

// Setters
void Estoque::setNomeEstoque(const std::string& novo_nome) {
    nome_estoque = novo_nome;
}

void Estoque::setLocalizacaoEstoque(const std::string& nova_localizacao) {
    localizacao_estoque = nova_localizacao;
}