from binascii import crc32
import angr
import claripy
import re

flag = claripy.BVS('flag', 16*8)
solver = claripy.Solver()

solver.add(crc32(flag.get_bytes(0, 16)) == 0xff09b794)
solver.add(re.match('^[A-Z]{16}$', flag.get_bytes(0, 16).decode("utf-8")))
solver.add(flag.get_bytes(0, 4).decode("utf-8") == 'FLAG')

flag_value = solver.eval(flag, 1)[0]
print(flag_value)