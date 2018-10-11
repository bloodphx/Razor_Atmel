/**********************************************************************************************************************
File: user_app1.c                                                                

----------------------------------------------------------------------------------------------------------------------
To start a new task using this user_app1 as a template:
 1. Copy both user_app1.c and user_app1.h to the Application directory
 2. Rename the files yournewtaskname.c and yournewtaskname.h
 3. Add yournewtaskname.c and yournewtaskname.h to the Application Include and Source groups in the IAR project
 4. Use ctrl-h (make sure "Match Case" is checked) to find and replace all instances of "user_app1" with "yournewtaskname"
 5. Use ctrl-h to find and replace all instances of "UserApp1" with "YourNewTaskName"
 6. Use ctrl-h to find and replace all instances of "USER_APP1" with "YOUR_NEW_TASK_NAME"
 7. Add a call to YourNewTaskNameInitialize() in the init section of main
 8. Add a call to YourNewTaskNameRunActiveState() in the Super Loop section of main
 9. Update yournewtaskname.h per the instructions at the top of yournewtaskname.h
10. Delete this text (between the dashed lines) and update the Description below to describe your task
----------------------------------------------------------------------------------------------------------------------

Description:
This is a user_app1.c file template 

------------------------------------------------------------------------------------------------------------------------
API:

Public functions:


Protected System functions:
void UserApp1Initialize(void)
Runs required initialzation for the task.  Should only be called once in main init section.

void UserApp1RunActiveState(void)
Runs current task state.  Should only be called once in main loop.


**********************************************************************************************************************/

#include "configuration.h"

/***********************************************************************************************************************
Global variable definitions with scope across entire project.
All Global variable names shall start with "G_UserApp1"
***********************************************************************************************************************/
/* New variables */
volatile u32 G_u32UserApp1Flags;                       /* Global state flags */


/*--------------------------------------------------------------------------------------------------------------------*/
/* Existing variables (defined in other files -- should all contain the "extern" keyword) */
extern volatile u32 G_u32SystemFlags;                  /* From main.c */
extern volatile u32 G_u32ApplicationFlags;             /* From main.c */

extern volatile u32 G_u32SystemTime1ms;                /* From board-specific source file */
extern volatile u32 G_u32SystemTime1s;                 /* From board-specific source file */
int u16BlinkCount;

/***********************************************************************************************************************
Global variable definitions with scope limited to this local application.
Variable names shall start with "UserApp1_" and be declared as static.
***********************************************************************************************************************/
static fnCode_type UserApp1_StateMachine;            /* The state machine function pointer */
//static u32 UserApp1_u32Timeout;                      /* Timeout counter used across states */


/**********************************************************************************************************************
Function Definitions
**********************************************************************************************************************/

/*--------------------------------------------------------------------------------------------------------------------*/
/* Public functions                                                                                                   */
/*--------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------*/
/* Protected functions                                                                                                */
/*--------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
Function: UserApp1Initialize

Description:
Initializes the State Machine and its variables.

Requires:
  -

Promises:
  - 
*/
void UserApp1Initialize(void)
{
 
  /* If good initialization, set state to Idle */
  if( 1 )
  {
    UserApp1_StateMachine = UserApp1SM_Idle;
  }
  else
  {
    /* The task isn't properly initialized, so shut it down and don't run */
    UserApp1_StateMachine = UserApp1SM_Error;
  }

} /* end UserApp1Initialize() */

  
/*----------------------------------------------------------------------------------------------------------------------
Function UserApp1RunActiveState()

Description:
Selects and runs one iteration of the current state in the state machine.
All state machines have a TOTAL of 1ms to execute, so on average n state machines
may take 1ms / n to execute.

Requires:
  - State machine function pointer points at current state

Promises:
  - Calls the function to pointed by the state machine function pointer
*/
void UserApp1RunActiveState(void)
{
   LedOff(WHITE);
   LedOff(PURPLE);
   LedOff(BLUE);
   LedOff(CYAN);
   LedOff(GREEN);
   LedOff(YELLOW);
   LedOff(ORANGE);
   LedOff(RED);
   while(1)
   {
     u16BlinkCount++;
     if(u16BlinkCount>=0 && u16BlinkCount<20000)
     {
       LedPWM(WHITE, LED_PWM_100);
       LedOn(WHITE);
       LedOff(RED);
     }
     if(u16BlinkCount >= 20000&& u16BlinkCount<=35000)
     {
       LedPWM(PURPLE, LED_PWM_80);
       LedOff(WHITE);
       LedOn(PURPLE);
     }  
     if(u16BlinkCount >= 35000 && u16BlinkCount<=45000 )
     {
       LedPWM(BLUE, LED_PWM_70);
       LedOff(PURPLE);
       LedOn(BLUE);
     }  
     
     if(u16BlinkCount >= 45000 && u16BlinkCount<=53000 )
     {
       LedPWM(CYAN, LED_PWM_60);
       LedOff(BLUE);
       LedOn(CYAN);
     } 
     if(u16BlinkCount >= 53000 && u16BlinkCount<=60000)
     {
       LedPWM(GREEN, LED_PWM_50);
       LedOff(CYAN);
       LedOn(GREEN);
     } 
     if(u16BlinkCount >= 60000 && u16BlinkCount<=66000)
     {
       LedPWM(YELLOW, LED_PWM_40);
       LedOff(GREEN);
       LedOn(YELLOW);
     } 
     if(u16BlinkCount >= 66000 && u16BlinkCount<=70000)
     {
       LedPWM(ORANGE, LED_PWM_30);
       LedOff(YELLOW);
       LedOn(ORANGE);
     }
     if(u16BlinkCount >= 70000 &&  u16BlinkCount<=72000)
     {
       LedPWM(RED, LED_PWM_20);
       LedOff(ORANGE);
       LedOn(RED);
       u16BlinkCount=0;
     }
   }
  UserApp1_StateMachine();

} /* end UserApp1RunActiveState */


/*--------------------------------------------------------------------------------------------------------------------*/
/* Private functions                                                                                                  */
/*--------------------------------------------------------------------------------------------------------------------*/


/**********************************************************************************************************************
State Machine Function Definitions
**********************************************************************************************************************/

/*-------------------------------------------------------------------------------------------------------------------*/
/* Wait for ??? */
static void UserApp1SM_Idle(void)
{

} /* end UserApp1SM_Idle() */
    

/*-------------------------------------------------------------------------------------------------------------------*/
/* Handle an error */
static void UserApp1SM_Error(void)          
{  

} /* end UserApp1SM_Error() */





/*--------------------------------------------------------------------------------------------------------------------*/
/* End of File                                                                                                        */
/*--------------------------------------------------------------------------------------------------------------------*/


