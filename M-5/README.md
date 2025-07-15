# ✅ Resumo — C++ Módulo 05: Repetition and Exceptions
## 🧩 EX00 — Bureaucrat
### Objetivo:
Criar a classe Bureaucrat, representando um funcionário com:

Um nome constante (std::string name)

Um nível/nota (int grade) entre 1 (melhor) e 150 (pior)

Regras:
Se a grade for menor que 1, lança GradeTooHighException

Se for maior que 150, lança GradeTooLowException

Métodos principais:
getName(), getGrade() — getters

incrementGrade() — diminui o número (melhora o cargo)

decrementGrade() — aumenta o número (piora o cargo)

Extra:
Sobrecarga do operador << para imprimir:
"<name>, bureaucrat grade <grade>"

Exceções personalizadas herdando de std::exception
```cpp
    class GradeTooHighException : public std::exception;
    class GradeTooLowException : public std::exception;
```

## 📄 EX01 — Form
### Objetivo:
Criar a classe Form (mais tarde será renomeada para AForm), representando um formulário que pode ser assinado.

Atributos:
name (constante)

isSigned (bool)

gradeToSign, gradeToExecute (const int)

Regras:
Grade fora dos limites: lança GradeTooHighException / GradeTooLowException

A função beSigned(Bureaucrat) altera isSigned = true se o burocrata tiver grade suficiente

Interação com Bureaucrat:
Bureaucrat::signForm(Form&) tenta assinar:

Se conseguir, imprime:
"Bob signed TaxForm"

Se falhar, imprime:
"Bob couldn't sign TaxForm because <reason>"

## 🛠️ EX02 — AForm e Formulários Concretos
### Objetivo:
Transformar Form em uma classe abstrata chamada AForm com método virtual puro execute().

Criar 3 classes concretas:

🌲 ShrubberyCreationForm

🤖 RobotomyRequestForm

🪪 PresidentialPardonForm

📌 AForm (classe base abstrata)
Herda de nada, mas usada como base

Possui:

name, isSigned, gradeToSign, gradeToExecute

Métodos:

beSigned(Bureaucrat)

execute(Bureaucrat const& executor) const = 0 ← puro

Exceções: GradeTooHighException, GradeTooLowException, FormNotSignedException

🌲 ShrubberyCreationForm
Grades: sign 145, exec 137

Ação: cria arquivo <target>_shrubbery com árvores ASCII

Usa ofstream para gravar o conteúdo

🤖 RobotomyRequestForm
Grades: sign 72, exec 45

Ação: imprime barulhos de furadeira e "robotomiza" 50% das vezes

Usa std::rand() com std::srand(time(0)) para gerar aleatoriedade

🪪 PresidentialPardonForm
Grades: sign 25, exec 5

Ação: imprime que <target> foi perdoado por Zaphod Beeblebrox

📌 Bureaucrat::executeForm(const AForm&)
Executa o formulário:
```cpp
    void Bureaucrat::executeForm(const AForm& form) const {
    try {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << name << " couldn't execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}
```
🧪 Exceções e Avaliação
Pratique:
- Testar exceções com try/catch

- Verificar mensagens claras e coerentes

- Certificar que os arquivos .hpp têm guards

- Seguir a Forma Canônica Ortodoxa:

- Construtor default

- Construtor com parâmetros

- Copy constructor

- Copy assignment

Destrutor

🧼 Dicas para a avaliação
Compile com: -Wall -Wextra -Werror -std=c++98

Não use STL ainda! (<vector>, <list>, <map>, <algorithm> etc. são proibidos)

Não use: printf, malloc, free, nem using namespace std

Use exceções corretamente, nunca deixe elas passarem silenciosamente

Documente e organize o código

Teste cada formulário com um Bureaucrat que:

Não pode assinar

Pode assinar mas não executar

Pode assinar e executar





