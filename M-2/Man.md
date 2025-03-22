# Forma Canônica Ortodoxa
A Forma Canônica Ortodoxa (Orthodox Canonical Form) é um conjunto de regras que garantem que uma classe em C++ possa ser copiada, atribuída e destruída corretamente. Esse conceito é especialmente importante para classes que gerenciam recursos dinâmicos (como memória alocada com new, arquivos abertos, conexões de rede, etc.).

🔍 O que é a Forma Canônica Ortodoxa?
É uma convenção que define quatro funções especiais obrigatórias que você deve implementar quando cria uma classe que gerencia recursos. Essas funções são conhecidas como os "Big Four":

📌 Os Big Four
Construtor Padrão (Default Constructor)

Construtor de Cópia (Copy Constructor)

Operador de Atribuição por Cópia (Copy Assignment Operator)

Destrutor (Destructor)

A partir do C++11, um quinto membro é geralmente considerado essencial, especialmente se você deseja que sua classe suporte movimentação eficiente:

Movimento Semântico (Move Constructor e Move Assignment Operator) — Usados para mover recursos ao invés de copiá-los.

### ✅ Funções Essenciais e Suas Funções
1. Construtor Padrão (Fixed())
O construtor padrão é responsável por inicializar os membros da classe com valores padrão.

```
Fixed() : value(0) {
    std::cout << "Construtor padrão chamado!" << std::endl;
}
```

2. Construtor de Cópia (Fixed(const Fixed& other))
É invocado quando um novo objeto é criado a partir de um objeto existente. Deve realizar uma cópia profunda se houver recursos dinâmicos envolvidos.

```
Fixed(const Fixed& other) : value(other.value) {
    std::cout << "Construtor de cópia chamado!" << std::endl;
}
```

3. Operador de Atribuição por Cópia (Fixed& operator=(const Fixed& other))
Responsável por copiar o estado de um objeto existente para um já inicializado. Deve evitar auto-atribuição e liberar recursos antigos, se necessário.


```
Fixed& operator=(const Fixed& other) {
    std::cout << "Operador de atribuição por cópia chamado!" << std::endl;
    if (this != &other) {  // Evita auto-atribuição
        value = other.value;
    }
    return *this;
}
```

4. Destrutor (~Fixed())
Libera recursos alocados dinamicamente e executa a limpeza necessária quando um objeto é destruído.

```
~Fixed() {
    std::cout << "Destrutor chamado!" << std::endl;
}
```

5. Movimento Semântico (C++11 e Superior)
Para permitir movimentação eficiente, especialmente ao lidar com recursos dinâmicos.
Os dois operadores adicionais são:

📌 Construtor de Movimento (Fixed(Fixed&& other))
Transfere recursos de um objeto para outro, deixando o original em um estado válido, mas vazio.

```
Fixed(Fixed&& other) noexcept : value(other.value) {
    std::cout << "Construtor de movimento chamado!" << std::endl;
    other.value = 0; // Deixa o objeto original num estado válido
}
```
📌 Operador de Atribuição por Movimento (Fixed& operator=(Fixed&& other))
Libera os recursos atuais e toma posse dos recursos de outro objeto.

```
Fixed& operator=(Fixed&& other) noexcept {
    std::cout << "Operador de atribuição por movimento chamado!" << std::endl;
    if (this != &other) {
        value = other.value;
        other.value = 0; // Deixa o objeto original num estado válido
    }
    return *this;
}
```

📌 Resumo
A Forma Canônica Ortodoxa é obrigatória para garantir que sua classe funcione corretamente ao ser copiada, atribuída ou destruída.

Para classes que não gerenciam recursos dinâmicos, você geralmente pode confiar na implementação padrão do C++.

Para classes que gerenciam recursos dinâmicos, você precisa implementar explicitamente essas funções para evitar vazamentos de memória e comportamentos indesejados.


# NÚMERO DE PONTO FIXO

Um número de ponto fixo é uma representação numérica usada principalmente em sistemas embarcados e hardware que não possuem suporte eficiente para números de ponto flutuante. Ao invés de ter uma vírgula flutuante como em float ou double, o ponto fixo possui a vírgula em uma posição fixa e pré-determinada.

🔍 Como Funciona
Em um número de ponto fixo, o valor é armazenado como um inteiro, mas é interpretado como se estivesse dividido por um fator específico (geralmente uma potência de 2 ou 10). Isso permite representar números fracionários sem precisar de operações complexas como as realizadas em ponto flutuante.

Por exemplo, se escolhemos que nossos números têm 16 bits para a parte inteira e 16 bits para a parte fracionária (formato 16.16):

O valor binário 0000000000000001.0000000000000000 (em decimal: 1 << 16) representa o número 1.0.

O valor binário 0000000000000000.1000000000000000 (em decimal: 1 << 15) representa o número 0.5.

📌 Por que usar Ponto Fixo?
✅ Desempenho: As operações de ponto fixo são geralmente mais rápidas que as de ponto flutuante porque envolvem apenas operações inteiras (adição, subtração, multiplicação e, às vezes, deslocamento de bits para divisão).

✅ Determinismo: Os cálculos são mais previsíveis, o que é essencial para sistemas de tempo real.

✅ Precisão Controlada: Oferece controle sobre a precisão e alcance do número, que é útil em sistemas com recursos limitados.

📖 Exemplo em C++
Vamos dizer que queremos um sistema de ponto fixo que trabalhe com duas casas decimais (escala de 100).


## ✅ Conversão de Inteiro para Ponto Fixo
- Ao converter um número inteiro (`int`) para ponto fixo, queremos que ele seja representado como se estivesse multiplicado por um fator de escala (normalmente `256`, que é `2^8`).
- A operação usada é:
  ```cpp
  _value = intValue << _fractionalBits;  // ou
  _value = intValue * (1 << _fractionalBits);
  ```
- Exemplo:
  ```cpp
  int value = 42;
  int fixedPointValue = value << 8;  // Resultado: 10752
  ```

---

## ✅ Conversão de Float para Ponto Fixo
- Para converter um `float` para ponto fixo, multiplicamos o `float` pelo fator de escala e arredondamos o resultado.
- A operação usada é:
  ```cpp
  _value = roundf(floatValue * (1 << _fractionalBits));
  ```
- Exemplo:
  ```cpp
  float value = 42.42f;
  int fixedPointValue = roundf(value * 256);  // Resultado: 10855
  ```

---

## ✅ Implementação do Operador `<<` para `Fixed`
- O operador `<<` permite imprimir objetos da classe `Fixed` como números de ponto flutuante com `std::cout`.
- Deve ser implementado **fora da classe `Fixed`** como uma função global.

### 📌 Declaração (`Fixed.hpp`):
```cpp
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
```

### 📌 Implementação (`Fixed.cpp`):
```cpp
std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}
```

### 📌 Uso:
```cpp
Fixed a(42.42f);
std::cout << a << std::endl;  // Saída: 42.4219 (ou próximo disso)
```

---

## 📌 Resumo Final
- Inteiros são convertidos para ponto fixo usando **deslocamento (`<<`) ou multiplicação (`*`).**
- Floats são convertidos para ponto fixo multiplicando e **arredondando o resultado.**
- O operador `<<` é implementado fora da classe para permitir impressão amigável do número convertido para `float`.

