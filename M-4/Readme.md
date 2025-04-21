# 🐾 C++ - Módulo 04 - Polimorfismo, Classes Abstratas e Deep Copy

Este repositório documenta e implementa exercícios fundamentais do módulo 04 de C++ da 42, com foco em **polimorfismo**, **classes abstratas**, **funções virtuais**, **herança**, **destrutores virtuais**, **deep copies** e **gestão correta de memória dinâmica**.

---

## 🧠 Índice

1. [Conceitos Fundamentais](#conceitos-fundamentais)
2. [Funções Virtuais e Polimorfismo](#funções-virtuais-e-polimorfismo)
3. [Destrutores Virtuais](#destrutores-virtuais)
4. [Classe Abstrata](#classe-abstrata)
5. [Deep Copy vs Shallow Copy](#deep-copy-vs-shallow-copy)

---

## 📘 Conceitos Fundamentais

### 🧩 Herança
Permite que uma classe herde atributos e comportamentos de outra.  
Exemplo:

```cpp
class Animal {
protected:
    std::string type;
};

class Dog : public Animal {
    // herda 'type'
};
```

### 🔁 Polimorfismo
Capacidade de tratar diferentes objetos derivados da mesma maneira, usando ponteiros ou referências da classe base.

```cpp
Animal* a = new Dog(); // comportamento de Dog via ponteiro Animal

```


### 🧙‍♀️ Funções Virtuais e Polimorfismo

```cpp
class Animal {
public:
    virtual void makeSound() const;
};

```
A palavra-chave virtual permite o polimorfismo dinâmico: o método chamado será o do tipo real do objeto (ex: Dog), e não o da classe base (Animal).
-- ⚠️ Isso só funciona com ponteiros ou referências da classe base.


### 💣 Destrutores Virtuais
Se uma classe tem métodos virtuais, seu destrutor deve ser virtual para garantir que o destrutor da classe derivada seja chamado corretamente ao deletar via ponteiro da base.

```cpp
class Animal {
public:
    virtual ~Animal(); // Garante liberação correta de recursos
};
```

### 🛑 Classe Abstrata
Uma classe abstrata é aquela que não pode ser instanciada diretamente. Serve apenas como interface/base.

```cpp
class Animal {
public:
    virtual void makeSound() const = 0; // função virtual pura
};
```
-- Qualquer classe com ao menos uma função virtual pura é abstrata.

### 🧬 Deep Copy vs Shallow Copy

### ❌ Shallow Copy
Copia o ponteiro, mas não os dados apontados → dois objetos compartilham o mesmo recurso → pode causar double free ou comportamento indesejado.

### ✅ Deep Copy
Copia os dados apontados. Cada objeto tem sua própria cópia do recurso.
```cpp
Dog::Dog(const Dog& other) {
    brain = new Brain(*other.brain); // Deep copy
}
```
### 📎 Operador de Atribuição
```cpp
Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other); // Copia tipo
        delete brain;
        brain = new Brain(*other.brain); // Deep copy
    }
    return *this;
}
```
-- A verificação if (this != &other) evita autoatribuição.

### 👨‍💻 Autor
Este guia foi elaborado como apoio para reforço pessoal de conceitos essenciais do C++ moderno.
