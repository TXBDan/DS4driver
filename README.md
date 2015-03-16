# DS4driver
Sony DS4 controller for Intel Edison 

I ran this using the the latest Yocto firmware as of 3/15/15, version "120".

The follow steps are necessary to initally pair and connect the DS4 to the Edison:
root@edison:~# rfkill unblock bluetooth
root@edison:~# bluetoothctl
[NEW] Controller 98:4F:EE:03:62:87 edison [default]
[bluetooth]# agent on
Agent registered
[bluetooth]# default-agent
Default agent request successful
[bluetooth]# power on
Changing power on succeeded
[bluetooth]# discoverable on
Changing discoverable on succeeded
[CHG] Controller 98:4F:EE:03:62:87 Discoverable: yes
[bluetooth]# pairable on
Changing pairable on succeeded
[bluetooth]# scan on
Discovery started
[CHG] Controller 98:4F:EE:03:62:87 Discovering: yes
[NEW] Device 1C:96:5A:57:86:10 Wireless Controller
[NEW] Device 60:03:08:D3:60:A4 60-03-08-D3-60-A4
[CHG] Device 1C:96:5A:57:86:10 RSSI: -63
[bluetooth]# pair 1C:96:5A:57:86:10
Attempting to pair with 1C:96:5A:57:86:10
[CHG] Device 1C:96:5A:57:86:10 Connected: yes
[CHG] Device 1C:96:5A:57:86:10 UUIDs:
        00001124-0000-1000-8000-00805f9b34fb
        00001200-0000-1000-8000-00805f9b34fb
[CHG] Device 1C:96:5A:57:86:10 Paired: yes
Pairing successful
Authorize service 00001124-0000-1000-8000-00805f9b34fb (yes/no)?
[bluetooth]# yes
[  383.526655] hid-generic 0005:054C:05C4.0001: unknown main item tag 0x0
trust 1C:96:5A:57:86:10 ?
[bluetooth]# yes
[CHG] Device 1C:96:5A:57:86:10 Trusted: yes
Changing 1C:96:5A:57:86:10 trust succeeded
[bluetooth]# connect 1C:96:5A:57:86:10
Attempting to connect to 1C:96:5A:57:86:10
Connection successful
[bluetooth]# info 1C:96:5A:57:86:10
Device 1C:96:5A:57:86:10
        Name: Wireless Controller
        Alias: Wireless Controller
        Class: 0x002508
        Icon: input-gaming
        Paired: yes
        Trusted: yes
        Blocked: no
        Connected: yes
        LegacyPairing: no
        UUID: Human Interface Device... (00001124-0000-1000-8000-00805f9b34fb)
        UUID: PnP Information           (00001200-0000-1000-8000-00805f9b34fb)
        Modalias: usb:v054Cp05C4d0100
        
From then on (even after power cycles), all you need to do  is 'rfkill unblock bluetooth' and then power on the DS4 controller. It should automatically pair and connect and be ready to go.

The device will show up in '/dev/input/eventX'. For me it was event2. Be sure to modify main.cpp to pass the correct device when calling your init() function.

This was just a quick first step. Hopefully it will get you going.
