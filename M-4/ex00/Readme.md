# 🐾 C++ - Guia de Estudo: Herança, Polimorfismo, Destrutores Virtuais e Forma Ortodoxa Canônica

Este guia resume os pontos essenciais para entender o comportamento de herança e polimorfismo em C++, com foco no exercício do módulo 04.

---

## 📦 Estrutura do Exercício

- Criar uma classe base `Animal`
- Criar classes derivadas: `Dog`, `Cat`
- Cada classe tem:
  - Um atributo `type`
  - Um método `makeSound()`
  - Construtores e destrutores que imprimem mensagens diferentes
- Criar também as classes `WrongAnimal` e `WrongCat` para demonstrar a **ausência de polimorfismo**

---

## 🧠 Conceitos Importantes

### 🔹 1. Herança e Polimorfismo

```cpp
class Animal {
public:
    virtual void makeSound() const;
};

class Dog : public Animal {
public:
    void makeSound() const override;
};
```

- A palavra-chave virtual permite polimorfismo.

- override (opcional, mas recomendado) ajuda a detectar erros na sobrescrita.

📌 Uma função virtual na classe base permite que a função da classe derivada seja chamada corretamente via ponteiros ou referências da base.


### 🔹 2. Ponteiros e Polimorfismo

```cpp
Animal* a = new Dog();
a->makeSound(); // Chama Dog::makeSound() se for virtual

```

### 🔹 3. Referências e Polimorfismo

```cpp
Dog d;
Animal& a = d;
a.makeSound(); // Também funciona com virtual

```
### ⚰️ 4. Destrutores Virtuais

Por que o destrutor da base deve ser virtual?
```cpp
class Animal {
public:
    virtual ~Animal(); // Necessário!
};
```

Quando você faz:
```cpp
Animal* a = new Dog();
delete a; // Chama ~Dog() e ~Animal()
```
Se o destrutor não for virtual, o destrutor da classe derivada não será chamado → vazamento de memória e comportamento indefinido.

### 🧱 5. Construtor de Cópia e Lista de Inicialização

✅ Forma correta com lista de inicialização (mais eficiente):
```cpp
Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "[Animal] Copy constructor called\n";
}
```
- Isso inicializa diretamente o membro type

- Evita o uso desnecessário do operador de atribuição

⚠️ Sem lista de inicialização:
```cpp
Animal::Animal(const Animal& other) {
    type = other.type; // usa operador de atribuição
}
```
- O membro type é construído primeiro com valor padrão, depois recebe o valor com operator=

- Menos eficiente

### 🧼 6. Forma Ortodoxa Canônica

Inclui os seguintes métodos:
```cpp
class Animal {
public:
    Animal();                            // Construtor padrão
    Animal(const Animal& other);         // Construtor de cópia
    Animal& operator=(const Animal&);    // Operador de atribuição
    virtual ~Animal();                   // Destrutor (virtual!)
};
```
Usar essa forma garante:

Cópia segura

Atribuição correta

Destruição adequada (principalmente com ponteiros)

### ✅ Exemplo de Execução Esperada
```txt
[Animal] Constructor called
[Animal] Constructor called
[Dog] Constructor called
[Animal] Constructor called
[Cat] Constructor called
Type: Dog
Type: Cat
[Cat] Meow meow!
[Dog] Woof woof!
[Animal] makes a generic sound
[Animal] Destructor called
[Dog] Destructor called
[Animal] Destructor called
[Cat] Destructor called
[Animal] Destructor called
```
