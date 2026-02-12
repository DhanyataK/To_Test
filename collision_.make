#
# Simcenter Amesim system make file
#


# This makefile has been created using the following cathegory path list
#	$AME/libame
#	$AME
#	$AME/libsig
#	$AME/libmec
#	$AME/libdrv
#	$AME/libeng
#	$AME/libcfd1d
#	$AME/libexh
#	$AME/libhydr
#	$AME/libhcd
#	$AME/libhr
#	$AME/libfi
#	$AME/libth
#	$AME/libthh
#	$AME/libthcd
#	$AME/libcs
#	$AME/libtpf
#	$AME/libac
#	$AME/libheat
#	$AME/libpn
#	$AME/libpcd
#	$AME/libgm
#	$AME/libma
#	$AME/libec
#	$AME/libfc
#	$AME/libtr
#	$AME/libm6dof
#	$AME/libplm
#	$AME/libdv
#	$AME/libicar
#	$AME/libcf
#	$AME/libem
#	$AME/libesc
#	$AME/libeb
#	$AME/libemd
#	$AME/libae
#	$AME/libesg
#	$AME/libess
#	$AME/libfl
#	$AME/libflcd
#	$AME/libh2
#	$AME/libflst
#	$AME/libaero
#	$AME/libace
#	$AME/libgte
#	$AME/liblp
#	$AME/libacf
#	$AME/libmotion
# End category path list
# The MACHINETYPE variable can be used in -L statements
# or otherwise to separate machine dependent code

MACHINETYPE = win64-gcc

# Then the object files
OBJECTS = \
	D:/Amesim/V2604/v2604_1/Amesim/libmec/submodels/win64-gcc/RSPR00.o \
	D:/Amesim/V2604/v2604_1/Amesim/libmec/submodels/win64-gcc/TORQC.o \
	D:/Amesim/V2604/v2604_1/Amesim/libmec/submodels/win64-gcc/T000.o \
	D:/Amesim/V2604/v2604_1/Amesim/libsig/submodels/win64-gcc/SIGUDA01.o \
	D:/Amesim/V2604/v2604_1/Amesim/libmec/submodels/win64-gcc/MECRL0.o

OBJECTS2 = \
	"D:/Amesim/V2604/v2604_1/Amesim/libmec/submodels/win64-gcc/RSPR00.o" \
	"D:/Amesim/V2604/v2604_1/Amesim/libmec/submodels/win64-gcc/TORQC.o" \
	"D:/Amesim/V2604/v2604_1/Amesim/libmec/submodels/win64-gcc/T000.o" \
	"D:/Amesim/V2604/v2604_1/Amesim/libsig/submodels/win64-gcc/SIGUDA01.o" \
	"D:/Amesim/V2604/v2604_1/Amesim/libmec/submodels/win64-gcc/MECRL0.o"

collision_.dll: $(OBJECTS) collision_.o
	@echo collision_.make.link_args =
	@type collision_.make.link_args
	"$(AME)\interfaces\standalonesimulator\win32\stdsim_dynlink" win64 $(CC) -m64 $(LDFLAGS) -o collision_.dll collision_.o @"collision_.make.link_args" $(AMELIBS)

collision_.o: collision_.c
	"$(AME)\interfaces\user_cosim\win32\ame_user_cosim_dyncompile" $(CC) -m64 -c -I"$(AME)\interfaces\user_cosim" -I"$(AME)\interfaces\standalonesimulator" -I"$(AME)\interfaces" $(CFLAGS) -o collision_.o collision_.c

.c.o:
	@echo
	@echo "Warning: \"$<\" is newer than the object."
	@echo ""

.f.o:
	@echo
	@echo "Warning: \"$<\" is newer than the object."
	@echo ""

# End of file

