/*----------------------------------------------------------------------------*
 *                                                                            *
 *         M I N I M A L I S T I C    L O G M G R     E N T I T Y             *
 *                                                                            *
 *                    Copyright (C) 2010 Amit Chawre.                         *
 *                                                                            *
 *----------------------------------------------------------------------------*/

/** 
 * @file hello-world.c
 * @brief This file contains example of a minimalistic log manager entity.
*/

#include <stdio.h>
#include <assert.h>
#include "NwLog.h"
#include "NwSdp.h"

#include "NwMiniLogMgrEntity.h"

#ifdef __cplusplus 
extern "C" {
#endif

NwU32T g_log_level = NW_LOG_LEVEL_INFO;

/*---------------------------------------------------------------------------
 * Public functions
 *--------------------------------------------------------------------------*/

NwSdpRcT nwMiniLogMgrInit(NwMiniLogMgrT* thiz, NwU32T logLevel )
{
  thiz->logLevel = logLevel;
  return NW_SDP_OK;
}

NwSdpRcT nwMiniLogMgrSetLogLevel(NwMiniLogMgrT* thiz, NwU32T logLevel)
{
  thiz->logLevel = logLevel;
}

NwSdpRcT nwMiniLogMgrLogRequest (NwSdpLogMgrHandleT hLogMgr,
    NwU32T logLevel,
    NwCharT* file,
    NwU32T line,
    NwCharT* logStr)
{
  NwMiniLogMgrT* thiz = (NwMiniLogMgrT*) hLogMgr;
  if(thiz->logLevel >= logLevel)
    printf("NWSDP-ULP     %s - %s <%s,%u>\n", gLogLevelStr[logLevel], logStr, basename(file), line);
  return NW_SDP_OK;
}

#ifdef __cplusplus 
}
#endif

