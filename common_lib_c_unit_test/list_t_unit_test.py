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
import unittest

#import node_t from common_lib
class ListNodeT(Structure):
        pass
ListNodeT._field_ = [("data", c_void_p), ("next", POINTER(ListNodeT))]
    
#import list_t from common_lib
class ListT(Structure):
    _field_ = [("head", POINTER(ListNodeT))]

#load functions from lib, get the pointer which can use the lib
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

class CommonLibCListTestCase(unittest.TestCase):
    def setUp(self):
        #load common_lib_c
        common_lib_c_path = r"../Debug/common_lib_c.dll"
        self.common_lib_c = load_common_lib_c(common_lib_c_path)
        
        #construct list_t
        self.list_t_object = ListT()
    def tearDown(self):
        pass        
    def testPush(self):
        org_data_list = ['A', 'AB', 'ABC', 'ABCD', 'ABCDE']
        popped_data_list = []

        #initialize
        self.common_lib_c.initialize_list_t(pointer(self.list_t_object))

        #push
        #for data in org_data_list:
        #    p_data = create_string_buffer(10)
        #    p_data.value = b"ABC"
        #    print(data)
        #    print(p_data)
        #    print(p_data.value)
        #    self.common_lib_c.list_t_push(pointer(self.list_t_object), p_data)
        #self.assertEqual(self.common_lib_c.list_t_count(pointer(self.list_t_object)), 
        #                len(org_data_list))
        p_data_list = [b'', b'', b'']
        p_data_list[0] = create_string_buffer(10)
        p_data_list[0].value = b"A"
        p_data_list[1] = create_string_buffer(10)
        p_data_list[1].value = b"AB"
        p_data_list[2] = create_string_buffer(10)
        p_data_list[2].value = b"ABC"
        print(p_data_list)
        self.common_lib_c.list_t_push(pointer(self.list_t_object), p_data_list[0])
        self.common_lib_c.list_t_push(pointer(self.list_t_object), p_data_list[1])
        self.common_lib_c.list_t_push(pointer(self.list_t_object), p_data_list[2])


        #pop
        popped_data_list = [b'', b'', b'']
        i = 0
        while self.common_lib_c.list_t_count(pointer(self.list_t_object)) > 0:
            popped_data_list[i] = create_string_buffer(10)
            self.common_lib_c.list_t_pop(pointer(self.list_t_object), popped_data_list[i])
            print(popped_data_list[i])
            print(popped_data_list[i].value)
            i += 1
        print(popped_data_list)
        

def suite():
    suite = unittest.TestSuite()
    suite.addTest(CommonLibCListTestCase("testPush"))
    #suite.addTest(CommonLibCListTestCase("testPush"))
    return suite
    #return unittest.makeSuite(CommonLibCListTestCase, "test")

def main():
    print("Unittest Start.")
    
    runner = unittest.TextTestRunner()
    runner.run(suite())

    print("Unittest Done.")


if __name__ == '__main__':
    main()



