/*******************************************************************
*
*  DESCRIPTION: Atomic Model DataTransmission
*
*  AUTHOR: Shafagh Jafer
*
*  EMAIL: sjafer@connect.carleton.ca
*
*
*  DATE: 8/06/2006
*
*******************************************************************/
#ifndef __DATATRANSMISSION_H
#define __DATATRANSMISSION_H

/** include files **/
#include "atomic.h"  // class Atomic


/** declarations **/
class DataTransmission: public Atomic
{
public:
	DataTransmission( const string &name = "DataTransmission" ) ;	 // Default constructor

	

	virtual string className() const
		{return "DataTransmission";}

protected:
	Model &initFunction()
		{   dataReceived = 0;
			data = 0;
                      this -> passivate();
                      return *this;}

	Model &externalFunction( const ExternalMessage & );

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );

private:
	const Port &dataOut;
    const Port &gotData ;
    Port &dataSent;
    Port &dataPort ;
    Time processingTime;
    int   dataReceived, data;
	

    
};	// class DataTransmission


#endif    //__DATATRANSMISSION_H
