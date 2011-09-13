#ifndef __SCHEDULE_H
#define __SCHEDULE_H

/**
\addtogroup MAChigh
\{
\addtogroup Schedule
\{
*/

#include "openwsn.h"

//=========================== define ==========================================

#define SCHEDULELENGTH  9    // the length, in slot, of the schedule
#define MINBE           4    // min backoff exponent, used in shared TX slots
#define MAXBE           7    // max backoff exponent, used in shared TX slots

enum {
   CELLTYPE_OFF         = 0,
   CELLTYPE_ADV         = 1,
   CELLTYPE_TX          = 2,
   CELLTYPE_RX          = 3,
   CELLTYPE_TXRX        = 4,
   CELLTYPE_SERIALRX    = 5
};

//=========================== typedef =========================================

typedef uint8_t    cellType_t;
typedef uint8_t    channelOffset_t;

typedef struct {
   uint8_t         type;
   bool            shared;
   uint8_t         backoffExponent;
   uint8_t         backoff;
   uint8_t         channelOffset;
   open_addr_t     neighbor;
   uint8_t         numRx;
   uint8_t         numTx;
   uint8_t         numTxACK;
   uint32_t        asn;
} scheduleRow_t;

typedef struct {
   uint8_t         row;
   scheduleRow_t   cellUsage;
} debugScheduleRow_t;

//=========================== variables =======================================

//=========================== prototypes ======================================

          void            schedule_init();
          bool            debugPrint_schedule();
__monitor cellType_t      schedule_getType(asn_t asn_param);
__monitor channelOffset_t schedule_getChannelOffset(asn_t asn_param);
__monitor void            schedule_getNeighbor(asn_t asn_param, open_addr_t* addrToWrite);
          void            schedule_indicateRx(asn_t    asnTimestamp);
          void            schedule_indicateTx(asn_t    asnTimestamp,
                                              uint8_t  numTxAttempts,
                                              bool     was_finally_acked);
/**
\}
\}
*/
          
#endif