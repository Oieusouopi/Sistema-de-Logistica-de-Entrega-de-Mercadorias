# Sistema de Logística de Entrega de Mercadorias (SLEM)

## Descrição

O objetivo deste trabalho é desenvolver um Sistema de Logística de Entrega de Mercadorias
utilizando os conceitos de algoritmos e estruturas de dados aprendidos na disciplina de
Algoritmos e Estruturas de Dados I. O sistema deverá simular o gerenciamento de pedidos,
veículos e locais, com foco na manipulação eficiente de dados e na implementação de um
algoritmo de roteamento básico.

## Requisitos

1 - Cadastros dos locais:

ex:
```sh
classe Local {
  nome: string - (identificador único)
  int x: coordenada x;
  int y: coordenada y;
}
Operação do serviço {
  void criar() -> Operação para cadastrar um local 
  std::vector<Local> listar() -> Operação para listar todos os locais
  void excluir(string nome) -> Operação para excluir um local
}
```

2 - Cadastro de Veículos:

ex:
```sh
classe Veiculo {
  placa: string - (identificador único)
  modelo: string
  status: booleano
  localAtual: Local
}
Operação do serviço {
  criar() -> Operação para cadastrar um veiculo
  listar() -> Operação para listar todos os veiculos
  excluir(string placa) -> Operação para excluir um veiculo
  updateStatus(string placa, booleano status) -> Operação para atualizar o status
  updateLocalAtual(string placa, Local local) -> Operação para atualizar o local atual do véiculo
}
```

3 - Cadastro de Pedidos:

ex:
```sh
classe Pedido {
  id: inteiro - (identificador único)
  localDeOrigem: Local
  destino: Local
  pesoDoItem: float
}
Operações do serviço {
  criar() -> Operacao para cadastrar um pedido
  listar() -> Operação para lsitar todos os pedidos
  update(int id) -> Atualizar atributo do pedido
  excluir(int id) -> Excluir atributo do pedido
```
4. Cálculo e Exibição de Rota de Entrega:
  ○ Dado um Pedido pendente, o sistema deve calcular e mostrar a rota de entrega
  a partir do veículo disponível mais próximo do local de origem do pedido.
  ○ A distância entre dois locais (cidades, pontos de entrega, etc.) será calculada
  utilizando a distância euclidiana entre suas coordenadas (X, Y).
  ○ A rota deve indicar o veículo selecionado, o local de origem do pedido, o local de
  destino do pedido e a distância total percorrida.


## Arquietura
 Vamos desenvolver uma arquitetura MSC (Model, Service, Controller)

### Explicação dessa arquitetura:
  Essa arquitetura e feito por camadas (Controller,Service,Model) onde cada camada tem suas responsabilidades o que torna o desenvolvimento mais granular, maior facilidade na manutenibilidade pois alterar uma camada raramente altera a outra, testabilidade, reutilização do código (Services podem ser reutilizados em outros Services o que evita a duplicação da lógica). 
  
  O que cada camada faz:
    Model: Gerencia dados e regras de negocio (Seria a camada mais interna mais proxima das entidades e do dado real)
    Service: Gerencia a lógica,negocios e operações na aplicação (Seria a camada que faz a comunicação entre as duas a Controller e a Model)
    Controller: Gerencia as requisições feitas pelo usuário (Seria a camada mais externa mais próxima do usuário)

```
.
├──src
│  ├──Tests
│  │  ├──Service
│  │  │  ├──PedidoServiceTest.cpp
│  │  │  ├──LocalServiceTest.cpp
│  │  │  ├──VeiculoServiceTest.cpp
│  │  │  └──RotaServiceTest.cpp
│  │  ├──Controller
│  │  │  ├──PedidoControllerTest.cpp
│  │  │  ├──LocalControllerTest.cpp
│  │  │  └──RotaControllerTest.cpp
│  ├──Utils
│  │  ├──ExibirMensagem.cpp --> Implementações das mensagens
│  │  ├──ExibirMensagm.h --> Cabeçalho para exibir mensagem
│  │  ├──EnumStatusVeiculoUtils.cpp --> Enum utils para veiculo
│  │  ├──EnumStatusVeiculoUtils.h
│  │  ├──EnumUtils.h
│  │  ├──inputUtils.h
│  │  ├──LocalUtils.cpp
│  │  ├──LocalUtils.h
│  │  ├──VeiculoUtils.cpp
│  │  ├──VeiculoUtils.h
│  │  └──EnumMenu.h
│  ├──Storage --> Aqui vão ser armazenado os arquivos bin
│  │  ├──pedidos.bin
│  │  ├──locais.bin
│  │  └──veiculos.bin
│  ├──Repository --> Camada para manusear os dados
│  │  ├─LocalRepository.cpp
│  │  ├─LocalRepository.h
│  │  ├─VeiculoRepository.cpp
│  │  ├─VeiculoRepository.h
│  │  ├─PedidoRepository.cpp
│  │  └──PedidoRepository.h
│  ├──Controller --> Camada para a requisição e resposta para o usuário camada mais externa
│  │  ├──PedidoController.cpp --> Implementação
│  │  ├──PedidoController.h --> Declaração
│  │  ├──LocalController.cpp
│  │  ├──LocalController.h
│  │  ├──VeiculoController.cpp
│  │  ├──VeiculoController.h
│  │  ├──RotaController.cpp
│  │  └──RotaController.h
│  ├──Service --> Criação das tabelas
│  │  ├──PedidoService.cpp --> Implementação
│  │  ├──PedidoService.h --> Declaração
│  │  ├──LocalService.cpp
│  │  ├──LocalService.h
│  │  ├──VeiculoService.cpp
│  │  ├──VeiculoService.h
│  │  └──RotaService.cpp 
│  ├──Model --> Camada de como deve ser as entidades
│  │  ├──Pedido.h Classe Pedido
│  │  ├──Local.h --> Classe Local
│  │  └──Veiculo.h --> classe Veiculo
│  ├──App.cpp --> Instanciar os metodos e injeções de dependência
│  ├──App.h --> Cabeçalho das instâncias
│  └──main.cpp --> Arquivo onde começa a aplicação pode ser somente a lógica do menu
└──README.MD
```
  
## Fluxo

![fluxo projeto](./fluxo_aeds_trabalho.png)<br/>
