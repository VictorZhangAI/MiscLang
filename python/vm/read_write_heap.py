#!/usr/bin/env python3

import sys

def print_usage_and_exit():
    print("Usage: {} pid search write".format(sys.argv[0]));
    sys.exit(1);

def main():
    if len(sys.argv) != 4:
        print_usage_and_exit()

    pid = int(sys.argv[1])
    if pid <= 0:
        print_usage_and_exit()

    search_string = str(sys.argv[2])
    if search_string == "":
        print_usage_and_exit()

    write_string = str(sys.argv[3])
    if write_string == "":
        print_usage_and_exit()

    maps_filename = "/proc/{}/maps".format(pid)
    print("[*]maps: {}".format(maps_filename))
    mem_filename = "/proc/{}/mem".format(pid)
    print("[*]mem: {}".format(mem_filename))

    try:
        maps_file = open("/proc/{}/maps".format(pid), 'r')
    except IOError as e:
        print("[ERROR] Cannot open file {}:".format(maps_filename))
        print("I/O error({}): {}".format(e.errno, e.strerror))
        sys.exit(1)

    for line in maps_file:
        sline = line.split(' ')
        if sline[-1][:-1] != "[heap]":
            continue
        print("[*]Found [heap]:")

        addr = sline[0]
        perm = sline[1]
        offset = sline[2]
        device = sline[3]
        inode = sline[4]
        pathname = sline[-1][:-1]
        print("\tpathname = {}".format(pathname))
        print("\taddresses = {}".format(addr))
        print("\tpermisions = {}".format(perm))
        print("\toffset = {}".format(offset))
        print("\toffset = {}".format(offset))

        if perm[0] != 'r' or perm[1] != 'w':
            print("[*] {} does not have read/write permission".format(pathname))
            maps_file.close()
            exit(0)

        addr = addr.split("-")
        if len(addr) != 2:
            print("[*] Wrong addr format")
            maps_file.close()
            exit(1)

        addr_start = int(addr[0], 16)
        addr_end = int(addr[1], 16)
        print("\tAddr start [{:x}] | end [{:x}]".format(addr_start, addr_end))

        try:
            mem_file = open(mem_filename, 'rb+')
        except IOError as e:
            print("[ERROR] Can not open file {}:".format(mem_filename))
            print("I/O error({}): {}".format(e.errno, e.strerror))
            maps_file.close()
            exit(1)

        mem_file.seek(addr_start)
        heap = mem_file.read(addr_end - addr_start)

        try:
            i = heap.index(bytes(search_string, "ASCII"))
        except Exception:
            print("Can't find '{}'".format(search_string))
            maps_file.close()
            mem_file.close()
            exit(0)

        print("[*] Found '{}' at {:x}".format(search_string, i))

        print("[*] Writing '{}' at {:x}".format(write_string, addr_start + i))
        mem_file.seek(addr_start + i)
        mem_file.write(write_string, "ASCII")

        maps_file.close()
        mem_file.close()

        break
    return

if __name__ == "__main__":
    main()
