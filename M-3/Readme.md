🔹 1. O que é uma classe em C++?
Resposta:
Uma classe é uma estrutura que encapsula dados (atributos) e comportamentos (métodos) relacionados. É usada como modelo para criar objetos. Ela permite organizar o código de forma mais modular e reutilizável.

🔹 2. O que é herança? E por que usamos herança nesse projeto?
Resposta:
Herança é um mecanismo que permite uma classe derivada herdar atributos e métodos de uma classe base. Neste projeto, usamos herança para evitar duplicação de código entre os robôs (ClapTrap, ScavTrap, FragTrap) e reaproveitar o comportamento comum, como attack(), takeDamage() e beRepaired().

🔹 3. O construtor da classe base é chamado automaticamente?
Resposta:
Sim. Quando criamos um objeto da classe derivada, o construtor da classe base é chamado automaticamente primeiro. Isso garante que a parte base do objeto esteja corretamente inicializada antes da derivada ser construída.

🔹 4. Qual a ordem de chamada dos destrutores?
Resposta:
Na destruição, a ordem é invertida: primeiro o destrutor da classe derivada, depois o destrutor da classe base. Isso é importante pra liberar recursos na ordem correta.

🔹 5. Você sobrescreveu o método attack() nas classes derivadas. Qual o objetivo disso?
Resposta:
Sobrescrevi o método attack() para personalizar o comportamento de ataque em ScavTrap e FragTrap, permitindo que cada tipo de robô tenha mensagens diferentes e, futuramente, comportamentos específicos se necessário.

🔹 6. Por que usamos this em alguns lugares?
Resposta:
Usamos this para deixar claro que estamos acessando membros da instância atual, especialmente quando o nome do parâmetro é igual ao nome do atributo. Também ajuda na legibilidade do código.

🔹 7. Qual a diferença entre public, protected e private na herança?
Resposta:

public herda os membros públicos e protegidos como estão.

protected transforma membros públicos da base em protegidos na derivada.

private faz tudo virar privado e, geralmente, é mais restritivo. Para esse projeto usamos herança public porque queremos preservar o acesso aos métodos da classe base.

🔹 8. O que faz o método guardGate()? E o highFivesGuys()?
Resposta:
São métodos exclusivos das classes ScavTrap e FragTrap, respectivamente.

guardGate() ativa o modo de sentinela, uma habilidade especial do ScavTrap.

highFivesGuys() exibe uma mensagem positiva de interação, exclusiva do FragTrap.

🔹 9. Se você tivesse que adicionar mais um tipo de robô, como faria?
Resposta:
Criaria uma nova classe que herda de ClapTrap, personalizaria os atributos e, se necessário, sobrescreveria métodos como attack(). Também adicionaria métodos exclusivos para representar habilidades novas.

🔹 10. Por que você colocou as mensagens de construção/destruição com cores?
Resposta:
Para facilitar a visualização no terminal e destacar quando a construção ou destruição de cada tipo de robô está acontecendo. Isso ajuda a entender a ordem correta de execução na herança.
