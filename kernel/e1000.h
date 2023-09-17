#pragma once
#include "mbuf.h"
#include "types.h"

void e1000_tx_init();
void e1000_rx_init();
void e1000_init(uint32 *);
int e1000_send(struct mbuf *);
void e1000_recv(void);
void e1000_intr(void);