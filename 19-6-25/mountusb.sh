#!/bin/sh
#moutusb.sh

quit()
{
  clear
  echo "***********************************************"
  echo "*       Thank you to use, Good bye!           *"
  echo "***********************************************"
  exit 0
}

mountusb()
{
  clear
  mkdir /mnt/usb
  /sbin/fdisk -l | grep /dev/sd
  echo -e "Please Enter the device name of usb as shown above:\c"
  read PARAMETER
  mount /dev/$PARAMETER /mnt/usb
}

umountusb()
{
  clear
  umount /mnt/usb
}

display()
{
  clear
  ls -l /mnt/usb
}

cpdisktousb()
{
  clear
  echo -e "Please Enter the filename to be Copied(under Current directory):\c"
  read FILE
  echo "Copying, Please wait!..."
  cp $FILE /mnt/usb
}

cpustodisk()
{
  clear
  echo -e "Please Enter the filename to be Copied in USB:\c"
  read FILE
  echo "Copying,Please wait!..."
  cp /mnt/usb/$FILE .
}

clear
while true
do
  echo "============================================================="
  echo "===                UNIX USB MANAGE PROGRAM                  ="
  echo "============================================================="
  echo "                   1-MOUNT USB                               "
  echo "                   2-UMOUNT USB                              "
  echo "                   3-DISPLAY USB INFORMATION                 "
  echo "                   4-COPY FILE IN DISK TO USB                "
  echo "                   5-COPY FILE IN USB TO DISK                "
  echo "                   0-EXIT                                    "
  echo "============================================================="
  echo -e "Please Enter a Choice(0--5):\c"
  read CHOICE
  case $CHOICE in
  1) mountusb;;
  2) umountusb;;
  3) display;;
  4) cpdisktousb;;
  5) cpustodisk;;
  0) exit 1;;
  *) echo "Invalid Choice!Correct Choice is (0---5)"
     sleep 4
     clear;;
    esac
  done
