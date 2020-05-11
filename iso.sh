#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/ashos.kernel isodir/boot/ashos.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "AshOS" {
     multiboot /boot/ashos.kernel
}
EOF
grub-mkrescue -o ashos.iso isodir
