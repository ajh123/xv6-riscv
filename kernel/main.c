#include "types.h"
#include "param.h"
#include "memlayout.h"
#include "riscv.h"
#include "defs.h"
#include "pci.h"
#include "arp.h"
#include "tcp.h"
#include "udp.h"

volatile static int started = 0;

// start() jumps here in supervisor mode on all CPUs.
void
main()
{
  if(cpuid() == 0){
    consoleinit();
    printfinit();
    printf("\n");
    printf("xv6 kernel is booting\n");
    printf("\n");
    kinit();         // physical page allocator
    kvminit();       // create kernel page table
    kvminithart();   // turn on paging
    procinit();      // process table
    trapinit();      // trap vectors
    trapinithart();  // install kernel trap vector
    plicinit();      // set up interrupt controller
    plicinithart();  // ask PLIC for device interrupts
    binit();         // buffer cache
    iinit();         // inode table
    fileinit();      // file table
    virtio_disk_init(); // emulated hard disk
    printf("pci init\n");
    pci_init();         // pci
    printf("pci init done\n");
    printf("socket init\n");
    socket_init();      // socket
    printf("socket init done\n");
    printf("arp init\n");
    arp_init();         // arp
    printf("arp init done\n");
    printf("tcp init\n");
    tcp_init();         // tcp
    printf("tcp init done\n");
    printf("udp init\n");
    udp_init();         // udp
    printf("udp init done\n");
    printf("user init\n");
    userinit();      // first user process
    printf("user init done\n");
    __sync_synchronize();
    started = 1;
  } else {
    while(started == 0)
      ;
    __sync_synchronize();
    printf("hart %d starting\n", cpuid());
    kvminithart();    // turn on paging
    trapinithart();   // install kernel trap vector
    plicinithart();   // ask PLIC for device interrupts
  }

  scheduler();        
}
