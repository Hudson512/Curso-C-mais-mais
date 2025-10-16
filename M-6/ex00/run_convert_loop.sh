#!/bin/bash

num=0

# Loop de 0 até 130 (inclusive)
while [ $num -le 130 ]
do
    echo "=============================="
    echo "🔢 Testando valor: $num"
    echo "=============================="
    
    # Executa o programa e mostra saída
    ./convert $num

    # Espera 5 segundos para observar o resultado
    sleep 5

    # Incrementa o contador
    num=$((num + 1))
done
