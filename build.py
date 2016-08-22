#!/usr/bin/python
import sys
import os
import ftplib
import glob
import datetime
import shutil
from ftplib import FTP

def allFile(pattern):
    s = "";
    for file in glob.glob(pattern):
        s += file + " ";
    return s;

def allFolderFile(pattern, ext):
	s = "";
	for dirpath, dirnames, filenames in os.walk(pattern):
		for filename in [f for f in filenames if f.endswith(ext)]:
			s+= os.path.join(dirpath, filename) + ' '
	return s;

USA_TID 	= "0004000000187000"
NAME 		= "MonsterHunter"
HOST		= "192.168.1.99"
PORT		= "5000"
COPYTOPATH	= "%s.plg" % NAME
CC 		= "arm-none-eabi-gcc"
CP 		= "arm-none-eabi-g++"
OC		= "arm-none-eabi-objcopy" 
LD 		= "arm-none-eabi-ld"
CTRULIB 	= "../libctru"
DEVKITARM 	= "c:/devkitPro/devkitARM"
LIBPATH 	= "-L ./lib "
ARCH 		= " -march=armv6k -mlittle-endian -mtune=mpcore -mfloat-abi=hard "
CFLAGS		= " -Os -c " + ARCH
ASFLAGS		= " -Os -c -s " + ARCH
LIBFLAGS 	= " -lntr -lShark2NTR_dev -lctr -lg -lsysbase -lc -lgcc "
LDFLAGS		= " -pie --gc-sections -T 3ds.ld -Map=%s.map " % NAME
INCLUDES 	= " -I Includes -I Sources -I Includes/libntrplg "
CFILES		= allFolderFile(".\\Sources\\", ".c")
ASFILES		= allFolderFile(".\\Sources\\", ".s")
OFILES          = allFolderFile(".\\ofiles\\", ".o") 
ftp 		= FTP()
FILE		= COPYTOPATH
		
def connect(host, port):
    ftp.connect(host, port);

def disconnect():
	ftp.quit();

def ls():
	ftp.dir();

def send():
	file = open(FILE, 'rb');
	ftp.cwd(FTP_FOLDER);
	ftp.storbinary('STOR '+ FILE, file);
	file.close();

def printf(string):
    print(datetime.datetime.strftime(datetime.datetime.now(), '%Y-%m-%d %H:%M:%S') + " : " + string);

def run(cmd):
	#print(cmd);
	return (os.system(cmd));

def error():
	print("\n\n");
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	printf("There's some errors on your code.");
	printf("Correct them and try again, for now I'm exiting the compilation.\n");
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
	sys.exit();

cwd = os.getcwd()
print("\n\n");
printf("Hello!\n");
printf("How are you ?\n");
printf("Preparing to compile the plugin: %s\n " % COPYTOPATH);
printf("Please just wait a second...\n");
if (os.path.isfile("obj/cheats.o")):
	run("rm obj/*.o")
if (os.path.isfile(COPYTOPATH)):
	run("rm *.plg")
printf("Compiling C files");
result = run(CC +  CFLAGS + INCLUDES + CFILES);
if (result != 0):
	error();

printf("Compiling S files");
result = run(CC + ASFLAGS + ASFILES);
if (result != 0):
	error();

OFILES += allFile("*.o") + " " + allFile("lib/*.o")
printf("Linking all files into " + COPYTOPATH);
result = run(LD + LDFLAGS + ' ' + LIBPATH  + OFILES + LIBFLAGS )
if (result != 0):
	error();

if (os.path.isfile("config.o")):
	run("cp -r *.o obj/ ")
	run("rm *.o")
if (os.path.isfile("a.out")):
	run(OC +" -O binary a.out payload.bin -S")	
if (os.path.isfile("a.out")):
	run("rm *.out")
if (os.path.isfile("payload.bin")):
	shutil.copy2("payload.bin", COPYTOPATH);
	run("rm payload.bin");
if (os.path.isfile(NAME + ".map")):
	run("rm *.map");

printf("Done, enjoy your plugin !\n\n");

