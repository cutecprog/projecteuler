#ifndef TEST_MACROS_H
#define TEST_MACROS_H

// for TRY, CATCH, THROW macros
//#include <setjmp.h>
//jmp_buf __ex_buf__; 

#define TEST(function_call, o, a, verbose, exit_action, code)                   \
                if (o != a) {                                                   \
                        printf("! " #function_call " returned %i but expected " \
                                        "%i (error code: 0x%x)\n", o, a, code); \
                        exit_action;                                            \
                } else if (verbose) {                                           \
                        printf("~ Passed test 0x%x\n", code);                   \
                }

#define TRY     if (!setjmp(__ex_buf__))
#define CATCH   else
#define THROW   longjmp(__ex_buf__, 1)
            
#endif

