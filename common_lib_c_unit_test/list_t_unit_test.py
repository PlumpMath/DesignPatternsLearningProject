#!python3
# coding=UTF-8
"""
Description:
Author: wangyoucao577@gmail.com
Version: 2016-01-10
"""

import os
import sys
from ctypes import *


#import node_t from common_lib
class ListNodeT(Structure):
        pass
ListNodeT._field_ = [("data", c_void_p), ("next", POINTER(ListNodeT))]
    
#import list_t from common_lib
class ListT(Structure):
    _field_ = [("head", POINTER(ListNodeT))]

def load_common_lib_c(lib_path):
    if os.path.exists(lib_path):
        loaded_lib = cdll.LoadLibrary(lib_path)
        sys.stdout.write("loaded_lib :")
        print(loaded_lib)

        #print address of imported functions
        sys.stdout.write("loaded_lib.initialize_list_t :")
        print(loaded_lib.initialize_list_t);
        sys.stdout.write("loaded_lib.list_t_push :")
        print(loaded_lib.list_t_push)
        sys.stdout.write("loaded_lib.list_t_pop :")
        print(loaded_lib.list_t_pop)
        sys.stdout.write("loaded_lib.list_t_remove :")
        print(loaded_lib.list_t_remove)
        sys.stdout.write("loaded_lib.list_t_peek :")
        print(loaded_lib.list_t_peek)
        sys.stdout.write("loaded_lib.list_t_clear :")
        print(loaded_lib.list_t_clear)
        sys.stdout.write("loaded_lib.list_t_count :")
        print(loaded_lib.list_t_count)
    else:
        assert False
    return loaded_lib

def main():
    common_lib_c_path = r"../Debug/common_lib_c.dll"
    common_lib_c = load_common_lib_c(common_lib_c_path)


if __name__ == '__main__':
    main()



