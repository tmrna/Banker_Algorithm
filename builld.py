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
    

#sets up build in path_to_proj/Banker_Algorithm
setup_build_dir("")