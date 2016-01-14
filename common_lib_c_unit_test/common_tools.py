#!python3
# coding=UTF-8
"""
Description:
Author: wangyoucao577@gmail.com
Version: 2016-01-14
"""
import sys

def get_func_name_line():
    """Return the frame object for the caller's stack frame."""
    try:
        raise Exception
    except:
        f = sys.exc_info()[2].tb_frame.f_back
    return (f.f_code.co_name, f.f_lineno)
    
def get_func_name():
    """Return the frame object for the caller's stack frame."""
    try:
        raise Exception
    except:
        f = sys.exc_info()[2].tb_frame.f_back
    return f.f_code.co_name

def main():
    print("common_tools.py test.")
    #print(get_func_name_line())

if __name__ == '__main__':
    main()
else:
    print("Module common_tools.py has been loaded.")


