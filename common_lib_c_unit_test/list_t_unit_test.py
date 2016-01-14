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
import faulthandler
from common_tools import *

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
        sys.stdout.write("\nloaded_lib :")
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
        print("")
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

        #prepare push data
        #self.p_push_bytes_data = {}
        #org_data_list = ['A', 'AB', 'ABC', 'ABCD', 'ABCDE']
        #for data in org_data_list:
        #    self.p_push_bytes_data[data] = create_string_buffer(data.encode('ascii'))

    def tearDown(self):
        pass  
          
    def testInitialize(self):
        print(get_func_name() + "test start.")
        self.common_lib_c.initialize_list_t(pointer(self.list_t_object))
        print(get_func_name() + "test end.\n")

    def testPushPop(self):
        print(get_func_name() + "test start.")
        org_data_list = ['A', 'AB', 'ABC', 'ABCD', 'ABCDE']

        #initialize
        self.common_lib_c.initialize_list_t(pointer(self.list_t_object))

        #push
        p_push_bytes_data = {}
        for data in org_data_list:
            #print(data)
            p_push_bytes_data[data] = create_string_buffer(data.encode('ascii'))
            print("p_push_bytes_data[%s] ->%s (%s)" 
                 %(data, p_push_bytes_data[data].value.decode('ascii'), p_push_bytes_data[data]))
            y = data.encode('ascii')
            self.common_lib_c.list_t_push(pointer(self.list_t_object), p_push_bytes_data[data])
        print(self.common_lib_c.list_t_count(pointer(self.list_t_object)))
        self.assertEqual(self.common_lib_c.list_t_count(pointer(self.list_t_object)), 
                        len(org_data_list))
        print("p_push_bytes_data:")
        print(p_push_bytes_data)
        print("")

        #pop
        p_pop_data_list = {}
        popped_data_list = []
        i = 0
        while self.common_lib_c.list_t_count(pointer(self.list_t_object)) > 0:
            data = c_char_p()
            p_data = pointer(data)
            self.common_lib_c.list_t_pop(pointer(self.list_t_object), p_data)
            #p_data.contents.value is equal to data.value
            #TODO: how to print data as 0x12345678?
            print("pop :%s at %s" %(p_data.contents.value.decode('ascii'), data))

            #add value to dict
            p_pop_data_list[i] = p_data.contents.value.decode('ascii')
            print("p_pop_data_list[%d] ->%s" %(i, p_pop_data_list[i]))

            #add value to list
            popped_data_list.append(p_data.contents.value.decode('ascii'))
            print("popped_data_list[%d] ->%s\n" %(i, popped_data_list[i]))

            i += 1
        print("popped_data_list:")
        print(popped_data_list)
        print("p_pop_data_list:")
        print(p_pop_data_list)
        print(get_func_name() + "test end.\n")

def suite():
    suite = unittest.TestSuite()
    suite.addTest(CommonLibCListTestCase("testInitialize"))
    suite.addTest(CommonLibCListTestCase("testPushPop"))
    return suite
    #return unittest.makeSuite(CommonLibCListTestCase, "test")

def main():
    print("Unittest Start.")
    
    runner = unittest.TextTestRunner()
    runner.run(suite())

    print("Unittest Done.")

# always execute
faulthandler.enable()

if __name__ == '__main__':
    main()



