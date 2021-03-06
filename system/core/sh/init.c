

#include "shell.h"
#include "mystring.h"
#include "init.h"
#include "eval.h"
#include <stdio.h>
#include "input.h"
#include "error.h"
#include <stdlib.h>
#include "options.h"
#include "redir.h"
#include <signal.h>
#include "trap.h"
#include "output.h"
#include "memalloc.h"
#include "var.h"



#undef  ATABSIZE
#define ATABSIZE 39
#undef  YYBISON
#define YYBISON 1
#undef  YYSKELETON_NAME
#define YYSKELETON_NAME "yacc.c"
#undef  YYPURE
#define YYPURE 0
#undef  YYLSP_NEEDED
#define YYLSP_NEEDED 0
#undef  ARITH_NUM
#define ARITH_NUM 258
#undef  ARITH_LPAREN
#define ARITH_LPAREN 259
#undef  ARITH_RPAREN
#define ARITH_RPAREN 260
#undef  ARITH_OR
#define ARITH_OR 261
#undef  ARITH_AND
#define ARITH_AND 262
#undef  ARITH_BOR
#define ARITH_BOR 263
#undef  ARITH_BXOR
#define ARITH_BXOR 264
#undef  ARITH_BAND
#define ARITH_BAND 265
#undef  ARITH_NE
#define ARITH_NE 266
#undef  ARITH_EQ
#define ARITH_EQ 267
#undef  ARITH_LE
#define ARITH_LE 268
#undef  ARITH_GE
#define ARITH_GE 269
#undef  ARITH_GT
#define ARITH_GT 270
#undef  ARITH_LT
#define ARITH_LT 271
#undef  ARITH_RSHIFT
#define ARITH_RSHIFT 272
#undef  ARITH_LSHIFT
#define ARITH_LSHIFT 273
#undef  ARITH_SUB
#define ARITH_SUB 274
#undef  ARITH_ADD
#define ARITH_ADD 275
#undef  ARITH_REM
#define ARITH_REM 276
#undef  ARITH_DIV
#define ARITH_DIV 277
#undef  ARITH_MUL
#define ARITH_MUL 278
#undef  ARITH_BNOT
#define ARITH_BNOT 279
#undef  ARITH_NOT
#define ARITH_NOT 280
#undef  ARITH_UNARYPLUS
#define ARITH_UNARYPLUS 281
#undef  ARITH_UNARYMINUS
#define ARITH_UNARYMINUS 282
#undef  YYFINAL
#define YYFINAL  14
#undef  YYLAST
#define YYLAST   170
#undef  YYNTOKENS
#define YYNTOKENS  28
#undef  YYNNTS
#define YYNNTS  3
#undef  YYNRULES
#define YYNRULES  26
#undef  YYNSTATES
#define YYNSTATES  52
#undef  YYUNDEFTOK
#define YYUNDEFTOK  2
#undef  YYMAXUTOK
#define YYMAXUTOK   282
#undef  YYPACT_NINF
#define YYPACT_NINF -13
#undef  YYTABLE_NINF
#define YYTABLE_NINF -1
#undef  yyerrok
#define yyerrok		(yyerrstatus = 0)
#undef  yyclearin
#define yyclearin	(yychar = YYEMPTY)
#undef  YYEMPTY
#define YYEMPTY		(-2)
#undef  YYEOF
#define YYEOF		0
#undef  YYACCEPT
#define YYACCEPT	goto yyacceptlab
#undef  YYABORT
#define YYABORT		goto yyabortlab
#undef  YYERROR
#define YYERROR		goto yyerrorlab
#undef  YYFAIL
#define YYFAIL		goto yyerrlab
#undef  YYTERROR
#define YYTERROR	1
#undef  YYERRCODE
#define YYERRCODE	256
#undef  YYPOPSTACK
#define YYPOPSTACK   (yyvsp--, yyssp--)
#undef  YY_INT_ALIGNED
#define  YY_INT_ALIGNED short int
#undef  FLEX_SCANNER
#define FLEX_SCANNER
#undef  YY_FLEX_MAJOR_VERSION
#define YY_FLEX_MAJOR_VERSION 2
#undef  YY_FLEX_MINOR_VERSION
#define YY_FLEX_MINOR_VERSION 5
#undef  YY_FLEX_SUBMINOR_VERSION
#define YY_FLEX_SUBMINOR_VERSION 31
#undef  FLEX_BETA
#define FLEX_BETA
#undef  FLEXINT_H
#define FLEXINT_H
#undef  INT8_MIN
#define INT8_MIN               (-128)
#undef  INT16_MIN
#define INT16_MIN              (-32767-1)
#undef  INT32_MIN
#define INT32_MIN              (-2147483647-1)
#undef  INT8_MAX
#define INT8_MAX               (127)
#undef  INT16_MAX
#define INT16_MAX              (32767)
#undef  INT32_MAX
#define INT32_MAX              (2147483647)
#undef  UINT8_MAX
#define UINT8_MAX              (255U)
#undef  UINT16_MAX
#define UINT16_MAX             (65535U)
#undef  UINT32_MAX
#define UINT32_MAX             (4294967295U)
#undef  YY_USE_CONST
#define YY_USE_CONST
#undef  YY_USE_CONST
#define YY_USE_CONST
#undef  yyconst
#define yyconst const
#undef  yyconst
#define yyconst
#undef  YY_NULL
#define YY_NULL 0
#undef  BEGIN
#define BEGIN (yy_start) = 1 + 2 *
#undef  YY_START
#define YY_START (((yy_start) - 1) / 2)
#undef  YYSTATE
#define YYSTATE YY_START
#undef  YY_NEW_FILE
#define YY_NEW_FILE yyrestart(yyin  )
#undef  YY_END_OF_BUFFER_CHAR
#define YY_END_OF_BUFFER_CHAR 0
#undef  YY_BUF_SIZE
#define YY_BUF_SIZE 16384
#undef  YY_TYPEDEF_YY_BUFFER_STATE
#define YY_TYPEDEF_YY_BUFFER_STATE
#undef  EOB_ACT_CONTINUE_SCAN
#define EOB_ACT_CONTINUE_SCAN 0
#undef  EOB_ACT_END_OF_FILE
#define EOB_ACT_END_OF_FILE 1
#undef  EOB_ACT_LAST_MATCH
#define EOB_ACT_LAST_MATCH 2
#undef  YY_TYPEDEF_YY_SIZE_T
#define YY_TYPEDEF_YY_SIZE_T
#undef  YY_STRUCT_YY_BUFFER_STATE
#define YY_STRUCT_YY_BUFFER_STATE
#undef  YY_BUFFER_NEW
#define YY_BUFFER_NEW 0
#undef  YY_BUFFER_NORMAL
#define YY_BUFFER_NORMAL 1
#undef  YY_BUFFER_EOF_PENDING
#define YY_BUFFER_EOF_PENDING 2
#undef  YY_CURRENT_BUFFER
#define YY_CURRENT_BUFFER ( (yy_buffer_stack) \
#undef  YY_CURRENT_BUFFER_LVALUE
#define YY_CURRENT_BUFFER_LVALUE (yy_buffer_stack)[(yy_buffer_stack_top)]
#undef  YY_FLUSH_BUFFER
#define YY_FLUSH_BUFFER yy_flush_buffer(YY_CURRENT_BUFFER )
#undef  yy_new_buffer
#define yy_new_buffer yy_create_buffer
#undef  YY_SKIP_YYWRAP
#define YY_SKIP_YYWRAP
#undef  yytext_ptr
#define yytext_ptr yytext
#undef  YY_DO_BEFORE_ACTION
#define YY_DO_BEFORE_ACTION \
#undef  YY_NUM_RULES
#define YY_NUM_RULES 29
#undef  YY_END_OF_BUFFER
#define YY_END_OF_BUFFER 30
#undef  REJECT
#define REJECT reject_used_but_not_detected
#undef  YY_MORE_ADJ
#define YY_MORE_ADJ 0
#undef  YY_RESTORE_YY_MORE_OFFSET
#define YY_RESTORE_YY_MORE_OFFSET
#undef  YY_NO_UNPUT
#define YY_NO_UNPUT
#undef  INITIAL
#define INITIAL 0
#undef  YY_EXTRA_TYPE
#define YY_EXTRA_TYPE void *
#undef  YY_READ_BUF_SIZE
#define YY_READ_BUF_SIZE 8192
#undef  ECHO
#define ECHO (void) fwrite( yytext, yyleng, 1, yyout )
#undef  YY_START_STACK_INCR
#define YY_START_STACK_INCR 25
#undef  YY_DECL_IS_OURS
#define YY_DECL_IS_OURS 1
#undef  YY_DECL
#define YY_DECL int yylex (void)
#undef  YY_USER_ACTION
#define YY_USER_ACTION
#undef  YY_BREAK
#define YY_BREAK break;
#undef  YY_RULE_SETUP
#define YY_RULE_SETUP \
#undef  YY_EXIT_FAILURE
#define YY_EXIT_FAILURE 2
#undef  YYTABLES_NAME
#define YYTABLES_NAME "yytables"
#undef  MAXPWD
#define MAXPWD 256
#undef  signal
#define signal bsd_signal
#undef  ALL
#define ALL (E_OPEN|E_CREAT|E_EXEC)
#undef  EV_EXIT
#define EV_EXIT 01		/* exit after evaluating tree */
#undef  EV_TESTED
#define EV_TESTED 02		/* exit status is checked; ignore -e flag */
#undef  EV_BACKCMD
#define EV_BACKCMD 04		/* command executing within back quotes */
#undef  CMDTABLESIZE
#define CMDTABLESIZE 31		/* should be prime */
#undef  ARB
#define ARB 1			/* actual size determined at run time */
#undef  NEWARGS
#define NEWARGS 5
#undef  EOF_NLEFT
#define EOF_NLEFT -99		/* value of parsenleft when EOF pushed back */
#undef  _PATH_DEVNULL
#define _PATH_DEVNULL "/dev/null"
#undef  PROFILE
#define PROFILE 0
#undef  SIGSSIZE
#define SIGSSIZE (sizeof(sigs)/sizeof(sigs[0]))
#undef  MINSIZE
#define MINSIZE 504		/* minimum size of a block */
#undef  DEFINE_OPTIONS
#define DEFINE_OPTIONS
#undef  EOFMARKLEN
#define EOFMARKLEN 79
#undef  OPENBRACE
#define OPENBRACE '{'
#undef  CLOSEBRACE
#define CLOSEBRACE '}'
#undef  EMPTY
#define EMPTY -2		/* marks an unused slot in redirtab */
#undef  signal
#define signal bsd_signal
#undef  sys_signame
#define sys_signame sys_siglist
#undef  S_DFL
#define S_DFL 1			/* default signal handling (SIG_DFL) */
#undef  S_CATCH
#define S_CATCH 2		/* signal is caught */
#undef  S_IGN
#define S_IGN 3			/* signal is ignored (SIG_IGN) */
#undef  S_HARD_IGN
#define S_HARD_IGN 4		/* signal is ignored permenantly */
#undef  S_RESET
#define S_RESET 5		/* temporary - to reset a hard ignored sig */
#undef  OUTBUFSIZ
#define OUTBUFSIZ BUFSIZ
#undef  BLOCK_OUT
#define BLOCK_OUT -2		/* output to a fixed block of memory */
#undef  MEM_OUT
#define MEM_OUT -3		/* output to dynamically allocated memory */
#undef  OUTPUT_ERR
#define OUTPUT_ERR 01		/* error occurred on output */
#undef  TEMPSIZE
#define TEMPSIZE 24
#undef  HAVE_VASPRINTF
#define HAVE_VASPRINTF 1
#undef  VTABSIZE
#define VTABSIZE 39
#undef  VTABSIZE
#define VTABSIZE 517
#undef  ATABSIZE
#define ATABSIZE 39
#undef  YYBISON
#define YYBISON 1
#undef  YYSKELETON_NAME
#define YYSKELETON_NAME "yacc.c"
#undef  YYPURE
#define YYPURE 0
#undef  YYLSP_NEEDED
#define YYLSP_NEEDED 0
#undef  ARITH_NUM
#define ARITH_NUM 258
#undef  ARITH_LPAREN
#define ARITH_LPAREN 259
#undef  ARITH_RPAREN
#define ARITH_RPAREN 260
#undef  ARITH_OR
#define ARITH_OR 261
#undef  ARITH_AND
#define ARITH_AND 262
#undef  ARITH_BOR
#define ARITH_BOR 263
#undef  ARITH_BXOR
#define ARITH_BXOR 264
#undef  ARITH_BAND
#define ARITH_BAND 265
#undef  ARITH_NE
#define ARITH_NE 266
#undef  ARITH_EQ
#define ARITH_EQ 267
#undef  ARITH_LE
#define ARITH_LE 268
#undef  ARITH_GE
#define ARITH_GE 269
#undef  ARITH_GT
#define ARITH_GT 270
#undef  ARITH_LT
#define ARITH_LT 271
#undef  ARITH_RSHIFT
#define ARITH_RSHIFT 272
#undef  ARITH_LSHIFT
#define ARITH_LSHIFT 273
#undef  ARITH_SUB
#define ARITH_SUB 274
#undef  ARITH_ADD
#define ARITH_ADD 275
#undef  ARITH_REM
#define ARITH_REM 276
#undef  ARITH_DIV
#define ARITH_DIV 277
#undef  ARITH_MUL
#define ARITH_MUL 278
#undef  ARITH_BNOT
#define ARITH_BNOT 279
#undef  ARITH_NOT
#define ARITH_NOT 280
#undef  ARITH_UNARYPLUS
#define ARITH_UNARYPLUS 281
#undef  ARITH_UNARYMINUS
#define ARITH_UNARYMINUS 282
#undef  YYFINAL
#define YYFINAL  14
#undef  YYLAST
#define YYLAST   170
#undef  YYNTOKENS
#define YYNTOKENS  28
#undef  YYNNTS
#define YYNNTS  3
#undef  YYNRULES
#define YYNRULES  26
#undef  YYNSTATES
#define YYNSTATES  52
#undef  YYUNDEFTOK
#define YYUNDEFTOK  2
#undef  YYMAXUTOK
#define YYMAXUTOK   282
#undef  YYPACT_NINF
#define YYPACT_NINF -13
#undef  YYTABLE_NINF
#define YYTABLE_NINF -1
#undef  yyerrok
#define yyerrok		(yyerrstatus = 0)
#undef  yyclearin
#define yyclearin	(yychar = YYEMPTY)
#undef  YYEMPTY
#define YYEMPTY		(-2)
#undef  YYEOF
#define YYEOF		0
#undef  YYACCEPT
#define YYACCEPT	goto yyacceptlab
#undef  YYABORT
#define YYABORT		goto yyabortlab
#undef  YYERROR
#define YYERROR		goto yyerrorlab
#undef  YYFAIL
#define YYFAIL		goto yyerrlab
#undef  YYTERROR
#define YYTERROR	1
#undef  YYERRCODE
#define YYERRCODE	256
#undef  YYPOPSTACK
#define YYPOPSTACK   (yyvsp--, yyssp--)
#undef  YY_INT_ALIGNED
#define  YY_INT_ALIGNED short int
#undef  FLEX_SCANNER
#define FLEX_SCANNER
#undef  YY_FLEX_MAJOR_VERSION
#define YY_FLEX_MAJOR_VERSION 2
#undef  YY_FLEX_MINOR_VERSION
#define YY_FLEX_MINOR_VERSION 5
#undef  YY_FLEX_SUBMINOR_VERSION
#define YY_FLEX_SUBMINOR_VERSION 31
#undef  FLEX_BETA
#define FLEX_BETA
#undef  FLEXINT_H
#define FLEXINT_H
#undef  INT8_MIN
#define INT8_MIN               (-128)
#undef  INT16_MIN
#define INT16_MIN              (-32767-1)
#undef  INT32_MIN
#define INT32_MIN              (-2147483647-1)
#undef  INT8_MAX
#define INT8_MAX               (127)
#undef  INT16_MAX
#define INT16_MAX              (32767)
#undef  INT32_MAX
#define INT32_MAX              (2147483647)
#undef  UINT8_MAX
#define UINT8_MAX              (255U)
#undef  UINT16_MAX
#define UINT16_MAX             (65535U)
#undef  UINT32_MAX
#define UINT32_MAX             (4294967295U)
#undef  YY_USE_CONST
#define YY_USE_CONST
#undef  YY_USE_CONST
#define YY_USE_CONST
#undef  yyconst
#define yyconst const
#undef  yyconst
#define yyconst
#undef  YY_NULL
#define YY_NULL 0
#undef  BEGIN
#define BEGIN (yy_start) = 1 + 2 *
#undef  YY_START
#define YY_START (((yy_start) - 1) / 2)
#undef  YYSTATE
#define YYSTATE YY_START
#undef  YY_NEW_FILE
#define YY_NEW_FILE yyrestart(yyin  )
#undef  YY_END_OF_BUFFER_CHAR
#define YY_END_OF_BUFFER_CHAR 0
#undef  YY_BUF_SIZE
#define YY_BUF_SIZE 16384
#undef  YY_TYPEDEF_YY_BUFFER_STATE
#define YY_TYPEDEF_YY_BUFFER_STATE
#undef  EOB_ACT_CONTINUE_SCAN
#define EOB_ACT_CONTINUE_SCAN 0
#undef  EOB_ACT_END_OF_FILE
#define EOB_ACT_END_OF_FILE 1
#undef  EOB_ACT_LAST_MATCH
#define EOB_ACT_LAST_MATCH 2
#undef  YY_TYPEDEF_YY_SIZE_T
#define YY_TYPEDEF_YY_SIZE_T
#undef  YY_STRUCT_YY_BUFFER_STATE
#define YY_STRUCT_YY_BUFFER_STATE
#undef  YY_BUFFER_NEW
#define YY_BUFFER_NEW 0
#undef  YY_BUFFER_NORMAL
#define YY_BUFFER_NORMAL 1
#undef  YY_BUFFER_EOF_PENDING
#define YY_BUFFER_EOF_PENDING 2
#undef  YY_CURRENT_BUFFER
#define YY_CURRENT_BUFFER ( (yy_buffer_stack) \
#undef  YY_CURRENT_BUFFER_LVALUE
#define YY_CURRENT_BUFFER_LVALUE (yy_buffer_stack)[(yy_buffer_stack_top)]
#undef  YY_FLUSH_BUFFER
#define YY_FLUSH_BUFFER yy_flush_buffer(YY_CURRENT_BUFFER )
#undef  yy_new_buffer
#define yy_new_buffer yy_create_buffer
#undef  YY_SKIP_YYWRAP
#define YY_SKIP_YYWRAP
#undef  yytext_ptr
#define yytext_ptr yytext
#undef  YY_DO_BEFORE_ACTION
#define YY_DO_BEFORE_ACTION \
#undef  YY_NUM_RULES
#define YY_NUM_RULES 29
#undef  YY_END_OF_BUFFER
#define YY_END_OF_BUFFER 30
#undef  REJECT
#define REJECT reject_used_but_not_detected
#undef  YY_MORE_ADJ
#define YY_MORE_ADJ 0
#undef  YY_RESTORE_YY_MORE_OFFSET
#define YY_RESTORE_YY_MORE_OFFSET
#undef  YY_NO_UNPUT
#define YY_NO_UNPUT
#undef  INITIAL
#define INITIAL 0
#undef  YY_EXTRA_TYPE
#define YY_EXTRA_TYPE void *
#undef  YY_READ_BUF_SIZE
#define YY_READ_BUF_SIZE 8192
#undef  ECHO
#define ECHO (void) fwrite( yytext, yyleng, 1, yyout )
#undef  YY_START_STACK_INCR
#define YY_START_STACK_INCR 25
#undef  YY_DECL_IS_OURS
#define YY_DECL_IS_OURS 1
#undef  YY_DECL
#define YY_DECL int yylex (void)
#undef  YY_USER_ACTION
#define YY_USER_ACTION
#undef  YY_BREAK
#define YY_BREAK break;
#undef  YY_RULE_SETUP
#define YY_RULE_SETUP \
#undef  YY_EXIT_FAILURE
#define YY_EXIT_FAILURE 2
#undef  YYTABLES_NAME
#define YYTABLES_NAME "yytables"
#undef  MAXPWD
#define MAXPWD 256
#undef  signal
#define signal bsd_signal
#undef  ALL
#define ALL (E_OPEN|E_CREAT|E_EXEC)
#undef  EV_EXIT
#define EV_EXIT 01		/* exit after evaluating tree */
#undef  EV_TESTED
#define EV_TESTED 02		/* exit status is checked; ignore -e flag */
#undef  EV_BACKCMD
#define EV_BACKCMD 04		/* command executing within back quotes */
#undef  CMDTABLESIZE
#define CMDTABLESIZE 31		/* should be prime */
#undef  ARB
#define ARB 1			/* actual size determined at run time */
#undef  NEWARGS
#define NEWARGS 5
#undef  EOF_NLEFT
#define EOF_NLEFT -99		/* value of parsenleft when EOF pushed back */
#undef  _PATH_DEVNULL
#define _PATH_DEVNULL "/dev/null"
#undef  PROFILE
#define PROFILE 0
#undef  SIGSSIZE
#define SIGSSIZE (sizeof(sigs)/sizeof(sigs[0]))
#undef  MINSIZE
#define MINSIZE 504		/* minimum size of a block */
#undef  DEFINE_OPTIONS
#define DEFINE_OPTIONS
#undef  EOFMARKLEN
#define EOFMARKLEN 79
#undef  OPENBRACE
#define OPENBRACE '{'
#undef  CLOSEBRACE
#define CLOSEBRACE '}'
#undef  EMPTY
#define EMPTY -2		/* marks an unused slot in redirtab */
#undef  signal
#define signal bsd_signal
#undef  sys_signame
#define sys_signame sys_siglist
#undef  S_DFL
#define S_DFL 1			/* default signal handling (SIG_DFL) */
#undef  S_CATCH
#define S_CATCH 2		/* signal is caught */
#undef  S_IGN
#define S_IGN 3			/* signal is ignored (SIG_IGN) */
#undef  S_HARD_IGN
#define S_HARD_IGN 4		/* signal is ignored permenantly */
#undef  S_RESET
#define S_RESET 5		/* temporary - to reset a hard ignored sig */
#undef  OUTBUFSIZ
#define OUTBUFSIZ BUFSIZ
#undef  BLOCK_OUT
#define BLOCK_OUT -2		/* output to a fixed block of memory */
#undef  MEM_OUT
#define MEM_OUT -3		/* output to dynamically allocated memory */
#undef  OUTPUT_ERR
#define OUTPUT_ERR 01		/* error occurred on output */
#undef  TEMPSIZE
#define TEMPSIZE 24
#undef  HAVE_VASPRINTF
#define HAVE_VASPRINTF 1
#undef  VTABSIZE
#define VTABSIZE 39
#undef  VTABSIZE
#define VTABSIZE 517
#undef  main
#define main echocmd
#undef  YYBISON
#define YYBISON 1
#undef  YYSKELETON_NAME
#define YYSKELETON_NAME "yacc.c"
#undef  YYPURE
#define YYPURE 0
#undef  YYLSP_NEEDED
#define YYLSP_NEEDED 0
#undef  ARITH_NUM
#define ARITH_NUM 258
#undef  ARITH_LPAREN
#define ARITH_LPAREN 259
#undef  ARITH_RPAREN
#define ARITH_RPAREN 260
#undef  ARITH_OR
#define ARITH_OR 261
#undef  ARITH_AND
#define ARITH_AND 262
#undef  ARITH_BOR
#define ARITH_BOR 263
#undef  ARITH_BXOR
#define ARITH_BXOR 264
#undef  ARITH_BAND
#define ARITH_BAND 265
#undef  ARITH_NE
#define ARITH_NE 266
#undef  ARITH_EQ
#define ARITH_EQ 267
#undef  ARITH_LE
#define ARITH_LE 268
#undef  ARITH_GE
#define ARITH_GE 269
#undef  ARITH_GT
#define ARITH_GT 270
#undef  ARITH_LT
#define ARITH_LT 271
#undef  ARITH_RSHIFT
#define ARITH_RSHIFT 272
#undef  ARITH_LSHIFT
#define ARITH_LSHIFT 273
#undef  ARITH_SUB
#define ARITH_SUB 274
#undef  ARITH_ADD
#define ARITH_ADD 275
#undef  ARITH_REM
#define ARITH_REM 276
#undef  ARITH_DIV
#define ARITH_DIV 277
#undef  ARITH_MUL
#define ARITH_MUL 278
#undef  ARITH_BNOT
#define ARITH_BNOT 279
#undef  ARITH_NOT
#define ARITH_NOT 280
#undef  ARITH_UNARYPLUS
#define ARITH_UNARYPLUS 281
#undef  ARITH_UNARYMINUS
#define ARITH_UNARYMINUS 282
#undef  YYFINAL
#define YYFINAL  14
#undef  YYLAST
#define YYLAST   170
#undef  YYNTOKENS
#define YYNTOKENS  28
#undef  YYNNTS
#define YYNNTS  3
#undef  YYNRULES
#define YYNRULES  26
#undef  YYNSTATES
#define YYNSTATES  52
#undef  YYUNDEFTOK
#define YYUNDEFTOK  2
#undef  YYMAXUTOK
#define YYMAXUTOK   282
#undef  YYPACT_NINF
#define YYPACT_NINF -13
#undef  YYTABLE_NINF
#define YYTABLE_NINF -1
#undef  yyerrok
#define yyerrok		(yyerrstatus = 0)
#undef  yyclearin
#define yyclearin	(yychar = YYEMPTY)
#undef  YYEMPTY
#define YYEMPTY		(-2)
#undef  YYEOF
#define YYEOF		0
#undef  YYACCEPT
#define YYACCEPT	goto yyacceptlab
#undef  YYABORT
#define YYABORT		goto yyabortlab
#undef  YYERROR
#define YYERROR		goto yyerrorlab
#undef  YYFAIL
#define YYFAIL		goto yyerrlab
#undef  YYTERROR
#define YYTERROR	1
#undef  YYERRCODE
#define YYERRCODE	256
#undef  YYPOPSTACK
#define YYPOPSTACK   (yyvsp--, yyssp--)
#undef  YY_INT_ALIGNED
#define  YY_INT_ALIGNED short int
#undef  FLEX_SCANNER
#define FLEX_SCANNER
#undef  YY_FLEX_MAJOR_VERSION
#define YY_FLEX_MAJOR_VERSION 2
#undef  YY_FLEX_MINOR_VERSION
#define YY_FLEX_MINOR_VERSION 5
#undef  YY_FLEX_SUBMINOR_VERSION
#define YY_FLEX_SUBMINOR_VERSION 31
#undef  FLEX_BETA
#define FLEX_BETA
#undef  FLEXINT_H
#define FLEXINT_H
#undef  INT8_MIN
#define INT8_MIN               (-128)
#undef  INT16_MIN
#define INT16_MIN              (-32767-1)
#undef  INT32_MIN
#define INT32_MIN              (-2147483647-1)
#undef  INT8_MAX
#define INT8_MAX               (127)
#undef  INT16_MAX
#define INT16_MAX              (32767)
#undef  INT32_MAX
#define INT32_MAX              (2147483647)
#undef  UINT8_MAX
#define UINT8_MAX              (255U)
#undef  UINT16_MAX
#define UINT16_MAX             (65535U)
#undef  UINT32_MAX
#define UINT32_MAX             (4294967295U)
#undef  YY_USE_CONST
#define YY_USE_CONST
#undef  YY_USE_CONST
#define YY_USE_CONST
#undef  yyconst
#define yyconst const
#undef  yyconst
#define yyconst
#undef  YY_NULL
#define YY_NULL 0
#undef  BEGIN
#define BEGIN (yy_start) = 1 + 2 *
#undef  YY_START
#define YY_START (((yy_start) - 1) / 2)
#undef  YYSTATE
#define YYSTATE YY_START
#undef  YY_NEW_FILE
#define YY_NEW_FILE yyrestart(yyin  )
#undef  YY_END_OF_BUFFER_CHAR
#define YY_END_OF_BUFFER_CHAR 0
#undef  YY_BUF_SIZE
#define YY_BUF_SIZE 16384
#undef  YY_TYPEDEF_YY_BUFFER_STATE
#define YY_TYPEDEF_YY_BUFFER_STATE
#undef  EOB_ACT_CONTINUE_SCAN
#define EOB_ACT_CONTINUE_SCAN 0
#undef  EOB_ACT_END_OF_FILE
#define EOB_ACT_END_OF_FILE 1
#undef  EOB_ACT_LAST_MATCH
#define EOB_ACT_LAST_MATCH 2
#undef  YY_TYPEDEF_YY_SIZE_T
#define YY_TYPEDEF_YY_SIZE_T
#undef  YY_STRUCT_YY_BUFFER_STATE
#define YY_STRUCT_YY_BUFFER_STATE
#undef  YY_BUFFER_NEW
#define YY_BUFFER_NEW 0
#undef  YY_BUFFER_NORMAL
#define YY_BUFFER_NORMAL 1
#undef  YY_BUFFER_EOF_PENDING
#define YY_BUFFER_EOF_PENDING 2
#undef  YY_CURRENT_BUFFER
#define YY_CURRENT_BUFFER ( (yy_buffer_stack) \
#undef  YY_CURRENT_BUFFER_LVALUE
#define YY_CURRENT_BUFFER_LVALUE (yy_buffer_stack)[(yy_buffer_stack_top)]
#undef  YY_FLUSH_BUFFER
#define YY_FLUSH_BUFFER yy_flush_buffer(YY_CURRENT_BUFFER )
#undef  yy_new_buffer
#define yy_new_buffer yy_create_buffer
#undef  yytext_ptr
#define yytext_ptr yytext
#undef  YY_DO_BEFORE_ACTION
#define YY_DO_BEFORE_ACTION \
#undef  YY_NUM_RULES
#define YY_NUM_RULES 29
#undef  YY_END_OF_BUFFER
#define YY_END_OF_BUFFER 30
#undef  REJECT
#define REJECT reject_used_but_not_detected
#undef  YY_MORE_ADJ
#define YY_MORE_ADJ 0
#undef  YY_RESTORE_YY_MORE_OFFSET
#define YY_RESTORE_YY_MORE_OFFSET
#undef  YY_NO_UNPUT
#define YY_NO_UNPUT
#undef  INITIAL
#define INITIAL 0
#undef  YY_EXTRA_TYPE
#define YY_EXTRA_TYPE void *
#undef  YY_READ_BUF_SIZE
#define YY_READ_BUF_SIZE 8192
#undef  ECHO
#define ECHO (void) fwrite( yytext, yyleng, 1, yyout )
#undef  YY_START_STACK_INCR
#define YY_START_STACK_INCR 25
#undef  YY_DECL_IS_OURS
#define YY_DECL_IS_OURS 1
#undef  YY_DECL
#define YY_DECL int yylex (void)
#undef  YY_USER_ACTION
#define YY_USER_ACTION
#undef  YY_BREAK
#define YY_BREAK break;
#undef  YY_RULE_SETUP
#define YY_RULE_SETUP \
#undef  YY_EXIT_FAILURE
#define YY_EXIT_FAILURE 2
#undef  YYTABLES_NAME
#define YYTABLES_NAME "yytables"
#undef  MAXPWD
#define MAXPWD 256
#undef  ALL
#define ALL (E_OPEN|E_CREAT|E_EXEC)
#undef  EV_EXIT
#define EV_EXIT 01		/* exit after evaluating tree */
#undef  EV_TESTED
#define EV_TESTED 02		/* exit status is checked; ignore -e flag */
#undef  EV_BACKCMD
#define EV_BACKCMD 04		/* command executing within back quotes */
#undef  CMDTABLESIZE
#define CMDTABLESIZE 31		/* should be prime */
#undef  ARB
#define ARB 1			/* actual size determined at run time */
#undef  NEWARGS
#define NEWARGS 5
#undef  EOF_NLEFT
#define EOF_NLEFT -99		/* value of parsenleft when EOF pushed back */
#undef  _PATH_DEVNULL
#define _PATH_DEVNULL "/dev/null"
#undef  PROFILE
#define PROFILE 0
#undef  SIGSSIZE
#define SIGSSIZE (sizeof(sigs)/sizeof(sigs[0]))
#undef  MINSIZE
#define MINSIZE 504		/* minimum size of a block */
#undef  DEFINE_OPTIONS
#define DEFINE_OPTIONS
#undef  EOFMARKLEN
#define EOFMARKLEN 79
#undef  OPENBRACE
#define OPENBRACE '{'
#undef  CLOSEBRACE
#define CLOSEBRACE '}'
#undef  EMPTY
#define EMPTY -2		/* marks an unused slot in redirtab */
#undef  S_DFL
#define S_DFL 1			/* default signal handling (SIG_DFL) */
#undef  S_CATCH
#define S_CATCH 2		/* signal is caught */
#undef  S_IGN
#define S_IGN 3			/* signal is ignored (SIG_IGN) */
#undef  S_HARD_IGN
#define S_HARD_IGN 4		/* signal is ignored permenantly */
#undef  S_RESET
#define S_RESET 5		/* temporary - to reset a hard ignored sig */
#undef  OUTBUFSIZ
#define OUTBUFSIZ BUFSIZ
#undef  BLOCK_OUT
#define BLOCK_OUT -2		/* output to a fixed block of memory */
#undef  MEM_OUT
#define MEM_OUT -3		/* output to dynamically allocated memory */
#undef  OUTPUT_ERR
#define OUTPUT_ERR 01		/* error occurred on output */
#undef  TEMPSIZE
#define TEMPSIZE 24
#undef  HAVE_VASPRINTF
#define HAVE_VASPRINTF 1
#undef  VTABSIZE
#define VTABSIZE 39
#undef  VTABSIZE
#define VTABSIZE 517
#undef  main
#define main echocmd



extern void rmaliases(void);

extern int loopnest;		/* current loop nesting level */

extern void deletefuncs(void);
extern void hash_special_builtins(void);

struct strpush {
	struct strpush *prev;	/* preceding string on stack */
	char *prevstring;
	int prevnleft;
	int prevlleft;
	struct alias *ap;	/* if push was associated with an alias */
};

struct parsefile {
	struct parsefile *prev;	/* preceding file on stack */
	int linno;		/* current line */
	int fd;			/* file descriptor (or -1 if string) */
	int nleft;		/* number of chars left in this line */
	int lleft;		/* number of chars left in this buffer */
	char *nextc;		/* next char in buffer */
	char *buf;		/* input buffer */
	struct strpush *strpush; /* for pushing strings at this level */
	struct strpush basestrpush; /* so pushing one is fast */
};

extern int parselleft;		/* copy of parsefile->lleft */
extern struct parsefile basepf;	/* top level input file */
extern char basebuf[BUFSIZ];	/* buffer for top level input file */

extern pid_t backgndpid;	/* pid of last background process */
extern int jobctl;

extern int tokpushback;		/* last token pushed back */
extern int checkkwd;            /* 1 == check for kwds, 2 == also eat newlines */

struct redirtab {
	struct redirtab *next;
	short renamed[10];
};

extern struct redirtab *redirlist;

extern char sigmode[NSIG];	/* current value of signal */

extern char **environ;




void
init() {

      /* from exec.c: */
      {
	      hash_special_builtins();
      }

      /* from input.c: */
      {
	      basepf.nextc = basepf.buf = basebuf;
      }

      /* from var.c: */
      {
	      char **envp;

	      initvar();
	      for (envp = environ ; *envp ; envp++) {
		      if (strchr(*envp, '=')) {
			      setvareq(*envp, VEXPORT|VTEXTFIXED);
		      }
	      }
      }
}




void
reset() {

      /* from eval.c: */
      {
	      evalskip = 0;
	      loopnest = 0;
	      funcnest = 0;
      }

      /* from input.c: */
      {
	      if (exception != EXSHELLPROC)
		      parselleft = parsenleft = 0;	/* clear input buffer */
	      popallfiles();
      }

      /* from parser.c: */
      {
	      tokpushback = 0;
	      checkkwd = 0;
      }

      /* from redir.c: */
      {
	      while (redirlist)
		      popredir();
      }

      /* from output.c: */
      {
	      out1 = &output;
	      out2 = &errout;
	      if (memout.buf != NULL) {
		      ckfree(memout.buf);
		      memout.buf = NULL;
	      }
      }
}




void
initshellproc() {

      /* from alias.c: */
      {
	      rmaliases();
      }

      /* from eval.c: */
      {
	      exitstatus = 0;
      }

      /* from exec.c: */
      {
	      deletefuncs();
      }

      /* from input.c: */
      {
	      popallfiles();
      }

      /* from jobs.c: */
      {
	      backgndpid = -1;
#if JOBS
	      jobctl = 0;
#endif
      }

      /* from options.c: */
      {
	      int i;

	      for (i = 0; optlist[i].name; i++)
		      optlist[i].val = 0;
	      optschanged();

      }

      /* from redir.c: */
      {
	      clearredir(0);
      }

      /* from trap.c: */
      {
	      char *sm;

	      clear_traps(0);
	      for (sm = sigmode ; sm < sigmode + NSIG ; sm++) {
		      if (*sm == S_IGN)
			      *sm = S_HARD_IGN;
	      }
      }

      /* from var.c: */
      {
	      shprocvar();
      }
}
