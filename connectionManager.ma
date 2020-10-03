[top]
components : pairedDeviceFinder@PairedDeviceFinder
components : permissionVerifier@PermissionVerifier

in : search IDin connectDevice granted
out : deviceID getID reqPermission connected

Link : search search@pairedDeviceFinder
Link : getID@pairedDeviceFinder getID
Link : IDin IDin@pairedDeviceFinder
Link : deviceID@pairedDeviceFinder deviceID
  
Link : connectDevice connectDevice@permissionVerifier
Link : reqPermission@permissionVerifier reqPermission
Link : granted granted@permissionVerifier 
Link : connected@permissionVerifier connected 

[permissionVerifier]
processingTime : 00:00:02:00

[pairedDeviceFinder]
processingTime : 00:00:02:00

