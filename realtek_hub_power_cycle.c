#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <libusb-1.0/libusb.h>

unsigned		vid = 0x0bda;
//unsigned		pid = 0x5411;//Jetson NANO DEvKit
unsigned		pid = 0x5489;//Jetson Xavier NX


int power_cycle(libusb_device_handle *hub_devh)
{
        int ret = -1;

        /*ep0 vendor command enable*/
        ret = libusb_control_transfer(hub_devh, 0x40, 0x02, 0x01, ((0x0B<<8)|(0xDA)), 0, 0, 100000);
        if (ret < 0) {
                printf("[error]:ep0 vendor command enable fail.\n");
                return ret;
        }

        /*ep0 vendor command disable*/
        libusb_control_transfer(hub_devh, 0x40, 0x1, 0x08, 0, NULL, 0, 100);
        libusb_control_transfer(hub_devh, 0x40, 0x3, 0x08, 0, NULL, 0, 100);
        libusb_control_transfer(hub_devh, 0x40, 0x02, 0x00, ((0x0B<<8)|(0xDA)), 0, 0, 100000);

        return ret;
}

int main(int argc, char *argv[])
{
    int ret=0;
    libusb_device_handle	*hub_devh;
    libusb_context		*context;

    ret = libusb_init(&context);
    if (ret != 0){
        printf("[error]:libusb init fail.\n");
        return ret;
    }
    
    hub_devh = libusb_open_device_with_vid_pid(context, vid, pid);
    if (!hub_devh) {
        printf("[error]:open device %04x:%04x fail.\n", vid, pid);
		return -1;
	}
    ret = power_cycle(hub_devh);
    return ret;
}

