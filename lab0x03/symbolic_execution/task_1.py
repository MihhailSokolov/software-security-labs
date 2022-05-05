import claripy

x = claripy.BVS('x', 32)
y = claripy.BVS('y', 32)
solver = claripy.Solver()

solver.add(x - y % (y + 0x87) + y ^ 0x281 == 0xe83)
solver.add(0xb4 * (0x9f ^ y * 0x0) == 0x6fcc)
solver.add(x % (0x347 * (y + x * (y + y)) + 0x35c) == 0xc02)
solver.add(0x138 % ((y - x * y | x) + 0x3c9) == 0x138)
solver.add(y - (x + (y | x) - 0xdc) & 0x188 == 0x88)

x_value = solver.eval(x, 1)[0]
y_value = solver.eval(y, 1)[0]

with open('task_1.json', 'w') as output:
    output.write('{\n\t"x": ' + str(x_value) + ',\n\t"y": ' + str(y_value) + '\n}\n')

print('x =', x_value)
print('y =', y_value)