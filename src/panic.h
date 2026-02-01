/*
 * PANIC AVR - AVR Version
 *
 * Copyright (c) 2012-2026 Luc Hondareyte
 * All rights reserved.
 *
 * $Id$
 */
 
#ifndef __PANIC_H__
#define __PANIC_H__

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <stdlib.h>
#include <util/delay.h>

#if defined (__AVR_ATtiny13__) || defined (__AVR_ATtiny13a__)
#define INTMSKR         GIMSK           // Interupt mask register
#define INTRGST         MCUCR           // Interrupt register
#else
#error "Device not supported"
#endif

void rx2tx(void);
void sendMidiByte(uint8_t);

void sendMessages(void);

#define setBit(octet,bit)     ( octet |= (1<<bit))
#define clearBit(octet,bit)   ( octet &= ~(1<<bit))
#define toggleBit(octet,bit)  ( octet ^= (1<<bit))
#define enable_INT0()         setBit(INTMSKR,INT0)
#define disable_INT0()        clearBit(INTMSKR,INT0)

#endif /* __PANIC_H__ */
