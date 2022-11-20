import os

starting_path = os.getcwd()
bnkr_alg = starting_path + "/Banker_Algo"
build_path = bnkr_alg + "/build"

os.chdir(bnkr_alg)

if(not os.path.exists("build")):
    os.system("mkdir build")

os.chdir(build_path)

os.system("cmake ..")

os.system("make")

os.system("mv Banker " + starting_path)

os.chdir(starting_path)