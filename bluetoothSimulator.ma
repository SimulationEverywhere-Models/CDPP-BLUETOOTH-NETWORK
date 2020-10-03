[top]
components : senderMobile@SenderMobile
components : dataTransmission@DataTransmission
components : ConnectionManager
components : receiverMobile@ReceiverMobile

out : newMsgArrival 
in : enableBT 

Link : enableBT enableBT@senderMobile
Link : searchDevice@senderMobile search@ConnectionManager
Link : getID@ConnectionManager IDrequested@receiverMobile
Link : IDout@receiverMobile IDin@ConnectionManager 
Link : deviceID@ConnectionManager deviceFound@senderMobile 
Link : connect@senderMobile connectDevice@ConnectionManager
Link : reqPermission@ConnectionManager permit@receiverMobile
Link : accepted@receiverMobile granted@ConnectionManager 
Link : connected@ConnectionManager start@senderMobile 
Link : dataOut@senderMobile dataOut@dataTransmission
Link : dataPort@dataTransmission data@receiverMobile  
Link : gotData@receiverMobile gotData@dataTransmission 
Link : dataSent@dataTransmission dataSent@senderMobile 
Link : newMsgArrival@receiverMobile newMsgArrival



[senderMobile]
permissionTime : 00:00:02:00
transferTime : 00:00:05:00 
processingTime : 00:00:02:00

[receiverMobile]
permissionTime : 00:00:02:00
transferTime : 00:00:05:00

[dataTransmission]
processingTime : 00:00:02:00


[ConnectionManager]
components : pairedDeviceFinder@PairedDeviceFinder
components : permissionVerifier@PermissionVerifier

in : search connectDevice granted IDin
out : deviceID connected getID reqPermission   

Link : search search@pairedDeviceFinder
Link : IDin IDin@pairedDeviceFinder
Link : deviceID@pairedDeviceFinder deviceID
Link : getID@pairedDeviceFinder getID

Link : connectDevice connectDevice@permissionVerifier
Link : granted granted@permissionVerifier
Link : connected@permissionVerifier connected
Link : reqPermission@permissionVerifier reqPermission


[permissionVerifier]
processingTime : 00:00:02:00

[pairedDeviceFinder]
 processingTime : 00:00:02:00

