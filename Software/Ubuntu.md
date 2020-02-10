# Ubuntu

## Articles

- [Building a Linux Desktop for Cloud Native Development](https://blog.alexellis.io/building-a-linux-desktop-for-cloud-native-development/)

## Ubuntu + Windows dual boot

Installing Windows **after** Ubuntu.

From <https://help.ubuntu.com/community/WindowsDualBoot>:

### Recovering GRUB after reinstalling Windows

Please refer to the [Reinstalling GRUB2](https://help.ubuntu.com/community/Grub2/Installing#Reinstalling_GRUB_2) guide.

### Master Boot Record backup and replacement

This method does not work for computers with UEFI boot. In consequence, it won't work for pre-installed Windows 8 and some pre-installed with Windows 7.

Back-up the existing MBR, install Windows, replace your backup overwriting the Windows boot code:

1. Create an NTFS partition for Windows (using fdisk, GParted or whatever tool you are familiar with)
2. Backup the MBR e.g. `dd if=/dev/sda of=/mbr.bin bs=446 count=1`

3. Install Windows
4. Boot into a [LiveCD](https://help.ubuntu.com/community/LiveCD)

5. Mount your root partition in the LiveCD
6. Restore the MBR e.g. `dd if=/media/sda/mbr.bin of=/dev/sda bs=446 count=1`

7. Restart and Ubuntu will boot
8. Setup GRUB to boot Windows
