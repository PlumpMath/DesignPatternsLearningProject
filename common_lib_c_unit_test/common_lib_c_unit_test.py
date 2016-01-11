#!python3
# coding=UTF-8
"""
Description:
Author: wangyoucao577@gmail.com
Version: 2016-01-10
"""

import os
from ctypes import *

common_lib_c_path = r"../Debug/common_lib_c.dll"

def load_log_print_from_lib(lib_path):
    if os.path.exists(lib_path):
        loaded_lib = cdll.LoadLibrary(lib_path)
        print(loaded_lib)
        print(loaded_lib.log_print)
    else:
        assert False

    return loaded_lib.log_print

def standard_libc_test():
    libc = cdll.msvcrt #for Windows
    #libc = cdll.LoadLibrary("libc.so.6")    #for Linux
    libc.printf(b"Hello %s.\n", "windows")

def main():
    log_print_common_lib_c_func = load_log_print_from_lib(common_lib_c_path)
    log_print_common_lib_c_func(b"Hello Tester!\n")

if __name__ == '__main__':
    main()



