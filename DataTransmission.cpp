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

/** include files **/
#include <math.h>            // fabs( ... )
#include <stdlib.h>
#include "DataTransmission.h"  // base header
#include "message.h"       // InternalMessage ....
#include "mainsimu.h"      // class MainSimulator
#include "strutil.h"       // str2float( ... )

/*******************************************************************
* Function Name: DataTransmission
* Description: constructor
********************************************************************/
DataTransmission::DataTransmission( const string &name )
: Atomic( name )
, dataOut( addInputPort( "dataOut" ) )
, gotData( addInputPort( "gotData" ) )
, dataSent( addOutputPort( "dataSent" ) )
, dataPort( addOutputPort( "dataPort" ) )
, processingTime (0,0,2,0)
{
	
	string time1( MainSimulator::Instance().getParameter( description(), "processingTime" ) ) ;

	if( time1 != "" )
		processingTime = time1 ;

}

/*******************************************************************
* Function Name: externalFunction
* Description: the DataTransmission receives dataOut, gotData
********************************************************************/
Model &DataTransmission::externalFunction( const ExternalMessage &msg )
{
  if ( this->state() == passive)
  {
  
    if (msg.port() == dataOut)
     {
        dataReceived = 0;  //set it to False	
	    data = static_cast < int > (msg.value());   //data recived at the dataOut port
        holdIn(active, processingTime);
     }
    if (msg.port() == gotData )
     {
       dataReceived = 1;   //set it to True
       holdIn(active, processingTime);
     }
     
	
  }
	return *this ;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &DataTransmission::internalFunction( const InternalMessage & )
{
	passivate();
	return *this;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &DataTransmission::outputFunction( const InternalMessage &msg )
{

      if ( dataReceived == 1 )
        {
         sendOutput( msg.time(),dataSent, data);
        }
         
        else
        {
         sendOutput( msg.time(),dataPort,data);
        }
      
	return *this;
}


