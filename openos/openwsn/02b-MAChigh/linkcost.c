#include "linkcost.h"


//calculate link cost based on ETX.
uint8_t linkcost_calcETX(uint8_t numTX, uint8_t numTXACK){

	return(uint8_t)((((float)numTx)/((float)numTxACK))*10.0);

}

//calculate link cost based on ETX.
uint8_t linkcost_calcRSSI(){

	return 0; //TODO

}
