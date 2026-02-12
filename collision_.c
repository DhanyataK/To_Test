/************** -*-C-*- *********************************************
 * $Id$
 *                                                                  *
 *       AMESim C code for cosimulation written by code generator.  *

                                 collision_
 *
 *******************************************************************/

#include "collision_.h"
#include "ame_interfaces.h"

#include <assert.h>
#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>

#include <fcntl.h>


#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <setjmp.h>

#ifdef _WIN32
#ifndef WIN32
#define WIN32
#endif
#endif

#include "ameutils.h"
#include "codegen_ameutils_public.h"
#include "itf_amesubintf_public.h"
#include "codegen_amestate_public.h"

#if defined (WIN32) || defined(XPCMSVISUALC)
#include <io.h>
#else
#include <unistd.h>
#endif

#if defined(_WINDOWS) || defined(_WIN32) || defined(WIN32)
#define DLLEXPORTDEF __declspec(dllexport)
#else
#define DLLEXPORTDEF
#endif

#if defined (RTLAB) || defined(LABCAR) || defined(AME_ADX) || defined(AME_HWA) || defined(RT) ||defined(AMEVERISTAND)
#ifdef DLLEXPORTDEF
#undef DLLEXPORTDEF
#endif
#define DLLEXPORTDEF
#endif

/* If we are in Simulink we should set things up for a AMEMULTIDLL (only static symbols) */
#if defined(AME_CS_SIMULINK) || defined(AME_ME_SIMULINK)
#ifndef AMEMULTIDLL
#define AMEMULTIDLL
#endif
#endif

/* If we are in Veristand we should set things up for a AMEMULTIDLL (only static symbols) */
#ifdef AMEVERISTAND
#ifndef AMEMULTIDLL
#define AMEMULTIDLL
#endif
#endif

/* avoid globally exported functions - required for exporting several models in one executable */
#if defined AMEMULTIDLL
#define DLLEXPORTDEF_OR_STATIC static
#else
#define DLLEXPORTDEF_OR_STATIC DLLEXPORTDEF
#endif

#if defined CREATING_STATIC_LIB
#define DLLEXPORTDEF_OR_EXTERN extern
#else
#define DLLEXPORTDEF_OR_EXTERN DLLEXPORTDEF
#endif

#define TIME_ROUNDOFF 1.0e-10
#define TLAST_MIN     -1E30

#if defined(FMICS1) || defined(FMICS2) || defined(FMICS3) || defined(FMIME1) || defined(FMIME2)
#ifdef FMIX
#undef FMIX
#endif
#define FMI
#define MODEL_IDENTIFIER         collision_
#define MODEL_IDENTIFIER_STRING "collision_"
#endif

/* *****************************************************************

   code inserted by AMESim

   *****************************************************************/

#define AMEVERSION                  202610000
#define SUB_LENGTH                  63

static const char soldToId[] = "For Internal Siemens PLM Use Only";

/**** Model structure definition ****/
/* Structural definition of the model */
#define AME_MODEL_ISEXPLICIT        1

/* Number of explicit declared states  */
#define AME_NBOF_EXPLICIT_STATE     3

/* Number of implicit declared states  */
#define AME_NBOF_IMPLICIT_STATE_DECLARED  0
#define AME_NBOF_IMPLICIT_STATE_GENERATED 0
#define AME_NBOF_IMPLICIT_STATE           0

/* Number of discrete declared states  */
#define AME_NBOF_DISCRETE_STATE     0

/* Total number of states manipulated by the Amesim solver including generated states */
#define AME_NBOF_SOLVER_STATES      3

#define AME_NBOF_PARAMS             30
#define AME_NBOF_REAL_PARAMS        13
#define AME_NBOF_INT_PARAMS         12
#define AME_NBOF_TEXT_PARAMS        1
#define AME_NBOF_CSTATE_PARAMS      3
#define AME_NBOF_DSTATE_PARAMS      0
#define AME_NBOF_FIXED_VAR_PARAMS   1

#define AME_NBOF_VARS               19
#define AME_NBOF_INPUTS             0
#define AME_NBOF_OUTPUTS            0

#define AME_NBOF_REAL_STORES        0
#define AME_NBOF_INT_STORES         13
#define AME_NBOF_POINTER_STORES     0

#define AME_SIZEOF_DBWORK_ARRAY     0

#define AME_NB_VAR_INFO             19

#define AME_NB_NETWORK              0

#define AME_NB_SUBMODEL_REF         6

#define AME_FUNC_LOOP               1

#define AME_HAS_ENABLED_SUBMODEL    0

static const S_AMEModelDef GmodelDef = {
   AME_MODEL_ISEXPLICIT,
   AME_NBOF_EXPLICIT_STATE,
   AME_NBOF_IMPLICIT_STATE_DECLARED,
   AME_NBOF_IMPLICIT_STATE_GENERATED,
   AME_NBOF_DISCRETE_STATE,
   AME_NBOF_VARS,
   AME_NBOF_PARAMS,
   AME_NBOF_REAL_PARAMS,
   AME_NBOF_INT_PARAMS,
   AME_NBOF_TEXT_PARAMS,
   AME_NBOF_CSTATE_PARAMS,
   AME_NBOF_DSTATE_PARAMS,
   AME_NBOF_FIXED_VAR_PARAMS,
   AME_NBOF_INPUTS,
   AME_NBOF_OUTPUTS,
   AME_NBOF_REAL_STORES,
   AME_NBOF_INT_STORES,
   AME_NBOF_POINTER_STORES,
   AME_SIZEOF_DBWORK_ARRAY,
   AME_NB_VAR_INFO,
   AME_NB_NETWORK,
   AME_NB_SUBMODEL_REF
};


static const char **GinputVarTitles = NULL;
static const char **GoutputVarTitles = NULL;

/**** Parameters structure definition ****/

#define NB_SUBMODELNAME       5
static const char* GsubmodelNameArray[NB_SUBMODELNAME] = {
     "RSPR00 instance 1"
   , "T000 instance 1"
   , "SIGUDA01 instance 1"
   , "MECRL0 instance 1"
   , "MECRL0 instance 2"
};

static const S_AMEParamInfo GParamInfo[30] = {
     {E_Real_Param           , E_Expression_Param, 0, -1, 0, 0}
   , {E_ContinuousState_Param, E_Expression_Param, 1, 4, 0, 0}
   , {E_FixedVar_Param       , E_Expression_Param, 0, 10, 1, 0}
   , {E_Real_Param           , E_Expression_Param, 1, -1, 2, 0}
   , {E_Real_Param           , E_Expression_Param, 2, -1, 2, 0}
   , {E_Int_Param            , E_Expression_Param, 0, -1, 2, 0}
   , {E_Int_Param            , E_Expression_Param, 1, -1, 2, 0}
   , {E_Int_Param            , E_Expression_Param, 2, -1, 2, 0}
   , {E_Int_Param            , E_Expression_Param, 3, -1, 2, 0}
   , {E_Int_Param            , E_Expression_Param, 4, -1, 2, 0}
   , {E_Int_Param            , E_Expression_Param, 5, -1, 2, 0}
   , {E_Int_Param            , E_Expression_Param, 6, -1, 2, 0}
   , {E_Int_Param            , E_Expression_Param, 7, -1, 2, 0}
   , {E_Int_Param            , E_Expression_Param, 8, -1, 2, 0}
   , {E_Int_Param            , E_Expression_Param, 9, -1, 2, 0}
   , {E_Text_Param           , E_Expression_Param, 0, -1, 2, 0}
   , {E_Real_Param           , E_Expression_Param, 3, -1, 3, 0}
   , {E_Real_Param           , E_Expression_Param, 4, -1, 3, 0}
   , {E_Real_Param           , E_Expression_Param, 5, -1, 3, 0}
   , {E_Real_Param           , E_Expression_Param, 6, -1, 3, 0}
   , {E_Real_Param           , E_Expression_Param, 7, -1, 3, 0}
   , {E_Int_Param            , E_Expression_Param, 10, -1, 3, 0}
   , {E_ContinuousState_Param, E_Expression_Param, 2, 7, 3, 0}
   , {E_Real_Param           , E_Expression_Param, 8, -1, 4, 0}
   , {E_Real_Param           , E_Expression_Param, 9, -1, 4, 0}
   , {E_Real_Param           , E_Expression_Param, 10, -1, 4, 0}
   , {E_Real_Param           , E_Expression_Param, 11, -1, 4, 0}
   , {E_Real_Param           , E_Expression_Param, 12, -1, 4, 0}
   , {E_Int_Param            , E_Expression_Param, 11, -1, 4, 0}
   , {E_ContinuousState_Param, E_Expression_Param, 0, 2, 4, 0}
};
#define NB_REAL_TUNABLE_PARAM 0
#define NB_INT_TUNABLE_PARAM 0

static const int GcontStateVarNum[AME_NBOF_EXPLICIT_STATE] = {
     2, 4, 7
};

static const int *GdiscStateVarNum = NULL;

static const int *GInputVarNum = NULL;

static const double *GInputStartValues = NULL;

static const int *GOutputVarNum = NULL;

static const int GFixedVarNum[AME_NBOF_FIXED_VAR_PARAMS] = {
     10
};

#define IS0 (&amesys->pModel->intStoreArray[0])
#define RP0 (&amesys->pModel->realParamArray[0])
#define IS3 (&amesys->pModel->intStoreArray[2])
#define RP3 (&amesys->pModel->realParamArray[1])
#define IP3 (&amesys->pModel->integerParamArray[0])
#define TP3 (&amesys->pModel->textParamArray[0])
#define IS4 (&amesys->pModel->intStoreArray[3])
#define RP4 (&amesys->pModel->realParamArray[3])
#define IP4 (&amesys->pModel->integerParamArray[10])
#define IS5 (&amesys->pModel->intStoreArray[8])
#define RP5 (&amesys->pModel->realParamArray[8])
#define IP5 (&amesys->pModel->integerParamArray[11])

static int SP3[1] = {1};

static const S_AMEVariableInfo GVarInfo[AME_NB_VAR_INFO] = {
   { 0, 1, 1, 1, "MECRL0", "wdup" }
  ,{ 1, 1, 1, 1, "RSPR00", "torq1" }
  ,{ 2, 1, 1, 2, "MECRL0", "w" }
  ,{ 3, 1, 1, 1, "RSPR00", "torq2" }
  ,{ 4, 1, 1, 1, "RSPR00", "theta" }
  ,{ 5, 0, 1, 1, "RSPR00", "powerCrspring" }
  ,{ 6, 1, 1, 1, "SIGUDA01", "u" }
  ,{ 7, 1, 1, 1, "MECRL0", "w" }
  ,{ 8, 1, 1, 1, "TORQC", "torque" }
  ,{ 9, 1, 1, 2, "MECRL0", "wdup" }
  ,{ 10, 1, 1, 1, "T000", "tzero" }
  ,{ 11, 1, 1, 1, "MECRL0", "accel" }
  ,{ 12, 1, 1, 1, "MECRL0", "Tvisc" }
  ,{ 13, 0, 1, 1, "MECRL0", "powerRfrict" }
  ,{ 14, 0, 1, 1, "MECRL0", "powerIrmass" }
  ,{ 15, 1, 1, 2, "MECRL0", "accel" }
  ,{ 16, 1, 1, 2, "MECRL0", "Tvisc" }
  ,{ 17, 0, 1, 2, "MECRL0", "powerRfrict" }
  ,{ 18, 0, 1, 2, "MECRL0", "powerIrmass" }
};

#if !defined(AME_IMPLICIT_MODEL_ACCEPTED) && (AME_MODEL_ISEXPLICIT == 0)
#error "Implicit model not supported for the current interface."
#endif


/* ============================================================== */
/* If the interface needs linearisation (cosim and Amesim) */

#ifndef AME_NO_LA
#ifndef AME_NEED_LINEAR_ANALYSIS
#define AME_NEED_LINEAR_ANALYSIS
#endif
#endif

#if( AME_MODEL_ISEXPLICIT == 1)
#define AMEfuncPerturb LPerturbIfNecessary
#else
#define AMEfuncPerturb DPerturbIfNecessary
#endif

#ifdef AME_ADVANCEDDEBUG
static void AME_POST_SUBMODCALL_WITH_DISCON(AMESIMSYSTEM *amesys, int *flag, int *sflag, int *oflag, int *panic, char *submodelname, int instancenum)
{
   if(*sflag < 3)*sflag = getnfg_();
#ifdef AME_NEED_LINEAR_ANALYSIS
   if(*flag == 5)
   {
      AMEfuncPerturb(amesys, flag);
   }
   else if(*oflag != 5)
   {
      resdis(amesys, flag, sflag, oflag, submodelname, instancenum, panic);
   }
#else
   resdis(amesys, flag, sflag, oflag, submodelname, instancenum, panic);
#endif
}

static void AME_POST_SUBMODCALL_NO_DISCON(AMESIMSYSTEM *amesys, int *flag)
{
#ifdef AME_NEED_LINEAR_ANALYSIS
   if(*flag == 5)
   {
      AMEfuncPerturb(amesys, flag);
   }
#endif
}
#endif


#ifndef AME_ADVANCEDDEBUG
#ifdef AME_NEED_LINEAR_ANALYSIS
/* Typically for normal runs and cosim */
#define AME_POST_SUBMODCALL_WITH_DISCON(amesys,flag,sflag,oflag,panic,submodelname,instancenum) if(*sflag < 3)*sflag = getnfg_(); if(*flag == 5) AMEfuncPerturb(amesys, flag); else if(*oflag != 5) resdis(amesys, flag, sflag, oflag, submodelname, instancenum, panic)
#define AME_POST_SUBMODCALL_NO_DISCON(amesys,flag) if(*flag == 5) AMEfuncPerturb(amesys, flag)
#else
/* Typically for code exchange (simulink for instance) */
#define AME_POST_SUBMODCALL_WITH_DISCON(amesys,flag,sflag,oflag,panic,submodelname,instancenum) if(*sflag < 3)*sflag = getnfg_(); resdis(amesys, flag, sflag, oflag,submodelname,instancenum,panic)
#define AME_POST_SUBMODCALL_NO_DISCON(amesys,flag)
#endif
#endif

#ifdef AMERT
/* We dont need LA nor resdis for real-time - so set them to (almost) empty macros. (reset sflag to orig value "oflag") */
#undef AME_POST_SUBMODCALL_WITH_DISCON
#undef AME_POST_SUBMODCALL_NO_DISCON
#define AME_POST_SUBMODCALL_WITH_DISCON(amesys,flag,sflag,oflag,panic,submodelname,instancenum) *sflag = *oflag
#define AME_POST_SUBMODCALL_NO_DISCON(amesys,flag)
#endif

/* ============================================================== */

#ifdef AMERT
double IL_collision_step_ratio=0;
#endif

#ifdef AME_MEMORY_ACCESS_RT_EXPORT
/* For memory access in case of RT target such as dSpace targets */
#include "collision_.export.h"

static void RT_Get_Watch_Var(AMESIMSYSTEM *amesys)
{
#if (NB_WATCH_VAR>0)
   int i;

   for(i=0; i<NB_WATCH_VAR; i++) {
      RT_Export_Vars[i] = amesys->v[RT_Watch_Vars_Idx[i]];
   }
#endif
}

static void RT_Get_Watch_Param(AMESIMSYSTEM *amesys)
{
#if (NB_WATCH_REAL_PARAM>0) || (NB_WATCH_INT_PARAM>0)
   int i;

   for(i=0; i<NB_WATCH_REAL_PARAM; i++) {
      RT_Export_RealParam[i] = amesys->pModel->realParamArray[RT_Watch_RP_Idx[i]];
   }
   for(i=0; i<NB_WATCH_INT_PARAM; i++) {
      RT_Export_IntParam[i] = amesys->pModel->integerParamArray[RT_Watch_IP_Idx[i]];
   }
#endif
}

static void RT_Set_Watch_Param(AMESIMSYSTEM *amesys)
{
#if (NB_WATCH_REAL_PARAM>0) || (NB_WATCH_INT_PARAM>0)
   int i;

   for(i=0; i<NB_WATCH_REAL_PARAM; i++) {
      amesys->pModel->realParamArray[RT_Watch_RP_Idx[i]] = RT_Export_RealParam[i];
   }
   for(i=0; i<NB_WATCH_INT_PARAM; i++) {
      amesys->pModel->integerParamArray[RT_Watch_IP_Idx[i]] = RT_Export_IntParam[i];
   }
#endif
}

#endif

#ifdef AME_INPUT_IN_MEMORY
#include "collision_.sim.h"
#endif

#if( AME_MODEL_ISEXPLICIT == 0 )
#define LRW (40+9*AME_NBOF_SOLVER_STATES+AME_NBOF_SOLVER_STATES*AME_NBOF_SOLVER_STATES)
#define LIW (21+AME_NBOF_SOLVER_STATES)
#endif

// Submodel RSPR00 . 1
// variable torq1 (Oneline var)
static const int EVIA_V0[7] = {1, -1, 0, -1, 1, 1, 1};
// variable w1 (Basic var)
static const int EVIA_V1[7] = {0, -1, 1, -1, 1, 1, 1};
// variable torq2 (Oneline var)
static const int EVIA_V2[7] = {3, -1, 2, -1, 1, 1, 1};
// variable w2 (Basic var)
static const int EVIA_V3[7] = {2, -1, 3, -1, 1, 1, 1};
// Submodel T000 . 1
// variable tzero (Fixed var)
static const int EVIA_V4[7] = {10, -1, 4, -1, 1, 1, 1};
// Submodel SIGUDA01 . 1
// variable u (Basic var)
static const int EVIA_V5[7] = {6, -1, 5, -1, 1, 1, 1};
// Submodel MECRL0 . 2
// variable wdup (Duplicate var)
static const int EVIA_V6[7] = {9, -1, 6, -1, 1, 1, 1};
// variable torq1 (Basic var)
static const int EVIA_V7[7] = {10, -1, 7, -1, 1, 1, 1};
// variable w (Explicit state)
static const int EVIA_V8[7] = {2, 0, 8, 9, 1, 1, 1};
// variable torq2 (Basic var)
static const int EVIA_V9[7] = {3, -1, 10, -1, 1, 1, 1};
// Submodel TORQC . 1
// variable input (Basic var)
static const int EVIA_V10[7] = {6, -1, 11, -1, 1, 1, 1};
// variable torque (Oneline var)
static const int EVIA_V11[7] = {8, -1, 12, -1, 1, 1, 1};
// Submodel MECRL0 . 1
// variable wdup (Duplicate var)
static const int EVIA_V12[7] = {0, -1, 13, -1, 1, 1, 1};
// variable torq1 (Basic var)
static const int EVIA_V13[7] = {1, -1, 14, -1, 1, 1, 1};
// variable w (Explicit state)
static const int EVIA_V14[7] = {7, 2, 15, 16, 1, 1, 1};
// variable torq2 (Basic var)
static const int EVIA_V15[7] = {8, -1, 17, -1, 1, 1, 1};
static const int* EVIA[16] = {
     EVIA_V0, EVIA_V1, EVIA_V2, EVIA_V3, EVIA_V4, EVIA_V5, EVIA_V6, EVIA_V7, EVIA_V8, EVIA_V9
   , EVIA_V10, EVIA_V11, EVIA_V12, EVIA_V13, EVIA_V14, EVIA_V15
};

// Submodel RSPR00 . 1
// variable theta (Explicit state)
static const int IVIA_V0[4] = {4, 1, 1, 1};
// variable actCrspring (Explicit state)
static const int IVIA_V1[4] = {-1, -1, 1, 0};
// variable powerCrspring (Activity var)
static const int IVIA_V2[4] = {5, -1, 1, 1};
// variable energyCrspring (Explicit state)
static const int IVIA_V3[4] = {-1, -1, 1, 0};
// Submodel T000 . 1
// Submodel SIGUDA01 . 1
// Submodel MECRL0 . 2
// variable accel (Basic var)
static const int IVIA_V4[4] = {15, -1, 1, 1};
// variable Tvisc (Basic var)
static const int IVIA_V5[4] = {16, -1, 1, 1};
// variable actRfrict (Explicit state)
static const int IVIA_V6[4] = {-1, -1, 1, 0};
// variable powerRfrict (Activity var)
static const int IVIA_V7[4] = {17, -1, 1, 1};
// variable energyRfrict (Explicit state)
static const int IVIA_V8[4] = {-1, -1, 1, 0};
// variable actIrmass (Explicit state)
static const int IVIA_V9[4] = {-1, -1, 1, 0};
// variable powerIrmass (Activity var)
static const int IVIA_V10[4] = {18, -1, 1, 1};
// variable energyIrmass (Explicit state)
static const int IVIA_V11[4] = {-1, -1, 1, 0};
// Submodel TORQC . 1
// Submodel MECRL0 . 1
// variable accel (Basic var)
static const int IVIA_V12[4] = {11, -1, 1, 1};
// variable Tvisc (Basic var)
static const int IVIA_V13[4] = {12, -1, 1, 1};
// variable actRfrict (Explicit state)
static const int IVIA_V14[4] = {-1, -1, 1, 0};
// variable powerRfrict (Activity var)
static const int IVIA_V15[4] = {13, -1, 1, 1};
// variable energyRfrict (Explicit state)
static const int IVIA_V16[4] = {-1, -1, 1, 0};
// variable actIrmass (Explicit state)
static const int IVIA_V17[4] = {-1, -1, 1, 0};
// variable powerIrmass (Activity var)
static const int IVIA_V18[4] = {14, -1, 1, 1};
// variable energyIrmass (Explicit state)
static const int IVIA_V19[4] = {-1, -1, 1, 0};
static const int* IVIA[20] = {
     IVIA_V0, IVIA_V1, IVIA_V2, IVIA_V3, IVIA_V4, IVIA_V5, IVIA_V6, IVIA_V7, IVIA_V8, IVIA_V9
   , IVIA_V10, IVIA_V11, IVIA_V12, IVIA_V13, IVIA_V14, IVIA_V15, IVIA_V16, IVIA_V17, IVIA_V18, IVIA_V19
};

static const int PVIA[18] = {
     1, 0, 3, 2, 10, 6, 9, 10, 2, 0
   , 3, 6, 8, 0, 1, 7, 2, 8
};

// Submodel RSPR00 . 1
static const int RPARAM_0[2] = {0, 1};
// Submodel T000 . 1
// Submodel SIGUDA01 . 1
static const int RPARAM_1[2] = {0, 1};
static const int RPARAM_2[2] = {1, 1};
static const int IPARAM_3[2] = {0, 1};
static const int IPARAM_4[2] = {1, 1};
static const int IPARAM_5[2] = {2, 1};
static const int IPARAM_6[2] = {3, 1};
static const int IPARAM_7[2] = {4, 1};
static const int IPARAM_8[2] = {5, 1};
static const int IPARAM_9[2] = {6, 1};
static const int IPARAM_10[2] = {7, 1};
static const int IPARAM_11[2] = {8, 1};
static const int IPARAM_12[2] = {9, 1};
static const int TPARAM_13[2] = {0, 1};
// Submodel MECRL0 . 2
static const int RPARAM_14[2] = {0, 1};
static const int RPARAM_15[2] = {1, 1};
static const int RPARAM_16[2] = {2, 1};
static const int RPARAM_17[2] = {3, 1};
static const int RPARAM_18[2] = {4, 1};
static const int IPARAM_19[2] = {0, 1};
// Submodel TORQC . 1
// Submodel MECRL0 . 1
static const int RPARAM_20[2] = {0, 1};
static const int RPARAM_21[2] = {1, 1};
static const int RPARAM_22[2] = {2, 1};
static const int RPARAM_23[2] = {3, 1};
static const int RPARAM_24[2] = {4, 1};
static const int IPARAM_25[2] = {0, 1};
static const int* PIA[26] = {
     RPARAM_0, RPARAM_1, RPARAM_2, IPARAM_3, IPARAM_4, IPARAM_5, IPARAM_6, IPARAM_7, IPARAM_8, IPARAM_9
   , IPARAM_10, IPARAM_11, IPARAM_12, TPARAM_13, RPARAM_14, RPARAM_15, RPARAM_16, RPARAM_17, RPARAM_18, IPARAM_19
   , RPARAM_20, RPARAM_21, RPARAM_22, RPARAM_23, RPARAM_24, IPARAM_25
};


static const int** NGIA = NULL;

static const int* NIA = NULL;

typedef int typeIntTuple3[3];
typedef int typeIntTuple2[2];

#define AME_EXPLICIT_STATE 0
#define AME_DECLARED_IMPLICIT_STATE 1
#define AME_CONSTRAINT_STATE 2
#define AME_GENERATED_IMPLICIT_STATE 3
#define SIZE_INPUT_DEF 0

static const int SUBSIMU[AME_NB_SUBMODEL_REF][6][2] = {
     {{1, 0}, {0, 0}, {0, 0}, {0, 0}, {2, 0}, {0, 0}}
   , {{0, 1}, {0, 0}, {0, 0}, {0, 0}, {0, 2}, {0, 0}}
   , {{2, 1}, {10, 0}, {1, 0}, {0, 0}, {1, 2}, {0, 0}}
   , {{5, 8}, {1, 11}, {0, 1}, {0, 0}, {5, 8}, {0, 0}}
   , {{0, 1}, {0, 0}, {0, 0}, {0, 0}, {0, 2}, {0, 0}}
   , {{5, 3}, {1, 10}, {0, 1}, {0, 0}, {5, 3}, {0, 0}}
};

typedef struct {
   S_AMESubStructuralInfo STLI;
   int SUBSIMU[6][2];
   const char* name;
   int instance;
   const typeIntTuple2* inDef;
} S_AMEModelSubInfo;

static const S_AMEModelSubInfo SUBSTRUC[AME_NB_SUBMODEL_REF] = {
     { {1, &EVIA[0], &IVIA[0], PVIA, &PIA[0], NULL, NULL, NULL}, {{1, 0}, {0, 0}, {0, 0}, {0, 0}, {2, 0}, {0, 0}}, "RSPR00", 1, NULL }
   , { {1, &EVIA[4], NULL, PVIA, NULL, NULL, NULL, NULL}, {{0, 1}, {0, 0}, {0, 0}, {0, 0}, {0, 2}, {0, 0}}, "T000", 1, NULL }
   , { {1, &EVIA[5], NULL, PVIA, &PIA[1], SP3, NULL, NULL}, {{2, 1}, {10, 0}, {1, 0}, {0, 0}, {1, 2}, {0, 0}}, "SIGUDA01", 1, NULL }
   , { {2, &EVIA[6], &IVIA[4], PVIA, &PIA[14], NULL, NULL, NULL}, {{5, 8}, {1, 11}, {0, 1}, {0, 0}, {5, 8}, {0, 0}}, "MECRL0", 2, NULL }
   , { {1, &EVIA[10], NULL, PVIA, NULL, NULL, NULL, NULL}, {{0, 1}, {0, 0}, {0, 0}, {0, 0}, {0, 2}, {0, 0}}, "TORQC", 1, NULL }
   , { {1, &EVIA[12], &IVIA[12], PVIA, &PIA[20], NULL, NULL, NULL}, {{5, 3}, {1, 10}, {0, 1}, {0, 0}, {5, 3}, {0, 0}}, "MECRL0", 1, NULL }
};

/* *******************  Function prototypes ************ */

extern AMEModelStatus t000_in(const S_AMESubIntf *sitf);
extern AMEModelStatus t000_end(const S_AMESubIntf *sitf);
extern AMEModelStatus siguda01_in(const S_AMESubIntf *sitf);
extern AMEModelStatus siguda01_calc(const S_AMESubIntf *sitf);
extern AMEModelStatus siguda01_end(const S_AMESubIntf *sitf);
extern AMEModelStatus mecrl0_in(const S_AMESubIntf *sitf);
extern AMEModelStatus mecrl0_calc(const S_AMESubIntf *sitf);
extern AMEModelStatus mecrl0_end(const S_AMESubIntf *sitf);
extern AMEModelStatus torqc_in(const S_AMESubIntf *sitf);
extern AMEModelStatus torqc_end(const S_AMESubIntf *sitf);
extern AMEModelStatus rspr00_in(const S_AMESubIntf *sitf);
extern AMEModelStatus rspr00_calc(const S_AMESubIntf *sitf);
extern AMEModelStatus rspr00_end(const S_AMESubIntf *sitf);

static AMEModelStatus rspr00_olm_torq1_0(const S_AMESubIntf *sitf)
{
   double *v = sitf->va;
   AMESIMSYSTEM *amesys = sitf->amesys;
   double t = sitf->t;
   v[1] = RP0[0]*((v[4]*0.0174532925199433));
   return AME_MODEL_OK;
}
static AMEModelStatus rspr00_olm_torq2_0(const S_AMESubIntf *sitf)
{
   double *v = sitf->va;
   AMESIMSYSTEM *amesys = sitf->amesys;
   double t = sitf->t;
   v[3] = RP0[0]*((v[4]*0.0174532925199433));
   return AME_MODEL_OK;
}
static AMEModelStatus torqc_olm_torque_4(const S_AMESubIntf *sitf)
{
   double *v = sitf->va;
   AMESIMSYSTEM *amesys = sitf->amesys;
   double t = sitf->t;
   v[8] = v[6];
   return AME_MODEL_OK;
}
typedef struct {
   AMEModelStatus (*func)(const S_AMESubIntf*);
   int subIdx;
} typeAmeSubFunc;

typedef struct {
   AMEModelStatus (*func)(const S_AMESubIntf*);
   int subIdx;
   int runtime;
   const typeIntTuple3* stateList;
   const typeIntTuple3 dupVar;
} typeAmeSubCalcFunc;

#define NB_CALL_prein 0
#define NB_CALL_in 6
static const typeAmeSubFunc TabFunc_in[NB_CALL_in] = {
     {&t000_in, 1}, {&siguda01_in, 2}
   , {&mecrl0_in, 3}, {&torqc_in, 4}
   , {&mecrl0_in, 5}, {&rspr00_in, 0}
};

#define NB_CALL_calc 9
static const typeAmeSubCalcFunc TabFunc_calc[NB_CALL_calc] = {
     {&rspr00_olm_torq1_0, 0, 0, NULL, {0, 0, 0}}, {&rspr00_olm_torq2_0, 0, 0, NULL, {0, 0, 0}}
   , {&siguda01_calc, 2, 1, NULL, {0, 0, 0}}, {&mecrl0_calc, 3, 9, NULL, {0, 0, 0}}
   , {NULL, 3, 64, NULL, {2, 9, 1}}, {&torqc_olm_torque_4, 4, 0, NULL, {0, 0, 0}}
   , {&mecrl0_calc, 5, 9, NULL, {0, 0, 0}}, {NULL, 5, 64, NULL, {7, 0, 1}}
   , {&rspr00_calc, 0, 9, NULL, {0, 0, 0}}
};

#define NB_CALL_end 6
static const typeAmeSubFunc TabFunc_end[NB_CALL_end] = {
     {&rspr00_end, 0}, {&mecrl0_end, 5}
   , {&torqc_end, 4}, {&mecrl0_end, 3}
   , {&siguda01_end, 2}, {&t000_end, 1}
};

const int TabJFunc_calc0[3] = {
     2, 3, 8
};

const int TabJFunc_calc1[6] = {
     5, 0, 1, 3, 6, 8
};

const int TabJFunc_calc2[4] = {
     3, 6, 7, 8
};

const int* TabJFunc_calc[3] = {
   TabJFunc_calc0, TabJFunc_calc1, TabJFunc_calc2
};


/* ******************    Here comes the functions ************ */
#if(AME_FUNC_LOOP == 1)

static void PreInitialize(AMESIMSYSTEM *amesys, double *y)
{
   int n = 0;
   double *v = amesys->v;
   double *Z = amesys->discrete_states;
   double *dbk_wk = amesys->pModel->dbk_wk;
   const double t = getstarttime_();
   S_AMESubIntf sitf = {amesys, NULL, NULL, t, NULL, v, NULL};
   AMEModelStatus status = AME_MODEL_OK;

#if (SIZE_INPUT_DEF > 0)
   double saveBuff[SIZE_INPUT_DEF];
#endif


   (void)n;

   /* Assign continuous state variables calculated by the integrator */
#if( (AME_MODEL_ISEXPLICIT == 0) && (AME_NBOF_SOLVER_STATES > 0) )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_SOLVER_STATES; idxState++) {
         v[GcontStateVarNum[idxState]] = y[idxState];
      }
   }
#elif( (AME_MODEL_ISEXPLICIT == 1) && (AME_NBOF_EXPLICIT_STATE > 0) )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_EXPLICIT_STATE; idxState++) {
         v[GcontStateVarNum[idxState]] = y[idxState];
      }
   }
#endif

   /* Assign discrete state variables */
#if( AME_NBOF_DISCRETE_STATE > 0 )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_DISCRETE_STATE; idxState++) {
         v[GdiscStateVarNum[idxState]] = Z[idxState];
      }
   }
#endif

   InitializeUnitsManagerAsDefault();

#if (NB_CALL_prein > 0)
   {
      int idxCall;
      
      for(idxCall = 0; idxCall < NB_CALL_prein; idxCall++) {
         sitf.structuralInfo  = &SUBSTRUC[TabFunc_prein[idxCall].subIdx].STLI;
         sitf.simulationInfo = &amesys->pModel->subArray[TabFunc_prein[idxCall].subIdx];

#if (SIZE_INPUT_DEF > 0)
         if(SUBSTRUC[TabFunc_prein[idxCall].subIdx].inDef) {
            int iInputDef;
            int pos = 0;
            for(iInputDef = 1; iInputDef < 1 + SUBSTRUC[TabFunc_prein[idxCall].subIdx].inDef[0][0]; iInputDef++) {
               int i;
               for(i = 0; i < SUBSTRUC[TabFunc_prein[idxCall].subIdx].inDef[iInputDef][1]; i++) {
                  saveBuff[pos + i] = v[SUBSTRUC[TabFunc_prein[idxCall].subIdx].inDef[iInputDef][0] + i];
               }
               pos += SUBSTRUC[TabFunc_prein[idxCall].subIdx].inDef[iInputDef][1];
            }
         }
#endif
      
         status |= (*TabFunc_prein[idxCall].func)(&sitf);
         
#if (SIZE_INPUT_DEF > 0)
         if(SUBSTRUC[TabFunc_prein[idxCall].subIdx].inDef) {
            int iInputDef;
            int pos = 0;
            for(iInputDef = 1; iInputDef < 1 + SUBSTRUC[TabFunc_prein[idxCall].subIdx].inDef[0][0]; iInputDef++) {
               int i;
               for(i = 0; i < SUBSTRUC[TabFunc_prein[idxCall].subIdx].inDef[iInputDef][1]; i++) {
                  v[SUBSTRUC[TabFunc_prein[idxCall].subIdx].inDef[iInputDef][0] + i] = saveBuff[pos + i];
               }
               pos += SUBSTRUC[TabFunc_prein[idxCall].subIdx].inDef[iInputDef][1];
            }
         }
#endif
         
         if(status & AME_MODEL_FATAL) goto _amefunc_preinit_end;
      }
   }
#endif

   /* Assign continuous state variables initialized by submodels */
#if( (AME_MODEL_ISEXPLICIT == 0) && (AME_NBOF_SOLVER_STATES > 0) )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_SOLVER_STATES; idxState++) {
         y[idxState] = v[GcontStateVarNum[idxState]];
      }
   }
#elif( (AME_MODEL_ISEXPLICIT == 1) && (AME_NBOF_EXPLICIT_STATE > 0) )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_EXPLICIT_STATE; idxState++) {
         y[idxState] = v[GcontStateVarNum[idxState]];
      }
   }
#endif

   /* Assign discrete state initialized by submodels */
#if( AME_NBOF_DISCRETE_STATE > 0 )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_DISCRETE_STATE; idxState++) {
         Z[idxState] = v[GdiscStateVarNum[idxState]];
      }
   }
#endif

#if (NB_CALL_prein > 0)
_amefunc_preinit_end:
#endif
   if(status & AME_MODEL_FATAL) AmeExit(1);
}

static void Initialize(AMESIMSYSTEM *amesys, double *y)
{
   int n;
   double *v = amesys->v;
   double *Z = amesys->discrete_states;
   double *dbk_wk = amesys->pModel->dbk_wk;
   const double t = getstarttime_();
   S_AMESubIntf sitf = {amesys, NULL, NULL, t, NULL, v, NULL};
   AMEModelStatus status = AME_MODEL_OK;
   
#if (SIZE_INPUT_DEF > 0)
   double saveBuff[SIZE_INPUT_DEF];
#endif


   (void)n;

   /* Assign continuous state variables */
#if( (AME_MODEL_ISEXPLICIT == 0) && (AME_NBOF_SOLVER_STATES > 0) )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_SOLVER_STATES; idxState++) {
         v[GcontStateVarNum[idxState]] = y[idxState];
      }
   }
#elif( (AME_MODEL_ISEXPLICIT == 1) && (AME_NBOF_EXPLICIT_STATE > 0) )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_EXPLICIT_STATE; idxState++) {
         v[GcontStateVarNum[idxState]] = y[idxState];
      }
   }
#endif

   /* Assign discrete state variables */
#if( AME_NBOF_DISCRETE_STATE > 0 )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_DISCRETE_STATE; idxState++) {
         v[GdiscStateVarNum[idxState]] = Z[idxState];
      }
   }
#endif

#if (NB_CALL_in > 0)
   {
      int idxCall;
      
      for(idxCall = 0; idxCall < NB_CALL_in; idxCall++) {
         sitf.structuralInfo  = &SUBSTRUC[TabFunc_in[idxCall].subIdx].STLI;
         sitf.simulationInfo = &amesys->pModel->subArray[TabFunc_in[idxCall].subIdx];
         
#if (SIZE_INPUT_DEF > 0)
         if(SUBSTRUC[TabFunc_in[idxCall].subIdx].inDef) {
            int iInputDef;
            int pos = 0;
            for(iInputDef = 1; iInputDef < 1 + SUBSTRUC[TabFunc_in[idxCall].subIdx].inDef[0][0]; iInputDef++) {
               int i;
               for(i = 0; i < SUBSTRUC[TabFunc_in[idxCall].subIdx].inDef[iInputDef][1]; i++) {
                  saveBuff[pos + i] = v[SUBSTRUC[TabFunc_in[idxCall].subIdx].inDef[iInputDef][0] + i];
               }
               pos += SUBSTRUC[TabFunc_in[idxCall].subIdx].inDef[iInputDef][1];
            }
         }
#endif
         
         status |= (*TabFunc_in[idxCall].func)(&sitf);
         
#if (SIZE_INPUT_DEF > 0)
         if(SUBSTRUC[TabFunc_in[idxCall].subIdx].inDef) {
            int iInputDef;
            int pos = 0;
            for(iInputDef = 1; iInputDef < 1 + SUBSTRUC[TabFunc_in[idxCall].subIdx].inDef[0][0]; iInputDef++) {
               int i;
               for(i = 0; i < SUBSTRUC[TabFunc_in[idxCall].subIdx].inDef[iInputDef][1]; i++) {
                  v[SUBSTRUC[TabFunc_in[idxCall].subIdx].inDef[iInputDef][0] + i] = saveBuff[pos + i];
               }
               pos += SUBSTRUC[TabFunc_in[idxCall].subIdx].inDef[iInputDef][1];
            }
         }
#endif
         
         if(status & AME_MODEL_FATAL) goto _amefunc_init_end;
      }
   }
#endif
   /* Assign continuous state variables initialized by submodels */
#if( (AME_MODEL_ISEXPLICIT == 0) && (AME_NBOF_SOLVER_STATES > 0) )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_SOLVER_STATES; idxState++) {
         y[idxState] = v[GcontStateVarNum[idxState]];
      }
   }
#elif( (AME_MODEL_ISEXPLICIT == 1) && (AME_NBOF_EXPLICIT_STATE > 0) )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_EXPLICIT_STATE; idxState++) {
         y[idxState] = v[GcontStateVarNum[idxState]];
      }
   }
#endif

   /* Assign discrete state initialized by submodels */
#if( AME_NBOF_DISCRETE_STATE > 0 )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_DISCRETE_STATE; idxState++) {
         Z[idxState] = v[GdiscStateVarNum[idxState]];
      }
   }
#endif

#if (NB_CALL_in > 0)
_amefunc_init_end:
#endif
   if(status & AME_MODEL_FATAL) AmeExit(1);
}

static void localFuncEval(AMESIMSYSTEM *amesys, double t, double *y, double *yprime, double *delta, int *flag)
{
   int sflag, oflag, n, panic, i=0;
   int *oldflag, *newflag;
   double *v = amesys->v;
   double *Z = amesys->discrete_states;
   double *input = amesys->inputs;
   double *output = amesys->outputs;
   double *dbk_wk = amesys->pModel->dbk_wk;
   AMEModelStatus status = AME_MODEL_OK;

#if(AME_MODEL_ISEXPLICIT == 1)
   double *dot = yprime;
   S_AMESubIntf sitf = {amesys, NULL, NULL, t, &sflag, v, dot};

#if(AME_HAS_ENABLED_SUBMODEL == 1)
   memset(dot,0,AME_NBOF_SOLVER_STATES*sizeof(double));
#elif (AME_NBOF_EXPLICIT_STATE == 0)
   dot[0] = 0.0;
#endif

#else
   double dot[AME_NBOF_SOLVER_STATES];
   S_AMESubIntf sitf = {amesys, NULL, NULL, t, &sflag, v, dot};

   /* Initialize the dot vector to the yprime vector. */
   memcpy((void *)dot, (void *)yprime, AME_NBOF_SOLVER_STATES*sizeof(double));
#endif

   SetGlobalSystem(amesys);

   (void)n;

#if(defined(AME_COSIM) && (AME_NBOF_INPUTS > 0))
   if(amesys->doInterpol) {
      if( getInputsCosimSlave(amesys->csSlave, t, input) != AME_NO_ERROR ) {
         AmeExit(1);
      }
   }
#endif

   /* Record old value of flag (oflag) and set
      flag value for use in submodels (sflag).
      Also get addresses of main discontinuity flags. */

   oflag = *flag;
   sflag = *flag;

   if(amesys->first_call)
   {
      GetFlagAddresses(&amesys->oldflag, &amesys->newflag);
   }
   oldflag = amesys->oldflag;
   newflag = amesys->newflag;

   /* Initialize everything ready for potential calls to stepdn
      in submodels. */

   panic = 0;
   getredstep();

   if(isstabrun_())
   {
      simOptGetFixedTime(amesys->simVOptions, &t);
   }
   else if(*flag == 2)
   {
      /* Record current simulation time for message passing. */

      SetSimTime(t);
   }
   /* Record current simulation time for ametim_(). */

   SetTimeAtThisStep(t);

   if (holdinputs_())
   {
      /* We reset artificially the time to the initial value
         to give the illusion of held inputs. */

      t = getstarttime_();
   }
   sitf.t = t;
   
   /* Assign the state variables y[] calculated by the integrator
      to the appropriate variables v[]. */

   /* Assign continuous state variables calculated by the integrator */
#if( (AME_MODEL_ISEXPLICIT == 0) && (AME_NBOF_SOLVER_STATES > 0) )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_SOLVER_STATES; idxState++) {
         v[GcontStateVarNum[idxState]] = y[idxState];
      }
   }
#elif( (AME_MODEL_ISEXPLICIT == 1) && (AME_NBOF_EXPLICIT_STATE > 0) )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_EXPLICIT_STATE; idxState++) {
         v[GcontStateVarNum[idxState]] = y[idxState];
      }
   }
#endif

   /* Assign discrete state variables */
#if( AME_NBOF_DISCRETE_STATE > 0 )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_DISCRETE_STATE; idxState++) {
         v[GdiscStateVarNum[idxState]] = Z[idxState];
      }
   }
#endif

   /* Assign the interface input variables to the appropriate variable v(). */
#if(AME_NBOF_INPUTS > 0)
   {
      int idxInput;
      for(idxInput = 0; idxInput < AME_NBOF_INPUTS; idxInput++) {
         v[GInputVarNum[idxInput]] = input[idxInput];
      }
   }
#endif

#if(AME_MODEL_ISEXPLICIT == 1)
  /* The following call ensures that lsoda does not integrate past
      time amesys->t_end_of_time_slice. This does not matter in a standard AMESim run but is
      very important with cosimulation. */

#ifdef AME_COSIM
   *oldflag = *newflag = sflag;
   discInput(&amesys->t_end_of_time_slice);
   AME_POST_SUBMODCALL_WITH_DISCON(amesys, flag,&sflag,&oflag,&panic,"_TunableParam",1);
#endif

#else
   if(*flag == 5)
   {
      DPerturbIfNecessary(amesys, flag);
   }

#ifdef AME_COSIM
   *oldflag = *newflag = sflag;
   discInput(&amesys->t_end_of_time_slice);
   AME_POST_SUBMODCALL_WITH_DISCON(amesys, flag,&sflag,&oflag,&panic,"_TunableParam",1);
#endif

#endif

   /* Call submodel calculation subroutine in the order
      that ensures the input requirements of each submodel
      are satisfied. */

#if (NB_REAL_TUNABLE_PARAM > 0) || (NB_INT_TUNABLE_PARAM > 0)
   if(*flag == 0)
   {
      int idxParam;
#if (NB_REAL_TUNABLE_PARAM > 0)
      for(idxParam = 0; idxParam < NB_REAL_TUNABLE_PARAM; idxParam++) {
         v[GRealTunableParam[idxParam][1]] = amesys->pModel->realParamArray[GRealTunableParam[idxParam][0]];
      }
#endif
#if(NB_INT_TUNABLE_PARAM > 0)
      for(idxParam = 0; idxParam < NB_INT_TUNABLE_PARAM; idxParam++) {
         v[GIntTunableParam[idxParam][1]] = amesys->pModel->integerParamArray[GIntTunableParam[idxParam][0]];
      }
#endif
   }
#endif

#if (NB_CALL_calc > 0)
   {
      int idxCall;
      for(idxCall = 0; idxCall < NB_CALL_calc; idxCall++) {
      
         if((TabFunc_calc[idxCall].runtime & 0x02) && !isprint_()) {
            // Call only when printing
            continue;
         }
         
         if(TabFunc_calc[idxCall].runtime & 0x04) {
            // Sensed variables
            SetVisibility(amesys);
         }
         
         if(TabFunc_calc[idxCall].runtime & 0x01) { *oldflag = *newflag = sflag; }
         
         // Prepare and call function 
         if(TabFunc_calc[idxCall].runtime & 0x20) {
            // duplicate
            int idxDup;
            for(idxDup=0; idxDup < TabFunc_calc[idxCall].dupVar[2]; idxDup++) 
            {
               v[TabFunc_calc[idxCall].dupVar[1] + idxDup] = v[TabFunc_calc[idxCall].dupVar[0] + idxDup];
            }
         }
         else if(TabFunc_calc[idxCall].runtime & 0x40) {
            // sign reversed duplicate
            int idxDup;
            for(idxDup=0; idxDup < TabFunc_calc[idxCall].dupVar[2]; idxDup++) 
            {
               v[TabFunc_calc[idxCall].dupVar[1] + idxDup] = -v[TabFunc_calc[idxCall].dupVar[0] + idxDup];
            }
         }
         else {
            sitf.structuralInfo = &SUBSTRUC[TabFunc_calc[idxCall].subIdx].STLI;
            sitf.simulationInfo = &amesys->pModel->subArray[TabFunc_calc[idxCall].subIdx];
            status |= (*TabFunc_calc[idxCall].func)(&sitf);
         }
         
         if(TabFunc_calc[idxCall].runtime & 0x04) {
            // Sensed variables
            ClearVisibility(amesys);
         }


#if (AME_NBOF_IMPLICIT_STATE_GENERATED > 0)
         if(TabFunc_calc[idxCall].runtime & 0x10) {
            // Deal with generated implicit
            int idxVarImp;
            for(idxVarImp = 0; idxVarImp < TabFunc_calc[idxCall].stateList[0][0]; idxVarImp++) {
               if(TabFunc_calc[idxCall].stateList[idxVarImp + 1][0] == AME_GENERATED_IMPLICIT_STATE) {
                  int numState = TabFunc_calc[idxCall].stateList[idxVarImp + 1][1];
                  int sizeState = TabFunc_calc[idxCall].stateList[idxVarImp + 1][2];
                  int idxState;
                  for(idxState = numState; idxState < (numState + sizeState); idxState++) {
                     delta[idxState] = v[GcontStateVarNum[idxState]] - y[idxState];
                     v[GcontStateVarNum[idxState]] = y[idxState];
                  }
               }
            }
         }
#endif
         if(TabFunc_calc[idxCall].runtime & 0x01) {
            AME_POST_SUBMODCALL_WITH_DISCON(amesys, flag, &sflag, &oflag, &panic, SUBSTRUC[TabFunc_calc[idxCall].subIdx].name, SUBSTRUC[TabFunc_calc[idxCall].subIdx].instance);
         }
         else {
            AME_POST_SUBMODCALL_NO_DISCON(amesys, flag);
         }

      }         
   }   
#endif // NB_CALL_calc > 0

   /* Set interface outputs here. */

   /* Set interface outputs here. */
#if(AME_NBOF_OUTPUTS > 0)
   {
      int idxOutput;
      for(idxOutput = 0; idxOutput < AME_NBOF_OUTPUTS; idxOutput++) {
         output[idxOutput] = v[GOutputVarNum[idxOutput]];
      }
   }
#endif

#if(AME_MODEL_ISEXPLICIT == 1)
   applyStateStatus(dot,AME_NBOF_SOLVER_STATES);
#else
#if( AME_NBOF_EXPLICIT_STATE > 0)
   applyStateStatus(dot,AME_NBOF_EXPLICIT_STATE);

   for(i=0;i<AME_NBOF_EXPLICIT_STATE;i++)
   {
      delta[i] = dot[i] - yprime[i];
   }
#endif
   for(i=AME_NBOF_EXPLICIT_STATE;i<(AME_NBOF_EXPLICIT_STATE + AME_NBOF_IMPLICIT_STATE_DECLARED);i++)
   {
      delta[i] = dot[i];
   }
#endif

   if(*flag == 0)
   {
      /* It is an initialization call and the user
         is permitted to change the state variables
         and discrete variables. */
      updateStatesFromModel(amesys, y, AME_CONTINUOUS_STATE|AME_DISCRETE_STATE);
   }

#if( AME_NBOF_DISCRETE_STATE > 0)
   if(is_sample_time()) {
      /* Change discrete variables */
      updateStatesFromModel(amesys, y, AME_DISCRETE_STATE);
   }
#endif

   UpFECount(amesys);

   amesys->first_call = 0;
   
   if(status & AME_MODEL_FATAL) {
      AmeExit(1);
   }
}

static void localJFuncEval(AMESIMSYSTEM *amesys, double t, double *y, double *yprime, double *delta, int col)
{
   int sflag=1; /* Only one flag value is required. */
   int n=1, i=0;
   double *v = amesys->v;
   double *vcopy = amesys->vcopy;
   double *input = amesys->inputs;
   double *output = amesys->outputs;
   double *Z = amesys->discrete_states;
   double *dbk_wk = amesys->pModel->dbk_wk;
   
#if(AME_MODEL_ISEXPLICIT == 1)
   double *dot = yprime;
#else
   double dot[AME_NBOF_SOLVER_STATES];
#endif
   
   S_AMESubIntf sitf = { amesys, NULL, NULL, t, &sflag, v, dot};
   AMEModelStatus status = AME_MODEL_OK;

#if(AME_MODEL_ISEXPLICIT == 0)
   /* Initialize the dot vector to the yprime vector. */
   memcpy((void *)dot, (void *)yprime, AME_NBOF_SOLVER_STATES*sizeof(double));
#endif

#if(AME_MODEL_ISEXPLICIT == 0)
   /* Initialize everything ready for potential calls to stepdn
      in submodels. */

#if(defined(AME_COSIM) && (AME_NBOF_INPUTS > 0))
   if(amesys->doInterpol) {
      if( getInputsCosimSlave(amesys->csSlave, t, input) != AME_NO_ERROR ) {
         AmeExit(1);
      }
   }
#endif

   if(isstabrun_())
   {
      simOptGetFixedTime(amesys->simVOptions, &t);
   }
#endif

   /* Record current simulation time for ametim_(). */

   SetTimeAtThisStep(t);

   if (holdinputs_())
   {
      /* We reset artificially the time to the initial value
         to give the illusion of held inputs. */

      t = getstarttime_();
   }
   sitf.t = t;
   
#if ((AME_NBOF_EXPLICIT_STATE > 0) || (AME_NBOF_IMPLICIT_STATE > 0))

   /* Assign the state variables y[] calculated by the integrator
      to the appropriate variables v[] and right calls necessary
      for that state in a case of a switch. */


   // Assign perturbated state in v
   v[GcontStateVarNum[col]] = y[col];
   
   {
      int idxCall;
      for(idxCall = 0; idxCall < TabJFunc_calc[col][0]; idxCall++) {
         int idxFunc = TabJFunc_calc[col][idxCall + 1];

         if((TabFunc_calc[idxFunc].runtime & 0x02) && !isprint_()) {
            // Call only when printing
            continue;
         }
         
         if(TabFunc_calc[idxFunc].runtime & 0x04) {
            // Sensed variables
            SetVisibility(amesys);
         }
         
         // Prepare and call function 
         if(TabFunc_calc[idxFunc].runtime & 0x20) {
            // duplicate
            int idxDup;
            for(idxDup=0; idxDup < TabFunc_calc[idxFunc].dupVar[2]; idxDup++) {
               v[TabFunc_calc[idxFunc].dupVar[1] + idxDup] = v[TabFunc_calc[idxFunc].dupVar[0] + idxDup];
            }
         }
         else if(TabFunc_calc[idxFunc].runtime & 0x40) {
            // sign reversed duplicate
            int idxDup;
            for(idxDup=0; idxDup < TabFunc_calc[idxFunc].dupVar[2]; idxDup++) {
               v[TabFunc_calc[idxFunc].dupVar[1] + idxDup] = -v[TabFunc_calc[idxFunc].dupVar[0] + idxDup];
            }
         }
         else {
            sitf.structuralInfo = &SUBSTRUC[TabFunc_calc[idxFunc].subIdx].STLI;
            sitf.simulationInfo = &amesys->pModel->subArray[TabFunc_calc[idxFunc].subIdx];
            status |= (*TabFunc_calc[idxFunc].func)(&sitf);
         }

         if(TabFunc_calc[idxFunc].runtime & 0x04) {
            // Sensed variables
            ClearVisibility(amesys);
         }
#if(AME_MODEL_ISEXPLICIT == 0)
         if(TabFunc_calc[idxFunc].runtime & 0x18) {
            // Deal with states
            int idxVarImp;
            for(idxVarImp = 0; idxVarImp < TabFunc_calc[idxFunc].stateList[0][0]; idxVarImp++) {
               int idxState;
               int numState = TabFunc_calc[idxFunc].stateList[idxVarImp + 1][1];
               int sizeState = TabFunc_calc[idxFunc].stateList[idxVarImp + 1][2];
               
               if(TabFunc_calc[idxFunc].stateList[idxVarImp + 1][0] == AME_EXPLICIT_STATE) {
                  // Explicit state
                  for(idxState = numState; idxState < (numState + sizeState); idxState++) {
                     delta[idxState] = dot[idxState] - yprime[idxState];
                  }
               }
               else if( (TabFunc_calc[idxFunc].stateList[idxVarImp + 1][0] == AME_DECLARED_IMPLICIT_STATE)
                  || (TabFunc_calc[idxFunc].stateList[idxVarImp + 1][0] == AME_CONSTRAINT_STATE) ) {
                  // Declared implicit state
                  for(idxState = numState; idxState < (numState + sizeState); idxState++) {
                     delta[idxState] = dot[idxState];
                  }
               }
               else if(TabFunc_calc[idxFunc].stateList[idxVarImp + 1][0] == AME_GENERATED_IMPLICIT_STATE) {
                  // Generated implicit state
                  for(idxState = numState; idxState < (numState + sizeState); idxState++) {
                     delta[idxState] = v[GcontStateVarNum[idxState]] - y[idxState];
                     v[GcontStateVarNum[idxState]] = y[idxState];
                  }
               }
            }
         }
#endif
      }
   }         
   

#else

   dot[0] = 0.0; /* Artificial state variable derivative. */

#endif

   UpFECount(amesys);
   
   if(status & AME_MODEL_FATAL) {
      AmeExit(1);
   }  
}

static void EndOfSimulation(AMESIMSYSTEM *amesys)
{
   int n=1;
   double *y = amesys->states;
   double *v = amesys->v;
   double *Z = amesys->discrete_states;
   double *dbk_wk = amesys->pModel->dbk_wk;
   const double t = getfinaltime_();
   S_AMESubIntf sitf = {amesys, NULL, NULL, t, NULL, v, NULL};
   AMEModelStatus status = AME_MODEL_OK;
   

   (void)n;
   (void)status;

#if (NB_CALL_end > 0)
   {
      int idxCall;
      
      for(idxCall = 0; idxCall < NB_CALL_end; idxCall++) {
         sitf.structuralInfo  = &SUBSTRUC[TabFunc_end[idxCall].subIdx].STLI;
         sitf.simulationInfo = &amesys->pModel->subArray[TabFunc_end[idxCall].subIdx];
         status |= (*TabFunc_end[idxCall].func)(&sitf);
      }
   }
#endif
}

#else

static void PreInitialize(AMESIMSYSTEM *amesys, double *y)
{
   int n = 0;
   double *v = amesys->v;
   double *Z = amesys->discrete_states;
   double *dbk_wk = amesys->pModel->dbk_wk;
   const double t = getstarttime_();
   S_AMESubIntf sitf = {amesys, NULL, NULL, t, NULL, v, NULL};
   AMEModelStatus status = AME_MODEL_OK;


   (void)n;

   /* Assign continuous state variables calculated by the integrator */
#if( (AME_MODEL_ISEXPLICIT == 0) && (AME_NBOF_SOLVER_STATES > 0) )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_SOLVER_STATES; idxState++) {
         v[GcontStateVarNum[idxState]] = y[idxState];
      }
   }
#elif( (AME_MODEL_ISEXPLICIT == 1) && (AME_NBOF_EXPLICIT_STATE > 0) )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_EXPLICIT_STATE; idxState++) {
         v[GcontStateVarNum[idxState]] = y[idxState];
      }
   }
#endif

   /* Assign discrete state variables */
#if( AME_NBOF_DISCRETE_STATE > 0 )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_DISCRETE_STATE; idxState++) {
         v[GdiscStateVarNum[idxState]] = Z[idxState];
      }
   }
#endif

   InitializeUnitsManagerAsDefault();


   /* Assign continuous state variables initialized by submodels */
#if( (AME_MODEL_ISEXPLICIT == 0) && (AME_NBOF_SOLVER_STATES > 0) )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_SOLVER_STATES; idxState++) {
         y[idxState] = v[GcontStateVarNum[idxState]];
      }
   }
#elif( (AME_MODEL_ISEXPLICIT == 1) && (AME_NBOF_EXPLICIT_STATE > 0) )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_EXPLICIT_STATE; idxState++) {
         y[idxState] = v[GcontStateVarNum[idxState]];
      }
   }
#endif

   /* Assign discrete state initialized by submodels */
#if( AME_NBOF_DISCRETE_STATE > 0 )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_DISCRETE_STATE; idxState++) {
         Z[idxState] = v[GdiscStateVarNum[idxState]];
      }
   }
#endif

   if(status & AME_MODEL_FATAL) AmeExit(1);
}

static void Initialize(AMESIMSYSTEM *amesys, double *y)
{
   int n;
   double *v = amesys->v;
   double *Z = amesys->discrete_states;
   double *dbk_wk = amesys->pModel->dbk_wk;
   const double t = getstarttime_();
   S_AMESubIntf sitf = {amesys, NULL, NULL, t, NULL, v, NULL};
   AMEModelStatus status = AME_MODEL_OK;


   (void)n;

   /* Assign continuous state variables */
#if( (AME_MODEL_ISEXPLICIT == 0) && (AME_NBOF_SOLVER_STATES > 0) )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_SOLVER_STATES; idxState++) {
         v[GcontStateVarNum[idxState]] = y[idxState];
      }
   }
#elif( (AME_MODEL_ISEXPLICIT == 1) && (AME_NBOF_EXPLICIT_STATE > 0) )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_EXPLICIT_STATE; idxState++) {
         v[GcontStateVarNum[idxState]] = y[idxState];
      }
   }
#endif

   /* Assign discrete state variables */
#if( AME_NBOF_DISCRETE_STATE > 0 )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_DISCRETE_STATE; idxState++) {
         v[GdiscStateVarNum[idxState]] = Z[idxState];
      }
   }
#endif


   /* Assign continuous state variables initialized by submodels */
#if( (AME_MODEL_ISEXPLICIT == 0) && (AME_NBOF_SOLVER_STATES > 0) )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_SOLVER_STATES; idxState++) {
         y[idxState] = v[GcontStateVarNum[idxState]];
      }
   }
#elif( (AME_MODEL_ISEXPLICIT == 1) && (AME_NBOF_EXPLICIT_STATE > 0) )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_EXPLICIT_STATE; idxState++) {
         y[idxState] = v[GcontStateVarNum[idxState]];
      }
   }
#endif

   /* Assign discrete state initialized by submodels */
#if( AME_NBOF_DISCRETE_STATE > 0 )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_DISCRETE_STATE; idxState++) {
         Z[idxState] = v[GdiscStateVarNum[idxState]];
      }
   }
#endif

_amefunc_init_end:
   if(status & AME_MODEL_FATAL) AmeExit(1);
}

static void localFuncEval(AMESIMSYSTEM *amesys, double t, double *y, double *yprime, double *delta, int *flag)
{
   int sflag, oflag, n, panic, i=0;
   int *oldflag, *newflag;
   double *v = amesys->v;
   double *Z = amesys->discrete_states;
   double *input = amesys->inputs;
   double *output = amesys->outputs;
   double *dbk_wk = amesys->pModel->dbk_wk;
   AMEModelStatus status = AME_MODEL_OK;

#if(AME_MODEL_ISEXPLICIT == 1)
   double *dot = yprime;
   S_AMESubIntf sitf = {amesys, NULL, NULL, t, &sflag, v, dot};

#if(AME_HAS_ENABLED_SUBMODEL == 1)
   memset(dot,0,AME_NBOF_SOLVER_STATES*sizeof(double));
#elif (AME_NBOF_EXPLICIT_STATE == 0)
   dot[0] = 0.0;
#endif

#else
   double dot[AME_NBOF_SOLVER_STATES];
   S_AMESubIntf sitf = {amesys, NULL, NULL, t, &sflag, v, dot};

   /* Initialize the dot vector to the yprime vector. */
   memcpy((void *)dot, (void *)yprime, AME_NBOF_SOLVER_STATES*sizeof(double));
#endif

   SetGlobalSystem(amesys);

   (void)n;

#if(defined(AME_COSIM) && (AME_NBOF_INPUTS > 0))
   if(amesys->doInterpol) {
      if( getInputsCosimSlave(amesys->csSlave, t, input) != AME_NO_ERROR ) {
         AmeExit(1);
      }
   }
#endif

   /* Record old value of flag (oflag) and set
      flag value for use in submodels (sflag).
      Also get addresses of main discontinuity flags. */

   oflag = *flag;
   sflag = *flag;

   if(amesys->first_call)
   {
      GetFlagAddresses(&amesys->oldflag, &amesys->newflag);
   }
   oldflag = amesys->oldflag;
   newflag = amesys->newflag;

   /* Initialize everything ready for potential calls to stepdn
      in submodels. */

   panic = 0;
   getredstep();

   if(isstabrun_())
   {
      simOptGetFixedTime(amesys->simVOptions, &t);
      sitf.t = t;
   }
   else if(*flag == 2)
   {
      /* Record current simulation time for message passing. */

      SetSimTime(t);
   }
   /* Record current simulation time for ametim_(). */

   SetTimeAtThisStep(t);

   if (holdinputs_())
   {
      /* We reset artificially the time to the initial value
         to give the illusion of held inputs. */
      t = getstarttime_();
      sitf.t = t;
   }
   /* Assign the state variables y[] calculated by the integrator
      to the appropriate variables v[]. */

   /* Assign continuous state variables calculated by the integrator */
#if( (AME_MODEL_ISEXPLICIT == 0) && (AME_NBOF_SOLVER_STATES > 0) )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_SOLVER_STATES; idxState++) {
         v[GcontStateVarNum[idxState]] = y[idxState];
      }
   }
#elif( (AME_MODEL_ISEXPLICIT == 1) && (AME_NBOF_EXPLICIT_STATE > 0) )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_EXPLICIT_STATE; idxState++) {
         v[GcontStateVarNum[idxState]] = y[idxState];
      }
   }
#endif

   /* Assign discrete state variables */
#if( AME_NBOF_DISCRETE_STATE > 0 )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_DISCRETE_STATE; idxState++) {
         v[GdiscStateVarNum[idxState]] = Z[idxState];
      }
   }
#endif

   /* Assign the interface input variables to the appropriate variable v(). */
#if(AME_NBOF_INPUTS > 0)
   {
      int idxInput;
      for(idxInput = 0; idxInput < AME_NBOF_INPUTS; idxInput++) {
         v[GInputVarNum[idxInput]] = input[idxInput];
      }
   }
#endif

#if(AME_MODEL_ISEXPLICIT == 1)
  /* The following call ensures that lsoda does not integrate past
      time amesys->t_end_of_time_slice. This does not matter in a standard AMESim run but is
      very important with cosimulation. */

#ifdef AME_COSIM
   *oldflag = *newflag = sflag;
   discInput(&amesys->t_end_of_time_slice);
   AME_POST_SUBMODCALL_WITH_DISCON(amesys, flag,&sflag,&oflag,&panic,"_TunableParam",1);
#endif

#else
   if(*flag == 5)
   {
      DPerturbIfNecessary(amesys, flag);
   }

#ifdef AME_COSIM
   *oldflag = *newflag = sflag;
   discInput(&amesys->t_end_of_time_slice);
   AME_POST_SUBMODCALL_WITH_DISCON(amesys, flag,&sflag,&oflag,&panic,"_TunableParam",1);
#endif

#endif

   /* Call submodel calculation subroutine in the order
      that ensures the input requirements of each submodel
      are satisfied. */

#if (NB_REAL_TUNABLE_PARAM > 0) || (NB_INT_TUNABLE_PARAM > 0)
   if(*flag == 0)
   {
      int idxParam;
#if (NB_REAL_TUNABLE_PARAM > 0)
      for(idxParam = 0; idxParam < NB_REAL_TUNABLE_PARAM; idxParam++) {
         v[GRealTunableParam[idxParam][1]] = amesys->pModel->realParamArray[GRealTunableParam[idxParam][0]];
      }
#endif
#if(NB_INT_TUNABLE_PARAM > 0)
      for(idxParam = 0; idxParam < NB_INT_TUNABLE_PARAM; idxParam++) {
         v[GIntTunableParam[idxParam][1]] = amesys->pModel->integerParamArray[GIntTunableParam[idxParam][0]];
      }
#endif
   }
#endif




   /* Set interface outputs here. */
#if(AME_NBOF_OUTPUTS > 0)
   {
      int idxOutput;
      for(idxOutput = 0; idxOutput < AME_NBOF_OUTPUTS; idxOutput++) {
         output[idxOutput] = v[GOutputVarNum[idxOutput]];
      }
   }
#endif

#if(AME_MODEL_ISEXPLICIT == 1)
   applyStateStatus(dot,AME_NBOF_SOLVER_STATES);
#else
#if( AME_NBOF_EXPLICIT_STATE > 0)
   applyStateStatus(dot,AME_NBOF_EXPLICIT_STATE);

   for(i=0;i<AME_NBOF_EXPLICIT_STATE;i++)
   {
      delta[i] = dot[i] - yprime[i];
   }
#endif
   for(i=AME_NBOF_EXPLICIT_STATE;i<(AME_NBOF_EXPLICIT_STATE + AME_NBOF_IMPLICIT_STATE_DECLARED);i++)
   {
      delta[i] = dot[i];
   }
#endif

   if(*flag == 0)
   {
      /* It is an initialization call and the user
         is permitted to change the state variables
         and discrete variables. */
      updateStatesFromModel(amesys, y, AME_CONTINUOUS_STATE|AME_DISCRETE_STATE);
   }

#if( AME_NBOF_DISCRETE_STATE > 0)
   if(is_sample_time()) {
      /* Change discrete variables */
      updateStatesFromModel(amesys, y, AME_DISCRETE_STATE);
   }
#endif

   UpFECount(amesys);

   amesys->first_call = 0;
   
   if(status & AME_MODEL_FATAL) {
      AmeExit(1);
   }
}


static void localJFuncEval(AMESIMSYSTEM *amesys, double t, double *y, double *yprime, double *delta, int col)
{
   int sflag=1; /* Only one flag value is required. */
   int n=1, i=0;
   double *v = amesys->v;
   double *vcopy = amesys->vcopy;
   double *input = amesys->inputs;
   double *output = amesys->outputs;
   double *Z = amesys->discrete_states;
   double *dbk_wk = amesys->pModel->dbk_wk;
   AMEModelStatus status = AME_MODEL_OK;
   
#if(AME_MODEL_ISEXPLICIT == 1)
   double *dot = yprime;

#else
   double dot[AME_NBOF_SOLVER_STATES];

   /* Initialize the dot vector to the yprime vector. */
   memcpy((void *)dot, (void *)yprime, AME_NBOF_SOLVER_STATES*sizeof(double));
#endif

#if(AME_MODEL_ISEXPLICIT == 0)
   /* Initialize everything ready for potential calls to stepdn
      in submodels. */

#if(defined(AME_COSIM) && (AME_NBOF_INPUTS > 0))
   if(amesys->doInterpol) {
      if( getInputsCosimSlave(amesys->csSlave, t, input) != AME_NO_ERROR ) {
         AmeExit(1);
      }
   }
#endif

   if(isstabrun_())
   {
      simOptGetFixedTime(amesys->simVOptions, &t);
   }
#endif

   /* Record current simulation time for ametim_(). */

   SetTimeAtThisStep(t);

   if (holdinputs_())
   {
      /* We reset artificially the time to the initial value
         to give the illusion of held inputs. */

      t = getstarttime_();
   }

   /* Assign the state variables y[] calculated by the integrator
      to the appropriate variables v[] and right calls necessary
      for that state in a case of a switch. */


   status |= (*jfunc_table[col])(amesys, t, y, dot, v, yprime, delta, col);


   UpFECount(amesys);
   
   if(status & AME_MODEL_FATAL) {
      AmeExit(1);
   }
}

static void EndOfSimulation(AMESIMSYSTEM *amesys)
{
   int n=1;
   double *y = amesys->states;
   double *v = amesys->v;
   double *Z = amesys->discrete_states;
   double *dbk_wk = amesys->pModel->dbk_wk;
   const double t = getfinaltime_();
   S_AMESubIntf sitf = {amesys, NULL, NULL, t, NULL, v, NULL};
   AMEModelStatus status = AME_MODEL_OK;
   

   (void)n;
   (void)status;

}

#endif /* (AME_FUNC_LOOP == 1) */


static void ameTerminate(AMESIMSYSTEM *amesys)
{
#ifdef AME_WRITE_RUNSTAT
   if(amesys->simOptions ) {
      bool statistics;
      SimOptIsStatisticsEnabled(amesys->simOptions, &statistics);
      if(statistics)
      {
         WriteRunStats(amesys);
      }
   }
#endif
#ifdef AME_PROCESS_TIME
   ProcessTime(2);
#endif

   /* Save state count, discontinuities and finalize the Performance Analyzer */
#ifdef AME_PERFORMANCE_ANALYZER
   if(!isfixedstepsolver_()){
      PerfAnalyzer_SaveStateCount (amesys);
      PerfAnalyzer_SaveDiscontinuities(amesys);
      PerfAnalyzer_Close(amesys);
   }
#endif

#ifdef AME_RESULT_FILE
   amesys->CloseResultFile(amesys);
#endif

   EndOfSimulation(amesys);
   AmeCallAtEnd(amesys->ameExitStatus);
   modelCleanStore(amesys->pModel);
}

#ifdef AME_EXPOSE_JACOBIAN
static int getPartialDerivatives(double *A, double *B, double *C, double *D)
{
   int res;
   AMESIMSYSTEM  *amesys = GetGlobalSystem();

   SPARSE_MATRIX *Amat, *Bmat, *Cmat, *Dmat;

#if(AME_MODEL_ISEXPLICIT == 1)
   if (amesys->tlast > TLAST_MIN)
      res = LDoLinearAnalysisOnDemand(amesys, amesys->numstates,
                                       amesys->tlast, amesys->states,
                                       &Amat, &Bmat, &Cmat, &Dmat);
#else
   if (amesys->tlast > TLAST_MIN)
      res = DDoLinearAnalysisOnDemand(amesys, amesys->neq,
                                       amesys->tlast,
                                       amesys->states, amesys->dotstates,
                                       &Amat, &Bmat, &Cmat, &Dmat);
#endif
   else
      res = 0;  /* failed: system probably not initialized */

   if(res != 0) {
      if(Amat) {
         GetMatAsDense(Amat,A);
      }
      if(Bmat) {
         GetMatAsDense(Bmat,B);
      }
      if(Cmat) {
         GetMatAsDense(Cmat,C);
      }
      if(Dmat) {
         GetMatAsDense(Dmat,D);
      }
      FreeSparseMatrix(Amat);
      FreeSparseMatrix(Bmat);
      FreeSparseMatrix(Cmat);
      FreeSparseMatrix(Dmat);
   }

   return res;
} /* getPartialDerivatives */

static int setLASettingsFromIO(int num_input_index, int num_output_index,
                              int *input_index, int *output_index, int *nbState)
{
   *nbState = AME_NBOF_EXPLICIT_STATE + AME_NBOF_IMPLICIT_STATE;

   return SetLADetailsFromIO(AME_NBOF_EXPLICIT_STATE, AME_NBOF_IMPLICIT_STATE,
                              AME_NBOF_INPUTS, AME_NBOF_OUTPUTS,
                              num_input_index, num_output_index, input_index, output_index,
                              GInputVarNum, GOutputVarNum, 0.0, 1.0, 1.0, 0.1);
}
#endif

/* ============================================================== */

static void ModelAmeExit(AMESIMSYSTEM *amesys, int status)
{
   /* Will be catch by the state machine */
   amesys->ameExitStatus = status;
   longjmp(amesys->jump_env, status);
}

/**************************************************************
*                                                             *
* Function load_subdata_tables reads data for lookuptables    *
* mostly/only used for realtime                               *
*                                                             *
* 0106429                                                     *
* Move the include outside of function. The include now       *
* contains one function per table and a function that calls   *
* them all. This reduces the risk that a compiler crashes due *
* to a huge function.                                         *
**************************************************************/
#ifdef AME_TABLES_IN_MEMORY
#include "collision_.subdata.h"
#endif

static void load_subdata_tables(void)
{
#ifdef AME_TABLES_IN_MEMORY
   add_all_tables_to_memory();
#endif
}

/***********************************************************
   Purpose  :  Return Simcenter Amesim version used to generate the model C code
               It allows the client to update interface management for
               backward compatibility.
   Author	:  J.Andre
   Creation :  2016 - 09 - 05
   Inputs   :  None
   Outputs  :  Simcenter Amesim version
   Revision :
************************************************************/
static unsigned int AmesysGetVersion()
{
	/* Returned number indicates 10000* main verion + 100* SL version + minor */
   /* Eg. Rev15     (15.0.0)  => 150000 */
   /* Eg. Rev15SL1  (15.1.0)  => 150100 */
   /* Eg. Rev15.0.1 (15.0.1)  => 150001 */

   return AMEVERSION;
}

/***********************************************************
   Purpose  :  Return SoldTo ID which Simcenter Amesim model has been generated.
   Author	:  J.Andre
   Creation :  2017 - 02 - 13
   Inputs   :  None
   Outputs  :  SoldToID
   Revision :
************************************************************/
static const char* getSoldToID()
{
   return "For Internal Siemens PLM Use Only";
}

#ifdef AME_INPUT_IN_MEMORY
#include "collision_.globalparams.h"
#endif

/***********************************************************
   Purpose  : Load and evaluate model parameters from files
   Author   : J.Andre
   Created  : 2016 - 09 - 08
   Inputs   :
      amesys  : system
      errmsg  : error message
   Outputs  : Error code
   Revision :
************************************************************/
static AMESystemError loadModelParamFromDisk(AMESIMSYSTEM *amesys, AMESystemError *gpError,  AMESystemError *lpError, char *errmsg)
{
   AMESystemError ret;
   *gpError = AME_NO_ERROR;
   *lpError = AME_NO_ERROR;

   ret = AmeReadGPFile(amesys);

   if(ret == AME_NO_ERROR) {
      *gpError = AmeEvalGlobalParamList(amesys, 1, errmsg);
      *lpError = loadParameterFromFile(amesys->pModel, GetDataFileName(), errmsg);
   }
   return ret;
}

#ifdef AME_INPUT_IN_MEMORY

/***********************************************************
   Purpose    : Load and evaluate model parameters from memory
   Author	  : J.Andre
   Created on : 2016 - 09 - 08
   Inputs	  :
      amesys  : system
      errmsg  : error message
   Outputs	  : Parameter error code
   Revision   :
************************************************************/
static AMESystemError loadModelParamFromMemory(AMESIMSYSTEM *amesys, AMESystemError *gpError,  AMESystemError *lpError, char * errmsg)
{
#include "collision_.data.h"

   ameAddGlobalParamsFromMemory(amesys,errmsg);

   if(amecheckversion(AMESIMRUNTIMEVERSION, __TIME__, __DATE__, NULL)) {
      amefprintf(stderr, "A problem with incompatible versions of the AMESim runtime library has been found.");
   }

   *gpError = AmeEvalGlobalParamList(amesys, 1, errmsg);
   *lpError = loadParameterFromDataTable(amesys->pModel, allparams, errmsg);

   return AME_NO_ERROR;
}

#endif

/***********************************************************
   Purpose    : Load and evaluate model parameters
   Author	  : J.Andre
   Created on : 2016 - 09 - 08
   Inputs	  :
      amesys  : system
      errmsg  : error message
   Outputs	  : Parameter error code
   Revision   :
************************************************************/
static AMESystemError loadModelParameters(AMESIMSYSTEM *amesys)
{
   AMESystemError res = AME_PARAMETER_ERROR;
   char errmsg[PATH_MAX+128];
   AMESystemError ret_gp = AME_NO_ERROR;
   AMESystemError ret_lp = AME_NO_ERROR;

   errmsg[0] = '\0';

#ifdef AME_INPUT_IN_MEMORY
#ifdef AME_RT_CAN_READ_FILE
   res = loadModelParamFromDisk(amesys, &ret_gp, &ret_lp, errmsg);

   if (res != AME_NO_ERROR) {
      /* If the file is not there - we say nothing */
      if (res != AME_PARAM_FILE_OPEN_ERROR) {
         amefprintf(stderr,"%s",errmsg);
         amefprintf(stderr,"loadParameterFromFile> %s\n",errmsg);
         ClearGPs();
      }
   }
   else {
      amefprintf(stderr,"Using data from disk (%s)\n",GetDataFileName());
   }
#endif
   if(res != AME_NO_ERROR) {
      /* Read all from memory */
      res = loadModelParamFromMemory(amesys, &ret_gp, &ret_lp, errmsg);
      SetGlobalParamReadFile(0);
   }
#else
   /* Read all from disk */
   res = loadModelParamFromDisk(amesys, &ret_gp, &ret_lp, errmsg);
#endif

   if( (res != AME_NO_ERROR) || (ret_gp != AME_NO_ERROR) || (ret_lp != AME_NO_ERROR) ) {
      amefprintf(stderr,"%s",errmsg);

      if( (res != AME_NO_ERROR) || (ret_lp != AME_NO_ERROR) ) {
         res = AME_GLOBAL_PARAMETER_ERROR;
      }
   }
   return res;
}

static AMESystemError Input(AMESIMSYSTEM *amesys)
{
   int retval;

   /* Load data files for submodels */
   load_subdata_tables();

   /* Load parameters for submodels */
   retval = loadModelParameters(amesys);

   /* Ensure parameters seen by RT is initialized correctly */
#ifdef AME_MEMORY_ACCESS_RT_EXPORT
   RT_Get_Watch_Param(amesys);
#endif

   return retval;
}

static int ameSetOptions(AMESIMSYSTEM *amesys,
                         double tsaveinc,
                         double maxstepsize,
                         double tolerance,
                         int errorcontrol,
                         int writelevel,
                         int extradisconprint,
                         int runstats,
                         int theruntype,
                         int thesolvertype)
{
   SimOptSetVariableErrorType(amesys->simOptions, errorcontrol);
   SimOptSetVariableTol(amesys->simOptions, tolerance);
   SimOptSetDiscontinuityPrintoutEnabled(amesys->simOptions, extradisconprint);
   SimOptSetStatisticsEnabled(amesys->simOptions, runstats);
   SimOptSetCautiousSolverEnabled(amesys->simOptions, thesolvertype);
   simSetSimRunType(amesys->simOptions, theruntype);
   bool enabled = writelevel != 2 ? true : false;
   SimOptSetMonitorTimeEnabled(amesys->simOptions, enabled);
   SimOptSetTInc(amesys->simOptions, tsaveinc);
   SimOptSetVariableHMax(amesys->simOptions, maxstepsize);

   /* Copy sim option to share with libraries before to modify it */
   SimOptCopySimOptions(amesys->sharedSimOptions, amesys->simOptions);
   bool cautious_enabled;
   SimOptIsCautiousSolverEnabled(amesys->simOptions, &cautious_enabled);
   if(cautious_enabled) {
      /* It is the cautious option. The maximum time step
         should not exceed the print interval. */
      double tInc;
      SimOptGetTInc(amesys->simOptions, &tInc);
      setmaxstep_(&tInc);
   }

#if( AME_MODEL_ISEXPLICIT == 1) && (AME_NBOF_EXPLICIT_STATE == 0 )
   if(maxstepsize > tsaveinc) {
      amefprintf(stderr, "Since the model has no state variable,\n");
      amefprintf(stderr, "the maximum time step has been reduced to %gs.\n", tsaveinc);
      double tInc;
      SimOptGetTInc(amesys->simOptions, &tInc);
      setmaxstep_(&tInc);
   }
#endif

   SetInitPrintIntervalFromSimOpts(amesys);

   ValidateRuntype(theruntype);


   return 1;
}

static int ameSetOptionsFixed(AMESIMSYSTEM *amesys,
                              double printinterval,
                              int fixed_type,
                              int fixedOrder,
                              double fixed_h,
                              int run_type)
{

   SimOptSetMonitorTimeEnabled(amesys->simOptions, false);

   ValidateRuntype(run_type);

	/* Ensure that runflag StabilizingRun=0. It might have been set to true */
	/* due to a previous selection for the variable step integrator. */
   ClearStabilizingRun();

   SimOptSetFixedOrder(amesys->simOptions, fixedOrder);
   simOptSetFixedStep(amesys->simVOptions, 1); /* Yes - fixed step */
   SimOptSetFixedH(amesys->simOptions, fixed_h);

   SimOptSetTInc(amesys->simOptions,  printinterval);
   SimOptSetDiscontinuityPrintoutEnabled(amesys->simOptions, false);  /* No discontinuity printout using fixed step solver */

   simOptSetFixedType(amesys->simVOptions, fixed_type);
   SetIsUsingFixedSolver(( fixed_type == 1)*100 +  (fixed_type != 1)*200 + fixedOrder);

   SetFixedTimeStep(fixed_h);

   return 1;
}

static int ameInputs(AMESIMSYSTEM *amesys, int numInputs, const double *inputARG)
{
   if(numInputs != amesys->numinputs)
   {
      char error_message[256];
      sprintf(error_message, "AMEInputs> Expected %d inputs but got %d\n", amesys->numinputs, numInputs);
      DisplayMessage(error_message);
      return 0;
   }
#if (AME_NBOF_INPUTS > 0)
   memcpy(amesys->inputs, inputARG, amesys->numinputs*sizeof(double) );
#endif
   return 1;
}

static void doAssembly(AMESIMSYSTEM *amesys)
{
   if (IsAssemblyNecessary_())
   {
      double time = getstarttime_();
      double tmp[AME_NBOF_SOLVER_STATES];
      int local_flag;

      /* Perform the assembly. */
      amesys->consflag = 1;
      local_flag = 0;
#if(AME_MODEL_ISEXPLICIT == 1)
      amesys->FuncEval(amesys, time, amesys->states, tmp, NULL, &local_flag);
#else
      amesys->res(amesys, time, amesys->states, amesys->dotstates, tmp, &local_flag);
#endif
      amesys->first_call = 1;

      amesys->consflag = 2;
      local_flag = 0;
#if(AME_MODEL_ISEXPLICIT == 1)
      amesys->FuncEval(amesys, time, amesys->states, tmp, NULL, &local_flag);
#else
      amesys->res(amesys, time, amesys->states, amesys->dotstates, tmp, &local_flag);
#endif
      amesys->first_call = 1;
      amesys->consflag = 0;
   }
}

static int ameEvalTstart(AMESIMSYSTEM *amesys, const double *modelInputs, double *modelOutputs)
{
#ifndef AMERT
   double time = getstarttime_();

   ameInputs(amesys, AME_NBOF_INPUTS, modelInputs);

   doAssembly(amesys);

   /* Initialize, maybe perform an initialising run */

   if(isstabrun_())
   {
      simOptSetFixedTime(amesys->simVOptions, time);
   }
   int stabilOption;
   simGetSimStabilOption(amesys->simOptions, &stabilOption);
   bool cautious_enabled;
   SimOptIsCautiousSolverEnabled(amesys->simOptions, &cautious_enabled);
   int cautious = cautious_enabled ? 1 : 0;
   stabilOption += 4*cautious;
   simSetSimStabilOption(amesys->simOptions,stabilOption);

#if(AME_MODEL_ISEXPLICIT == 1)

   if(!IntegrateInit(amesys, time, time))
   {
      return 0;
   }
#else
   bool is_enabled = false;
   amesys->internal_discont = 1;
   double tInc;
   SimOptGetTInc(amesys->simOptions, &tInc);
   double hMax;
   SimOptGetVariableHMax(amesys->simOptions, &hMax);
   int statistics;
   SimOptIsStatisticsEnabled(amesys->simOptions, &is_enabled);
   statistics = is_enabled ? 1 : 0;

   double abstol;
   simOptGetAbsTol(amesys->simOptions, &abstol);   
   double reltol;
   simOptGetRelTol(amesys->simOptions, &reltol);
   int iWrite = 0;

   SimOptIsMonitorTimeEnabled(amesys->simOptions, &is_enabled);
   iWrite = is_enabled ? 0 : 2;
   int minimalDiscont;
   SimOptIsMinDiscHandlingEnabled(amesys->simOptions, &is_enabled);   
   minimalDiscont = is_enabled ? 1 : 0;

   SimOptIsDiscontinuityPrintoutEnabled(amesys->simOptions, &is_enabled);
   int rStrtp = is_enabled ? 1 : 0;
   DIntegrateInit(amesys, AME_NBOF_EXPLICIT_STATE, time, getfinaltime_(), tInc, amesys->states,
                  amesys->dotstates, hMax, AME_NBOF_SOLVER_STATES, amesys->iwork, reltol, abstol, rStrtp, LIW, LRW, statistics, stabilOption, iWrite, minimalDiscont, Gis_constraint);

   if(isstabrun_())
   {
      /* HELP !!!! */
   }
#endif

#if (AME_NBOF_OUTPUTS > 0)
   memcpy(modelOutputs, amesys->outputs, amesys->numoutputs*sizeof(double) );
#endif
   amesys->tlast = time;

   return 1;
#else
   char error_message[256];
   sprintf(error_message, "ameEvalTstart> Should never be called for real-time simulation\n");
   DisplayMessage(error_message);
   return 0;
#endif
}

static int ameSetUpLockedStatus(AMESIMSYSTEM *amesys)
{
#ifdef AME_INPUT_IN_MEMORY
#include "collision_.lock.h"
   if(0 != SetUpLockedStatesFromMemory(amesys, lockedstates_length, lockedstates_array))
   {
      amefprintf(stderr,"Failed to set the locked states status.\n");
   }
#else
   SetUpLockedStates(GetCircuitName());
#endif
   return 0;
}

static int ameInitializeConditions(AMESIMSYSTEM *amesys)
{
#ifdef AME_VSOLVER_ACCEPTED
   double time;
   SimOptGetTStart(amesys->simOptions, &time);

   double tFinal;
   SimOptGetTFinal(amesys->simOptions, &tFinal);

   /* Initialise some static variables */
   setfinaltime_(tFinal);

   amesys->first_call=1;  /* should this be done or not ?*/
   amesys->internal_discont = 1;

   amesys->tlast = TLAST_MIN;

   memset(amesys->ecount,0,amesys->numstates*sizeof(int));
   memset(amesys->dotstates,0,amesys->numstates*sizeof(double));

#if(AME_MODEL_ISEXPLICIT == 0)
   memset(amesys->iwork,0,LIW*sizeof(int));
#endif
   /*  The following statement covers the case where there are
       no state variables y. */
#if( AME_NBOF_EXPLICIT_STATE == 0 )
   amesys->states[0] = 0.0;
#endif

   /* Call Input to read submodel and simulation parameters. */
   if(Input(amesys) != AME_NO_ERROR) return 0;
   modelSetInitValues(amesys->pModel, amesys->states, amesys->discrete_states);

   /* Register print interval that maybe used bys some submodels */
   SetInitPrintIntervalFromSimOpts(amesys);

   setstarttime_(time);

   /* Call pre-initialize function */

   PreInitialize(amesys,amesys->states);

#ifndef AME_INPUT_IN_MEMORY
   if( NeedReloadInputFiles() != 0 )
   {
      ClearGPs();
      if(Input(amesys) != AME_NO_ERROR) return 0;
      modelSetInitValues(amesys->pModel, amesys->states, amesys->discrete_states);
      ClearReloadedFiles();
   }
#endif

   /* Call initialize subroutine to set con and icon array members */

   Initialize(amesys,amesys->states);

   /* At this point, SIMP00 init as been called and we know what Jacobian
   heuristic and Jacobian storage will be used as well as tolerance method.
   Inform the end user of default behavior modification. */
   InformAboutJacHeurJacStorageAndJacPertAndTolMethod(amesys);

   /* Overwriting initial state values with requests emitted by */
   /* submodels that have a more global view (cf. register.c mechanism) */
   /* Can also fire some callbacks to 'fix' float and integer store */
   OverloadStatesWithRegister(amesys, amesys->states, SVREGISTER_DEFAULT);

   double abstol;
   double reltol;
   double hMax;

   simOptGetAbsTol(amesys->simOptions, &abstol);
   simOptGetRelTol(amesys->simOptions, &reltol);
   SimOptGetVariableHMax(amesys->simOptions, &hMax);

   CheckSimParams(amesys, &abstol, &reltol, &hMax);

   SimOptSetVariableHMax(amesys->simOptions, hMax);


#ifdef AME_RESULT_FILE
   /*  Open file for results. */
   amesys->AmeReadFile(amesys, &time, amesys->states);
#endif

   if(isconrun_() || isusefinval_())
   {
      updateStatesFromModel(amesys, amesys->states, AME_CONTINUOUS_STATE|AME_DISCRETE_STATE);
   }

   /* Read linear analysis specification. */
#ifndef FMI

   SetLADetails(GetLAFileName(), amesys->numstates, amesys->numvars, time,  reltol, abstol, getfinaltime_()-time);

   /* Remove old err file */

   remove(GetErrorFileName());

   /* Initialize the Performance analyzer */
   if(!isfixedstepsolver_()) {
      PerfAnalyzer_Init(amesys, time, getfinaltime_() );
   }
#endif
   if(isconrun_())
      setstarttime_(time);

   /* Set the locked states info */
   ameSetUpLockedStatus(amesys);

   return 1;
#else
   char error_message[256];
   sprintf(error_message, "AMEInitializeConditions> Should never be called for real-time simulation\n");
   DisplayMessage(error_message);
   return 0;
#endif
}

#if(AME_MODEL_ISEXPLICIT == 1)
static int ameEvalTstartFixed(AMESIMSYSTEM *amesys, const double *modelInputs, double *modelOutputs)
{
   double time = getstarttime_();

   ameInputs(amesys, AME_NBOF_INPUTS, modelInputs);

   doAssembly(amesys);

   amesys->tlast = time;

   /* Evaluation of the model at tStart */
   {
      int local_flag = 0;
      SetIsPrinting(amesys);
      amesys->FuncEval(amesys, time, amesys->states, amesys->yh, NULL, &local_flag);
      ClearIsPrinting(amesys);

#if defined(AME_RESULT_FILE) && !defined(STANDALONESIMULATOR)
      amesys->OutputResults(amesys, amesys->tlast);
      amesys->resultFileStructPtr->lastprinttime = amesys->tlast;
#endif

      /* Now, amesys->first_call == 0 (set at the end of FunctionEval) */
   }

#if (AME_NBOF_OUTPUTS > 0)
   memcpy(modelOutputs, amesys->outputs,amesys->numoutputs*sizeof(double) );
#endif
   amesys->tlast = time;

#ifdef AME_PROCESS_TIME
   /* Initialization of time timers */
   ProcessTime(0);
#endif

   return 1;
}

static int ameInitializeConditionsFixed(AMESIMSYSTEM *amesys)
{
   int using_amesim_solver=1;
   double tStart;
   SimOptGetTStart(amesys->simOptions, &tStart);
   double tFinal;
   SimOptGetTFinal(amesys->simOptions, &tFinal);

   double start_time = tStart;

   assert(amesys);

   amesys->first_call=1;  /* should this be done or not ?*/

   amesys->tlast=TLAST_MIN;

   /* Init solver */
   memset(amesys->yh,0,(AME_NBOF_SOLVER_STATES*13)*sizeof(double));
   
   InitFixedStepIntegrate(amesys, using_amesim_solver );

   setfinaltime_(tFinal);

   /* Call Input to read submodel and simulation parameters. */
   if(Input(amesys) != AME_NO_ERROR) return 0;
   modelSetInitValues(amesys->pModel, amesys->states, amesys->discrete_states);

   SetInitPrintIntervalFromSimOpts(amesys);

   setstarttime_(start_time);

   /* Call pre-initialize function */

   PreInitialize(amesys,amesys->states);

#ifndef AME_INPUT_IN_MEMORY
   if( NeedReloadInputFiles() != 0 )
   {
      ClearGPs();
      if(Input(amesys) != AME_NO_ERROR) return 0;
      modelSetInitValues(amesys->pModel, amesys->states, amesys->discrete_states);
      ClearReloadedFiles();
   }
#endif

   /* Call initialize subroutine to set con and icon array members */

   Initialize(amesys,amesys->states);

   /* Overwriting initial state values with requests emitted by */
   /* submodels that have a more global view (cf. register.c mechanism) */
   /* Can also fire some callbacks to 'fix' float and integer store */
   OverloadStatesWithRegister(amesys, amesys->states, SVREGISTER_DEFAULT);

#ifdef AME_RESULT_FILE
   /*  Open file for results. */
   amesys->AmeReadFile(amesys, &start_time, amesys->states);
#endif

   if(isconrun_() || isusefinval_())
   {
      updateStatesFromModel(amesys, amesys->states, AME_CONTINUOUS_STATE|AME_DISCRETE_STATE);
   }

   /* Set the locked states info */
   ameSetUpLockedStatus(amesys);

   if(isconrun_()) {
      setstarttime_(start_time);
   }

   return 1;
}
#endif

/*=============================================================================*/

/*=============================================================================*/

/***********************************************************
   Purpose    : Test request acceptance
   Author	  : J.Andre
   Created on : 2016 - 09 - 05
   Inputs	  :
      event   : entry event
   Outputs	  :
      AME_NO_ERROR : event accepted
      AME_SEQUENCE_ERROR : event refused
   Revision   :
************************************************************/
static AMESystemError AmesysControlRequest(AMESIMSYSTEM *amesys, AMESystemCmd event)
{
   AMESystemError res = AME_NO_ERROR;

   if(!amesys) {
      if(event == AME_CMD_GET_MODEL_INFO) {
         return AME_NO_ERROR;
      }
      return AME_SEQUENCE_ERROR;
   }

   switch(event) {
      case AME_CMD_RELEASE: {
         if( !(amesys->systemState & (AMESTATE_TERMINATED | AMESTATE_FATAL | AMESTATE_INSTANTIATED)) ) {
            res = AME_SEQUENCE_ERROR;
         }
      }
      break;
      case AME_CMD_SETUP: {
         if( !(amesys->systemState & AMESTATE_INSTANTIATED) ) {
            res = AME_SEQUENCE_ERROR;
         }
      }
      break;
      case AME_CMD_INITIALIZE: {
         if(amesys->systemState != AMESTATE_READY) {
            res = AME_SEQUENCE_ERROR;
         }
      }
      break;
      case AME_CMD_TERMINATE: {
         if( !(amesys->systemState & (AMESTATE_RUN | AMESTATE_READY | AMESTATE_ERROR)) ) {
            res = AME_SEQUENCE_ERROR;
         }
      }
      break;
      case AME_CMD_TSTART: {
         if( !(amesys->systemState & AMESTATE_INITIALIZED) ) {
            res = AME_SEQUENCE_ERROR;
         }
      }
      break;
      case AME_CMD_STEP: {
         if( !(amesys->systemState & AMESTATE_RUNNING) ) {
            res = AME_SEQUENCE_ERROR;
         }
         else {
            amesys->systemState |= AMESTATE_STEP_IN_PROGRESS;
         }
      }
      break;
      case AME_CMD_RESTART: {
         /* At this time, it is not still implemented */
         /* Depends of clean-up in terminated state and static variables */
         res = AME_SEQUENCE_ERROR;
      }
      break;
      case AME_CMD_GET_MODEL_INFO: {
         res = AME_NO_ERROR;
      }
      break;
      case AME_CMD_SET_MODEL_PARAM_TUNABLE: {
         if( !(amesys->systemState & (AMESTATE_READY | AMESTATE_RUN)) ) {
            res = AME_SEQUENCE_ERROR;
         }
      }
      break;
      case AME_CMD_SET_MODEL_PARAM:
      case AME_CMD_SET_RUN_PARAM:
      case AME_CMD_SET_SOLVER_PARAM: {
         if(amesys->systemState != AMESTATE_READY) {
            res = AME_SEQUENCE_ERROR;
         }
      }
      break;
      case AME_CMD_GET_MODEL_PARAM:
      case AME_CMD_GET_SOLVER_PARAM:
      case AME_CMD_GET_RUN_PARAM: {
         if( !(amesys->systemState & (AMESTATE_READY | AMESTATE_RUN | AMESTATE_ERROR)) ) {
            res = AME_SEQUENCE_ERROR;
         }
      }
      break;
      case AME_CMD_REQ_RUN_INTERRUPT: {
         if( !(amesys->systemState & (AMESTATE_INSTANTIATED | AMESTATE_READY | AMESTATE_INITIALIZED | AMESTATE_RUNNING)) ) {
            res = AME_SEQUENCE_ERROR;
         }
      }
      break;
      case AME_CMD_SET_ENV: {
         if( !(amesys->systemState & AMESTATE_INSTANTIATED) ) {
            res = AME_SEQUENCE_ERROR;
         }
      }
      break;
      case AME_CMD_FUNCEVAL: {
         if( !(amesys->systemState & AMESTATE_RUNNING) ) {
            res = AME_SEQUENCE_ERROR;
         }
      }
      break;
      default:
         res = AME_SEQUENCE_ERROR;
      break;
   }

   return res;
}

/***********************************************************
   Purpose    : Update state and manage result of request
   Author	  : J.Andre
   Created on : 2016 - 09 - 05
   Inputs	  :
      event   : entry event
      reqResult : result of request achievement
   Outputs	  :
      AME_NO_ERROR : event accepted
      AME_SEQUENCE_ERROR : event refused
   Revision   :
************************************************************/
static AMESystemError AmesysUpdateState(AMESIMSYSTEM *amesys, AMESystemCmd event, AMESystemError reqResult)
{
   unsigned int newState;
   AMESystemError res;

   if(!amesys) {
      return AME_SEQUENCE_ERROR;
   }

   newState = amesys->systemState;   /* Default: no change in state */
   res = reqResult;                  /* Default: no change in result */

   switch(event) {
      case AME_CMD_INSTANTIATE: {
         if(reqResult != AME_NO_ERROR) {
            newState = AMESTATE_FATAL;
         }
         else {
            newState = AMESTATE_INSTANTIATED;
         }
      }
      break;
      case AME_CMD_SETUP: {
         if(reqResult != AME_NO_ERROR) {
            newState = AMESTATE_FATAL;
         }
         else {
            newState = AMESTATE_READY;
         }
      }
      break;
      case AME_CMD_INITIALIZE: {
         if(reqResult != AME_NO_ERROR) {
            newState = AMESTATE_ERROR;
         }
         else {
            newState = AMESTATE_INITIALIZED;
         }
      }
      break;
      case AME_CMD_TERMINATE: {
         if(reqResult != AME_NO_ERROR) {
            amesys->systemState = AMESTATE_TERMINATED; /* Avoid automatic call to ameterminate */
            newState = AMESTATE_FATAL;
         }
         else {
            newState = AMESTATE_TERMINATED;
         }
      }
      break;
      case AME_CMD_TSTART: {
         if(reqResult != AME_NO_ERROR) {
            newState = AMESTATE_ERROR;
         }
         else {
            newState = AMESTATE_RUNNING;
         }
      }
      break;
      case AME_CMD_STEP: {
         if(reqResult != AME_NO_ERROR) {
            /* test ameExitStatus */
            if(reqResult == AME_EXIT_ERROR) {
               if(amesys->ameExitStatus == 0) {
                  /* Simulation stopped early but normally */
                  amesys->requestinterrupt = 0;
                  newState = AMESTATE_STOPPED_EARLY;
                  res = AME_NO_ERROR;
               }
               else
               {
                  newState = AMESTATE_ERROR;
               }
            }
            else {
               newState = AMESTATE_ERROR;
            }
         }
         else if(amesys->requestinterrupt) {
            amesys->requestinterrupt = 0;
            newState = AMESTATE_STOPPED_END;
         }
         newState &= ~AMESTATE_STEP_IN_PROGRESS;
      }
      break;
      case AME_CMD_REQ_RUN_INTERRUPT:
      break;
      case AME_CMD_FUNCEVAL: {
         if(reqResult != AME_NO_ERROR) {
            /* test ameExitStatus */
            if(reqResult == AME_EXIT_ERROR) {
               if(amesys->ameExitStatus == 0) {
                  /* Simulation stopped early but normally */
                  newState = AMESTATE_STOPPED_EARLY;
                  res = AME_NO_ERROR;
               }
               else
               {
                  newState = AMESTATE_ERROR;
               }
            }
            else {
               newState = AMESTATE_ERROR;
            }
         }
      }
      break;
      default:
      /* No state change, no exception to catch, just pass result */
      break;
   }

   if(amesys->systemState != newState) {
      if(newState == AMESTATE_FATAL) {
         if(amesys->systemState & (AMESTATE_RUN | AMESTATE_READY | AMESTATE_ERROR)) {
            /* Terminating the simulation */
            ameTerminate(amesys);
         }
      }

#if !defined(STANDALONESIMULATOR)
      if(newState & (AMESTATE_FATAL | AMESTATE_ERROR)) {
         if(amesys->systemState & AMESTATE_RUN) {
            amefprintf(stderr, "Simcenter Amesim model: simulation failed.\n");
         }
         else if(amesys->systemState & AMESTATE_IDLE) {
            amefprintf(stderr, "Simcenter Amesim model: instantiation failed.\n");
         }
         else if(amesys->systemState & AMESTATE_READY) {
            amefprintf(stderr, "Simcenter Amesim model: initialization failed.\n");
         }
      }
      else if(newState & AMESTATE_INITIALIZED) {
         amefprintf(stdout, "Simcenter Amesim model: initialization done.\n");
      }
      else if(newState & AMESTATE_TERMINATED) {
         amefprintf(stdout, "Simcenter Amesim model: simulation terminated.\n");
      }
      else if((newState & AMESTATE_RUNNING) && (amesys->systemState & AMESTATE_INITIALIZED)) {
         amefprintf(stdout, "Simcenter Amesim model: simulation started.\n");
      }
#endif

      /* Update state */
      amesys->systemState = newState;
   }

   if(amesys->systemState == AMESTATE_FATAL) {
      /* Greedy error */
      res = AME_FATAL_ERROR;
   }

   return res;
}

/***********************************************************
   Purpose    : Instantiate the system
   Author	  : J.Andre
   Created on : 2016 - 09 - 08
   Inputs	  : None
   Outputs	  : Error code
   Revision   :
************************************************************/
static AMESystemError AmesysInstantiate(AMESIMSYSTEM **amesysPtr)
{
   int jump_ret;
   AMESIMSYSTEM *amesys;
   AMESystemError result = AME_FATAL_ERROR;

   S_AME_Model *pModel;

   if(*amesysPtr != NULL) {
      return AME_SEQUENCE_ERROR;
   }

   result = createModel(&pModel, &GmodelDef, GParamInfo, GVarInfo, GsubmodelNameArray,
                        GcontStateVarNum, GdiscStateVarNum, GFixedVarNum);

   if(result == AME_NO_ERROR) {
#if(AME_MODEL_ISEXPLICIT == 1)
      amefprintf(stdout, "Instantiating a system with %d unknowns.\n", AME_NBOF_EXPLICIT_STATE);
#else
      amefprintf(stdout, "Instantiating a system with %d unknowns.\n", AME_NBOF_SOLVER_STATES);
#endif
      if (strcmp(soldToId,"not available") != 0)
         amefprintf(stdout, "Simcenter Amesim version: %s (%s).\n", "2604", soldToId);
      else
         amefprintf(stdout, "Simcenter Amesim version: %s.\n", "2604");
      result = createAMESystem(&amesys, pModel, AME_NBOF_SOLVER_STATES, AMEVERSION);
   }
#if (AME_NB_SUBMODEL_REF>0)
   if(result == AME_NO_ERROR) {
      int idx_sub;
      for(idx_sub = 0; idx_sub < AME_NB_SUBMODEL_REF; idx_sub++) {
         S_AMESubSimuInfo info;
         info.rp = SUBSTRUC[idx_sub].SUBSIMU[0][0] > 0 ? &pModel->realParamArray[SUBSTRUC[idx_sub].SUBSIMU[0][1]] : NULL;
         info.ip = SUBSTRUC[idx_sub].SUBSIMU[1][0] > 0 ? &pModel->integerParamArray[SUBSTRUC[idx_sub].SUBSIMU[1][1]] : NULL;
         info.tp = (const char **)(SUBSTRUC[idx_sub].SUBSIMU[2][0] > 0 ? &pModel->textParamArray[SUBSTRUC[idx_sub].SUBSIMU[2][1]] : NULL);
         info.c = SUBSTRUC[idx_sub].SUBSIMU[3][0] > 0 ? &pModel->realStoreArray[SUBSTRUC[idx_sub].SUBSIMU[3][1]] : NULL;
         info.ic = SUBSTRUC[idx_sub].SUBSIMU[4][0] > 0 ? &pModel->intStoreArray[SUBSTRUC[idx_sub].SUBSIMU[4][1]] : NULL;
         info.ps = SUBSTRUC[idx_sub].SUBSIMU[5][0] > 0 ? &pModel->pointerStoreArray[SUBSTRUC[idx_sub].SUBSIMU[5][1]] : NULL;
         info.na = pModel->ptrNetWorkArray;
         result |= setSubSimuParam(pModel, idx_sub, &info);
      }
   }
#endif

   if(result == AME_NO_ERROR) {
      if( (jump_ret = setjmp(amesys->jump_env)) == 0) { /* ~try */
         SetGlobalSystem(amesys);

         amesys->consflag = 0;

#if(AME_MODEL_ISEXPLICIT == 1)
         amesys->FuncEval = localFuncEval;
         amesys->JFuncEval = localJFuncEval;
#else
         amesys->res = localFuncEval;
         amesys->Jres = localJFuncEval;
#endif
         amesys->AmeExit = ModelAmeExit;

         amesys->ameExitStatus = 0;

         /* Set input directory to current directory */
         AmeSetInputDir(amesys,NULL);

         /* Set output directory to current directory */
         AmeSetOutputDir(amesys,NULL);

         /* Set base name of input files, no extension */
         AmeSetModelBaseName(amesys,"collision_", NULL);

         result = AME_NO_ERROR;
      }
      else { /* Catch AmeExit */
         result = AME_EXIT_ERROR;
      }
   }

   if(result == AME_NO_ERROR) {
      /* Update state and result */
      result =  AmesysUpdateState(amesys, AME_CMD_INSTANTIATE, result);
   }

   if(result != AME_NO_ERROR) {
      deleteAMESystem(&amesys);
      SetGlobalSystem(NULL);
   }
   else {
      *amesysPtr = amesys;
   }

   return result;
}

static AMESystemError AmesysTerminate(AMESIMSYSTEM *amesys)
{
   int jump_ret;
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_TERMINATE);
   if(res != AME_NO_ERROR) {
      /* Request not accepted */
      return res;
   }

   if(res == AME_NO_ERROR) { /* Request accepted */
      if( (jump_ret = setjmp(amesys->jump_env)) == 0) { /* ~try */
         ameTerminate(amesys);
      }
      else { /* Catch AmeExit */
         res = AME_EXIT_ERROR;
      }
   }

   /* Update state and result */
   res =  AmesysUpdateState(amesys, AME_CMD_TERMINATE, res);

   return res;
}

static AMESystemError AmesysRelease(AMESIMSYSTEM **amesysPtr)
{
   AMESystemError res = AME_NO_ERROR;
   if(*amesysPtr) {
      SetGlobalSystem(*amesysPtr);
      res = AmesysControlRequest(*amesysPtr, AME_CMD_RELEASE);

      if(res == AME_NO_ERROR) { /* Request accepted */
         AmeSignalModelUnload();
         res = deleteAMESystem(amesysPtr);
         SetGlobalSystem(NULL);
      }
   }
   return res;
}

/***********************************************************
   Purpose    : Go in Ready state to be able receive external
                initialization of model and simulation
   Author	  : J.Andre
   Created on : 2016 - 09 - 08
   Inputs	  : loadParam: if true, model parameters are read
   Outputs	  : Error code
   Revision   :
************************************************************/
static AMESystemError AmesysSetUp(AMESIMSYSTEM *amesys, const int loadParam)
{
   int jump_ret;
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SETUP);

   if(res != AME_NO_ERROR) {
      /* Request not accepted */
      return res;
   }

   if( (jump_ret = setjmp(amesys->jump_env)) == 0) { /* ~try */
      amesys->ameExitStatus = 0;

      /* Construct file names */
      AmeConstructFileName(amesys);

      /* Read sim file */
      {
         SIMOptions *opts = NULL;

         SimOptStatus status;
         status = SimOptCreateSimOptions(&opts);
         SIMVolatileOptions vopts = {0};
#ifndef AME_INPUT_IN_MEMORY
#ifndef AMEHAVENOSTDIO
         char errMsg[PATH_MAX+128];
         SimOptStatus result = SimOptReadSimFile(opts, GetCircuitName(), GetBatchRunNumber());
         if(result != SimOptStatusSuccess)
         {
            amefprintf(stderr, "%s \n", SimOptGetLastErrorMessage());
         }

#else
         amefprintf(stderr,"Error: Invalid file_name in %s: Unable to open file.\n", GetSimFileName());
#endif
#else
         SimOptStatus result = SimOptReadSimFromCharArrays(opts, simparams, simparams_length);
#endif
         if(result == SimOptStatusSuccess) {
            
            simOptSetFixedStepFromSimOptions(&vopts, opts);
            simOptSetFixedTypeFromSimOptions(&vopts, opts);
            /* Initialyze Amesystem SIMOptions */
            SimOptCopySimOptions(amesys->simOptions, opts);
            /* Initialyze Amesystem SIMVolatileOptions */
            *amesys->simVOptions = vopts; // Perform a shallow copy
#ifdef AME_RESULT_FILE
            simOptSetOutOff(amesys->simVOptions, 0);
#else
            simOptSetOutOff(amesys->simVOptions, 1);
#endif

#ifdef AME_PERFORMANCE_ANALYZER
            bool is_enabled = false;
            SimOptIsAutoLAEnabled(opts, &is_enabled);
            int autoLA = is_enabled ? 1 : 0;
            double autoLAstep;
            SimOptGetAutoLAStep(opts, &autoLAstep);
            ALA_Setparam(autoLA, 1, autoLAstep);
            DISCLOG_SetParam(1);
#endif
         }
         else {
            res = AME_SETUP_ERROR;
         }
         SimOptDestroySimOptions(&opts);
      }

      if(loadParam) {
         /* Load parameters */
         loadModelParameters(amesys);
      }

   }
   else { /* Catch AmeExit */
      res = AME_EXIT_ERROR;
   }

   /* Update state and result */
   res =  AmesysUpdateState(amesys, AME_CMD_SETUP, res);

   return res;
}

/***********************************************************
   Purpose    : Initialize the model
   Author	  : J.Andre
   Created on : 2016 - 09 - 08
   Inputs	  : None
   Outputs	  : Error code
   Revision   :
************************************************************/
static AMESystemError AmesysInitialize(AMESIMSYSTEM *amesys)
{
   int jump_ret;
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_INITIALIZE);

   if(res != AME_NO_ERROR) {
      /* Request not accepted */
      return res;
   }

   if( (jump_ret = setjmp(amesys->jump_env)) == 0) { /* try */
      bool fixedIntegratorEnabled;
      SimOptIsFixedStepIntegratorEnabled(amesys->simOptions, &fixedIntegratorEnabled);
      if(fixedIntegratorEnabled) {
         /* fixed step initialization */
#if(AME_MODEL_ISEXPLICIT == 1)
         double tInc;
         SimOptGetTInc(amesys->simOptions, &tInc);
         double fixedH;
         SimOptGetFixedH(amesys->simOptions, &fixedH);
         int fixedType;
         simOptGetFixedType(amesys->simVOptions, &fixedType);
         int fixedOrder;
         SimOptGetFixedOrder(amesys->simOptions, &fixedOrder);
         int runType;
         simGetSimRunType(amesys->simOptions, &runType);
         ameSetOptionsFixed(amesys, tInc, fixedType,
            fixedOrder, fixedH, runType);

         if(!ameInitializeConditionsFixed(amesys)) {
            res = AME_INITIALIZE_ERROR;
         }
#else
         amefprintf(stderr,"It is not possible to use a fixed step solver\nfor implicit systems.\n");
         res = AME_INITIALIZE_ERROR;
#endif
      }
      else {
#ifdef AME_VSOLVER_ACCEPTED
         /* variable step initialization */
         double tInc;
         SimOptGetTInc(amesys->simOptions, &tInc);

         bool is_enabled;
         SimOptIsCautiousSolverEnabled(amesys->simOptions, &is_enabled);
         int cautious = is_enabled ? 1 : 0;

         double hMax;
         SimOptGetVariableHMax(amesys->simOptions, &hMax);

         SimOptIsDiscontinuityPrintoutEnabled(amesys->simOptions, &is_enabled);
         int rStrtp = is_enabled ? 1 : 0;
         int iWrite = 0;

         SimOptIsMonitorTimeEnabled(amesys->simOptions, &is_enabled);
         iWrite = is_enabled ? 0 : 2;
         int statistics;
         SimOptIsStatisticsEnabled(amesys->simOptions, &is_enabled);
         statistics = is_enabled ? 1 : 0;

         int runType;
         simGetSimRunType(amesys->simOptions, &runType);
         SimOptErrorType simopt_errorType;
         SimOptGetVariableErrorType(amesys->simOptions, &simopt_errorType);
         int errorType = (int)simopt_errorType;
         double tol;
         SimOptGetVariableTol(amesys->simOptions, &tol);

         ameSetOptions(amesys, tInc, hMax, tol,
            errorType, iWrite, rStrtp,
            statistics, runType, cautious);

         if(!ameInitializeConditions(amesys)) {
            res = AME_INITIALIZE_ERROR;
         }
#else
         amefprintf(stderr,"It is not possible to use a variable step solver\nfor this interface.\n");
         res = AME_INITIALIZE_ERROR;
#endif
      }

#if defined(AME_MEMORY_ACCESS_RT_EXPORT)
#if (NB_WATCH_VAR>0)
         RT_Get_Watch_Var(amesys);
#endif
#endif

   }
   else { /* Catch AmeExit */
      res = AME_EXIT_ERROR;
   }

   /* Update state and result */
   res =  AmesysUpdateState(amesys, AME_CMD_INITIALIZE, res);

   return res;
}

#if(AME_MODEL_ISEXPLICIT == 1)
static void doAFixedStep(AMESIMSYSTEM *amesys, double time)
{
   double timerange;
   double actual_timestep;
   int stepratio;
   int stepratio_ceil;
   int stepratio_floor;
   int i=0;
   int zero=0;
   double tinc;
   int isTimeForPrint=0;
   double next_print_time;

   if (amesys->first_call)
   {
      SetIsPrinting(amesys);
      amesys->FuncEval(amesys, amesys->tlast, amesys->states, amesys->yh, NULL, &zero);
      ClearIsPrinting(amesys);

#if defined(AME_RESULT_FILE) && !defined(STANDALONESIMULATOR)
      amesys->OutputResults(amesys, amesys->tlast);
      amesys->resultFileStructPtr->lastprinttime = amesys->tlast;
#endif
   }

   timerange = time - amesys->tlast;

   if(timerange <= 0.0)
   {
      return;
   }
   double fixedH;
   SimOptGetFixedH(amesys->simOptions, &fixedH);
   if(fixedH > 0.0)
   {
      stepratio = stepratio_ceil = (int)ceil(timerange/fixedH);
      stepratio_floor = (int)floor(timerange/fixedH);

      actual_timestep = timerange/(double)stepratio_ceil;

      if(fabs(actual_timestep-fixedH) > 0.001*fixedH)
      {
         if(stepratio_floor == 0)
         {
#ifdef AMEDEBUG
            amefprintf(stdout,"skipping %14.8e  range= %14.8e  actual_timestep=%14.8e stepratio_ceil=%d   stepratio_floor=%d\n",time, timerange, actual_timestep, stepratio_ceil,stepratio_floor);
#endif
            return;
         }

#ifdef AMEDEBUGw
         amefprintf(stdout,"using floor\n");
         amefprintf(stdout,"timerange=%14.8e\n", timerange);
         amefprintf(stdout,"actual_timestep=%14.8e\n", actual_timestep);
         amefprintf(stdout,"fixedH=%14.8e\n", fixedH);
         amefprintf(stdout,"fabs(actual_timestep-fixedH)=%14.8e\n", fabs(actual_timestep-fixedH));
         amefprintf(stdout,"stepratio_floor=%d\n", stepratio_floor);
         amefprintf(stdout,"stepratio_ceil=%d\n", stepratio_ceil);
#endif
         actual_timestep = timerange/(double)stepratio_floor;
         stepratio = stepratio_floor;
      }

      if(fabs(actual_timestep-fixedH) > 0.001*fixedH)
      {
#ifdef AMEDEBUGw
         amefprintf(stdout,"Adjusting time step %14.8e => %14.8e\n", fixedH, actual_timestep);
         amefprintf(stdout,"stepratio_floor=%d\n", stepratio_floor);
         amefprintf(stdout,"stepratio_ceil=%d\n", stepratio_ceil);
         amefprintf(stdout,"stepratio=%d\n", stepratio);
         amefprintf(stdout,"timerange=%14.8e\n", timerange);
#endif
      }
   }
   else
   {
      /* just single step from the last point in time when we were called */
      stepratio=1;
      actual_timestep = timerange;
   }

#if defined(AME_RESULT_FILE) && !defined(STANDALONESIMULATOR)
   if(amesys->resultFileStructPtr && !amesys->resultFileStructPtr->outoff)
   {
      double tInc;
      SimOptGetTInc(amesys->simOptions, &tInc);
      double tFinal;
      SimOptGetTFinal(amesys->simOptions, &tFinal);

      next_print_time = GetNextPrintTime(&tinc, amesys->resultFileStructPtr->lastprinttime, tFinal, tInc, actual_timestep);
   }
#endif

#ifdef AMERT
   /* Allow changes of the stepratio - typically on RT platforms. */
   {
      double localstepratio=floor(IL_collision_step_ratio);
      if (localstepratio >= 1)
      {
         actual_timestep=timerange/localstepratio;
         stepratio = (int)localstepratio;
      }
   }
#endif
#ifdef STANDALONESIMULATOR
   double _tInc;
   SimOptGetTInc(amesys->simOptions, &_tInc);
   int fixedOrder;
   SimOptGetFixedOrder(amesys->simOptions, &fixedOrder);
   int fixedType;
   simOptGetFixedType(amesys->simVOptions, &fixedType);
   FixedStepIntegrate(amesys,AME_NBOF_SOLVER_STATES,amesys->tlast,time, _tInc, amesys->states,
         amesys->yh, fixedType, fixedOrder,actual_timestep);
#else
   for (i=0; (i<stepratio) && (amesys->requestinterrupt == 0);i++)
   {
      int fixedType;
      simOptGetFixedType(amesys->simVOptions, &fixedType);
      int fixedOrder;
      SimOptGetFixedOrder(amesys->simOptions, &fixedOrder);
      /*Integrate one step */
      if ( fixedType == 1)
      {
         DoAnABStep(amesys, amesys->numstates, fixedOrder, &amesys->tlast, actual_timestep, amesys->states, amesys->yh);
      }
      else
      {
         DoAnRKStep(amesys, amesys->numstates, fixedOrder, &amesys->tlast, actual_timestep, amesys->states, amesys->yh);
      }

#ifndef AMERT
      isTimeForPrint = amesys->resultFileStructPtr && (!amesys->resultFileStructPtr->outoff && ((amesys->tlast >= next_print_time) || ((next_print_time-amesys->tlast)/tinc < TIME_ROUNDOFF)));
      if(isTimeForPrint)
      {
#ifdef AME_PROCESS_TIME
         ProcessTime(1);
#endif
         SetIsPrinting(amesys);
         amesys->FuncEval(amesys, amesys->tlast, amesys->states, amesys->yh, NULL, &zero);
         ClearIsPrinting(amesys);
         amesys->OutputResults(amesys,amesys->tlast);
         double _tInc;
         SimOptGetTInc(amesys->simOptions, &_tInc);
         double tFinal;
         SimOptGetTFinal(amesys->simOptions, &tFinal);
         next_print_time = GetNextPrintTime(&tinc, amesys->tlast, tFinal, _tInc, actual_timestep);
      }
      else
#endif
      {
         amesys->FuncEval(amesys, amesys->tlast, amesys->states, amesys->yh, NULL, &zero);
      }
   }
#endif
   amesys->tlast = time;
}
#endif

static int ameOutputs(AMESIMSYSTEM *amesys, double timeARG, int numOutputs, double *outputARG)
{
   int theprintflag=1;
   double *dot;
   double *v;

   assert(amesys);

   v = amesys->v;
   dot = amesys->dotstates;

   if(numOutputs != amesys->numoutputs)
   {
      char error_message[256];
      sprintf(error_message, "AMEOutputs> Expected %d outputs but got %d\n", amesys->numoutputs, numOutputs);
      DisplayMessage(error_message);
      AmeExit(1);
   }

   if (!isdynrun_())
   {
      /* it is not a dynamic run (neither dynamic nor stabilizing + dynamic) */
      /* stabilizing has already been processed during Init.*/
      /*Exit */
      return 1;
   }

   if(timeARG < amesys->tlast)
   {
      DisplayMessage("trying to integrate backwards\n");
      return 0;
   }
#if(AME_MODEL_ISEXPLICIT == 1)
   amesys->t_end_of_time_slice = timeARG;
#ifndef AMERT
   if(!isfixedstepsolver_())
   {
      if(!IntegrateStep(amesys, amesys->tlast, timeARG))
      {
         DisplayMessage("IntegrateStep failed");
         return 0;
      }
      amesys->tlast = timeARG;
   }
   else
   {
      doAFixedStep(amesys, timeARG);
   }
#else
   doAFixedStep(amesys, timeARG);
#endif

#else
   double tInc;
   SimOptGetTInc(amesys->simOptions, &tInc);   
   int stabilOption;
   simGetSimStabilOption(amesys->simOptions, &stabilOption);      
   double abstol;
   simOptGetAbsTol(amesys->simOptions, &abstol);   
   double reltol;
   simOptGetRelTol(amesys->simOptions, &reltol);   
   double hMax;
   SimOptGetVariableHMax(amesys->simOptions, &hMax);
   bool is_enabled;
   SimOptIsDiscontinuityPrintoutEnabled(amesys->simOptions, &is_enabled);
   int rStrtp = is_enabled ? 1 : 0;
   int iWrite = 0;

   SimOptIsMonitorTimeEnabled(amesys->simOptions, &is_enabled);
   iWrite = is_enabled ? 0 : 2;

   int minimalDiscont;
   SimOptIsMinDiscHandlingEnabled(amesys->simOptions, &is_enabled);   
   minimalDiscont = is_enabled ? 1 : 0;

   int statistics;
   SimOptIsStatisticsEnabled(amesys->simOptions, &is_enabled);
   statistics = is_enabled ? 1 : 0;

   if(!DIntegrateStep(amesys, AME_NBOF_EXPLICIT_STATE, amesys->tlast, timeARG, tInc, amesys->states,
      amesys->dotstates, hMax, AME_NBOF_SOLVER_STATES, amesys->iwork, reltol,
      abstol, rStrtp, LIW, LRW, statistics,
      stabilOption, iWrite, minimalDiscont,
      amesys->internal_discont, Gis_constraint, &amesys->requestinterrupt))
   {
      DisplayMessage("DIntegrateStep failed");
      return 0;
   }

   amesys->tlast = timeARG;
#endif

#if (AME_NBOF_OUTPUTS > 0)
   memcpy(outputARG, amesys->outputs, amesys->numoutputs*sizeof(double) );
#endif

   return 1;
}

static AMESystemError AmesysComputeAtTstart(AMESIMSYSTEM *amesys, const double *theInputs, double *theOutputs)
{
   int jump_ret;
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_TSTART);

   if(res != AME_NO_ERROR) {
      /* Request not accepted */
      return res;
   }

   if( (jump_ret = setjmp(amesys->jump_env)) == 0) { /* try */
      bool fixedIntegratorEnabled;
      SimOptIsFixedStepIntegratorEnabled(amesys->simOptions, &fixedIntegratorEnabled);
      if(fixedIntegratorEnabled) {
         /* fixed step solver */
#if(AME_MODEL_ISEXPLICIT == 1)
         if(!ameEvalTstartFixed(amesys, theInputs, theOutputs)) {
            res = AME_INITIALIZE_ERROR;
         }
#else
         amefprintf(stderr,"It is not possible to use a fixed step solver\nfor implicit systems.\n");
         res = AME_INITIALIZE_ERROR;
#endif
      }
      else {
         /* variable step solver */
         if(!ameEvalTstart(amesys, theInputs, theOutputs)) {
            res = AME_INITIALIZE_ERROR;
         }
      }

   }
   else { /* Catch AmeExit */
      res = AME_EXIT_ERROR;
   }

   /* Update state and result */
   res =  AmesysUpdateState(amesys, AME_CMD_TSTART, res);

   return res;
}

/***********************************************************
   Purpose    : Do a co-simulation step
   Author	  : J.Andre
   Created on : 2016 - 09 - 12
   Inputs	  : None
   Outputs	  : Error code
   Revision   :
************************************************************/
static AMESystemError AmesysStep(AMESIMSYSTEM *amesys, int stepType, const double t, const double *theInputs, double *theOutputs,
   const int doInterpol, const unsigned int *orderTab, const double **polyTab, const E_CS_Reset cs_reset)
{
   int jump_ret;
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_STEP);

   if(res != AME_NO_ERROR) {
      /* Request not accepted */
      return res;
   }

   if( (jump_ret = setjmp(amesys->jump_env)) == 0) { /* try */

#if defined(AME_MEMORY_ACCESS_RT_EXPORT)
#if (NB_WATCH_REAL_PARAM>0) || (NB_WATCH_INT_PARAM>0)
      RT_Set_Watch_Param(amesys);
#endif
#endif

#if defined(AME_COSIM) && (AME_NBOF_INPUTS > 0) && (!defined(AMERT))
      amesys->doInterpol = doInterpol;

      if(amesys->doInterpol) {
         stepType = 1;
         res = setPolyCosimSlave(amesys->csSlave, orderTab, polyTab);
      }
      else {
         res = setPolyCosimSlaveByInputs(amesys->csSlave, theInputs);
      }
#else
      amesys->doInterpol = 0;
#endif

      if(res == AME_NO_ERROR) {
         if(stepType == 0) {  /* Do a step */
            if(!ameOutputs(amesys, t, AME_NBOF_OUTPUTS, theOutputs)) {
               res = AME_STEP_ERROR;
            }
#ifndef AMERT
            amesys->input_discont = CheckIfColdStartNeed(amesys, theInputs, cs_reset);
            /* Need to do something here if no internal disc and disc printout */
            AddExtraPrintOut(amesys, amesys->tlast);
#endif
            if(amesys->doInterpol == 0) {
               if(!ameInputs(amesys, AME_NBOF_INPUTS, theInputs)) {
                  res = AME_STEP_ERROR;
               }
            }
         }
         else {  /* Do a step 2 */
#ifndef AMERT
            amesys->input_discont = CheckIfColdStartNeed(amesys, theInputs, cs_reset);

            /* Need to do something here if no internal disc and disc printout */
            res |= changePolynomialSlot(amesys->csSlave);
            AddExtraPrintOut(amesys, amesys->tlast);
            res |= changePolynomialSlot(amesys->csSlave);
#endif
            if(amesys->doInterpol == 0) {
               if(!ameInputs(amesys, AME_NBOF_INPUTS, theInputs)) {
                  res = AME_STEP_ERROR;
               }
            }

            if(!ameOutputs(amesys, t, AME_NBOF_OUTPUTS, theOutputs)) {
               res = AME_STEP_ERROR;
            }
#ifndef AMERT
            if(amesys->doInterpol != 0) {
               if( getInputsCosimSlave(amesys->csSlave, t, amesys->inputs) != AME_NO_ERROR ) {
                  res = AME_STEP_ERROR;
               }
            }
#endif
         }
         amesys->num_steps_taken++;
#ifndef AMERT
         res |= changePolynomialSlot(amesys->csSlave);
         res |= setTciCosimSlave(amesys->csSlave, t);
#endif
      }

#if defined(AME_MEMORY_ACCESS_RT_EXPORT)
#if (NB_WATCH_VAR>0)
      RT_Get_Watch_Var(amesys);
#endif
#endif
   }
   else { /* Catch AmeExit */
      res = AME_EXIT_ERROR;
   }

   /* Update state and result */
   res =  AmesysUpdateState(amesys, AME_CMD_STEP, res);

   return res;
}

/***********************************************************
   Purpose    : Set solver parameters
   Author	  : J.Andre
   Created on : 2016 - 09 - 09
   Inputs	  : None
   Outputs	  :
   Revision   :
************************************************************/
static AMESystemError AmesysSetSolverParam(AMESIMSYSTEM *amesys, const solverSettings *solver)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_SOLVER_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      /* Initialyze Amesystem solver parameters */
      simOptSetSolverParam(amesys->simOptions, amesys->simVOptions, solver);
   }

   return res;
}

/***********************************************************
   Purpose    : Get solver parameters
   Author	  : J.Andre
   Created on : 2016 - 09 - 09
   Inputs	  : None
   Outputs	  :
   Revision   :
************************************************************/
static AMESystemError AmesysGetSolverParam(AMESIMSYSTEM *amesys, solverSettings *solver)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_GET_SOLVER_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      /* Initialyze Amesystem solver parameters */
      simOptGetSolverParam(amesys->simOptions, amesys->simVOptions, solver);
   }

   return res;
}

/***********************************************************
   Purpose    : Set run parameters
   Author	  : J.Andre
   Created on : 2016 - 09 - 09
   Inputs	  : None
   Outputs	  :
   Revision   :
************************************************************/
static AMESystemError AmesysSetSimParam(AMESIMSYSTEM *amesys, const simSettings *simOpt)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_RUN_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      /* Initialyze Simulation parameters */
      simOptSetSimParam(amesys->simOptions,simOpt);
   }

   return res;
}

static AMESystemError AmesysGetSimParam(AMESIMSYSTEM *amesys, simSettings *simOpt)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_GET_RUN_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      /* Get Simulation parameters */
      simOptGetSimParam(amesys->simOptions, simOpt);
   }

   return res;
}

static AMESystemError AmesysSetSimItem(AMESIMSYSTEM *amesys, const int Id, const int enabled)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_RUN_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      /* Initialyze Amesystem solver parameters */
      if(simOptSetOneOfSimParam(amesys->simOptions, Id, enabled) != 0) {
         res = AME_SETTINGS_ERROR;
      }
   }

   return res;
}

static AMESystemError AmesysGetSimItem(AMESIMSYSTEM *amesys, const int Id, int *enabled)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_GET_RUN_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      /* Initialyze Amesystem solver parameters */
      if(simOptGetOneOfSimParam(amesys->simOptions, Id, enabled) != 0) {
         res = AME_SETTINGS_ERROR;
      }
   }

   return res;
}

/***********************************************************
   Purpose    : Set run parameters
   Author	  : J.Andre
   Created on : 2016 - 09 - 09
   Inputs	  : None
   Outputs	  :
   Revision   :
************************************************************/
static AMESystemError AmesysSetStdOptions(AMESIMSYSTEM *amesys, const stdOptions *stdOpt)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_RUN_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      /* Initialize standard parameters */
      simOptSetStdParam(amesys->simOptions,stdOpt);
   }

   return res;
}

static AMESystemError AmesysGetStdOptions(AMESIMSYSTEM *amesys, stdOptions *stdOpt)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_GET_RUN_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      /* Get standard parameter */
      simOptGetStdParam(amesys->simOptions, stdOpt);
   }

   return res;
}

static AMESystemError AmesysSetStdItem(AMESIMSYSTEM *amesys, const int Id, const int enabled)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_RUN_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      /* Initialize standard parameter */
      if(simOptSetOneOfStdParam(amesys->simOptions, Id, enabled) != 0) {
         res = AME_SETTINGS_ERROR;
      }
   }

   return res;
}

static AMESystemError AmesysGetStdItem(AMESIMSYSTEM *amesys, const int Id, int *enabled)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_GET_RUN_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      /* Initialize standard parameter */
      if(simOptGetOneOfStdParam(amesys->simOptions, Id, enabled) != 0) {
         res = AME_SETTINGS_ERROR;
      }
   }

   return res;
}

static AMESystemError AmesysSetALAParam(AMESIMSYSTEM *amesys, const autoLAOptions *alaOpt)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_RUN_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      /* Initialize standard parameters */
      bool is_enabled = false;
      is_enabled = (alaOpt->autoLAOpt & SIMOPT_AUTOLA_ACTIVATE) != 0;
      SimOptSetAutoLAEnabled(amesys->simOptions, is_enabled);
      SimOptSetAutoLAStep(amesys->simOptions, alaOpt->autoLAstep);
   }

   return res;
}

static AMESystemError AmesysGetALAParam(AMESIMSYSTEM *amesys, autoLAOptions *alaOpt)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_GET_RUN_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      /* Get standard parameter */
      bool is_enabled = false;
      SimOptIsAutoLAEnabled(amesys->simOptions, &is_enabled);
      if(is_enabled)
      {
         alaOpt->autoLAOpt |= SIMOPT_AUTOLA_ACTIVATE;
      }
      else
      {
         alaOpt->autoLAOpt &= ~SIMOPT_AUTOLA_ACTIVATE;
      }
      SimOptGetAutoLAStep(amesys->simOptions, &alaOpt->autoLAstep);
   }

   return res;
}

/***********************************************************
   Purpose     : Turn off/on results
   Author	   : J.Andre
   Created on  : 2016 - 09 - 09
   Inputs	   :
      outoff   :  0 : result file off
                  1 : result file on
   Outputs	   :
   Revision    :
************************************************************/
static AMESystemError AmesysEnableResult(AMESIMSYSTEM *amesys, const int out)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_RUN_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      if(out) {
         simOptSetOutOff(amesys->simVOptions, 0);
      }
      else {
         simOptSetOutOff(amesys->simVOptions, 1);
      }
   }

   return res;
}

/***********************************************************
   Purpose     : Return the state of Amesystem
   Author	   : J.Andre
   Created     : 2016 - 09 - 05
   Inputs	   : None
   Outputs	   :
      state    : machine state
   Revision    :
************************************************************/
static unsigned int AmesysGetState(AMESIMSYSTEM *amesys)
{
   if(amesys) {
      return amesys->systemState;
   }
   else {
      return AMESTATE_IDLE;
   }
}

static AMESystemError AmesysGetModelInfo(unsigned int *numinputs, unsigned int *numoutputs, unsigned int *numstates, unsigned int *numimplicits)
{
   *numinputs = AME_NBOF_INPUTS;
   *numoutputs = AME_NBOF_OUTPUTS;
   *numstates = AME_NBOF_EXPLICIT_STATE;
   *numimplicits = AME_NBOF_IMPLICIT_STATE;

   return AME_NO_ERROR;
}

static AMESystemError AmesysGetModelPortName(const char **inputName[], const char **outputName[])
{
   *inputName = GinputVarTitles;
   *outputName = GoutputVarTitles;

   return AME_NO_ERROR;
}

static AMESystemError AmesysGetModelNumParam(unsigned int *numParam)
{
   *numParam = AME_NBOF_PARAMS;

   return AME_NO_ERROR;
}

static AMESystemError AmesysGetParamType(const int nbParam, const int idx[], E_ParamCType paramType[])
{
   AMESystemError res = AME_NO_ERROR;
   int i;

   for(i = 0; (i < nbParam) && (res == AME_NO_ERROR); i++) {
      if(i < AME_NBOF_PARAMS) {
         switch(GParamInfo[idx[i]].category) {
            case E_Int_Param:
               paramType[i] = E_CType_IntParam;
            break;
            case E_Text_Param:
               paramType[i] = E_CType_StringParam;
            break;
            default:
               paramType[i] = E_CType_DoubleParam;
            break;
         }
         return AME_NO_ERROR;
      }
      else {
         res = AME_PARAM_IDX_ERROR;
      }
   }

   return res;
}

static AMESystemError AmesysFindParamFromVar(const int nbParam, const int varIdx[], int paramIdx[], E_ParamCategory category[])
{
   AMESystemError res = AME_NO_ERROR;
   int idx, i;

   for(idx = 0; (idx < nbParam) && (res == AME_NO_ERROR); idx++) {
      res = AME_PARAM_IDX_ERROR;
      for(i = 0; i < AME_NBOF_PARAMS; i++) {
         if(GParamInfo[i].varIdx == varIdx[idx]) {
            paramIdx[idx] = i;
            category[idx] = GParamInfo[i].category;
            res = AME_NO_ERROR;
         }
      }
   }

   return res;
}

static AMESystemError AmesysGetIntParamValue(AMESIMSYSTEM *amesys, const int nbParam, const int idx[], int value[])
{
   AMESystemError res;
   int i;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_GET_MODEL_PARAM);

   for(i = 0; (i < nbParam) && (res == AME_NO_ERROR); i++) {
      res = getIntParameter(amesys->pModel, idx[i], &value[i]);
   }

   return res;
}

static AMESystemError AmesysGetDoubleParamValue(AMESIMSYSTEM *amesys, const int nbParam, const int idx[], double value[])
{
   AMESystemError res;
   int i;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_GET_MODEL_PARAM);

   for(i = 0; (i < nbParam) && (res == AME_NO_ERROR); i++) {
      res = getDoubleParameter(amesys->pModel, idx[i], &value[i]);
   }

   return res;
}

static AMESystemError AmesysGetStringParamValue(AMESIMSYSTEM *amesys, const int nbParam, const int idx[], const char* value[])
{
   AMESystemError res;
   int i;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_GET_MODEL_PARAM);

   for(i = 0; (i < nbParam) && (res == AME_NO_ERROR); i++) {
      res = getStringParameter(amesys->pModel, idx[i], &value[i]);
   }

   return res;
}

static AMESystemError AmesysSetIntParamValue(AMESIMSYSTEM *amesys, const int nbParam, const int idx[], const int value[])
{
   AMESystemError res;
   int i;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_MODEL_PARAM_TUNABLE);

   for(i = 0; (i < nbParam) && (res == AME_NO_ERROR); i++) {
      int isTunable;
      res = isParamTunable(amesys->pModel, idx[i], &isTunable);

      if(res ==  AME_NO_ERROR) {
         if(isTunable) {
            res = AmesysControlRequest(amesys, AME_CMD_SET_MODEL_PARAM_TUNABLE);
         }
         else {
            res = AmesysControlRequest(amesys, AME_CMD_SET_MODEL_PARAM);
         }
      }
      if(res ==  AME_NO_ERROR) {
         res = setIntParameter(amesys->pModel, idx[i], value[i]);
      }
      if(res == AME_NO_ERROR) {
         SignalInputChange();
         res = setParamAsUserDefined(amesys->pModel, idx[i]);
      }
   }

   return res;
}

static AMESystemError AmesysSetDoubleParamValue(AMESIMSYSTEM *amesys, const int nbParam, const int idx[], const double value[])
{
   AMESystemError res;
   int i;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_MODEL_PARAM_TUNABLE);

   for(i = 0; (i < nbParam) && (res == AME_NO_ERROR); i++) {
      int isTunable;
      res = isParamTunable(amesys->pModel, idx[i], &isTunable);

      if(res ==  AME_NO_ERROR) {
         if(isTunable) {
            res = AmesysControlRequest(amesys, AME_CMD_SET_MODEL_PARAM_TUNABLE);
         }
         else {
            res = AmesysControlRequest(amesys, AME_CMD_SET_MODEL_PARAM);
         }
      }
      if(res ==  AME_NO_ERROR) {
         res = setDoubleParameter(amesys->pModel, idx[i], value[i]);
      }
      if(res == AME_NO_ERROR) {
         SignalInputChange();
         res = setParamAsUserDefined(amesys->pModel, idx[i]);
      }
   }

   return res;
}

static AMESystemError AmesysSetStringParamValue(AMESIMSYSTEM *amesys, const int nbParam, const int idx[], const char* value[])
{
   AMESystemError res;
   int i;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_MODEL_PARAM_TUNABLE);

   for(i = 0; (i < nbParam) && (res == AME_NO_ERROR); i++) {
      int isTunable;
      res = isParamTunable(amesys->pModel, idx[i], &isTunable);

      if(res ==  AME_NO_ERROR) {
         if(isTunable) {
            res = AmesysControlRequest(amesys, AME_CMD_SET_MODEL_PARAM_TUNABLE);
         }
         else {
            res = AmesysControlRequest(amesys, AME_CMD_SET_MODEL_PARAM);
         }
      }
      if(res ==  AME_NO_ERROR) {
         res = setStringParameter(amesys->pModel,idx[i], value[i]);
      }
      if(res == AME_NO_ERROR) {
         res = setParamAsUserDefined(amesys->pModel, idx[i]);
      }
   }

   return res;
}

static AMESystemError AmesysGetDoubleGlobalParamValue(AMESIMSYSTEM *amesys, const int nbParam, const char* name[], double value[])
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_GET_MODEL_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      int i;
      for(i = 0; i<nbParam; i++) {
         if(getGlobalParamValueByName(name[i], &value[i]) != no_error) {
            res = AME_GLOBAL_PARAMETER_ERROR;
            break;
         }
      }
   }

   return res;
}

static AMESystemError AmesysGetStringGlobalParamValue(AMESIMSYSTEM *amesys, const int nbParam, const char* name[], const char* value[])
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_GET_MODEL_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      int i;
      for(i = 0; i<nbParam; i++) {
         if(getTextGlobalParamValueByName(name[i], &value[i]) != no_error) {
            res = AME_GLOBAL_PARAMETER_ERROR;
            break;
         }
      }
   }

   return res;
}

static AMESystemError AmesysSetIntGlobalParamValue(AMESIMSYSTEM *amesys, const int nbParam, const char* name[], const int value[])
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_MODEL_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      int i;
      for(i = 0; i<nbParam; i++) {
         if(ChangeOrAddIntGlobalParamValue(name[i], value[i], 1) != AME_NO_ERROR) {
            res = AME_GLOBAL_PARAMETER_ERROR;
            break;
         }
      }
   }

   return res;
}

static AMESystemError AmesysSetDoubleGlobalParamValue(AMESIMSYSTEM *amesys, const int nbParam, const char* name[], const double value[])
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_MODEL_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      int i;
      for(i = 0; i<nbParam; i++) {
         if(ChangeOrAddRealGlobalParamValue(name[i], value[i], 1) != AME_NO_ERROR) {
            res = AME_GLOBAL_PARAMETER_ERROR;
            break;
         }
      }
   }

   return res;
}

static AMESystemError AmesysSetStringGlobalParamValue(AMESIMSYSTEM *amesys, const int nbParam, const char* name[], const char* value[])
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_MODEL_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      int i;
      for(i = 0; i<nbParam; i++) {
         if(ChangeOrAddTextGlobalParamValue(name[i], value[i], 1) != AME_NO_ERROR) {
            res = AME_GLOBAL_PARAMETER_ERROR;
            break;
         }
      }
   }

   return res;
}

static AMESystemError AmesysRequestRunInterrupt(AMESIMSYSTEM *amesys)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_REQ_RUN_INTERRUPT);

   if(res == AME_NO_ERROR) { /* Request accepted */
      amesys->requestinterrupt = 1;

	   /* Update state and result */
	   res =  AmesysUpdateState(amesys, AME_CMD_REQ_RUN_INTERRUPT, res);
   }

   return res;
}

static AMESystemError AmesysSetFinalTime(AMESIMSYSTEM *amesys, const double finaltime)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_RUN_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      SimOptSetTFinal(amesys->simOptions, finaltime);
   }

   return res;
}

static AMESystemError AmesysSetInitTime(AMESIMSYSTEM *amesys, const double inittime)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_RUN_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      SimOptSetTStart(amesys->simOptions, inittime);
   }

   return res;
}

static AMESystemError AmesysSetPrintInterval(AMESIMSYSTEM *amesys, const double tInc)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_RUN_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      SimOptSetTInc(amesys->simOptions, tInc);
   }

   return res;
}

static AMESystemError AmesysSetToleranceMethod(AMESIMSYSTEM *amesys, const int tolMethod)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_SOLVER_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      setToleranceMethod(amesys, tolMethod);
   }

   return res;
}

static AMESystemError AmesysSetAbsoluteAndRelativeTolerances(AMESIMSYSTEM *amesys, const double atol, const double rtol)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_SOLVER_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      setToleranceValues(amesys, atol, rtol);
   }

   return res;
}

static AMESystemError AmesysGetToleranceMethodAndValues(AMESIMSYSTEM *amesys, int *tolmethod, double *atol, double *rtol)
{
   AMESystemError res = AME_NO_ERROR;
   *tolmethod = getToleranceMethodAndValues(amesys->simOptions, atol, rtol);
   return res;
}

static AMESystemError AmesysSetLogger( int (*newameInternalfprintf)(FILE *fp, const char *fmt, va_list ap) )
{
   ameInstallFprintf(newameInternalfprintf);
   return AME_NO_ERROR;
}

static AMESystemError AmesysSetInputDir(AMESIMSYSTEM *amesys, const char *inputDir)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_ENV);

   if(res == AME_NO_ERROR) { /* Request accepted */
      AmeSetInputDir(amesys, inputDir);
   }

   return res;
}

static AMESystemError AmesysSetOutputDir(AMESIMSYSTEM *amesys, const char *outputDir)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_ENV);

   if(res == AME_NO_ERROR) { /* Request accepted */
      AmeSetOutputDir(amesys, outputDir);
   }

   return res;
}

static AMESystemError AmesysSetBaseFilesName(AMESIMSYSTEM *amesys, const char *baseName, const char* extension)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_ENV);

   if(res == AME_NO_ERROR) { /* Request accepted */
      AmeSetModelBaseName(amesys, baseName, extension);
   }

   return res;
}

static AMESystemError AmesysSetResultFilesName(AMESIMSYSTEM *amesys, const char *outName)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_ENV);

   if(res == AME_NO_ERROR) { /* Request accepted */
      AmeSetResultFileName(amesys, outName);
   }

   return res;
}

/* To ensure compliancy with old template and entry points */
static AMESystemError AmesysSetParamAsInitModel(AMESIMSYSTEM *amesys,
                  double time,
                  double PrintInterval,
                  double MaxTimeStep,
                  double tolerance,
                  int errCtrl,
                  int writeLevel,
                  int extraDisconPrints,
                  int runStats,
                  int runType,
                  int thesolvertype)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_RUN_PARAM);
   res |= AmesysControlRequest(amesys, AME_CMD_SET_SOLVER_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      SIMOptions *sim_options = amesys->simOptions;

      simSettings sim;
      stdOptions std;

      SimOptSetFixedStepIntegratorEnabled(amesys->simOptions, 0);
      SimOptSetVariableHMax(amesys->simOptions, MaxTimeStep);
      SimOptSetVariableTol(amesys->simOptions, tolerance);
      SimOptSetVariableErrorType(amesys->simOptions, errCtrl);

      sim.tStart = time;
      double tFinal;
      SimOptGetTFinal(amesys->simOptions, &tFinal);

      sim.tFinal = tFinal;
      sim.simOpt = 0;

      if(runType & 0x01) {
         sim.simOpt |= SIMOPT_SIM_CONTINUATION_RUN;
      }
      if(runType & 0x02) {
         sim.simOpt |= SIMOPT_SIM_USE_FINAL_VALUES;
      }
      if(writeLevel != 2) {
         sim.simOpt |= SIMOPT_SIM_MONITOR_TIME;
      }
      if(runStats) {
         sim.simOpt |= SIMOPT_SIM_STATISTICS;
      }

      if(PrintInterval <= 0) {
         sim.tInc = -PrintInterval;
         simOptSetOutOff(amesys->simVOptions, 1);
      }
      else {
         sim.tInc = PrintInterval;
         simOptSetOutOff(amesys->simVOptions, 0);
      }

      simOptSetSimParam(amesys->simOptions, &sim);

      std.simMode = ((runType & 0x0c) >> 2);
      std.stdOpt = 0;

      if(extraDisconPrints) {
         std.stdOpt |= SIMOPT_STD_DISC_PRINTOUT;
      }
      if(runType & 0x10) {
         std.stdOpt |= SIMOPT_STD_HOLD_INPUTS;
      }
      bool lock_states_enabled;
      SimOptIsLockStatesEnabled(amesys->simOptions, &lock_states_enabled);
      if(lock_states_enabled) {
         std.stdOpt |= SIMOPT_STD_LOCK_STATES;
      }
      bool diagnostics_enabled;
      SimOptIsDiagnosticsEnabled(amesys->simOptions, &diagnostics_enabled);
      if(diagnostics_enabled) {
         std.stdOpt |= SIMOPT_STD_DIAGNOSTICS;
      }
      if(thesolvertype) {
         std.stdOpt |= SIMOPT_STD_CAUTIOUS;
      }
      bool minimalDiscont;
      SimOptIsMinDiscHandlingEnabled(amesys->simOptions, &minimalDiscont);
      if(minimalDiscont) {
         std.stdOpt |= SIMOPT_STD_MIN_DISC_HANDLING;
      }
      if(runType & 0x100) {
         std.stdOpt |= SIMOPT_STD_DISABLE_OPTIMAZED;
      }

      bool activity_enabled;
      SimOptIsActivityEnabled(sim_options, &activity_enabled);

      if(activity_enabled) {
         std.stdOpt |= SIMOPT_STD_ACTIVITY;
      }

      bool power_enabled;
      SimOptIsPowerEnabled(sim_options, &power_enabled);
      if(power_enabled) {
         std.stdOpt |= SIMOPT_STD_POWER;
      }

      bool energy_enabled;
      SimOptIsEnergyEnabled(sim_options, &energy_enabled);
      if(energy_enabled) {
         std.stdOpt |= SIMOPT_STD_ENERGY;
      }
      simOptSetStdParam(amesys->simOptions, &std);
   }
   return res;
}

/* To ensure compliancy with old template and entry points */
static AMESystemError AmesysSetParamAsFixedStep(AMESIMSYSTEM *amesys,
                                       double start_time, int run_type, int solver_type,
                                       int runge_kutta_order, double fixed_h, double printinterval)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_RUN_PARAM);
   res |= AmesysControlRequest(amesys, AME_CMD_SET_SOLVER_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      solverSettings solver;
      
      res = AME_NO_ERROR;

      SimOptSetFixedStepIntegratorEnabled(amesys->simOptions, 1);
      SimOptSetFixedH(amesys->simOptions, fixed_h);
      SimOptSetFixedOrder(amesys->simOptions, runge_kutta_order);
      simOptSetFixedType(amesys->simVOptions, solver_type);

      SimOptSetTStart(amesys->simOptions, start_time);
      if(printinterval <= 0) {
         simOptSetOutOff(amesys->simVOptions, 1);
         SimOptSetTInc(amesys->simOptions, -printinterval);
         
      }
      else {
         simOptSetOutOff(amesys->simVOptions, 0);
         SimOptSetTInc(amesys->simOptions,  printinterval);
      }
      simOptSetOneOfSimParam(amesys->simOptions, SIMOPT_SIM_CONTINUATION_RUN, run_type & 0x01);
      simOptSetOneOfSimParam(amesys->simOptions, SIMOPT_SIM_USE_FINAL_VALUES, (run_type & 0x02)>>1);
   }
   return res;
}

#ifndef AME_COSIM

static AMESystemError AmesysInitME(AMESIMSYSTEM *amesys, int withAssembly)
{
   AMESystemError res = AME_NO_ERROR;
   int jump_ret;

   res = AmesysControlRequest(amesys, AME_CMD_INITIALIZE);

   if(res != AME_NO_ERROR) {
      /* Request not accepted */
      return res;
   }

   /* Load parameters */
   res = Input(amesys);

   /* Set initial values */
   modelSetInitValues(amesys->pModel, amesys->states, amesys->discrete_states);

   if(res == AME_NO_ERROR) {
      if( (jump_ret = setjmp(amesys->jump_env)) == 0) { /* try */
         double tStart;
         SimOptGetTStart(amesys->simOptions, &tStart);
         double tFinal;
         SimOptGetTFinal(amesys->simOptions, &tFinal);
         setstarttime_(tStart);
         setfinaltime_(tFinal);

         amesys->first_call = 1;  /* should this be done or not ?*/
         amesys->internal_discont = 1;

         amesys->tlast = TLAST_MIN;

         memset(amesys->ecount,0,amesys->numstates*sizeof(int));
         memset(amesys->dotstates,0,amesys->numstates*sizeof(double));

         PreInitialize(amesys,amesys->states);

#ifndef AME_INPUT_IN_MEMORY
         if( NeedReloadInputFiles() != 0 )
         {
            ClearGPs();
            Input(amesys);
            /* Set initial values */
            modelSetInitValues(amesys->pModel, amesys->states, amesys->discrete_states);
            ClearReloadedFiles();
         }
#endif

         Initialize(amesys,amesys->states);

         OverloadStatesWithRegister(amesys, amesys->states, SVREGISTER_DEFAULT);

         if(withAssembly) {
            doAssembly(amesys);
         }
         amesys->tlast = getstarttime_();
#ifdef AME_PROCESS_TIME
         /* Initialization of time timers */
         ProcessTime(0);
#endif
      }
      else { /* Catch AmeExit */
         res = AME_EXIT_ERROR;
      }
   }

   /* Update state and result */
   res =  AmesysUpdateState(amesys, AME_CMD_INITIALIZE, res);

   if(res == AME_NO_ERROR) {
      /* Go in Run state: simulate acknowledgment of evaluation at t start command */
      res =  AmesysUpdateState(amesys, AME_CMD_TSTART, res);

#if defined(AME_MEMORY_ACCESS_RT_EXPORT)
#if (NB_WATCH_VAR>0)
         RT_Get_Watch_Var(amesys);
#endif
#endif
   }

   return res;
}

static AMESystemError AmesysFuncEvalME(AMESIMSYSTEM *amesys, double t, double *y, double *yprime, double *delta, int *flag)
{
   int jump_ret;
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_FUNCEVAL);

   if(res != AME_NO_ERROR) {
      /* Request not accepted */
      return res;
   }

   if( (jump_ret = setjmp(amesys->jump_env)) == 0) { /* try */
      amesys->doInterpol = 0;
      localFuncEval(amesys, t, y, yprime, delta, flag);
   }
   else { /* Catch AmeExit */
      res = AME_EXIT_ERROR;
   }

   /* Update state and result */
   res =  AmesysUpdateState(amesys, AME_CMD_FUNCEVAL, res);
   return res;
}

#endif

/****************************/

#define SYSNME collision_

#if defined(STANDALONESIMULATOR) || defined(OLS)
#include "ame_standalone_simulator.h"

#elif defined(FMICS1)
#include "ame_fmics1.h"
#elif defined(FMICS2)
#include "ame_fmics2.h"
#elif defined(FMICS3)
#include "ame_fmics3.h"
#elif defined(FMIME1) || defined(FMIME2)
#if(AME_MODEL_ISEXPLICIT == 0)
#error "FMI for model exchange is not allowed for implicit model."
#elif defined(AMERT)
#error "FMU for real-time is not allowed for model exchange."
#elif defined(FMIME1)
#include "ame_fmime1.h"
#else
#include "ame_fmime2.h"
#endif
#elif defined(FMIX)
#include "ame_user_cosim.h"

#elif defined(AMEUSERCOSIM)
#include "ame_user_cosim.h"

#elif defined(AME_CS_SIMULINK)
#include "ame_simulink_cosim.h"

#elif defined(AME_ME_SIMULINK)
#include "ame_simulink_me.h"

#elif defined(AME_CS_ADAMS)
#include "ame_adams_cosim.h"

#elif defined(AME_ME_ADAMS)
#include "adams_cont.h"

#elif defined(AME_CS_MOTION)
#include "ame_motion_cosim.h"

#elif defined(AME_ME_MOTION)
#include "ame_motion_me.h"

#elif defined(DISCRETEPART)
#include "ame_discrete_part.h"

#elif defined(GEN_COSIM)
#include "gen_cosim.h"

#elif defined(AME_CS_SIMULINK_SCANER)
#include "ame_simulink_scaner.h"

#else
#error "Unknown interface defined. Cannot generate Amesim model code."
#endif
