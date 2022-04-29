from cgitb import reset
import angr

p = angr.Project('./explore', auto_load_libs=False)
s = p.factory.simgr()

cfg = p.analyses.CFGFast()
print("This is the graph:", cfg.graph)
print("It has %d nodes and %d edges" % (len(cfg.graph.nodes()), len(cfg.graph.edges())))

target_offset = 0x104265
target_addr = p.loader.main_object.offset_to_addr(target_offset)
avoid_offsets = [0x104322, 0x104320]
avoid_addrs = list(map(p.loader.main_object.offset_to_addr, avoid_offsets))
s.explore(find=target_addr, avoid=avoid_addrs)

my_state = s.found[0]
result = my_state.posix.stdin.concretize()[0]
print(result)

with open('task_2.bin', 'wb') as output:
    output.write(result)