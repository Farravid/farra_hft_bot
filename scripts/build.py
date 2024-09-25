# The options are based on folders name so make sure to avoid changing folder names or option names in this script

import subprocess
import sys

def install_and_import(package):
    try:
        __import__(package)
    except ImportError:
        print(f"{package} not found. Installing...")
        subprocess.check_call([sys.executable, "-m", "pip", "install", package])
    finally:
        globals()[package] = __import__(package)

def perform_building(builds):
    for build in builds:
        subprocess.run("cmake -S " + build + " -B build/" + build + " -DCMAKE_BUILD_TYPE=Debug", shell=True)
        subprocess.run("cmake --build build/" + build, shell=True)
    
    for build in builds:
        target_name = build
        if build == "standalone":
            target_name = "Greeter"

        subprocess.run("./build/" + build + "/" + target_name[0].upper() + target_name[1:], shell=True)

def main():
    install_and_import('inquirer')
    builds = [
        inquirer.Checkbox(
            "builds",
            message="What do you want to build?",
            choices=["standalone", "test", "benchmark", "documentation"],
            default=["standalone", "test"],
        ),
    ]

    answer_b = inquirer.prompt(builds)

    type = [
    inquirer.List(
        "type",
        message="Debug or Release?",
        choices=["Debug", "Release"],
    ),
    ]

    answer_t = inquirer.prompt(type)

    perform_building(answer_b['builds'])

     
if __name__ == "__main__":
    main()