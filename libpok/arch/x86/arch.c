/*
 *                               POK header
 *
 * The following file is a part of the POK project. Any modification should
 * be made according to the POK licence. You CANNOT use this file or a part
 * of a file for your own project.
 *
 * For more information on the POK licence, please see our LICENCE FILE
 *
 * Please follow the coding guidelines described in doc/CODING_GUIDELINES
 *
 *                                      Copyright (c) 2007-2020 POK team
 */

#ifndef POK_CONFIG_OPTIMIZE_FOR_GENERATED_CODE

#include <arch.h>

void pok_arch_idle(void) {
  while (1) {
    asm("nop");
  }
}

#endif
