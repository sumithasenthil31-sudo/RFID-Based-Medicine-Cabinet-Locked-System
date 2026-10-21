#ifndef PINS_H
#define PINS_H

#include <LPC21xx.h>

/* LCD (8-bit mode) */
#define LCD_D       (0xFF << 8)    /* P0.8  - P0.15 */
#define RS          (1 << 16)      /* P0.16 */
#define E           (1 << 17)      /* P0.17 */

/* Motor driver */
#define MOTOR_IN1   (1 << 18)      /* P0.18 */
#define MOTOR_IN2   (1 << 19)      /* P0.19 */

/* LED, buzzer, switch */
#define LED         (1 << 20)      /* P0.20 (active low) */
#define BUZZER      (1 << 21)      /* P0.21 (active low) */
#define SWITCH      (1 << 22)      /* P0.22 (input)      */

#endif
