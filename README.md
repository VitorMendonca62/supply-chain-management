# Projeto de Estrutura de Dados Orientada a Objetos: Sistema de Gerenciamento da Cadeia de Suprimentos

## Descrição

Este projeto é um sistema de gerenciamento da cadeia de suprimentos desenvolvido em C++ como parte do trabalho prático da disciplina de Estrutura de Dados Orientada a Objetos (EDOO). O sistema permite o gerenciamento de produtos, fornecedores e estoque, com diferentes níveis de acesso para funcionários e gerentes.

## Funcionalidades

O sistema oferece as seguintes funcionalidades:

* **Autenticação de Usuário:** O sistema diferencia o acesso de funcionários e gerentes, com o gerente tendo permissões para gerenciar todos os módulos.
* **Gerenciamento de Produtos:**
    * Adicionar, listar, editar e remover produtos.
* **Gerenciamento de Fornecedores:**
    * Adicionar, listar, editar e remover fornecedores.
    * Verificação de CEP utilizando a API BrasilAPI.
* **Gerenciamento de Estoque:**
    * Adicionar, listar e atualizar itens no estoque.

## Estrutura do Projeto

O projeto está organizado da seguinte forma:

* `src/`: Contém todo o código-fonte do projeto.
    * `main.cpp`: Ponto de entrada do programa.
    * `system/`: Contém a classe `System` que controla o fluxo inicial do programa.
    * `shared/`: Contém classes e interfaces compartilhadas, como a `MenuView`.
    * `user/`, `employee/`, `manager/`: Classes relacionadas aos usuários do sistema (Funcionário e Gerente).
    * `product/`: Classes para o gerenciamento de produtos.
    * `vendor/`: Classes para o gerenciamento de fornecedores, incluindo a integração com a API BrasilAPI.
    * `stock/`: Classes para o gerenciamento de estoque.
* `.vscode/`: Contém as configurações do Visual Studio Code para o projeto, incluindo configurações de compilação e depuração.
* `.gitignore`: Arquivo para ignorar arquivos e pastas no controle de versão.

## Como Compilar e Executar

### Pré-requisitos

* Compilador C++ (g++)
* OpenSSL (para a funcionalidade de consulta de CEP)

### Passos

1.  **Clone o repositório:**

    ```bash
    git clone [https://github.com/vitormendonca62/supply-chain-management.git](https://github.com/vitormendonca62/supply-chain-management.git)
    cd supply-chain-management
    ```

2.  **Compile o projeto:**

    Navegue até o diretório `src` e compile os arquivos-fonte:

    ```bash
    cd src
    g++ -std=c++11 -o main main.cpp system/system.cpp user/user.cpp manager/manager.cpp employee/employee.cpp product/Product.cpp stock/stock.cpp vendor/vendor.cpp product/Product_view.cpp vendor/vendor_view.cpp stock/Stock_view.cpp employee/employee_view.cpp manager/manager_view.cpp -lssl -lcrypto
    ```

3.  **Execute o programa:**

    ```bash
    ./main
    ```

## Conceitos de EDOO Aplicados

Este projeto foi desenvolvido utilizando os pilares da programação orientada a objetos para garantir um código modular, reutilizável e de fácil manutenção.

### Herança

A herança permite que uma classe (filha) herde atributos e métodos de outra classe (pai), promovendo o reuso de código e a criação de hierarquias lógicas.

* **Hierarquia de Usuários**: A classe base `User` define os atributos e métodos comuns a todos os usuários. As classes `Manager` e `Employee` herdam de `User`, especializando o comportamento quando necessário, como no método `getAuthorization`.
* **Hierarquia de Menus**: A classe `MenuView` serve como uma interface base para todas as telas de menu. Classes como `ManagerView`, `ProductView`, e `VendorView` herdam dela, garantindo uma estrutura consistente para a interação com o usuário.

### Polimorfismo

O polimorfismo permite que objetos de diferentes classes respondam à mesma mensagem (chamada de método) de maneiras específicas.

* **Menus Dinâmicos**: O polimorfismo é utilizado de forma central no sistema de menus. A classe `System` e a `ManagerView`, por exemplo, manipulam ponteiros do tipo `MenuView`. Em tempo de execução, esses ponteiros podem apontar para objetos de qualquer classe filha (`ManagerView`, `ProductView`, etc.). Ao chamar `menu_view->call_menu_function()`, a versão correta do método é executada, correspondente ao tipo real do objeto, sem que o código que faz a chamada precise saber qual é esse tipo. Isso é possível através do uso de **funções virtuais** na classe base `MenuView`.

### Encapsulamento

O encapsulamento agrupa dados e os métodos que os manipulam dentro de uma classe, escondendo os detalhes de implementação do mundo exterior.

* **Proteção de Dados**: Todas as classes de dados (`Product`, `Vendor`, `Stock`, `User`) declaram seus atributos como `private`. O acesso a esses dados é estritamente controlado por métodos públicos (`getters` e `setters`). Isso garante a integridade dos dados e que as regras de negócio (como a validação de um CNPJ ou CEP) sejam sempre aplicadas.

### Abstração

A abstração foca em expor apenas as funcionalidades essenciais de um objeto, ocultando a complexidade interna.

* **Interface Abstrata de Menu**: A classe `MenuView` é um exemplo de abstração, definindo um "contrato" que toda classe de menu deve seguir (implementar `print_menu` e `call_menu_function`) sem se preocupar com os detalhes de cada menu específico.
* **Simplificação de Operações Complexas**: A classe `Vendor` abstrai a complexidade de fazer uma requisição web. Para o restante do sistema, verificar um CEP é tão simples quanto chamar o método `vendor->verifyCep(cep)`. Os detalhes da comunicação HTTP e do parsing da resposta da API BrasilAPI, gerenciados pela biblioteca `httplib.h`, ficam totalmente contidos dentro da classe `Vendor`.

## Autores

* Arthur Marinho
* Luís Moreira
* Vitor Mendonça
