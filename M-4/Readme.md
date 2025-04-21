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
Polimorfismo significa "muitas formas".

Capacidade de tratar diferentes objetos derivados da mesma maneira, usando ponteiros ou referências da classe base.

Se Dog e Cat herdam de Animal, elas podem sobrescrever (override) o método makeSound() para fazer coisas diferentes:

```cpp
Animal* a = new Dog(); // comportamento de Dog via ponteiro Animal

```


### 🧙‍♀️ Funções Virtuais e Polimorfismo
É o segredo do polimorfismo verdadeiro.

Quando você declara um método como virtual na classe base, você está dizendo:

“Se alguma classe filha sobrescrever essa função, use a versão da filha, mesmo se o ponteiro for da classe base”.

Sem o virtual, o C++ usa a função da classe base, não importa quem é o objeto real.

```cpp
class Animal {
public:
    virtual void makeSound() const;
};

```
A palavra-chave virtual permite o polimorfismo dinâmico: o método chamado será o do tipo real do objeto (ex: Dog), e não o da classe base (Animal).
-- ⚠️ Isso só funciona com ponteiros ou referências da classe base.

#### 🧠 1. Por que o virtual só é relevante quando usamos ponteiros ou referências?
🔹 Porque o C++ é uma linguagem estática e compilada
Quando você faz:
```cpp
Animal a = Pig();
```
O compilador resolve tudo em tempo de compilação. Como o tipo da variável é Animal, ele chama os métodos da classe Animal, mesmo que a instância real seja Pig. Isso é chamado de binding estático.

#### 🔥 Exemplo:
```cpp
class Animal {
public:
    virtual void makeSound() {
        std::cout << "Animal sound\n";
    }
};

class Pig : public Animal {
public:
    void makeSound() override {
        std::cout << "Oink!\n";
    }
};

int main() {
    Animal a = Pig();  // Aqui acontece "slicing"
    a.makeSound();     // Vai imprimir "Animal sound"
}
```
#### 🪓 O que está acontecendo? "Slicing"
🧩 Object Slicing ("fatiamento de objeto")
Quando você faz:
```cpp
Animal a = Pig();
```
Você está dizendo: crie um objeto do tipo Animal copiando o Pig.

Mas o objeto Pig pode ter atributos e métodos extras, e como você está colocando ele dentro de uma variável do tipo Animal, o que está além do que Animal define é descartado. Ou seja, você perdeu a parte "Pig".

#### 🛠 Solução: usar ponteiros ou referências
```cpp
Animal* a = new Pig(); // Aqui não tem slicing!
a->makeSound();        // Vai imprimir "Oink!" se a função for virtual
```
Ou com referência:
```cpp
void playSound(const Animal& a) {
    a.makeSound();
}

Pig p;
playSound(p);  // Polimorfismo verdadeiro
```
#### 🧠 Porque o C++ permite conversão implícita para classe base
ex: Animal* a = new Pig();

Se Pig herda de Animal, então todo Pig é também um Animal.
Isso é o conceito de substituição de Liskov:
“Se S é subtipo de T, então objetos de tipo T podem ser substituídos por objetos de tipo S”.
Logo, isso é válido:
```cpp
Animal* a = new Pig();   // OK
Animal& a = Pig();       // OK
```
Mas o contrário não é permitido automaticamente:
```cpp
Pig* p = new Animal();   // ❌ Erro de compilação
```
Você só pode tratar um Pig como Animal, não o contrário, porque Animal pode não ter o que Pig precisa.


### 🛑 Classe Abstrata
Uma classe abstrata é aquela que não pode ser instanciada diretamente. Serve apenas como interface/base.

```cpp
class Animal {
public:
    virtual void makeSound() const = 0; // função virtual pura
};
```
Qualquer classe com ao menos uma função virtual pura é abstrata.

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
A verificação if (this != &other) evita autoatribuição.

### 💣 4. Destrutores virtuais

1. Se uma classe tem métodos virtuais, seu destrutor deve ser virtual para garantir que o destrutor da classe derivada seja chamado corretamente ao deletar via ponteiro da base.

2. Se você for deletar um objeto via ponteiro da classe base, o destrutor também precisa ser virtual, senão ele não vai chamar o destrutor da classe derivada.

```cpp
class Animal {
public:
    virtual ~Animal(); // Garante liberação correta de recursos
};
```

### 👨‍💻 Autor
Este guia foi elaborado como apoio para reforço pessoal de conceitos essenciais do C++ moderno.
