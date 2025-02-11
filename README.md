Controle de Servomotor por PWM com Raspberry Pi Pico W

Este repositório contém a implementação de um sistema de controle de um servomotor utilizando PWM no microcontrolador Raspberry Pi Pico W, programado em C com o Pico SDK. O sistema simula o controle do ângulo do servomotor, ajustando suas posições para 0°, 90° e 180°, e realiza um movimento suave entre esses ângulos. Além disso, um LED RGB é controlado para indicar o movimento do servomotor.
Requisitos

Para executar este projeto, é necessário:

    Raspberry Pi Pico W (ou simulação no Wokwi)
    Servomotor padrão (micro servo, simulado no Wokwi)
    LED RGB (GPIO 12)
    Ambiente de desenvolvimento configurado com:
        VS Code
        Pico SDK
        Simulador Wokwi

Configuração do Hardware

Os componentes devem ser conectados aos GPIOs da Raspberry Pi Pico W da seguinte forma:
Componente	GPIO
Servomotor	22
LED RGB	12
Instalação e Execução

Clone este repositório:

git clone https://github.com/gabmoleiro/EMBARCATECH---SERVOMOTOR-PWM.git
cd EMBARCATECH---SERVOMOTOR-PWM

Configure o ambiente de desenvolvimento:

    Instale o Pico SDK.
    Configure o VS Code para compilar códigos C para o Raspberry Pi Pico.
    Integre o simulador Wokwi ao VS Code.

Funcionamento

    O servomotor é movido para 180° (ciclo ativo de 2.400μs) e mantém essa posição por 5 segundos.
    O servomotor é movido para 90° (ciclo ativo de 1.470μs) e mantém essa posição por 5 segundos.
    O servomotor é movido para 0° (ciclo ativo de 500μs) e mantém essa posição por 5 segundos.
    O servomotor se move suavemente entre 0° e 180° com incrementos de ±5μs e atraso de 10ms.
    O LED RGB é acionado para indicar o movimento do servomotor

Conclusão

Este projeto demonstra o controle preciso de um servomotor utilizando o Raspberry Pi Pico e o módulo PWM, além de integrar o controle de um LED RGB para observação dos resultados.