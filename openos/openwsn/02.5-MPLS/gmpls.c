/**
 \brief GMPLS L2.5 manager. Is in charge of L2.5 activity. Controls RSVP messages and its timing and sends to cfres RSVP objects
 containing the information to create an schedule. It can talk with uRes as well.

 \author Xavi Vilajosana <xvilajosana@eecs.berkeley.edu>, March 2012.
 */


typedef struct {
   uint16_t        refreshperiod;
   bool            busySending;          // TRUE when busy sending a rsvp message
   opentimer_id_t  timerId;
} mpls_vars_t;

mpls_vars_t mpls_vars;

void    mpls_timer_cb();

void    mpls_init(){
	mpls_vars.refreshperiod = 600000; // fires every 10 min on average
	mpls_vars.busySending       = FALSE;
	mpls_vars.timerId = opentimers_start(res_vars.periodMaintenance,
	                                       TIMER_PERIODIC,
	                                       mpls_timer_cb);
}

// from upper layer or from the timer. Triggers a reservation request. Genereates a rsv msg or in contrast forwards path message.
error_t mpls_send(OpenQueueEntry_t *msg){

}


/*
 *  from lower layer.
 *  get the message. Determine type.
 *  if path message, trigger cfres to modify the scheduling.
 *  send path messsage down to the next neighbour.
 *
 *  if resv message, aggregate demand from neighbours. and go up.
 */
void  mpls_receive(OpenQueueEntry_t* msg){

}

void mpls_timer_cb(){
	//TODO
}
