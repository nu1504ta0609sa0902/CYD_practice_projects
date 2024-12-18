print_mac_address:

- Run the sketch to get the CYD MAC address

Light_Data_Sender: (Master/Sender)

- Use the breadboad and connect it to the normal ESP32
- Load it
- This will send the state of the photoresister to CYD

Light_Data_Receiver_Server: (Slave/Receiver)

- CYD sketch to show the GUI
- Show the status received from Slave