import os
import sys


path = os.getcwd()

def mkdir(destination : str) -> None:
    os.system("mkdir " + path + destination)

def run_cmake(destination_parent : str) -> None:
    os.system("cmake " + path + destination_parent)
    
def make(destination : str) -> None:
    os.system("make " + path + destination)
    
def setup_build_dir(destination_parent : str) -> None:
    destination = destination_parent + "/build"
    if(not os.path.exists(path + destination)):
        mkdir(destination)
        run_cmake(destination_parent)
    else:
        print(path + destination + " already exists")
    make(destination)
    
    
setup_build_dir("/Banker_Algo/lib/read_write/deps/pugixml")

setup_build_dir("/Banker_Algo/lib/read_write/deps")

setup_build_dir("/Banker_Algo/lib/read_write")

setup_build_dir("/Banker_Algo/lib/row_matrix")

setup_build_dir("/Banker_Algo/lib")

setup_build_dir("/Baner_Algo")