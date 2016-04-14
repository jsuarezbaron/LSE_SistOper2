/*************************************************************************//**

  @file     main.c.c

  @brief    EJERCICIO 1.1 - RTOS 2 OSEK

  @author   Marcos Darino (MD)

 ******************************************************************************/

/**
   Ejercicio​ 1.1
   Implementar una tarea que encienda un LED durante 500ms cada 1 seg. 
**/


/** \addtogroup FreeRTOS Ejer1.1
 ** @{ */
 


/*==================[inclusions]=============================================*/
#include "main.h"       /* <= own header */
#include "os.h"               /* <= operating system header */
#include "HW_leds.h"

#ifndef CPU
#define CPU lpc4337
#endif


#ifndef CPU
#error CPU shall be defined
#endif
#if (lpc4337 == CPU)
#include "chip.h"
#elif (mk60fx512vlq15 == CPU)
#else
#endif


/*==================[macros and definitions]=================================*/


/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/
uint8_t test=0;


int main(void)
{
   /* perform the needed initialization here */
  StartOS(AppMode1);

  
   return 0;
}


void ErrorHook(void)
{
  
   ShutdownOS(0);
}

/** \brief Initial task
 *
 * This task is started automatically in the application mode 1.
 */
TASK(InitTask)
{
   led_Init();

   /* init CIAA kernel and devices */
   SetRelAlarm(ActivatePeriodicTask, 0, 500);

   /* terminate task */
   TerminateTask();
}

/** \brief Periodic Task
 *
 * This task is started automatically every time that the alarm
 * ActivatePeriodicTask expires.
 *
 */
TASK(PeriodicTask)
{

   led_SetToggle(LED_1);  //Toggle LED 1 - Every 500mSeg
   /* terminate task */
   TerminateTask();
}

/** @} doxygen end group definition */

/*==================[end of file]============================================*/

