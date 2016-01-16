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
        self.p_push_bytes_data = {}
        self.org_data_list = ['A', 'AB', 'ABC', 'ABCD', 'ABCDE']
        for data in self.org_data_list:
            self.p_push_bytes_data[data] = create_string_buffer(data.encode('ascii'))

    def tearDown(self):
        pass  

    def doDataPush(self):
        print(get_func_name() + "start.")

        for data in self.org_data_list:
            print("self.p_push_bytes_data[%s] ->%s, type:%s" %(data, self.p_push_bytes_data[data].value.decode('ascii'), self.p_push_bytes_data[data]))
            self.common_lib_c.list_t_push(byref(self.list_t_object), self.p_push_bytes_data[data])
            sys.stdout.write("list_t_count ->")
            print(self.common_lib_c.list_t_count(byref(self.list_t_object)))
        
        self.assertEqual(self.common_lib_c.list_t_count(byref(self.list_t_object)), 
                         len(self.p_push_bytes_data))

        print(get_func_name() + "end.")

    def testInitialize(self):
        print(get_func_name() + " start.")
        self.common_lib_c.initialize_list_t(byref(self.list_t_object))
        print(get_func_name() + " end.\n")

    def testPushPop(self):
        print(get_func_name() + " start.")

        #initialize
        self.common_lib_c.initialize_list_t(byref(self.list_t_object))

        #push
        self.doDataPush()

        #pop
        popped_data_dict = {}
        popped_data_list = []
        i = 0
        while self.common_lib_c.list_t_count(byref(self.list_t_object)) > 0:
            data = c_char_p()
            #p_data = pointer(data)
            print("id(data):0x%x at 0x%x" %(id(data), id(byref(data))))
            self.common_lib_c.list_t_pop(byref(self.list_t_object), byref(data))
            #p_data.contents.value == data.value
            #TODO: how to print data as 0x12345678?
            #print("pop :%s at %s" %(p_data.contents.value.decode('ascii'), data))
            print("pop :%s at %s" %(data.value.decode('ascii'), data))

            #add value to dict
            popped_data_dict[i] = data.value.decode('ascii')
            print("popped_data_dict[%d] ->%s" %(i, popped_data_dict[i]))

            #add value to list
            popped_data_list.append(data.value.decode('ascii'))
            print("popped_data_list[%d] ->%s\n" %(i, popped_data_list[i]))

            i += 1
        print("popped_data_list:")
        print(popped_data_list)
        print("popped_data_dict:")
        print(popped_data_dict)
        self.assertEqual(self.common_lib_c.list_t_count(byref(self.list_t_object)), 0)

        print(get_func_name() + " end.\n")
    
    def testPushPeek(self):
        print(get_func_name() + " start.")

        #initialize
        self.common_lib_c.initialize_list_t(byref(self.list_t_object))

        #push
        self.doDataPush()

        #peek
        peeked_data_list = []
        i = 0
        while i < self.common_lib_c.list_t_count(byref(self.list_t_object)):
            data = c_char_p()
            #p_data = pointer(data)
            self.common_lib_c.list_t_peek(byref(self.list_t_object), i, byref(data))
            print("peek[%d] ->%s at %s" %(i, data.value.decode('ascii'), data))

            #add value to list
            peeked_data_list.append(data.value.decode('ascii'))
            print("peeked_data_list[%d] ->%s\n" %(i, peeked_data_list[i]))

            i += 1

        print("peeked_data_list:")
        print(peeked_data_list)
        self.assertEqual(self.common_lib_c.list_t_count(byref(self.list_t_object)), len(self.org_data_list))

        print(get_func_name() + " end.\n")

    def testPushClear(self):
        print(get_func_name() + " start.")

        #initialize
        self.common_lib_c.initialize_list_t(byref(self.list_t_object))

        #push
        self.doDataPush()

        #clear
        self.common_lib_c.list_t_clear(byref(self.list_t_object))
        self.assertEqual(self.common_lib_c.list_t_count(byref(self.list_t_object)), 0)

        print(get_func_name() + " end.\n")

    def testPushRemove(self):
        print(get_func_name() + " start.")

        #initialize
        self.common_lib_c.initialize_list_t(byref(self.list_t_object))

        #push
        self.doDataPush()

        #remove
        for data in self.org_data_list:
            print("going to remove: p_push_bytes_data[%s] ->%s, type:%s" %(data, self.p_push_bytes_data[data].value.decode('ascii'), self.p_push_bytes_data[data]))
            self.common_lib_c.list_t_remove(byref(self.list_t_object), self.p_push_bytes_data[data])
            sys.stdout.write("list_t_count ->")
            print(self.common_lib_c.list_t_count(byref(self.list_t_object)))

        self.assertEqual(self.common_lib_c.list_t_count(byref(self.list_t_object)), 0)

        print(get_func_name() + " end.\n")

def list_t_unit_test_suite():
    suite = unittest.TestSuite()
    #suite.addTest(CommonLibCListTestCase("testInitialize"))
    #suite.addTest(CommonLibCListTestCase("testPushPop"))
    #suite.addTest(CommonLibCListTestCase("testPushClear"))
    #suite.addTest(CommonLibCListTestCase("testPushRemove"))
    #return suite
    return unittest.makeSuite(CommonLibCListTestCase, "test")

def main():
    print("list_t_unit_test Start.")
    
    runner = unittest.TextTestRunner()
    runner.run(list_t_unit_test_suite())

    print("list_t_unit_test Done.")

# always execute
faulthandler.enable()

if __name__ == '__main__':
    main()
else:
    print("Module list_t_unit_test.py has been loaded.")



