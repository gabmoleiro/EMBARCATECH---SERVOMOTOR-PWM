#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h" 

// Definições do PWM
#define PWM_PIN     22           // Pino GPIO para o PWM do servo
#define LED_PIN     12           // Pino GPIO para o LED RGB (BitDogLab)
#define PWM_FREQ    50           // Frequência do PWM em Hz
#define CLOCK_DIV   25           // Divisor de clock para atingir ~50Hz
#define PWM_WRAP    100000       // Contador PWM para 50Hz: (125 MHz / (50 Hz * 25))

// Ciclos de trabalho (Duty Cycle) para controle do servo
#define SERVO_180   12000        // 2.400μs (0,12% do ciclo) -> 180 graus
#define SERVO_90    7350         // 1.470μs (0,0735% do ciclo) -> 90 graus
#define SERVO_0     2500         // 500μs (0,025% do ciclo) -> 0 graus

// Movimentação suave
#define STEP_SIZE   5            // Incremento do PWM em 5μs (~0,005% do ciclo)
#define STEP_DELAY  10           // Tempo entre incrementos (ms)

void set_servo_position(uint slice, uint16_t level) {
    pwm_set_gpio_level(PWM_PIN, level); 
}

int main() {
    stdio_init_all();  // Inicializa a comunicação serial

    // Configuração dos pinos
    gpio_set_function(PWM_PIN, GPIO_FUNC_PWM);   // Configura o PWM no GPIO 22
    gpio_init(LED_PIN);                          // Inicializa GPIO 12 para LED
    gpio_set_dir(LED_PIN, GPIO_OUT);             // Configura LED como saída

    uint slice = pwm_gpio_to_slice_num(PWM_PIN);

    // Configuração do PWM para ~50Hz
    pwm_set_clkdiv(slice, CLOCK_DIV);
    pwm_set_wrap(slice, PWM_WRAP);
    pwm_set_enabled(slice, true);

    // Movimento inicial do servo
    set_servo_position(slice, SERVO_180);
    gpio_put(LED_PIN, 1);  // Acende o LED
    sleep_ms(5000);

    set_servo_position(slice, SERVO_90);
    gpio_put(LED_PIN, 0);  // Apaga o LED
    sleep_ms(5000);

    set_servo_position(slice, SERVO_0);
    gpio_put(LED_PIN, 1);  // Acende o LED novamente
    sleep_ms(5000);

    // Movimentação periódica entre 0° e 180°
    uint16_t position = SERVO_0;
    bool increasing = true;

    while (true) {
        position += (increasing ? STEP_SIZE : -STEP_SIZE);
        set_servo_position(slice, position);
        
        // Inverte direção ao atingir os limites
        if (position <= SERVO_0 || position >= SERVO_180) {
            increasing = !increasing;
            gpio_put(LED_PIN, increasing);  // Alterna o estado do LED ao inverter direção
        }

        sleep_ms(STEP_DELAY);
    }
}
