#!/bin/bash

# 🧠 Lista de entradas abrangentes para o ScalarConverter
inputs=(
    # Inteiros dentro e fora dos limites
    0 1 -1 42 -42 127 -128 128 255 256
    2147483647 -2147483648 2147483648 -2147483649

    # Floats e Doubles (valores comuns e extremos)
    3.14 -2.718 0.0001 -0.0001 1.0 1.0000001
    42.0 42.42 -42.42 0.42 .42 4.2e1 4.2e+1 4.2e-1
    1e10 -1e10 1e20 -1e20 1e38 -1e38 1e-45 -1e-45
    42.42f -42.42f 4.2e1f 4.2e-1f 1e10f -1e10f
    42.42.42 4.2ee1 4.2ff .e1

    # Pseudo-literais e especiais
    nan nanf NaN NAN inf inff +inf -inf +inff -inff
    infinity -infinity +infinity

    # Caracteres simples e imprimíveis
    a z A Z @ # $ % ^ & * ( ) [ ] { } ' " ? ! ~
    'a' 'Z' '0' ' ' '\n' '\t'  # incluindo escapes

    # Strings diversas
    "" " " "   " "hello" "42" "0.0" "42f" "4.2f"
    "abc" "nanf" "inff" "inf" "pi" "NaN"

    # Casos limite adicionais e edge cases
    9999999999999999999999999999999999999999
    -9999999999999999999999999999999999999999
    +000042 -00042 0000 0001
)

# 🌀 Loop principal
for value in "${inputs[@]}"
do
    echo "==============================================="
    echo "🧪 Testando entrada: '$value'"
    echo "==============================================="
    
    # Executa o programa e mostra a saída
    ./convert "$value"
    echo ""
    
    # Espera 5 segundos para observar o resultado
    sleep 1
done

