#!python3
# coding=UTF-8
"""
Description:
Author: wangyoucao577@gmail.com
Version: 2016-01-10
"""

from list_t_unit_test import *


def main():
    print("common_lib_c_unit_test Start.")

    runner = unittest.TextTestRunner()
    runner.run(list_t_unit_test_suite())
    
    print("common_lib_c_unit_test Done.")

if __name__ == '__main__':
    main()



