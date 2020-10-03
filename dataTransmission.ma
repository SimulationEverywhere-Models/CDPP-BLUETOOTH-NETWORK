[top]
components : dataTransmission@DataTransmission 
out : dataSent 
out : dataPort  
in : dataOut gotData
Link : dataOut dataOut@dataTransmission 
Link : gotData gotData@dataTransmission 
Link : dataSent@dataTransmission dataSent
Link : dataPort@dataTransmission dataPort
 

[dataTransmission]
processingTime : 00:00:02:00
